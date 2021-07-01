#include <iostream>
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TDirectory.h"
#include "TFile.h"
void draw2DplotsMWGR_barrelWheel(std::string infilename, int TotalLumiSections, std::string outfilename)
{

//Define Canvas	
/*TCanvas *c1 = new TCanvas("c1", "c1", 61,24,800,800);
c1->Range(2.40754,-1.002296,9.425494,6.993801);
*/

//Open the root file
//TFile *f1 = TFile::Open("SummaryAnalyzeEfficiency_Express2021_339579.root");
TFile *f1 = TFile::Open(infilename.c_str());

//Open Barrel directory
TDirectory* dir_barrel = (TDirectory*)f1->Get("Barrel");

//------------------------------------------------------------------------
//Define input 2D hist
//------------------------------------------------------------------------

TH2F *ACSWm1, *ACSWm2, *ACSW0, *ACSW1, *ACSW2;       //average cluster size
TH2F *FCEWm1, *FCEWm2, *FCEW0, *FCEW1, *FCEW2;             //Fudicial cut efficiencies
TH2F *ROWm1, *ROWm2, *ROW0, *ROW1, *ROW2;             //RPC occupancy



//------------------------------------------------------------------------
//extract the hist
//------------------------------------------------------------------------
//average cluster size
dir_barrel->GetObject("AverageCLSW-1",ACSWm1);
dir_barrel->GetObject("AverageCLSW-2",ACSWm2);
dir_barrel->GetObject("AverageCLSW0",ACSW0);
dir_barrel->GetObject("AverageCLSW1",ACSW1);
dir_barrel->GetObject("AverageCLSW2",ACSW2);


//Fudicial cut efficiencies
dir_barrel->GetObject("FiducialCutEffW-1",FCEWm1);
dir_barrel->GetObject("FiducialCutEffW-2",FCEWm2);
dir_barrel->GetObject("FiducialCutEffW0",FCEW0);
dir_barrel->GetObject("FiducialCutEffW1",FCEW1);
dir_barrel->GetObject("FiducialCutEffW2",FCEW2);


//RPC occupancy
dir_barrel->GetObject("RPCRealOccW-1",ROWm1);
dir_barrel->GetObject("RPCRealOccW-2",ROWm2);
dir_barrel->GetObject("RPCRealOccW0",ROW0);
dir_barrel->GetObject("RPCRealOccW1",ROW1);
dir_barrel->GetObject("RPCRealOccW2",ROW2);


//------------------------------------------------------------------------


//------------------------------------------------------------------------
//define output hist
//------------------------------------------------------------------------




//average cluster size

TH2D *out_ACSWm1 = new TH2D("ACS_VS_FCE_W-1", "Cluster Size VS Fiducial Cut Efficiency - Wheel -1", 101,-0.5,100.5, 16,0.0,4.0);
TH2D *out_ACSWm2 = new TH2D("ACS_VS_FCE_W-2", "Cluster Size VS Fiducial Cut Efficiency - Wheel -2", 101,-0.5,100.5, 16,0.0,4.0);
TH2D *out_ACSW0 = new TH2D("ACS_VS_FCE_W0", "Cluster Size VS Fiducial Cut Efficiency - Wheel 0", 101,-0.5,100.5, 16,0.0,4.0);
TH2D *out_ACSW1 = new TH2D("ACS_VS_FCE_W1", "Cluster Size VS Fiducial Cut Efficiency - Wheel 1", 101,-0.5,100.5, 16,0.0,4.0);
TH2D *out_ACSW2 = new TH2D("ACS_VS_FCE_W2", "Cluster Size VS Fiducial Cut Efficiency - Wheel 2", 101,-0.5,100.5, 16,0.0,4.0);


//RPC occupancy
TH2F *out_ROWm1 = new TH2F("RPCOcc_VS_FCE_W-1","RPC Occupancy VS Fiducial Cut Efficiency - Wheel -1",101,-0.5,100.5, 50,0.0,500.0);
TH2F *out_ROWm2 = new TH2F("RPC_VS_FCE_W-2","RPC Occupancy VS Fiducial Cut Efficiency - Wheel -2",101,-0.5,100.5,50,0.0,500.0);
TH2F *out_ROW0 = new TH2F("RPCOcc_VS_FCE_W0","RPC Occupancy VS Fiducial Cut Efficiency - Wheel 0",101,-0.5,100.5,50,0.0,500.0);
TH2F *out_ROW1 = new TH2F("RPCOcc_VS_FCE_W1","RPC Occupancy VS Fiducial Cut Efficiency - Wheel 1",101,-0.5,100.5,50,0.0,500.0);
TH2F *out_ROW2 = new TH2F("RPCOcc_VS_FCE_W2","RPC Occupancy VS Fiducial Cut Efficiency - Wheel 2",101,-0.5,100.5,50,0.0,500.0);


//RPC occupancy vs ACS
TH2F *out_ROACSWm1 = new TH2F("RPCOcc_VS_ACS_W-1","RPC Occupancy VS Cluster Size - Wheel -1",50,0.0,500.0,16,0.0,4.0);
TH2F *out_ROACSWm2 = new TH2F("RPCOcc_VS_ACS_W-2","RPC Occupancy VS Cluster Size - Wheel -2",50,0.0,500.0,16,0.0,4.0);
TH2F *out_ROACSW0 = new TH2F("RPCOcc_VS_ACS_W0","RPC Occupancy VS Cluster Size - Wheel 0",50,0.0,500.0,16,0.0,4.0);
TH2F *out_ROACSW1 = new TH2F("RPCOcc_VS_ACS_W1","RPC Occupancy VS Cluster Size - Wheel 1",50,0.0,500.0,16,0.0,4.0);
TH2F *out_ROACSW2 = new TH2F("RPCOcc_VS_ACS_W2","RPC Occupancy VS Cluster Size - Wheel 2",50,0.0,500.0,16,0.0,4.0);



//------------------------------------------------------------------------
//Define array to be filled in output
//------------------------------------------------------------------------

float arr_ACSWm1[500], arr_ACSWm2[500], arr_ACSW0[500], arr_ACSW1[500], arr_ACSW2[500];       //average cluster size
float arr_FCEWm1[500], arr_FCEWm2[500], arr_FCEW0[500], arr_FCEW1[500], arr_FCEW2[500];             //Fudicial cut efficiencies
float arr_ROWm1[500], arr_ROWm2[500], arr_ROW0[500], arr_ROW1[500], arr_ROW2[500];             //RPC occupancy
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

//average cluster size
arr_ACSWm1[i] = ACSWm1->GetBinContent(i,k);
arr_ACSWm2[i] = ACSWm2->GetBinContent(i,k);
arr_ACSW0[i] = ACSW0->GetBinContent(i,k);
arr_ACSW1[i] = ACSW1->GetBinContent(i,k);
arr_ACSW2[i] = ACSW2->GetBinContent(i,k);


//Fudicial cut efficiencies
arr_FCEWm1[i] = FCEWm1->GetBinContent(i,k);
arr_FCEWm2[i] = FCEWm2->GetBinContent(i,k);
arr_FCEW0[i] = FCEW0->GetBinContent(i,k);
arr_FCEW1[i] = FCEW1->GetBinContent(i,k);
arr_FCEW2[i] = FCEW2->GetBinContent(i,k);


//RPC occupancy
arr_ROWm1[i] = (ROWm1->GetBinContent(i,k))/TotalLumiSections;

//cout<<"arr_ROWm1: "<<arr_ROWm1[i]<<endl;

arr_ROWm2[i] = (ROWm2->GetBinContent(i,k))/TotalLumiSections;
arr_ROW0[i] = (ROW0->GetBinContent(i,k))/TotalLumiSections;
arr_ROW1[i] = (ROW1->GetBinContent(i,k))/TotalLumiSections;
arr_ROW2[i] = (ROW2->GetBinContent(i,k))/TotalLumiSections;


//------------------------------------------------------------------------
//Fill output hist
//------------------------------------------------------------------------


//average cluster size vs FCE
 out_ACSWm1->Fill(arr_FCEWm1[i],arr_ACSWm1[i]);
 out_ACSWm2->Fill(arr_FCEWm2[i],arr_ACSWm2[i]);
 out_ACSW0->Fill(arr_FCEW0[i],arr_ACSW0[i]);
 out_ACSW1->Fill(arr_FCEW1[i],arr_ACSW1[i]);
 out_ACSW2->Fill(arr_FCEW2[i],arr_ACSW2[i]);


//RPC occupancy vs FCE
 out_ROWm1->Fill(arr_FCEWm1[i],arr_ROWm1[i]);
 out_ROWm2->Fill(arr_FCEWm2[i],arr_ROWm2[i]);
 out_ROW0->Fill(arr_FCEW0[i],arr_ROW0[i]);
 out_ROW1->Fill(arr_FCEW1[i],arr_ROW1[i]);
 out_ROW2->Fill(arr_FCEW2[i],arr_ROW2[i]);

 //average cluster size vs RO
 out_ROACSWm1->Fill(arr_ROWm1[i],arr_ACSWm1[i]);
 out_ROACSWm2->Fill(arr_ROWm2[i],arr_ACSWm2[i]);
 out_ROACSW0->Fill(arr_ROW0[i],arr_ACSW0[i]);
 out_ROACSW1->Fill(arr_ROW1[i],arr_ACSW1[i]);
 out_ROACSW2->Fill(arr_ROW2[i],arr_ACSW2[i]);


	}
}

