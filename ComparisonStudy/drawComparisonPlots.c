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
void drawComparisonPlots(std::string infilename1, std::string legendEntry1, std::string infilename2, std::string legendEntry2, std::string outfilename)
{

gSystem->Exec("mkdir ComparisonPlots");
gSystem->Exec("mkdir ComparisonPlots/Barrel");
gSystem->Exec("mkdir ComparisonPlots/Barrel/AverageCLS/");
gSystem->Exec("mkdir ComparisonPlots/Barrel/AverageResiduals/");
gSystem->Exec("mkdir ComparisonPlots/Barrel/AverageStripEff/");
gSystem->Exec("mkdir ComparisonPlots/Barrel/DeltaFudicialEff/");
gSystem->Exec("mkdir ComparisonPlots/Barrel/ExpOcc/");
gSystem->Exec("mkdir ComparisonPlots/Barrel/FiducialCutEff/");
gSystem->Exec("mkdir ComparisonPlots/Barrel/RPCOcc/");
gSystem->Exec("mkdir ComparisonPlots/Barrel/RPCRealOcc/");
gSystem->Exec("mkdir ComparisonPlots/Barrel/TotalEff/");


gSystem->Exec("mkdir ComparisonPlots/Endcap");
gSystem->Exec("mkdir ComparisonPlots/Endcap/AverageCLS/");
gSystem->Exec("mkdir ComparisonPlots/Endcap/AverageResiduals/");
gSystem->Exec("mkdir ComparisonPlots/Endcap/AverageStripEff/");
gSystem->Exec("mkdir ComparisonPlots/Endcap/DeltaFudicialEff/");
gSystem->Exec("mkdir ComparisonPlots/Endcap/ExpOcc/");
gSystem->Exec("mkdir ComparisonPlots/Endcap/FiducialCutEff/");
gSystem->Exec("mkdir ComparisonPlots/Endcap/RPCOcc/");
gSystem->Exec("mkdir ComparisonPlots/Endcap/RPCRealOcc/");
gSystem->Exec("mkdir ComparisonPlots/Endcap/TotalEff/");

//Open the root file
//TFile *f1 = TFile::Open("output_run_339579.root");		//MWGR_1
//TFile *f2 = TFile::Open("output_run_340323.root");		//MWGR_2
TFile *f1 = TFile::Open(infilename1.c_str());            //MWGR_1
TFile *f2 = TFile::Open(infilename2.c_str());            //MWGR_2



TFile *out = TFile::Open(outfilename.c_str(), "RECREATE");
out->mkdir("Barrel");
out->mkdir("Endcap");
out->Close();

//-----------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
//Barrel 
//--------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------
//average_residuals
//--------------------------------------------------------------------------------------------------



TDirectory* dir_BACS1 = (TDirectory*)f1->Get("Barrel/average_cluster_size");
TDirectory* dir_BACS12 = (TDirectory*)f2->Get("Barrel/average_cluster_size");

std::vector<std::string>hist_name_BACS;

hist_name_BACS.push_back("AverageCLSW-2");
hist_name_BACS.push_back("AverageCLSW-1");
hist_name_BACS.push_back("AverageCLSW0");
hist_name_BACS.push_back("AverageCLSW1");
hist_name_BACS.push_back("AverageCLSW2");

const Int_t nhist=10;
TCanvas *Barrel_AverageCLSW[nhist];
for(unsigned int i=0;i<hist_name_BACS.size();i++){
	TH1F *hist_BACS1= (TH1F*)dir_BACS1->Get((hist_name_BACS.at(i)).c_str());
	TH1F *hist_BACS2= (TH1F*)dir_BACS12->Get((hist_name_BACS.at(i)).c_str());

Barrel_AverageCLSW[i] = new TCanvas(Form("AverageCLSW%d", i-2));


  TPad *BACS_pad1 = new TPad("BACS_pad1", "", 0, 0.3, 1, 1.0);
   BACS_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BACS_pad1->Draw();             // Draw the upper pad: pad1
   BACS_pad1->cd();               // pad1 becomes the current pad


    hist_BACS2->Draw();
//hist_BACS2->Draw();
/*gPad->Update();
TPaveStats *st = (TPaveStats*)hist_BACS2->FindObject("stats");
st->SetX1NDC(0.3); //new x start position
st->SetX2NDC(0.5);
*/
hist_BACS1->SetLineColor(kRed);
hist_BACS1->Draw("sames");

float maxBACS1=hist_BACS1->GetMaximum();
float maxBACS2=hist_BACS2->GetMaximum();
if(maxBACS1 > maxBACS2){
hist_BACS2->SetMaximum(maxBACS1*1.5);
}
else
{
hist_BACS2->SetMaximum(maxBACS2*1.5);
}


gPad->Update();
TPaveStats *st_BACS1 = (TPaveStats*)hist_BACS1->FindObject("stats");
st_BACS1->SetY1NDC(0.60); //new x start position
st_BACS1->SetY2NDC(0.75);
st_BACS1->SetTextColor(kRed);

TLegend *l_BACS = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BACS->SetBorderSize(0);

        l_BACS->AddEntry(hist_BACS1, legendEntry1.c_str(),"l");
        l_BACS->AddEntry(hist_BACS2, legendEntry2.c_str(),"l");

       l_BACS->Draw();
Barrel_AverageCLSW[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *BACS_pad2 = new TPad("BACS_pad2", "", 0, 0.05, 1, 0.3);
   BACS_pad2->SetTopMargin(0);
   BACS_pad2->SetBottomMargin(0.2);
   BACS_pad2->SetTitle("");
   BACS_pad2->SetGridy();
   BACS_pad2->SetGridx();
   BACS_pad2->Draw();
   BACS_pad2->cd();       // pad2 becomes the current pad


   TH1F *BACS_h3 = (TH1F*)hist_BACS2->Clone("BACS_h3");
   BACS_h3->SetTitle("");
   BACS_h3->SetLineColor(kBlack);
   BACS_h3->SetStats(0);      // No statistics on lower plot
   BACS_h3->Divide(hist_BACS1);
   BACS_h3->SetMarkerStyle(21);
   BACS_h3->GetXaxis()->SetLabelSize(0.1);
   BACS_h3->GetYaxis()->SetRangeUser(-2,5);
//   BACS_h3->GetYaxis()->SetNdivisions(508);
   BACS_h3->GetYaxis()->SetTitle("Ratio");
   BACS_h3->GetYaxis()->SetTitleOffset(0.2);
   BACS_h3->GetYaxis()->SetTitleSize(0.15);
   BACS_h3->GetYaxis()->SetLabelSize(0.1);


   BACS_h3->Draw("ep");       // Draw the ratio plot



TFile *out = TFile::Open(outfilename.c_str(), "UPDATE"); 
//out->mkdir("Barrel");
out->mkdir("Barrel/average_cluster_size/");
out->cd("Barrel/average_cluster_size/");
Barrel_AverageCLSW[i]->Write();
out->Close();



std::string outName = "Barrel" + std::string(hist_name_BACS.at(i)) + ".png";       //save histogram as a image
Barrel_AverageCLSW[i]->SaveAs(outName.c_str());

}



//------------------------------------------------------------------------------------------------
//average_residuals
//--------------------------------------------------------------------------------------------------





TDirectory* dir_BAR1 = (TDirectory*)f1->Get("Barrel/average_residuals");
TDirectory* dir_BAR12 = (TDirectory*)f2->Get("Barrel/average_residuals");

std::vector<std::string>hist_name_BAR;

hist_name_BAR.push_back("AverageResidualsW-2");
hist_name_BAR.push_back("AverageResidualsW-1");
hist_name_BAR.push_back("AverageResidualsW0");
hist_name_BAR.push_back("AverageResidualsW1");
hist_name_BAR.push_back("AverageResidualsW2");

//const Int_t nhist=10;
TCanvas *Barrel_AverageResiduals[10];
for(unsigned int i=0;i<hist_name_BAR.size();i++){

TH1F *hist_BAR1= (TH1F*)dir_BAR1->Get((hist_name_BAR.at(i)).c_str());
TH1F *hist_BAR2= (TH1F*)dir_BAR12->Get((hist_name_BAR.at(i)).c_str());

Barrel_AverageResiduals[i] = new TCanvas(Form("AverageResidualsW%d", i-2));

TPad *BAR_pad1 = new TPad("BAR_pad1", "", 0, 0.3, 1, 1.0);
   BAR_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BAR_pad1->Draw();             // Draw the upper pad: pad1
   BAR_pad1->cd();               // pad1 becomes the current pad


hist_BAR2->Draw();
hist_BAR1->SetLineColor(kRed);
hist_BAR1->Draw("sames");

float maxBAR1=hist_BAR1->GetMaximum();
float maxBAR2=hist_BAR2->GetMaximum();
if(maxBAR1 > maxBAR2){
hist_BAR2->SetMaximum(maxBAR1*1.5);
}
else
{
hist_BAR2->SetMaximum(maxBAR2*1.5);
}


gPad->Update();
TPaveStats *st_BAR1 = (TPaveStats*)hist_BAR1->FindObject("stats");
st_BAR1->SetY1NDC(0.60); //new x start position
st_BAR1->SetY2NDC(0.75);
st_BAR1->SetTextColor(kRed);



TLegend *l_BAR = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BAR->SetBorderSize(0);

        l_BAR->AddEntry(hist_BAR1, legendEntry1.c_str(),"l");
        l_BAR->AddEntry(hist_BAR2, legendEntry2.c_str(),"l");

       l_BAR->Draw();


Barrel_AverageResiduals[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *BAR_pad2 = new TPad("BAR_pad2", "", 0, 0.05, 1, 0.3);
   BAR_pad2->SetTopMargin(0);
   BAR_pad2->SetBottomMargin(0.2);
   BAR_pad2->SetTitle("");
   BAR_pad2->SetGridy();
   BAR_pad2->SetGridx();
   BAR_pad2->Draw();
   BAR_pad2->cd();       // pad2 becomes the current pad


   TH1F *BAR_h3 = (TH1F*)hist_BAR2->Clone("BAR_h3");
   BAR_h3->SetTitle("");
   BAR_h3->SetLineColor(kBlack);
   BAR_h3->SetStats(0);      // No statistics on lower plot
   BAR_h3->Divide(hist_BAR1);
   BAR_h3->SetMarkerStyle(21);
   BAR_h3->GetXaxis()->SetLabelSize(0.1);
   BAR_h3->GetYaxis()->SetRangeUser(-2,5);
   BAR_h3->GetYaxis()->SetNdivisions(508);
   BAR_h3->GetYaxis()->SetTitle("Ratio");
   BAR_h3->GetYaxis()->SetTitleOffset(0.2);
   BAR_h3->GetYaxis()->SetTitleSize(0.15);
   BAR_h3->GetYaxis()->SetLabelSize(0.1);
   BAR_h3->Draw("ep");       // Draw the ratio plot


TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Barrel");
out->mkdir("Barrel/average_residuals/");
out->cd("Barrel/average_residuals/");
Barrel_AverageResiduals[i]->Write();
out->Close();

std::string outNameBAR = "Barrel" + std::string(hist_name_BAR.at(i)) + ".png";       //save histogram as a image
Barrel_AverageResiduals[i]->SaveAs(outNameBAR.c_str());




}





//------------------------------------------------------------------------------------------------
//average_strip_efficiencies
//--------------------------------------------------------------------------------------------------





TDirectory* dir_BASE1 = (TDirectory*)f1->Get("Barrel/average_strip_efficiencies");
TDirectory* dir_BASE12 = (TDirectory*)f2->Get("Barrel/average_strip_efficiencies");

std::vector<std::string>hist_name_BASE;

hist_name_BASE.push_back("AverageStripEffW-2");
hist_name_BASE.push_back("AverageStripEffW-1");
hist_name_BASE.push_back("AverageStripEffW0");
hist_name_BASE.push_back("AverageStripEffW1");
hist_name_BASE.push_back("AverageStripEffW2");

//const Int_t nhist=10;
TCanvas *Barrel_AverageStripEff[10];
for(unsigned int i=0;i<hist_name_BASE.size();i++){

TH1F *hist_BASE1= (TH1F*)dir_BASE1->Get((hist_name_BASE.at(i)).c_str());
TH1F *hist_BASE2= (TH1F*)dir_BASE12->Get((hist_name_BASE.at(i)).c_str());

Barrel_AverageStripEff[i] = new TCanvas(Form("AverageStripEffW%d", i-2));

  TPad *BASE_pad1 = new TPad("BASE_pad1", "", 0, 0.3, 1, 1.0);
   BASE_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BASE_pad1->Draw();             // Draw the upper pad: pad1
   BASE_pad1->cd();               // pad1 becomes the current pad



hist_BASE2->Draw();
hist_BASE1->SetLineColor(kRed);
hist_BASE1->Draw("sames");

float maxBASE1=hist_BASE1->GetMaximum();
float maxBASE2=hist_BASE2->GetMaximum();
if(maxBASE1 > maxBASE2){
hist_BASE2->SetMaximum(maxBASE1*1.5);
}
else
{
hist_BASE2->SetMaximum(maxBASE2*1.5);
}


gPad->Update();
TPaveStats *st_BASE2 = (TPaveStats*)hist_BASE2->FindObject("stats");
st_BASE2->SetX1NDC(0.15);
st_BASE2->SetX2NDC(0.35);
st_BASE2->SetY1NDC(0.50); //new x start position
st_BASE2->SetY2NDC(0.65);


TPaveStats *st_BASE1 = (TPaveStats*)hist_BASE1->FindObject("stats");

st_BASE1->SetX1NDC(0.15);
st_BASE1->SetX2NDC(0.35);
st_BASE1->SetY1NDC(0.70); //new x start position
st_BASE1->SetY2NDC(0.85);
st_BASE1->SetTextColor(kRed);

TLegend *l_BASE = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BASE->SetBorderSize(0);

        l_BASE->AddEntry(hist_BASE1, legendEntry1.c_str(),"l");
        l_BASE->AddEntry(hist_BASE2, legendEntry2.c_str(),"l");

       l_BASE->Draw();

       Barrel_AverageStripEff[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *BASE_pad2 = new TPad("BASE_pad2", "", 0, 0.05, 1, 0.3);
   BASE_pad2->SetTopMargin(0);
   BASE_pad2->SetBottomMargin(0.2);
   BASE_pad2->SetTitle("");
   BASE_pad2->SetGridy();
   BASE_pad2->SetGridx();
   BASE_pad2->Draw();
   BASE_pad2->cd();       // pad2 becomes the current pad


   TH1F *BASE_h3 = (TH1F*)hist_BASE2->Clone("BASE_h3");
   BASE_h3->SetTitle("");
   BASE_h3->SetLineColor(kBlack);
   BASE_h3->SetStats(0);      // No statistics on lower plot
   BASE_h3->Divide(hist_BASE1);
   BASE_h3->SetMarkerStyle(21);
   BASE_h3->GetXaxis()->SetLabelSize(0.1);
   BASE_h3->GetYaxis()->SetRangeUser(-1,6);
   BASE_h3->GetYaxis()->SetNdivisions(508);
   BASE_h3->GetYaxis()->SetTitle("Ratio");
   BASE_h3->GetYaxis()->SetTitleOffset(0.2);
   BASE_h3->GetYaxis()->SetTitleSize(0.15);
   BASE_h3->GetYaxis()->SetLabelSize(0.1);
   BASE_h3->Draw("ep");       // Draw the ratio plot



TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Barrel");
out->mkdir("Barrel/average_strip_efficiencies/");
out->cd("Barrel/average_strip_efficiencies/");
Barrel_AverageStripEff[i]->Write();
out->Close();

std::string outNameBASE = "Barrel" + std::string(hist_name_BASE.at(i)) + ".png";       //save histogram as a image
Barrel_AverageStripEff[i]->SaveAs(outNameBASE.c_str());



}





//------------------------------------------------------------------------------------------------
//expected_occupancy
//--------------------------------------------------------------------------------------------------





TDirectory* dir_BEO1 = (TDirectory*)f1->Get("Barrel/expected_occupancy");
TDirectory* dir_BEO12 = (TDirectory*)f2->Get("Barrel/expected_occupancy");

std::vector<std::string>hist_name_BEO;

hist_name_BEO.push_back("ExpOccW-2");
hist_name_BEO.push_back("ExpOccW-1");
hist_name_BEO.push_back("ExpOccW0");
hist_name_BEO.push_back("ExpOccW1");
hist_name_BEO.push_back("ExpOccW2");

//const Int_t nhist=10;
TCanvas *Barrel_ExpOcc[10];
for(unsigned int i=0;i<hist_name_BEO.size();i++){

TH1F *hist_BEO1= (TH1F*)dir_BEO1->Get((hist_name_BEO.at(i)).c_str());
TH1F *hist_BEO2= (TH1F*)dir_BEO12->Get((hist_name_BEO.at(i)).c_str());

Barrel_ExpOcc[i] = new TCanvas(Form("ExpOccW%d", i-2));

  TPad *BEO_pad1 = new TPad("BEO_pad1", "", 0, 0.3, 1, 1.0);
   BEO_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BEO_pad1->Draw();             // Draw the upper pad: pad1
   BEO_pad1->cd();               // pad1 becomes the current pad



hist_BEO2->Draw();
hist_BEO1->SetLineColor(kRed);
hist_BEO1->Draw("sames");

float maxBEO1=hist_BEO1->GetMaximum();
float maxBEO2=hist_BEO2->GetMaximum();
if(maxBEO1 > maxBEO2){
hist_BEO2->SetMaximum(maxBEO1*1.5);
}
else
{
hist_BEO2->SetMaximum(maxBEO2*1.5);
}


gPad->Update();
TPaveStats *st_BEO1 = (TPaveStats*)hist_BEO1->FindObject("stats");
st_BEO1->SetY1NDC(0.60); //new x start position
st_BEO1->SetY2NDC(0.75);
st_BEO1->SetTextColor(kRed);
TLegend *l_BEO = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BEO->SetBorderSize(0);

        l_BEO->AddEntry(hist_BEO1, legendEntry1.c_str(),"l");
        l_BEO->AddEntry(hist_BEO2, legendEntry2.c_str(),"l");

       l_BEO->Draw();

       Barrel_ExpOcc[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *BEO_pad2 = new TPad("BEO_pad2", "", 0, 0.05, 1, 0.3);
   BEO_pad2->SetTopMargin(0);
   BEO_pad2->SetBottomMargin(0.2);
   BEO_pad2->SetTitle("");
   BEO_pad2->SetGridy();
   BEO_pad2->SetGridx();
   BEO_pad2->Draw();
   BEO_pad2->cd();       // pad2 becomes the current pad


   TH1F *BEO_h3 = (TH1F*)hist_BEO2->Clone("BEO_h3");
   BEO_h3->SetTitle("");
   BEO_h3->SetLineColor(kBlack);
   BEO_h3->SetStats(0);      // No statistics on lower plot
   BEO_h3->Divide(hist_BEO1);
   BEO_h3->SetMarkerStyle(21);
   BEO_h3->GetXaxis()->SetLabelSize(0.1);
   BEO_h3->GetYaxis()->SetRangeUser(-1,8);
   BEO_h3->GetYaxis()->SetNdivisions(508);
   BEO_h3->GetYaxis()->SetTitle("Ratio");
   BEO_h3->GetYaxis()->SetTitleOffset(0.2);
   BEO_h3->GetYaxis()->SetTitleSize(0.15);
   BEO_h3->GetYaxis()->SetLabelSize(0.1);
   BEO_h3->Draw("ep");       // Draw the ratio plot



TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Barrel");
out->mkdir("Barrel/expected_occupancy/");
out->cd("Barrel/expected_occupancy/");
Barrel_ExpOcc[i]->Write();
out->Close();

std::string outNameBEO = "Barrel" + std::string(hist_name_BEO.at(i)) + ".png";       //save histogram as a image
Barrel_ExpOcc[i]->SaveAs(outNameBEO.c_str());



}



//------------------------------------------------------------------------------------------------
//Fudicial_cut_efficiencies
//--------------------------------------------------------------------------------------------------





TDirectory* dir_BFCD1 = (TDirectory*)f1->Get("Barrel/Fudicial_cut_efficiencies");
TDirectory* dir_BFCD12 = (TDirectory*)f2->Get("Barrel/Fudicial_cut_efficiencies");

std::vector<std::string>hist_name_BFCD;

hist_name_BFCD.push_back("FiducialCutEffW-2");
hist_name_BFCD.push_back("FiducialCutEffW-1");
hist_name_BFCD.push_back("FiducialCutEffW0");
hist_name_BFCD.push_back("FiducialCutEffW1");
hist_name_BFCD.push_back("FiducialCutEffW2");

//const Int_t nhist=10;
TCanvas *Barrel_FiducialCutEff[10];
for(unsigned int i=0;i<hist_name_BFCD.size();i++){

TH1F *hist_BFCD1= (TH1F*)dir_BFCD1->Get((hist_name_BFCD.at(i)).c_str());
TH1F *hist_BFCD2= (TH1F*)dir_BFCD12->Get((hist_name_BFCD.at(i)).c_str());

Barrel_FiducialCutEff[i] = new TCanvas(Form("FiducialCutEffW%d", i-2));

TPad *BFCD_pad1 = new TPad("BFCD_pad1", "", 0, 0.3, 1, 1.0);
   BFCD_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BFCD_pad1->Draw();             // Draw the upper pad: pad1
   BFCD_pad1->cd();               // pad1 becomes the current pad



hist_BFCD2->Draw();
hist_BFCD1->SetLineColor(kRed);
hist_BFCD1->Draw("sames");

float maxBFCD1=hist_BFCD1->GetMaximum();
float maxBFCD2=hist_BFCD2->GetMaximum();
if(maxBFCD1 > maxBFCD2){
hist_BFCD2->SetMaximum(maxBFCD1*1.5);
}
else
{
hist_BFCD2->SetMaximum(maxBFCD2*1.5);
}


gPad->Update();
TPaveStats *st_BFCD1 = (TPaveStats*)hist_BFCD1->FindObject("stats");
st_BFCD1->SetX1NDC(0.15);
st_BFCD1->SetX2NDC(0.35);
st_BFCD1->SetY1NDC(0.50); //new x start position
st_BFCD1->SetY2NDC(0.65);
st_BFCD1->SetTextColor(kRed);


TPaveStats *st_BFCD2 = (TPaveStats*)hist_BFCD2->FindObject("stats");
st_BFCD2->SetX1NDC(0.15);
st_BFCD2->SetX2NDC(0.35);
st_BFCD2->SetY1NDC(0.70); //new x start position
st_BFCD2->SetY2NDC(0.85);



TLegend *l_BFCD = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BFCD->SetBorderSize(0);

        l_BFCD->AddEntry(hist_BFCD1, legendEntry1.c_str(),"l");
        l_BFCD->AddEntry(hist_BFCD2, legendEntry2.c_str(),"l");

       l_BFCD->Draw();



Barrel_FiducialCutEff[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *BFCD_pad2 = new TPad("BFCD_pad2", "", 0, 0.05, 1, 0.3);
   BFCD_pad2->SetTopMargin(0);
   BFCD_pad2->SetBottomMargin(0.2);
   BFCD_pad2->SetTitle("");
   BFCD_pad2->SetGridy();
   BFCD_pad2->SetGridx();
   BFCD_pad2->Draw();
   BFCD_pad2->cd();       // pad2 becomes the current pad


   TH1F *BFCD_h3 = (TH1F*)hist_BFCD2->Clone("BFCD_h3");
   BFCD_h3->SetTitle("");
   BFCD_h3->SetLineColor(kBlack);
   BFCD_h3->SetStats(0);      // No statistics on lower plot
   BFCD_h3->Divide(hist_BFCD1);
   BFCD_h3->SetMarkerStyle(21);
   BFCD_h3->GetXaxis()->SetLabelSize(0.1);
   BFCD_h3->GetYaxis()->SetRangeUser(-1,6);
   BFCD_h3->GetYaxis()->SetNdivisions(508);
   BFCD_h3->GetYaxis()->SetTitle("Ratio");
   BFCD_h3->GetYaxis()->SetTitleOffset(0.2);
   BFCD_h3->GetYaxis()->SetTitleSize(0.15);
   BFCD_h3->GetYaxis()->SetLabelSize(0.1);
   BFCD_h3->Draw("ep");       // Draw the ratio plot



TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Barrel");
out->mkdir("Barrel/Fudicial_cut_efficiencies/");
out->cd("Barrel/Fudicial_cut_efficiencies/");
Barrel_FiducialCutEff[i]->Write();
out->Close();

std::string outNameBFCD = "Barrel" + std::string(hist_name_BFCD.at(i)) + ".png";       //save histogram as a image
Barrel_FiducialCutEff[i]->SaveAs(outNameBFCD.c_str());



}



//------------------------------------------------------------------------------------------------
//RPC_occupancy_from_DT
//--------------------------------------------------------------------------------------------------





TDirectory* dir_BROD1 = (TDirectory*)f1->Get("Barrel/RPC_occupancy_from_DT");
TDirectory* dir_BROD12 = (TDirectory*)f2->Get("Barrel/RPC_occupancy_from_DT");

std::vector<std::string>hist_name_BROD;

hist_name_BROD.push_back("RPCOccW-2");
hist_name_BROD.push_back("RPCOccW-1");
hist_name_BROD.push_back("RPCOccW0");
hist_name_BROD.push_back("RPCOccW1");
hist_name_BROD.push_back("RPCOccW2");

//const Int_t nhist=10;
TCanvas *Barrel_RPCOcc[10];
for(unsigned int i=0;i<hist_name_BROD.size();i++){

TH1F *hist_BROD1= (TH1F*)dir_BROD1->Get((hist_name_BROD.at(i)).c_str());
TH1F *hist_BROD2= (TH1F*)dir_BROD12->Get((hist_name_BROD.at(i)).c_str());

Barrel_RPCOcc[i] = new TCanvas(Form("RPCOccW%d", i-2));

 TPad *BROD_pad1 = new TPad("BROD_pad1", "", 0, 0.3, 1, 1.0);
   BROD_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BROD_pad1->Draw();             // Draw the upper pad: pad1
   BROD_pad1->cd();               // pad1 becomes the current pad



hist_BROD2->Draw();
hist_BROD1->SetLineColor(kRed);
hist_BROD1->Draw("sames");

float maxBROD1=hist_BROD1->GetMaximum();
float maxBROD2=hist_BROD2->GetMaximum();
if(maxBROD1 > maxBROD2){
hist_BROD2->SetMaximum(maxBROD1*1.5);
}
else
{
hist_BROD2->SetMaximum(maxBROD2*1.5);
}


gPad->Update();
TPaveStats *st_BROD1 = (TPaveStats*)hist_BROD1->FindObject("stats");
st_BROD1->SetY1NDC(0.60); //new x start position
st_BROD1->SetY2NDC(0.75);
st_BROD1->SetTextColor(kRed);

TLegend *l_BROD = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BROD->SetBorderSize(0);

        l_BROD->AddEntry(hist_BROD1, legendEntry1.c_str(),"l");
        l_BROD->AddEntry(hist_BROD2, legendEntry2.c_str(),"l");

       l_BROD->Draw();
Barrel_RPCOcc[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *BROD_pad2 = new TPad("BROD_pad2", "", 0, 0.05, 1, 0.3);
   BROD_pad2->SetTopMargin(0);
   BROD_pad2->SetBottomMargin(0.2);
   BROD_pad2->SetTitle("");
   BROD_pad2->SetGridy();
   BROD_pad2->SetGridx();
   BROD_pad2->Draw();
   BROD_pad2->cd();       // pad2 becomes the current pad


   TH1F *BROD_h3 = (TH1F*)hist_BROD2->Clone("BROD_h3");
   BROD_h3->SetTitle("");
   BROD_h3->SetLineColor(kBlack);
   BROD_h3->SetStats(0);      // No statistics on lower plot
   BROD_h3->Divide(hist_BROD1);
   BROD_h3->SetMarkerStyle(21);
   BROD_h3->GetXaxis()->SetLabelSize(0.1);
   BROD_h3->GetYaxis()->SetRangeUser(-1,6);
   BROD_h3->GetYaxis()->SetNdivisions(508);
   BROD_h3->GetYaxis()->SetTitle("Ratio");
   BROD_h3->GetYaxis()->SetTitleOffset(0.2);
   BROD_h3->GetYaxis()->SetTitleSize(0.15);
   BROD_h3->GetYaxis()->SetLabelSize(0.1);
   BROD_h3->Draw("ep");       // Draw the ratio plot


TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Barrel");
out->mkdir("Barrel/RPC_occupancy_from_DT/");
out->cd("Barrel/RPC_occupancy_from_DT/");
Barrel_RPCOcc[i]->Write();
out->Close();

std::string outNameBROD = "Barrel" + std::string(hist_name_BROD.at(i)) + ".png";       //save histogram as a image
Barrel_RPCOcc[i]->SaveAs(outNameBROD.c_str());



}


//------------------------------------------------------------------------------------------------
//RPC_occupancy
//--------------------------------------------------------------------------------------------------





TDirectory* dir_BRO1 = (TDirectory*)f1->Get("Barrel/RPC_occupancy");
TDirectory* dir_BRO12 = (TDirectory*)f2->Get("Barrel/RPC_occupancy");

std::vector<std::string>hist_name_BRO;

hist_name_BRO.push_back("RPCRealOccW-2");
hist_name_BRO.push_back("RPCRealOccW-1");
hist_name_BRO.push_back("RPCRealOccW0");
hist_name_BRO.push_back("RPCRealOccW1");
hist_name_BRO.push_back("RPCRealOccW2");

//const Int_t nhist=10;
TCanvas *Barrel_RPCRealOcc[10];
for(unsigned int i=0;i<hist_name_BRO.size();i++){

TH1F *hist_BRO1= (TH1F*)dir_BRO1->Get((hist_name_BRO.at(i)).c_str());
TH1F *hist_BRO2= (TH1F*)dir_BRO12->Get((hist_name_BRO.at(i)).c_str());

Barrel_RPCRealOcc[i] = new TCanvas(Form("RPCRealOccW%d", i-2));

 TPad *BRO_pad1 = new TPad("BRO_pad1", "", 0, 0.3, 1, 1.0);
   BRO_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BRO_pad1->Draw();             // Draw the upper pad: pad1
   BRO_pad1->cd();               // pad1 becomes the current pad




hist_BRO2->Draw();
hist_BRO1->SetLineColor(kRed);
hist_BRO1->Draw("sames");

float maxBRO1=hist_BRO1->GetMaximum();
float maxBRO2=hist_BRO2->GetMaximum();
if(maxBRO1 > maxBRO2){
hist_BRO2->SetMaximum(maxBRO1*1.5);
}
else
{
hist_BRO2->SetMaximum(maxBRO2*1.5);
}


gPad->Update();
TPaveStats *st_BRO1 = (TPaveStats*)hist_BRO1->FindObject("stats");
st_BRO1->SetY1NDC(0.60); //new x start position
st_BRO1->SetY2NDC(0.75);
st_BRO1->SetTextColor(kRed);

TLegend *l_BRO = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BRO->SetBorderSize(0);

        l_BRO->AddEntry(hist_BRO1, legendEntry1.c_str(),"l");
        l_BRO->AddEntry(hist_BRO2, legendEntry2.c_str(),"l");

       l_BRO->Draw();


Barrel_RPCRealOcc[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *BRO_pad2 = new TPad("BROD_pad2", "", 0, 0.05, 1, 0.3);
   BRO_pad2->SetTopMargin(0);
   BRO_pad2->SetBottomMargin(0.2);
   BRO_pad2->SetTitle("");
   BRO_pad2->SetGridy();
   BRO_pad2->SetGridx();
   BRO_pad2->Draw();
   BRO_pad2->cd();       // pad2 becomes the current pad


   TH1F *BRO_h3 = (TH1F*)hist_BRO2->Clone("BRO_h3");
   BRO_h3->SetTitle("");
   BRO_h3->SetLineColor(kBlack);
   BRO_h3->SetStats(0);      // No statistics on lower plot
   BRO_h3->Divide(hist_BRO1);
   BRO_h3->SetMarkerStyle(21);
   BRO_h3->GetXaxis()->SetLabelSize(0.1);
   BRO_h3->GetYaxis()->SetRangeUser(-1,11);
   BRO_h3->GetYaxis()->SetNdivisions(508);
   BRO_h3->GetYaxis()->SetTitle("Ratio");
   BRO_h3->GetYaxis()->SetTitleOffset(0.2);
   BRO_h3->GetYaxis()->SetTitleSize(0.15);
   BRO_h3->GetYaxis()->SetLabelSize(0.1);
   BRO_h3->Draw("ep");       // Draw the ratio plot



TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Barrel");
out->mkdir("Barrel/RPC_occupancy/");
out->cd("Barrel/RPC_occupancy/");
Barrel_RPCRealOcc[i]->Write();
out->Close();

std::string outNameBRO = "Barrel" + std::string(hist_name_BRO.at(i)) + ".png";       //save histogram as a image
Barrel_RPCRealOcc[i]->SaveAs(outNameBRO.c_str());



}


//------------------------------------------------------------------------------------------------
//Total_efficiencies
//--------------------------------------------------------------------------------------------------





TDirectory* dir_BTE1 = (TDirectory*)f1->Get("Barrel/Total_efficiencies");
TDirectory* dir_BTE12 = (TDirectory*)f2->Get("Barrel/Total_efficiencies");

std::vector<std::string>hist_name_BTE;

hist_name_BTE.push_back("TotalEffW-2");
hist_name_BTE.push_back("TotalEffW-1");
hist_name_BTE.push_back("TotalEffW0");
hist_name_BTE.push_back("TotalEffW1");
hist_name_BTE.push_back("TotalEffW2");

//const Int_t nhist=10;
TCanvas *Barrel_TotalEff[10];
for(unsigned int i=0;i<hist_name_BTE.size();i++){

TH1F *hist_BTE1= (TH1F*)dir_BTE1->Get((hist_name_BTE.at(i)).c_str());
TH1F *hist_BTE2= (TH1F*)dir_BTE12->Get((hist_name_BTE.at(i)).c_str());

Barrel_TotalEff[i] = new TCanvas(Form("TotalEffW%d", i-2));

 TPad *BTE_pad1 = new TPad("BTE_pad1", "", 0, 0.3, 1, 1.0);
   BTE_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   BTE_pad1->Draw();             // Draw the upper pad: pad1
   BTE_pad1->cd();               // pad1 becomes the current pad



hist_BTE2->Draw();
hist_BTE1->SetLineColor(kRed);
hist_BTE1->Draw("sames");


float maxBTE1=hist_BTE1->GetMaximum();
float maxBTE2=hist_BTE2->GetMaximum();
if(maxBTE1 > maxBTE2){
hist_BTE2->SetMaximum(maxBTE1*1.5);
}
else
{
hist_BTE2->SetMaximum(maxBTE2*1.5);
}



gPad->Update();
TPaveStats *st_BTE1 = (TPaveStats*)hist_BTE1->FindObject("stats");

st_BTE1->SetX1NDC(0.15);
st_BTE1->SetX2NDC(0.35); 
st_BTE1->SetY1NDC(0.50); //new x start position
st_BTE1->SetY2NDC(0.65);
st_BTE1->SetTextColor(kRed);

TPaveStats *st_BTE2 = (TPaveStats*)hist_BTE2->FindObject("stats");
st_BTE2->SetX1NDC(0.15);
st_BTE2->SetX2NDC(0.35); 
st_BTE2->SetY1NDC(0.70); //new x start position
st_BTE2->SetY2NDC(0.85);




TLegend *l_BTE = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_BTE->SetBorderSize(0);

        l_BTE->AddEntry(hist_BTE1, legendEntry1.c_str(),"l");
        l_BTE->AddEntry(hist_BTE2, legendEntry2.c_str(),"l");

       l_BTE->Draw();

Barrel_TotalEff[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *BTE_pad2 = new TPad("BTE_pad2", "", 0, 0.05, 1, 0.3);
   BTE_pad2->SetTopMargin(0);
   BTE_pad2->SetBottomMargin(0.2);
   BTE_pad2->SetTitle("");
   BTE_pad2->SetGridy();
   BTE_pad2->SetGridx();
   BTE_pad2->Draw();
   BTE_pad2->cd();       // pad2 becomes the current pad


   TH1F *BTE_h3 = (TH1F*)hist_BTE2->Clone("BTE_h3");
   BTE_h3->SetTitle("");
   BTE_h3->SetLineColor(kBlack);
   BTE_h3->SetStats(0);      // No statistics on lower plot
   BTE_h3->Divide(hist_BTE1);
   BTE_h3->SetMarkerStyle(21);
   BTE_h3->GetXaxis()->SetLabelSize(0.1);
   BTE_h3->GetYaxis()->SetRangeUser(-1,6);
   BTE_h3->GetYaxis()->SetNdivisions(508);
   BTE_h3->GetYaxis()->SetTitle("Ratio");
   BTE_h3->GetYaxis()->SetTitleOffset(0.2);
   BTE_h3->GetYaxis()->SetTitleSize(0.15);
   BTE_h3->GetYaxis()->SetLabelSize(0.1);
   BTE_h3->Draw("ep");       // Draw the ratio plot




TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Barrel");
out->mkdir("Barrel/Total_efficiencies/");
out->cd("Barrel/Total_efficiencies/");
Barrel_TotalEff[i]->Write();
out->Close();

std::string outNameBTE = "Barrel" + std::string(hist_name_BTE.at(i)) + ".png";       //save histogram as a image
Barrel_TotalEff[i]->SaveAs(outNameBTE.c_str());



}











//-----------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
//Endcap 
//--------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------
//average_residuals
//--------------------------------------------------------------------------------------------------



TDirectory* dir_EACS1 = (TDirectory*)f1->Get("Endcap/average_cluster_size");
TDirectory* dir_EACS12 = (TDirectory*)f2->Get("Endcap/average_cluster_size");

std::vector<std::string>hist_name_EACS;

hist_name_EACS.push_back("AverageCLSD-4");
hist_name_EACS.push_back("AverageCLSD-3");
hist_name_EACS.push_back("AverageCLSD-2");
hist_name_EACS.push_back("AverageCLSD-1");
hist_name_EACS.push_back("AverageCLSD1");
hist_name_EACS.push_back("AverageCLSD2");
hist_name_EACS.push_back("AverageCLSD3");
hist_name_EACS.push_back("AverageCLSD4");



const Int_t nhistE=10;
TCanvas *Endcap_AverageCLSW[nhistE];
for(unsigned int i=0;i<hist_name_EACS.size();i++){

TH1F *hist_EACS1= (TH1F*)dir_EACS1->Get((hist_name_EACS.at(i)).c_str());
TH1F *hist_EACS2= (TH1F*)dir_EACS12->Get((hist_name_EACS.at(i)).c_str());


if(i<4){
Endcap_AverageCLSW[i] = new TCanvas(Form("AverageCLSD%d", i-4));
}
else{
Endcap_AverageCLSW[i] = new TCanvas(Form("AverageCLSD%d", i-3));
}
//Endcap_AverageCLSW[i] = new TCanvas(Form("AverageCLSD%d", i-2));


 TPad *EACS_pad1 = new TPad("EACS_pad1", "", 0, 0.3, 1, 1.0);
   EACS_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EACS_pad1->Draw();             // Draw the upper pad: pad1
   EACS_pad1->cd();               // pad1 becomes the current pad



hist_EACS2->Draw();
hist_EACS1->SetLineColor(kRed);
hist_EACS1->Draw("sames");

float maxEACS1=hist_EACS1->GetMaximum();
float maxEACS2=hist_EACS2->GetMaximum();
if(maxEACS1 > maxEACS2){
hist_EACS2->SetMaximum(maxEACS1*1.5);
}
else
{
hist_EACS2->SetMaximum(maxEACS2*1.5);
}


gPad->Update();
TPaveStats *st_EACS1 = (TPaveStats*)hist_EACS1->FindObject("stats");
st_EACS1->SetY1NDC(0.60); //new x start position
st_EACS1->SetY2NDC(0.75);
st_EACS1->SetTextColor(kRed);

TLegend *l_EACS = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EACS->SetBorderSize(0);

        l_EACS->AddEntry(hist_EACS1, legendEntry1.c_str(),"l");
        l_EACS->AddEntry(hist_EACS2, legendEntry2.c_str(),"l");

       l_EACS->Draw();
Endcap_AverageCLSW[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *EACS_pad2 = new TPad("EACS_pad2", "", 0, 0.05, 1, 0.3);
   EACS_pad2->SetTopMargin(0);
   EACS_pad2->SetBottomMargin(0.2);
   EACS_pad2->SetTitle("");
   EACS_pad2->SetGridy();
   EACS_pad2->SetGridx();
   EACS_pad2->Draw();
   EACS_pad2->cd();       // pad2 becomes the current pad


   TH1F *EACS_h3 = (TH1F*)hist_EACS2->Clone("EACS_h3");
   EACS_h3->SetTitle("");
   EACS_h3->SetLineColor(kBlack);
   EACS_h3->SetStats(0);      // No statistics on lower plot
   EACS_h3->Divide(hist_EACS1);
   EACS_h3->SetMarkerStyle(21);
   EACS_h3->GetXaxis()->SetLabelSize(0.1);
   EACS_h3->GetYaxis()->SetRangeUser(-2,5);
   EACS_h3->GetYaxis()->SetNdivisions(508);
   EACS_h3->GetYaxis()->SetTitle("Ratio");
   EACS_h3->GetYaxis()->SetTitleOffset(0.2);
   EACS_h3->GetYaxis()->SetTitleSize(0.15);
   EACS_h3->GetYaxis()->SetLabelSize(0.1);
   EACS_h3->Draw("ep");       // Draw the ratio plot




TFile *out = TFile::Open(outfilename.c_str(), "UPDATE"); 
//out->mkdir("Endcap");
out->mkdir("Endcap/average_cluster_size/");
out->cd("Endcap/average_cluster_size/");
Endcap_AverageCLSW[i]->Write();
out->Close();


std::string outNameEACS = "Endcap" + std::string(hist_name_EACS.at(i)) + ".png";       //save histogram as a image
Endcap_AverageCLSW[i]->SaveAs(outNameEACS.c_str());


}



//------------------------------------------------------------------------------------------------
//average_residuals
//--------------------------------------------------------------------------------------------------





TDirectory* dir_EAR1 = (TDirectory*)f1->Get("Endcap/average_residuals");
TDirectory* dir_EAR12 = (TDirectory*)f2->Get("Endcap/average_residuals");

std::vector<std::string>hist_name_EAR;

hist_name_EAR.push_back("AverageResidualsD-4");
hist_name_EAR.push_back("AverageResidualsD-3");
hist_name_EAR.push_back("AverageResidualsD-2");
hist_name_EAR.push_back("AverageResidualsD-1");
hist_name_EAR.push_back("AverageResidualsD1");
hist_name_EAR.push_back("AverageResidualsD2");
hist_name_EAR.push_back("AverageResidualsD3");
hist_name_EAR.push_back("AverageResidualsD4");


//const Int_t nhist=10;
TCanvas *Endcap_AverageResiduals[10];
for(unsigned int i=0;i<hist_name_EAR.size();i++){

TH1F *hist_EAR1= (TH1F*)dir_EAR1->Get((hist_name_EAR.at(i)).c_str());
TH1F *hist_EAR2= (TH1F*)dir_EAR12->Get((hist_name_EAR.at(i)).c_str());


if(i<4){
Endcap_AverageResiduals[i] = new TCanvas(Form("AverageResidualsD%d", i-4));
}
else{
Endcap_AverageResiduals[i] = new TCanvas(Form("AverageResidualsD%d", i-3));
}
//Endcap_AverageResiduals[i] = new TCanvas(Form("AverageResidualsD%d", i-2));


TPad *EAR_pad1 = new TPad("EAR_pad1", "", 0, 0.3, 1, 1.0);
   EAR_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EAR_pad1->Draw();             // Draw the upper pad: pad1
   EAR_pad1->cd();               // pad1 becomes the current pad



hist_EAR2->Draw();
hist_EAR1->SetLineColor(kRed);
hist_EAR1->Draw("sames");

float maxEAR1=hist_EAR1->GetMaximum();
float maxEAR2=hist_EAR2->GetMaximum();
if(maxEAR1 > maxEAR2){
hist_EAR2->SetMaximum(maxEAR1*1.5);
}
else
{
hist_EAR2->SetMaximum(maxEAR2*1.5);
}


gPad->Update();
TPaveStats *st_EAR1 = (TPaveStats*)hist_EAR1->FindObject("stats");
st_EAR1->SetY1NDC(0.60); //new x start position
st_EAR1->SetY2NDC(0.75);
st_EAR1->SetTextColor(kRed);

TLegend *l_EAR = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EAR->SetBorderSize(0);

        l_EAR->AddEntry(hist_EAR1, legendEntry1.c_str(),"l");
        l_EAR->AddEntry(hist_EAR2, legendEntry2.c_str(),"l");

       l_EAR->Draw();


Endcap_AverageResiduals[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *EAR_pad2 = new TPad("EAR_pad2", "", 0, 0.05, 1, 0.3);
   EAR_pad2->SetTopMargin(0);
   EAR_pad2->SetBottomMargin(0.2);
   EAR_pad2->SetTitle("");
   EAR_pad2->SetGridy();
   EAR_pad2->SetGridx();
   EAR_pad2->Draw();
   EAR_pad2->cd();       // pad2 becomes the current pad


   TH1F *EAR_h3 = (TH1F*)hist_EAR2->Clone("EAR_h3");
   EAR_h3->SetTitle("");
   EAR_h3->SetLineColor(kBlack);
   EAR_h3->SetStats(0);      // No statistics on lower plot
   EAR_h3->Divide(hist_EAR1);
   EAR_h3->SetMarkerStyle(21);
   EAR_h3->GetXaxis()->SetLabelSize(0.1);
   EAR_h3->GetYaxis()->SetRangeUser(-1,8);
   EAR_h3->GetYaxis()->SetNdivisions(508);
   EAR_h3->GetYaxis()->SetTitle("Ratio");
   EAR_h3->GetYaxis()->SetTitleOffset(0.2);
   EAR_h3->GetYaxis()->SetTitleSize(0.15);
   EAR_h3->GetYaxis()->SetLabelSize(0.1);
   EAR_h3->Draw("ep");       // Draw the ratio plot




TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Endcap");
out->mkdir("Endcap/average_residuals/");
out->cd("Endcap/average_residuals/");
Endcap_AverageResiduals[i]->Write();
out->Close();


std::string outNameEAR = "Endcap" + std::string(hist_name_EAR.at(i)) + ".png";       //save histogram as a image
Endcap_AverageResiduals[i]->SaveAs(outNameEAR.c_str());


}





//------------------------------------------------------------------------------------------------
//average_strip_efficiencies
//--------------------------------------------------------------------------------------------------





TDirectory* dir_EASE1 = (TDirectory*)f1->Get("Endcap/average_strip_efficiencies");
TDirectory* dir_EASE12 = (TDirectory*)f2->Get("Endcap/average_strip_efficiencies");

std::vector<std::string>hist_name_EASE;

hist_name_EASE.push_back("AverageStripEffD-4");
hist_name_EASE.push_back("AverageStripEffD-3");
hist_name_EASE.push_back("AverageStripEffD-2");
hist_name_EASE.push_back("AverageStripEffD-1");
hist_name_EASE.push_back("AverageStripEffD1");
hist_name_EASE.push_back("AverageStripEffD2");
hist_name_EASE.push_back("AverageStripEffD3");
hist_name_EASE.push_back("AverageStripEffD4");


//const Int_t nhist=10;
TCanvas *Endcap_AverageStripEff[10];
for(unsigned int i=0;i<hist_name_EASE.size();i++){

TH1F *hist_EASE1= (TH1F*)dir_EASE1->Get((hist_name_EASE.at(i)).c_str());
TH1F *hist_EASE2= (TH1F*)dir_EASE12->Get((hist_name_EASE.at(i)).c_str());

if(i<4){
Endcap_AverageStripEff[i] = new TCanvas(Form("AverageStripEffD%d", i-4));
}
else{
Endcap_AverageStripEff[i] = new TCanvas(Form("AverageStripEffD%d", i-3));
}

//Endcap_AverageStripEff[i] = new TCanvas(Form("AverageStripEffD%d", i-2));



  TPad *EASE_pad1 = new TPad("EASE_pad1", "", 0, 0.3, 1, 1.0);
   EASE_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EASE_pad1->Draw();             // Draw the upper pad: pad1
   EASE_pad1->cd();               // pad1 becomes the current pad




hist_EASE2->Draw();
hist_EASE1->SetLineColor(kRed);
hist_EASE1->Draw("sames");

float maxEASE1=hist_EASE1->GetMaximum();
float maxEASE2=hist_EASE2->GetMaximum();
if(maxEASE1 > maxEASE2){
hist_EASE2->SetMaximum(maxEASE1*1.5);
}
else
{
hist_EASE2->SetMaximum(maxEASE2*1.5);
}


gPad->Update();
TPaveStats *st_EASE1 = (TPaveStats*)hist_EASE1->FindObject("stats");
st_EASE1->SetX1NDC(0.25);
st_EASE1->SetX2NDC(0.45);

st_EASE1->SetY1NDC(0.50); //new x start position
st_EASE1->SetY2NDC(0.65);
st_EASE1->SetTextColor(kRed);

TPaveStats *st_EASE2 = (TPaveStats*)hist_EASE2->FindObject("stats");
st_EASE2->SetX1NDC(0.25);
st_EASE2->SetX2NDC(0.45);
st_EASE2->SetY1NDC(0.70); //new x start position
st_EASE2->SetY2NDC(0.85);


TLegend *l_EASE = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EASE->SetBorderSize(0);

        l_EASE->AddEntry(hist_EASE1, legendEntry1.c_str(),"l");
        l_EASE->AddEntry(hist_EASE2, legendEntry2.c_str(),"l");

       l_EASE->Draw();



            Endcap_AverageStripEff[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *EASE_pad2 = new TPad("EASE_pad2", "", 0, 0.05, 1, 0.3);
   EASE_pad2->SetTopMargin(0);
   EASE_pad2->SetBottomMargin(0.2);
   EASE_pad2->SetTitle("");
   EASE_pad2->SetGridy();
   EASE_pad2->SetGridx();
   EASE_pad2->Draw();
   EASE_pad2->cd();       // pad2 becomes the current pad


   TH1F *EASE_h3 = (TH1F*)hist_EASE2->Clone("EASE_h3");
   EASE_h3->SetTitle("");
   EASE_h3->SetLineColor(kBlack);
   EASE_h3->SetStats(0);      // No statistics on lower plot
   EASE_h3->Divide(hist_EASE1);
   EASE_h3->SetMarkerStyle(21);
   EASE_h3->GetXaxis()->SetLabelSize(0.1);
   EASE_h3->GetYaxis()->SetRangeUser(-1,8);
   EASE_h3->GetYaxis()->SetNdivisions(508);
   EASE_h3->GetYaxis()->SetTitle("Ratio");
   EASE_h3->GetYaxis()->SetTitleOffset(0.2);
   EASE_h3->GetYaxis()->SetTitleSize(0.15);
   EASE_h3->GetYaxis()->SetLabelSize(0.1);
   EASE_h3->Draw("ep");       // Draw the ratio plot


TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Endcap");
out->mkdir("Endcap/average_strip_efficiencies/");
out->cd("Endcap/average_strip_efficiencies/");
Endcap_AverageStripEff[i]->Write();
out->Close();

std::string outNameEASE = "Endcap" + std::string(hist_name_EASE.at(i)) + ".png";       //save histogram as a image
Endcap_AverageStripEff[i]->SaveAs(outNameEASE.c_str());



}





//------------------------------------------------------------------------------------------------
//expected_occupancy
//--------------------------------------------------------------------------------------------------





TDirectory* dir_EEO1 = (TDirectory*)f1->Get("Endcap/expected_occupancy");
TDirectory* dir_EEO12 = (TDirectory*)f2->Get("Endcap/expected_occupancy");

std::vector<std::string>hist_name_EEO;

hist_name_EEO.push_back("ExpOccD-4");
hist_name_EEO.push_back("ExpOccD-3");
hist_name_EEO.push_back("ExpOccD-2");
hist_name_EEO.push_back("ExpOccD-1");
hist_name_EEO.push_back("ExpOccD1");
hist_name_EEO.push_back("ExpOccD2");
hist_name_EEO.push_back("ExpOccD3");
hist_name_EEO.push_back("ExpOccD4");


//const Int_t nhist=10;
TCanvas *Endcap_ExpOcc[10];
for(unsigned int i=0;i<hist_name_EEO.size();i++){

TH1F *hist_EEO1= (TH1F*)dir_EEO1->Get((hist_name_EEO.at(i)).c_str());
TH1F *hist_EEO2= (TH1F*)dir_EEO12->Get((hist_name_EEO.at(i)).c_str());

if(i<4){
Endcap_ExpOcc[i] = new TCanvas(Form("ExpOccD%d", i-4));
}
else{
Endcap_ExpOcc[i] = new TCanvas(Form("ExpOccD%d", i-3));
}

//Endcap_ExpOcc[i] = new TCanvas(Form("ExpOccD%d", i-2));


TPad *EEO_pad1 = new TPad("EEO_pad1", "", 0, 0.3, 1, 1.0);
   EEO_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EEO_pad1->Draw();             // Draw the upper pad: pad1
   EEO_pad1->cd();               // pad1 becomes the current pad





hist_EEO2->Draw();
hist_EEO1->SetLineColor(kRed);
hist_EEO1->Draw("sames");

float maxEEO1=hist_EEO1->GetMaximum();
float maxEEO2=hist_EEO2->GetMaximum();
if(maxEEO1 > maxEEO2){
hist_EEO2->SetMaximum(maxEEO1*1.5);
}
else
{
hist_EEO2->SetMaximum(maxEEO2*1.5);
}


gPad->Update();
TPaveStats *st_EEO1 = (TPaveStats*)hist_EEO1->FindObject("stats");
st_EEO1->SetY1NDC(0.60); //new x start position
st_EEO1->SetY2NDC(0.75);
st_EEO1->SetTextColor(kRed);

TLegend *l_EEO = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EEO->SetBorderSize(0);

        l_EEO->AddEntry(hist_EEO1, legendEntry1.c_str(),"l");
        l_EEO->AddEntry(hist_EEO2, legendEntry2.c_str(),"l");

       l_EEO->Draw();

      Endcap_ExpOcc[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *EEO_pad2 = new TPad("EEO_pad2", "", 0, 0.05, 1, 0.3);
   EEO_pad2->SetTopMargin(0);
   EEO_pad2->SetBottomMargin(0.2);
   EEO_pad2->SetTitle("");
   EEO_pad2->SetGridy();
   EEO_pad2->SetGridx();
   EEO_pad2->Draw();
   EEO_pad2->cd();       // pad2 becomes the current pad


   TH1F *EEO_h3 = (TH1F*)hist_EEO2->Clone("EEO_h3");
   EEO_h3->SetTitle("");
   EEO_h3->SetLineColor(kBlack);
   EEO_h3->SetStats(0);      // No statistics on lower plot
   EEO_h3->Divide(hist_EEO1);
   EEO_h3->SetMarkerStyle(21);
   EEO_h3->GetXaxis()->SetLabelSize(0.1);
   EEO_h3->GetYaxis()->SetRangeUser(-2,5);
   EEO_h3->GetYaxis()->SetNdivisions(508);
   EEO_h3->GetYaxis()->SetTitle("Ratio");
   EEO_h3->GetYaxis()->SetTitleOffset(0.2);
   EEO_h3->GetYaxis()->SetTitleSize(0.15);
   EEO_h3->GetYaxis()->SetLabelSize(0.1);
   EEO_h3->Draw("ep");       // Draw the ratio plot



TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Endcap");
out->mkdir("Endcap/expected_occupancy/");
out->cd("Endcap/expected_occupancy/");
Endcap_ExpOcc[i]->Write();
out->Close();

std::string outNameEEO = "Endcap" + std::string(hist_name_EEO.at(i)) + ".png";       //save histogram as a image
Endcap_ExpOcc[i]->SaveAs(outNameEEO.c_str());


}



//------------------------------------------------------------------------------------------------
//Fudicial_cut_efficiencies
//--------------------------------------------------------------------------------------------------





TDirectory* dir_EFCD1 = (TDirectory*)f1->Get("Endcap/Fudicial_cut_efficiencies");
TDirectory* dir_EFCD12 = (TDirectory*)f2->Get("Endcap/Fudicial_cut_efficiencies");

std::vector<std::string>hist_name_EFCD;

hist_name_EFCD.push_back("FiducialCutEffD-4");
hist_name_EFCD.push_back("FiducialCutEffD-3");
hist_name_EFCD.push_back("FiducialCutEffD-2");
hist_name_EFCD.push_back("FiducialCutEffD-1");
hist_name_EFCD.push_back("FiducialCutEffD1");
hist_name_EFCD.push_back("FiducialCutEffD2");
hist_name_EFCD.push_back("FiducialCutEffD3");
hist_name_EFCD.push_back("FiducialCutEffD4");


//const Int_t nhist=10;
TCanvas *Endcap_FiducialCutEff[10];
for(unsigned int i=0;i<hist_name_EFCD.size();i++){

TH1F *hist_EFCD1= (TH1F*)dir_EFCD1->Get((hist_name_EFCD.at(i)).c_str());
TH1F *hist_EFCD2= (TH1F*)dir_EFCD12->Get((hist_name_EFCD.at(i)).c_str());

if(i<4){
Endcap_FiducialCutEff[i] = new TCanvas(Form("FiducialCutEffD%d", i-4));
}
else{
Endcap_FiducialCutEff[i] = new TCanvas(Form("FiducialCutEffD%d", i-3));
}

//Endcap_FiducialCutEff[i] = new TCanvas(Form("FiducialCutEffD%d", i-2));

TPad *EFCD_pad1 = new TPad("EFCD_pad1", "", 0, 0.3, 1, 1.0);
   EFCD_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EFCD_pad1->Draw();             // Draw the upper pad: pad1
   EFCD_pad1->cd();               // pad1 becomes the current pad




hist_EFCD2->Draw();
hist_EFCD1->SetLineColor(kRed);
hist_EFCD1->Draw("sames");

float maxEFCD1=hist_EFCD1->GetMaximum();
float maxEFCD2=hist_EFCD2->GetMaximum();
if(maxEFCD1 > maxEFCD2){
hist_EFCD2->SetMaximum(maxEFCD1*1.5);
}
else
{
hist_EFCD2->SetMaximum(maxEFCD2*1.5);
}


gPad->Update();
TPaveStats *st_EFCD1 = (TPaveStats*)hist_EFCD1->FindObject("stats");
st_EFCD1->SetX1NDC(0.25);
st_EFCD1->SetX2NDC(0.45);
st_EFCD1->SetY1NDC(0.50); //new x start position
st_EFCD1->SetY2NDC(0.65);
st_EFCD1->SetTextColor(kRed);

TPaveStats *st_EFCD2 = (TPaveStats*)hist_EFCD2->FindObject("stats");
st_EFCD2->SetX1NDC(0.25);
st_EFCD2->SetX2NDC(0.45);
st_EFCD2->SetY1NDC(0.70); //new x start position
st_EFCD2->SetY2NDC(0.85);

TLegend *l_EFCD = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EFCD->SetBorderSize(0);

        l_EFCD->AddEntry(hist_EFCD1, legendEntry1.c_str(),"l");
        l_EFCD->AddEntry(hist_EFCD2, legendEntry2.c_str(),"l");

       l_EFCD->Draw();


       Endcap_FiducialCutEff[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *EFCD_pad2 = new TPad("EFCD_pad2", "", 0, 0.05, 1, 0.3);
   EFCD_pad2->SetTopMargin(0);
   EFCD_pad2->SetBottomMargin(0.2);
   EFCD_pad2->SetTitle("");
   EFCD_pad2->SetGridy();
   EFCD_pad2->SetGridx();
   EFCD_pad2->Draw();
   EFCD_pad2->cd();       // pad2 becomes the current pad


   TH1F *EFCD_h3 = (TH1F*)hist_EFCD2->Clone("EFCD_h3");
   EFCD_h3->SetTitle("");
   EFCD_h3->SetLineColor(kBlack);
   EFCD_h3->SetStats(0);      // No statistics on lower plot
   EFCD_h3->Divide(hist_EFCD1);
   EFCD_h3->SetMarkerStyle(21);
   EFCD_h3->GetXaxis()->SetLabelSize(0.1);
   EFCD_h3->GetYaxis()->SetRangeUser(-1,6);
   EFCD_h3->GetYaxis()->SetNdivisions(508);
   EFCD_h3->GetYaxis()->SetTitle("Ratio");
   EFCD_h3->GetYaxis()->SetTitleOffset(0.2);
   EFCD_h3->GetYaxis()->SetTitleSize(0.15);
   EFCD_h3->GetYaxis()->SetLabelSize(0.1);
   EFCD_h3->Draw("ep");       // Draw the ratio plot




TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Endcap");
out->mkdir("Endcap/Fudicial_cut_efficiencies/");
out->cd("Endcap/Fudicial_cut_efficiencies/");
Endcap_FiducialCutEff[i]->Write();
out->Close();


std::string outNameEFCD = "Endcap" + std::string(hist_name_EFCD.at(i)) + ".png";       //save histogram as a image
Endcap_FiducialCutEff[i]->SaveAs(outNameEFCD.c_str());



}



//------------------------------------------------------------------------------------------------
//RPC_occupancy_from_DT
//--------------------------------------------------------------------------------------------------





TDirectory* dir_EROD1 = (TDirectory*)f1->Get("Endcap/RPC_occupancy_from_DT");
TDirectory* dir_EROD12 = (TDirectory*)f2->Get("Endcap/RPC_occupancy_from_DT");

std::vector<std::string>hist_name_EROD;

hist_name_EROD.push_back("RPCOccD-4");
hist_name_EROD.push_back("RPCOccD-3");
hist_name_EROD.push_back("RPCOccD-2");
hist_name_EROD.push_back("RPCOccD-1");
hist_name_EROD.push_back("RPCOccD1");
hist_name_EROD.push_back("RPCOccD2");
hist_name_EROD.push_back("RPCOccD3");
hist_name_EROD.push_back("RPCOccD4");



//const Int_t nhist=10;
TCanvas *Endcap_RPCOcc[10];
for(unsigned int i=0;i<hist_name_EROD.size();i++){

TH1F *hist_EROD1= (TH1F*)dir_EROD1->Get((hist_name_EROD.at(i)).c_str());
TH1F *hist_EROD2= (TH1F*)dir_EROD12->Get((hist_name_EROD.at(i)).c_str());

//Endcap_RPCOcc[i] = new TCanvas(Form("RPCOccD%d", i-2));
if(i<4){
Endcap_RPCOcc[i] = new TCanvas(Form("RPCOccD%d", i-4));

}
else{
Endcap_RPCOcc[i] = new TCanvas(Form("RPCOccD%d", i-3));
        
}


TPad *EROD_pad1 = new TPad("EROD_pad1", "", 0, 0.3, 1, 1.0);
   EROD_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   EROD_pad1->Draw();             // Draw the upper pad: pad1
   EROD_pad1->cd();               // pad1 becomes the current pad




hist_EROD2->Draw();
hist_EROD1->SetLineColor(kRed);
hist_EROD1->Draw("sames");

float maxEROD1=hist_EROD1->GetMaximum();
float maxEROD2=hist_EROD2->GetMaximum();
if(maxEROD1 > maxEROD2){
hist_EROD2->SetMaximum(maxEROD1*1.5);
}
else
{
hist_EROD2->SetMaximum(maxEROD2*1.5);
}



gPad->Update();
TPaveStats *st_EROD1 = (TPaveStats*)hist_EROD1->FindObject("stats");
st_EROD1->SetY1NDC(0.60); //new x start position
st_EROD1->SetY2NDC(0.75);
st_EROD1->SetTextColor(kRed);

TLegend *l_EROD = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_EROD->SetBorderSize(0);

        l_EROD->AddEntry(hist_EROD1, legendEntry1.c_str(),"l");
        l_EROD->AddEntry(hist_EROD2, legendEntry2.c_str(),"l");

       l_EROD->Draw();


       Endcap_RPCOcc[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *EROD_pad2 = new TPad("EROD_pad2", "", 0, 0.05, 1, 0.3);
   EROD_pad2->SetTopMargin(0);
   EROD_pad2->SetBottomMargin(0.2);
   EROD_pad2->SetTitle("");
   EROD_pad2->SetGridy();
   EROD_pad2->SetGridx();
   EROD_pad2->Draw();
   EROD_pad2->cd();       // pad2 becomes the current pad


   TH1F *EROD_h3 = (TH1F*)hist_EROD2->Clone("EROD_h3");
   EROD_h3->SetTitle("");
   EROD_h3->SetLineColor(kBlack);
   EROD_h3->SetStats(0);      // No statistics on lower plot
   EROD_h3->Divide(hist_EROD1);
   EROD_h3->SetMarkerStyle(21);
   EROD_h3->GetXaxis()->SetLabelSize(0.1);
   EROD_h3->GetYaxis()->SetRangeUser(-1,6);
   EROD_h3->GetYaxis()->SetNdivisions(508);
   EROD_h3->GetYaxis()->SetTitle("Ratio");
   EROD_h3->GetYaxis()->SetTitleOffset(0.2);
   EROD_h3->GetYaxis()->SetTitleSize(0.15);
   EROD_h3->GetYaxis()->SetLabelSize(0.1);
   EROD_h3->Draw("ep");       // Draw the ratio plot




TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Endcap");
out->mkdir("Endcap/RPC_occupancy_from_DT/");
out->cd("Endcap/RPC_occupancy_from_DT/");
Endcap_RPCOcc[i]->Write();
out->Close();

std::string outNameEROD = "Endcap" + std::string(hist_name_EROD.at(i)) + ".png";       //save histogram as a image
Endcap_RPCOcc[i]->SaveAs(outNameEROD.c_str());



}


//------------------------------------------------------------------------------------------------
//RPC_occupancy
//--------------------------------------------------------------------------------------------------





TDirectory* dir_ERO1 = (TDirectory*)f1->Get("Endcap/RPC_occupancy");
TDirectory* dir_ERO12 = (TDirectory*)f2->Get("Endcap/RPC_occupancy");

std::vector<std::string>hist_name_ERO;

hist_name_ERO.push_back("RPCRealOccD-4");
hist_name_ERO.push_back("RPCRealOccD-3");
hist_name_ERO.push_back("RPCRealOccD-2");
hist_name_ERO.push_back("RPCRealOccD-1");
hist_name_ERO.push_back("RPCRealOccD1");
hist_name_ERO.push_back("RPCRealOccD2");
hist_name_ERO.push_back("RPCRealOccD3");
hist_name_ERO.push_back("RPCRealOccD4");

//const Int_t nhist=10;
TCanvas *Endcap_RPCRealOcc[10];
for(unsigned int i=0;i<hist_name_ERO.size();i++){

TH1F *hist_ERO1= (TH1F*)dir_ERO1->Get((hist_name_ERO.at(i)).c_str());
TH1F *hist_ERO2= (TH1F*)dir_ERO12->Get((hist_name_ERO.at(i)).c_str());

//Endcap_RPCRealOcc[i] = new TCanvas(Form("RPCRealOccD%d", i-4));


if(i<4){
Endcap_RPCRealOcc[i] = new TCanvas(Form("RPCRealOccD%d", i-4));
}
else{
Endcap_RPCRealOcc[i] = new TCanvas(Form("RPCRealOccD%d",i-3));
}



 TPad *ERO_pad1 = new TPad("ERO_pad1", "", 0, 0.3, 1, 1.0);
   ERO_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   ERO_pad1->Draw();             // Draw the upper pad: pad1
   ERO_pad1->cd();               // pad1 becomes the current pad



hist_ERO2->Draw();
hist_ERO1->SetLineColor(kRed);
hist_ERO1->Draw("sames");

float maxERO1=hist_ERO1->GetMaximum();
float maxERO2=hist_ERO2->GetMaximum();
if(maxERO1 > maxERO2){
hist_ERO2->SetMaximum(maxERO1*1.5);
}
else
{
hist_ERO2->SetMaximum(maxERO2*1.5);
}



gPad->Update();
TPaveStats *st_ERO1 = (TPaveStats*)hist_ERO1->FindObject("stats");
st_ERO1->SetY1NDC(0.60); //new x start position
st_ERO1->SetY2NDC(0.75);
st_ERO1->SetTextColor(kRed);

TLegend *l_ERO = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_ERO->SetBorderSize(0);

        l_ERO->AddEntry(hist_ERO1, legendEntry1.c_str(),"l");
        l_ERO->AddEntry(hist_ERO2, legendEntry2.c_str(),"l");

       l_ERO->Draw();

Endcap_RPCRealOcc[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *ERO_pad2 = new TPad("EROD_pad2", "", 0, 0.05, 1, 0.3);
   ERO_pad2->SetTopMargin(0);
   ERO_pad2->SetBottomMargin(0.2);
   ERO_pad2->SetTitle("");
   ERO_pad2->SetGridy();
   ERO_pad2->SetGridx();
   ERO_pad2->Draw();
   ERO_pad2->cd();       // pad2 becomes the current pad


   TH1F *ERO_h3 = (TH1F*)hist_ERO2->Clone("ERO_h3");
   ERO_h3->SetTitle("");
   ERO_h3->SetLineColor(kBlack);
   ERO_h3->SetStats(0);      // No statistics on lower plot
   ERO_h3->Divide(hist_ERO1);
   ERO_h3->SetMarkerStyle(21);
   ERO_h3->GetXaxis()->SetLabelSize(0.1);
   ERO_h3->GetYaxis()->SetRangeUser(-2,5);
   ERO_h3->GetYaxis()->SetNdivisions(508);
   ERO_h3->GetYaxis()->SetTitle("Ratio");
   ERO_h3->GetYaxis()->SetTitleOffset(0.2);
   ERO_h3->GetYaxis()->SetTitleSize(0.15);
   ERO_h3->GetYaxis()->SetLabelSize(0.1);
   ERO_h3->Draw("ep");       // Draw the ratio plot


TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Endcap");
out->mkdir("Endcap/RPC_occupancy/");
out->cd("Endcap/RPC_occupancy/");
Endcap_RPCRealOcc[i]->Write();
out->Close();


std::string outNameERO = "Endcap" + std::string(hist_name_ERO.at(i)) + ".png";       //save histogram as a image
Endcap_RPCRealOcc[i]->SaveAs(outNameERO.c_str());



}


//------------------------------------------------------------------------------------------------
//Total_efficiencies
//--------------------------------------------------------------------------------------------------





TDirectory* dir_ETE1 = (TDirectory*)f1->Get("Endcap/Total_efficiencies");
TDirectory* dir_ETE12 = (TDirectory*)f2->Get("Endcap/Total_efficiencies");

std::vector<std::string>hist_name_ETE;

hist_name_ETE.push_back("TotalEffD-4");
hist_name_ETE.push_back("TotalEffD-3");
hist_name_ETE.push_back("TotalEffD-2");
hist_name_ETE.push_back("TotalEffD-1");
hist_name_ETE.push_back("TotalEffD1");
hist_name_ETE.push_back("TotalEffD2");
hist_name_ETE.push_back("TotalEffD3");
hist_name_ETE.push_back("TotalEffD4");


//const Int_t nhist=10;
TCanvas *Endcap_TotalEff[10];
for(unsigned int i=0;i<hist_name_ETE.size();i++){

TH1F *hist_ETE1= (TH1F*)dir_ETE1->Get((hist_name_ETE.at(i)).c_str());
TH1F *hist_ETE2= (TH1F*)dir_ETE12->Get((hist_name_ETE.at(i)).c_str());

if(i<4){
Endcap_TotalEff[i] = new TCanvas(Form("TotalEffD%d", i-4));
}
else{
Endcap_TotalEff[i] = new TCanvas(Form("TotalEffD%d",i-3));
}



TPad *ETE_pad1 = new TPad("ETE_pad1", "", 0, 0.3, 1, 1.0);
   ETE_pad1->SetBottomMargin(1); // Upper and lower plot are joined
   ETE_pad1->Draw();             // Draw the upper pad: pad1
   ETE_pad1->cd();               // pad1 becomes the current pad


hist_ETE2->Draw();
hist_ETE1->SetLineColor(kRed);
hist_ETE1->Draw("sames");

float maxETE1=hist_ETE1->GetMaximum();
float maxETE2=hist_ETE2->GetMaximum();
if(maxETE1 > maxETE2){
hist_ETE2->SetMaximum(maxETE1*1.5);
}
else
{
hist_ETE2->SetMaximum(maxETE2*1.5);
}



gPad->Update();
TPaveStats *st_ETE1 = (TPaveStats*)hist_ETE1->FindObject("stats");

st_ETE1->SetX1NDC(0.25);
st_ETE1->SetX2NDC(0.45);
st_ETE1->SetY1NDC(0.50); //new x start position
st_ETE1->SetY2NDC(0.65);
st_ETE1->SetTextColor(kRed);

TPaveStats *st_ETE2 = (TPaveStats*)hist_ETE2->FindObject("stats");
st_ETE2->SetX1NDC(0.25);
st_ETE2->SetX2NDC(0.45);
st_ETE2->SetY1NDC(0.70); //new x start position
st_ETE2->SetY2NDC(0.85);


TLegend *l_ETE = new TLegend(0.5094002,0.7020649,0.7278424,0.8613569,NULL,"brNDC");
   l_ETE->SetBorderSize(0);

        l_ETE->AddEntry(hist_ETE1, legendEntry1.c_str(),"l");
        l_ETE->AddEntry(hist_ETE2, legendEntry2.c_str(),"l");

       l_ETE->Draw();


       Endcap_TotalEff[i]->cd();          // Go back to the main canvas before defining pad2
   TPad *ETE_pad2 = new TPad("ETE_pad2", "", 0, 0.05, 1, 0.3);
   ETE_pad2->SetTopMargin(0);
   ETE_pad2->SetBottomMargin(0.2);
   ETE_pad2->SetTitle("");
   ETE_pad2->SetGridy();
   ETE_pad2->SetGridx();
   ETE_pad2->Draw();
   ETE_pad2->cd();       // pad2 becomes the current pad


   TH1F *ETE_h3 = (TH1F*)hist_ETE2->Clone("ETE_h3");
   ETE_h3->SetTitle("");
   ETE_h3->SetLineColor(kBlack);
   ETE_h3->SetStats(0);      // No statistics on lower plot
   ETE_h3->Divide(hist_ETE1);
   ETE_h3->SetMarkerStyle(21);
   ETE_h3->GetXaxis()->SetLabelSize(0.1);
   ETE_h3->GetYaxis()->SetRangeUser(-1,11);
   ETE_h3->GetYaxis()->SetNdivisions(508);
   ETE_h3->GetYaxis()->SetTitle("Ratio");
   ETE_h3->GetYaxis()->SetTitleOffset(0.2);
   ETE_h3->GetYaxis()->SetTitleSize(0.15);
   ETE_h3->GetYaxis()->SetLabelSize(0.1);
   ETE_h3->Draw("ep");       // Draw the ratio plot




TFile *out = TFile::Open(outfilename.c_str(), "UPDATE");
//out->mkdir("Endcap");
out->mkdir("Endcap/Total_efficiencies/");
out->cd("Endcap/Total_efficiencies/");
Endcap_TotalEff[i]->Write();
out->Close();


std::string outNameETE = "Endcap" + std::string(hist_name_ETE.at(i)) + ".png";       //save histogram as a image
Endcap_TotalEff[i]->SaveAs(outNameETE.c_str());


}













}
