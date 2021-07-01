#include <iostream>
#include <stdlib.h>
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TDirectory.h"
#include "TFile.h"
void draw2DplotsMWGR_barrel(std::string infilename, int TotalLumiSections, std::string outfilename)
{


//Open the root file
TFile *f1 = TFile::Open(infilename.c_str());

TDirectory* dir_barrel = (TDirectory*)f1->Get("Barrel");

//------------------------------------------------------------------------
//extract the hist
//------------------------------------------------------------------------

//average_cluster_size
std::vector<std::string>hist_name_BACS;
hist_name_BACS.push_back("AverageCLSW-2");
hist_name_BACS.push_back("AverageCLSW-1");
hist_name_BACS.push_back("AverageCLSW0");
hist_name_BACS.push_back("AverageCLSW1");
hist_name_BACS.push_back("AverageCLSW2");

//Fudicial_cut_efficiencies
std::vector<std::string>hist_name_BFCE;
hist_name_BFCE.push_back("FiducialCutEffW-2");
hist_name_BFCE.push_back("FiducialCutEffW-1");
hist_name_BFCE.push_back("FiducialCutEffW0");
hist_name_BFCE.push_back("FiducialCutEffW1");
hist_name_BFCE.push_back("FiducialCutEffW2");

//RPC_occupancy
std::vector<std::string>hist_name_BRO;
hist_name_BRO.push_back("RPCRealOccW-2");
hist_name_BRO.push_back("RPCRealOccW-1");
hist_name_BRO.push_back("RPCRealOccW0");
hist_name_BRO.push_back("RPCRealOccW1");
hist_name_BRO.push_back("RPCRealOccW2");

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------
//Define array to be filled in output
//------------------------------------------------------------------------
float arr_BACS[500], arr_BFCE[500], arr_BRO[500];


//------------------------------------------------------------------------



TH2F *out_BACS = new TH2F("ACS_VS_FCE", "Cluster Size VS Fiducial Cut Efficiency", 101,-0.5,100.5, 16,0.0,4.0);
TH2F *out_BRO = new TH2F("RPCOcc_VS_FCE","RPC Occupancy VS Fiducial Cut Efficiency",101,-0.5,100.5, 50,0.0,500.0);
TH2F *out_BROACS = new TH2F("RPCOcc_VS_ACS","RPC Occupancy VS Cluster Size",50,0.0,500.0,16,0.0,4.0);



int max;
const Int_t nhist=10;

for(unsigned int p=0; p<hist_name_BACS.size(); p++){
        TH2F *hist_BACS= (TH2F*)dir_barrel->Get((hist_name_BACS.at(p)).c_str());
        TH2F *hist_BFCE = (TH2F*)dir_barrel->Get((hist_name_BFCE.at(p)).c_str());
        TH2F *hist_BRO= (TH2F*)dir_barrel->Get((hist_name_BRO.at(p)).c_str());

        int q = p-2;
        for(int i = 1; i<=12; i++){
                        if(i<=3){max=17;}
                        else if(i==4){max=21;}
                        else if(i>4 && i<=8){max=17;}
                        else if(i==9 || i==11){max=15;}
                        else {max=17;}
                        for(int k = 1; k<=max; k++){
				arr_BACS[i] = hist_BACS->GetBinContent(i,k);
                                arr_BFCE[i] = hist_BFCE->GetBinContent(i,k);
                                arr_BRO[i] = (hist_BRO->GetBinContent(i,k))/TotalLumiSections;
				
				out_BACS->Fill(arr_BFCE[i],arr_BACS[i]);
				out_BRO->Fill(arr_BFCE[i],arr_BRO[i]);
				out_BROACS->Fill(arr_BRO[i],arr_BACS[i]);
                         }
        }
}

float corr_BACS=out_BACS->GetCorrelationFactor();
float corr_BRO=out_BRO->GetCorrelationFactor();
float corr_BROACS=out_BROACS->GetCorrelationFactor();



//Draw Canvas

//Average Cluster Size VS Fiducial Cut Eff

TCanvas *BAverageCLS = new TCanvas(Form("ACS_VS_FCE"));
BAverageCLS->cd();
out_BACS->GetXaxis()->SetTitle("Fiducial Efficiency");
out_BACS->GetYaxis()->SetTitle("Average Cluster Size");
out_BACS->Draw("colz text");
gPad->Update();
TLatex l_BACS;
l_BACS.SetTextSize(0.04);
l_BACS.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_BACS));


//RPC Occupancy VS Fiducial Cut Eff

TCanvas *BRPCOcc = new TCanvas(Form("RO_VS_FCE"));
BRPCOcc->cd();
out_BRO->GetXaxis()->SetTitle("Fiducial Efficiency");
out_BRO->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_BRO->GetYaxis()->SetTitleSize(0.03);
out_BRO->Draw("colz text");
gPad->Update();
TLatex l_BRO;
l_BRO.SetTextSize(0.04);
l_BRO.DrawLatex(1,400,Form("Correlation Factor = %f", corr_BRO));


//RPC Occupancy VS Average Cluster Size


TCanvas *BACS_RPCOcc = new TCanvas(Form("RO_VS_ACS"));
BACS_RPCOcc->cd();
out_BROACS->GetYaxis()->SetTitle("Average Cluster Size");
out_BROACS->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_BROACS->GetXaxis()->SetTitleOffset(1.2);
out_BROACS->GetXaxis()->SetTitleSize(0.03);
out_BROACS->Draw("colz text");
gPad->Update();
TLatex l_BROACS;
l_BROACS.SetTextSize(0.04);
l_BROACS.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_BROACS));

//------------------------------------------------------------------------
//Write hist to directory
//------------------------------------------------------------------------

TFile *out = new TFile(outfilename.c_str(), "RECREATE");
        out->mkdir("Barrel");

out->cd("/Barrel");

//average cluster size VS Fiducial Cut Eff
out->mkdir("Barrel/ACS_VS_FCE/");
out->cd("Barrel/ACS_VS_FCE/");
BAverageCLS->Write();
BAverageCLS->SaveAs("Barrel_ClusterSize_VS_FiducialEff.png");


//RPC Occupancy VS Fiducial Cut Eff
out->mkdir("Barrel/RPCOcc_VS_FCE/");
out->cd("Barrel/RPCOcc_VS_FCE/");
BRPCOcc->Write();
BRPCOcc->SaveAs("Barrel_RPCOcc_VS_FiducialEff.png");


//RPC Occupancy VS Average Cluster Size
out->mkdir("Barrel/RPCOcc_VS_ACS/");
out->cd("Barrel/RPCOcc_VS_ACS/");
BACS_RPCOcc->Write();
BACS_RPCOcc->SaveAs("Barrel_ClusterSize_VS_RPCOcc.png");

}