float corr_ACSWm1=out_ACSWm1->GetCorrelationFactor();
float corr_ACSWm2=out_ACSWm2->GetCorrelationFactor();
float corr_ACSW0=out_ACSW0->GetCorrelationFactor();
float corr_ACSW1=out_ACSW1->GetCorrelationFactor();
float corr_ACSW2=out_ACSW2->GetCorrelationFactor();


float corr_ROWm1=out_ROWm1->GetCorrelationFactor();
float corr_ROWm2=out_ROWm2->GetCorrelationFactor();
float corr_ROW0=out_ROW0->GetCorrelationFactor();
float corr_ROW1=out_ROW1->GetCorrelationFactor();
float corr_ROW2=out_ROW2->GetCorrelationFactor();

float corr_ROACSWm1=out_ROACSWm1->GetCorrelationFactor();
float corr_ROACSWm2=out_ROACSWm2->GetCorrelationFactor();
float corr_ROACSW0=out_ROACSW0->GetCorrelationFactor();
float corr_ROACSW1=out_ROACSW1->GetCorrelationFactor();
float corr_ROACSW2=out_ROACSW2->GetCorrelationFactor();


//Draw Canvas

//Average Cluster Size VS Fiducial Cut Eff

TCanvas *AverageCLSWm1 = new TCanvas(Form("ACS_VS_FCE_W-1"));
AverageCLSWm1->cd();
out_ACSWm1->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSWm1->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSWm1->Draw("colz text");
gPad->Update();
TLatex l_ACSWm1;
l_ACSWm1.SetTextSize(0.04);
l_ACSWm1.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSWm1));

