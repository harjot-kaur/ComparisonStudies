#include <iostream>
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TDirectory.h"
#include "TFile.h"
void drawplotsMWGR(std::string infilename, std::string outfilename)
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
TH2F *ARWm1, *ARWm2, *ARW0, *ARW1, *ARW2;			//average residuals
TH2F *ASEWm1, *ASEWm2, *ASEW0, *ASEW1, *ASEW2;		//average strip efficiencies
TH2F *EOWm1, *EOWm2, *EOW0, *EOW1, *EOW2;             		//expected occupancy
TH2F *FCEWm1, *FCEWm2, *FCEW0, *FCEW1, *FCEW2;             //Fudicial cut efficiencies
TH2F *RODWm1, *RODWm2, *RODW0, *RODW1, *RODW2;             //RPC occupancy from DT
TH2F *ROWm1, *ROWm2, *ROW0, *ROW1, *ROW2;             //RPC occupancy
TH2F *TEWm1, *TEWm2, *TEW0, *TEW1, *TEW2;             //total efficiencies



//------------------------------------------------------------------------
//extract the hist
//------------------------------------------------------------------------
//average cluster size
dir_barrel->GetObject("AverageCLSW-1",ACSWm1);
dir_barrel->GetObject("AverageCLSW-2",ACSWm2);
dir_barrel->GetObject("AverageCLSW0",ACSW0);
dir_barrel->GetObject("AverageCLSW1",ACSW1);
dir_barrel->GetObject("AverageCLSW2",ACSW2);

//average residuals
dir_barrel->GetObject("AverageResidualsW-1",ARWm1);
dir_barrel->GetObject("AverageResidualsW-2",ARWm2);
dir_barrel->GetObject("AverageResidualsW0",ARW0);
dir_barrel->GetObject("AverageResidualsW1",ARW1);
dir_barrel->GetObject("AverageResidualsW2",ARW2);

//average strip efficiencies
dir_barrel->GetObject("AverageStripEffW-1",ASEWm1);
dir_barrel->GetObject("AverageStripEffW-2",ASEWm2);
dir_barrel->GetObject("AverageStripEffW0",ASEW0);
dir_barrel->GetObject("AverageStripEffW1",ASEW1);
dir_barrel->GetObject("AverageStripEffW2",ASEW2);

//expected occupancy
dir_barrel->GetObject("ExpOccW-1",EOWm1);
dir_barrel->GetObject("ExpOccW-2",EOWm2);
dir_barrel->GetObject("ExpOccW0",EOW0);
dir_barrel->GetObject("ExpOccW1",EOW1);
dir_barrel->GetObject("ExpOccW2",EOW2);


//Fudicial cut efficiencies
dir_barrel->GetObject("FiducialCutEffW-1",FCEWm1);
dir_barrel->GetObject("FiducialCutEffW-2",FCEWm2);
dir_barrel->GetObject("FiducialCutEffW0",FCEW0);
dir_barrel->GetObject("FiducialCutEffW1",FCEW1);
dir_barrel->GetObject("FiducialCutEffW2",FCEW2);


//RPC occupancy from DT
dir_barrel->GetObject("RPCOccW-1",RODWm1);
dir_barrel->GetObject("RPCOccW-2",RODWm2);
dir_barrel->GetObject("RPCOccW0",RODW0);
dir_barrel->GetObject("RPCOccW1",RODW1);
dir_barrel->GetObject("RPCOccW2",RODW2);


//RPC occupancy
dir_barrel->GetObject("RPCRealOccW-1",ROWm1);
dir_barrel->GetObject("RPCRealOccW-2",ROWm2);
dir_barrel->GetObject("RPCRealOccW0",ROW0);
dir_barrel->GetObject("RPCRealOccW1",ROW1);
dir_barrel->GetObject("RPCRealOccW2",ROW2);


//total efficiencies
dir_barrel->GetObject("TotalEffW-1",TEWm1);
dir_barrel->GetObject("TotalEffW-2",TEWm2);
dir_barrel->GetObject("TotalEffW0",TEW0);
dir_barrel->GetObject("TotalEffW1",TEW1);
dir_barrel->GetObject("TotalEffW2",TEW2);

//------------------------------------------------------------------------


//------------------------------------------------------------------------
//define output hist
//------------------------------------------------------------------------

//average cluster size
TH1F *out_ACSWm1 = new TH1F("AverageCLSW-1","Cluster Size Mean Value - Wheel -1",16,0.0,4.0);
TH1F *out_ACSWm2 = new TH1F("AverageCLSW-2","Cluster Size Mean Value - Wheel -2",16,0.0,4.0);
TH1F *out_ACSW0 = new TH1F("AverageCLSW0","Cluster Size Mean Value - Wheel 0",16,0.0,4.0);
TH1F *out_ACSW1 = new TH1F("AverageCLSW1","Cluster Size Mean Value - Wheel 1",16,0.0,4.0);
TH1F *out_ACSW2 = new TH1F("AverageCLSW2","Cluster Size Mean Value - Wheel 2",16,0.0,4.0);


//average residuals
TH1F *out_ARWm1 = new TH1F("AverageResidualsW-1","Residuals Mean Value - Wheel -1",16,-4.0,4.0);
TH1F *out_ARWm2 = new TH1F("AverageResidualsW-2","Residuals Mean Value - Wheel -2",16,-4.0,4.0);
TH1F *out_ARW0 = new TH1F("AverageResidualsW0","Residuals Mean Value - Wheel 0",16,-4.0,4.0);
TH1F *out_ARW1 = new TH1F("AverageResidualsW1","Residuals Mean Value - Wheel 1",16,-4.0,4.0);
TH1F *out_ARW2 = new TH1F("AverageResidualsW2","Residuals Mean Value - Wheel 2",16,-4.0,4.0);


