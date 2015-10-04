// This macros creates the histogram plots and ratio plots, which are needed for further analysis.
// It contains 4 functions:
//    1. PlotHistogram() is to create the histograms for single LOW/HIGH/SINGLE intensity.
//    2. PlotHighOverLow() creates the HIGH/LOW ratio plots.
//    3. PlotSingleOverLow() creates the SINGLE/LOW ratio plots.
//    4. PlotSingleOverHigh() creates the SINGLE/HIGH ratio plots.

void PlotHistogram() {
   TFile* file = new TFile("./FullDST-HLS-NewDataForCutSensitivityAnalysis.root");
   TH1D* h_cp_HITrkActivePlanes = (TH1D*)file->Get("h_HITrkActivePlanes");
   TH1D* h_cp_HITrkMeanPh = (TH1D*)file->Get("h_HITrkMeanPh");
   TH1D* h_cp_HILowHighPh = (TH1D*)file->Get("h_HILowHighPh");
   TH1D* h_cp_HITrkPhFrac = (TH1D*)file->Get("h_HITrkPhFrac");
   TH1D* h_cp_HITrkActivePlanes_S = (TH1D*)file->Get("h_HITrkActivePlanes_S");
   TH1D* h_cp_HITrkMeanPh_S = (TH1D*)file->Get("h_HITrkMeanPh_S");
   TH1D* h_cp_HILowHighPh_S = (TH1D*)file->Get("h_HILowHighPh_S");
   TH1D* h_cp_HITrkPhFrac_S = (TH1D*)file->Get("h_HITrkPhFrac_S");
   TH1D* h_cp_HITrkActivePlanes_B = (TH1D*)file->Get("h_HITrkActivePlanes_B");
   TH1D* h_cp_HITrkMeanPh_B = (TH1D*)file->Get("h_HITrkMeanPh_B");
   TH1D* h_cp_HILowHighPh_B = (TH1D*)file->Get("h_HILowHighPh_B");
   TH1D* h_cp_HITrkPhFrac_B = (TH1D*)file->Get("h_HITrkPhFrac_B");
   TH1D* h_cp_LITrkActivePlanes = (TH1D*)file->Get("h_LITrkActivePlanes");
   TH1D* h_cp_LITrkMeanPh = (TH1D*)file->Get("h_LITrkMeanPh");
   TH1D* h_cp_LILowHighPh = (TH1D*)file->Get("h_LILowHighPh");
   TH1D* h_cp_LITrkPhFrac = (TH1D*)file->Get("h_LITrkPhFrac");
   TH1D* h_cp_LITrkActivePlanes_S = (TH1D*)file->Get("h_LITrkActivePlanes_S");
   TH1D* h_cp_LITrkMeanPh_S = (TH1D*)file->Get("h_LITrkMeanPh_S");
   TH1D* h_cp_LILowHighPh_S = (TH1D*)file->Get("h_LILowHighPh_S");
   TH1D* h_cp_LITrkPhFrac_S = (TH1D*)file->Get("h_LITrkPhFrac_S");
   TH1D* h_cp_LITrkActivePlanes_B = (TH1D*)file->Get("h_LITrkActivePlanes_B");
   TH1D* h_cp_LITrkMeanPh_B = (TH1D*)file->Get("h_LITrkMeanPh_B");
   TH1D* h_cp_LILowHighPh_B = (TH1D*)file->Get("h_LILowHighPh_B");
   TH1D* h_cp_LITrkPhFrac_B = (TH1D*)file->Get("h_LITrkPhFrac_B");
   TH1D* h_cp_SITrkActivePlanes = (TH1D*)file->Get("h_SITrkActivePlanes");
   TH1D* h_cp_SITrkMeanPh = (TH1D*)file->Get("h_SITrkMeanPh");
   TH1D* h_cp_SILowHighPh = (TH1D*)file->Get("h_SILowHighPh");
   TH1D* h_cp_SITrkPhFrac = (TH1D*)file->Get("h_SITrkPhFrac");
   TH1D* h_cp_SITrkActivePlanes_S = (TH1D*)file->Get("h_SITrkActivePlanes_S");
   TH1D* h_cp_SITrkMeanPh_S = (TH1D*)file->Get("h_SITrkMeanPh_S");
   TH1D* h_cp_SILowHighPh_S = (TH1D*)file->Get("h_SILowHighPh_S");
   TH1D* h_cp_SITrkPhFrac_S = (TH1D*)file->Get("h_SITrkPhFrac_S");
   TH1D* h_cp_SITrkActivePlanes_B = (TH1D*)file->Get("h_SITrkActivePlanes_B");
   TH1D* h_cp_SITrkMeanPh_B = (TH1D*)file->Get("h_SITrkMeanPh_B");
   TH1D* h_cp_SILowHighPh_B = (TH1D*)file->Get("h_SILowHighPh_B");
   TH1D* h_cp_SITrkPhFrac_B = (TH1D*)file->Get("h_SITrkPhFrac_B");

   // TrkActivePlanes
   TCanvas* c_HI_TrkActivePlanes = new TCanvas();
   h_cp_HITrkActivePlanes_S->SetFillStyle(3003);
   h_cp_HITrkActivePlanes_S->SetFillColor(kRed+2);
   h_cp_HITrkActivePlanes_B->SetFillStyle(3003);
   h_cp_HITrkActivePlanes_B->SetFillColor(kBlue+2);
   h_cp_HITrkActivePlanes->Draw();
   h_cp_HITrkActivePlanes_S->Draw("sames");
   h_cp_HITrkActivePlanes_B->Draw("sames");
   h_cp_HITrkActivePlanes->SetStats(0);
   h_cp_HITrkActivePlanes_S->SetStats(0);
   h_cp_HITrkActivePlanes_B->SetStats(0);
   h_cp_HITrkActivePlanes->GetXaxis()->SetTitle("Number of Active Planes");
   h_cp_HITrkActivePlanes->GetYaxis()->SetTitle("Counts");
   h_cp_HITrkActivePlanes->GetYaxis()->SetTitleOffset(1.4);
   h_cp_HITrkActivePlanes->GetXaxis()->CenterTitle();
   h_cp_HITrkActivePlanes->GetYaxis()->CenterTitle();
   TLegend* leg_1 = new TLegend(0.7,0.75,0.9,0.9);
   leg_1->AddEntry(h_cp_HITrkActivePlanes, "Signal + Background","f");
   leg_1->AddEntry(h_cp_HITrkActivePlanes_S, "Signal","f");
   leg_1->AddEntry(h_cp_HITrkActivePlanes_B, "Background","f");
   leg_1->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_HI_TrkActivePlanes->SaveAs("HI_TrkActivePlanes.eps");

   TCanvas* c_LI_TrkActivePlanes = new TCanvas();
   h_cp_LITrkActivePlanes_S->SetFillStyle(3003);
   h_cp_LITrkActivePlanes_S->SetFillColor(kRed+2);
   h_cp_LITrkActivePlanes_B->SetFillStyle(3003);
   h_cp_LITrkActivePlanes_B->SetFillColor(kBlue+2);
   h_cp_LITrkActivePlanes->Draw();
   h_cp_LITrkActivePlanes_S->Draw("sames");
   h_cp_LITrkActivePlanes_B->Draw("sames");
   h_cp_LITrkActivePlanes->SetStats(0);
   h_cp_LITrkActivePlanes_S->SetStats(0);
   h_cp_LITrkActivePlanes_B->SetStats(0);
   h_cp_LITrkActivePlanes->GetXaxis()->SetTitle("Number of Active Planes");
   h_cp_LITrkActivePlanes->GetYaxis()->SetTitle("Counts");
   h_cp_LITrkActivePlanes->GetYaxis()->SetTitleOffset(1.4);
   h_cp_LITrkActivePlanes->GetXaxis()->CenterTitle();
   h_cp_LITrkActivePlanes->GetYaxis()->CenterTitle();
   TLegend* leg_2 = new TLegend(0.7,0.75,0.9,0.9);
   leg_2->AddEntry(h_cp_LITrkActivePlanes, "Signal + Background","f");
   leg_2->AddEntry(h_cp_LITrkActivePlanes_S, "Signal","f");
   leg_2->AddEntry(h_cp_LITrkActivePlanes_B, "Background","f");
   leg_2->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_LI_TrkActivePlanes->SaveAs("LI_TrkActivePlanes.eps");

   TCanvas* c_SI_TrkActivePlanes = new TCanvas();
   h_cp_SITrkActivePlanes_S->SetFillStyle(3003);
   h_cp_SITrkActivePlanes_S->SetFillColor(kRed+2);
   h_cp_SITrkActivePlanes_B->SetFillStyle(3003);
   h_cp_SITrkActivePlanes_B->SetFillColor(kBlue+2);
   h_cp_SITrkActivePlanes->Draw();
   h_cp_SITrkActivePlanes_S->Draw("sames");
   h_cp_SITrkActivePlanes_B->Draw("sames");
   h_cp_SITrkActivePlanes->SetStats(0);
   h_cp_SITrkActivePlanes_S->SetStats(0);
   h_cp_SITrkActivePlanes_B->SetStats(0);
   h_cp_SITrkActivePlanes->GetXaxis()->SetTitle("Number of Active Planes");
   h_cp_SITrkActivePlanes->GetYaxis()->SetTitle("Counts");
   h_cp_SITrkActivePlanes->GetYaxis()->SetTitleOffset(1.4);
   h_cp_SITrkActivePlanes->GetXaxis()->CenterTitle();
   h_cp_SITrkActivePlanes->GetYaxis()->CenterTitle();
   TLegend* leg_3 = new TLegend(0.7,0.75,0.9,0.9);
   leg_3->AddEntry(h_cp_SITrkActivePlanes, "Signal + Background","f");
   leg_3->AddEntry(h_cp_SITrkActivePlanes_S, "Signal","f");
   leg_3->AddEntry(h_cp_SITrkActivePlanes_B, "Background","f");
   leg_3->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_SI_TrkActivePlanes->SaveAs("SI_TrkActivePlanes.eps");






   // TrkMeanPh
   TCanvas* c_HI_TrkMeanPh = new TCanvas();
   h_cp_HITrkMeanPh_S->SetFillStyle(3003);
   h_cp_HITrkMeanPh_S->SetFillColor(kRed+2);
   h_cp_HITrkMeanPh_B->SetFillStyle(3003);
   h_cp_HITrkMeanPh_B->SetFillColor(kBlue+2);
   h_cp_HITrkMeanPh->Draw();
   h_cp_HITrkMeanPh_S->Draw("sames");
   h_cp_HITrkMeanPh_B->Draw("sames");
   h_cp_HITrkMeanPh->SetStats(0);
   h_cp_HITrkMeanPh_S->SetStats(0);
   h_cp_HITrkMeanPh_B->SetStats(0);
   h_cp_HITrkMeanPh->GetXaxis()->SetTitle("Mean Pulse Height");
   h_cp_HITrkMeanPh->GetYaxis()->SetTitle("Counts");
   h_cp_HITrkMeanPh->GetYaxis()->SetTitleOffset(1.4);
   h_cp_HITrkMeanPh->GetXaxis()->CenterTitle();
   h_cp_HITrkMeanPh->GetYaxis()->CenterTitle();
   TLegend* leg_4 = new TLegend(0.6,0.65,0.85,0.85);
   leg_4->AddEntry(h_cp_HITrkMeanPh, "Signal + Background","f");
   leg_4->AddEntry(h_cp_HITrkMeanPh_S, "Signal","f");
   leg_4->AddEntry(h_cp_HITrkMeanPh_B, "Background","f");
   leg_4->Draw();
   leg_4->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_HI_TrkMeanPh->SaveAs("HI_TrkMeanPh.eps");

   TCanvas* c_LI_TrkMeanPh = new TCanvas();
   h_cp_LITrkMeanPh_S->SetFillStyle(3003);
   h_cp_LITrkMeanPh_S->SetFillColor(kRed+2);
   h_cp_LITrkMeanPh_B->SetFillStyle(3003);
   h_cp_LITrkMeanPh_B->SetFillColor(kBlue+2);
   h_cp_LITrkMeanPh->Draw();
   h_cp_LITrkMeanPh_S->Draw("sames");
   h_cp_LITrkMeanPh_B->Draw("sames");
   h_cp_LITrkMeanPh->SetStats(0);
   h_cp_LITrkMeanPh_S->SetStats(0);
   h_cp_LITrkMeanPh_B->SetStats(0);
   h_cp_LITrkMeanPh->GetXaxis()->SetTitle("Mean Pulse Height");
   h_cp_LITrkMeanPh->GetYaxis()->SetTitle("Counts");
   h_cp_LITrkMeanPh->GetYaxis()->SetTitleOffset(1.4);
   h_cp_LITrkMeanPh->GetXaxis()->CenterTitle();
   h_cp_LITrkMeanPh->GetYaxis()->CenterTitle();
   TLegend* leg_5 = new TLegend(0.6,0.65,0.85,0.85);
   leg_5->AddEntry(h_cp_LITrkMeanPh, "Signal + Background","f");
   leg_5->AddEntry(h_cp_LITrkMeanPh_S, "Signal","f");
   leg_5->AddEntry(h_cp_LITrkMeanPh_B, "Background","f");
   leg_5->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_LI_TrkMeanPh->SaveAs("LI_TrkMeanPh.eps");

   TCanvas* c_SI_TrkMeanPh = new TCanvas();
   h_cp_SITrkMeanPh_S->SetFillStyle(3003);
   h_cp_SITrkMeanPh_S->SetFillColor(kRed+2);
   h_cp_SITrkMeanPh_B->SetFillStyle(3003);
   h_cp_SITrkMeanPh_B->SetFillColor(kBlue+2);
   h_cp_SITrkMeanPh->Draw();
   h_cp_SITrkMeanPh_S->Draw("sames");
   h_cp_SITrkMeanPh_B->Draw("sames");
   h_cp_SITrkMeanPh->SetStats(0);
   h_cp_SITrkMeanPh_S->SetStats(0);
   h_cp_SITrkMeanPh_B->SetStats(0);
   h_cp_SITrkMeanPh->GetXaxis()->SetTitle("Mean Pulse Height");
   h_cp_SITrkMeanPh->GetYaxis()->SetTitle("Counts");
   h_cp_SITrkMeanPh->GetYaxis()->SetTitleOffset(1.4);
   h_cp_SITrkMeanPh->GetXaxis()->CenterTitle();
   h_cp_SITrkMeanPh->GetYaxis()->CenterTitle();
   TLegend* leg_6 = new TLegend(0.6,0.65,0.85,0.85);
   leg_6->AddEntry(h_cp_SITrkMeanPh, "Signal + Background","f");
   leg_6->AddEntry(h_cp_SITrkMeanPh_S, "Signal","f");
   leg_6->AddEntry(h_cp_SITrkMeanPh_B, "Background","f");
   leg_6->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_SI_TrkMeanPh->SaveAs("SI_TrkMeanPh.eps");




   // LowHighPh
   TCanvas* c_HI_LowHighPh = new TCanvas();
   h_cp_HILowHighPh_S->SetFillStyle(3003);
   h_cp_HILowHighPh_S->SetFillColor(kRed+2);
   h_cp_HILowHighPh_B->SetFillStyle(3003);
   h_cp_HILowHighPh_B->SetFillColor(kBlue+2);
   h_cp_HILowHighPh->Draw();
   h_cp_HILowHighPh_S->Draw("sames");
   h_cp_HILowHighPh_B->Draw("sames");
   h_cp_HILowHighPh->SetStats(0);
   h_cp_HILowHighPh_S->SetStats(0);
   h_cp_HILowHighPh_B->SetStats(0);
   h_cp_HILowHighPh->GetXaxis()->SetTitle("Low/High Pulse Height Ratio");
   h_cp_HILowHighPh->GetYaxis()->SetTitle("Counts");
   h_cp_HILowHighPh->GetYaxis()->SetTitleOffset(1.4);
   h_cp_HILowHighPh->GetXaxis()->CenterTitle();
   h_cp_HILowHighPh->GetYaxis()->CenterTitle();
   TLegend* leg_7 = new TLegend(0.6,0.65,0.85,0.85);
   leg_7->AddEntry(h_cp_HILowHighPh, "Signal + Background","f");
   leg_7->AddEntry(h_cp_HILowHighPh_S, "Signal","f");
   leg_7->AddEntry(h_cp_HILowHighPh_B, "Background","f");
   leg_7->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_HI_LowHighPh->SaveAs("HI_LowHighPh.eps");

   TCanvas* c_LI_LowHighPh = new TCanvas();
   h_cp_LILowHighPh_S->SetFillStyle(3003);
   h_cp_LILowHighPh_S->SetFillColor(kRed+2);
   h_cp_LILowHighPh_B->SetFillStyle(3003);
   h_cp_LILowHighPh_B->SetFillColor(kBlue+2);
   h_cp_LILowHighPh->Draw();
   h_cp_LILowHighPh_S->Draw("sames");
   h_cp_LILowHighPh_B->Draw("sames");
   h_cp_LILowHighPh->SetStats(0);
   h_cp_LILowHighPh_S->SetStats(0);
   h_cp_LILowHighPh_B->SetStats(0);
   h_cp_LILowHighPh->GetXaxis()->SetTitle("Low/High Pulse Height Ratio");
   h_cp_LILowHighPh->GetYaxis()->SetTitle("Counts");
   h_cp_LILowHighPh->GetYaxis()->SetTitleOffset(1.4);
   h_cp_LILowHighPh->GetXaxis()->CenterTitle();
   h_cp_LILowHighPh->GetYaxis()->CenterTitle();
   TLegend* leg_8 = new TLegend(0.6,0.65,0.85,0.85);
   leg_8->AddEntry(h_cp_LILowHighPh, "Signal + Background","f");
   leg_8->AddEntry(h_cp_LILowHighPh_S, "Signal","f");
   leg_8->AddEntry(h_cp_LILowHighPh_B, "Background","f");
   leg_8->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_LI_LowHighPh->SaveAs("LI_LowHighPh.eps");

   TCanvas* c_SI_LowHighPh = new TCanvas();
   h_cp_SILowHighPh_S->SetFillStyle(3003);
   h_cp_SILowHighPh_S->SetFillColor(kRed+2);
   h_cp_SILowHighPh_B->SetFillStyle(3003);
   h_cp_SILowHighPh_B->SetFillColor(kBlue+2);
   h_cp_SILowHighPh->Draw();
   h_cp_SILowHighPh_S->Draw("sames");
   h_cp_SILowHighPh_B->Draw("sames");
   h_cp_SILowHighPh->SetStats(0);
   h_cp_SILowHighPh_S->SetStats(0);
   h_cp_SILowHighPh_B->SetStats(0);
   h_cp_SILowHighPh->GetXaxis()->SetTitle("Low/High Pulse Height Ratio");
   h_cp_SILowHighPh->GetYaxis()->SetTitle("Counts");
   h_cp_SILowHighPh->GetYaxis()->SetTitleOffset(1.4);
   h_cp_SILowHighPh->GetXaxis()->CenterTitle();
   h_cp_SILowHighPh->GetYaxis()->CenterTitle();
   TLegend* leg_9 = new TLegend(0.6,0.65,0.85,0.85);
   leg_9->AddEntry(h_cp_SILowHighPh, "Signal + Background","f");
   leg_9->AddEntry(h_cp_SILowHighPh_S, "Signal","f");
   leg_9->AddEntry(h_cp_SILowHighPh_B, "Background","f");
   leg_9->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_SI_LowHighPh->SaveAs("SI_LowHighPh.eps");



   // TrkPhFrac
   TCanvas* c_HI_TrkPhFrac = new TCanvas();
   h_cp_HITrkPhFrac_S->SetFillStyle(3002);
   h_cp_HITrkPhFrac_S->SetFillColor(kRed+2);
   h_cp_HITrkPhFrac_B->SetFillStyle(3001);
   h_cp_HITrkPhFrac_B->SetFillColor(kBlue+2);
   h_cp_HITrkPhFrac->Draw();
   h_cp_HITrkPhFrac_S->Draw("sames");
   h_cp_HITrkPhFrac_B->Draw("sames");
   h_cp_HITrkPhFrac->SetStats(0);
   h_cp_HITrkPhFrac_S->SetStats(0);
   h_cp_HITrkPhFrac_B->SetStats(0);
   h_cp_HITrkPhFrac->GetXaxis()->SetTitle("Fraction of Track Hits");
   h_cp_HITrkPhFrac->GetYaxis()->SetTitle("Counts");
   h_cp_HITrkPhFrac->GetYaxis()->SetTitleOffset(1.4);
   h_cp_HITrkPhFrac->GetXaxis()->CenterTitle();
   h_cp_HITrkPhFrac->GetYaxis()->CenterTitle();
   TLegend* leg_10 = new TLegend(0.2,0.65,0.45,0.85);
   leg_10->AddEntry(h_cp_HITrkPhFrac, "Signal + Background","f");
   leg_10->AddEntry(h_cp_HITrkPhFrac_S, "Signal","f");
   leg_10->AddEntry(h_cp_HITrkPhFrac_B, "Background","f");
   leg_10->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_HI_TrkPhFrac->SaveAs("HI_TrkPhFrac.eps");

   TCanvas* c_LI_TrkPhFrac = new TCanvas();
   h_cp_LITrkPhFrac_S->SetFillStyle(3002);
   h_cp_LITrkPhFrac_S->SetFillColor(kRed+2);
   h_cp_LITrkPhFrac_B->SetFillStyle(3001);
   h_cp_LITrkPhFrac_B->SetFillColor(kBlue+2);
   h_cp_LITrkPhFrac->Draw();
   h_cp_LITrkPhFrac_S->Draw("sames");
   h_cp_LITrkPhFrac_B->Draw("sames");
   h_cp_LITrkPhFrac->SetStats(0);
   h_cp_LITrkPhFrac_S->SetStats(0);
   h_cp_LITrkPhFrac_B->SetStats(0);
   h_cp_LITrkPhFrac->GetXaxis()->SetTitle("Fraction of Track Hits");
   h_cp_LITrkPhFrac->GetYaxis()->SetTitle("Counts");
   h_cp_LITrkPhFrac->GetYaxis()->SetTitleOffset(1.4);
   h_cp_LITrkPhFrac->GetXaxis()->CenterTitle();
   h_cp_LITrkPhFrac->GetYaxis()->CenterTitle();
   TLegend* leg_11 = new TLegend(0.2,0.65,0.45,0.85);
   leg_11->AddEntry(h_cp_LITrkPhFrac, "Signal + Background","f");
   leg_11->AddEntry(h_cp_LITrkPhFrac_S, "Signal","f");
   leg_11->AddEntry(h_cp_LITrkPhFrac_B, "Background","f");
   leg_11->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_LI_TrkPhFrac->SaveAs("LI_TrkPhFrac.eps");

   TCanvas* c_SI_TrkPhFrac = new TCanvas();
   h_cp_SITrkPhFrac_S->SetFillStyle(3002);
   h_cp_SITrkPhFrac_S->SetFillColor(kRed+2);
   h_cp_SITrkPhFrac_B->SetFillStyle(3001);
   h_cp_SITrkPhFrac_B->SetFillColor(kBlue+2);
   h_cp_SITrkPhFrac->Draw();
   h_cp_SITrkPhFrac_S->Draw("sames");
   h_cp_SITrkPhFrac_B->Draw("sames");
   h_cp_SITrkPhFrac->SetStats(0);
   h_cp_SITrkPhFrac_S->SetStats(0);
   h_cp_SITrkPhFrac_B->SetStats(0);
   h_cp_SITrkPhFrac->GetXaxis()->SetTitle("Fraction of Track Hits");
   h_cp_SITrkPhFrac->GetYaxis()->SetTitle("Counts");
   h_cp_SITrkPhFrac->GetYaxis()->SetTitleOffset(1.4);
   h_cp_SITrkPhFrac->GetXaxis()->CenterTitle();
   h_cp_SITrkPhFrac->GetYaxis()->CenterTitle();
   TLegend* leg_12 = new TLegend(0.2,0.65,0.45,0.85);
   leg_12->AddEntry(h_cp_SITrkPhFrac, "Signal + Background","f");
   leg_12->AddEntry(h_cp_SITrkPhFrac_S, "Signal","f");
   leg_12->AddEntry(h_cp_SITrkPhFrac_B, "Background","f");
   leg_12->Draw();
   gPad->SetLogy();
   //gPad->SetGrid();
   c_SI_TrkPhFrac->SaveAs("SI_TrkPhFrac.eps");

}


