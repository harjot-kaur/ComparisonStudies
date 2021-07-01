#include <iostream>
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TDirectory.h"
#include "TFile.h"
void draw2DplotsMWGR_endcapDisk(std::string infilename, int TotalLumiSections, std::string outfilename)
{

//Define Canvas	
/*TCanvas *c1 = new TCanvas("c1", "c1", 61,24,800,800);
c1->Range(2.40754,-1.002296,9.425494,6.993801);
*/

//Open the root file
//TFile *f1 = TFile::Open("SummaryAnalyzeEfficiency_Express2021_339579.root");
TFile *f1 = TFile::Open(infilename.c_str());

//Open Endcap directory
TDirectory* dir_endcap = (TDirectory*)f1->Get("Endcap");

//------------------------------------------------------------------------
//Define input 2D hist
//------------------------------------------------------------------------

TH2F *ACSDm1, *ACSDm2, *ACSDm3, *ACSDm4, *ACSD4, *ACSD3, *ACSD1, *ACSD2;       //average cluster size
TH2F *FCEDm1, *FCEDm2, *FCEDm3, *FCEDm4, *FCED4, *FCED3, *FCED1, *FCED2;             //Fudicial cut efficiencies
TH2F *RODm1, *RODm2, *RODm3, *RODm4, *ROD4, *ROD3, *ROD1, *ROD2;             //RPC occupancy



//------------------------------------------------------------------------
//extract the hist
//------------------------------------------------------------------------
//average cluster size
dir_endcap->GetObject("AverageCLSD-1",ACSDm1);
dir_endcap->GetObject("AverageCLSD-2",ACSDm2);
dir_endcap->GetObject("AverageCLSD-3",ACSDm3);
dir_endcap->GetObject("AverageCLSD-4",ACSDm4);
dir_endcap->GetObject("AverageCLSD1",ACSD1);
dir_endcap->GetObject("AverageCLSD2",ACSD2);
dir_endcap->GetObject("AverageCLSD3",ACSD3);
dir_endcap->GetObject("AverageCLSD4",ACSD4);


//Fudicial cut efficiencies
dir_endcap->GetObject("FiducialCutEffD-1",FCEDm1);
dir_endcap->GetObject("FiducialCutEffD-2",FCEDm2);
dir_endcap->GetObject("FiducialCutEffD-3",FCEDm3);
dir_endcap->GetObject("FiducialCutEffD-4",FCEDm4);
dir_endcap->GetObject("FiducialCutEffD1",FCED1);
dir_endcap->GetObject("FiducialCutEffD2",FCED2);
dir_endcap->GetObject("FiducialCutEffD3",FCED3);
dir_endcap->GetObject("FiducialCutEffD4",FCED4);


//RPC occupancy
dir_endcap->GetObject("RPCRealOccD-1",RODm1);
dir_endcap->GetObject("RPCRealOccD-2",RODm2);
dir_endcap->GetObject("RPCRealOccD-3",RODm3);
dir_endcap->GetObject("RPCRealOccD-4",RODm4);
dir_endcap->GetObject("RPCRealOccD1",ROD1);
dir_endcap->GetObject("RPCRealOccD2",ROD2);
dir_endcap->GetObject("RPCRealOccD3",ROD3);
dir_endcap->GetObject("RPCRealOccD4",ROD4);


//------------------------------------------------------------------------


//------------------------------------------------------------------------
//define output hist
//------------------------------------------------------------------------




//average cluster size

TH2D *out_ACSDm4 = new TH2D("ACS_VS_FCE_D-4", "Cluster Size VS Fiducial Cut Efficiency - Disk -4", 101,-0.5,100.5, 16,0.0,4.0);
TH2D *out_ACSDm3 = new TH2D("ACS_VS_FCE_D-3", "Cluster Size VS Fiducial Cut Efficiency - Disk -3", 101,-0.5,100.5, 16,0.0,4.0);
TH2D *out_ACSDm2 = new TH2D("ACS_VS_FCE_D-2", "Cluster Size VS Fiducial Cut Efficiency - Disk -2", 101,-0.5,100.5, 16,0.0,4.0);
TH2D *out_ACSDm1 = new TH2D("ACS_VS_FCE_D-1", "Cluster Size VS Fiducial Cut Efficiency - Disk -1", 101,-0.5,100.5, 16,0.0,4.0);
TH2D *out_ACSD1 = new TH2D("ACS_VS_FCE_D1", "Cluster Size VS Fiducial Cut Efficiency - Disk 1", 101,-0.5,100.5, 16,0.0,4.0);
TH2D *out_ACSD2 = new TH2D("ACS_VS_FCE_D2", "Cluster Size VS Fiducial Cut Efficiency - Disk 2", 101,-0.5,100.5, 16,0.0,4.0);
TH2D *out_ACSD3 = new TH2D("ACS_VS_FCE_D3", "Cluster Size VS Fiducial Cut Efficiency - Disk 3", 101,-0.5,100.5, 16,0.0,4.0);
TH2D *out_ACSD4 = new TH2D("ACS_VS_FCE_D4", "Cluster Size VS Fiducial Cut Efficiency - Disk 4", 101,-0.5,100.5, 16,0.0,4.0);


//RPC occupancy
TH2F *out_RODm4 = new TH2F("RPCOcc_VS_FCE_D-4","RPC Occupancy VS Fiducial Cut Efficiency - Disk -4",101,-0.5,100.5, 50,0.0,500.0);
TH2F *out_RODm3 = new TH2F("RPCOcc_VS_FCE_D-3","RPC Occupancy VS Fiducial Cut Efficiency - Disk -3",101,-0.5,100.5, 50,0.0,500.0);
TH2F *out_RODm2 = new TH2F("RPCOcc_VS_FCE_D-2","RPC Occupancy VS Fiducial Cut Efficiency - Disk -2",101,-0.5,100.5, 50,0.0,500.0);
TH2F *out_RODm1 = new TH2F("RPCOcc_VS_FCE_D-1","RPC Occupancy VS Fiducial Cut Efficiency - Disk -1",101,-0.5,100.5, 50,0.0,500.0);
TH2F *out_ROD1 = new TH2F("RPCOcc_VS_FCE_D1","RPC Occupancy VS Fiducial Cut Efficiency - Disk 1",101,-0.5,100.5, 50,0.0,500.0);
TH2F *out_ROD2 = new TH2F("RPCOcc_VS_FCE_D2","RPC Occupancy VS Fiducial Cut Efficiency - Disk 2",101,-0.5,100.5, 50,0.0,500.0);
TH2F *out_ROD3 = new TH2F("RPCOcc_VS_FCE_D3","RPC Occupancy VS Fiducial Cut Efficiency - Disk 3",101,-0.5,100.5, 50,0.0,500.0);
TH2F *out_ROD4 = new TH2F("RPCOcc_VS_FCE_D4","RPC Occupancy VS Fiducial Cut Efficiency - Disk 4",101,-0.5,100.5, 50,0.0,500.0);


//RPC occupancy vs ACS
TH2F *out_ROACSDm4 = new TH2F("RPCOcc_VS_ACS_D-4","RPC Occupancy VS Cluster Size - Disk -4",50,0.0,500.0,16,0.0,4.0);
TH2F *out_ROACSDm3 = new TH2F("RPCOcc_VS_ACS_D-3","RPC Occupancy VS Cluster Size - Disk -3",50,0.0,500.0,16,0.0,4.0);
TH2F *out_ROACSDm2 = new TH2F("RPCOcc_VS_ACS_D-2","RPC Occupancy VS Cluster Size - Disk -2",50,0.0,500.0,16,0.0,4.0);
TH2F *out_ROACSDm1 = new TH2F("RPCOcc_VS_ACS_D-1","RPC Occupancy VS Cluster Size - Disk -1",50,0.0,500.0,16,0.0,4.0);
TH2F *out_ROACSD1 = new TH2F("RPCOcc_VS_ACS_D1","RPC Occupancy VS Cluster Size - Disk 1",50,0.0,500.0,16,0.0,4.0);
TH2F *out_ROACSD2 = new TH2F("RPCOcc_VS_ACS_D2","RPC Occupancy VS Cluster Size - Disk 2",50,0.0,500.0,16,0.0,4.0);
TH2F *out_ROACSD3 = new TH2F("RPCOcc_VS_ACS_D3","RPC Occupancy VS Cluster Size - Disk 3",50,0.0,500.0,16,0.0,4.0);
TH2F *out_ROACSD4 = new TH2F("RPCOcc_VS_ACS_D4","RPC Occupancy VS Cluster Size - Disk 4",50,0.0,500.0,16,0.0,4.0);



//------------------------------------------------------------------------
//Define array to be filled in output
//------------------------------------------------------------------------

float arr_ACSDm1[500], arr_ACSDm2[500], arr_ACSDm3[500], arr_ACSDm4[500], arr_ACSD4[500], arr_ACSD3[500], arr_ACSD1[500], arr_ACSD2[500];       //average cluster size
float arr_FCEDm1[500], arr_FCEDm2[500], arr_FCEDm3[500], arr_FCEDm4[500], arr_FCED4[500], arr_FCED3[500], arr_FCED1[500], arr_FCED2[500];             //Fudicial cut efficiencies
float arr_RODm1[500], arr_RODm2[500], arr_RODm3[500], arr_RODm4[500], arr_ROD4[500], arr_ROD3[500], arr_ROD1[500], arr_ROD2[500];             //RPC occupancy



//------------------------------------------------------------------------



for(int j = 1; j<=36; j++)
{
        for(int l = 1; l<=6; l++){

//average cluster size
arr_ACSDm1[j] = ACSDm1->GetBinContent(j,l);
arr_ACSDm2[j] = ACSDm2->GetBinContent(j,l);
arr_ACSDm3[j] = ACSDm3->GetBinContent(j,l);
arr_ACSDm4[j] = ACSDm4->GetBinContent(j,l);
arr_ACSD1[j] = ACSD1->GetBinContent(j,l);
arr_ACSD2[j] = ACSD2->GetBinContent(j,l);
arr_ACSD3[j] = ACSD3->GetBinContent(j,l);
arr_ACSD4[j] = ACSD4->GetBinContent(j,l);


//Fudicial cut efficiencies
arr_FCEDm1[j] = FCEDm1->GetBinContent(j,l);
arr_FCEDm2[j] = FCEDm2->GetBinContent(j,l);
arr_FCEDm3[j] = FCEDm3->GetBinContent(j,l);
arr_FCEDm4[j] = FCEDm4->GetBinContent(j,l);
arr_FCED1[j] = FCED1->GetBinContent(j,l);
arr_FCED2[j] = FCED2->GetBinContent(j,l);
arr_FCED3[j] = FCED3->GetBinContent(j,l);
arr_FCED4[j] = FCED4->GetBinContent(j,l);


//RPC occupancy
arr_RODm1[j] = (RODm1->GetBinContent(j,l))/TotalLumiSections;
arr_RODm2[j] = (RODm2->GetBinContent(j,l))/TotalLumiSections;
arr_RODm3[j] = (RODm3->GetBinContent(j,l))/TotalLumiSections;
arr_RODm4[j] = (RODm4->GetBinContent(j,l))/TotalLumiSections;
arr_ROD1[j] = (ROD1->GetBinContent(j,l))/TotalLumiSections;
arr_ROD2[j] = (ROD2->GetBinContent(j,l))/TotalLumiSections;
arr_ROD3[j] = (ROD3->GetBinContent(j,l))/TotalLumiSections;
arr_ROD4[j] = (ROD4->GetBinContent(j,l))/TotalLumiSections;


//------------------------------------------------------------------------
//Fill output hist
//------------------------------------------------------------------------


//average cluster size vs FCE

out_ACSDm4->Fill(arr_FCEDm4[j],arr_ACSDm4[j]);
out_ACSDm3->Fill(arr_FCEDm3[j],arr_ACSDm3[j]);
out_ACSDm2->Fill(arr_FCEDm2[j],arr_ACSDm2[j]);
out_ACSDm1->Fill(arr_FCEDm1[j],arr_ACSDm1[j]);
out_ACSD1->Fill(arr_FCED1[j],arr_ACSD1[j]);
out_ACSD2->Fill(arr_FCED2[j],arr_ACSD2[j]);
out_ACSD3->Fill(arr_FCED3[j],arr_ACSD3[j]);
out_ACSD4->Fill(arr_FCED4[j],arr_ACSD4[j]);


//RPC occupancy vs FCE
out_RODm4->Fill(arr_FCEDm4[j],arr_RODm4[j]);
out_RODm3->Fill(arr_FCEDm3[j],arr_RODm3[j]);
out_RODm2->Fill(arr_FCEDm2[j],arr_RODm2[j]);
out_RODm1->Fill(arr_FCEDm1[j],arr_RODm1[j]);
out_ROD1->Fill(arr_FCED1[j],arr_ROD1[j]);
out_ROD2->Fill(arr_FCED2[j],arr_ROD2[j]);
out_ROD3->Fill(arr_FCED3[j],arr_ROD3[j]);
out_ROD4->Fill(arr_FCED4[j],arr_ROD4[j]);

//average cluster size vs RO
out_ROACSDm4->Fill(arr_RODm4[j],arr_ACSDm4[j]);
out_ROACSDm3->Fill(arr_RODm3[j],arr_ACSDm3[j]);
out_ROACSDm2->Fill(arr_RODm2[j],arr_ACSDm2[j]);
out_ROACSDm1->Fill(arr_RODm1[j],arr_ACSDm1[j]);
out_ROACSD1->Fill(arr_ROD1[j],arr_ACSD1[j]);
out_ROACSD2->Fill(arr_ROD2[j],arr_ACSD2[j]);
out_ROACSD3->Fill(arr_ROD3[j],arr_ACSD3[j]);
out_ROACSD4->Fill(arr_ROD4[j],arr_ACSD4[j]);


	}
}

float corr_ACSDm4=out_ACSDm4->GetCorrelationFactor();
float corr_ACSDm3=out_ACSDm3->GetCorrelationFactor();
float corr_ACSDm2=out_ACSDm2->GetCorrelationFactor();
float corr_ACSDm1=out_ACSDm1->GetCorrelationFactor();
float corr_ACSD1=out_ACSD1->GetCorrelationFactor();
float corr_ACSD2=out_ACSD2->GetCorrelationFactor();
float corr_ACSD3=out_ACSD3->GetCorrelationFactor();
float corr_ACSD4=out_ACSD4->GetCorrelationFactor();


float corr_RODm4=out_RODm4->GetCorrelationFactor();
float corr_RODm3=out_RODm3->GetCorrelationFactor();
float corr_RODm2=out_RODm2->GetCorrelationFactor();
float corr_RODm1=out_RODm1->GetCorrelationFactor();
float corr_ROD1=out_ROD1->GetCorrelationFactor();
float corr_ROD2=out_ROD2->GetCorrelationFactor();
float corr_ROD3=out_ROD3->GetCorrelationFactor();
float corr_ROD4=out_ROD4->GetCorrelationFactor();

float corr_ROACSDm4=out_ROACSDm4->GetCorrelationFactor();
float corr_ROACSDm3=out_ROACSDm3->GetCorrelationFactor();
float corr_ROACSDm2=out_ROACSDm2->GetCorrelationFactor();
float corr_ROACSDm1=out_ROACSDm1->GetCorrelationFactor();
float corr_ROACSD1=out_ROACSD1->GetCorrelationFactor();
float corr_ROACSD2=out_ROACSD2->GetCorrelationFactor();
float corr_ROACSD3=out_ROACSD3->GetCorrelationFactor();
float corr_ROACSD4=out_ROACSD4->GetCorrelationFactor();


//Draw Canvas

//Average Cluster Size VS Fiducial Cut Eff

TCanvas *AverageCLSDm4 = new TCanvas(Form("ACS_VS_FCE_D-4"));
AverageCLSDm4->cd();
out_ACSDm4->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSDm4->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSDm4->Draw("colz text");
gPad->Update();
TLatex l_ACSDm4;
l_ACSDm4.SetTextSize(0.04);
l_ACSDm4.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSDm4));


