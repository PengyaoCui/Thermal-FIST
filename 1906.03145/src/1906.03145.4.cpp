#include "inc/loadFist.h"


// Particle list
//ThermalParticleSystem parts(string(ThermalFIST_INPUT_FOLDER) + "/list/PDG2014/list-withnuclei.dat");
ThermalParticleSystem parts(string(ThermalFIST_INPUT_FOLDER) + "/list/PDG2014/list.dat");

// Different data to be fitted, 
vector<string> datafilenames;
// Names for output
vector<string> outputnames;
// Nch multiplicities
vector<double> dNchdEta;

// Output file name
std::string outputDependence = "vs-dNdEta.dat";

int main(){

}

void PrepareModel(ThermalModelBase * &model, ThermalParticleSystem *parts, const string& ensemble, const string& width_scheme){
  if (ensemble == "GCE"){
    model = new ThermalModelIdeal(parts);
  }else{
    model = new ThermalModelCanonical(parts);
    // For SCE treat B & Q grand-canonically
    if (ensemble == "SCE") {
      static_cast<ThermalModelCanonical*>(model)->ConserveBaryonCharge(false);
      static_cast<ThermalModelCanonical*>(model)->ConserveElectricCharge(false);
    }
  }

  ThermalModelParameters params;
  // Chemical potentials are fixed to zero
  params.muB = 0.0;
  params.muQ = 0.0;
  params.muS = 0.0;
  params.muC = 0.0;

  // Initial temperature value in fits
  params.T = 0.155;

  // Quantum numbers are zero
  params.B = params.Q = params.S = params.C = 0;

  model->SetParameters(params);

  // Quantum statistics only for pions
  model->SetStatistics(true);
  for(int i = 0; i < model->TPS()->Particles().size(); ++i){
    ThermalParticle &part = model->TPS()->Particle(i);
    if (part.BaryonCharge() != 0) part.UseStatistics(false);
  }

  if (ensemble != "GCE") static_cast<ThermalModelCanonical*>(model)->CalculateQuantumNumbersRange();

  // Set resonance widths scheme
  if (width_scheme == "ZeroWidth") model->SetUseWidth(ThermalParticle::ZeroWidth);
  else if (width_scheme == "BWTwoGamma") model->SetUseWidth(ThermalParticle::BWTwoGamma);
  else model->SetUseWidth(ThermalParticle::eBW);

  model->FillChemicalPotentials();
}

