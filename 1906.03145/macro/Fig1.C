#include "inc/ThermalFistUtil.h"

void Fig1(){
 
  TGraph *g[3];
  g[0] = new TGraph("./dat/1906.03145.1_eBW.GCEDensitiesVsEcm.dat", "%lg %*lg %*lg %*lg %*lg %*lg %lg");
  g[1] = new TGraph("./dat/1906.03145.1_eBW.GCEDensitiesVsEcm.dat", "%lg %*lg %*lg %*lg %*lg %*lg %*lg %lg");
  g[2] = new TGraph("./dat/1906.03145.1_eBW.GCEDensitiesVsEcm.dat", "%lg %*lg %*lg %*lg %*lg %*lg %*lg %*lg %lg");

//=============================================================================
  auto dflx(2.e0), dfux(4.e3);
  auto dfly(0.), dfuy(1.);

  auto dlsx(0.05), dlsy(0.05);
  auto dtsx(0.05), dtsy(0.05);
  auto dtox(1.30), dtoy(1.10);

  TString stnx("#sqrt{#it{s}_{NN}} [GeV]");
  TString stny("");

  SetStyle(kTRUE);

  auto can(MakeCanvas(Form("Fig1")));
  can->SetLogx();
  auto hfm(can->DrawFrame(dflx, dfly, dfux, dfuy));
  SetupFrame(hfm, stnx, stny, dlsx, dlsy, dtsx, dtsy, dtox, dtoy);
  hfm->GetXaxis()->SetNdivisions(510);
  hfm->GetYaxis()->SetNdivisions(510);

//-----------------------------------------------------------------------------
  DrawGraph(g[0], wcl[0], wmk[0], wls[0], "L");
  DrawGraph(g[1], wcl[1], wmk[1], wls[1], "L");
  DrawGraph(g[2], wcl[2], wmk[2], wls[2], "L");

  auto leg(new TLegend(0.75, 0.9, 1., 0.7)); SetupLegend(leg);
  leg->AddEntry(g[0], "n_{B}/n_{tot}", "L")->SetTextSizePixels(24);
  leg->AddEntry(g[1], "n_{Q}/n_{tot}", "L")->SetTextSizePixels(24);
  leg->AddEntry(g[2], "n_{S}/n_{tot}", "L")->SetTextSizePixels(24);
  leg->Draw();

  //auto tex(new TLatex());
  //tex->SetNDC();
  //tex->SetTextSizePixels(24);
  //tex->DrawLatex(0.16, 0.92, "Thermal-FIST");
  //tex->DrawLatex(0.16, 0.2, "#mu_{B} = 0");

//-----------------------------------------------------------------------------
  can->SaveAs(Form("./figure/eps/Fig1.eps"));
  can->SaveAs(Form("./figure/pdf/Fig1.pdf"));
  can->SaveAs(Form("./figure/png/Fig1.png"));
  CanvasEnd(can);
  return;

}

