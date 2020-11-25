#include "inc/ThermalFistUtil.h"

void Fig5(){
 
  //TGraph *g[3];
  //g[0] = new TGraph("dat/cpc1.Id-HRG.TDep.out",  "%lg %lg");
  //g[1] = new TGraph("dat/cpc1.EV-HRG.TDep.out",  "%lg %lg");
  //g[2] = new TGraph("dat/cpc1.QvdW-HRG.TDep.out","%lg %lg");
  auto g = new TGraph("dat/cpc2.Id-HRG.ALICE2_76.chi2.TDep.out","%lg %*lg %*lg %lg");

//=============================================================================
  auto dflx(100.), dfux(350.);
  auto dfly(0.), dfuy(100.);

  auto dlsx(0.05), dlsy(0.05);
  auto dtsx(0.05), dtsy(0.05);
  auto dtox(1.30), dtoy(1.10);

  TString stnx("T (MeV)");
  TString stny("#chi^{2}");

  SetStyle(kTRUE);

  auto can(MakeCanvas(Form("Fig5")));
  //can->SetLogy();
  auto hfm(can->DrawFrame(dflx, dfly, dfux, dfuy));
  SetupFrame(hfm, stnx, stny, dlsx, dlsy, dtsx, dtsy, dtox, dtoy);
  hfm->GetXaxis()->SetNdivisions(510);
  hfm->GetYaxis()->SetNdivisions(510);

//-----------------------------------------------------------------------------
  g->SetLineStyle(1);
  DrawGraph(g, wcl[0], "L");

  auto leg(new TLegend(0.75, 0.90, 0.9, 0.7)); SetupLegend(leg);
  leg->AddEntry(g, "Id-HRG", "L")->SetTextSizePixels(24);
  leg->Draw();

  auto tex(new TLatex());
  tex->SetNDC();
  tex->SetTextSizePixels(24);
  tex->DrawLatex(0.76, 0.9, "Thermal-FIST");
  tex->DrawLatex(0.16, 0.2, "#mu_{B} = 0");

//-----------------------------------------------------------------------------
  can->SaveAs(Form("./figure/eps/Fig5.eps"));
  can->SaveAs(Form("./figure/pdf/Fig5.pdf"));
  can->SaveAs(Form("./figure/png/Fig5.png"));
  CanvasEnd(can);
  return;

}

