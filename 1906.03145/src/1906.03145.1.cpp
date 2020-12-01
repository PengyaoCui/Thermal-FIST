#include <string.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdio>

#include "HRGBase.h"
#include "HRGEV.h"
#include "HRGFit.h"
#include "HRGVDW.h"

#include "ThermalFISTConfig.h"

using namespace std;

#ifdef ThermalFIST_USENAMESPACE
using namespace thermalfist;
#endif

int main(int argc, char *argv[])
{

//==================================================================================================== 
  string listname = string(ThermalFIST_INPUT_FOLDER) + "/list/PDG2014/list.dat";
  ThermalParticleSystem TPS(listname);

//==================================================================================================== 
  ThermalModelBase* model;
  model = new ThermalModelIdeal(&TPS);

  model->ConstrainMuS(true);
  model->ConstrainMuQ(true);
  model->ConstrainMuC(true);
  model->SetQoverB(0.4);
  model->SetStatistics(false);  // neglect quantum statistics  Boltzmann
  model->SetUseWidth(ThermalParticle::eBW);
  //model->SetTemperature(T);
  //model->SetCanonicalVolumeRadius(config.VolumeRSC);

  //model->GetDensity(2212, Feeddown::Electromagnetic);




  return 0;
}