//average strip efficiencies
TH1F *out_ASEWm1 = new TH1F("AverageStripEffW-1","Average Strip Efficiency - Wheel -1",101,-0.5,100.5);
TH1F *out_ASEWm2 = new TH1F("AverageStripEffW-2","Average Strip Efficiency - Wheel -2",101,-0.5,100.5);
TH1F *out_ASEW0 = new TH1F("AverageStripEffW0","Average Strip Efficiency - Wheel 0",101,-0.5,100.5);
TH1F *out_ASEW1 = new TH1F("AverageStripEffW1","Average Strip Efficiency - Wheel 1",101,-0.5,100.5);
TH1F *out_ASEW2 = new TH1F("AverageStripEffW2","Average Strip Efficiency - Wheel 2",101,-0.5,100.5);


//expected occupancy
TH1F *out_EOWm1 = new TH1F("ExpOccW-1","Expected Occupancy - Wheel -1",41,0.0,410000.0);
TH1F *out_EOWm2 = new TH1F("ExpOccW-2","Expected Occupancy - Wheel -2",41,0.0,410000.0);
TH1F *out_EOW0 = new TH1F("ExpOccW0","Expected Occupancy - Wheel 0",41,0.0,410000.0);
TH1F *out_EOW1 = new TH1F("ExpOccW1","Expected Occupancy - Wheel 1",41,0.0,410000.0);
TH1F *out_EOW2 = new TH1F("ExpOccW2","Expected Occupancy - Wheel 2",41,0.0,410000.0);


//Fudicial cut efficiencies
TH1F *out_FCEWm1 = new TH1F("FiducialCutEffW-1","Fiducial Cut Efficiency - Wheel -1",101,-0.5,100.5);
TH1F *out_FCEWm2 = new TH1F("FiducialCutEffW-2","Fiducial Cut Efficiency - Wheel -2",101,-0.5,100.5);
TH1F *out_FCEW0 = new TH1F("FiducialCutEffW0","Fiducial Cut Efficiency - Wheel 0",101,-0.5,100.5);
TH1F *out_FCEW1 = new TH1F("FiducialCutEffW1","Fiducial Cut Efficiency - Wheel 1",101,-0.5,100.5);
TH1F *out_FCEW2 = new TH1F("FiducialCutEffW2","Fiducial Cut Efficiency - Wheel 2",101,-0.5,100.5);


//RPC occupancy from DT
TH1F *out_RODWm1 = new TH1F("RPCOccW-1","RPC Occupancy from DT - Wheel -1",41,0.0,410000.0);
TH1F *out_RODWm2 = new TH1F("RPCOccW-2","RPC Occupancy from DT - Wheel -2",41,0.0,410000.0);
TH1F *out_RODW0 = new TH1F("RPCOccW0","RPC Occupancy from DT - Wheel 0",41,0.0,410000.0);
TH1F *out_RODW1 = new TH1F("RPCOccW1","RPC Occupancy from DT - Wheel 1",41,0.0,410000.0);
TH1F *out_RODW2 = new TH1F("RPCOccW2","RPC Occupancy from DT - Wheel 2",41,0.0,410000.0);


//RPC occupancy
TH1F *out_ROWm1 = new TH1F("RPCRealOccW-1","RPC Occupancy - Wheel -1",100,0.0,1000000.0);
TH1F *out_ROWm2 = new TH1F("RPCRealOccW-2","RPC Occupancy - Wheel -2",100,0.0,1000000.0);
TH1F *out_ROW0 = new TH1F("RPCRealOccW0","RPC Occupancy - Wheel 0",100,0.0,1000000.0);
TH1F *out_ROW1 = new TH1F("RPCRealOccW1","RPC Occupancy - Wheel 1",100,0.0,1000000.0);
TH1F *out_ROW2 = new TH1F("RPCRealOccW2","RPC Occupancy - Wheel 2",100,0.0,1000000.0);


//total efficiencies
TH1F *out_TEWm1 = new TH1F("TotalEffW-1","Total Efficiency - Wheel -1",101,-0.5,100.5);
TH1F *out_TEWm2 = new TH1F("TotalEffW-2","Total Efficiency - Wheel -2",101,-0.5,100.5);
TH1F *out_TEW0 = new TH1F("TotalEffW0","Total Efficiency - Wheel 0",101,-0.5,100.5);
TH1F *out_TEW1 = new TH1F("TotalEffW1","Total Efficiency - Wheel 1",101,-0.5,100.5);
TH1F *out_TEW2 = new TH1F("TotalEffW2","Total Efficiency - Wheel 2",101,-0.5,100.5);

//------------------------------------------------------------------------
//Define array to be filled in output
//------------------------------------------------------------------------

float arr_ACSWm1[500], arr_ACSWm2[500], arr_ACSW0[500], arr_ACSW1[500], arr_ACSW2[500];       //average cluster size
float arr_ARWm1[500], arr_ARWm2[500], arr_ARW0[500], arr_ARW1[500], arr_ARW2[500];                       //average residuals
float arr_ASEWm1[500], arr_ASEWm2[500], arr_ASEW0[500], arr_ASEW1[500], arr_ASEW2[500];          //average strip efficiencies
float arr_EOWm1[500], arr_EOWm2[500], arr_EOW0[500], arr_EOW1[500], arr_EOW2[500];                       //expected occupancy
float arr_FCEWm1[500], arr_FCEWm2[500], arr_FCEW0[500], arr_FCEW1[500], arr_FCEW2[500];             //Fudicial cut efficiencies
float arr_RODWm1[500], arr_RODWm2[500], arr_RODW0[500], arr_RODW1[500], arr_RODW2[500];             //RPC occupancy from DT
float arr_ROWm1[500], arr_ROWm2[500], arr_ROW0[500], arr_ROW1[500], arr_ROW2[500];             //RPC occupancy
float arr_TEWm1[500], arr_TEWm2[500], arr_TEW0[500], arr_TEW1[500], arr_TEW2[500];             //total efficiencies

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
//	cout<<"arr_ACSWm1[i]"<<arr_ACSWm1[i]<<endl;
//	if (ACSWm1->GetBinContent(i) == 0.0000) {
//      continue;
//    }
arr_ACSWm2[i] = ACSWm2->GetBinContent(i,k);
arr_ACSW0[i] = ACSW0->GetBinContent(i,k);
arr_ACSW1[i] = ACSW1->GetBinContent(i,k);
arr_ACSW2[i] = ACSW2->GetBinContent(i,k);
	

