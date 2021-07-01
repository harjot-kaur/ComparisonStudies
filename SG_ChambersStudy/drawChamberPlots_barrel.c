#include <iostream>
#include <stdlib.h>
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TDirectory.h"
#include "TFile.h"
void drawChamberPlots_barrel(std::string infilename, std::string outfilename, std::string outtxtfile, std::string outtxtfileFCE90)
{

//------------------------------------------------------------------------
// List of chambers
//------------------------------------------------------------------------

std::string  listofchambers_barrel[] = {"Wheel-2  S5_RB4+_B", "Wheel-2  S5_RB4+_F", "Wheel-2  S8_RB1in_B", "Wheel-2  S8_RB1in_F", "Wheel-2  S8_RB3-_B", "Wheel-2  S8_RB3-_F", "Wheel-2  S8_RB4,-_B", "Wheel-2  S8_RB4,-_F", "Wheel-2  S10_RB1in_B", "Wheel-2  S10_RB1in_F", "Wheel-2  S10_RB3-_B", "Wheel-2  S10_RB3-_F", "Wheel-2  S10_RB4+_B", "Wheel-2  S10_RB4+_F", "Wheel-2  S12_RB1out_B", "Wheel-2  S12_RB1out_F", "Wheel-1  S1_RB3-_B", "Wheel-1  S1_RB3-_F", "Wheel-1  S2_RB1in_B", "Wheel-1  S2_RB1in_F", "Wheel-1  S2_RB1out_B", "Wheel-1  S2_RB1out_F", "Wheel-1  S4_RB1out_B", "Wheel-1  S4_RB1out_F", "Wheel-1  S4_RB2in_B", "Wheel-1  S4_RB2in_M", "Wheel-1  S4_RB2in_F", "Wheel-1  S4_RB2out_B", "Wheel-1  S4_RB2out_F", "Wheel-1  S5_RB4,-_B", "Wheel-1  S5_RB4,-_F", "Wheel-1  S5_RB4+_B", "Wheel-1  S5_RB4+_F", "Wheel-1  S6_RB3-_B", "Wheel-1  S6_RB3-_F", "Wheel-1  S7_RB2in_B", "Wheel-1  S7_RB2in_M", "Wheel-1  S7_RB2in_F", "Wheel-1  S7_RB2out_B", "Wheel-1  S7_RB2out_F", "Wheel-1  S8_RB4+_B", "Wheel-1  S8_RB4+_F", "Wheel-1  S11_RB1out_B", "Wheel-1  S11_RB1out_F", "Wheel-1  S11_RB3+_B", "Wheel-1  S11_RB3+_F", "Wheel-1  S12_RB2out_B", "Wheel-1  S12_RB2out_F", "Wheel-1  S12_RB4+_B", "Wheel-1  S12_RB4+_F", "Wheel0  S1_RB1in_B", "Wheel0  S1_RB1in_F", "Wheel0  S5_RB2in_B", "Wheel0  S5_RB2in_M", "Wheel0  S5_RB2in_F", "Wheel0  S7_RB1out_B", "Wheel0  S7_RB1out_F", "Wheel0  S8_RB1in_B", "Wheel0  S8_RB1in_F", "Wheel0  S10_RB3-_B", "Wheel0  S10_RB3-_F", "Wheel0  S12_RB1in_B", "Wheel0  S12_RB1in_F", "Wheel0  S12_RB4,-_B", "Wheel0  S12_RB4,-_F", "Wheel1  S1_RB1in_B", "Wheel1  S1_RB1in_F", "Wheel1  S1_RB2in_B", "Wheel1  S1_RB2in_M", "Wheel1  S1_RB2in_F", "Wheel1  S3_RB1out_B", "Wheel1  S3_RB1out_F", "Wheel1  S4_RB2in_F", "Wheel1  S4_RB2in_M", "Wheel1  S4_RB2in_B", "Wheel1  S5_RB2out_F", "Wheel1  S5_RB2out_B", "Wheel1  S6_RB1out_F", "Wheel1  S6_RB1out_B", "Wheel1  S6_RB4,-_F", "Wheel1  S6_RB4,-_B", "Wheel1  S7_RB4,-_F", "Wheel1  S7_RB4,-_B", "Wheel1  S10_RB1out_F", "Wheel1  S10_RB1out_B", "Wheel1  S11_RB1out_F", "Wheel1  S11_RB1out_B", "Wheel1  S12_RB2out_F", "Wheel1  S12_RB2out_B", "Wheel2  S1_RB3+_F", "Wheel2  S1_RB3+_B", "Wheel2  S1_RB4,-_F", "Wheel2  S1_RB4,-_B", "Wheel2  S1_RB4+_F", "Wheel2  S1_RB4+_B", "Wheel2  S2_RB1out_F", "Wheel2  S2_RB1out_B", "Wheel2  S8_RB2in_F", "Wheel2  S8_RB2in_M", "Wheel2  S8_RB2in_B", "Wheel2  S8_RB2out_F", "Wheel2  S8_RB2out_B", "Wheel2  S10_RB4,-_F", "Wheel2  S10_RB4,-_B", "Wheel2  S11_RB1out_F", "Wheel2  S11_RB1out_B", "Wheel2  S11_RB3+_F", "Wheel2  S11_RB3+_B", "Wheel2  S12_RB1in_F", "Wheel2  S12_RB1in_B", "Wheel2  S12_RB1out_F", "Wheel2  S12_RB1out_B", "Wheel2  S12_RB3+_F", "Wheel2  S12_RB3+_B"};



int numberofchambers_barrel = sizeof(listofchambers_barrel)/sizeof(listofchambers_barrel[0]) ;





//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------





//Open the root file
TFile *f1 = TFile::Open(infilename.c_str());

TFile *out = new TFile(outfilename.c_str(), "RECREATE");
        out->mkdir("Barrel");

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


//average_residuals
std::vector<std::string>hist_name_BAR;
hist_name_BAR.push_back("AverageResidualsW-2");
hist_name_BAR.push_back("AverageResidualsW-1");
hist_name_BAR.push_back("AverageResidualsW0");
hist_name_BAR.push_back("AverageResidualsW1");
hist_name_BAR.push_back("AverageResidualsW2");

//average_strip_efficiencies
std::vector<std::string>hist_name_BASE;
hist_name_BASE.push_back("AverageStripEffW-2");
hist_name_BASE.push_back("AverageStripEffW-1");
hist_name_BASE.push_back("AverageStripEffW0");
hist_name_BASE.push_back("AverageStripEffW1");
hist_name_BASE.push_back("AverageStripEffW2");

//expected_occupancy
std::vector<std::string>hist_name_BEO;
hist_name_BEO.push_back("ExpOccW-2");
hist_name_BEO.push_back("ExpOccW-1");
hist_name_BEO.push_back("ExpOccW0");
hist_name_BEO.push_back("ExpOccW1");
hist_name_BEO.push_back("ExpOccW2");


//Fudicial_cut_efficiencies
std::vector<std::string>hist_name_BFCE;
hist_name_BFCE.push_back("FiducialCutEffW-2");
hist_name_BFCE.push_back("FiducialCutEffW-1");
hist_name_BFCE.push_back("FiducialCutEffW0");
hist_name_BFCE.push_back("FiducialCutEffW1");
hist_name_BFCE.push_back("FiducialCutEffW2");

//RPC_occupancy_from_DT
std::vector<std::string>hist_name_BROD;
hist_name_BROD.push_back("RPCOccW-2");
hist_name_BROD.push_back("RPCOccW-1");
hist_name_BROD.push_back("RPCOccW0");
hist_name_BROD.push_back("RPCOccW1");
hist_name_BROD.push_back("RPCOccW2");


//RPC_occupancy
std::vector<std::string>hist_name_BRO;
hist_name_BRO.push_back("RPCRealOccW-2");
hist_name_BRO.push_back("RPCRealOccW-1");
hist_name_BRO.push_back("RPCRealOccW0");
hist_name_BRO.push_back("RPCRealOccW1");
hist_name_BRO.push_back("RPCRealOccW2");


//Total_efficiencies
std::vector<std::string>hist_name_BTE;
hist_name_BTE.push_back("TotalEffW-2");
hist_name_BTE.push_back("TotalEffW-1");
hist_name_BTE.push_back("TotalEffW0");
hist_name_BTE.push_back("TotalEffW1");
hist_name_BTE.push_back("TotalEffW2");




//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------
//Define array to be filled in output
//------------------------------------------------------------------------
float arr_BACS[500], arr_BAR[500], arr_BASE[500], arr_BEO[500], arr_BFCE[500], arr_BROD[500], arr_BRO[500],arr_BTE[500];

const char *xlab_W[500], *ylab_W[500];


//------------------------------------------------------------------------


ofstream FCE90;
FCE90.open(outtxtfileFCE90.c_str());

ofstream txtfile;
txtfile.open (outtxtfile.c_str());
txtfile<<"\\begin{tabular}{ | l | c | c | c | c | c | c | c | c | c |}  \n";
txtfile<<" \\hline"<<endl;
txtfile << "Chamber &  Average cluster size &   Average Residuals  &   Average Strip Efficiencies &   expected occupancy & Fiducial Eff & RPC occupancy from DT &   RPC occupancy &  total efficiencies \\\\  \\hline \n";


TH1F *out_BACS = new TH1F("AverageCLS","Cluster Size Mean Value",8,0.0,4.0);
TH1F *out_BAR = new TH1F("AverageResiduals","Residuals Mean Value",16,-4.0,4.0);
TH1F *out_BASE = new TH1F("AverageStripEff","Average Strip Efficiency",101,-0.5,100.5);
TH1F *out_BEO = new TH1F("ExpOcc","Expected Occupancy",410,0.0,410000.0);
TH1F *out_BFCE = new TH1F("FiducialCutEff","Fiducial Cut Efficiency",102,-1.0,101.0);
TH1F *out_BROD = new TH1F("RPCOcc","RPC Occupancy from DT",410,0.0,410000.0);
TH1F *out_BRO = new TH1F("RPCRealOcc","RPC Occupancy",1000,0.0,10000000.0);
TH1F *out_BTE = new TH1F("TotalEff","Total Efficiency",102,-1.0,101.0);



std:: string chamber;
int max;
const Int_t nhist=10;

for(unsigned int p=0; p<hist_name_BACS.size(); p++){
        TH2F *hist_BACS= (TH2F*)dir_barrel->Get((hist_name_BACS.at(p)).c_str());
	TH2F *hist_BAR= (TH2F*)dir_barrel->Get((hist_name_BAR.at(p)).c_str());
        TH2F *hist_BASE= (TH2F*)dir_barrel->Get((hist_name_BASE.at(p)).c_str());
        TH2F *hist_BEO= (TH2F*)dir_barrel->Get((hist_name_BEO.at(p)).c_str());
        TH2F *hist_BFCE = (TH2F*)dir_barrel->Get((hist_name_BFCE.at(p)).c_str());
        TH2F *hist_BROD= (TH2F*)dir_barrel->Get((hist_name_BROD.at(p)).c_str());
        TH2F *hist_BRO= (TH2F*)dir_barrel->Get((hist_name_BRO.at(p)).c_str());
        TH2F *hist_BTE= (TH2F*)dir_barrel->Get((hist_name_BTE.at(p)).c_str());

        int q = p-2;
        for(int i = 1; i<=12; i++){
                        if(i<=3){max=17;}
                        else if(i==4){max=21;}
                        else if(i>4 && i<=8){max=17;}
                        else if(i==9 || i==11){max=15;}
                        else {max=17;}
                        for(int k = 1; k<=max; k++){
                                xlab_W[i] = hist_BACS->GetXaxis()->GetBinLabel(i);
                                ylab_W[k] = hist_BACS->GetYaxis()->GetBinLabel(k);

                        std:: string chamber = "Wheel" + std::to_string(q) + "  S" + std:: string(xlab_W[i]) + "_" + std::string(ylab_W[k]);
                        //cout<<p<<"      chamber name: "<<chamber<<endl;
                                for(int m=0; m<numberofchambers_barrel; m++){
                                                if(listofchambers_barrel[m] == chamber){
                                                        
							arr_BACS[m] = hist_BACS->GetBinContent(i,k);
							out_BACS->Fill(arr_BACS[m]);

                                                        arr_BAR[m] = hist_BAR->GetBinContent(i,k);
							out_BAR->Fill(arr_BAR[m]);

                                                        arr_BASE[m] = hist_BASE->GetBinContent(i,k);
							out_BASE->Fill(arr_BASE[m]);

                                                        arr_BEO[m] = hist_BEO->GetBinContent(i,k);
							out_BEO->Fill(arr_BEO[m]);

                                                        arr_BFCE[m] = hist_BFCE->GetBinContent(i,k);
							out_BFCE->Fill(arr_BFCE[m]);

                                                        arr_BROD[m] = hist_BROD->GetBinContent(i,k);
							out_BROD->Fill(arr_BROD[m]);

                                                        arr_BRO[m] = hist_BRO->GetBinContent(i,k);
							out_BRO->Fill(arr_BRO[m]);

                                                        arr_BTE[m] = hist_BTE->GetBinContent(i,k);
							out_BTE->Fill(arr_BTE[m]);


							txtfile <<listofchambers_barrel[m]<<std::setw(10)<<" & "<<arr_BACS[m]<<" & "<<std::setw(10)<<arr_BAR[m]<<" & "<<std::setw(10)<<arr_BASE[m]<<" & "<<std::setw(10)<<arr_BEO[m]<<" & "<<std::setw(10)<<arr_BFCE[m]<<" & "<<std::setw(10)<<arr_BROD[m]<<" & "<<std::setw(10)<<arr_BRO[m]<<" & "<<std::setw(10)<<arr_BTE[m]<<" \\\\ \\hline "<<endl;

                                                        if(arr_BFCE[m] > 90){
					FCE90 <<listofchambers_barrel[m]<<std::setw(25)<<"	"<<arr_BFCE[m]<<endl;
                                                        }


//                                                      cout<<"chamber:   "<<chamber<<"   arr_ACS["<<m<<"] ="<<arr_BACS[m]<<endl;
                                                }
                                }
                        }
        }
}

out->cd("/Barrel");
out_BACS->Write();
out_BAR->Write();
out_BASE->Write();
out_BEO->Write();
out_BFCE->Write();
out_BROD->Write();
out_BRO->Write();
out_BTE->Write();


txtfile<<" \n";




}