TCanvas *AverageCLSDm3 = new TCanvas(Form("ACS_VS_FCE_D-3"));
AverageCLSDm3->cd();
out_ACSDm3->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSDm3->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSDm3->Draw("colz text");
gPad->Update();
TLatex l_ACSDm3;
l_ACSDm3.SetTextSize(0.04);
l_ACSDm3.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSDm3));


TCanvas *AverageCLSDm2 = new TCanvas(Form("ACS_VS_FCE_D-2"));
AverageCLSDm2->cd();
out_ACSDm2->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSDm2->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSDm2->Draw("colz text");
gPad->Update();
TLatex l_ACSDm2;
l_ACSDm2.SetTextSize(0.04);
l_ACSDm2.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSDm2));


TCanvas *AverageCLSDm1 = new TCanvas(Form("ACS_VS_FCE_D-1"));
AverageCLSDm1->cd();
out_ACSDm1->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSDm1->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSDm1->Draw("colz text");
gPad->Update();
TLatex l_ACSDm1;
l_ACSDm1.SetTextSize(0.04);
l_ACSDm1.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSDm1));


TCanvas *AverageCLSD1 = new TCanvas(Form("ACS_VS_FCE_D1"));
AverageCLSD1->cd();
out_ACSD1->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSD1->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSD1->Draw("colz text");
gPad->Update();
TLatex l_ACSD1;
l_ACSD1.SetTextSize(0.04);
l_ACSD1.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSD1));


