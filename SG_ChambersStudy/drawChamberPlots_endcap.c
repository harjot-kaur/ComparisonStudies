#include <iostream>
#include <stdlib.h>
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TDirectory.h"
#include "TFile.h"
void drawChamberPlots_endcap(std::string infilename, std::string outfilename, std::string outtxtfile, std::string outtxtfileFCE90)
{

//------------------------------------------------------------------------
// List of chambers
//------------------------------------------------------------------------



std::string  listofchambers_endcap[] = {"RE3 Ring2 C 4", "RE3 Ring2 B 4", "RE3 Ring2 A 4", "RE3 Ring2 C 5", "RE3 Ring2 B 5", "RE3 Ring2 A 5", "RE3 Ring3 C 21", "RE3 Ring3 B 21", "RE3 Ring3 A 21", "RE2 Ring3 C 19", "RE2 Ring3 B 19", "RE2 Ring3 A 19", "RE1 Ring2 C 11", "RE1 Ring2 B 11", "RE1 Ring2 A 11", "RE1 Ring2 C 32", "RE1 Ring2 B 32", "RE1 Ring2 A 32", "RE-1 Ring2 C 20", "RE-1 Ring2 B 20", "RE-1 Ring2 A 20", "RE-1 Ring2 C 29", "RE-1 Ring2 B 29", "RE-1 Ring2 A 29", "RE-1 Ring2 C 31", "RE-1 Ring2 B 31", "RE-1 Ring2 A 31", "RE-1 Ring3 C 17", "RE-1 Ring3 B 17", "RE-1 Ring3 A 17", "RE-2 Ring3 C 22", "RE-2 Ring3 B 22", "RE-2 Ring3 A 22", "RE-2 Ring3 C 29", "RE-2 Ring3 B 29", "RE-2 Ring3 A 29", "RE-2 Ring3 C 27", "RE-2 Ring3 B 27", "RE-2 Ring3 A 27", "RE-3 Ring2 C 17", "RE-3 Ring2 B 17", "RE-3 Ring2 A 17", "RE-3 Ring2 C 20", "RE-3 Ring2 B 20", "RE-3 Ring2 A 20"};

int numberofchambers_endcap= sizeof(listofchambers_endcap)/sizeof(listofchambers_endcap[0]) ;

//---------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------





//Open the root file
TFile *f1 = TFile::Open(infilename.c_str());

TFile *out = new TFile(outfilename.c_str(), "RECREATE");
        out->mkdir("Endcap");

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

//average_residuals
std::vector<std::string>hist_name_EAR;
hist_name_EAR.push_back("AverageResidualsD-4");
hist_name_EAR.push_back("AverageResidualsD-3");
hist_name_EAR.push_back("AverageResidualsD-2");
hist_name_EAR.push_back("AverageResidualsD-1");
hist_name_EAR.push_back("AverageResidualsD1");
hist_name_EAR.push_back("AverageResidualsD2");
hist_name_EAR.push_back("AverageResidualsD3");
hist_name_EAR.push_back("AverageResidualsD4");

//average_strip_efficiencies
std::vector<std::string>hist_name_EASE;
hist_name_EASE.push_back("AverageStripEffD-4");
hist_name_EASE.push_back("AverageStripEffD-3");
hist_name_EASE.push_back("AverageStripEffD-2");
hist_name_EASE.push_back("AverageStripEffD-1");
hist_name_EASE.push_back("AverageStripEffD1");
hist_name_EASE.push_back("AverageStripEffD2");
hist_name_EASE.push_back("AverageStripEffD3");
hist_name_EASE.push_back("AverageStripEffD4");

//expected_occupancy
std::vector<std::string>hist_name_EEO;
hist_name_EEO.push_back("ExpOccD-4");
hist_name_EEO.push_back("ExpOccD-3");
hist_name_EEO.push_back("ExpOccD-2");
hist_name_EEO.push_back("ExpOccD-1");
hist_name_EEO.push_back("ExpOccD1");
hist_name_EEO.push_back("ExpOccD2");
hist_name_EEO.push_back("ExpOccD3");
hist_name_EEO.push_back("ExpOccD4");

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

//RPC_occupancy_from_DT
std::vector<std::string>hist_name_EROD;
hist_name_EROD.push_back("RPCOccD-4");
hist_name_EROD.push_back("RPCOccD-3");
hist_name_EROD.push_back("RPCOccD-2");
hist_name_EROD.push_back("RPCOccD-1");
hist_name_EROD.push_back("RPCOccD1");
hist_name_EROD.push_back("RPCOccD2");
hist_name_EROD.push_back("RPCOccD3");
hist_name_EROD.push_back("RPCOccD4");

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

//Total_efficiencies
std::vector<std::string>hist_name_ETE;
hist_name_ETE.push_back("TotalEffD-4");
hist_name_ETE.push_back("TotalEffD-3");
hist_name_ETE.push_back("TotalEffD-2");
hist_name_ETE.push_back("TotalEffD-1");
hist_name_ETE.push_back("TotalEffD1");
hist_name_ETE.push_back("TotalEffD2");
hist_name_ETE.push_back("TotalEffD3");
hist_name_ETE.push_back("TotalEffD4");


//----------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------
//Define array to be filled in output
//------------------------------------------------------------------------
float arr_EACS[46], arr_EAR[46], arr_EASE[46], arr_EEO[46], arr_EFCE[46], arr_EROD[46], arr_ERO[46],arr_ETE[46];

const char *xlab_D[500], *ylab_D[500];


//------------------------------------------------------------------------


ofstream FCE90;
FCE90.open(outtxtfileFCE90.c_str());

ofstream txtfile;
txtfile.open (outtxtfile.c_str());
txtfile<<"\\begin{tabular}{ | l | c | c | c | c | c | c | c | c | c |}  \n";
txtfile<<" \\hline"<<endl;
txtfile << "Chamber &  Average cluster size &   Average Residuals  &   Average Strip Efficiencies &   expected occupancy & Fiducial Eff & RPC occupancy from DT &   RPC occupancy &  total efficiencies \\\\  \\hline \n";



TH1F *out_EACS = new TH1F("AverageCLS","Cluster Size Mean Value",8,0.0,4.0);
TH1F *out_EAR = new TH1F("AverageResiduals","Residuals Mean Value",16,-4.0,4.0);
TH1F *out_EASE = new TH1F("AverageStripEff","Average Strip Efficiency",101,-0.5,100.5);
TH1F *out_EEO = new TH1F("ExpOcc","Expected Occupancy",41,0.0,410000.0);
TH1F *out_EFCE = new TH1F("FiducialCutEff","Fiducial Cut Efficiency",102,-1.0,101.0);
TH1F *out_EROD = new TH1F("RPCOcc","RPC Occupancy from DT",41,0.0,410000.0);
TH1F *out_ERO = new TH1F("RPCRealOcc","RPC Occupancy",100,0.0,10000000.0);
TH1F *out_ETE = new TH1F("TotalEff","Total Efficiency",102,-1.0,101.0);


int q;
for(unsigned int p=0; p<hist_name_EACS.size(); p++){
        TH2F *hist_EACS= (TH2F*)dir_endcap->Get((hist_name_EACS.at(p)).c_str());
        TH2F *hist_EAR= (TH2F*)dir_endcap->Get((hist_name_EAR.at(p)).c_str());
        TH2F *hist_EASE= (TH2F*)dir_endcap->Get((hist_name_EASE.at(p)).c_str());
        TH2F *hist_EEO= (TH2F*)dir_endcap->Get((hist_name_EEO.at(p)).c_str());
        TH2F *hist_EFCE= (TH2F*)dir_endcap->Get((hist_name_EFCE.at(p)).c_str());
        TH2F *hist_EROD= (TH2F*)dir_endcap->Get((hist_name_EROD.at(p)).c_str());
        TH2F *hist_ERO= (TH2F*)dir_endcap->Get((hist_name_ERO.at(p)).c_str());
        TH2F *hist_ETE= (TH2F*)dir_endcap->Get((hist_name_ETE.at(p)).c_str());

        if(p<=3){q = p-4;}
        else{q = p-3;}
        for(int i = 1; i<=36; i++){
                for(int k = 1; k<=6; k++){
                                xlab_D[i] = hist_EACS->GetXaxis()->GetBinLabel(i);
                                ylab_D[k] = hist_EACS->GetYaxis()->GetBinLabel(k);
                                std::string ring_name;
                                if(k==1 || k==3) {ring_name = " Ring2 ";}
                                else if(k==2 || k==5){ring_name = " ";}
                                else {ring_name = " Ring3 ";}
std::string chamber_endcap = "RE" + std::to_string(q) + std::string(ring_name) + std:: string(ylab_D[k]) + " " + std::string(xlab_D[i]);
                               for(int m=0; m<numberofchambers_endcap; m++){
                                       if(chamber_endcap == listofchambers_endcap[m]){

                                              arr_EACS[m] = hist_EACS->GetBinContent(i,k);
					      out_EACS->Fill(arr_EACS[m]);

                                              arr_EAR[m] = hist_EAR->GetBinContent(i,k);
					      out_EAR->Fill(arr_EAR[m]);

                                              arr_EASE[m] = hist_EASE->GetBinContent(i,k);
					      out_EASE->Fill(arr_EASE[m]);

                                              arr_EEO[m] = hist_EEO->GetBinContent(i,k);
					      out_EEO->Fill(arr_EEO[m]);

                                              arr_EFCE[m] = hist_EFCE->GetBinContent(i,k);
					      out_EFCE->Fill(arr_EFCE[m]);

                                              arr_EROD[m] = hist_EROD->GetBinContent(i,k);
					      out_EROD->Fill(arr_EROD[m]);

                                              arr_ERO[m] = hist_ERO->GetBinContent(i,k);
					      out_ERO->Fill(arr_ERO[m]);

                                              arr_ETE[m] = hist_ETE->GetBinContent(i,k);
					      out_ETE->Fill(arr_ETE[m]);

txtfile <<listofchambers_endcap[m]<<std::setw(10)<<" & "<<arr_EACS[m]<<" & "<<std::setw(10)<<arr_EAR[m]<<" & "<<std::setw(10)<<arr_EASE[m]<<" & "<<std::setw(10)<<arr_EEO[m]<<" & "<<std::setw(10)<<arr_EFCE[m]<<" & "<<std::setw(10)<<arr_EROD[m]<<" & "<<std::setw(10)<<arr_ERO[m]<<" & "<<std::setw(10)<<arr_ETE[m]<<" \\\\ \\hline "<<endl;

						      if(arr_EFCE[m] > 90){
                                        FCE90 <<listofchambers_endcap[m]<<std::setw(25)<<"	"<<arr_EFCE[m]<<endl;
                                                        }


                                              //       cout<<"chamber:   "<<chamber_endcap<<"   arr_EACS["<<m<<"] ="<<arr_EACS[m]<<endl;
                           }
                      }
                }
           }
        }

txtfile<<"\\end{tabular} \n";

out->cd("/Endcap");
out_EACS->Write();
out_EAR->Write();
out_EASE->Write();
out_EEO->Write();
out_EFCE->Write();
out_EROD->Write();
out_ERO->Write();
out_ETE->Write();


}
