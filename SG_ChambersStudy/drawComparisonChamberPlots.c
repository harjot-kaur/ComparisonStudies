#include <iostream>
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TKey.h"
#include "TList.h"
#include <sys/stat.h>
void drawComparisonChamberPlots(std::string infilename1, std::string legendEntry1, std::string infilename2, std::string legendEntry2, std::string outfilename)
{

//gSystem->Exec("mkdir output");
//gSystem->Exec("mkdir output/Barrel");


//gSystem->Exec("mkdir output/Endcap");


//Open the root file
TFile *f1 = TFile::Open(infilename1.c_str());		//MWGR_1
TFile *f2 = TFile::Open(infilename2.c_str());		//MWGR_2



TH1F *BACS1, *BAR1, *BASE1, *BEO1, *BFCE1, *BROD1, *BRO1, *BTE1;
TH1F *BACS2, *BAR2, *BASE2, *BEO2, *BFCE2, *BROD2, *BRO2, *BTE2;

TH1F *EACS1, *EAR1, *EASE1, *EEO1, *EFCE1, *EROD1, *ERO1, *ETE1;
TH1F *EACS2, *EAR2, *EASE2, *EEO2, *EFCE2, *EROD2, *ERO2, *ETE2;




TDirectory* dir_barrel1 = (TDirectory*)f1->Get("Barrel");
TDirectory* dir_barrel2 = (TDirectory*)f2->Get("Barrel");


TDirectory* dir_endcap1 = (TDirectory*)f1->Get("Endcap");
TDirectory* dir_endcap2 = (TDirectory*)f2->Get("Endcap");


dir_barrel1->GetObject("AverageCLS", BACS1);
dir_barrel1->GetObject("AverageResiduals",BAR1);
dir_barrel1->GetObject("AverageStripEff",BASE1);
dir_barrel1->GetObject("ExpOcc",BEO1);
dir_barrel1->GetObject("FiducialCutEff",BFCE1);
dir_barrel1->GetObject("RPCOcc",BROD1);
dir_barrel1->GetObject("RPCRealOcc",BRO1);
dir_barrel1->GetObject("TotalEff",BTE1);

dir_barrel2->GetObject("AverageCLS",BACS2);
dir_barrel2->GetObject("AverageResiduals",BAR2);
dir_barrel2->GetObject("AverageStripEff",BASE2);
dir_barrel2->GetObject("ExpOcc",BEO2);
dir_barrel2->GetObject("FiducialCutEff",BFCE2);
dir_barrel2->GetObject("RPCOcc",BROD2);
dir_barrel2->GetObject("RPCRealOcc",BRO2);
dir_barrel2->GetObject("TotalEff",BTE2);


TCanvas *Barrel_AverageCLS = new TCanvas(Form("AverageCLS"));
TCanvas *Barrel_AverageResiduals= new TCanvas(Form("AverageResiduals"));
TCanvas *Barrel_AverageStripEff = new TCanvas(Form("AverageStripEff"));
TCanvas *Barrel_ExpOcc = new TCanvas(Form("ExpOcc"));
TCanvas *Barrel_FiducialCutEff = new TCanvas(Form("FiducialCutEff"));
TCanvas *Barrel_RPCOcc = new TCanvas(Form("RPCOcc"));
TCanvas *Barrel_RPCRealOcc = new TCanvas(Form("RPCRealOcc"));
TCanvas *Barrel_TotalEff = new TCanvas(Form("TotalEff"));





Barrel_AverageCLS->cd();
  TPad *BACS_pad1 = new TPad("BACS_pad1", "", 0, 0.3, 1, 1.0);
   BACS_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BACS_pad1->Draw();             // Draw the upper pad: pad1
   BACS_pad1->cd();               // pad1 becomes the current pad


    BACS2->Draw();
BACS1->SetLineColor(kRed);
BACS1->Draw("sames");

float maxBACS1=BACS1->GetMaximum();
float maxBACS2=BACS2->GetMaximum();
if(maxBACS1 > maxBACS2){
BACS2->SetMaximum(maxBACS1*1.5);
}
else
{
BACS2->SetMaximum(maxBACS2*1.5);
}


gPad->Update();
TPaveStats *st_BACS1 = (TPaveStats*)BACS1->FindObject("stats");
st_BACS1->SetY1NDC(0.60); //new x start position
st_BACS1->SetY2NDC(0.75);
st_BACS1->SetTextColor(kRed);

TLegend *l_BACS = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BACS->SetBorderSize(0);

        l_BACS->AddEntry(BACS1, legendEntry1.c_str(),"l");
        l_BACS->AddEntry(BACS2, legendEntry2.c_str(),"l");

       l_BACS->Draw();
Barrel_AverageCLS->cd();          // Go back to the main canvas before defining pad2
   TPad *BACS_pad2 = new TPad("BACS_pad2", "", 0, 0.05, 1, 0.3);
   BACS_pad2->SetTopMargin(0);
   BACS_pad2->SetBottomMargin(0.2);
   BACS_pad2->SetTitle("");
   BACS_pad2->SetGridy();
   BACS_pad2->SetGridx();
   BACS_pad2->Draw();
   BACS_pad2->cd();       // pad2 becomes the current pad


   TH1F *BACS_h3 = (TH1F*)BACS2->Clone("BACS_h3");
   BACS_h3->SetTitle("");
   BACS_h3->SetLineColor(kBlack);
   BACS_h3->SetStats(0);      // No statistics on lower plot
   BACS_h3->Divide(BACS1);
   BACS_h3->SetMarkerStyle(21);
   BACS_h3->GetXaxis()->SetLabelSize(0.1);
   BACS_h3->GetYaxis()->SetRangeUser(-2,5);
   BACS_h3->GetYaxis()->SetTitle("Ratio");
   BACS_h3->GetYaxis()->SetTitleOffset(0.2);
   BACS_h3->GetYaxis()->SetTitleSize(0.15);
   BACS_h3->GetYaxis()->SetLabelSize(0.1);


   BACS_h3->Draw("ep");       // Draw the ratio plot



//--------------------------------------------------------------------------------------------------------------------


Barrel_AverageResiduals->cd();


TPad *BAR_pad1 = new TPad("BAR_pad1", "", 0, 0.3, 1, 1.0);
   BAR_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BAR_pad1->Draw();             // Draw the upper pad: pad1
   BAR_pad1->cd();               // pad1 becomes the current pad


BAR2->Draw();
BAR1->SetLineColor(kRed);
BAR1->Draw("sames");

float maxBAR1=BAR1->GetMaximum();
float maxBAR2=BAR2->GetMaximum();
if(maxBAR1 > maxBAR2){
BAR2->SetMaximum(maxBAR1*1.5);
}
else
{
BAR2->SetMaximum(maxBAR2*1.5);
}


gPad->Update();
TPaveStats *st_BAR1 = (TPaveStats*)BAR1->FindObject("stats");
st_BAR1->SetY1NDC(0.60); //new x start position
st_BAR1->SetY2NDC(0.75);
st_BAR1->SetTextColor(kRed);



TLegend *l_BAR = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BAR->SetBorderSize(0);

        l_BAR->AddEntry(BAR1, legendEntry1.c_str(),"l");
        l_BAR->AddEntry(BAR2, legendEntry2.c_str(),"l");

       l_BAR->Draw();


Barrel_AverageResiduals->cd();          // Go back to the main canvas before defining pad2
   TPad *BAR_pad2 = new TPad("BAR_pad2", "", 0, 0.05, 1, 0.3);
   BAR_pad2->SetTopMargin(0);
   BAR_pad2->SetBottomMargin(0.2);
   BAR_pad2->SetTitle("");
   BAR_pad2->SetGridy();
   BAR_pad2->SetGridx();
   BAR_pad2->Draw();
   BAR_pad2->cd();       // pad2 becomes the current pad


   TH1F *BAR_h3 = (TH1F*)BAR2->Clone("BAR_h3");
   BAR_h3->SetTitle("");
   BAR_h3->SetLineColor(kBlack);
   BAR_h3->SetStats(0);      // No statistics on lower plot
   BAR_h3->Divide(BAR1);
   BAR_h3->SetMarkerStyle(21);
   BAR_h3->GetXaxis()->SetLabelSize(0.1);
   BAR_h3->GetYaxis()->SetRangeUser(-2,5);
   BAR_h3->GetYaxis()->SetNdivisions(508);
   BAR_h3->GetYaxis()->SetTitle("Ratio");
   BAR_h3->GetYaxis()->SetTitleOffset(0.2);
   BAR_h3->GetYaxis()->SetTitleSize(0.15);
   BAR_h3->GetYaxis()->SetLabelSize(0.1);
   BAR_h3->Draw("ep");       // Draw the ratio plot



//------------------------------------------------------------------------------------------------------------------------------------


Barrel_AverageStripEff->cd();
  TPad *BASE_pad1 = new TPad("BASE_pad1", "", 0, 0.3, 1, 1.0);
   BASE_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BASE_pad1->Draw();             // Draw the upper pad: pad1
   BASE_pad1->cd();               // pad1 becomes the current pad



BASE2->Draw();
BASE1->SetLineColor(kRed);
BASE1->Draw("sames");

float maxBASE1=BASE1->GetMaximum();
float maxBASE2=BASE2->GetMaximum();
if(maxBASE1 > maxBASE2){
BASE2->SetMaximum(maxBASE1*1.5);
}
else
{
BASE2->SetMaximum(maxBASE2*1.5);
}


gPad->Update();
TPaveStats *st_BASE2 = (TPaveStats*)BASE2->FindObject("stats");
st_BASE2->SetX1NDC(0.15);
st_BASE2->SetX2NDC(0.35);
st_BASE2->SetY1NDC(0.50); //new x start position
st_BASE2->SetY2NDC(0.65);
TPaveStats *st_BASE1 = (TPaveStats*)BASE1->FindObject("stats");

st_BASE1->SetX1NDC(0.15);
st_BASE1->SetX2NDC(0.35);
st_BASE1->SetY1NDC(0.70); //new x start position
st_BASE1->SetY2NDC(0.85);
st_BASE1->SetTextColor(kRed);

TLegend *l_BASE = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BASE->SetBorderSize(0);

        l_BASE->AddEntry(BASE1, legendEntry1.c_str(),"l");
        l_BASE->AddEntry(BASE2, legendEntry2.c_str(),"l");

       l_BASE->Draw();

       Barrel_AverageStripEff->cd();          // Go back to the main canvas before defining pad2
   TPad *BASE_pad2 = new TPad("BASE_pad2", "", 0, 0.05, 1, 0.3);
   BASE_pad2->SetTopMargin(0);
   BASE_pad2->SetBottomMargin(0.2);
   BASE_pad2->SetTitle("");
   BASE_pad2->SetGridy();
   BASE_pad2->SetGridx();
   BASE_pad2->Draw();
   BASE_pad2->cd();       // pad2 becomes the current pad


   TH1F *BASE_h3 = (TH1F*)BASE2->Clone("BASE_h3");
   BASE_h3->SetTitle("");
   BASE_h3->SetLineColor(kBlack);
   BASE_h3->SetStats(0);      // No statistics on lower plot
   BASE_h3->Divide(BASE1);
   BASE_h3->SetMarkerStyle(21);
   BASE_h3->GetXaxis()->SetLabelSize(0.1);
   BASE_h3->GetYaxis()->SetRangeUser(-1,6);
   BASE_h3->GetYaxis()->SetNdivisions(508);
   BASE_h3->GetYaxis()->SetTitle("Ratio");
   BASE_h3->GetYaxis()->SetTitleOffset(0.2);
   BASE_h3->GetYaxis()->SetTitleSize(0.15);
   BASE_h3->GetYaxis()->SetLabelSize(0.1);
   BASE_h3->Draw("ep");       // Draw the ratio plot

//---------------------------------------------------------------------------------------------------------------------------------


   Barrel_ExpOcc ->cd();
  TPad *BEO_pad1 = new TPad("BEO_pad1", "", 0, 0.3, 1, 1.0);
   BEO_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BEO_pad1->Draw();             // Draw the upper pad: pad1
   BEO_pad1->cd();               // pad1 becomes the current pad



BEO2->Draw();
BEO1->SetLineColor(kRed);
BEO1->Draw("sames");

float maxBEO1=BEO1->GetMaximum();
float maxBEO2=BEO2->GetMaximum();
if(maxBEO1 > maxBEO2){
BEO2->SetMaximum(maxBEO1*1.5);
}
else
{
BEO2->SetMaximum(maxBEO2*1.5);
}


gPad->Update();
TPaveStats *st_BEO1 = (TPaveStats*)BEO1->FindObject("stats");
st_BEO1->SetY1NDC(0.60); //new x start position
st_BEO1->SetY2NDC(0.75);
st_BEO1->SetTextColor(kRed);
TLegend *l_BEO = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BEO->SetBorderSize(0);

        l_BEO->AddEntry(BEO1, legendEntry1.c_str(),"l");
        l_BEO->AddEntry(BEO2, legendEntry2.c_str(),"l");

       l_BEO->Draw();
       Barrel_ExpOcc->cd();          // Go back to the main canvas before defining pad2
   TPad *BEO_pad2 = new TPad("BEO_pad2", "", 0, 0.05, 1, 0.3);
   BEO_pad2->SetTopMargin(0);
   BEO_pad2->SetBottomMargin(0.2);
   BEO_pad2->SetTitle("");
   BEO_pad2->SetGridy();
   BEO_pad2->SetGridx();
   BEO_pad2->Draw();
   BEO_pad2->cd();       // pad2 becomes the current pad


   TH1F *BEO_h3 = (TH1F*)BEO2->Clone("BEO_h3");
   BEO_h3->SetTitle("");
   BEO_h3->SetLineColor(kBlack);
   BEO_h3->SetStats(0);      // No statistics on lower plot
   BEO_h3->Divide(BEO1);
   BEO_h3->SetMarkerStyle(21);
   BEO_h3->GetXaxis()->SetLabelSize(0.1);
   BEO_h3->GetYaxis()->SetRangeUser(-1,8);
   BEO_h3->GetYaxis()->SetNdivisions(508);
   BEO_h3->GetYaxis()->SetTitle("Ratio");
   BEO_h3->GetYaxis()->SetTitleOffset(0.2);
   BEO_h3->GetYaxis()->SetTitleSize(0.15);
   BEO_h3->GetYaxis()->SetLabelSize(0.1);
   BEO_h3->Draw("ep");       // Draw the ratio plot




//--------------------------------------------------------------------------------------------------------------------------------

Barrel_FiducialCutEff->cd();

TPad *BFCE_pad1 = new TPad("BFCE_pad1", "", 0, 0.3, 1, 1.0);
   BFCE_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BFCE_pad1->Draw();             // Draw the upper pad: pad1
   BFCE_pad1->cd();               // pad1 becomes the current pad



BFCE2->Draw();
BFCE1->SetLineColor(kRed);
BFCE1->Draw("sames");

float maxBFCE1=BFCE1->GetMaximum();
float maxBFCE2=BFCE2->GetMaximum();
if(maxBFCE1 > maxBFCE2){
BFCE2->SetMaximum(maxBFCE1*1.5);
}
else
{
BFCE2->SetMaximum(maxBFCE2*1.5);
}


gPad->Update();
TPaveStats *st_BFCE1 = (TPaveStats*)BFCE1->FindObject("stats");
st_BFCE1->SetX1NDC(0.15);
st_BFCE1->SetX2NDC(0.35);
st_BFCE1->SetY1NDC(0.50); //new x start position
st_BFCE1->SetY2NDC(0.65);
st_BFCE1->SetTextColor(kRed);

TPaveStats *st_BFCE2 = (TPaveStats*)BFCE2->FindObject("stats");
st_BFCE2->SetX1NDC(0.15);
st_BFCE2->SetX2NDC(0.35);
st_BFCE2->SetY1NDC(0.70); //new x start position
st_BFCE2->SetY2NDC(0.85);



TLegend *l_BFCE = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BFCE->SetBorderSize(0);

        l_BFCE->AddEntry(BFCE1, legendEntry1.c_str(),"l");
        l_BFCE->AddEntry(BFCE2, legendEntry2.c_str(),"l");

       l_BFCE->Draw();



Barrel_FiducialCutEff->cd();          // Go back to the main canvas before defining pad2
   TPad *BFCE_pad2 = new TPad("BFCE_pad2", "", 0, 0.05, 1, 0.3);
   BFCE_pad2->SetTopMargin(0);
   BFCE_pad2->SetBottomMargin(0.2);
   BFCE_pad2->SetTitle("");
   BFCE_pad2->SetGridy();
   BFCE_pad2->SetGridx();
   BFCE_pad2->Draw();
   BFCE_pad2->cd();       // pad2 becomes the current pad


   TH1F *BFCE_h3 = (TH1F*)BFCE2->Clone("BFCE_h3");
   BFCE_h3->SetTitle("");
   BFCE_h3->SetLineColor(kBlack);
   BFCE_h3->SetStats(0);      // No statistics on lower plot
   BFCE_h3->Divide(BFCE1);
   BFCE_h3->SetMarkerStyle(21);
   BFCE_h3->GetXaxis()->SetLabelSize(0.1);
   BFCE_h3->GetYaxis()->SetRangeUser(-1,6);
   BFCE_h3->GetYaxis()->SetNdivisions(508);
   BFCE_h3->GetYaxis()->SetTitle("Ratio");
   BFCE_h3->GetYaxis()->SetTitleOffset(0.2);
   BFCE_h3->GetYaxis()->SetTitleSize(0.15);
   BFCE_h3->GetYaxis()->SetLabelSize(0.1);
   BFCE_h3->Draw("ep");       // Draw the ratio plot





//--------------------------------------------------------------------------------------------------------------------------------


Barrel_RPCOcc->cd();
 TPad *BROD_pad1 = new TPad("BROD_pad1", "", 0, 0.3, 1, 1.0);
   BROD_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BROD_pad1->Draw();             // Draw the upper pad: pad1
   BROD_pad1->cd();               // pad1 becomes the current pad



BROD2->Draw();
BROD1->SetLineColor(kRed);
BROD1->Draw("sames");

float maxBROD1=BROD1->GetMaximum();
float maxBROD2=BROD2->GetMaximum();
if(maxBROD1 > maxBROD2){
BROD2->SetMaximum(maxBROD1*1.5);
}
else
{
BROD2->SetMaximum(maxBROD2*1.5);
}


gPad->Update();
TPaveStats *st_BROD1 = (TPaveStats*)BROD1->FindObject("stats");
st_BROD1->SetY1NDC(0.60); //new x start position
st_BROD1->SetY2NDC(0.75);
st_BROD1->SetTextColor(kRed);

TLegend *l_BROD = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BROD->SetBorderSize(0);

        l_BROD->AddEntry(BROD1, legendEntry1.c_str(),"l");
        l_BROD->AddEntry(BROD2, legendEntry2.c_str(),"l");

       l_BROD->Draw();
Barrel_RPCOcc->cd();          // Go back to the main canvas before defining pad2
   TPad *BROD_pad2 = new TPad("BROD_pad2", "", 0, 0.05, 1, 0.3);
   BROD_pad2->SetTopMargin(0);
   BROD_pad2->SetBottomMargin(0.2);
   BROD_pad2->SetTitle("");
   BROD_pad2->SetGridy();
   BROD_pad2->SetGridx();
   BROD_pad2->Draw();
   BROD_pad2->cd();       // pad2 becomes the current pad


   TH1F *BROD_h3 = (TH1F*)BROD2->Clone("BROD_h3");
   BROD_h3->SetTitle("");
   BROD_h3->SetLineColor(kBlack);
   BROD_h3->SetStats(0);      // No statistics on lower plot
   BROD_h3->Divide(BROD1);
   BROD_h3->SetMarkerStyle(21);
   BROD_h3->GetXaxis()->SetLabelSize(0.1);
   BROD_h3->GetYaxis()->SetRangeUser(-1,6);
   BROD_h3->GetYaxis()->SetNdivisions(508);
   BROD_h3->GetYaxis()->SetTitle("Ratio");
   BROD_h3->GetYaxis()->SetTitleOffset(0.2);
   BROD_h3->GetYaxis()->SetTitleSize(0.15);
   BROD_h3->GetYaxis()->SetLabelSize(0.1);
   BROD_h3->Draw("ep");       // Draw the ratio plot

  
  //------------------------------------------------------------------------------------------------------------------------------------

Barrel_RPCRealOcc->cd();

  
   TPad *BRO_pad1 = new TPad("BRO_pad1", "", 0, 0.3, 1, 1.0);
   BRO_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BRO_pad1->Draw();             // Draw the upper pad: pad1
   BRO_pad1->cd();               // pad1 becomes the current pad




BRO2->Draw();
BRO1->SetLineColor(kRed);
BRO1->Draw("sames");

float maxBRO1=BRO1->GetMaximum();
float maxBRO2=BRO2->GetMaximum();
if(maxBRO1 > maxBRO2){
BRO2->SetMaximum(maxBRO1*1.5);
}
else
{
BRO2->SetMaximum(maxBRO2*1.5);
}


gPad->Update();
TPaveStats *st_BRO1 = (TPaveStats*)BRO1->FindObject("stats");
st_BRO1->SetY1NDC(0.60); //new x start position
st_BRO1->SetY2NDC(0.75);
st_BRO1->SetTextColor(kRed);

TLegend *l_BRO = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BRO->SetBorderSize(0);

        l_BRO->AddEntry(BRO1, legendEntry1.c_str(),"l");
        l_BRO->AddEntry(BRO2, legendEntry2.c_str(),"l");
       l_BRO->Draw();


Barrel_RPCRealOcc->cd();          // Go back to the main canvas before defining pad2
   TPad *BRO_pad2 = new TPad("BROD_pad2", "", 0, 0.05, 1, 0.3);
   BRO_pad2->SetTopMargin(0);
   BRO_pad2->SetBottomMargin(0.2);
   BRO_pad2->SetTitle("");
   BRO_pad2->SetGridy();
   BRO_pad2->SetGridx();
   BRO_pad2->Draw();
   BRO_pad2->cd();       // pad2 becomes the current pad


   TH1F *BRO_h3 = (TH1F*)BRO2->Clone("BRO_h3");
   BRO_h3->SetTitle("");
   BRO_h3->SetLineColor(kBlack);
   BRO_h3->SetStats(0);      // No statistics on lower plot
   BRO_h3->Divide(BRO1);
   BRO_h3->SetMarkerStyle(21);
   BRO_h3->GetXaxis()->SetLabelSize(0.1);
   BRO_h3->GetYaxis()->SetRangeUser(-1,11);
   BRO_h3->GetYaxis()->SetNdivisions(508);
   BRO_h3->GetYaxis()->SetTitle("Ratio");
   BRO_h3->GetYaxis()->SetTitleOffset(0.2);
   BRO_h3->GetYaxis()->SetTitleSize(0.15);
   BRO_h3->GetYaxis()->SetLabelSize(0.1);
   BRO_h3->Draw("ep");       // Draw the ratio plot




//------------------------------------------------------------------------------------------------------------------------------------
Barrel_TotalEff->cd();
TPad *BTE_pad1 = new TPad("BTE_pad1", "", 0, 0.3, 1, 1.0);
   BTE_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BTE_pad1->Draw();             // Draw the upper pad: pad1
   BTE_pad1->cd();               // pad1 becomes the current pad



BTE2->Draw();
BTE1->SetLineColor(kRed);
BTE1->Draw("sames");


float maxBTE1=BTE1->GetMaximum();
float maxBTE2=BTE2->GetMaximum();
if(maxBTE1 > maxBTE2){
BTE2->SetMaximum(maxBTE1*1.5);
}
else
{
BTE2->SetMaximum(maxBTE2*1.5);
}



gPad->Update();
TPaveStats *st_BTE1 = (TPaveStats*)BTE1->FindObject("stats");

st_BTE1->SetX1NDC(0.15);
st_BTE1->SetX2NDC(0.35);
st_BTE1->SetY1NDC(0.50); //new x start position
st_BTE1->SetY2NDC(0.65);
st_BTE1->SetTextColor(kRed);

TPaveStats *st_BTE2 = (TPaveStats*)BTE2->FindObject("stats");
st_BTE2->SetX1NDC(0.15);
st_BTE2->SetX2NDC(0.35);
st_BTE2->SetY1NDC(0.70); //new x start position
st_BTE2->SetY2NDC(0.85);




TLegend *l_BTE = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BTE->SetBorderSize(0);

        l_BTE->AddEntry(BTE1, legendEntry1.c_str(),"l");
        l_BTE->AddEntry(BTE2, legendEntry2.c_str(),"l");

       l_BTE->Draw();

Barrel_TotalEff->cd();          // Go back to the main canvas before defining pad2
   TPad *BTE_pad2 = new TPad("BTE_pad2", "", 0, 0.05, 1, 0.3);
   BTE_pad2->SetTopMargin(0);
   BTE_pad2->SetBottomMargin(0.2);
   BTE_pad2->SetTitle("");
   BTE_pad2->SetGridy();
   BTE_pad2->SetGridx();
   BTE_pad2->Draw();
   BTE_pad2->cd();       // pad2 becomes the current pad


   TH1F *BTE_h3 = (TH1F*)BTE2->Clone("BTE_h3");
   BTE_h3->SetTitle("");
   BTE_h3->SetLineColor(kBlack);
  BTE_h3->SetStats(0);      // No statistics on lower plot
   BTE_h3->Divide(BTE1);
   BTE_h3->SetMarkerStyle(21);
   BTE_h3->GetXaxis()->SetLabelSize(0.1);
   BTE_h3->GetYaxis()->SetRangeUser(-1,6);
   BTE_h3->GetYaxis()->SetNdivisions(508);
   BTE_h3->GetYaxis()->SetTitle("Ratio");
   BTE_h3->GetYaxis()->SetTitleOffset(0.2);
   BTE_h3->GetYaxis()->SetTitleSize(0.15);
   BTE_h3->GetYaxis()->SetLabelSize(0.1);
   BTE_h3->Draw("ep");       // Draw the ratio plot





//-----------------------------------------------------------------------------------------------------------------------------------





//----------------------------------------------------------------------------------------------------------------------------------



dir_endcap1->GetObject("AverageCLS", EACS1);

dir_endcap1->GetObject("AverageResiduals",EAR1);
dir_endcap1->GetObject("AverageStripEff",EASE1);
dir_endcap1->GetObject("ExpOcc",EEO1);
dir_endcap1->GetObject("FiducialCutEff",EFCE1);
dir_endcap1->GetObject("RPCOcc",EROD1);
dir_endcap1->GetObject("RPCRealOcc",ERO1);
dir_endcap1->GetObject("TotalEff",ETE1);

dir_endcap2->GetObject("AverageCLS",EACS2);
dir_endcap2->GetObject("AverageResiduals",EAR2);
dir_endcap2->GetObject("AverageStripEff",EASE2);
dir_endcap2->GetObject("ExpOcc",EEO2);
dir_endcap2->GetObject("FiducialCutEff",EFCE2);
dir_endcap2->GetObject("RPCOcc",EROD2);
dir_endcap2->GetObject("RPCRealOcc",ERO2);
dir_endcap2->GetObject("TotalEff",ETE2);


TCanvas *Endcap_AverageCLS = new TCanvas(Form("Endcap_AverageCLS"));
TCanvas *Endcap_AverageResiduals= new TCanvas(Form("Endcap_AverageResiduals"));
TCanvas *Endcap_AverageStripEff = new TCanvas(Form("Endcap_AverageStripEff"));
TCanvas *Endcap_ExpOcc = new TCanvas(Form("Endcap_ExpOcc"));
TCanvas *Endcap_FiducialCutEff = new TCanvas(Form("Endcap_FiducialCutEff"));
TCanvas *Endcap_RPCOcc = new TCanvas(Form("Endcap_RPCOcc"));
TCanvas *Endcap_RPCRealOcc = new TCanvas(Form("Endcap_RPCRealOcc"));
TCanvas *Endcap_TotalEff = new TCanvas(Form("Endcap_TotalEff"));


//-----------------------------------------------------------------------------------------------------------------------------------
Endcap_AverageCLS->cd();
 TPad *EACS_pad1 = new TPad("EACS_pad1", "", 0, 0.3, 1, 1.0);
   EACS_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EACS_pad1->Draw();             // Draw the upper pad: pad1
   EACS_pad1->cd();               // pad1 becomes the current pad



EACS2->Draw();
EACS1->SetLineColor(kRed);
EACS1->Draw("sames");

float maxEACS1=EACS1->GetMaximum();
float maxEACS2=EACS2->GetMaximum();
if(maxEACS1 > maxEACS2){
EACS2->SetMaximum(maxEACS1*1.5);
}
else
{
EACS2->SetMaximum(maxEACS2*1.5);
}


gPad->Update();
TPaveStats *st_EACS1 = (TPaveStats*)EACS1->FindObject("stats");
st_EACS1->SetY1NDC(0.60); //new x start position
st_EACS1->SetY2NDC(0.75);
st_EACS1->SetTextColor(kRed);

TLegend *l_EACS = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EACS->SetBorderSize(0);

        l_EACS->AddEntry(EACS1, legendEntry1.c_str(),"l");
        l_EACS->AddEntry(EACS2, legendEntry2.c_str(),"l");

       l_EACS->Draw();
Endcap_AverageCLS->cd();          // Go back to the main canvas before defining pad2
   TPad *EACS_pad2 = new TPad("EACS_pad2", "", 0, 0.05, 1, 0.3);
   EACS_pad2->SetTopMargin(0);
   EACS_pad2->SetBottomMargin(0.2);
   EACS_pad2->SetTitle("");
   EACS_pad2->SetGridy();
   EACS_pad2->SetGridx();
   EACS_pad2->Draw();
   EACS_pad2->cd();       // pad2 becomes the current pad


   TH1F *EACS_h3 = (TH1F*)EACS2->Clone("EACS_h3");
   EACS_h3->SetTitle("");
   EACS_h3->SetLineColor(kBlack);
   EACS_h3->SetStats(0);      // No statistics on lower plot
   EACS_h3->Divide(EACS1);
   EACS_h3->SetMarkerStyle(21);
   EACS_h3->GetXaxis()->SetLabelSize(0.1);
   EACS_h3->GetYaxis()->SetRangeUser(-2,5);
   EACS_h3->GetYaxis()->SetNdivisions(508);
   EACS_h3->GetYaxis()->SetTitle("Ratio");
   EACS_h3->GetYaxis()->SetTitleOffset(0.2);
   EACS_h3->GetYaxis()->SetTitleSize(0.15);
   EACS_h3->GetYaxis()->SetLabelSize(0.1);
   EACS_h3->Draw("ep");       // Draw the ratio plot




//-----------------------------------------------------------------------------------------------------------------------------------
Endcap_AverageResiduals->cd();
TPad *EAR_pad1 = new TPad("EAR_pad1", "", 0, 0.3, 1, 1.0);
   EAR_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EAR_pad1->Draw();             // Draw the upper pad: pad1
   EAR_pad1->cd();               // pad1 becomes the current pad



EAR2->Draw();
EAR1->SetLineColor(kRed);
EAR1->Draw("sames");

float maxEAR1=EAR1->GetMaximum();
float maxEAR2=EAR2->GetMaximum();
if(maxEAR1 > maxEAR2){
EAR2->SetMaximum(maxEAR1*1.5);
}
else
{
EAR2->SetMaximum(maxEAR2*1.5);
}


gPad->Update();
TPaveStats *st_EAR1 = (TPaveStats*)EAR1->FindObject("stats");
st_EAR1->SetY1NDC(0.60); //new x start position
st_EAR1->SetY2NDC(0.75);
st_EAR1->SetTextColor(kRed);

TLegend *l_EAR = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EAR->SetBorderSize(0);

        l_EAR->AddEntry(EAR1, legendEntry1.c_str(),"l");
        l_EAR->AddEntry(EAR2, legendEntry2.c_str(),"l");
       l_EAR->Draw();


Endcap_AverageResiduals->cd();          // Go back to the main canvas before defining pad2
   TPad *EAR_pad2 = new TPad("EAR_pad2", "", 0, 0.05, 1, 0.3);
   EAR_pad2->SetTopMargin(0);
   EAR_pad2->SetBottomMargin(0.2);
   EAR_pad2->SetTitle("");
   EAR_pad2->SetGridy();
   EAR_pad2->SetGridx();
   EAR_pad2->Draw();
   EAR_pad2->cd();       // pad2 becomes the current pad


   TH1F *EAR_h3 = (TH1F*)EAR2->Clone("EAR_h3");
   EAR_h3->SetTitle("");
   EAR_h3->SetLineColor(kBlack);
   EAR_h3->SetStats(0);      // No statistics on lower plot
   EAR_h3->Divide(EAR1);
   EAR_h3->SetMarkerStyle(21);
   EAR_h3->GetXaxis()->SetLabelSize(0.1);
   EAR_h3->GetYaxis()->SetRangeUser(-1,8);
   EAR_h3->GetYaxis()->SetNdivisions(508);
   EAR_h3->GetYaxis()->SetTitle("Ratio");
   EAR_h3->GetYaxis()->SetTitleOffset(0.2);
   EAR_h3->GetYaxis()->SetTitleSize(0.15);
   EAR_h3->GetYaxis()->SetLabelSize(0.1);
   EAR_h3->Draw("ep");       // Draw the ratio plot




//-----------------------------------------------------------------------------------------------------------------------------------
Endcap_AverageStripEff->cd();

  TPad *EASE_pad1 = new TPad("EASE_pad1", "", 0, 0.3, 1, 1.0);
   EASE_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EASE_pad1->Draw();             // Draw the upper pad: pad1
   EASE_pad1->cd();               // pad1 becomes the current pad




EASE2->Draw();
EASE1->SetLineColor(kRed);
EASE1->Draw("sames");

float maxEASE1=EASE1->GetMaximum();
float maxEASE2=EASE2->GetMaximum();
if(maxEASE1 > maxEASE2){
EASE2->SetMaximum(maxEASE1*1.5);
}
else
{
EASE2->SetMaximum(maxEASE2*1.5);
}


gPad->Update();
TPaveStats *st_EASE1 = (TPaveStats*)EASE1->FindObject("stats");
st_EASE1->SetX1NDC(0.25);
st_EASE1->SetX2NDC(0.45);

st_EASE1->SetY1NDC(0.50); //new x start position
st_EASE1->SetY2NDC(0.65);
st_EASE1->SetTextColor(kRed);

TPaveStats *st_EASE2 = (TPaveStats*)EASE2->FindObject("stats");
st_EASE2->SetX1NDC(0.25);
st_EASE2->SetX2NDC(0.45);
st_EASE2->SetY1NDC(0.70); //new x start position
st_EASE2->SetY2NDC(0.85);


TLegend *l_EASE = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EASE->SetBorderSize(0);

        l_EASE->AddEntry(EASE1, legendEntry1.c_str(),"l");
        l_EASE->AddEntry(EASE2, legendEntry2.c_str(),"l");

       l_EASE->Draw();



            Endcap_AverageStripEff->cd();          // Go back to the main canvas before defining pad2
   TPad *EASE_pad2 = new TPad("EASE_pad2", "", 0, 0.05, 1, 0.3);
   EASE_pad2->SetTopMargin(0);
   EASE_pad2->SetBottomMargin(0.2);
   EASE_pad2->SetTitle("");
   EASE_pad2->SetGridy();
   EASE_pad2->SetGridx();
   EASE_pad2->Draw();
   EASE_pad2->cd();       // pad2 becomes the current pad


   TH1F *EASE_h3 = (TH1F*)EASE2->Clone("EASE_h3");
   EASE_h3->SetTitle("");
   EASE_h3->SetLineColor(kBlack);
   EASE_h3->SetStats(0);      // No statistics on lower plot
   EASE_h3->Divide(EASE1);
   EASE_h3->SetMarkerStyle(21);
   EASE_h3->GetXaxis()->SetLabelSize(0.1);
   EASE_h3->GetYaxis()->SetRangeUser(-1,8);
   EASE_h3->GetYaxis()->SetNdivisions(508);
   EASE_h3->GetYaxis()->SetTitle("Ratio");
   EASE_h3->GetYaxis()->SetTitleOffset(0.2);
   EASE_h3->GetYaxis()->SetTitleSize(0.15);
   EASE_h3->GetYaxis()->SetLabelSize(0.1);
   EASE_h3->Draw("ep");       // Draw the ratio plot




//-----------------------------------------------------------------------------------------------------------------------------------
Endcap_ExpOcc->cd();
TPad *EEO_pad1 = new TPad("EEO_pad1", "", 0, 0.3, 1, 1.0);
   EEO_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EEO_pad1->Draw();             // Draw the upper pad: pad1
   EEO_pad1->cd();               // pad1 becomes the current pad


EEO2->Draw();
EEO1->SetLineColor(kRed);
EEO1->Draw("sames");

float maxEEO1=EEO1->GetMaximum();
float maxEEO2=EEO2->GetMaximum();
if(maxEEO1 > maxEEO2){
EEO2->SetMaximum(maxEEO1*1.5);
}
else
{
EEO2->SetMaximum(maxEEO2*1.5);
}


gPad->Update();
TPaveStats *st_EEO1 = (TPaveStats*)EEO1->FindObject("stats");
st_EEO1->SetY1NDC(0.60); //new x start position
st_EEO1->SetY2NDC(0.75);
st_EEO1->SetTextColor(kRed);

TLegend *l_EEO = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EEO->SetBorderSize(0);

        l_EEO->AddEntry(EEO1, legendEntry1.c_str(),"l");
        l_EEO->AddEntry(EEO2, legendEntry2.c_str(),"l");

       l_EEO->Draw();
      Endcap_ExpOcc->cd();          // Go back to the main canvas before defining pad2
   TPad *EEO_pad2 = new TPad("EEO_pad2", "", 0, 0.05, 1, 0.3);
   EEO_pad2->SetTopMargin(0);
   EEO_pad2->SetBottomMargin(0.2);
   EEO_pad2->SetTitle("");
   EEO_pad2->SetGridy();
   EEO_pad2->SetGridx();
   EEO_pad2->Draw();
   EEO_pad2->cd();       // pad2 becomes the current pad


   TH1F *EEO_h3 = (TH1F*)EEO2->Clone("EEO_h3");
   EEO_h3->SetTitle("");
   EEO_h3->SetLineColor(kBlack);
   EEO_h3->SetStats(0);      // No statistics on lower plot
   EEO_h3->Divide(EEO1);
   EEO_h3->SetMarkerStyle(21);
   EEO_h3->GetXaxis()->SetLabelSize(0.1);
   EEO_h3->GetYaxis()->SetRangeUser(-2,5);
   EEO_h3->GetYaxis()->SetNdivisions(508);
   EEO_h3->GetYaxis()->SetTitle("Ratio");
   EEO_h3->GetYaxis()->SetTitleOffset(0.2);
   EEO_h3->GetYaxis()->SetTitleSize(0.15);
   EEO_h3->GetYaxis()->SetLabelSize(0.1);
   EEO_h3->Draw("ep");       // Draw the ratio plot




//-----------------------------------------------------------------------------------------------------------------------------------
Endcap_FiducialCutEff->cd();

TPad *EFCE_pad1 = new TPad("EFCE_pad1", "", 0, 0.3, 1, 1.0);
   EFCE_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EFCE_pad1->Draw();             // Draw the upper pad: pad1
   EFCE_pad1->cd();               // pad1 becomes the current pad




EFCE2->Draw();
EFCE1->SetLineColor(kRed);
EFCE1->Draw("sames");

float maxEFCE1=EFCE1->GetMaximum();
float maxEFCE2=EFCE2->GetMaximum();
if(maxEFCE1 > maxEFCE2){
EFCE2->SetMaximum(maxEFCE1*1.5);
}
else
{
EFCE2->SetMaximum(maxEFCE2*1.5);
}


gPad->Update();
TPaveStats *st_EFCE1 = (TPaveStats*)EFCE1->FindObject("stats");
st_EFCE1->SetX1NDC(0.25);
st_EFCE1->SetX2NDC(0.45);
st_EFCE1->SetY1NDC(0.50); //new x start position
st_EFCE1->SetY2NDC(0.65);
st_EFCE1->SetTextColor(kRed);
TPaveStats *st_EFCE2 = (TPaveStats*)EFCE2->FindObject("stats");
st_EFCE2->SetX1NDC(0.25);
st_EFCE2->SetX2NDC(0.45);
st_EFCE2->SetY1NDC(0.70); //new x start position
st_EFCE2->SetY2NDC(0.85);

TLegend *l_EFCE = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EFCE->SetBorderSize(0);

        l_EFCE->AddEntry(EFCE1, legendEntry1.c_str(),"l");
        l_EFCE->AddEntry(EFCE2, legendEntry2.c_str(),"l");

       l_EFCE->Draw();


       Endcap_FiducialCutEff->cd();          // Go back to the main canvas before defining pad2
   TPad *EFCE_pad2 = new TPad("EFCE_pad2", "", 0, 0.05, 1, 0.3);
   EFCE_pad2->SetTopMargin(0);
   EFCE_pad2->SetBottomMargin(0.2);
   EFCE_pad2->SetTitle("");
   EFCE_pad2->SetGridy();
   EFCE_pad2->SetGridx();
   EFCE_pad2->Draw();
   EFCE_pad2->cd();       // pad2 becomes the current pad


   TH1F *EFCE_h3 = (TH1F*)EFCE2->Clone("EFCE_h3");
   EFCE_h3->SetTitle("");
   EFCE_h3->SetLineColor(kBlack);
   EFCE_h3->SetStats(0);      // No statistics on lower plot
   EFCE_h3->Divide(EFCE1);
   EFCE_h3->SetMarkerStyle(21);
   EFCE_h3->GetXaxis()->SetLabelSize(0.1);
   EFCE_h3->GetYaxis()->SetRangeUser(-1,6);
   EFCE_h3->GetYaxis()->SetNdivisions(508);
   EFCE_h3->GetYaxis()->SetTitle("Ratio");
   EFCE_h3->GetYaxis()->SetTitleOffset(0.2);
   EFCE_h3->GetYaxis()->SetTitleSize(0.15);
   EFCE_h3->GetYaxis()->SetLabelSize(0.1);
   EFCE_h3->Draw("ep");       // Draw the ratio plot



//-----------------------------------------------------------------------------------------------------------------------------------
Endcap_RPCOcc->cd();

TPad *EROD_pad1 = new TPad("EROD_pad1", "", 0, 0.3, 1, 1.0);
   EROD_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EROD_pad1->Draw();             // Draw the upper pad: pad1
   EROD_pad1->cd();               // pad1 becomes the current pad




EROD2->Draw();
EROD1->SetLineColor(kRed);
EROD1->Draw("sames");

float maxEROD1=EROD1->GetMaximum();
float maxEROD2=EROD2->GetMaximum();
if(maxEROD1 > maxEROD2){
EROD2->SetMaximum(maxEROD1*1.5);
}
else
{
EROD2->SetMaximum(maxEROD2*1.5);
}



gPad->Update();
TPaveStats *st_EROD1 = (TPaveStats*)EROD1->FindObject("stats");
st_EROD1->SetY1NDC(0.60); //new x start position
st_EROD1->SetY2NDC(0.75);
st_EROD1->SetTextColor(kRed);

TLegend *l_EROD = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EROD->SetBorderSize(0);
        l_EROD->AddEntry(EROD1, legendEntry1.c_str(),"l");
        l_EROD->AddEntry(EROD2, legendEntry2.c_str(),"l");

       l_EROD->Draw();


       Endcap_RPCOcc->cd();          // Go back to the main canvas before defining pad2
   TPad *EROD_pad2 = new TPad("EROD_pad2", "", 0, 0.05, 1, 0.3);
   EROD_pad2->SetTopMargin(0);
   EROD_pad2->SetBottomMargin(0.2);
   EROD_pad2->SetTitle("");
   EROD_pad2->SetGridy();
   EROD_pad2->SetGridx();
   EROD_pad2->Draw();
   EROD_pad2->cd();       // pad2 becomes the current pad


   TH1F *EROD_h3 = (TH1F*)EROD2->Clone("EROD_h3");
   EROD_h3->SetTitle("");
   EROD_h3->SetLineColor(kBlack);
   EROD_h3->SetStats(0);      // No statistics on lower plot
   EROD_h3->Divide(EROD1);
   EROD_h3->SetMarkerStyle(21);
   EROD_h3->GetXaxis()->SetLabelSize(0.1);
   EROD_h3->GetYaxis()->SetRangeUser(-1,6);
   EROD_h3->GetYaxis()->SetNdivisions(508);
   EROD_h3->GetYaxis()->SetTitle("Ratio");
   EROD_h3->GetYaxis()->SetTitleOffset(0.2);
   EROD_h3->GetYaxis()->SetTitleSize(0.15);
   EROD_h3->GetYaxis()->SetLabelSize(0.1);
   EROD_h3->Draw("ep");       // Draw the ratio plot


//-----------------------------------------------------------------------------------------------------------------------------------
Endcap_RPCRealOcc->cd();

 TPad *ERO_pad1 = new TPad("ERO_pad1", "", 0, 0.3, 1, 1.0);
   ERO_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   ERO_pad1->Draw();             // Draw the upper pad: pad1
   ERO_pad1->cd();               // pad1 becomes the current pad



ERO2->Draw();
ERO1->SetLineColor(kRed);
ERO1->Draw("sames");

float maxERO1=ERO1->GetMaximum();
float maxERO2=ERO2->GetMaximum();
if(maxERO1 > maxERO2){
ERO2->SetMaximum(maxERO1*1.5);
}
else
{
ERO2->SetMaximum(maxERO2*1.5);
}



gPad->Update();
TPaveStats *st_ERO1 = (TPaveStats*)ERO1->FindObject("stats");
st_ERO1->SetY1NDC(0.60); //new x start position
st_ERO1->SetY2NDC(0.75);
st_ERO1->SetTextColor(kRed);

TLegend *l_ERO = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_ERO->SetBorderSize(0);

        l_ERO->AddEntry(ERO1, legendEntry1.c_str(),"l");
        l_ERO->AddEntry(ERO2, legendEntry2.c_str(),"l");

       l_ERO->Draw();

Endcap_RPCRealOcc->cd();          // Go back to the main canvas before defining pad2
   TPad *ERO_pad2 = new TPad("EROD_pad2", "", 0, 0.05, 1, 0.3);
   ERO_pad2->SetTopMargin(0);
   ERO_pad2->SetBottomMargin(0.2);
   ERO_pad2->SetTitle("");
   ERO_pad2->SetGridy();
   ERO_pad2->SetGridx();
   ERO_pad2->Draw();
   ERO_pad2->cd();       // pad2 becomes the current pad


   TH1F *ERO_h3 = (TH1F*)ERO2->Clone("ERO_h3");
   ERO_h3->SetTitle("");
   ERO_h3->SetLineColor(kBlack);
   ERO_h3->SetStats(0);      // No statistics on lower plot
   ERO_h3->Divide(ERO1);
   ERO_h3->SetMarkerStyle(21);
   ERO_h3->GetXaxis()->SetLabelSize(0.1);
   ERO_h3->GetYaxis()->SetRangeUser(-2,5);
   ERO_h3->GetYaxis()->SetNdivisions(508);
   ERO_h3->GetYaxis()->SetTitle("Ratio");
   ERO_h3->GetYaxis()->SetTitleOffset(0.2);
   ERO_h3->GetYaxis()->SetTitleSize(0.15);
   ERO_h3->GetYaxis()->SetLabelSize(0.1);
   ERO_h3->Draw("ep");       // Draw the ratio plot


//-----------------------------------------------------------------------------------------------------------------------------------
Endcap_TotalEff->cd();
TPad *ETE_pad1 = new TPad("ETE_pad1", "", 0, 0.3, 1, 1.0);
   ETE_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   ETE_pad1->Draw();             // Draw the upper pad: pad1
   ETE_pad1->cd();               // pad1 becomes the current pad


ETE2->Draw();
ETE1->SetLineColor(kRed);
ETE1->Draw("sames");

float maxETE1=ETE1->GetMaximum();
float maxETE2=ETE2->GetMaximum();
if(maxETE1 > maxETE2){
ETE2->SetMaximum(maxETE1*1.5);
}
else
{
ETE2->SetMaximum(maxETE2*1.5);
}



gPad->Update();
TPaveStats *st_ETE1 = (TPaveStats*)ETE1->FindObject("stats");

st_ETE1->SetX1NDC(0.25);
st_ETE1->SetX2NDC(0.45);
st_ETE1->SetY1NDC(0.50); //new x start position
st_ETE1->SetY2NDC(0.65);
st_ETE1->SetTextColor(kRed);

TPaveStats *st_ETE2 = (TPaveStats*)ETE2->FindObject("stats");
st_ETE2->SetX1NDC(0.25);
st_ETE2->SetX2NDC(0.45);
st_ETE2->SetY1NDC(0.70); //new x start position
st_ETE2->SetY2NDC(0.85);


TLegend *l_ETE = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_ETE->SetBorderSize(0);

        l_ETE->AddEntry(ETE1, legendEntry1.c_str(),"l");
        l_ETE->AddEntry(ETE2, legendEntry2.c_str(),"l");

       l_ETE->Draw();


       Endcap_TotalEff->cd();          // Go back to the main canvas before defining pad2
   TPad *ETE_pad2 = new TPad("ETE_pad2", "", 0, 0.05, 1, 0.3);
   ETE_pad2->SetTopMargin(0);
   ETE_pad2->SetBottomMargin(0.2);
   ETE_pad2->SetTitle("");
   ETE_pad2->SetGridy();
   ETE_pad2->SetGridx();
   ETE_pad2->Draw();
   ETE_pad2->cd();       // pad2 becomes the current pad


   TH1F *ETE_h3 = (TH1F*)ETE2->Clone("ETE_h3");
   ETE_h3->SetTitle("");
   ETE_h3->SetLineColor(kBlack);
   ETE_h3->SetStats(0);      // No statistics on lower plot
   ETE_h3->Divide(ETE1);
   ETE_h3->SetMarkerStyle(21);
   ETE_h3->GetXaxis()->SetLabelSize(0.1);
   ETE_h3->GetYaxis()->SetRangeUser(-1,11);
   ETE_h3->GetYaxis()->SetNdivisions(508);
   ETE_h3->GetYaxis()->SetTitle("Ratio");
   ETE_h3->GetYaxis()->SetTitleOffset(0.2);
   ETE_h3->GetYaxis()->SetTitleSize(0.15);
   ETE_h3->GetYaxis()->SetLabelSize(0.1);
   ETE_h3->Draw("ep");       // Draw the ratio plot








//-----------------------------------------------------------------------------------------------------------------------------------





//----------------------------------------------------------------------------------------------------------------------------------



TFile *out = new TFile(outfilename.c_str(), "RECREATE");
out->mkdir("Barrel");

out->cd("Barrel/");
Barrel_AverageCLS->Write();
Barrel_AverageResiduals->Write();
Barrel_AverageStripEff->Write();
Barrel_ExpOcc->Write();
Barrel_FiducialCutEff->Write();
Barrel_RPCOcc->Write();
Barrel_RPCRealOcc->Write();
Barrel_TotalEff->Write();




out->mkdir("Endcap");

out->cd("Endcap/");
Endcap_AverageCLS->Write();
Endcap_AverageResiduals->Write();
Endcap_AverageStripEff->Write();
Endcap_ExpOcc->Write();
Endcap_FiducialCutEff->Write();
Endcap_RPCOcc->Write();
Endcap_RPCRealOcc->Write();
Endcap_TotalEff->Write();





out->Close();


Barrel_AverageCLS->SaveAs("Barrel_AverageCLSW.png");
Barrel_AverageResiduals->SaveAs("Barrel_AverageResiduals.png");
Barrel_AverageStripEff->SaveAs("Barrel_AverageStripEff.png");
Barrel_ExpOcc->SaveAs("Barrel_ExpOcc.png");
Barrel_FiducialCutEff->SaveAs("Barrel_FiducialCutEff.png");
Barrel_RPCOcc->SaveAs("Barrel_RPCOcc.png");
Barrel_RPCRealOcc->SaveAs("Barrel_RPCRealOcc.png");
Barrel_TotalEff->SaveAs("Barrel_TotalEff.png");





Endcap_AverageCLS->SaveAs("Endcap_AverageCLSW.png");
Endcap_AverageResiduals->SaveAs("Endcap_AverageResiduals.png");
Endcap_AverageStripEff->SaveAs("Endcap_AverageStripEff.png");
Endcap_ExpOcc->SaveAs("Endcap_ExpOcc.png");
Endcap_FiducialCutEff->SaveAs("Endcap_FiducialCutEff.png");
Endcap_RPCOcc->SaveAs("Endcap_RPCOcc.png");
Endcap_RPCRealOcc->SaveAs("Endcap_RPCRealOcc.png");
Endcap_TotalEff->SaveAs("Endcap_TotalEff.png");


}