TCanvas *AverageCLSD2 = new TCanvas(Form("ACS_VS_FCE_D2"));
AverageCLSD2->cd();
out_ACSD2->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSD2->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSD2->Draw("colz text");
gPad->Update();
TLatex l_ACSD2;
l_ACSD2.SetTextSize(0.04);
l_ACSD2.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSD2));


TCanvas *AverageCLSD3 = new TCanvas(Form("ACS_VS_FCE_D3"));
AverageCLSD3->cd();
out_ACSD3->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSD3->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSD3->Draw("colz text");
gPad->Update();
TLatex l_ACSD3;
l_ACSD3.SetTextSize(0.04);
l_ACSD3.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSD3));


TCanvas *AverageCLSD4 = new TCanvas(Form("ACS_VS_FCE_D4"));
AverageCLSD4->cd();
out_ACSD4->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ACSD4->GetYaxis()->SetTitle("Average Cluster Size");
out_ACSD4->Draw("colz text");
gPad->Update();
TLatex l_ACSD4;
l_ACSD4.SetTextSize(0.04);
l_ACSD4.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ACSD4));






//RPC Occupancy VS Fiducial Cut Eff

TCanvas *RPCOccDm4 = new TCanvas(Form("RO_VS_FCE_D-4"));
RPCOccDm4->cd();
out_RODm4->GetXaxis()->SetTitle("Fiducial Efficiency");
out_RODm4->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_RODm4->GetYaxis()->SetTitleSize(0.03);
out_RODm4->Draw("colz text");
gPad->Update();
TLatex l_RODm4;
l_RODm4.SetTextSize(0.04);
l_RODm4.DrawLatex(1,400,Form("Correlation Factor = %f", corr_RODm4));


