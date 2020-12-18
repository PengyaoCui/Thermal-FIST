#include "inc/loadFist.h"

bool our_frz_curve = false;

double muBss(double ecm){
  if (our_frz_curve) return 1.477 / (1. + 0.343 * ecm);
  else return 1.308 / (1. + 0.273 * ecm);
}

double Tss(double ecm){
  double tmpmuB = muBss(ecm);
  if (our_frz_curve) return 0.157 - 0.087 * tmpmuB * tmpmuB - 0.092 * tmpmuB * tmpmuB * tmpmuB * tmpmuB;
  else return 0.166 - 0.139 * tmpmuB * tmpmuB - 0.053 * tmpmuB * tmpmuB * tmpmuB * tmpmuB;
}

void DensitiesVsEcm(ThermalModelBase *model, double smin = 3., double smax = 3000., int iterss = 10, std::string filename = "out/GCEDensitiesVsEcm.dat"){
  //Output on the screen and to a file
  vector<std::ostream*> outs;
  outs.push_back(&std::cout);
  
  ofstream fout(filename.c_str());
  outs.push_back(&fout);
  
  for(std::ostream* out : outs) {
    *out << setw(15) << "sqrts[GeV]";
    *out << setw(15) << "T[MeV]";
    *out << setw(15) << "muB[MeV]";
    *out << setw(15) << "muQ[MeV]";
    *out << setw(15) << "muS[MeV]";
    *out << setw(15) << "nH[fm-3]";
    *out << setw(15) << "nB/nH";
    *out << setw(15) << "nQ/nH";
    *out << setw(15) << "nS/nH";
    *out << endl;
  }
  

  model->ConstrainMuS(true);
  model->ConstrainMuQ(true);
  model->ConstrainMuC(true);
  model->SetQoverB(0.4);

  double logSmin = log(smin);//log()=ln  log10()
  double logSmax = log(smax);
  double dlogS = (logSmax - logSmin) / iterss;
  for (int is = 0; is <= iterss; ++is){
    double ss = exp(logSmin + is * dlogS);
    double T = Tss(ss);
    double muB = muBss(ss);

    model->SetTemperature(T);
    model->SetBaryonChemicalPotential(muB);
    model->FixParameters();

    model->CalculateDensities();

    double nH = 0., nB = 0., nQ = 0., nS = 0.;
    //nH = model->CalculateHadronDensity();
    for (int i = 0; i < model->Densities().size(); ++i){
      const ThermalParticle& part = model->TPS()->Particle(i);
      nH += model->Densities()[i];

      if (part.BaryonCharge() != 0) nB += model->Densities()[i];
      if (part.ElectricCharge() != 0) nQ += model->Densities()[i];
      if (part.Strangeness() != 0) nS += model->Densities()[i];
    }
    
    for(std::ostream* out : outs) {
      *out << setw(15) << ss;
      *out << setw(15) << T * 1.e3;
      *out << setw(15) << muB * 1.e3;
      *out << setw(15) << model->Parameters().muQ * 1.e3;
      *out << setw(15) << model->Parameters().muS * 1.e3;
      *out << setw(15) << nH;
      *out << setw(15) << nB / nH;
      *out << setw(15) << nQ / nH;
      *out << setw(15) << nS / nH;
      *out << endl;
    }
  }
}
int main(){
  // PDG2014 particle list with light nuclei
  ThermalParticleSystem parts(string(ThermalFIST_INPUT_FOLDER) + "/list/PDG2014/list-withnuclei.dat");

  // Ideal HRG model
  ThermalModelIdeal model(&parts);

  // Energy-dependent Breit-Wigner widths
  ThermalParticle::ResonanceWidthIntegration useWidth = ThermalParticle::eBW;
  model.SetUseWidth(useWidth);

  // Quantum statistics

  bool useQStats = true;
  model.SetStatistics(useQStats);

  // Include quantum statistics for mesons only
  if (useQStats){
    for (int i = 0; i < model.TPS()->Particles().size(); ++i){
      ThermalParticle &part = model.TPS()->Particle(i);
      if (part.BaryonCharge() != 0) part.UseStatistics(false);
    }
  }

  // Run the collision energy dependence calculation (Fig. 1)

  string filename = "GCEDensitiesVsEcm.dat";
  if (model.TPS()->ResonanceWidthIntegrationType() == ThermalParticle::eBW)
  filename = "eBW." + filename;
  filename = "out/1906.03145.1_" + filename; 
  DensitiesVsEcm(&model, 2., 5100., 200, filename);
  
  return 0;
}