TCanvas *AverageCLSWm2 = new TCanvas(Form("ACS_VS_FCE_W-2"));
AverageCLSWm2->cd();
out_ACSWm2->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSWm2->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSWm2->Draw("colz text");
gPad->Update();
TLatex l_ACSWm2;
l_ACSWm2.SetTextSize(0.04);
l_ACSWm2.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSWm2));


TCanvas *AverageCLSW0 = new TCanvas(Form("ACS_VS_FCE_W0"));
AverageCLSW0->cd();
out_ACSW0->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSW0->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSW0->Draw("colz text");
gPad->Update();
TLatex l_ACSW0;
l_ACSW0.SetTextSize(0.04);
l_ACSW0.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSW0));


TCanvas *AverageCLSW1 = new TCanvas(Form("ACS_VS_FCE_W1"));
AverageCLSW1->cd();
out_ACSW1->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSW1->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSW1->Draw("colz text");
gPad->Update();
TLatex l_ACSW1;
l_ACSW1.SetTextSize(0.04);
l_ACSW1.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSW1));


TCanvas *AverageCLSW2 = new TCanvas(Form("ACS_VS_FCE_W2"));
AverageCLSW2->cd();
out_ACSW2->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSW2->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSW2->Draw("colz text");
gPad->Update();
TLatex l_ACSW2;
l_ACSW2.SetTextSize(0.04);
l_ACSW2.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSW2));





