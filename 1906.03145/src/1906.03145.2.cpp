#include "inc/loadFist.h"

bool useWidth  = true;
bool useQStats = true;

double Tch = 0.155;

vector<int> pdgsCE;
vector<string> namesCE;

vector<double> yieldsGCE;

vector<std::ostream*> outs;

void PerformVcScan(ThermalModelBase *model, const string& filename);

int main(){
  ThermalParticleSystem parts(string(ThermalFIST_INPUT_FOLDER) + "/list/PDG2014/list.dat");
  
//===================================================================
  
  pdgsCE.push_back(111);
  namesCE.push_back("pi0");
  
  pdgsCE.push_back(211);
  namesCE.push_back("pi+");
  
  pdgsCE.push_back(321);
  namesCE.push_back("K+");
  
  pdgsCE.push_back(310);
  namesCE.push_back("K0S");
  
  pdgsCE.push_back(221);
  namesCE.push_back("eta");
  
  pdgsCE.push_back(323);
  namesCE.push_back("KStar+");
  
  pdgsCE.push_back(333);
  namesCE.push_back("phi");
  
  pdgsCE.push_back(2212);
  namesCE.push_back("p");
  
  pdgsCE.push_back(2112);
  namesCE.push_back("n");
  
  pdgsCE.push_back(3122);
  namesCE.push_back("Lambda");
  
  pdgsCE.push_back(3222);
  namesCE.push_back("Sigma+");
  
  pdgsCE.push_back(3112);
  namesCE.push_back("Sigma+");
  
  pdgsCE.push_back(3212);
  namesCE.push_back("Sigma0");
  
  pdgsCE.push_back(3322);
  namesCE.push_back("Ksi0");
  
  pdgsCE.push_back(3312);
  namesCE.push_back("Ksi-");
  
  pdgsCE.push_back(3334);
  namesCE.push_back("Omega");
  
  /*pdgsCE.push_back(1000010020);
  namesCE.push_back("d");
  
  pdgsCE.push_back(1000020030);
  namesCE.push_back("He3");
  
  pdgsCE.push_back(1010010030);
  namesCE.push_back("H3La");
  
  pdgsCE.push_back(1000020040);
  namesCE.push_back("He4");*/
  
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
  for (int i = 0; i < namesCE.size(); ++i) {
    yieldsGCE.push_back(modelgce.GetDensity(pdgsCE[i], 1));
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

  modelce.ConserveBaryonCharge(true);
  modelce.ConserveElectricCharge(true);
  modelce.ConserveStrangeness(true);
  modelce.CalculateQuantumNumbersRange();

  PerformVcScan(&modelce, "out/1906.03145.2_YieldsCSMvsVc.BSQ.dat");
}

void PerformVcScan(ThermalModelBase *model, const string& filename)
{
  ofstream fout(filename);
  outs[1] = &fout;

  for(std::ostream* out : outs) {
    *out << setw(15) << "Vc[fm3]";

    for(auto&& name: namesCE) {
      *out << setw(15) << "(" + name + ")" + "toHML";
    }
    *out << endl;
  }

  double Vmin = 4.;
  double Vmax = 30000.;
  int iters = 30;
  double logVmin = log10(Vmin), logVmax = log10(Vmax);
  double dlogV = (logVmax - logVmin) / (iters - 1);

  for (double logV = logVmin; logV <= logVmax + 1.e-3; logV += dlogV) {
    double V = pow(10., logV);

    model->SetVolume(V);
    model->SetCanonicalVolume(V);
    model->CalculateDensities();

    for(std::ostream* out : outs) {
      *out << setw(15) << V;

      for (int i = 0; i < namesCE.size(); ++i) {
        *out << setw(15) << model->GetDensity(pdgsCE[i], 1) / yieldsGCE[i];
      }
      *out << endl;
    }
  }
  
  for(std::ostream* out : outs) {
    *out << setw(15) << "HML";

    for (int i = 0; i < namesCE.size(); ++i) {
      *out << setw(15) << 1.;
    }

    *out << endl;
  }

  fout.close();
}