void PrepareConfiguration(const string& syst, const string& ensemble, const string& width_scheme, const string& use_gs, double VcOverV){

  datafilenames.resize(0);
  outputnames.resize(0);
  dNchdEta.resize(0);

  if (syst == "pp"){

    std::string datafolder = string(ThermalFIST_INPUT_FOLDER) + "/../../input/data/pp";

    // V0M-I-II
    datafilenames.push_back(datafolder + "/ALICE-pp7TeV-V0M-I-II.dat");
    outputnames.push_back("ALICE-pp7TeV-V0M-I-II");
    dNchdEta.push_back(18.9);

    // V0M-III-IV
    datafilenames.push_back(datafolder + "/ALICE-pp7TeV-V0M-III-IV.dat");
    outputnames.push_back("ALICE-pp7TeV-V0M-III-IV");
    dNchdEta.push_back(12.5);

    // V0M-V-VI
    datafilenames.push_back(datafolder + "/ALICE-pp7TeV-V0M-V-VI.dat");
    outputnames.push_back("ALICE-pp7TeV-V0M-V-VI");
    dNchdEta.push_back(9.275);

    // V0M-VII-VIII
    datafilenames.push_back(datafolder + "/ALICE-pp7TeV-V0M-VII-VIII.dat");
    outputnames.push_back("ALICE-pp7TeV-V0M-VII-VIII");
    dNchdEta.push_back(6.06);

    // V0M-IX-X
    datafilenames.push_back(datafolder + "/ALICE-pp7TeV-V0M-IX-X.dat");
    outputnames.push_back("ALICE-pp7TeV-V0M-IX-X");
    dNchdEta.push_back(3.08);

  }
  else if (syst == "pPb") {

      std::string datafolder = string(ThermalFIST_INPUT_FOLDER) + "/../../input/data/pPb";

      // V0A0005
      datafilenames.push_back(datafolder + "/ALICE-pPb5TeV-V0A0005.dat");
      outputnames.push_back("ALICE-pPb5TeV-V0A0005");
      dNchdEta.push_back(45);

      // V0A0510
      datafilenames.push_back(datafolder + "/ALICE-pPb5TeV-V0A0510.dat");
      outputnames.push_back("ALICE-pPb5TeV-V0A0510");
      dNchdEta.push_back(36.2);

      // V0A1020
      datafilenames.push_back(datafolder + "/ALICE-pPb5TeV-V0A1020.dat");
      outputnames.push_back("ALICE-pPb5TeV-V0A1020");
      dNchdEta.push_back(30.5);

      // V0A2040
      datafilenames.push_back(datafolder + "/ALICE-pPb5TeV-V0A2040.dat");
      outputnames.push_back("ALICE-pPb5TeV-V0A2040");
      dNchdEta.push_back(23.2);

      // V0A4060
      datafilenames.push_back(datafolder + "/ALICE-pPb5TeV-V0A4060.dat");
      outputnames.push_back("ALICE-pPb5TeV-V0A4060");
      dNchdEta.push_back(16.1);

      // V0A6080
      datafilenames.push_back(datafolder + "/ALICE-pPb5TeV-V0A6080.dat");
      outputnames.push_back("ALICE-pPb5TeV-V0A6080");
      dNchdEta.push_back(9.8);

      // V0A8000
      datafilenames.push_back(datafolder + "/ALICE-pPb5TeV-V0A8000.dat");
      outputnames.push_back("ALICE-pPb5TeV-V0A8000");
      dNchdEta.push_back(4.4);

  }
  else {
      std::string datafolder = string(ThermalFIST_INPUT_FOLDER) + "/../../input/data/PbPb";

      // 0-10
      datafilenames.push_back(datafolder + "/ALICE-PbPb2.76TeV-0-10-all-symmetrized.dat");
      outputnames.push_back("ALICE-PbPb5TeV-0010");
      dNchdEta.push_back(1447.5);

      // 10-20
      datafilenames.push_back(datafolder + "/ALICE-PbPb2.76TeV-10-20-all-symmetrized.dat");
      outputnames.push_back("ALICE-PbPb5TeV-1020");
      dNchdEta.push_back(966);

      // 20-40
      datafilenames.push_back(datafolder + "/ALICE-PbPb2.76TeV-20-40-all-symmetrized.dat");
      outputnames.push_back("ALICE-PbPb5TeV-2040");
      dNchdEta.push_back(537.5);

      // 40-60
      datafilenames.push_back(datafolder + "/ALICE-PbPb2.76TeV-40-60-all-symmetrized.dat");
      outputnames.push_back("ALICE-PbPb5TeV-4060");
      dNchdEta.push_back(205);

      // 60-80
      datafilenames.push_back(datafolder + "/ALICE-PbPb2.76TeV-60-80-all-symmetrized.dat");
      outputnames.push_back("ALICE-PbPb5TeV-6080");
      dNchdEta.push_back(55.5);
  }

  outputDependence = "vs-dNdEta.dat";

  for (int i = 0; i < outputnames.size(); ++i) {
      outputnames[i] = width_scheme + "-" + outputnames[i];

      if (use_gs == "gammaS") {
          outputnames[i] = "gammaS-" + outputnames[i];

      }
      outputnames[i] = ensemble + "-" + outputnames[i];

      if (ensemble != "GCE") {
        char cc[500];
        sprintf(cc, "%lf", VcOverV);
        outputnames[i] = "VcOverV." + string(cc) + "-" + outputnames[i];
      }

          outputnames[i] = syst + "-" + outputnames[i];
      }

  outputDependence = width_scheme + "-" + outputDependence;
  if (use_gs == "gammaS")
      outputDependence = "gammaS-" + outputDependence;
  outputDependence = ensemble + "-" + outputDependence;
  if (ensemble != "GCE") {
    char cc[500];
    sprintf(cc, "%lf", VcOverV);
    outputDependence = "VcOverV." + string(cc) + "-" + outputDependence;
  }
  //outputDependence = syst + "-" + outputDependence;
  outputDependence = "out/fits/4_" + syst + "-" + outputDependence;
}