//RPC Occupancy VS Fiducial Cut Eff

TCanvas *RPCOccWm1 = new TCanvas(Form("RO_VS_FCE_W-1"));
RPCOccWm1->cd();
out_ROWm1->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ROWm1->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROWm1->GetYaxis()->SetTitleSize(0.03);
out_ROWm1->Draw("colz text");
gPad->Update();
TLatex l_ROWm1;
l_ROWm1.SetTextSize(0.04);
l_ROWm1.DrawLatex(1,400,Form("Correlation Factor = %f", corr_ROWm1));

TCanvas *RPCOccWm2 = new TCanvas(Form("RO_VS_FCE_W-2"));
RPCOccWm2->cd();
out_ROWm2->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ROWm2->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROWm2->GetYaxis()->SetTitleSize(0.03);
out_ROWm2->Draw("colz text");
gPad->Update();
TLatex l_ROWm2;
l_ROWm2.SetTextSize(0.04);
l_ROWm2.DrawLatex(1,400,Form("Correlation Factor = %f", corr_ROWm2));

TCanvas *RPCOccW0 = new TCanvas(Form("RO_VS_FCE_W0"));
RPCOccW0->cd();
out_ROW0->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ROW0->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROW0->GetYaxis()->SetTitleSize(0.03);
out_ROW0->Draw("colz text");
gPad->Update();
TLatex l_ROW0;
l_ROW0.SetTextSize(0.04);
l_ROW0.DrawLatex(1,400,Form("Correlation Factor = %f", corr_ROW0));


TCanvas *RPCOccW1 = new TCanvas(Form("RO_VS_FCE_W1"));
RPCOccW1->cd();
out_ROW1->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ROW1->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROW1->GetYaxis()->SetTitleSize(0.03);
out_ROW1->Draw("colz text");
gPad->Update();
TLatex l_ROW1;
l_ROW1.SetTextSize(0.04);
l_ROW1.DrawLatex(1,400,Form("Correlation Factor = %f", corr_ROW1));


TCanvas *RPCOccW2 = new TCanvas(Form("RO_VS_FCE_W2"));
RPCOccW2->cd();
out_ROW2->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ROW2->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROW2->GetYaxis()->SetTitleSize(0.03);
out_ROW2->Draw("colz text");
gPad->Update();
TLatex l_ROW2;
l_ROW2.SetTextSize(0.04);
l_ROW2.DrawLatex(1,400,Form("Correlation Factor = %f", corr_ROW2));






//RPC Occupancy VS Average Cluster Size


TCanvas *ACS_RPCOccWm1 = new TCanvas(Form("RO_VS_ACS_W-1"));
ACS_RPCOccWm1->cd();
out_ROACSWm1->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSWm1->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSWm1->GetXaxis()->SetTitleOffset(1.2);
out_ROACSWm1->GetXaxis()->SetTitleSize(0.03);
out_ROACSWm1->Draw("colz text");
gPad->Update();
TLatex l_ROACSWm1;
l_ROACSWm1.SetTextSize(0.04);
l_ROACSWm1.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSWm1));


TCanvas *ACS_RPCOccWm2 = new TCanvas(Form("RO_VS_ACS_W-2"));
ACS_RPCOccWm2->cd();
out_ROACSWm2->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSWm2->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSWm2->GetXaxis()->SetTitleOffset(1.2);
out_ROACSWm2->GetXaxis()->SetTitleSize(0.03);
out_ROACSWm2->Draw("colz text");
gPad->Update();
TLatex l_ROACSWm2;
l_ROACSWm2.SetTextSize(0.04);
l_ROACSWm2.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSWm2));


TCanvas *ACS_RPCOccW0 = new TCanvas(Form("RO_VS_ACS_W0"));
ACS_RPCOccW0->cd();
out_ROACSW0->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSW0->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSW0->GetXaxis()->SetTitleOffset(1.2);
out_ROACSW0->GetXaxis()->SetTitleSize(0.03);
out_ROACSW0->Draw("colz text");
gPad->Update();
TLatex l_ROACSW0;
l_ROACSW0.SetTextSize(0.04);
l_ROACSW0.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSW0));