//average residuals
arr_ARWm1[i] = ARWm1->GetBinContent(i,k);
arr_ARWm2[i] = ARWm2->GetBinContent(i,k);
arr_ARW0[i] = ARW0->GetBinContent(i,k);
arr_ARW1[i] = ARW1->GetBinContent(i,k);
arr_ARW2[i] = ARW2->GetBinContent(i,k);


//average strip efficiencies
arr_ASEWm1[i] = ASEWm1->GetBinContent(i,k);
arr_ASEWm2[i] = ASEWm2->GetBinContent(i,k);
arr_ASEW0[i] = ASEW0->GetBinContent(i,k);
arr_ASEW1[i] = ASEW1->GetBinContent(i,k);
arr_ASEW2[i] = ASEW2->GetBinContent(i,k);


//expected occupancy
arr_EOWm1[i] = EOWm1->GetBinContent(i,k);
arr_EOWm2[i] = EOWm2->GetBinContent(i,k);
arr_EOW0[i] = EOW0->GetBinContent(i,k);
arr_EOW1[i] = EOW1->GetBinContent(i,k);
arr_EOW2[i] = EOW2->GetBinContent(i,k);


//Fudicial cut efficiencies
arr_FCEWm1[i] = FCEWm1->GetBinContent(i,k);
arr_FCEWm2[i] = FCEWm2->GetBinContent(i,k);
arr_FCEW0[i] = FCEW0->GetBinContent(i,k);
arr_FCEW1[i] = FCEW1->GetBinContent(i,k);
arr_FCEW2[i] = FCEW2->GetBinContent(i,k);


//RPC occupancy from DT
arr_RODWm1[i] = RODWm1->GetBinContent(i,k);
arr_RODWm2[i] = RODWm2->GetBinContent(i,k);
arr_RODW0[i] = RODW0->GetBinContent(i,k);
arr_RODW1[i] = RODW1->GetBinContent(i,k);
arr_RODW2[i] = RODW2->GetBinContent(i,k);


//RPC occupancy
arr_ROWm1[i] = ROWm1->GetBinContent(i,k);
arr_ROWm2[i] = ROWm2->GetBinContent(i,k);
arr_ROW0[i] = ROW0->GetBinContent(i,k);
arr_ROW1[i] = ROW1->GetBinContent(i,k);
arr_ROW2[i] = ROW2->GetBinContent(i,k);


//total efficiencies
arr_TEWm1[i] = TEWm1->GetBinContent(i,k);
arr_TEWm2[i] = TEWm2->GetBinContent(i,k);
arr_TEW0[i] = TEW0->GetBinContent(i,k);
arr_TEW1[i] = TEW1->GetBinContent(i,k);
arr_TEW2[i] = TEW2->GetBinContent(i,k);

	

//------------------------------------------------------------------------
//Fill output hist
//------------------------------------------------------------------------


//average cluster size
out_ACSWm1->Fill(arr_ACSWm1[i]);
out_ACSWm2->Fill(arr_ACSWm2[i]);
out_ACSW0->Fill(arr_ACSW0[i]);
out_ACSW1->Fill(arr_ACSW1[i]);
out_ACSW2->Fill(arr_ACSW2[i]);

//average residuals
out_ARWm1->Fill(arr_ARWm1[i]);
out_ARWm2->Fill(arr_ARWm2[i]);
out_ARW0->Fill(arr_ARW0[i]);
out_ARW1->Fill(arr_ARW1[i]);
out_ARW2->Fill(arr_ARW2[i]);

//average strip efficiencies
out_ASEWm1->Fill(arr_ASEWm1[i]);
out_ASEWm2->Fill(arr_ASEWm2[i]);
out_ASEW0->Fill(arr_ASEW0[i]);
out_ASEW1->Fill(arr_ASEW1[i]);
out_ASEW2->Fill(arr_ASEW2[i]);

//expected occupancy
out_EOWm1->Fill(arr_EOWm1[i]);
out_EOWm2->Fill(arr_EOWm2[i]);
out_EOW0->Fill(arr_EOW0[i]);
out_EOW1->Fill(arr_EOW1[i]);
out_EOW2->Fill(arr_EOW2[i]);


//Fudicial cut efficiencies
out_FCEWm1->Fill(arr_FCEWm1[i]);
out_FCEWm2->Fill(arr_FCEWm2[i]);
out_FCEW0->Fill(arr_FCEW0[i]);
out_FCEW1->Fill(arr_FCEW1[i]);
out_FCEW2->Fill(arr_FCEW2[i]);

//RPC occupancy from DT
out_RODWm1->Fill(arr_RODWm1[i]);
out_RODWm2->Fill(arr_RODWm2[i]);
out_RODW0->Fill(arr_RODW0[i]);
out_RODW1->Fill(arr_RODW1[i]);
out_RODW2->Fill(arr_RODW2[i]);


//RPC occupancy
out_ROWm1->Fill(arr_ROWm1[i]);
out_ROWm2->Fill(arr_ROWm2[i]);
out_ROW0->Fill(arr_ROW0[i]);
out_ROW1->Fill(arr_ROW1[i]);
out_ROW2->Fill(arr_ROW2[i]);


//total efficiencies
out_TEWm1->Fill(arr_TEWm1[i]);
out_TEWm2->Fill(arr_TEWm2[i]);
out_TEW0->Fill(arr_TEW0[i]);
out_TEW1->Fill(arr_TEW1[i]);
out_TEW2->Fill(arr_TEW2[i]);




//h2->Draw();
	}
}

TFile *out = new TFile(outfilename.c_str(), "RECREATE");
        out->mkdir("Barrel");
//        out->mkdir("Endcap");

//------------------------------------------------------------------------
//Write hist to directory
//------------------------------------------------------------------------


        out->cd("/Barrel");
        out->mkdir("Barrel/average_cluster_size/");
out->cd("Barrel/average_cluster_size/");

//average cluster size
out_ACSWm1->Write();
out_ACSWm2->Write();
out_ACSW0->Write();
out_ACSW1->Write();
out_ACSW2->Write();

out->mkdir("Barrel/average_residuals/");
out->cd("Barrel/average_residuals/");
//average residuals
out_ARWm1->Write();
out_ARWm2->Write();
out_ARW0->Write();
out_ARW1->Write();
out_ARW2->Write();


