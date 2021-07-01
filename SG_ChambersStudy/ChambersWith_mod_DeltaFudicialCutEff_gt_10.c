#include <iostream>
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TDirectory.h"
#include "TFile.h"
void ChambersWith_mod_DeltaFudicialCutEff_gt_10(std::string infilename1, std::string infilename2, std::string outfilename)
{

//Define Canvas	
/*TCanvas *c1 = new TCanvas("c1", "c1", 61,24,800,800);
c1->Range(2.40754,-1.002296,9.425494,6.993801);
*/

//Open the root file
TFile *f1 = TFile::Open(infilename1.c_str());
TFile *f2 = TFile::Open(infilename2.c_str());


//Open Barrel directory
TDirectory* dir_barrel1 = (TDirectory*)f1->Get("Barrel");
TDirectory* dir_barrel2 = (TDirectory*)f2->Get("Barrel");

TDirectory* dir_endcap1 = (TDirectory*)f1->Get("Endcap");
TDirectory* dir_endcap2 = (TDirectory*)f2->Get("Endcap");



std::vector<std::string>hist_name_BFCE;
hist_name_BFCE.push_back("FiducialCutEffW-2");
hist_name_BFCE.push_back("FiducialCutEffW-1");
hist_name_BFCE.push_back("FiducialCutEffW0");
hist_name_BFCE.push_back("FiducialCutEffW1");
hist_name_BFCE.push_back("FiducialCutEffW2");

std::vector<std::string>hist_name_EFCE;
hist_name_EFCE.push_back("FiducialCutEffD1");
hist_name_EFCE.push_back("FiducialCutEffD2");




ofstream outfile;
outfile.open (outfilename.c_str());
outfile << "	Chamber			Delta Fiducial Cut Eff\n";

float arr_BFCE[500], arr_EFCE[500];
const char *xlab_W[500], *ylab_W[500];
const char *xlab_D[500], *ylab_D[500];




std:: string chamber;
int max;
const Int_t nhist=10;

for(unsigned int p=0; p<hist_name_BFCE.size(); p++){
        TH2F *hist_BFCE1 = (TH2F*)dir_barrel1->Get((hist_name_BFCE.at(p)).c_str());
        TH2F *hist_BFCE2 = (TH2F*)dir_barrel2->Get((hist_name_BFCE.at(p)).c_str());

        int q = p-2;
        for(int i = 1; i<=12; i++){
                        if(i<=3){max=17;}
                        else if(i==4){max=21;}
                        else if(i>4 && i<=8){max=17;}
                        else if(i==9 || i==11){max=15;}
                        else {max=17;}
                        for(int k = 1; k<=max; k++){
                                xlab_W[i] = hist_BFCE1->GetXaxis()->GetBinLabel(i);
                                ylab_W[k] = hist_BFCE1->GetYaxis()->GetBinLabel(k);
                  std:: string chamber = "Wheel" + std::to_string(q) + "  S" + std:: string(xlab_W[i]) + "_" + std::string(ylab_W[k]);
                       
			arr_BFCE[k] = hist_BFCE2->GetBinContent(i,k) -  hist_BFCE1->GetBinContent(i,k);
			if(arr_BFCE[k]<-10 || arr_BFCE[k]>10){
     		              outfile<<std::setw(25)<<chamber<<std::setw(20)<<arr_BFCE[k]<<endl;
			}
                      }
                    }
                  }
        


int q;
for(unsigned int p=0; p<hist_name_EFCE.size(); p++){
        TH2F *hist_EFCE1= (TH2F*)dir_endcap1->Get((hist_name_EFCE.at(p)).c_str());
	TH2F *hist_EFCE2= (TH2F*)dir_endcap2->Get((hist_name_EFCE.at(p)).c_str());
        q=p+1;
  
        for(int i = 1; i<=36; i++){
                for(int k = 1; k<=6; k++){
                                xlab_D[i] = hist_EFCE1->GetXaxis()->GetBinLabel(i);
                                ylab_D[k] = hist_EFCE1->GetYaxis()->GetBinLabel(k);
                                std::string ring_name;
                                if(k==1 || k==3) {ring_name = " Ring2 ";}
                                else if(k==2 || k==5){ring_name = " ";}
                                else {ring_name = " Ring3 ";}
std::string chamber_endcap = "RE" + std::to_string(q) + std::string(ring_name) + std:: string(ylab_D[k]) + " " + std::string(xlab_D[i]);
                                arr_EFCE[k] = hist_EFCE2->GetBinContent(i,k) -  hist_EFCE1->GetBinContent(i,k);

                        if(arr_EFCE[k]<-10 || arr_EFCE[k]>10){
                              outfile<<std::setw(25)<<chamber_endcap<<std::setw(20)<<arr_EFCE[k]<<endl;

                           }
                      }
                }
           }
 







}


