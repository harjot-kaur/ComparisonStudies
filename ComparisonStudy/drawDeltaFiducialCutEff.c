#include <iostream>
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TPaveStats.h"
void drawDeltaFiducialCutEff(std::string infilename1, std::string infilename2, std::string outfilename)
{

//gSystem->Exec("mkdir output/Barrel/DeltaFiducialCutEff/");
//gSystem->Exec("mkdir output/Endcap/DeltaFiducialCutEff/");
//Define Canvas	
/*TCanvas *c1 = new TCanvas("c1", "c1", 61,24,800,800);
c1->Range(2.40754,-1.002296,9.425494,6.993801);
*/

//Open the root file

//TFile *f1 = TFile::Open("SummaryAnalyzeEfficiency_Express2021_339579.root");
//TFile *f2 = TFile::Open("SummaryAnalyzeEfficiency_Express2021_340323.root");


TFile *f1 = TFile::Open(infilename1.c_str());
TFile *f2 = TFile::Open(infilename2.c_str());


//Open Barrel directory
TDirectory* dir_barrel1 = (TDirectory*)f1->Get("Barrel");
TDirectory* dir_barrel2 = (TDirectory*)f2->Get("Barrel");
//------------------------------------------------------------------------
//Define input 2D hist
//------------------------------------------------------------------------

TH2F *FCEWm11, *FCEWm21, *FCEW01, *FCEW11, *FCEW21;             //Fiducial cut efficiencies
TH2F *FCEWm12, *FCEWm22, *FCEW02, *FCEW12, *FCEW22;             //Fiducial cut efficiencies



//------------------------------------------------------------------------
//extract the hist
//------------------------------------------------------------------------

//Fiducial cut efficiencies
dir_barrel1->GetObject("FiducialCutEffW-1",FCEWm11);
dir_barrel1->GetObject("FiducialCutEffW-2",FCEWm21);
dir_barrel1->GetObject("FiducialCutEffW0",FCEW01);
dir_barrel1->GetObject("FiducialCutEffW1",FCEW11);
dir_barrel1->GetObject("FiducialCutEffW2",FCEW21);



dir_barrel2->GetObject("FiducialCutEffW-1",FCEWm12);
dir_barrel2->GetObject("FiducialCutEffW-2",FCEWm22);
dir_barrel2->GetObject("FiducialCutEffW0",FCEW02);
dir_barrel2->GetObject("FiducialCutEffW1",FCEW12);
dir_barrel2->GetObject("FiducialCutEffW2",FCEW22);


//------------------------------------------------------------------------


//------------------------------------------------------------------------
//define output hist
//------------------------------------------------------------------------



//Fiducial cut efficiencies
TH1F *out_FCEWm1 = new TH1F("DeltaFiducialCutEffW-1","Delta Fiducial Cut Efficiency - Wheel -1",201,-100.5,100.5);
TH1F *out_FCEWm2 = new TH1F("DeltaFiducialCutEffW-2","Delta Fiducial Cut Efficiency - Wheel -2",201,-100.5,100.5);
TH1F *out_FCEW0 = new TH1F("DeltaFiducialCutEffW0","Delta Fiducial Cut Efficiency - Wheel 0",201,-100.5,100.5);
TH1F *out_FCEW1 = new TH1F("DeltaFiducialCutEffW1","Delta Fiducial Cut Efficiency - Wheel 1",201,-100.5,100.5);
TH1F *out_FCEW2 = new TH1F("DeltaFiducialCutEffW2","Delta Fiducial Cut Efficiency - Wheel 2",201,-100.5,100.5);



//------------------------------------------------------------------------
//Define array to be filled in output
//------------------------------------------------------------------------

float arr_FCEWm1[500], arr_FCEWm2[500], arr_FCEW0[500], arr_FCEW1[500], arr_FCEW2[500];             //Fiducial cut efficiencies

//------------------------------------------------------------------------


int max;

for(int i = 1; i<=12; i++)
{
	if(i<=3){max=17;}
	else if(i==4){max=21;}
	else if(i>4 && i<=8){max=17;}
	else if(i==9 || i==11){max=15;}
	else {max=17;}
	for(int k = 1; k<=max; k++){
//cout<<"i="<<i<<", k="<<k<<endl;



//Fiducial cut efficiencies
arr_FCEWm1[i] = ((FCEWm12->GetBinContent(i,k)) - (FCEWm11->GetBinContent(i,k)));
arr_FCEWm2[i] = ((FCEWm22->GetBinContent(i,k)) - (FCEWm21->GetBinContent(i,k)));
arr_FCEW0[i] = ((FCEW02->GetBinContent(i,k)) - (FCEW01->GetBinContent(i,k)));
arr_FCEW1[i] = ((FCEW12->GetBinContent(i,k)) - (FCEW11->GetBinContent(i,k)));
arr_FCEW2[i] = ((FCEW22->GetBinContent(i,k)) - (FCEW21->GetBinContent(i,k)));



//------------------------------------------------------------------------
//Fill output hist
//------------------------------------------------------------------------


//Fiducial cut efficiencies
out_FCEWm1->Fill(arr_FCEWm1[i]);
out_FCEWm2->Fill(arr_FCEWm2[i]);
out_FCEW0->Fill(arr_FCEW0[i]);
out_FCEW1->Fill(arr_FCEW1[i]);
out_FCEW2->Fill(arr_FCEW2[i]);


	}

}

//TFile *out = new TFile("test.root", "RECREATE");

TFile *out = TFile::Open(outfilename.c_str(), "RECREATE");

out->mkdir("Barrel");
out->mkdir("Endcap");

//------------------------------------------------------------------------
//Write hist to directory
//------------------------------------------------------------------------


        out->cd("/Barrel");

out->mkdir("Barrel/Delta_Fiducial_cut_efficiencies/");
out->cd("Barrel/Delta_Fiducial_cut_efficiencies/");
//Fiducial cut efficiencies
out_FCEWm1->Write();
TCanvas *Barrel_DeltaFCEWm1 = new TCanvas(Form("DeltaFiducialCutEffW-1"));
out_FCEWm1->Draw();
Barrel_DeltaFCEWm1->SaveAs("DeltaFiducialCutEffW-1.png");

out_FCEWm2->Write();
TCanvas *Barrel_DeltaFCEWm2 = new TCanvas(Form("DeltaFiducialCutEffW-2"));
out_FCEWm2->Draw();
Barrel_DeltaFCEWm2->SaveAs("DeltaFiducialCutEffW-2.png");


out_FCEW0->Write();
TCanvas *Barrel_DeltaFCEW0 = new TCanvas(Form("DeltaFiducialCutEffW0"));
out_FCEW0->Draw();
Barrel_DeltaFCEW0->SaveAs("DeltaFiducialCutEffW0.png");


out_FCEW1->Write();
TCanvas *Barrel_DeltaFCEW1 = new TCanvas(Form("DeltaFiducialCutEffW1"));
out_FCEW1->Draw();
Barrel_DeltaFCEW1->SaveAs("DeltaFiducialCutEffW1.png");


out_FCEW2->Write();
TCanvas *Barrel_DeltaFCEW2 = new TCanvas(Form("DeltaFiducialCutEffW2"));
out_FCEW2->Draw();
Barrel_DeltaFCEW2->SaveAs("DeltaFiducialCutEffW2.png");



	
//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------
//Endacap
//----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------

//Open Endcap directory
TDirectory* dir_endcap1 = (TDirectory*)f1->Get("Endcap");
TDirectory* dir_endcap2 = (TDirectory*)f2->Get("Endcap");
//------------------------------------------------------------------------
//Define input 2D hist
//------------------------------------------------------------------------

TH2F *FCEDm11, *FCEDm21, *FCEDm31, *FCEDm41, *FCED41, *FCED31, *FCED11, *FCED21;             //Fiducial cut efficiencies
TH2F *FCEDm12, *FCEDm22, *FCEDm32, *FCEDm42, *FCED42, *FCED32, *FCED12, *FCED22;             //Fiducial cut efficiencies

//------------------------------------------------------------------------
//extract the hist
//------------------------------------------------------------------------
//Fiducial cut efficiencies
dir_endcap1->GetObject("FiducialCutEffD-1",FCEDm11);
dir_endcap1->GetObject("FiducialCutEffD-2",FCEDm21);
dir_endcap1->GetObject("FiducialCutEffD-3",FCEDm31);
dir_endcap1->GetObject("FiducialCutEffD-4",FCEDm41);
dir_endcap1->GetObject("FiducialCutEffD1",FCED11);
dir_endcap1->GetObject("FiducialCutEffD2",FCED21);
dir_endcap1->GetObject("FiducialCutEffD3",FCED31);
dir_endcap1->GetObject("FiducialCutEffD4",FCED41);

dir_endcap2->GetObject("FiducialCutEffD-1",FCEDm12);
dir_endcap2->GetObject("FiducialCutEffD-2",FCEDm22);
dir_endcap2->GetObject("FiducialCutEffD-3",FCEDm32);
dir_endcap2->GetObject("FiducialCutEffD-4",FCEDm42);
dir_endcap2->GetObject("FiducialCutEffD1",FCED12);
dir_endcap2->GetObject("FiducialCutEffD2",FCED22);
dir_endcap2->GetObject("FiducialCutEffD3",FCED32);
dir_endcap2->GetObject("FiducialCutEffD4",FCED42);



//------------------------------------------------------------------------


//------------------------------------------------------------------------
//define output hist
//------------------------------------------------------------------------


//Fiducial cut efficiencies
TH1F *out_FCEDm1 = new TH1F("DeltaFiducialCutEffD-1","Delta Fiducial Cut Efficiency - Disk -1",201,-100.5,100.5);
TH1F *out_FCEDm2 = new TH1F("DeltaFiducialCutEffD-2","Delta Fiducial Cut Efficiency - Disk -2",201,-100.5,100.5);
TH1F *out_FCEDm3 = new TH1F("DeltaFiducialCutEffD-3","Delta Fiducial Cut Efficiency - Disk -3",201,-100.5,100.5);
TH1F *out_FCEDm4 = new TH1F("DeltaFiducialCutEffD-4","Delta Fiducial Cut Efficiency - Disk -4",201,-100.5,100.5);
TH1F *out_FCED1 = new TH1F("DeltaFiducialCutEffD1","Delta Fiducial Cut Efficiency - Disk 1",201,-100.5,100.5);
TH1F *out_FCED2 = new TH1F("DeltaFiducialCutEffD2","Delta Fiducial Cut Efficiency - Disk 2",201,-100.5,100.5);
TH1F *out_FCED3 = new TH1F("DeltaFiducialCutEffD3","Delta Fiducial Cut Efficiency - Disk 3",201,-100.5,100.5);
TH1F *out_FCED4 = new TH1F("DeltaFiducialCutEffD4","Delta Fiducial Cut Efficiency - Disk 4",201,-100.5,100.5);


//------------------------------------------------------------------------
//Define array to be filled in output
//------------------------------------------------------------------------

float arr_FCEDm1[500], arr_FCEDm2[500], arr_FCEDm3[500], arr_FCEDm4[500], arr_FCED4[500], arr_FCED3[500], arr_FCED1[500], arr_FCED2[500];             //Fiducial cut efficiencies

//------------------------------------------------------------------------




for(int j = 1; j<=36; j++)
{
	for(int l = 1; l<=6; l++){



//Fiducial cut efficiencies
arr_FCEDm1[j] = ((FCEDm12->GetBinContent(j,l)) - (FCEDm11->GetBinContent(j,l)));
arr_FCEDm2[j] = ((FCEDm22->GetBinContent(j,l)) - (FCEDm21->GetBinContent(j,l)));
arr_FCEDm3[j] = ((FCEDm32->GetBinContent(j,l)) - (FCEDm31->GetBinContent(j,l)));
arr_FCEDm4[j] = ((FCEDm42->GetBinContent(j,l)) - (FCEDm41->GetBinContent(j,l)));
arr_FCED1[j] = ((FCED12->GetBinContent(j,l)) - (FCED11->GetBinContent(j,l)));
arr_FCED2[j] = ((FCED22->GetBinContent(j,l)) - (FCED21->GetBinContent(j,l)));
arr_FCED3[j] = ((FCED32->GetBinContent(j,l)) - (FCED31->GetBinContent(j,l)));
arr_FCED4[j] = ((FCED42->GetBinContent(j,l)) - (FCED41->GetBinContent(j,l)));



//------------------------------------------------------------------------
//Fill output hist
//------------------------------------------------------------------------


//Fiducial cut efficiencies
out_FCEDm1->Fill(arr_FCEDm1[j]);
out_FCEDm2->Fill(arr_FCEDm2[j]);
out_FCEDm3->Fill(arr_FCEDm3[j]);
out_FCEDm4->Fill(arr_FCEDm4[j]);
out_FCED1->Fill(arr_FCED1[j]);
out_FCED2->Fill(arr_FCED2[j]);
out_FCED3->Fill(arr_FCED3[j]);
out_FCED4->Fill(arr_FCED4[j]);



	}
}

//------------------------------------------------------------------------
//Write hist to directory
//------------------------------------------------------------------------




//        out->mkdir("Endcap");
        out->cd("/Endcap");

out->mkdir("Endcap/Delta_Fiducial_cut_efficiencies/");
out->cd("Endcap/Delta_Fiducial_cut_efficiencies/");
//Fiducial cut efficiencies
out_FCEDm1->Write();
TCanvas *DeltaFCEDm1 = new TCanvas(Form("DeltaFiducialCutEffD-1"));
out_FCEDm1->Draw();
DeltaFCEDm1->SaveAs("DeltaFiducialCutEffD-1.png");


out_FCEDm2->Write();
TCanvas *DeltaFCEDm2 = new TCanvas(Form("DeltaFiducialCutEffD-2"));
out_FCEDm2->Draw();
DeltaFCEDm2->SaveAs("DeltaFiducialCutEffD-2.png");


out_FCEDm3->Write();
TCanvas *DeltaFCEDm3 = new TCanvas(Form("DeltaFiducialCutEffD-3"));
out_FCEDm3->Draw();
DeltaFCEDm3->SaveAs("DeltaFiducialCutEffD-3.png");


out_FCEDm4->Write();
TCanvas *DeltaFCEDm4 = new TCanvas(Form("DeltaFiducialCutEffD-4"));
out_FCEDm4->Draw();
DeltaFCEDm4->SaveAs("DeltaFiducialCutEffD-4.png");


out_FCED1->Write();
TCanvas *DeltaFCED1 = new TCanvas(Form("DeltaFiducialCutEffD1"));
out_FCED1->Draw();
DeltaFCED1->SaveAs("DeltaFiducialCutEffD1.png");


out_FCED2->Write();
TCanvas *DeltaFCED2 = new TCanvas(Form("DeltaFiducialCutEffD2"));
out_FCED2->Draw();
DeltaFCED2->SaveAs("DeltaFiducialCutEffD2.png");


out_FCED3->Write();
TCanvas *DeltaFCED3 = new TCanvas(Form("DeltaFiducialCutEffD3"));
out_FCED3->Draw();
DeltaFCED3->SaveAs("DeltaFiducialCutEffD3.png");


out_FCED4->Write();
TCanvas *DeltaFCED4 = new TCanvas(Form("DeltaFiducialCutEffD4"));
out_FCED4->Draw();
DeltaFCED4->SaveAs("DeltaFiducialCutEffD4.png");




}


