#include "./inc/ThermalFistUtil.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

void Fig1(){
 
    ifstream infile; 
    infile.open("./dat/ZeroWidth-vs-BW-vs-eBW-vs-T.dat");
    assert(infile.is_open());

    string s;
    int i =0;
    s = infile.getline(e, 135)
    cout<<s<<endl; 
    infile.close();

//=============================================================================
#if 0
  auto dflx(100.), dfux(200.);
  auto dfly(0.), dfuy(2.);

  auto dlsx(0.05), dlsy(0.05);
  auto dtsx(0.05), dtsy(0.05);
  auto dtox(1.30), dtoy(1.10);

  TString stnx("T (MeV)");
  TString stny("p/T^{4}");

  SetStyle(kTRUE);

  auto can(MakeCanvas(Form("Fig4a")));
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
  can->SaveAs(Form("./figure/eps/Fig4a.eps"));
  can->SaveAs(Form("./figure/pdf/Fig4a.pdf"));
  can->SaveAs(Form("./figure/png/Fig4a.png"));
  CanvasEnd(can);
#endif
  return;

}

