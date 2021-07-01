# ComparisonStudies
#These set of instructions can be run on local machine, lxplus or lpc

--------------------------------------------------------------------------------------------------
I. COMPARISON BETWEEN MWGRs AND RUN2
--------------------------------------------------------------------------------------------------

> cd ComparisonStudies/ComparisonStudy/
> root -l

--------------------------------------------------------------------------------------------------

**1. Distribution for variables**

> .x drawplotsMWGR.c("<input root file>", "<output root file>")

where input root file is the output obtained from offline analysis code

  Example:  .x drawplotsMWGR.c("SummaryAnalyzeEfficiency_Express2021_339579.root", "output_run339579.root")

  

**2. Comparison of distribution between MWGRs:**

> .x drawComparisonPlots.c("<input file1>", "<legend Entry name1>", "<input file2>", "<legend Entry name2>", "<output file>")

where input root file is the output obtained from 1st step
  
Example:  .x drawComparisonPlots.c("output_run339579.root", "2021 MWGR#1 Run:339579", "output_run340323.root", "2021 MWGR#2 Run:340323", "output_comparisonplots_MWGR1andMWGR2.root")


  
**3. Delta Fiducial Cut Efficiency ( MWGR2-MWGR1)**

> .x drawDeltaFiducialCutEff.c("<input file1>", "<input file2>", "<output file>")

where input file is the output root file obtained from offline analysis code
  
Example:  .x drawDeltaFiducialCutEff.c("SummaryAnalyzeEfficiency_Express2021_339579.root", "SummaryAnalyzeEfficiency_Express2021_340323.root", "output_DeltaFiducialEff_MWGR2_MWGR1.root")


--------------------------------------------------------------------------------------------------
II.  To obtain 2D plots (Average Cluster Size vs Fiducial Efficiency, RPC occupancy/(Total # Lumisections) vs Fiducial Efficiency and Average Cluster Size vs RPC occupancy/(Total # Lumisections)):
--------------------------------------------------------------------------------------------------

> cd ComparisonStudies/2D_plots/
> root -l

--------------------------------------------------------------------------------------------------

**4. For each Wheel of Barrel**

.x draw2DplotsMWGR_barrelWheel.c("<input root file>", <Total # Lumisections>, "<output root file>")

where input root file is the output obtained from offline analysis code. Total #Lumisections can be found on http://cmsoms.cern.ch
  
Example:  .x draw2DplotsMWGR_barrelWheel.c("SummaryAnalyzeEfficiency_Express2021_339579.root", 21167, "2Doutput_barrelWheel_run339579.root")

  

**5. For entire Barrel**

> .x draw2DplotsMWGR_barrel.c("<input root file>", <Total # Lumisections>, "<output root file>")

where input root file is the output obtained from offline analysis code. Total #Lumisections can be found on http://cmsoms.cern.ch
  
Example:  .x draw2DplotsMWGR_barrel.c("SummaryAnalyzeEfficiency_Express2021_339579.root", 21167, "2Doutput_barrel_run339579.root")


  
**6. For each Disk of Endcap**

> .x draw2DplotsMWGR_endcapDisk.c("<input root file>", <Total # Lumisections>, "<output root file>")

where input root file is the output obtained from offline analysis code. Total #Lumisections can be found on http://cmsoms.cern.ch

Example:  .x draw2DplotsMWGR_endcapDisk.c("SummaryAnalyzeEfficiency_Express2021_339579.root", 21167, "2Doutput_endcapDisk_run339579.root")


  
**7. For entire Endcap**

> .x draw2DplotsMWGR_endcap.c("<input root file>", <Total # Lumisections>, "<output root file>")

where input root file is the output obtained from offline analysis code. Total #Lumisections can be found on http://cmsoms.cern.ch

Example:  .x draw2DplotsMWGR_endcap.c("SummaryAnalyzeEfficiency_Express2021_339579.root", 21167, "2Doutput_endcap_run339579.root")


--------------------------------------------------------------------------------------------------
III. For the given list of chambers (SG chambers):
--------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------
> cd ComparisonStudies/SG_ChambersStudy/
> root -l

--------------------------------------------------------------------------------------------------

**8. Distribution for variables**

To obtain distribution of various variables for the given list of chambers, we  first need to update the list of chambers in code. For barrel list is named as listofchambers_barrel[] and listofchambers_endcap[] is for endcap.

> .x drawChamberPlots_barrel.c("<input file1>", "<output root file>", “<output txt file with all chambers>”, “<output txt file with FCE>90 >”)

where input file is the output root file obtained from offline analysis code

Example:  .x drawChamberPlots_barrel.c("SummaryAnalyzeEfficiency_Express2021_339579.root", "SG_output_run339579.root", "SG_output_ListForChambers_run339579.txt", "SG_output_ChambersWithFCE_GT_90_run339579.txt")

From this step, we will get output root file (distribution stored), text file containing the list of chambers along with the parameters and the list of chambers having fiducial cut efficiency > 90.

Similarly we can do for endcap using drawChamberPlots_endcap.c


  
**9. Comparison of distribution between MWGRs:**
> .x drawComparisonChamberPlots.c("<input file1>", "<legend Entry name1>", "<input file2>", "<legend Entry name2>", "<output file>")

where input root file is the output obtained from 8th step

Example:  .x drawComparisonChamberPlots.c("SG_output_run339579.root", "2021 MWGR#1 Run:339579", "SG_output_run340323.root", "2021 MWGR#2 Run:340323", "output_comparisonplots.root")

--------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------