void PlotHighOverLow() {
   TFile* file = new TFile("./FullDST-HLS-NewDataForCutSensitivityAnalysis.root");
   // HIGH
   TH1D* h_cp_HITrkActivePlanes = (TH1D*)file->Get("h_HITrkActivePlanes");
   TH1D* h_cp_HITrkMeanPh = (TH1D*)file->Get("h_HITrkMeanPh");
   TH1D* h_cp_HILowHighPh = (TH1D*)file->Get("h_HILowHighPh");
   TH1D* h_cp_HITrkPhFrac = (TH1D*)file->Get("h_HITrkPhFrac");
   TH1D* h_cp_HITrkActivePlanes_S = (TH1D*)file->Get("h_HITrkActivePlanes_S");
   TH1D* h_cp_HITrkMeanPh_S = (TH1D*)file->Get("h_HITrkMeanPh_S");
   TH1D* h_cp_HILowHighPh_S = (TH1D*)file->Get("h_HILowHighPh_S");
   TH1D* h_cp_HITrkPhFrac_S = (TH1D*)file->Get("h_HITrkPhFrac_S");
   TH1D* h_cp_HITrkActivePlanes_B = (TH1D*)file->Get("h_HITrkActivePlanes_B");
   TH1D* h_cp_HITrkMeanPh_B = (TH1D*)file->Get("h_HITrkMeanPh_B");
   TH1D* h_cp_HILowHighPh_B = (TH1D*)file->Get("h_HILowHighPh_B");
   TH1D* h_cp_HITrkPhFrac_B = (TH1D*)file->Get("h_HITrkPhFrac_B");
   // LOW
   TH1D* h_cp_LITrkActivePlanes = (TH1D*)file->Get("h_LITrkActivePlanes");
   TH1D* h_cp_LITrkMeanPh = (TH1D*)file->Get("h_LITrkMeanPh");
   TH1D* h_cp_LILowHighPh = (TH1D*)file->Get("h_LILowHighPh");
   TH1D* h_cp_LITrkPhFrac = (TH1D*)file->Get("h_LITrkPhFrac");
   TH1D* h_cp_LITrkActivePlanes_S = (TH1D*)file->Get("h_LITrkActivePlanes_S");
   TH1D* h_cp_LITrkMeanPh_S = (TH1D*)file->Get("h_LITrkMeanPh_S");
   TH1D* h_cp_LILowHighPh_S = (TH1D*)file->Get("h_LILowHighPh_S");
   TH1D* h_cp_LITrkPhFrac_S = (TH1D*)file->Get("h_LITrkPhFrac_S");
   TH1D* h_cp_LITrkActivePlanes_B = (TH1D*)file->Get("h_LITrkActivePlanes_B");
   TH1D* h_cp_LITrkMeanPh_B = (TH1D*)file->Get("h_LITrkMeanPh_B");
   TH1D* h_cp_LILowHighPh_B = (TH1D*)file->Get("h_LILowHighPh_B");
   TH1D* h_cp_LITrkPhFrac_B = (TH1D*)file->Get("h_LITrkPhFrac_B");


// TrkActivePlanes
   TCanvas* c_HL_TrkActivePlanes_S = new TCanvas();
   h_cp_HITrkActivePlanes_S->Sumw2();
   h_cp_HITrkActivePlanes_S->Divide(h_cp_HITrkActivePlanes);
   h_cp_LITrkActivePlanes_S->Sumw2();
   h_cp_LITrkActivePlanes_S->Divide(h_cp_LITrkActivePlanes);
   h_cp_HITrkActivePlanes_S->Divide(h_cp_LITrkActivePlanes_S);
   h_cp_HITrkActivePlanes_S->SetTitle("High/Low Ratio of TrkActivePlanes (Signal)");
   h_cp_HITrkActivePlanes_S->GetXaxis()->SetTitle("Number of Planes");
   h_cp_HITrkActivePlanes_S->SetStats(0);
   h_cp_HITrkActivePlanes_S->Draw();
   c_HL_TrkActivePlanes_S->SaveAs("HL_TrkActivePlanes_S.eps");

   TCanvas* c_HL_TrkActivePlanes_B = new TCanvas();
   h_cp_HITrkActivePlanes_B->Sumw2();
   h_cp_HITrkActivePlanes_B->Divide(h_cp_HITrkActivePlanes);
   h_cp_LITrkActivePlanes_B->Sumw2();
   h_cp_LITrkActivePlanes_B->Divide(h_cp_LITrkActivePlanes);
   h_cp_HITrkActivePlanes_B->Divide(h_cp_LITrkActivePlanes_B);
   h_cp_HITrkActivePlanes_B->SetTitle("High/Low Ratio of TrkActivePlanes (Background)");
   h_cp_HITrkActivePlanes_B->GetXaxis()->SetTitle("Number of Planes");
   h_cp_HITrkActivePlanes_B->SetStats(0);
   h_cp_HITrkActivePlanes_B->Draw();
   c_HL_TrkActivePlanes_B->SaveAs("HL_TrkActivePlanes_B.eps");

// TrkMeanPh
   TCanvas* c_HL_TrkMeanPh_S = new TCanvas();
   h_cp_HITrkMeanPh_S->Sumw2();
   h_cp_HITrkMeanPh_S->Divide(h_cp_HITrkMeanPh);
   h_cp_LITrkMeanPh_S->Sumw2();
   h_cp_LITrkMeanPh_S->Divide(h_cp_LITrkMeanPh);
   h_cp_HITrkMeanPh_S->Divide(h_cp_LITrkMeanPh_S);
   h_cp_HITrkMeanPh_S->SetTitle("High/Low Ratio of TrkMeanPh (Signal)");
   h_cp_HITrkMeanPh_S->GetXaxis()->SetTitle("Mean Pulse Height");
   h_cp_HITrkMeanPh_S->SetStats(0);
   h_cp_HITrkMeanPh_S->Draw();
   c_HL_TrkMeanPh_S->SaveAs("HL_TrkMeanPh_S.eps");

   TCanvas* c_HL_TrkMeanPh_B = new TCanvas();
   h_cp_HITrkMeanPh_B->Sumw2();
   h_cp_HITrkMeanPh_B->Divide(h_cp_HITrkMeanPh);
   h_cp_LITrkMeanPh_B->Sumw2();
   h_cp_LITrkMeanPh_B->Divide(h_cp_LITrkMeanPh);
   h_cp_HITrkMeanPh_B->Divide(h_cp_LITrkMeanPh_B);
   h_cp_HITrkMeanPh_B->SetTitle("High/Low Ratio of TrkMeanPh (Background)");
   h_cp_HITrkMeanPh_B->GetXaxis()->SetTitle("Mean Pulse Height");
   h_cp_HITrkMeanPh_B->SetStats(0);
   h_cp_HITrkMeanPh_B->Draw();
   c_HL_TrkMeanPh_B->SaveAs("HL_TrkMeanPh_B.eps");

// LowHighPh
   TCanvas* c_HL_LowHighPh_S = new TCanvas();
   h_cp_HILowHighPh_S->Sumw2();
   h_cp_HILowHighPh_S->Divide(h_cp_HILowHighPh);
   h_cp_LILowHighPh_S->Sumw2();
   h_cp_LILowHighPh_S->Divide(h_cp_LILowHighPh);
   h_cp_HILowHighPh_S->Divide(h_cp_LILowHighPh_S);
   h_cp_HILowHighPh_S->SetTitle("High/Low Ratio of LowHighPh (Signal)");
   h_cp_HILowHighPh_S->GetXaxis()->SetTitle("Low/High Pulse Height Ratio");
   h_cp_HILowHighPh_S->SetStats(0);
   h_cp_HILowHighPh_S->Draw();
   c_HL_LowHighPh_S->SaveAs("HL_LowHighPh_S.eps");

   TCanvas* c_HL_LowHighPh_B = new TCanvas();
   h_cp_HILowHighPh_B->Sumw2();
   h_cp_HILowHighPh_B->Divide(h_cp_HILowHighPh);
   h_cp_LILowHighPh_B->Sumw2();
   h_cp_LILowHighPh_B->Divide(h_cp_LILowHighPh);
   h_cp_HILowHighPh_B->Divide(h_cp_LILowHighPh_B);
   h_cp_HILowHighPh_B->SetTitle("High/Low Ratio of LowHighPh (Background)");
   h_cp_HILowHighPh_B->GetXaxis()->SetTitle("Low/High Pulse Height Ratio");
   h_cp_HILowHighPh_B->SetStats(0);
   h_cp_HILowHighPh_B->Draw();
   c_HL_LowHighPh_B->SaveAs("HL_LowHighPh_B.eps");

// TrkPhFrac
   TCanvas* c_HL_TrkPhFrac_S = new TCanvas();
   h_cp_HITrkPhFrac_S->Sumw2();
   h_cp_HITrkPhFrac_S->Divide(h_cp_HITrkPhFrac);
   h_cp_LITrkPhFrac_S->Sumw2();
   h_cp_LITrkPhFrac_S->Divide(h_cp_LITrkPhFrac);
   h_cp_HITrkPhFrac_S->Divide(h_cp_LITrkPhFrac_S);
   h_cp_HITrkPhFrac_S->SetTitle("High/Low Ratio of TrkPhFrac (Signal)");
   h_cp_HITrkPhFrac_S->GetXaxis()->SetTitle("Fraction of Track Hits");
   h_cp_HITrkPhFrac_S->SetStats(0);
   h_cp_HITrkPhFrac_S->Draw();
   c_HL_TrkPhFrac_S->SaveAs("HL_TrkPhFrac_S.eps");

   TCanvas* c_HL_TrkPhFrac_B = new TCanvas();
   h_cp_HITrkPhFrac_B->Sumw2();
   h_cp_HITrkPhFrac_B->Divide(h_cp_HITrkPhFrac);
   h_cp_LITrkPhFrac_B->Sumw2();
   h_cp_LITrkPhFrac_B->Divide(h_cp_LITrkPhFrac);
   h_cp_HITrkPhFrac_B->Divide(h_cp_LITrkPhFrac_B);
   h_cp_HITrkPhFrac_B->SetTitle("High/Low Ratio of TrkPhFrac (Background)");
   h_cp_HITrkPhFrac_B->GetXaxis()->SetTitle("Fraction of Track Hits");
   h_cp_HITrkPhFrac_B->SetStats(0);
   h_cp_HITrkPhFrac_B->Draw();
   c_HL_TrkPhFrac_B->SaveAs("HL_TrkPhFrac_B.eps");

}












