// This macro is used to create a ROOT file for further analysis.
// It extracts the necessary variables from the MINOS+ MC DST (in this case, they are
// the four kNN variables).

void MergeData() {
   // Import ROOT Files
   TFile* HIfile = new TFile("./I4.9E14fullDST.root");
   TTree* tr_HItest = (TTree*) HIfile->Get("trainPID");
   TTree* tr_HItestS = (TTree*) HIfile->Get("trainS");
   TTree* tr_HItestB = (TTree*) HIfile->Get("trainB");

   TFile* LIfile = new TFile("./I2.5E15fullDST.root");
   TTree* tr_LItest = (TTree*) LIfile->Get("trainPID");
   TTree* tr_LItestS = (TTree*) LIfile->Get("trainS");
   TTree* tr_LItestB = (TTree*) LIfile->Get("trainB");

   TFile* SIfile = new TFile("./ISinglefullDST.root");
   TTree* tr_SItest = (TTree*) SIfile->Get("trainPID");
   TTree* tr_SItestS = (TTree*) SIfile->Get("trainS");
   TTree* tr_SItestB = (TTree*) SIfile->Get("trainB");

   // Tmp variables to read trees
   /////////////////////////////////////////////////////
   //Float_t tmp_HItestID;
   //Float_t tmp_HIroID;
   Float_t tmp_HIknn01TrkActivePlanes;
   Float_t tmp_HIknn10TrkMeanPh;
   Float_t tmp_HIknn20LowHighPh;
   Float_t tmp_HIknn40TrkPhFrac;

   Float_t tmp_HIknn01TrkActivePlanes_S;
   Float_t tmp_HIknn10TrkMeanPh_S;
   Float_t tmp_HIknn20LowHighPh_S;
   Float_t tmp_HIknn40TrkPhFrac_S;

   Float_t tmp_HIknn01TrkActivePlanes_B;
   Float_t tmp_HIknn10TrkMeanPh_B;
   Float_t tmp_HIknn20LowHighPh_B;
   Float_t tmp_HIknn40TrkPhFrac_B;

   /////////////////////////////////////////////////////
   //Float_t tmp_LItestID;
   //Float_t tmp_LIroID;
   Float_t tmp_LIknn01TrkActivePlanes;
   Float_t tmp_LIknn10TrkMeanPh;
   Float_t tmp_LIknn20LowHighPh;
   Float_t tmp_LIknn40TrkPhFrac;

   Float_t tmp_LIknn01TrkActivePlanes_S;
   Float_t tmp_LIknn10TrkMeanPh_S;
   Float_t tmp_LIknn20LowHighPh_S;
   Float_t tmp_LIknn40TrkPhFrac_S;

   Float_t tmp_LIknn01TrkActivePlanes_B;
   Float_t tmp_LIknn10TrkMeanPh_B;
   Float_t tmp_LIknn20LowHighPh_B;
   Float_t tmp_LIknn40TrkPhFrac_B;

   /////////////////////////////////////////////////////
   //Float_t tmp_SItestID;
   //Float_t tmp_SIroID;
   Float_t tmp_SIknn01TrkActivePlanes;
   Float_t tmp_SIknn10TrkMeanPh;
   Float_t tmp_SIknn20LowHighPh;
   Float_t tmp_SIknn40TrkPhFrac;

   Float_t tmp_SIknn01TrkActivePlanes_S;
   Float_t tmp_SIknn10TrkMeanPh_S;
   Float_t tmp_SIknn20LowHighPh_S;
   Float_t tmp_SIknn40TrkPhFrac_S;

   Float_t tmp_SIknn01TrkActivePlanes_B;
   Float_t tmp_SIknn10TrkMeanPh_B;
   Float_t tmp_SIknn20LowHighPh_B;
   Float_t tmp_SIknn40TrkPhFrac_B;

   // Set Branch
   //tr_HItest->SetBranchAddress("testID", &tmp_HItestID);
   //tr_HItest->SetBranchAddress("roID", &tmp_HIroID);
   tr_HItest->SetBranchAddress("knn01TrkActivePlanes", &tmp_HIknn01TrkActivePlanes);
   tr_HItest->SetBranchAddress("knn10TrkMeanPh", &tmp_HIknn10TrkMeanPh);
   tr_HItest->SetBranchAddress("knn20LowHighPh", &tmp_HIknn20LowHighPh);
   tr_HItest->SetBranchAddress("knn40TrkPhFrac", &tmp_HIknn40TrkPhFrac);

   tr_HItestS->SetBranchAddress("knn01TrkActivePlanes", &tmp_HIknn01TrkActivePlanes_S);
   tr_HItestS->SetBranchAddress("knn10TrkMeanPh", &tmp_HIknn10TrkMeanPh_S);
   tr_HItestS->SetBranchAddress("knn20LowHighPh", &tmp_HIknn20LowHighPh_S);
   tr_HItestS->SetBranchAddress("knn40TrkPhFrac", &tmp_HIknn40TrkPhFrac_S);

   tr_HItestB->SetBranchAddress("knn01TrkActivePlanes", &tmp_HIknn01TrkActivePlanes_B);
   tr_HItestB->SetBranchAddress("knn10TrkMeanPh", &tmp_HIknn10TrkMeanPh_B);
   tr_HItestB->SetBranchAddress("knn20LowHighPh", &tmp_HIknn20LowHighPh_B);
   tr_HItestB->SetBranchAddress("knn40TrkPhFrac", &tmp_HIknn40TrkPhFrac_B);

   //tr_LItest->SetBranchAddress("testID", &tmp_LItestID);
   //tr_LItest->SetBranchAddress("roID", &tmp_LIroID);
   tr_LItest->SetBranchAddress("knn01TrkActivePlanes", &tmp_LIknn01TrkActivePlanes);
   tr_LItest->SetBranchAddress("knn10TrkMeanPh", &tmp_LIknn10TrkMeanPh);
   tr_LItest->SetBranchAddress("knn20LowHighPh", &tmp_LIknn20LowHighPh);
   tr_LItest->SetBranchAddress("knn40TrkPhFrac", &tmp_LIknn40TrkPhFrac);

   tr_LItestS->SetBranchAddress("knn01TrkActivePlanes", &tmp_LIknn01TrkActivePlanes_S);
   tr_LItestS->SetBranchAddress("knn10TrkMeanPh", &tmp_LIknn10TrkMeanPh_S);
   tr_LItestS->SetBranchAddress("knn20LowHighPh", &tmp_LIknn20LowHighPh_S);
   tr_LItestS->SetBranchAddress("knn40TrkPhFrac", &tmp_LIknn40TrkPhFrac_S);

   tr_LItestB->SetBranchAddress("knn01TrkActivePlanes", &tmp_LIknn01TrkActivePlanes_B);
   tr_LItestB->SetBranchAddress("knn10TrkMeanPh", &tmp_LIknn10TrkMeanPh_B);
   tr_LItestB->SetBranchAddress("knn20LowHighPh", &tmp_LIknn20LowHighPh_B);
   tr_LItestB->SetBranchAddress("knn40TrkPhFrac", &tmp_LIknn40TrkPhFrac_B);

   //tr_SItest->SetBranchAddress("testID", &tmp_SItestID);
   //tr_SItest->SetBranchAddress("roID", &tmp_SIroID);
   tr_SItest->SetBranchAddress("knn01TrkActivePlanes", &tmp_SIknn01TrkActivePlanes);
   tr_SItest->SetBranchAddress("knn10TrkMeanPh", &tmp_SIknn10TrkMeanPh);
   tr_SItest->SetBranchAddress("knn20LowHighPh", &tmp_SIknn20LowHighPh);
   tr_SItest->SetBranchAddress("knn40TrkPhFrac", &tmp_SIknn40TrkPhFrac);

   tr_SItestS->SetBranchAddress("knn01TrkActivePlanes", &tmp_SIknn01TrkActivePlanes_S);
   tr_SItestS->SetBranchAddress("knn10TrkMeanPh", &tmp_SIknn10TrkMeanPh_S);
   tr_SItestS->SetBranchAddress("knn20LowHighPh", &tmp_SIknn20LowHighPh_S);
   tr_SItestS->SetBranchAddress("knn40TrkPhFrac", &tmp_SIknn40TrkPhFrac_S);

   tr_SItestB->SetBranchAddress("knn01TrkActivePlanes", &tmp_SIknn01TrkActivePlanes_B);
   tr_SItestB->SetBranchAddress("knn10TrkMeanPh", &tmp_SIknn10TrkMeanPh_B);
   tr_SItestB->SetBranchAddress("knn20LowHighPh", &tmp_SIknn20LowHighPh_B);
   tr_SItestB->SetBranchAddress("knn40TrkPhFrac", &tmp_SIknn40TrkPhFrac_B);

   ////////////////////////////////////////////////////
   TH1D* h_HITrkActivePlanes = new TH1D("h_HITrkActivePlanes", "TrkActivePlanes High Intensity (Signal + Background)", 140, 0, 140);
   TH1D* h_HITrkMeanPh = new TH1D("h_HITrkMeanPh", "TrkMeanPh High Intensity (Signal + Background)", 60, 0, 60);
   TH1D* h_HILowHighPh = new TH1D("h_HILowHighPh", "LowHighPh High Intensity (Signal + Background)", 100, 0, 1);
   TH1D* h_HITrkPhFrac = new TH1D("h_HITrkPhFrac", "TrkPhFrac High Intensity (Signal + Background)", 110, 0, 1.1);

   TH1D* h_HITrkActivePlanes_S = new TH1D("h_HITrkActivePlanes_S", "TrkActivePlanes High Intensity (Signal)", 140, 0, 140);
   TH1D* h_HITrkMeanPh_S = new TH1D("h_HITrkMeanPh_S", "TrkMeanPh High Intensity (Signal)", 60, 0, 60);
   TH1D* h_HILowHighPh_S = new TH1D("h_HILowHighPh_S", "LowHighPh High Intensity (Signal)", 100, 0, 1);
   TH1D* h_HITrkPhFrac_S = new TH1D("h_HITrkPhFrac_S", "TrkPhFrac High Intensity (Signal)", 110, 0, 1.1);

   TH1D* h_HITrkActivePlanes_B = new TH1D("h_HITrkActivePlanes_B", "TrkActivePlanes High Intensity (Background)", 140, 0, 140);
   TH1D* h_HITrkMeanPh_B = new TH1D("h_HITrkMeanPh_B", "TrkMeanPh High Intensity (Background)", 60, 0, 60);
   TH1D* h_HILowHighPh_B = new TH1D("h_HILowHighPh_B", "LowHighPh High Intensity (Background)", 100, 0, 1);
   TH1D* h_HITrkPhFrac_B = new TH1D("h_HITrkPhFrac_B", "TrkPhFrac High Intensity (Background)", 110, 0, 1.1);

   TH1D* h_LITrkActivePlanes = new TH1D("h_LITrkActivePlanes", "TrkActivePlanes Low Intensity (Signal + Background)", 140, 0, 140);
   TH1D* h_LITrkMeanPh = new TH1D("h_LITrkMeanPh", "TrkMeanPh Low Intensity (Signal + Background)", 60, 0, 60);
   TH1D* h_LILowHighPh = new TH1D("h_LILowHighPh", "LowHighPh Low Intensity (Signal + Background)", 100, 0, 1);
   TH1D* h_LITrkPhFrac = new TH1D("h_LITrkPhFrac", "TrkPhFrac Low Intensity (Signal + Background)", 110, 0, 1.1);

   TH1D* h_LITrkActivePlanes_S = new TH1D("h_LITrkActivePlanes_S", "TrkActivePlanes Low Intensity (Signal)", 140, 0, 140);
   TH1D* h_LITrkMeanPh_S = new TH1D("h_LITrkMeanPh_S", "TrkMeanPh Low Intensity (Signal)", 60, 0, 60);
   TH1D* h_LILowHighPh_S = new TH1D("h_LILowHighPh_S", "LowHighPh Low Intensity (Signal)", 100, 0, 1);
   TH1D* h_LITrkPhFrac_S = new TH1D("h_LITrkPhFrac_S", "TrkPhFrac Low Intensity (Signal)", 110, 0, 1.1);

   TH1D* h_LITrkActivePlanes_B = new TH1D("h_LITrkActivePlanes_B", "TrkActivePlanes Low Intensity (Background)", 140, 0, 140);
   TH1D* h_LITrkMeanPh_B = new TH1D("h_LITrkMeanPh_B", "TrkMeanPh Low Intensity (Background)", 60, 0, 60);
   TH1D* h_LILowHighPh_B = new TH1D("h_LILowHighPh_B", "LowHighPh Low Intensity (Background)", 100, 0, 1);
   TH1D* h_LITrkPhFrac_B = new TH1D("h_LITrkPhFrac_B", "TrkPhFrac Low Intensity (Background)", 110, 0, 1.1);

   TH1D* h_SITrkActivePlanes = new TH1D("h_SITrkActivePlanes", "TrkActivePlanes Single (Signal + Background)", 140, 0, 140);
   TH1D* h_SITrkMeanPh = new TH1D("h_SITrkMeanPh", "TrkMeanPh Single (Signal + Background)", 60, 0, 60);
   TH1D* h_SILowHighPh = new TH1D("h_SILowHighPh", "LowHighPh Single (Signal + Background)", 100, 0, 1);
   TH1D* h_SITrkPhFrac = new TH1D("h_SITrkPhFrac", "TrkPhFrac Single (Signal + Background)", 110, 0, 1.1);

   TH1D* h_SITrkActivePlanes_S = new TH1D("h_SITrkActivePlanes_S", "TrkActivePlanes Single (Signal)", 140, 0, 140);
   TH1D* h_SITrkMeanPh_S = new TH1D("h_SITrkMeanPh_S", "TrkMeanPh Single (Signal)", 60, 0, 60);
   TH1D* h_SILowHighPh_S = new TH1D("h_SILowHighPh_S", "LowHighPh Single (Signal)", 100, 0, 1);
   TH1D* h_SITrkPhFrac_S = new TH1D("h_SITrkPhFrac_S", "TrkPhFrac Single (Signal)", 110, 0, 1.1);

   TH1D* h_SITrkActivePlanes_B = new TH1D("h_SITrkActivePlanes_B", "TrkActivePlanes Single (Background)", 140, 0, 140);
   TH1D* h_SITrkMeanPh_B = new TH1D("h_SITrkMeanPh_B", "TrkMeanPh Single (Background)", 60, 0, 60);
   TH1D* h_SILowHighPh_B = new TH1D("h_SILowHighPh_B", "LowHighPh Single (Background)", 100, 0, 1);
   TH1D* h_SITrkPhFrac_B = new TH1D("h_SITrkPhFrac_B", "TrkPhFrac Single (Background)", 110, 0, 1.1);

   //////////////////////////////////////////////////////////////////
   Int_t nentries_HI = (Int_t) tr_HItest->GetEntries();
   for (Int_t i = 0; i < nentries_HI; i++) {
      tr_HItest->GetEntry(i);
      h_HITrkActivePlanes->Fill(tmp_HIknn01TrkActivePlanes);
      h_HITrkMeanPh->Fill(tmp_HIknn10TrkMeanPh);
      h_HILowHighPh->Fill(tmp_HIknn20LowHighPh);
      h_HITrkPhFrac->Fill(tmp_HIknn40TrkPhFrac);
   }

   Int_t nentriesS_HI = (Int_t) tr_HItestS->GetEntries();
   for (Int_t i = 0; i < nentriesS_HI; i++) {
      tr_HItestS->GetEntry(i);
      h_HITrkActivePlanes_S->Fill(tmp_HIknn01TrkActivePlanes_S);
      h_HITrkMeanPh_S->Fill(tmp_HIknn10TrkMeanPh_S);
      h_HILowHighPh_S->Fill(tmp_HIknn20LowHighPh_S);
      h_HITrkPhFrac_S->Fill(tmp_HIknn40TrkPhFrac_S);
   }

   Int_t nentriesB_HI = (Int_t) tr_HItestB->GetEntries();
   for (Int_t i = 0; i < nentriesB_HI; i++) {
      tr_HItestB->GetEntry(i);
      h_HITrkActivePlanes_B->Fill(tmp_HIknn01TrkActivePlanes_B);
      h_HITrkMeanPh_B->Fill(tmp_HIknn10TrkMeanPh_B);
      h_HILowHighPh_B->Fill(tmp_HIknn20LowHighPh_B);
      h_HITrkPhFrac_B->Fill(tmp_HIknn40TrkPhFrac_B);
   }

   Int_t nentries_LI = (Int_t) tr_LItest->GetEntries();
   for (Int_t i = 0; i < nentries_LI; i++) {
      tr_LItest->GetEntry(i);
      h_LITrkActivePlanes->Fill(tmp_LIknn01TrkActivePlanes);
      h_LITrkMeanPh->Fill(tmp_LIknn10TrkMeanPh);
      h_LILowHighPh->Fill(tmp_LIknn20LowHighPh);
      h_LITrkPhFrac->Fill(tmp_LIknn40TrkPhFrac);
   }

   Int_t nentriesS_LI = (Int_t) tr_LItestS->GetEntries();
   for (Int_t i = 0; i < nentriesS_LI; i++) {
      tr_LItestS->GetEntry(i);
      h_LITrkActivePlanes_S->Fill(tmp_LIknn01TrkActivePlanes_S);
      h_LITrkMeanPh_S->Fill(tmp_LIknn10TrkMeanPh_S);
      h_LILowHighPh_S->Fill(tmp_LIknn20LowHighPh_S);
      h_LITrkPhFrac_S->Fill(tmp_LIknn40TrkPhFrac_S);
   }

   Int_t nentriesB_LI = (Int_t) tr_LItestB->GetEntries();
   for (Int_t i = 0; i < nentriesB_LI; i++) {
      tr_LItestB->GetEntry(i);
      h_LITrkActivePlanes_B->Fill(tmp_LIknn01TrkActivePlanes_B);
      h_LITrkMeanPh_B->Fill(tmp_LIknn10TrkMeanPh_B);
      h_LILowHighPh_B->Fill(tmp_LIknn20LowHighPh_B);
      h_LITrkPhFrac_B->Fill(tmp_LIknn40TrkPhFrac_B);
   }


   Int_t nentries_SI = (Int_t) tr_SItest->GetEntries();
   for (Int_t i = 0; i < nentries_SI; i++) {
      tr_SItest->GetEntry(i);
      h_SITrkActivePlanes->Fill(tmp_SIknn01TrkActivePlanes);
      h_SITrkMeanPh->Fill(tmp_SIknn10TrkMeanPh);
      h_SILowHighPh->Fill(tmp_SIknn20LowHighPh);
      h_SITrkPhFrac->Fill(tmp_SIknn40TrkPhFrac);
   }

   Int_t nentriesS_SI = (Int_t) tr_SItestS->GetEntries();
   for (Int_t i = 0; i < nentriesS_SI; i++) {
      tr_SItestS->GetEntry(i);
      h_SITrkActivePlanes_S->Fill(tmp_SIknn01TrkActivePlanes_S);
      h_SITrkMeanPh_S->Fill(tmp_SIknn10TrkMeanPh_S);
      h_SILowHighPh_S->Fill(tmp_SIknn20LowHighPh_S);
      h_SITrkPhFrac_S->Fill(tmp_SIknn40TrkPhFrac_S);
   }

   Int_t nentriesB_SI = (Int_t) tr_SItestB->GetEntries();
   for (Int_t i = 0; i < nentriesB_SI; i++) {
      tr_SItestB->GetEntry(i);
      h_SITrkActivePlanes_B->Fill(tmp_SIknn01TrkActivePlanes_B);
      h_SITrkMeanPh_B->Fill(tmp_SIknn10TrkMeanPh_B);
      h_SILowHighPh_B->Fill(tmp_SIknn20LowHighPh_B);
      h_SITrkPhFrac_B->Fill(tmp_SIknn40TrkPhFrac_B);
   }

   TFile f("FullDST-HLS-NewDataForCutSensitivityAnalysis.root", "recreate");
   h_HITrkActivePlanes->Write();
   h_HITrkMeanPh->Write();
   h_HILowHighPh->Write();
   h_HITrkPhFrac->Write();
   h_HITrkActivePlanes_S->Write();
   h_HITrkMeanPh_S->Write();
   h_HILowHighPh_S->Write();
   h_HITrkPhFrac_S->Write();
   h_HITrkActivePlanes_B->Write();
   h_HITrkMeanPh_B->Write();
   h_HILowHighPh_B->Write();
   h_HITrkPhFrac_B->Write();
   h_LITrkActivePlanes->Write();
   h_LITrkMeanPh->Write();
   h_LILowHighPh->Write();
   h_LITrkPhFrac->Write();
   h_LITrkActivePlanes_S->Write();
   h_LITrkMeanPh_S->Write();
   h_LILowHighPh_S->Write();
   h_LITrkPhFrac_S->Write();
   h_LITrkActivePlanes_B->Write();
   h_LITrkMeanPh_B->Write();
   h_LILowHighPh_B->Write();
   h_LITrkPhFrac_B->Write();
   h_SITrkActivePlanes->Write();
   h_SITrkMeanPh->Write();
   h_SILowHighPh->Write();
   h_SITrkPhFrac->Write();
   h_SITrkActivePlanes_S->Write();
   h_SITrkMeanPh_S->Write();
   h_SILowHighPh_S->Write();
   h_SITrkPhFrac_S->Write();
   h_SITrkActivePlanes_B->Write();
   h_SITrkMeanPh_B->Write();
   h_SILowHighPh_B->Write();
   h_SITrkPhFrac_B->Write();
   f.Write();
}