out->mkdir("Barrel/average_strip_efficiencies/");
out->cd("Barrel/average_strip_efficiencies/");
//average strip efficiencies
out_ASEWm1->Write();
out_ASEWm2->Write();
out_ASEW0->Write();
out_ASEW1->Write();
out_ASEW2->Write();

out->mkdir("Barrel/expected_occupancy/");
out->cd("Barrel/expected_occupancy/");
//expected occupancy
out_EOWm1->Write();
out_EOWm2->Write();
out_EOW0->Write();
out_EOW1->Write();
out_EOW2->Write();

out->mkdir("Barrel/Fudicial_cut_efficiencies/");
out->cd("Barrel/Fudicial_cut_efficiencies/");
//Fudicial cut efficiencies
out_FCEWm1->Write();
out_FCEWm2->Write();
out_FCEW0->Write();
out_FCEW1->Write();
out_FCEW2->Write();


out->mkdir("Barrel/RPC_occupancy_from_DT/");
out->cd("Barrel/RPC_occupancy_from_DT/");
//RPC occupancy from DT
out_RODWm1->Write();
out_RODWm2->Write();
out_RODW0->Write();
out_RODW1->Write();
out_RODW2->Write();

out->mkdir("Barrel/RPC_occupancy/");
out->cd("Barrel/RPC_occupancy/");
//RPC occupancy
out_ROWm1->Write();
out_ROWm2->Write();
out_ROW0->Write();
out_ROW1->Write();
out_ROW2->Write();

out->mkdir("Barrel/Total_efficiencies/");
out->cd("Barrel/Total_efficiencies/");
//total efficiencies
out_TEWm1->Write();
out_TEWm2->Write();
out_TEW0->Write();
out_TEW1->Write();
out_TEW2->Write();
	
	
	
	
//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------
//Endacap
//----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------

//Open Endcap directory
TDirectory* dir_endcap = (TDirectory*)f1->Get("Endcap");

//------------------------------------------------------------------------
//Define input 2D hist
//------------------------------------------------------------------------

TH2F *ACSDm1, *ACSDm2, *ACSDm3, *ACSDm4, *ACSD4, *ACSD3, *ACSD1, *ACSD2;       //average cluster size
TH2F *ARDm1, *ARDm2, *ARDm3, *ARDm4, *ARD4, *ARD3, *ARD1, *ARD2;                       //average residuals
TH2F *ASEDm1, *ASEDm2, *ASEDm3, *ASEDm4, *ASED4, *ASED3, *ASED1, *ASED2;          //average strip efficiencies
TH2F *EODm1, *EODm2, *EODm3, *EODm4, *EOD4, *EOD3, *EOD1, *EOD2;                       //expected occupancy
TH2F *FCEDm1, *FCEDm2, *FCEDm3, *FCEDm4, *FCED4, *FCED3, *FCED1, *FCED2;             //Fudicial cut efficiencies
TH2F *RODDm1, *RODDm2, *RODDm3, *RODDm4, *RODD4, *RODD3, *RODD1, *RODD2;             //RPC occupancy from DT
TH2F *RODm1, *RODm2, *RODm3, *RODm4, *ROD4, *ROD3, *ROD1, *ROD2;             //RPC occupancy
TH2F *TEDm1, *TEDm2, *TEDm3, *TEDm4, *TED4, *TED3, *TED1, *TED2;             //total efficiencies



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



//average residuals
dir_endcap->GetObject("AverageResidualsD-1",ARDm1);
dir_endcap->GetObject("AverageResidualsD-2",ARDm2);
dir_endcap->GetObject("AverageResidualsD-3",ARDm3);
dir_endcap->GetObject("AverageResidualsD-4",ARDm4);
dir_endcap->GetObject("AverageResidualsD1",ARD1);
dir_endcap->GetObject("AverageResidualsD2",ARD2);
dir_endcap->GetObject("AverageResidualsD3",ARD3);
dir_endcap->GetObject("AverageResidualsD4",ARD4);


//average strip efficiencies
dir_endcap->GetObject("AverageStripEffD-1",ASEDm1);
dir_endcap->GetObject("AverageStripEffD-2",ASEDm2);
dir_endcap->GetObject("AverageStripEffD-3",ASEDm3);
dir_endcap->GetObject("AverageStripEffD-4",ASEDm4);
dir_endcap->GetObject("AverageStripEffD1",ASED1);
dir_endcap->GetObject("AverageStripEffD2",ASED2);
dir_endcap->GetObject("AverageStripEffD3",ASED3);
dir_endcap->GetObject("AverageStripEffD4",ASED4);


//expected occupancy
dir_endcap->GetObject("ExpOccD-1",EODm1);
dir_endcap->GetObject("ExpOccD-2",EODm2);
dir_endcap->GetObject("ExpOccD-3",EODm3);
dir_endcap->GetObject("ExpOccD-4",EODm4);
dir_endcap->GetObject("ExpOccD1",EOD1);
dir_endcap->GetObject("ExpOccD2",EOD2);
dir_endcap->GetObject("ExpOccD3",EOD3);
dir_endcap->GetObject("ExpOccD4",EOD4);


//Fudicial cut efficiencies
dir_endcap->GetObject("FiducialCutEffD-1",FCEDm1);
dir_endcap->GetObject("FiducialCutEffD-2",FCEDm2);
dir_endcap->GetObject("FiducialCutEffD-3",FCEDm3);
dir_endcap->GetObject("FiducialCutEffD-4",FCEDm4);
dir_endcap->GetObject("FiducialCutEffD1",FCED1);
dir_endcap->GetObject("FiducialCutEffD2",FCED2);
dir_endcap->GetObject("FiducialCutEffD3",FCED3);
dir_endcap->GetObject("FiducialCutEffD4",FCED4);


//RPC occupancy from DT
dir_endcap->GetObject("RPCOccD-1",RODDm1);
dir_endcap->GetObject("RPCOccD-2",RODDm2);
dir_endcap->GetObject("RPCOccD-3",RODDm3);
dir_endcap->GetObject("RPCOccD-4",RODDm4);
dir_endcap->GetObject("RPCOccD1",RODD1);
dir_endcap->GetObject("RPCOccD2",RODD2);
dir_endcap->GetObject("RPCOccD3",RODD3);
dir_endcap->GetObject("RPCOccD4",RODD4);


