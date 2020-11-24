#include "TGraph.h"
void test1(){
  TCanvas *c1 = new TCanvas();
  TGraph* graph = new TGraph("/home/lenovo/Thermal-FIST/build/bin/examples/cpc1.Id-HRG.TDep.out","%lg %lg");
  graph->SetTitle("Thermal-FIST; T[MeV]; p/T^{4}");
  graph->Draw("AP");
}