TCanvas *RPCOccDm3 = new TCanvas(Form("RO_VS_FCE_D-3"));
RPCOccDm3->cd();
out_RODm3->GetXaxis()->SetTitle("Fiducial Efficiency");
out_RODm3->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_RODm3->GetYaxis()->SetTitleSize(0.03);
out_RODm3->Draw("colz text");
gPad->Update();
TLatex l_RODm3;
l_RODm3.SetTextSize(0.04);
l_RODm3.DrawLatex(1,400,Form("Correlation Factor = %f", corr_RODm3));


TCanvas *RPCOccDm2 = new TCanvas(Form("RO_VS_FCE_D-2"));
RPCOccDm2->cd();
out_RODm2->GetXaxis()->SetTitle("Fiducial Efficiency");
out_RODm2->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_RODm2->GetYaxis()->SetTitleSize(0.03);
out_RODm2->Draw("colz text");
gPad->Update();
TLatex l_RODm2;
l_RODm2.SetTextSize(0.04);
l_RODm2.DrawLatex(1,400,Form("Correlation Factor = %f", corr_RODm2));


TCanvas *RPCOccDm1 = new TCanvas(Form("RO_VS_FCE_D-1"));
RPCOccDm1->cd();
out_RODm1->GetXaxis()->SetTitle("Fiducial Efficiency");
out_RODm1->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_RODm1->GetYaxis()->SetTitleSize(0.03);
out_RODm1->Draw("colz text");
gPad->Update();
TLatex l_RODm1;
l_RODm1.SetTextSize(0.04);
l_RODm1.DrawLatex(1,400,Form("Correlation Factor = %f", corr_RODm1));


