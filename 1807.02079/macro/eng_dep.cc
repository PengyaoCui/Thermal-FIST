#include <stdio.h>
#include <iostream>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

void eng_dep(){
	
	TString energy[7]= {"7.7Gev","11.5Gev", "19.6Gev", "27Gev" , "39Gev", "62Gev", "200Gev"};
	TString energy1[7]= {"7","11", "19", "27" , "39", "62", "200"};
	TString Buff_t, Buff_d, Buff_p, Buff_na;	
	const Int_t ncen = 4,  neng = 7, na_nen = 5;
	Float_t eng[neng] = {7.7, 11.5, 19.6, 27, 39, 62, 200};
	Float_t dndyt[neng]={},dndyt_e[neng], dndy_t[neng][ncen], dndy_t_stse[neng][ncen], dndy_t_syse[neng][ncen], dndy_t_err[neng][ncen];  
	Float_t dndyd[neng]={}, dndy_d[neng][ncen+1], dndy_d_stse[neng][ncen+1], dndy_d_syse[neng][ncen+1], dndy_d_err[neng][ncen];  
	Float_t dndyp[neng]={}, dndy_p[neng][ncen+5], dndy_p_stse[neng][ncen+5], dndy_p_syse[neng][ncen+5];  
	Float_t rf[neng], ggg;

	Float_t na_ene[na_nen], na_r[na_nen], na_re[na_nen];
	ifstream out1[neng][ncen], out2[neng], out3[neng], out_na;

	for(int k = 0; k < neng; k++ ){
				for(int j = 0; j < ncen; j++){
				Buff_t = Form("/home/zhangdw/lightNuclei/triton/blast_wave/%s/data/dndyd%d.txt", energy[k].Data(), j+1);
				out1[k][j].open(Buff_t.Data());
				out1[k][j] >> dndy_t[k][j] >> dndy_t_stse[k][j] >> dndy_t_syse[k][j];	
				dndyt[k] = dndyt[k] + dndy_t[k][j];
				
				}
				cout << "t:\t"<<dndyt[k] << endl;
		    	//cout << dndyt[k] << endl;
			Buff_d = Form("/home/zhangdw/lightNuclei/deuteron/data/dndy/dndy%s.txt", energy1[k].Data());
			out2[k].open(Buff_d.Data());
			//cout << Buff_d << endl;
				for(int j = 0; j < 5; j++){
				out2[k] >> ggg >> ggg >> ggg >> dndy_d[k][j] >> dndy_d_stse[k][j] >> dndy_d_syse[k][j];
				dndyd[k] = dndyd[k] + dndy_d[k][j];
				}
				cout <<"d:\t"<< dndyd[k] << endl;
			Buff_p = Form("/home/zhangdw/lightNuclei/proton/data/dndy/%s.txt",energy1[k].Data());
			out3[k].open(Buff_p.Data());
				//cout << Buff_p << endl;
				for(int j = 0; j < 9; j++){
				out3[k] >> dndy_p[k][j] >> dndy_p_stse[k][j] >> dndy_p_syse[k][j];
				dndyp[k] = dndyp[k] + dndy_p[k][j];
				cout <<"p:\t"<< dndyp[k] << endl;
				
			}
			
			rf[k] = dndyt[k]*dndyp[k]/dndyd[k]/dndyd[k];
		//	cout << "r:\t"<<rf[k] << endl;	
		//	cout << "\t" << endl;

	}
		Buff_na = Form("/home/zhangdw/lightNuclei/ratio/na49/data.txt");
		out_na.open(Buff_na);
		for(i = 0; i < na_nen; i++){
		out_na >> na_ene[i] << na_r[i] << na_re[i] << endl; 	
		cout << ne_ene[i] << na_r[i] << na_re[i] << endl;

		}

	c1 = new TCanvas("c1", "c1", 0, 0, 800, 600);
	c1->SetLogx();
	c1->SetLogy();
	c1->SetLeftMargin(0.15);
	c1->SetRightMargin(0.15);
	c1->SetTopMargin(0.06);
	c1->SetBottomMargin(0.15);

	TPad *pad = new TPad("pad","pad", 0.1, 0.1, 1, 1);
	pad->SetLogy();
	pad->SetTopMargin(0.06);
	pad->SetBottomMargin(0.14);
	pad->SetRightMargin(0.14);
	pad->SetLeftMargin(0.14);
	pad->Draw();

		TH2F *gr = new TH2F("","",1000,0,1000,100,1e-3,2 );
		gr->SetStats(0);

		gr->GetXaxis()->SetRangeUser(0,1000);
		gr->GetXaxis()->SetTitle("#sqrt{S_{NN}}");
		gr->GetXaxis()->SetTitleFont(62);
		gr->GetXaxis()->SetTitleSize(0.05);
		gr->GetXaxis()->SetTitleOffset(1);
		gr->GetXaxis()->SetNdivisions(505);
		//gr->GetYaxis()->SetRangeUser(-0.001, -0.009);
		//gr->G
		gr->GetYaxis()->SetTitle("R");
		gr->GetYaxis()->SetTitleFont(62);
		gr->GetYaxis()->SetTitleSize(0.05);
		gr->GetYaxis()->SetTitleOffset(1);
		gr->GetYaxis()->SetNdivisions(505);
		gr->GetYaxis()->CenterTitle();
		gr->Draw();	
			
		gr1 = new TGraphErrors(neng, eng, dndyt, 0, 0);
		gr1->SetMarkerColor(1);
		gr1->SetMarkerStyle(20);
		gr1->SetMarkerSize(1.5);
		//gr1->Draw("P");

		gr2 = new TGraphErrors(neng, eng, dndyd, 0, 0);
		gr2->SetMarkerStyle(20);
		gr2->SetMarkerColor(2);
		gr2->SetMarkerSize(1.5);
		//gr2->Draw("P");

		gr3 = new TGraphErrors(neng, eng, dndyp, 0,0);
		gr3->SetMarkerStyle(20);
		gr3->SetMarkerColor(4);
		gr3->SetMarkerSize(1.5);
		//gr3->Draw("P");
		
		gr43 = new TGraphErrors(neng, eng, rf, 0,0);
		gr43->SetMarkerStyle(20);
		gr43->SetMarkerColor(2);
		gr43->SetMarkerSize(1.5);
		gr43->Draw("P");

		tex = new TLatex (100, -0.0075,"p_{T}=1.0GeV/c");
		tex->SetTextFont(62);
		tex->SetTextColor(4);
		tex->SetTextSize(0.03);
	//	tex->Draw();
		tex = new TLatex (100, -0.0085,"p_{T}=0.8GeV/c");
		tex->SetTextFont(62);
		tex->SetTextColor(2);
		tex->SetTextSize(0.03);
	//	tex->Draw();
		tex = new TLatex (100, -0.0095,"p_{T}=0.6GeV/c");
		tex->SetTextFont(62);
		tex->SetTextColor(1);
		tex->SetTextSize(0.03);
	//	tex->Draw();
		tex = new TLatex (10, -0.008,"AuAu Collision 0-80%");
		tex->SetTextFont(62);
		tex->SetTextColor(1);
		tex->SetTextSize(0.04);
	//	tex->Draw();

}

