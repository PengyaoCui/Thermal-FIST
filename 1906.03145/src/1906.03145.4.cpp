#include "inc/loadFist.h"

void PrepareModel(ThermalModelBase * &model, ThermalParticleSystem *parts, const string& ensemble, const string& width_scheme);
void PrepareConfiguration(const string& syst, const string& ensemble, const string& width_scheme, const string& use_gs, double VcOverV);
void PerformFits(const string& syst, const string& ensemble, const string& width_scheme, const string& use_gs, double VcOverV);

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

vector<int> pdgs1, pdgs2;
vector<string> names1, names2;

//==================================================================
int main(){

  // Ratios to output
  names1.push_back("p");
  names2.push_back("pi");
  pdgs1.push_back(2212);
  pdgs2.push_back(211);
    
  names1.push_back("K");
  names2.push_back("pi");
  pdgs1.push_back(321);
  pdgs2.push_back(211);

  names1.push_back("phi");
  names2.push_back("pi");
  pdgs1.push_back(333);
  pdgs2.push_back(211);

  names1.push_back("La");
  names2.push_back("pi");
  pdgs1.push_back(3122);
  pdgs2.push_back(211);

  names1.push_back("Xi");
  names2.push_back("pi");
  pdgs1.push_back(3312);
  pdgs2.push_back(211);

  names1.push_back("Om");
  names2.push_back("pi");
  pdgs1.push_back(3334);
  pdgs2.push_back(211);

  names1.push_back("K*0");
  names2.push_back("K-");
  pdgs1.push_back(313);
  pdgs2.push_back(-321);
  
  names1.push_back("rho0");
  names2.push_back("pi");
  pdgs1.push_back(113);
  pdgs2.push_back(211);
  
  names1.push_back("La*");
  names2.push_back("La");
  pdgs1.push_back(3124);
  pdgs2.push_back(3122);
  
  names1.push_back("Ksi*0"); // Ksi(1530)
  names2.push_back("Ksi-");
  pdgs1.push_back(3324);
  pdgs2.push_back(3312);
  
  names1.push_back("Ksi**-"); // Ksi(1820)
  names2.push_back("La");
  pdgs1.push_back(13314);
  pdgs2.push_back(3122);
  
  names1.push_back("Del++");
  names2.push_back("p");
  pdgs1.push_back(2224);
  pdgs2.push_back(2212);
  
  names1.push_back("Sig*+");
  names2.push_back("La");
  pdgs1.push_back(3224);
  pdgs2.push_back(3122);
  
  names1.push_back("Sig*-");
  names2.push_back("La");
  pdgs1.push_back(3114);
  pdgs2.push_back(3122);

  PerformFits("pp", "GCE", "eBW", "gammaS", 3.0);
}

//==================================================================
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

//==================================================================
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

  }else if (syst == "pPb"){

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

  }else{
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

  for (int i = 0; i < outputnames.size(); ++i){
    outputnames[i] = width_scheme + "-" + outputnames[i];

    if (use_gs == "gammaS") outputnames[i] = "gammaS-" + outputnames[i];
    outputnames[i] = ensemble + "-" + outputnames[i];

    if (ensemble != "GCE") {
      char cc[500];
      sprintf(cc, "%lf", VcOverV);
      outputnames[i] = "VcOverV." + string(cc) + "-" + outputnames[i];
    }
    outputnames[i] = syst + "-" + outputnames[i];
  }

  outputDependence = width_scheme + "-" + outputDependence;
  if (use_gs == "gammaS") outputDependence = "gammaS-" + outputDependence;
  outputDependence = ensemble + "-" + outputDependence;
  if (ensemble != "GCE"){
    char cc[500];
    sprintf(cc, "%lf", VcOverV);
    outputDependence = "VcOverV." + string(cc) + "-" + outputDependence;
  }
  //outputDependence = syst + "-" + outputDependence;
  outputDependence = "out/fits/4_" + syst + "-" + outputDependence;
}