TCanvas *RPCOccD1 = new TCanvas(Form("RO_VS_FCE_D1"));
RPCOccD1->cd();
out_ROD1->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ROD1->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROD1->GetYaxis()->SetTitleSize(0.03);
out_ROD1->Draw("colz text");
gPad->Update();
TLatex l_ROD1;
l_ROD1.SetTextSize(0.04);
l_ROD1.DrawLatex(1,400,Form("Correlation Factor = %f", corr_ROD1));


TCanvas *RPCOccD2 = new TCanvas(Form("RO_VS_FCE_D2"));
RPCOccD2->cd();
out_ROD2->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ROD2->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROD2->GetYaxis()->SetTitleSize(0.03);
out_ROD2->Draw("colz text");
gPad->Update();
TLatex l_ROD2;
l_ROD2.SetTextSize(0.04);
l_ROD2.DrawLatex(1,400,Form("Correlation Factor = %f", corr_ROD2));


TCanvas *RPCOccD3 = new TCanvas(Form("RO_VS_FCE_D3"));
RPCOccD3->cd();
out_ROD3->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ROD3->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROD3->GetYaxis()->SetTitleSize(0.03);
out_ROD3->Draw("colz text");
gPad->Update();
TLatex l_ROD3;
l_ROD3.SetTextSize(0.04);
l_ROD3.DrawLatex(1,400,Form("Correlation Factor = %f", corr_ROD3));