void PlotSingleOverLow() {
   TFile* file = new TFile("./FullDST-HLS-NewDataForCutSensitivityAnalysis.root");
   // Single
   TH1D* h_cp_SITrkActivePlanes = (TH1D*)file->Get("h_SITrkActivePlanes");
   TH1D* h_cp_SITrkMeanPh = (TH1D*)file->Get("h_SITrkMeanPh");
   TH1D* h_cp_SILowHighPh = (TH1D*)file->Get("h_SILowHighPh");
   TH1D* h_cp_SITrkPhFrac = (TH1D*)file->Get("h_SITrkPhFrac");
   TH1D* h_cp_SITrkActivePlanes_S = (TH1D*)file->Get("h_SITrkActivePlanes_S");
   TH1D* h_cp_SITrkMeanPh_S = (TH1D*)file->Get("h_SITrkMeanPh_S");
   TH1D* h_cp_SILowHighPh_S = (TH1D*)file->Get("h_SILowHighPh_S");
   TH1D* h_cp_SITrkPhFrac_S = (TH1D*)file->Get("h_SITrkPhFrac_S");
   TH1D* h_cp_SITrkActivePlanes_B = (TH1D*)file->Get("h_SITrkActivePlanes_B");
   TH1D* h_cp_SITrkMeanPh_B = (TH1D*)file->Get("h_SITrkMeanPh_B");
   TH1D* h_cp_SILowHighPh_B = (TH1D*)file->Get("h_SILowHighPh_B");
   TH1D* h_cp_SITrkPhFrac_B = (TH1D*)file->Get("h_SITrkPhFrac_B");
   // LOW
   TH1D* h_cp_LITrkActivePlanes = (TH1D*)file->Get("h_LITrkActivePlanes");
   TH1D* h_cp_LITrkMeanPh = (TH1D*)file->Get("h_LITrkMeanPh");
   TH1D* h_cp_LILowHighPh = (TH1D*)file->Get("h_LILowHighPh");
   TH1D* h_cp_LITrkPhFrac = (TH1D*)file->Get("h_LITrkPhFrac");
   TH1D* h_cp_LITrkActivePlanes_S = (TH1D*)file->Get("h_LITrkActivePlanes_S");
   TH1D* h_cp_LITrkMeanPh_S = (TH1D*)file->Get("h_LITrkMeanPh_S");
   TH1D* h_cp_LILowHighPh_S = (TH1D*)file->Get("h_LILowHighPh_S");
   TH1D* h_cp_LITrkPhFrac_S = (TH1D*)file->Get("h_LITrkPhFrac_S");
   TH1D* h_cp_LITrkActivePlanes_B = (TH1D*)file->Get("h_LITrkActivePlanes_B");
   TH1D* h_cp_LITrkMeanPh_B = (TH1D*)file->Get("h_LITrkMeanPh_B");
   TH1D* h_cp_LILowHighPh_B = (TH1D*)file->Get("h_LILowHighPh_B");
   TH1D* h_cp_LITrkPhFrac_B = (TH1D*)file->Get("h_LITrkPhFrac_B");


// TrkActivePlanes
   TCanvas* c_SL_TrkActivePlanes_S = new TCanvas();
   h_cp_SITrkActivePlanes_S->Sumw2();
   h_cp_SITrkActivePlanes_S->Divide(h_cp_SITrkActivePlanes);
   h_cp_LITrkActivePlanes_S->Sumw2();
   h_cp_LITrkActivePlanes_S->Divide(h_cp_LITrkActivePlanes);
   h_cp_SITrkActivePlanes_S->Divide(h_cp_LITrkActivePlanes_S);
   h_cp_SITrkActivePlanes_S->SetTitle("Single/Low Ratio of TrkActivePlanes (Signal)");
   h_cp_SITrkActivePlanes_S->GetXaxis()->SetTitle("Number of Planes");
   h_cp_SITrkActivePlanes_S->SetStats(0);
   h_cp_SITrkActivePlanes_S->Draw();
   c_SL_TrkActivePlanes_S->SaveAs("SL_TrkActivePlanes_S.eps");

   TCanvas* c_SL_TrkActivePlanes_B = new TCanvas();
   h_cp_SITrkActivePlanes_B->Sumw2();
   h_cp_SITrkActivePlanes_B->Divide(h_cp_SITrkActivePlanes);
   h_cp_LITrkActivePlanes_B->Sumw2();
   h_cp_LITrkActivePlanes_B->Divide(h_cp_LITrkActivePlanes);
   h_cp_SITrkActivePlanes_B->Divide(h_cp_LITrkActivePlanes_B);
   h_cp_SITrkActivePlanes_B->SetTitle("Single/Low Ratio of TrkActivePlanes (Background)");
   h_cp_SITrkActivePlanes_B->GetXaxis()->SetTitle("Number of Planes");
   h_cp_SITrkActivePlanes_B->SetStats(0);
   h_cp_SITrkActivePlanes_B->Draw();
   c_SL_TrkActivePlanes_B->SaveAs("SL_TrkActivePlanes_B.eps");

// TrkMeanPh
   TCanvas* c_SL_TrkMeanPh_S = new TCanvas();
   h_cp_SITrkMeanPh_S->Sumw2();
   h_cp_SITrkMeanPh_S->Divide(h_cp_SITrkMeanPh);
   h_cp_LITrkMeanPh_S->Sumw2();
   h_cp_LITrkMeanPh_S->Divide(h_cp_LITrkMeanPh);
   h_cp_SITrkMeanPh_S->Divide(h_cp_LITrkMeanPh_S);
   h_cp_SITrkMeanPh_S->SetTitle("Single/Low Ratio of TrkMeanPh (Signal)");
   h_cp_SITrkMeanPh_S->GetXaxis()->SetTitle("Mean Pulse Height");
   h_cp_SITrkMeanPh_S->SetStats(0);
   h_cp_SITrkMeanPh_S->Draw();
   c_SL_TrkMeanPh_S->SaveAs("SL_TrkMeanPh_S.eps");

   TCanvas* c_SL_TrkMeanPh_B = new TCanvas();
   h_cp_SITrkMeanPh_B->Sumw2();
   h_cp_SITrkMeanPh_B->Divide(h_cp_SITrkMeanPh);
   h_cp_LITrkMeanPh_B->Sumw2();
   h_cp_LITrkMeanPh_B->Divide(h_cp_LITrkMeanPh);
   h_cp_SITrkMeanPh_B->Divide(h_cp_LITrkMeanPh_B);
   h_cp_SITrkMeanPh_B->SetTitle("Single/Low Ratio of TrkMeanPh (Background)");
   h_cp_SITrkMeanPh_B->GetXaxis()->SetTitle("Mean Pulse Height");
   h_cp_SITrkMeanPh_B->SetStats(0);
   h_cp_SITrkMeanPh_B->Draw();
   c_SL_TrkMeanPh_B->SaveAs("SL_TrkMeanPh_B.eps");

// LowHighPh
   TCanvas* c_SL_LowHighPh_S = new TCanvas();
   h_cp_SILowHighPh_S->Sumw2();
   h_cp_SILowHighPh_S->Divide(h_cp_SILowHighPh);
   h_cp_LILowHighPh_S->Sumw2();
   h_cp_LILowHighPh_S->Divide(h_cp_LILowHighPh);
   h_cp_SILowHighPh_S->Divide(h_cp_LILowHighPh_S);
   h_cp_SILowHighPh_S->SetTitle("Single/Low Ratio of LowHighPh (Signal)");
   h_cp_SILowHighPh_S->GetXaxis()->SetTitle("Low/High Pulse Height Ratio");
   h_cp_SILowHighPh_S->SetStats(0);
   h_cp_SILowHighPh_S->Draw();
   c_SL_LowHighPh_S->SaveAs("SL_LowHighPh_S.eps");

   TCanvas* c_SL_LowHighPh_B = new TCanvas();
   h_cp_SILowHighPh_B->Sumw2();
   h_cp_SILowHighPh_B->Divide(h_cp_SILowHighPh);
   h_cp_LILowHighPh_B->Sumw2();
   h_cp_LILowHighPh_B->Divide(h_cp_LILowHighPh);
   h_cp_SILowHighPh_B->Divide(h_cp_LILowHighPh_B);
   h_cp_SILowHighPh_B->SetTitle("Single/Low Ratio of LowHighPh (Background)");
   h_cp_SILowHighPh_B->GetXaxis()->SetTitle("Low/High Pulse Height Ratio");
   h_cp_SILowHighPh_B->SetStats(0);
   h_cp_SILowHighPh_B->Draw();
   c_SL_LowHighPh_B->SaveAs("SL_LowHighPh_B.eps");

// TrkPhFrac
   TCanvas* c_SL_TrkPhFrac_S = new TCanvas();
   h_cp_SITrkPhFrac_S->Sumw2();
   h_cp_SITrkPhFrac_S->Divide(h_cp_SITrkPhFrac);
   h_cp_LITrkPhFrac_S->Sumw2();
   h_cp_LITrkPhFrac_S->Divide(h_cp_LITrkPhFrac);
   h_cp_SITrkPhFrac_S->Divide(h_cp_LITrkPhFrac_S);
   h_cp_SITrkPhFrac_S->SetTitle("Single/Low Ratio of TrkPhFrac (Signal)");
   h_cp_SITrkPhFrac_S->GetXaxis()->SetTitle("Fraction of Track Hits");
   h_cp_SITrkPhFrac_S->SetStats(0);
   h_cp_SITrkPhFrac_S->Draw();
   c_SL_TrkPhFrac_S->SaveAs("SL_TrkPhFrac_S.eps");

   TCanvas* c_SL_TrkPhFrac_B = new TCanvas();
   h_cp_SITrkPhFrac_B->Sumw2();
   h_cp_SITrkPhFrac_B->Divide(h_cp_SITrkPhFrac);
   h_cp_LITrkPhFrac_B->Sumw2();
   h_cp_LITrkPhFrac_B->Divide(h_cp_LITrkPhFrac);
   h_cp_SITrkPhFrac_B->Divide(h_cp_LITrkPhFrac_B);
   h_cp_SITrkPhFrac_B->SetTitle("Single/Low Ratio of TrkPhFrac (Background)");
   h_cp_SITrkPhFrac_B->GetXaxis()->SetTitle("Fraction of Track Hits");
   h_cp_SITrkPhFrac_B->SetStats(0);
   h_cp_SITrkPhFrac_B->Draw();
   c_SL_TrkPhFrac_B->SaveAs("SL_TrkPhFrac_B.eps");

}







