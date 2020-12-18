#include "inc/loadFist.h"

bool useWidth  = true;
bool useQStats = true;

double Tch = 0.155;

vector<int> pdgs1, pdgs2;
vector<string> names1, names2;

vector<double> ratiosGCE;

vector<std::ostream*> outs;

void PerformScan(ThermalModelBase *model, double k, const string& filename);

int main(){
  ThermalParticleSystem parts(string(ThermalFIST_INPUT_FOLDER) + "/list/PDG2014/list.dat");
  
//===================================================================
  
  names1.push_back("K");
  names2.push_back("pi");
  pdgs1.push_back(321);
  pdgs2.push_back(211);
  
  names1.push_back("Xi");
  names2.push_back("pi");
  pdgs1.push_back(3312);
  pdgs2.push_back(211);
  
  names1.push_back("phi");
  names2.push_back("pi");
  pdgs1.push_back(333);
  pdgs2.push_back(211);
  
  names1.push_back("p");
  names2.push_back("pi");
  pdgs1.push_back(2212);
  pdgs2.push_back(211);
  
  names1.push_back("Om");
  names2.push_back("pi");
  pdgs1.push_back(3334);
  pdgs2.push_back(211);
  
  names1.push_back("La");
  names2.push_back("pi");
  pdgs1.push_back(3122);
  pdgs2.push_back(211);
  
  names1.push_back("K*");
  names2.push_back("pi");
  pdgs1.push_back(323);
  pdgs2.push_back(211); 
//===================================================================
  
  ThermalModelIdeal modelgce(&parts);
  
  if (useWidth) modelgce.SetUseWidth(ThermalParticle::eBW);
  else modelgce.SetUseWidth(ThermalParticle::ZeroWidth);
  modelgce.SetStatistics(useQStats);
  // Include quantum statistics for mesons only
  if (useQStats){
    for (int i = 0; i < modelgce.TPS()->Particles().size(); ++i) {
      ThermalParticle &part = modelgce.TPS()->Particle(i);
      if (part.BaryonCharge() != 0) part.UseStatistics(false);
    }
  }
  modelgce.SetTemperature(Tch);
  modelgce.SetBaryonChemicalPotential(0.);
  modelgce.SetElectricChemicalPotential(0.);
  modelgce.SetStrangenessChemicalPotential(0.);
  modelgce.FillChemicalPotentials();
  
  modelgce.CalculateDensities();
  for (int i = 0; i < names1.size(); ++i) {
    ratiosGCE.push_back(modelgce.GetDensity(pdgs1[i], 1)/modelgce.GetDensity(pdgs2[i], 1));
  }

//===================================================================
  outs.push_back(&std::cout);
  outs.push_back(NULL);
  
//===================================================================
  ThermalModelCanonical modelce(&parts);
  if (useWidth) modelce.SetUseWidth(ThermalParticle::eBW);
  else modelce.SetUseWidth(ThermalParticle::ZeroWidth);
  
  modelce.SetStatistics(useQStats);
  // Include quantum statistics for mesons only
  if (useQStats){
    for (int i = 0; i < modelce.TPS()->Particles().size(); ++i) {
      ThermalParticle &part = modelce.TPS()->Particle(i);
      if (part.BaryonCharge() != 0)
          part.UseStatistics(false);
    }
  }
  
  modelce.SetTemperature(Tch);
  modelce.SetBaryonChemicalPotential(0.);
  modelce.SetElectricChemicalPotential(0.);
  modelce.SetStrangenessChemicalPotential(0.);
  
  modelce.SetBaryonCharge(0);
  modelce.SetElectricCharge(0);
  modelce.SetStrangeness(0);
  
  modelce.FillChemicalPotentials();

  //modelce.ConserveBaryonCharge(true);
  //modelce.ConserveElectricCharge(true);
  //modelce.ConserveStrangeness(true);
  //modelce.CalculateQuantumNumbersRange();

  PerformScan(&modelce, 1., "out/1906.03145.3_VanillaCSM.dy1.dat");
}

void PerformScan(ThermalModelBase *model, double k, const string& filename)
{
  ofstream fout(filename);
  outs[1] = &fout;

  for(std::ostream* out : outs) {
    *out << setw(15) << "dNpipm/dy";
    *out << setw(15) << "Vc[fm3]";

    for (int i = 0; i < names1.size(); ++i) {
      *out << setw(15) << "(" + (names1[i] + "/" + names2[i]) + ")toHML";
    }

    *out << endl;
  }

  double Vmin = 1. * k;
  double Vmax = 15000. * k;
  int iters = 30;
  double logVmin = log10(Vmin), logVmax = log10(Vmax);
  double dlogV = (logVmax - logVmin) / (iters - 1);

  for (double logV = logVmin; logV <= logVmax + 1.e-3; logV += dlogV) {
    double V = pow(10., logV);

    model->SetVolume(V);
    model->SetCanonicalVolume(V);
    model->CalculateDensities();

    for(std::ostream* out : outs) {
      *out << setw(15) << 2. * model->GetDensity(211, 1) * V / k; // Charged pions dN/dy
      *out << setw(15) << V; // Vc

      for (int i = 0; i < names1.size(); ++i) {
        *out << setw(15) << model->GetDensity(pdgs1[i], 1) / model->GetDensity(pdgs2[i], 1) / ratiosGCE[i];
      }
      *out << endl;
    }
  }

  for(std::ostream* out : outs) {
    *out << setw(15) << "HML";
    *out << setw(15) << "HML";

    for (int i = 0; i < ratiosGCE.size(); ++i) {
      *out << setw(15) << ratiosGCE[i];
    }

    *out << endl;
  }

  fout.close();
}