TCanvas *RPCOccD4 = new TCanvas(Form("RO_VS_FCE_D4"));
RPCOccD4->cd();
out_ROD4->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ROD4->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROD4->GetYaxis()->SetTitleSize(0.03);
out_ROD4->Draw("colz text");
gPad->Update();
TLatex l_ROD4;
l_ROD4.SetTextSize(0.04);
l_ROD4.DrawLatex(1,400,Form("Correlation Factor = %f", corr_ROD4));








//RPC Occupancy VS Average Cluster Size


TCanvas *ACS_RPCOccDm4 = new TCanvas(Form("RO_VS_ACS_D-4"));
ACS_RPCOccDm4->cd();
out_ROACSDm4->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSDm4->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSDm4->GetXaxis()->SetTitleOffset(1.2);
out_ROACSDm4->GetXaxis()->SetTitleSize(0.03);
out_ROACSDm4->Draw("colz text");
gPad->Update();
TLatex l_ROACSDm4;
l_ROACSDm4.SetTextSize(0.04);
l_ROACSDm4.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSDm4));


TCanvas *ACS_RPCOccDm3 = new TCanvas(Form("RO_VS_ACS_D-3"));
ACS_RPCOccDm3->cd();
out_ROACSDm3->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSDm3->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSDm3->GetXaxis()->SetTitleOffset(1.2);
out_ROACSDm3->GetXaxis()->SetTitleSize(0.03);
out_ROACSDm3->Draw("colz text");
gPad->Update();
TLatex l_ROACSDm3;
l_ROACSDm3.SetTextSize(0.04);
l_ROACSDm3.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSDm3));