void PlotSingleOverHigh() {
   TFile* file = new TFile("./FullDST-HLS-NewDataForCutSensitivityAnalysis.root");
   // Single
   TH1D* h_cp_SITrkActivePlanes = (TH1D*)file->Get("h_SITrkActivePlanes");
   TH1D* h_cp_SITrkMeanPh = (TH1D*)file->Get("h_SITrkMeanPh");
   TH1D* h_cp_SILowHighPh = (TH1D*)file->Get("h_SILowHighPh");
   TH1D* h_cp_SITrkPhFrac = (TH1D*)file->Get("h_SITrkPhFrac");
   TH1D* h_cp_SITrkActivePlanes_S = (TH1D*)file->Get("h_SITrkActivePlanes_S");
   TH1D* h_cp_SITrkMeanPh_S = (TH1D*)file->Get("h_SITrkMeanPh_S");
   TH1D* h_cp_SILowHighPh_S = (TH1D*)file->Get("h_SILowHighPh_S");
   TH1D* h_cp_SITrkPhFrac_S = (TH1D*)file->Get("h_SITrkPhFrac_S");
   TH1D* h_cp_SITrkActivePlanes_B = (TH1D*)file->Get("h_SITrkActivePlanes_B");
   TH1D* h_cp_SITrkMeanPh_B = (TH1D*)file->Get("h_SITrkMeanPh_B");
   TH1D* h_cp_SILowHighPh_B = (TH1D*)file->Get("h_SILowHighPh_B");
   TH1D* h_cp_SITrkPhFrac_B = (TH1D*)file->Get("h_SITrkPhFrac_B");
   // HIGH
   TH1D* h_cp_HITrkActivePlanes = (TH1D*)file->Get("h_HITrkActivePlanes");
   TH1D* h_cp_HITrkMeanPh = (TH1D*)file->Get("h_HITrkMeanPh");
   TH1D* h_cp_HILowHighPh = (TH1D*)file->Get("h_HILowHighPh");
   TH1D* h_cp_HITrkPhFrac = (TH1D*)file->Get("h_HITrkPhFrac");
   TH1D* h_cp_HITrkActivePlanes_S = (TH1D*)file->Get("h_HITrkActivePlanes_S");
   TH1D* h_cp_HITrkMeanPh_S = (TH1D*)file->Get("h_HITrkMeanPh_S");
   TH1D* h_cp_HILowHighPh_S = (TH1D*)file->Get("h_HILowHighPh_S");
   TH1D* h_cp_HITrkPhFrac_S = (TH1D*)file->Get("h_HITrkPhFrac_S");
   TH1D* h_cp_HITrkActivePlanes_B = (TH1D*)file->Get("h_HITrkActivePlanes_B");
   TH1D* h_cp_HITrkMeanPh_B = (TH1D*)file->Get("h_HITrkMeanPh_B");
   TH1D* h_cp_HILowHighPh_B = (TH1D*)file->Get("h_HILowHighPh_B");
   TH1D* h_cp_HITrkPhFrac_B = (TH1D*)file->Get("h_HITrkPhFrac_B");


// TrkActivePlanes
   TCanvas* c_SH_TrkActivePlanes_S = new TCanvas();
   h_cp_SITrkActivePlanes_S->Sumw2();
   h_cp_SITrkActivePlanes_S->Divide(h_cp_SITrkActivePlanes);
   h_cp_HITrkActivePlanes_S->Sumw2();
   h_cp_HITrkActivePlanes_S->Divide(h_cp_HITrkActivePlanes);
   h_cp_SITrkActivePlanes_S->Divide(h_cp_HITrkActivePlanes_S);
   h_cp_SITrkActivePlanes_S->SetTitle("Single/High Ratio of TrkActivePlanes (Signal)");
   h_cp_SITrkActivePlanes_S->GetXaxis()->SetTitle("Number of Planes");
   h_cp_SITrkActivePlanes_S->SetStats(0);
   h_cp_SITrkActivePlanes_S->Draw();
   c_SH_TrkActivePlanes_S->SaveAs("SH_TrkActivePlanes_S.eps");

   TCanvas* c_SH_TrkActivePlanes_B = new TCanvas();
   h_cp_SITrkActivePlanes_B->Sumw2();
   h_cp_SITrkActivePlanes_B->Divide(h_cp_SITrkActivePlanes);
   h_cp_HITrkActivePlanes_B->Sumw2();
   h_cp_HITrkActivePlanes_B->Divide(h_cp_HITrkActivePlanes);
   h_cp_SITrkActivePlanes_B->Divide(h_cp_HITrkActivePlanes_B);
   h_cp_SITrkActivePlanes_B->SetTitle("Single/High Ratio of TrkActivePlanes (Background)");
   h_cp_SITrkActivePlanes_B->GetXaxis()->SetTitle("Number of Planes");
   h_cp_SITrkActivePlanes_B->SetStats(0);
   h_cp_SITrkActivePlanes_B->Draw();
   c_SH_TrkActivePlanes_B->SaveAs("SH_TrkActivePlanes_B.eps");

// TrkMeanPh
   TCanvas* c_SH_TrkMeanPh_S = new TCanvas();
   h_cp_SITrkMeanPh_S->Sumw2();
   h_cp_SITrkMeanPh_S->Divide(h_cp_SITrkMeanPh);
   h_cp_HITrkMeanPh_S->Sumw2();
   h_cp_HITrkMeanPh_S->Divide(h_cp_HITrkMeanPh);
   h_cp_SITrkMeanPh_S->Divide(h_cp_HITrkMeanPh_S);
   h_cp_SITrkMeanPh_S->SetTitle("Single/High Ratio of TrkMeanPh (Signal)");
   h_cp_SITrkMeanPh_S->GetXaxis()->SetTitle("Mean Pulse Height");
   h_cp_SITrkMeanPh_S->SetStats(0);
   h_cp_SITrkMeanPh_S->Draw();
   c_SH_TrkMeanPh_S->SaveAs("SH_TrkMeanPh_S.eps");

   TCanvas* c_SH_TrkMeanPh_B = new TCanvas();
   h_cp_SITrkMeanPh_B->Sumw2();
   h_cp_SITrkMeanPh_B->Divide(h_cp_SITrkMeanPh);
   h_cp_HITrkMeanPh_B->Sumw2();
   h_cp_HITrkMeanPh_B->Divide(h_cp_HITrkMeanPh);
   h_cp_SITrkMeanPh_B->Divide(h_cp_HITrkMeanPh_B);
   h_cp_SITrkMeanPh_B->SetTitle("Single/High Ratio of TrkMeanPh (Background)");
   h_cp_SITrkMeanPh_B->GetXaxis()->SetTitle("Mean Pulse Height");
   h_cp_SITrkMeanPh_B->SetStats(0);
   h_cp_SITrkMeanPh_B->Draw();
   c_SH_TrkMeanPh_B->SaveAs("SH_TrkMeanPh_B.eps");

// LowHighPh
   TCanvas* c_SH_LowHighPh_S = new TCanvas();
   h_cp_SILowHighPh_S->Sumw2();
   h_cp_SILowHighPh_S->Divide(h_cp_SILowHighPh);
   h_cp_HILowHighPh_S->Sumw2();
   h_cp_HILowHighPh_S->Divide(h_cp_HILowHighPh);
   h_cp_SILowHighPh_S->Divide(h_cp_HILowHighPh_S);
   h_cp_SILowHighPh_S->SetTitle("Single/High Ratio of LowHighPh (Signal)");
   h_cp_SILowHighPh_S->GetXaxis()->SetTitle("Low/High Pulse Height Ratio");
   h_cp_SILowHighPh_S->SetStats(0);
   h_cp_SILowHighPh_S->Draw();
   c_SH_LowHighPh_S->SaveAs("SH_LowHighPh_S.eps");

   TCanvas* c_SH_LowHighPh_B = new TCanvas();
   h_cp_SILowHighPh_B->Sumw2();
   h_cp_SILowHighPh_B->Divide(h_cp_SILowHighPh);
   h_cp_HILowHighPh_B->Sumw2();
   h_cp_HILowHighPh_B->Divide(h_cp_HILowHighPh);
   h_cp_SILowHighPh_B->Divide(h_cp_HILowHighPh_B);
   h_cp_SILowHighPh_B->SetTitle("Single/High Ratio of LowHighPh (Background)");
   h_cp_SILowHighPh_B->GetXaxis()->SetTitle("Low/High Pulse Height Ratio");
   h_cp_SILowHighPh_B->SetStats(0);
   h_cp_SILowHighPh_B->Draw();
   c_SH_LowHighPh_B->SaveAs("SH_LowHighPh_B.eps");

// TrkPhFrac
   TCanvas* c_SH_TrkPhFrac_S = new TCanvas();
   h_cp_SITrkPhFrac_S->Sumw2();
   h_cp_SITrkPhFrac_S->Divide(h_cp_SITrkPhFrac);
   h_cp_HITrkPhFrac_S->Sumw2();
   h_cp_HITrkPhFrac_S->Divide(h_cp_HITrkPhFrac);
   h_cp_SITrkPhFrac_S->Divide(h_cp_HITrkPhFrac_S);
   h_cp_SITrkPhFrac_S->SetTitle("Single/High Ratio of TrkPhFrac (Signal)");
   h_cp_SITrkPhFrac_S->GetXaxis()->SetTitle("Fraction of Track Hits");
   h_cp_SITrkPhFrac_S->SetStats(0);
   h_cp_SITrkPhFrac_S->Draw();
   c_SH_TrkPhFrac_S->SaveAs("SH_TrkPhFrac_S.eps");

   TCanvas* c_SH_TrkPhFrac_B = new TCanvas();
   h_cp_SITrkPhFrac_B->Sumw2();
   h_cp_SITrkPhFrac_B->Divide(h_cp_SITrkPhFrac);
   h_cp_HITrkPhFrac_B->Sumw2();
   h_cp_HITrkPhFrac_B->Divide(h_cp_HITrkPhFrac);
   h_cp_SITrkPhFrac_B->Divide(h_cp_HITrkPhFrac_B);
   h_cp_SITrkPhFrac_B->SetTitle("Single/High Ratio of TrkPhFrac (Background)");
   h_cp_SITrkPhFrac_B->GetXaxis()->SetTitle("Fraction of Track Hits");
   h_cp_SITrkPhFrac_B->SetStats(0);
   h_cp_SITrkPhFrac_B->Draw();
   c_SH_TrkPhFrac_B->SaveAs("SH_TrkPhFrac_B.eps");

}