//==================================================================
void PerformFits(const string& syst, const string& ensemble, const string& width_scheme, const string& use_gs, double VcOverV){
  ThermalModelBase *model;
  PrepareModel(model, &parts, ensemble, width_scheme);
  PrepareConfiguration(syst, ensemble, width_scheme, use_gs, VcOverV);

  ofstream foutDep(outputDependence);

  foutDep << setw(20) << "dNchdeta";
  foutDep << setw(20) << "error";
  foutDep << setw(20) << "T[MeV]";
  foutDep << setw(20) << "error";
  foutDep << setw(20) << "gammaS";
  foutDep << setw(20) << "error";
  foutDep << setw(20) << "V[fm3]";
  foutDep << setw(20) << "error";
  foutDep << setw(20) << "Vc[fm3]";
  foutDep << setw(20) << "error";
  foutDep << setw(20) << "chi2";
  foutDep << setw(20) << "chi2dof";
  foutDep << setw(20) << "accuracy";
  foutDep << setw(20) << "accuracy_error";

  for (int i = 0; i < names1.size(); ++i) {
    foutDep << setw(20) << (names1[i] + "/" + names2[i]);
  }
  foutDep << endl;

  // Loop over all the data and do the fits
  // WARNING: This may take a while
  for (int ind = 0; ind < datafilenames.size(); ++ind){

    // Load the data from file
    vector<FittedQuantity> data = ThermalModelFit::loadExpDataFromFile(datafilenames[ind]);

    cout << data.size() << endl;

    // Fitter
    ThermalModelFit fitter(model);

    // Do not fit muB, it is fixed to zero
    fitter.SetParameterFitFlag("muB", false);

    // Total volume not too large
    fitter.SetParameter("R", 4.0, 2.0, 0.01, 12.0);//SetParameter(name, val, err, min, max)

    // Fit canonincal volume if not GCE, or use a fixed Vc/V ratio
    if (ensemble != "GCE") {
      if (VcOverV > 0.0) {
        fitter.SetVcOverV(VcOverV);
        fitter.FixVcOverV(true);
      }
      else {
        fitter.FixVcOverV(false);
        fitter.SetParameterFitFlag("Rc", true);
      }
    }

    // Fit (or not) gammaS
    if (use_gs == "gammaS") {
      fitter.SetParameter("gammaS", 1.0, 0.3, 0.2, 3.0);
      fitter.SetParameterFitFlag("gammaS", true);
    }

    // Set the data to be fitted
    fitter.SetQuantities(data);

    cout << "Fitting the " << outputnames[ind] << " data" << endl;

    // Performs the fit, the parameter suppresses the intermediate extra output
    ThermalModelFitParameters fit = fitter.PerformFit(false);

    cout << "Fit complete!" << endl;

    // Print the fit result on screen
    fitter.PrintFitLog();

    // Now print the results to file
    fitter.PrintYieldsTable("out/fits/4_" + std::string(outputnames[ind] + ".out"));
    std::string comment = "Thermal fit to " + datafilenames[ind] + " within " + fitter.model()->TAG();
    fitter.PrintFitLog("out/fits/4_" + std::string(outputnames[ind] + ".txt"), comment);

    cout << endl;
    cout << "--------------------------------------------------------";
    cout << endl;

    foutDep << setw(20) << dNchdEta[ind];
    foutDep << setw(20) << 0.;

    foutDep << setw(20) << 1.e3 * fit.T.value;
    foutDep << setw(20) << 1.e3 * fit.T.error;

    foutDep << setw(20) << fit.gammaS.value;
    foutDep << setw(20) << fit.gammaS.error;

    // Convert radius into volume, V = (4\pi/3) * R^3
    foutDep << setw(20) << 4. / 3. * xMath::Pi() * pow(fit.R.value, 3.);
    foutDep << setw(20) << 4. * xMath::Pi() * pow(fit.R.value, 2.) * fit.R.error;

    foutDep << setw(20) << 4. / 3. * xMath::Pi() * pow(fit.Rc.value, 3.);
    foutDep << setw(20) << 4. * xMath::Pi() * pow(fit.Rc.value, 2.) * fit.Rc.error;

    foutDep << setw(20) << fit.chi2;
    foutDep << setw(20) << fit.chi2ndf;


    std::pair<double, double> accuracy = fitter.ModelDescriptionAccuracy();//Returns a relative error of the data description (and its uncertainty estimate)
    foutDep << setw(20) << accuracy.first;
    foutDep << setw(20) << accuracy.second;

    model->CalculateDensities();

    for (int i = 0; i < pdgs1.size(); ++i) {
      foutDep << setw(20) << model->GetDensity(pdgs1[i], 1) / model->GetDensity(pdgs2[i], 1);
    }

    foutDep << endl;
    foutDep.flush();
  }

  foutDep.close();

  delete model;
}