TCanvas *ACS_RPCOccDm2 = new TCanvas(Form("RO_VS_ACS_D-2"));
ACS_RPCOccDm2->cd();
out_ROACSD2->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSDm2->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSDm2->GetXaxis()->SetTitleOffset(1.2);
out_ROACSDm2->GetXaxis()->SetTitleSize(0.03);
out_ROACSDm2->Draw("colz text");
gPad->Update();
TLatex l_ROACSDm2;
l_ROACSDm2.SetTextSize(0.04);
l_ROACSDm2.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSDm2));


TCanvas *ACS_RPCOccDm1 = new TCanvas(Form("RO_VS_ACS_D-1"));
ACS_RPCOccDm1->cd();
out_ROACSDm1->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSDm1->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSDm1->GetXaxis()->SetTitleOffset(1.2);
out_ROACSDm1->GetXaxis()->SetTitleSize(0.03);
out_ROACSDm1->Draw("colz text");
gPad->Update();
TLatex l_ROACSDm1;
l_ROACSDm1.SetTextSize(0.04);
l_ROACSDm1.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSDm1));


TCanvas *ACS_RPCOccD1 = new TCanvas(Form("RO_VS_ACS_D1"));
ACS_RPCOccD1->cd();
out_ROACSD1->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSD1->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSD1->GetXaxis()->SetTitleOffset(1.2);
out_ROACSD1->GetXaxis()->SetTitleSize(0.03);
out_ROACSD1->Draw("colz text");
gPad->Update();
TLatex l_ROACSD1;
l_ROACSD1.SetTextSize(0.04);
l_ROACSD1.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSD1));


TCanvas *ACS_RPCOccD2 = new TCanvas(Form("RO_VS_ACS_D2"));
ACS_RPCOccD2->cd();
out_ROACSD2->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSD2->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSD2->GetXaxis()->SetTitleOffset(1.2);
out_ROACSD2->GetXaxis()->SetTitleSize(0.03);
out_ROACSD2->Draw("colz text");
gPad->Update();
TLatex l_ROACSD2;
l_ROACSD2.SetTextSize(0.04);
l_ROACSD2.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSD2));


TCanvas *ACS_RPCOccD3 = new TCanvas(Form("RO_VS_ACS_D3"));
ACS_RPCOccD3->cd();
out_ROACSD3->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSD3->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSD3->GetXaxis()->SetTitleOffset(1.2);
out_ROACSD3->GetXaxis()->SetTitleSize(0.03);
out_ROACSD3->Draw("colz text");
gPad->Update();
TLatex l_ROACSD3;
l_ROACSD3.SetTextSize(0.04);
l_ROACSD3.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSD3));


TCanvas *ACS_RPCOccD4 = new TCanvas(Form("RO_VS_ACS_D4"));
ACS_RPCOccD4->cd();
out_ROACSD4->GetYaxis()->SetTitle("Average Cluster Size");
out_ROACSD4->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ROACSD4->GetXaxis()->SetTitleOffset(1.2);
out_ROACSD4->GetXaxis()->SetTitleSize(0.03);
out_ROACSD4->Draw("colz text");
gPad->Update();
TLatex l_ROACSD4;
l_ROACSD4.SetTextSize(0.04);
l_ROACSD4.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_ROACSD4));




//------------------------------------------------------------------------
//Write hist to directory
//------------------------------------------------------------------------

TFile *out = new TFile(outfilename.c_str(), "RECREATE");
        out->mkdir("Endcap");

