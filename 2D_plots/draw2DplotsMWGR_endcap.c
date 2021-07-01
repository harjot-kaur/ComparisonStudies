#include <iostream>
#include <stdlib.h>
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TDirectory.h"
#include "TFile.h"
void draw2DplotsMWGR_endcap(std::string infilename, int TotalLumiSections, std::string outfilename)
{

//Open the root file
TFile *f1 = TFile::Open(infilename.c_str());


TDirectory* dir_endcap = (TDirectory*)f1->Get("Endcap");

//------------------------------------------------------------------------
//extract the hist
//------------------------------------------------------------------------

//average cluster size
std::vector<std::string>hist_name_EACS;
hist_name_EACS.push_back("AverageCLSD-4");
hist_name_EACS.push_back("AverageCLSD-3");
hist_name_EACS.push_back("AverageCLSD-2");
hist_name_EACS.push_back("AverageCLSD-1");
hist_name_EACS.push_back("AverageCLSD1");
hist_name_EACS.push_back("AverageCLSD2");
hist_name_EACS.push_back("AverageCLSD3");
hist_name_EACS.push_back("AverageCLSD4");


//Fudicial_cut_efficiencies
std::vector<std::string>hist_name_EFCE;
hist_name_EFCE.push_back("FiducialCutEffD-4");
hist_name_EFCE.push_back("FiducialCutEffD-3");
hist_name_EFCE.push_back("FiducialCutEffD-2");
hist_name_EFCE.push_back("FiducialCutEffD-1");
hist_name_EFCE.push_back("FiducialCutEffD1");
hist_name_EFCE.push_back("FiducialCutEffD2");
hist_name_EFCE.push_back("FiducialCutEffD3");
hist_name_EFCE.push_back("FiducialCutEffD4");


//RPC_occupancy
std::vector<std::string>hist_name_ERO;
hist_name_ERO.push_back("RPCRealOccD-4");
hist_name_ERO.push_back("RPCRealOccD-3");
hist_name_ERO.push_back("RPCRealOccD-2");
hist_name_ERO.push_back("RPCRealOccD-1");
hist_name_ERO.push_back("RPCRealOccD1");
hist_name_ERO.push_back("RPCRealOccD2");
hist_name_ERO.push_back("RPCRealOccD3");
hist_name_ERO.push_back("RPCRealOccD4");

//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------
//Define array to be filled in output
//------------------------------------------------------------------------
float arr_EACS[46], arr_EFCE[46], arr_ERO[46];

//------------------------------------------------------------------------

TH2D *out_EACS = new TH2D("ACS_VS_FCE", "Cluster Size VS Fiducial Cut Efficiency", 101,-0.5,100.5, 16,0.0,4.0);
TH2F *out_ERO = new TH2F("RPCOcc_VS_FCE","RPC Occupancy VS Fiducial Cut Efficiency",101,-0.5,100.5, 50,0.0,500.0);
TH2F *out_EROACS = new TH2F("RPCOcc_VS_ACS","RPC Occupancy VS Cluster Size",50,0.0,500.0,16,0.0,4.0);

int q;
for(unsigned int p=0; p<hist_name_EACS.size(); p++){
        TH2F *hist_EACS= (TH2F*)dir_endcap->Get((hist_name_EACS.at(p)).c_str());
        TH2F *hist_EFCE= (TH2F*)dir_endcap->Get((hist_name_EFCE.at(p)).c_str());
        TH2F *hist_ERO= (TH2F*)dir_endcap->Get((hist_name_ERO.at(p)).c_str());

        for(int i = 1; i<=36; i++){
                for(int k = 1; k<=6; k++){
                        arr_EACS[i] = hist_EACS->GetBinContent(i,k);
                        arr_EFCE[i] = hist_EFCE->GetBinContent(i,k);
                        arr_ERO[i] = (hist_ERO->GetBinContent(i,k))/TotalLumiSections;


			out_EACS->Fill(arr_EFCE[i],arr_EACS[i]);
			out_ERO->Fill(arr_EFCE[i],arr_ERO[i]);
			out_EROACS->Fill(arr_ERO[i],arr_EACS[i]);

           }
    }
}

float corr_EACS=out_EACS->GetCorrelationFactor();
float corr_ERO=out_ERO->GetCorrelationFactor();
float corr_EROACS=out_EROACS->GetCorrelationFactor();



//Draw Canvas

//Average Cluster Size VS Fiducial Cut Eff
TCanvas *EAverageCLS = new TCanvas(Form("ACS_VS_FCE"));
EAverageCLS->cd();
out_EACS->GetXaxis()->SetTitle("Fiducial Efficiency");
out_EACS->GetYaxis()->SetTitle("Average Cluster Size");
out_EACS->Draw("colz text");
gPad->Update();
TLatex l_EACS;
l_EACS.SetTextSize(0.04);
l_EACS.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_EACS));

//RPC Occupancy VS Fiducial Cut Eff
TCanvas *ERPCOcc = new TCanvas(Form("RO_VS_FCE"));
ERPCOcc->cd();
out_ERO->GetXaxis()->SetTitle("Fiducial Efficiency");
out_ERO->GetYaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_ERO->GetYaxis()->SetTitleSize(0.03);
out_ERO->Draw("colz text");
gPad->Update();
TLatex l_ERO;
l_ERO.SetTextSize(0.04);
l_ERO.DrawLatex(1,400,Form("Correlation Factor = %f", corr_ERO));


//RPC Occupancy VS Average Cluster Size
TCanvas *EACS_RPCOcc = new TCanvas(Form("RO_VS_ACS"));
EACS_RPCOcc->cd();
out_EROACS->GetYaxis()->SetTitle("Average Cluster Size");
out_EROACS->GetXaxis()->SetTitle("#frac{RPC occupancy}{Total Lumisections}");
out_EROACS->GetXaxis()->SetTitleOffset(1.2);
out_EROACS->GetXaxis()->SetTitleSize(0.03);
out_EROACS->Draw("colz text");
gPad->Update();
TLatex l_EROACS;
l_EROACS.SetTextSize(0.04);
l_EROACS.DrawLatex(1,3.5,Form("Correlation Factor = %f", corr_EROACS));



//------------------------------------------------------------------------
//Write hist to directory
//------------------------------------------------------------------------

TFile *out = new TFile(outfilename.c_str(), "RECREATE");
        out->mkdir("Endcap");

out->cd("/Endcap");

//average cluster size VS Fiducial Cut Eff
out->mkdir("Endcap/ACS_VS_FCE/");
out->cd("Endcap/ACS_VS_FCE/");
EAverageCLS->Write();
EAverageCLS->SaveAs("Endcap_ClusterSize_VS_FiducialEff.png");


//RPC Occupancy VS Fiducial Cut Eff
out->mkdir("Endcap/RPCOcc_VS_FCE/");
out->cd("Endcap/RPCOcc_VS_FCE/");
ERPCOcc->Write();
ERPCOcc->SaveAs("Endcap_RPCOcc_VS_FiducialEff.png");


//RPC Occupancy VS Average Cluster Size
out->mkdir("Endcap/RPCOcc_VS_ACS/");
out->cd("Endcap/RPCOcc_VS_ACS/");
EACS_RPCOcc->Write();
EACS_RPCOcc->SaveAs("Endcap_ClusterSize_VS_RPCOcc.png");


}
