#include "inc/ThermalFistUtil.h"

void Fig2(){
  

//=============================================================================


//=============================================================================
  auto dflx(0.), dfux(12.);
  auto dfly(5e-7), dfuy(5.);
  
  auto dlsx(0.05), dlsy(0.05);
  auto dtsx(0.05), dtsy(0.05);
  auto dtox(1.30), dtoy(1.10);
  
  TString stnx("#it{p}_{T} (GeV/#it{c})");
  TString stny("d#it{#rho}/d#it{p}_{T} (GeV/#it{c} rad)^{-1}");
  
  SetStyle(kTRUE);
  
  auto can(MakeCanvas("Fig2"));

  TPad *p1= nullptr; TPad *p2= nullptr; TPad *p3= nullptr; TPad *p4 = nullptr;

  p1 = MakePadTL("p1"); can->cd(); //p1->SetLogy(); 
  p2 = MakePadTR("p2"); can->cd(); //p2->SetLogy();
  p3 = MakePadBL("p3"); can->cd(); //p3->SetLogy();
  p4 = MakePadBR("p4"); can->cd(); //p4->SetLogy();

  p1->cd();
  auto hfm(p1->DrawFrame(dflx, dfly, dfux, dfuy));
  SetupFrame(hfm, stnx, stny, dlsx, dlsy, dtsx, dtsy, dtox, dtoy);
  hfm->GetXaxis()->SetNdivisions(510);
  hfm->GetYaxis()->SetNdivisions(510);
  hfm->GetXaxis()->CenterTitle(kTRUE);
  //DrawHisto(hK[3], wcl[1], wmk[1], "same"); DrawGraph(gEK[3], wcl[1], "E2");
  //tex->DrawLatex(0.25, 0.1, "K^{0}_{S}");
  can->cd();
 
  p2->cd();
  hfm = p2->DrawFrame(dflx, dfly, dfux, dfuy);
  SetupFrame(hfm, stnx, stny, dlsx, dlsy, dtsx, dtsy, dtox, dtoy);
  hfm->GetXaxis()->SetNdivisions(510);
  hfm->GetYaxis()->SetNdivisions(510);
  hfm->GetXaxis()->CenterTitle(kTRUE);
  //DrawHisto(hL[3], wcl[1], wmk[1], "same"); DrawGraph(gEL[3], wcl[1], "E2");
  //tex->DrawLatex(0.25, 0.1, "#Lambda + #bar{#Lambda}");
  can->cd();

  p3->cd();
  hfm = p3->DrawFrame(dflx, dfly, dfux, dfuy);
  SetupFrame(hfm, stnx, stny, dlsx, dlsy, dtsx, dtsy, dtox, dtoy);
  hfm->GetXaxis()->SetNdivisions(510);
  hfm->GetYaxis()->SetNdivisions(510);
  hfm->GetXaxis()->CenterTitle(kTRUE);
  //DrawHisto(hL[3], wcl[1], wmk[1], "same"); DrawGraph(gEL[3], wcl[1], "E2");
  //tex->DrawLatex(0.25, 0.1, "#Lambda + #bar{#Lambda}");
  can->cd();
 
  p4->cd();
  hfm = p4->DrawFrame(dflx, dfly, dfux, dfuy);
  SetupFrame(hfm, stnx, stny, dlsx, dlsy, dtsx, dtsy, dtox, dtoy);
  hfm->GetXaxis()->SetNdivisions(505);
  hfm->GetYaxis()->SetNdivisions(505);
  hfm->GetXaxis()->CenterTitle(kTRUE);
  //DrawHisto(hL[3], wcl[1], wmk[1], "same"); DrawGraph(gEL[3], wcl[1], "E2");
  //tex->DrawLatex(0.25, 0.1, "#Lambda + #bar{#Lambda}");
  can->cd();



  auto leg(new TLegend(0.72, 0.65, 0.98, 0.86)); SetupLegend(leg);
  //leg->AddEntry(hK[0], "Inclusive", "LP")->SetTextSizePixels(24);
  //leg->AddEntry(gE[0], "Sys. Error", "f")->SetTextSizePixels(24);
  leg->Draw();

  auto tex(new TLatex());
  tex->SetNDC();
  tex->SetTextSizePixels(24);
  tex->DrawLatex(0.16, 0.92, "ALICE pp #sqrt{#it{s}} = 13 TeV");
  tex->DrawLatex(0.16, 0.3, "#it{R}(K^{0}_{S}, jet) < 0.4, |#eta_{K^{0}_{S}}| < 0.75");
  tex->DrawLatex(0.16, 0.2, "Jet: anti-#it{k}_{T}, #it{R} = 0.4, #it{p}_{T, jet}^{ch} > 10 GeV/#it{c}, |#eta_{jet}| < 0.35");
  tex->DrawLatex(0.86, 0.9, "K^{0}_{S}");
  
  //can->SaveAs(Form("./figure/eps/%s.eps", can->GetName()));
  //can->SaveAs(Form("./figure/pdf/%s.pdf", can->GetName()));
  //can->SaveAs(Form("./figure/png/%s.png", can->GetName()));
  CanvasEnd(can);

  return;
}

