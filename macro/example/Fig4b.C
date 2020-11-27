#include "inc/ThermalFistUtil.h"

void Fig4b(){
 
  TGraph *g[3];
  g[0] = new TGraph("dat/cpc1.Id-HRG.TDep.out",  "%lg %*lg %lg");
  g[1] = new TGraph("dat/cpc1.EV-HRG.TDep.out",  "%lg %*lg %lg");
  g[2] = new TGraph("dat/cpc1.QvdW-HRG.TDep.out","%lg %*lg %lg");

//=============================================================================
  auto dflx(100.), dfux(200.);
  auto dfly(0.), dfuy(10.);

  auto dlsx(0.05), dlsy(0.05);
  auto dtsx(0.05), dtsy(0.05);
  auto dtox(1.30), dtoy(1.10);

  TString stnx("T (MeV)");
  TString stny("#varepsilon/T^{4}");

  SetStyle(kTRUE);

  auto can(MakeCanvas(Form("Fig4b")));
  //can->SetLogy();
  auto hfm(can->DrawFrame(dflx, dfly, dfux, dfuy));
  SetupFrame(hfm, stnx, stny, dlsx, dlsy, dtsx, dtsy, dtox, dtoy);
  hfm->GetXaxis()->SetNdivisions(510);
  hfm->GetYaxis()->SetNdivisions(510);

//-----------------------------------------------------------------------------
  g[0]->SetLineStyle(1);
  g[1]->SetLineStyle(2);
  g[2]->SetLineStyle(7);
  DrawGraph(g[0], wcl[0], "L");
  DrawGraph(g[1], wcl[1], "L");
  DrawGraph(g[2], wcl[2], "L");

  auto leg(new TLegend(0.2, 0.80, 0.4, 0.6)); SetupLegend(leg);
  leg->AddEntry(g[0], "Id-HRG", "L")->SetTextSizePixels(24);
  leg->AddEntry(g[1], "EV-HRG", "L")->SetTextSizePixels(24);
  leg->AddEntry(g[2], "QvdW-HRG", "L")->SetTextSizePixels(24);
  leg->Draw();

  auto tex(new TLatex());
  tex->SetNDC();
  tex->SetTextSizePixels(24);
  tex->DrawLatex(0.16, 0.92, "Thermal-FIST");
  tex->DrawLatex(0.16, 0.2, "#mu_{B} = 0");

//-----------------------------------------------------------------------------
  can->SaveAs(Form("./figure/eps/Fig4b.eps"));
  can->SaveAs(Form("./figure/pdf/Fig4b.pdf"));
  can->SaveAs(Form("./figure/png/Fig4b.png"));
  CanvasEnd(can);
  return;

}