//RPC occupancy
dir_endcap->GetObject("RPCRealOccD-1",RODm1);
dir_endcap->GetObject("RPCRealOccD-2",RODm2);
dir_endcap->GetObject("RPCRealOccD-3",RODm3);
dir_endcap->GetObject("RPCRealOccD-4",RODm4);
dir_endcap->GetObject("RPCRealOccD1",ROD1);
dir_endcap->GetObject("RPCRealOccD2",ROD2);
dir_endcap->GetObject("RPCRealOccD3",ROD3);
dir_endcap->GetObject("RPCRealOccD4",ROD4);


//total efficiencies
dir_endcap->GetObject("TotalEffD-1",TEDm1);
dir_endcap->GetObject("TotalEffD-2",TEDm2);
dir_endcap->GetObject("TotalEffD-3",TEDm3);
dir_endcap->GetObject("TotalEffD-4",TEDm4);
dir_endcap->GetObject("TotalEffD1",TED1);
dir_endcap->GetObject("TotalEffD2",TED2);
dir_endcap->GetObject("TotalEffD3",TED3);
dir_endcap->GetObject("TotalEffD4",TED4);

//------------------------------------------------------------------------


//------------------------------------------------------------------------
//define output hist
//------------------------------------------------------------------------


//average cluster size
TH1F *out_ACSDm1 = new TH1F("AverageCLSD-1","Cluster Size Mean Value - Disk -1",16,0.0,4.0);
TH1F *out_ACSDm2 = new TH1F("AverageCLSD-2","Cluster Size Mean Value - Disk -2",16,0.0,4.0);
TH1F *out_ACSDm3 = new TH1F("AverageCLSD-3","Cluster Size Mean Value - Disk -3",16,0.0,4.0);
TH1F *out_ACSDm4 = new TH1F("AverageCLSD-4","Cluster Size Mean Value - Disk -4",16,0.0,4.0);
TH1F *out_ACSD1 = new TH1F("AverageCLSD1","Cluster Size Mean Value - Disk 1",16,0.0,4.0);
TH1F *out_ACSD2 = new TH1F("AverageCLSD2","Cluster Size Mean Value - Disk 2",16,0.0,4.0);
TH1F *out_ACSD3 = new TH1F("AverageCLSD3","Cluster Size Mean Value - Disk 3",16,0.0,4.0);
TH1F *out_ACSD4 = new TH1F("AverageCLSD4","Cluster Size Mean Value - Disk 4",16,0.0,4.0);


//average residuals
TH1F *out_ARDm1 = new TH1F("AverageResidualsD-1","Residuals Mean Value - Disk -1",16,-4.0,4.0);
TH1F *out_ARDm2 = new TH1F("AverageResidualsD-2","Residuals Mean Value - Disk -2",16,-4.0,4.0);
TH1F *out_ARDm3 = new TH1F("AverageResidualsD-3","Residuals Mean Value - Disk -3",16,-4.0,4.0);
TH1F *out_ARDm4 = new TH1F("AverageResidualsD-4","Residuals Mean Value - Disk -4",16,-4.0,4.0);
TH1F *out_ARD1 = new TH1F("AverageResidualsD1","Residuals Mean Value - Disk 1",16,-4.0,4.0);
TH1F *out_ARD2 = new TH1F("AverageResidualsD2","Residuals Mean Value - Disk 2",16,-4.0,4.0);
TH1F *out_ARD3 = new TH1F("AverageResidualsD3","Residuals Mean Value - Disk 3",16,-4.0,4.0);
TH1F *out_ARD4 = new TH1F("AverageResidualsD4","Residuals Mean Value - Disk 4",16,-4.0,4.0);


//average strip efficiencies
TH1F *out_ASEDm1 = new TH1F("AverageStripEffD-1","Average Strip Efficiency - Disk -1",101,-0.5,100.5);
TH1F *out_ASEDm2 = new TH1F("AverageStripEffD-2","Average Strip Efficiency - Disk -2",101,-0.5,100.5);
TH1F *out_ASEDm3 = new TH1F("AverageStripEffD-3","Average Strip Efficiency - Disk -3",101,-0.5,100.5);
TH1F *out_ASEDm4 = new TH1F("AverageStripEffD-4","Average Strip Efficiency - Disk -4",101,-0.5,100.5);
TH1F *out_ASED1 = new TH1F("AverageStripEffD1","Average Strip Efficiency - Disk 1",101,-0.5,100.5);
TH1F *out_ASED2 = new TH1F("AverageStripEffD2","Average Strip Efficiency - Disk 2",101,-0.5,100.5);
TH1F *out_ASED3 = new TH1F("AverageStripEffD3","Average Strip Efficiency - Disk 3",101,-0.5,100.5);
TH1F *out_ASED4 = new TH1F("AverageStripEffD4","Average Strip Efficiency - Disk 4",101,-0.5,100.5);


//expected occupancy
TH1F *out_EODm1 = new TH1F("ExpOccD-1","Expected Occupancy - Disk -1",41,0.0,410000.0);
TH1F *out_EODm2 = new TH1F("ExpOccD-2","Expected Occupancy - Disk -2",41,0.0,410000.0);
TH1F *out_EODm3 = new TH1F("ExpOccD-3","Expected Occupancy - Disk -3",41,0.0,410000.0);
TH1F *out_EODm4 = new TH1F("ExpOccD-4","Expected Occupancy - Disk -4",41,0.0,410000.0);
TH1F *out_EOD1 = new TH1F("ExpOccD1","Expected Occupancy - Disk 1",41,0.0,410000.0);
TH1F *out_EOD2 = new TH1F("ExpOccD2","Expected Occupancy - Disk 2",41,0.0,410000.0);
TH1F *out_EOD3 = new TH1F("ExpOccD3","Expected Occupancy - Disk 3",41,0.0,410000.0);
TH1F *out_EOD4 = new TH1F("ExpOccD4","Expected Occupancy - Disk 4",41,0.0,410000.0);