out->cd("/Endcap");
        out->mkdir("Endcap/ACS_VS_FCE/");
out->cd("Endcap/ACS_VS_FCE/");

//average cluster size VS Fiducial Cut Eff
AverageCLSDm4->Write();
AverageCLSDm3->Write();
AverageCLSDm2->Write();
AverageCLSDm1->Write();
AverageCLSD1->Write();
AverageCLSD2->Write();
AverageCLSD3->Write();
AverageCLSD4->Write();

AverageCLSDm4->SaveAs("ClusterSize_VS_FiducialEff_Disk-4.png");
AverageCLSDm3->SaveAs("ClusterSize_VS_FiducialEff_Disk-3.png");
AverageCLSDm2->SaveAs("ClusterSize_VS_FiducialEff_Disk-2.png");
AverageCLSDm1->SaveAs("ClusterSize_VS_FiducialEff_Disk-1.png");
AverageCLSD1->SaveAs("ClusterSize_VS_FiducialEff_Disk1.png");
AverageCLSD2->SaveAs("ClusterSize_VS_FiducialEff_Disk2.png");
AverageCLSD3->SaveAs("ClusterSize_VS_FiducialEff_Disk3.png");
AverageCLSD4->SaveAs("ClusterSize_VS_FiducialEff_Disk4.png");


//RPC Occupancy VS Fiducial Cut Eff
out->mkdir("Endcap/RPCOcc_VS_FCE/");
out->cd("Endcap/RPCOcc_VS_FCE/");

RPCOccDm4->Write();
RPCOccDm3->Write();
RPCOccDm2->Write();
RPCOccDm1->Write();
RPCOccD1->Write();
RPCOccD2->Write();
RPCOccD3->Write();
RPCOccD4->Write();


RPCOccDm4->SaveAs("RPCOcc_VS_FiducialEff_Disk-4.png");
RPCOccDm3->SaveAs("RPCOcc_VS_FiducialEff_Disk-3.png");
RPCOccDm2->SaveAs("RPCOcc_VS_FiducialEff_Disk-2.png");
RPCOccDm1->SaveAs("RPCOcc_VS_FiducialEff_Disk-1.png");
RPCOccD1->SaveAs("RPCOcc_VS_FiducialEff_Disk1.png");
RPCOccD2->SaveAs("RPCOcc_VS_FiducialEff_Disk2.png");
RPCOccD3->SaveAs("RPCOcc_VS_FiducialEff_Disk3.png");
RPCOccD4->SaveAs("RPCOcc_VS_FiducialEff_Disk4.png");



//RPC Occupancy VS Average Cluster Size
out->mkdir("Endcap/RPCOcc_VS_ACS/");
out->cd("Endcap/RPCOcc_VS_ACS/");

ACS_RPCOccDm4->Write();
ACS_RPCOccDm3->Write();
ACS_RPCOccDm2->Write();
ACS_RPCOccDm1->Write();
ACS_RPCOccD1->Write();
ACS_RPCOccD2->Write();
ACS_RPCOccD3->Write();
ACS_RPCOccD4->Write();

ACS_RPCOccDm4->SaveAs("ClusterSize_VS_RPCOcc_Disk-4.png");
ACS_RPCOccDm3->SaveAs("ClusterSize_VS_RPCOcc_Disk-3.png");
ACS_RPCOccDm2->SaveAs("ClusterSize_VS_RPCOcc_Disk-2.png");
ACS_RPCOccDm1->SaveAs("ClusterSize_VS_RPCOcc_Disk-1.png");
ACS_RPCOccD1->SaveAs("ClusterSize_VS_RPCOcc_Disk1.png");
ACS_RPCOccD2->SaveAs("ClusterSize_VS_RPCOcc_Disk2.png");
ACS_RPCOccD3->SaveAs("ClusterSize_VS_RPCOcc_Disk3.png");
ACS_RPCOccD4->SaveAs("ClusterSize_VS_RPCOcc_Disk4.png");


}