TCanvas *ACS_RPCOccW1 = new TCanvas(Form("RO_VS_ACS_W1"));
ACS_RPCOccW1->cd();
out_ROACSW1->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSW1->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSW1->GetXaxis()->SetTitleOffset(1.2);
out_ROACSW1->GetXaxis()->SetTitleSize(0.03);
out_ROACSW1->Draw("colz text");
gPad->Update();
TLatex l_ROACSW1;
l_ROACSW1.SetTextSize(0.04);
l_ROACSW1.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSW1));



TCanvas *ACS_RPCOccW2 = new TCanvas(Form("RO_VS_ACS_W2"));
ACS_RPCOccW2->cd();
out_ROACSW2->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSW2->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSW2->GetXaxis()->SetTitleOffset(1.2);
out_ROACSW2->GetXaxis()->SetTitleSize(0.03);
out_ROACSW2->Draw("colz text");
gPad->Update();
TLatex l_ROACSW2;
l_ROACSW2.SetTextSize(0.04);
l_ROACSW2.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSW2));


//------------------------------------------------------------------------
//Write hist to directory
//------------------------------------------------------------------------

TFile *out = new TFile(outfilename.c_str(), "RECREATE");
        out->mkdir("Barrel");

out->cd("/Barrel");
        out->mkdir("Barrel/ACS_VS_FCE/");
out->cd("Barrel/ACS_VS_FCE/");

//average cluster size VS Fiducial Cut Eff
AverageCLSWm2->Write();
AverageCLSWm1->Write();
AverageCLSW0->Write();
AverageCLSW1->Write();
AverageCLSW2->Write();

AverageCLSWm2->SaveAs("ClusterSize_VS_FiducialEff_Wheel-2.png");
AverageCLSWm1->SaveAs("ClusterSize_VS_FiducialEff_Wheel-1.png");
AverageCLSW0->SaveAs("ClusterSize_VS_FiducialEff_Wheel0.png");
AverageCLSW1->SaveAs("ClusterSize_VS_FiducialEff_Wheel1.png");
AverageCLSW2->SaveAs("ClusterSize_VS_FiducialEff_Wheel2.png");


//RPC Occupancy VS Fiducial Cut Eff
out->mkdir("Barrel/RPCOcc_VS_FCE/");
out->cd("Barrel/RPCOcc_VS_FCE/");

RPCOccWm2->Write();
RPCOccWm1->Write();
RPCOccW0->Write();
RPCOccW1->Write();
RPCOccW2->Write();


RPCOccWm2->SaveAs("RPCOcc_VS_FiducialEff_Wheel-2.png");
RPCOccWm1->SaveAs("RPCOcc_VS_FiducialEff_Wheel-1.png");
RPCOccW0->SaveAs("RPCOcc_VS_FiducialEff_Wheel0.png");
RPCOccW1->SaveAs("RPCOcc_VS_FiducialEff_Wheel1.png");
RPCOccW2->SaveAs("RPCOcc_VS_FiducialEff_Wheel2.png");



//RPC Occupancy VS Average Cluster Size
out->mkdir("Barrel/RPCOcc_VS_ACS/");
out->cd("Barrel/RPCOcc_VS_ACS/");

ACS_RPCOccWm2->Write();
ACS_RPCOccWm1->Write();
ACS_RPCOccW0->Write();
ACS_RPCOccW1->Write();
ACS_RPCOccW2->Write();

ACS_RPCOccWm2->SaveAs("ClusterSize_VS_RPCOcc_Wheel-2.png");
ACS_RPCOccWm1->SaveAs("ClusterSize_VS_RPCOcc_Wheel-1.png");
ACS_RPCOccW0->SaveAs("ClusterSize_VS_RPCOcc_Wheel0.png");
ACS_RPCOccW1->SaveAs("ClusterSize_VS_RPCOcc_Wheel1.png");
ACS_RPCOccW2->SaveAs("ClusterSize_VS_RPCOcc_Wheel2.png");


}