//Fudicial cut efficiencies
TH1F *out_FCEDm1 = new TH1F("FiducialCutEffD-1","Fiducial Cut Efficiency - Disk -1",101,-0.5,100.5);
TH1F *out_FCEDm2 = new TH1F("FiducialCutEffD-2","Fiducial Cut Efficiency - Disk -2",101,-0.5,100.5);
TH1F *out_FCEDm3 = new TH1F("FiducialCutEffD-3","Fiducial Cut Efficiency - Disk -3",101,-0.5,100.5);
TH1F *out_FCEDm4 = new TH1F("FiducialCutEffD-4","Fiducial Cut Efficiency - Disk -4",101,-0.5,100.5);
TH1F *out_FCED1 = new TH1F("FiducialCutEffD1","Fiducial Cut Efficiency - Disk 1",101,-0.5,100.5);
TH1F *out_FCED2 = new TH1F("FiducialCutEffD2","Fiducial Cut Efficiency - Disk 2",101,-0.5,100.5);
TH1F *out_FCED3 = new TH1F("FiducialCutEffD3","Fiducial Cut Efficiency - Disk 3",101,-0.5,100.5);
TH1F *out_FCED4 = new TH1F("FiducialCutEffD4","Fiducial Cut Efficiency - Disk 4",101,-0.5,100.5);


//RPC occupancy from DT
TH1F *out_RODDm1 = new TH1F("RPCOccD-1","RPC Occupancy from DT - Disk -1",41,0.0,410000.0);
TH1F *out_RODDm2 = new TH1F("RPCOccD-2","RPC Occupancy from DT - Disk -2",41,0.0,410000.0);
TH1F *out_RODDm3 = new TH1F("RPCOccD-3","RPC Occupancy from DT - Disk -3",41,0.0,410000.0);
TH1F *out_RODDm4 = new TH1F("RPCOccD-4","RPC Occupancy from DT - Disk -4",41,0.0,410000.0);
TH1F *out_RODD1 = new TH1F("RPCOccD1","RPC Occupancy from DT - Disk 1",41,0.0,410000.0);
TH1F *out_RODD2 = new TH1F("RPCOccD2","RPC Occupancy from DT - Disk 2",41,0.0,410000.0);
TH1F *out_RODD3 = new TH1F("RPCOccD3","RPC Occupancy from DT - Disk 3",41,0.0,410000.0);
TH1F *out_RODD4 = new TH1F("RPCOccD4","RPC Occupancy from DT - Disk 4",41,0.0,410000.0);


//RPC occupancy
TH1F *out_RODm1 = new TH1F("RPCRealOccD-1","RPC Occupancy - Disk -1",100,0.0,1000000.0);
TH1F *out_RODm2 = new TH1F("RPCRealOccD-2","RPC Occupancy - Disk -2",100,0.0,1000000.0);
TH1F *out_RODm3 = new TH1F("RPCRealOccD-3","RPC Occupancy - Disk -3",100,0.0,1000000.0);
TH1F *out_RODm4 = new TH1F("RPCRealOccD-4","RPC Occupancy - Disk -4",100,0.0,1000000.0);
TH1F *out_ROD1 = new TH1F("RPCRealOccD1","RPC Occupancy - Disk 1",100,0.0,1000000.0);
TH1F *out_ROD2 = new TH1F("RPCRealOccD2","RPC Occupancy - Disk 2",100,0.0,1000000.0);
TH1F *out_ROD3 = new TH1F("RPCRealOccD3","RPC Occupancy - Disk 3",100,0.0,1000000.0);
TH1F *out_ROD4 = new TH1F("RPCRealOccD4","RPC Occupancy - Disk 4",100,0.0,1000000.0);


//total efficiencies
TH1F *out_TEDm1 = new TH1F("TotalEffD-1","Total Efficiency - Disk -1",101,-0.5,100.5);
TH1F *out_TEDm2 = new TH1F("TotalEffD-2","Total Efficiency - Disk -2",101,-0.5,100.5);
TH1F *out_TEDm3 = new TH1F("TotalEffD-3","Total Efficiency - Disk -3",101,-0.5,100.5);
TH1F *out_TEDm4 = new TH1F("TotalEffD-4","Total Efficiency - Disk -4",101,-0.5,100.5);
TH1F *out_TED1 = new TH1F("TotalEffD1","Total Efficiency - Disk 1",101,-0.5,100.5);
TH1F *out_TED2 = new TH1F("TotalEffD2","Total Efficiency - Disk 2",101,-0.5,100.5);
TH1F *out_TED3 = new TH1F("TotalEffD3","Total Efficiency - Disk 3",101,-0.5,100.5);
TH1F *out_TED4 = new TH1F("TotalEffD4","Total Efficiency - Disk 4",101,-0.5,100.5);


//------------------------------------------------------------------------
//Define array to be filled in output
//------------------------------------------------------------------------

float arr_ACSDm1[500], arr_ACSDm2[500], arr_ACSDm3[500], arr_ACSDm4[500], arr_ACSD4[500], arr_ACSD3[500], arr_ACSD1[500], arr_ACSD2[500];       //average cluster size
float arr_ARDm1[500], arr_ARDm2[500], arr_ARDm3[500], arr_ARDm4[500], arr_ARD4[500], arr_ARD3[500], arr_ARD1[500], arr_ARD2[500];                       //average residuals
float arr_ASEDm1[500], arr_ASEDm2[500], arr_ASEDm3[500], arr_ASEDm4[500], arr_ASED4[500], arr_ASED3[500], arr_ASED1[500], arr_ASED2[500];          //average strip efficiencies
float arr_EODm1[500], arr_EODm2[500], arr_EODm3[500], arr_EODm4[500], arr_EOD4[500], arr_EOD3[500], arr_EOD1[500], arr_EOD2[500];                       //expected occupancy
float arr_FCEDm1[500], arr_FCEDm2[500], arr_FCEDm3[500], arr_FCEDm4[500], arr_FCED4[500], arr_FCED3[500], arr_FCED1[500], arr_FCED2[500];             //Fudicial cut efficiencies
float arr_RODDm1[500], arr_RODDm2[500], arr_RODDm3[500], arr_RODDm4[500], arr_RODD4[500], arr_RODD3[500], arr_RODD1[500], arr_RODD2[500];             //RPC occupancy from DT
float arr_RODm1[500], arr_RODm2[500], arr_RODm3[500], arr_RODm4[500], arr_ROD4[500], arr_ROD3[500], arr_ROD1[500], arr_ROD2[500];             //RPC occupancy
float arr_TEDm1[500], arr_TEDm2[500], arr_TEDm3[500], arr_TEDm4[500], arr_TED4[500], arr_TED3[500], arr_TED1[500], arr_TED2[500];             //total efficiencies

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


//average residuals
arr_ARDm1[j] = ARDm1->GetBinContent(j,l);
arr_ARDm2[j] = ARDm2->GetBinContent(j,l);
arr_ARDm3[j] = ARDm3->GetBinContent(j,l);
arr_ARDm4[j] = ARDm4->GetBinContent(j,l);
arr_ARD1[j] = ARD1->GetBinContent(j,l);
arr_ARD2[j] = ARD2->GetBinContent(j,l);
arr_ARD3[j] = ARD3->GetBinContent(j,l);
arr_ARD4[j] = ARD4->GetBinContent(j,l);


//average strip efficiencies
arr_ASEDm1[j] = ASEDm1->GetBinContent(j,l);
arr_ASEDm2[j] = ASEDm2->GetBinContent(j,l);
arr_ASEDm3[j] = ASEDm3->GetBinContent(j,l);
arr_ASEDm4[j] = ASEDm4->GetBinContent(j,l);
arr_ASED1[j] = ASED1->GetBinContent(j,l);
arr_ASED2[j] = ASED2->GetBinContent(j,l);
arr_ASED3[j] = ASED3->GetBinContent(j,l);
arr_ASED4[j] = ASED4->GetBinContent(j,l);


//expected occupancy
arr_EODm1[j] = EODm1->GetBinContent(j,l);
arr_EODm2[j] = EODm2->GetBinContent(j,l);
arr_EODm3[j] = EODm3->GetBinContent(j,l);
arr_EODm4[j] = EODm4->GetBinContent(j,l);
arr_EOD1[j] = EOD1->GetBinContent(j,l);
arr_EOD2[j] = EOD2->GetBinContent(j,l);
arr_EOD3[j] = EOD3->GetBinContent(j,l);
arr_EOD4[j] = EOD4->GetBinContent(j,l);


//Fudicial cut efficiencies
arr_FCEDm1[j] = FCEDm1->GetBinContent(j,l);
arr_FCEDm2[j] = FCEDm2->GetBinContent(j,l);
arr_FCEDm3[j] = FCEDm3->GetBinContent(j,l);
arr_FCEDm4[j] = FCEDm4->GetBinContent(j,l);
arr_FCED1[j] = FCED1->GetBinContent(j,l);
arr_FCED2[j] = FCED2->GetBinContent(j,l);
arr_FCED3[j] = FCED3->GetBinContent(j,l);
arr_FCED4[j] = FCED4->GetBinContent(j,l);


//RPC occupancy from DT
arr_RODDm1[j] = RODDm1->GetBinContent(j,l);
arr_RODDm2[j] = RODDm2->GetBinContent(j,l);
arr_RODDm3[j] = RODDm3->GetBinContent(j,l);
arr_RODDm4[j] = RODDm4->GetBinContent(j,l);
arr_RODD1[j] = RODD1->GetBinContent(j,l);
arr_RODD2[j] = RODD2->GetBinContent(j,l);
arr_RODD3[j] = RODD3->GetBinContent(j,l);
arr_RODD4[j] = RODD4->GetBinContent(j,l);


//RPC occupancy
arr_RODm1[j] = RODm1->GetBinContent(j,l);
arr_RODm2[j] = RODm2->GetBinContent(j,l);
arr_RODm3[j] = RODm3->GetBinContent(j,l);
arr_RODm4[j] = RODm4->GetBinContent(j,l);
arr_ROD1[j] = ROD1->GetBinContent(j,l);
arr_ROD2[j] = ROD2->GetBinContent(j,l);
arr_ROD3[j] = ROD3->GetBinContent(j,l);
arr_ROD4[j] = ROD4->GetBinContent(j,l);


//total efficiencies
arr_TEDm1[j] = TEDm1->GetBinContent(j,l);
arr_TEDm2[j] = TEDm2->GetBinContent(j,l);
arr_TEDm3[j] = TEDm3->GetBinContent(j,l);
arr_TEDm4[j] = TEDm4->GetBinContent(j,l);
arr_TED1[j] = TED1->GetBinContent(j,l);
arr_TED2[j] = TED2->GetBinContent(j,l);
arr_TED3[j] = TED3->GetBinContent(j,l);
arr_TED4[j] = TED4->GetBinContent(j,l);



//------------------------------------------------------------------------
//Fill output hist
//------------------------------------------------------------------------


//average cluster size
out_ACSDm1->Fill(arr_ACSDm1[j]);
out_ACSDm2->Fill(arr_ACSDm2[j]);
out_ACSDm3->Fill(arr_ACSDm3[j]);
out_ACSDm4->Fill(arr_ACSDm4[j]);
out_ACSD1->Fill(arr_ACSD1[j]);
out_ACSD2->Fill(arr_ACSD2[j]);
out_ACSD3->Fill(arr_ACSD3[j]);
out_ACSD4->Fill(arr_ACSD4[j]);


//average residuals
out_ARDm1->Fill(arr_ARDm1[j]);
out_ARDm2->Fill(arr_ARDm2[j]);
out_ARDm3->Fill(arr_ARDm3[j]);
out_ARDm4->Fill(arr_ARDm4[j]);
out_ARD1->Fill(arr_ARD1[j]);
out_ARD2->Fill(arr_ARD2[j]);
out_ARD3->Fill(arr_ARD3[j]);
out_ARD4->Fill(arr_ARD4[j]);


//average strip efficiencies
out_ASEDm1->Fill(arr_ASEDm1[j]);
out_ASEDm2->Fill(arr_ASEDm2[j]);
out_ASEDm3->Fill(arr_ASEDm3[j]);
out_ASEDm4->Fill(arr_ASEDm4[j]);
out_ASED1->Fill(arr_ASED1[j]);
out_ASED2->Fill(arr_ASED2[j]);
out_ASED3->Fill(arr_ASED3[j]);
out_ASED4->Fill(arr_ASED4[j]);


//expected occupancy
out_EODm1->Fill(arr_EODm1[j]);
out_EODm2->Fill(arr_EODm2[j]);
out_EODm3->Fill(arr_EODm3[j]);
out_EODm4->Fill(arr_EODm4[j]);
out_EOD1->Fill(arr_EOD1[j]);
out_EOD2->Fill(arr_EOD2[j]);
out_EOD3->Fill(arr_EOD3[j]);
out_EOD4->Fill(arr_EOD4[j]);


//Fudicial cut efficiencies
out_FCEDm1->Fill(arr_FCEDm1[j]);
out_FCEDm2->Fill(arr_FCEDm2[j]);
out_FCEDm3->Fill(arr_FCEDm3[j]);
out_FCEDm4->Fill(arr_FCEDm4[j]);
out_FCED1->Fill(arr_FCED1[j]);
out_FCED2->Fill(arr_FCED2[j]);
out_FCED3->Fill(arr_FCED3[j]);
out_FCED4->Fill(arr_FCED4[j]);


//RPC occupancy from DT
out_RODDm1->Fill(arr_RODDm1[j]);
out_RODDm2->Fill(arr_RODDm2[j]);
out_RODDm3->Fill(arr_RODDm3[j]);
out_RODDm4->Fill(arr_RODDm4[j]);
out_RODD1->Fill(arr_RODD1[j]);
out_RODD2->Fill(arr_RODD2[j]);
out_RODD3->Fill(arr_RODD3[j]);
out_RODD4->Fill(arr_RODD4[j]);


//RPC occupancy
out_RODm1->Fill(arr_RODm1[j]);
out_RODm2->Fill(arr_RODm2[j]);
out_RODm3->Fill(arr_RODm3[j]);
out_RODm4->Fill(arr_RODm4[j]);
out_ROD1->Fill(arr_ROD1[j]);
out_ROD2->Fill(arr_ROD2[j]);
out_ROD3->Fill(arr_ROD3[j]);
out_ROD4->Fill(arr_ROD4[j]);


//total efficiencies
out_TEDm1->Fill(arr_TEDm1[j]);
out_TEDm2->Fill(arr_TEDm2[j]);
out_TEDm3->Fill(arr_TEDm3[j]);
out_TEDm4->Fill(arr_TEDm4[j]);
out_TED1->Fill(arr_TED1[j]);
out_TED2->Fill(arr_TED2[j]);
out_TED3->Fill(arr_TED3[j]);
out_TED4->Fill(arr_TED4[j]);

	}
}

//------------------------------------------------------------------------
//Write hist to directory
//------------------------------------------------------------------------


//TFile *out = new TFile("endcap_output_run_339579.root", "RECREATE");

/*	out1->mkdir("Endcap");
        out1->cd("/Endcap");
        out->mkdir("Endacp/averageclustersize/");
out->cd("Endcap/averageclustersize/");
*/


        out->mkdir("Endcap");
        out->cd("/Endcap");
        out->mkdir("Endcap/average_cluster_size/");
out->cd("Endcap/average_cluster_size/");

//average cluster size
out_ACSDm1->Write();
out_ACSDm2->Write();
out_ACSDm3->Write();
out_ACSDm4->Write();
out_ACSD1->Write();
out_ACSD2->Write();
out_ACSD3->Write();
out_ACSD4->Write();


out->mkdir("Endcap/average_residuals/");
out->cd("Endcap/average_residuals/");
//average residuals
out_ARDm1->Write();
out_ARDm2->Write();
out_ARDm3->Write();
out_ARDm4->Write();
out_ARD1->Write();
out_ARD2->Write();
out_ARD3->Write();
out_ARD4->Write();


out->mkdir("Endcap/average_strip_efficiencies/");
out->cd("Endcap/average_strip_efficiencies/");
//average strip efficiencies
out_ASEDm1->Write();
out_ASEDm2->Write();
out_ASEDm3->Write();
out_ASEDm4->Write();
out_ASED1->Write();
out_ASED2->Write();
out_ASED3->Write();
out_ASED4->Write();


out->mkdir("Endcap/expected_occupancy/");
out->cd("Endcap/expected_occupancy/");
//expected occupancy
out_EODm1->Write();
out_EODm2->Write();
out_EODm3->Write();
out_EODm4->Write();
out_EOD1->Write();
out_EOD2->Write();
out_EOD3->Write();
out_EOD4->Write();


out->mkdir("Endcap/Fudicial_cut_efficiencies/");
out->cd("Endcap/Fudicial_cut_efficiencies/");
//Fudicial cut efficiencies
out_FCEDm1->Write();
out_FCEDm2->Write();
out_FCEDm3->Write();
out_FCEDm4->Write();
out_FCED1->Write();
out_FCED2->Write();
out_FCED3->Write();
out_FCED4->Write();


out->mkdir("Endcap/RPC_occupancy_from_DT/");
out->cd("Endcap/RPC_occupancy_from_DT/");
//RPC occupancy from DT
out_RODDm1->Write();
out_RODDm2->Write();
out_RODDm3->Write();
out_RODDm4->Write();
out_RODD1->Write();
out_RODD2->Write();
out_RODD3->Write();
out_RODD4->Write();


out->mkdir("Endcap/RPC_occupancy/");
out->cd("Endcap/RPC_occupancy/");
//RPC occupancy
out_RODm1->Write();
out_RODm2->Write();
out_RODm3->Write();
out_RODm4->Write();
out_ROD1->Write();
out_ROD2->Write();
out_ROD3->Write();
out_ROD4->Write();


out->mkdir("Endcap/Total_efficiencies/");
out->cd("Endcap/Total_efficiencies/");
//total efficiencies
out_TEDm1->Write();
out_TEDm2->Write();
out_TEDm3->Write();
out_TEDm4->Write();
out_TED1->Write();
out_TED2->Write();
out_TED3->Write();
out_TED4->Write();





}


