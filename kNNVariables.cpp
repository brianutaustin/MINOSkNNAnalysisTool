#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#include "TFile.h"
#include "TTree.h"
#include "TLeaf.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TError.h"
#include "TROOT.h"

#include "VpTree.h"

struct Point {
  bool signalMC;
  bool roSignalMC;
  double rw;
  std::vector< std::pair<int, double> > dungpid;
  Float_t knn01TrkActivePlanes;
  Float_t knn10TrkMeanPh;
  Float_t knn20LowHighPh;
  Float_t knn40TrkPhFrac;
};
std::vector< std::vector<Point> > HIPoints;
std::vector< std::vector<Point> > LIPoints;
std::vector< std::vector<Point> > SIPoints;

std::vector<double> wts;
//int NN = 80;

void Welcome();
std::vector< std::vector<Point> > Initialize(std::string, int, int, int);
std::vector<Point> TestQuery(std::string, int, int);
double GetDistributionWidth(std::vector<double>, double);
static double DistancePID(const Point&, const Point&);
std::vector<TH1D> MakeVariableHistogram(std::vector<Point>, std::string);
void MakekNNroIDROOTFile(std::vector<Point>, std::vector<Point>, std::vector<Point>);
void PlotkNNVariables(std::vector<TH1D>, std::vector<TH1D>, std::vector<TH1D>);
double GetPID(std::vector<Point>, int, int, int);

VpTree<Point, DistancePID> HItree;
VpTree<Point, DistancePID> LItree;
VpTree<Point, DistancePID> SItree;

void Welcome() {
  std::cout << std::endl;
  std::cout << "              MINOS kNN Algorithm Analysis Tool" << std::endl;
  std::cout << "-------------------------------------------------------------" << std::endl;
  std::cout << std::endl;
  std::cout << "                              ***                            " << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
}

// Choosing numEntries = -1, k = 80, randomSeed = 2
// IntensityType:
//    +1 = HIGH
//    +2 = LOW
//    +3 = SINGLE
std::vector< std::vector<Point> > Initialize(std::string fileName, int numEntries, int randomSeed, int IntensityType){

  std::vector< std::vector<Point> > Points;
  std::vector<Point> trainPoints;
  std::vector<Point> testPoints;
  trainPoints.clear();
  TFile* f = new TFile(fileName.c_str());
  std::cout << "-------------------------------------------------------------" << std::endl;
  std::cout << "OPENING: " << fileName.c_str() << "... " << std::endl;
  std::cout << "-------------------------------------------------------------" << std::endl;
  std::cout << std::endl;
  if (IntensityType == 1) {
    std::cout << "\t"  << "CREATING TRAINING SET FOR HIGH INTENSITY." << std::endl;
  } else if (IntensityType == 2) {
    std::cout << "\t"  << "CREATING TRAINING SET FOR LOW INTENSITY." << std::endl;
  } else if (IntensityType == 3) {
    std::cout << "\t"  << "CREATING TRAINING SET FOR SINGLE INTENSITY." << std::endl;
  }
  std::cout << "\t" << "=============================================" << std::endl;
  std::cout << "\t" << "Preparing Training Set from DST..." << std::endl;
  TTree* t = (TTree*) f->Get("trainPID");

  std::vector<Point> fullTrainS;
  std::vector<Point> fullTrainB;

  for(Int_t i=0; i < t->GetEntries(); i++) {
    t->GetEntry(i);
    Point point;
    point.signalMC = t->GetLeaf("signalMC")->GetValue();
    point.roSignalMC = t->GetLeaf("roSignalMC")->GetValue();
    point.rw = t->GetLeaf("rw")->GetValue();
    point.knn01TrkActivePlanes = t->GetLeaf("knn01TrkActivePlanes")->GetValue();
    point.knn10TrkMeanPh = t->GetLeaf("knn10TrkMeanPh")->GetValue();
    point.knn20LowHighPh = t->GetLeaf("knn20LowHighPh")->GetValue();
    point.knn40TrkPhFrac = t->GetLeaf("knn40TrkPhFrac")->GetValue();

    if(point.signalMC)
      fullTrainS.push_back(point);
    else
      fullTrainB.push_back(point);
  }

  std::cout << "\t" << "Number of signal     = " << fullTrainS.size() << "." << std::endl;
  std::cout << "\t" << "Number of background = " << fullTrainB.size() << "." << std::endl;

  if(randomSeed >= 0) {
    std::srand ((unsigned int)randomSeed);
    std::random_shuffle (fullTrainS.begin(), fullTrainS.end());
    std::random_shuffle (fullTrainB.begin(), fullTrainB.end());
  } else if(randomSeed == -1){
    std::srand ( unsigned ( std::time(0) ) );
    std::random_shuffle (fullTrainS.begin(), fullTrainS.end());
    std::random_shuffle (fullTrainB.begin(), fullTrainB.end());
  }
  std::cout << "\t" << "Finishing Randomization of Training Set... " << std::endl;

  int numEvtsMax = (fullTrainS.size() < fullTrainB.size()) ? fullTrainS.size() : fullTrainB.size();
  int numEvts = (numEntries >= numEvtsMax) ? numEvtsMax : numEntries;
  for(Int_t i=0; i < numEvts; i++){
    trainPoints.push_back(fullTrainS[i]);
    trainPoints.push_back(fullTrainB[i]);
  }
  std::cout << std::endl;
  std::cout << "\t" << "Making Weighted Training Set of Equal Number of Signal and Background Events." << std::endl;

  std::cout << "\t" << "Setting Weights for kNN Variables... " << std::endl;
  std::vector<double> vec0;
  std::vector<double> vec1;
  std::vector<double> vec2;
  std::vector<double> vec3;
  for(int i = 0; i < trainPoints.size(); i++) { vec0.push_back(trainPoints[i].knn01TrkActivePlanes); }
  for(int i = 0; i < trainPoints.size(); i++) { vec1.push_back(trainPoints[i].knn10TrkMeanPh); }
  for(int i = 0; i < trainPoints.size(); i++) { vec2.push_back(trainPoints[i].knn20LowHighPh); }
  for(int i = 0; i < trainPoints.size(); i++) { vec3.push_back(trainPoints[i].knn40TrkPhFrac); }
  wts.clear();
  wts.push_back(1. / GetDistributionWidth(vec0, 0.8));
  wts.push_back(1. / GetDistributionWidth(vec1, 0.8));
  wts.push_back(1. / GetDistributionWidth(vec2, 0.8));
  wts.push_back(1. / GetDistributionWidth(vec3, 0.8));
  std::cout << "\t \t" << "- Weight for knn01TrkActivePlanes : " << wts[0] << std::endl;
  std::cout << "\t \t" << "- Weight for knn10TrkMeanPh       : " << wts[1] << std::endl;
  std::cout << "\t \t" << "- Weight for knn20LowHighPh       : " << wts[2] << std::endl;
  std::cout << "\t \t" << "- Weight for knn40TrkPhFrac       : " << wts[3] << std::endl;

  std::cout << "\t" << "Applying Weights to kNN Variables... " << std::endl;
  for(int i = 0; i < trainPoints.size(); i++) { trainPoints[i].knn01TrkActivePlanes *= wts[0]; }
  for(int i = 0; i < trainPoints.size(); i++) { trainPoints[i].knn10TrkMeanPh *= wts[1]; }
  for(int i = 0; i < trainPoints.size(); i++) { trainPoints[i].knn20LowHighPh *= wts[2]; }
  for(int i = 0; i < trainPoints.size(); i++) { trainPoints[i].knn40TrkPhFrac *= wts[3]; }

  std::cout << std::endl;
  std::cout << "\t" << "Creating VP-Tree structure for " ;
  if (IntensityType == 1) {
    std::cout << "High Intensity Training Set." << std::endl;
    HItree.create(trainPoints);
    std::cout << "\t" << "Training Set for High Intensity has been prepared." << std::endl;
  } else if (IntensityType == 2) {
    std::cout << "Low Intensity Training Set." << std::endl;
    LItree.create(trainPoints);
    std::cout << "\t" << "Training Set for Low Intensity has been prepared." << std::endl;
  } else if (IntensityType == 3) {
    std::cout << "Single Events Training Set." << std::endl;
    SItree.create(trainPoints);
    std::cout << "\t" << "Training Set for Single Intensity has been prepared." << std::endl;
  }
  f->Close();

  std::cout << std::endl;
  if (IntensityType == 1) {
    std::cout << "\t"  << "CREATING TEST QUERIES FOR HIGH INTENSITY." << std::endl;
  } else if (IntensityType == 2) {
    std::cout << "\t"  << "CREATING TEST QUERIES FOR LOW INTENSITY." << std::endl;
  } else if (IntensityType == 3) {
    std::cout << "\t"  << "CREATING TEST QUERIES FOR SINGLE INTENSITY." << std::endl;
  }
  std::cout << "\t" << "=============================================" << std::endl;

  // Set the maximum number of Test Queries here!
  int maxNumEvts = 100;
  std::cout << "\t" << "Setting the number of events in Test Queries: " << maxNumEvts << ". " << std::endl;
  std::cout << "\t" << "Preparing Test Queries from DST..." << std::endl;
  testPoints = TestQuery(fileName, maxNumEvts, IntensityType);
  std::cout << std::endl;

  Points.push_back(trainPoints);
  Points.push_back(testPoints);

  return Points;
}

std::vector<Point> TestQuery(std::string fileName, int maxNumEvts, int IntensityType){

  std::vector<Point> testPoints;
  testPoints.clear();
  TFile* f = new TFile(fileName.c_str());
  TTree* t = (TTree*) f->Get("test");

  if (maxNumEvts == 0) {
    maxNumEvts = t->GetEntries();
  }

  for(Int_t i=0; i < maxNumEvts; i++) {
    t->GetEntry(i);
    Point point;
    point.signalMC = t->GetLeaf("signalMC")->GetValue();
    point.roSignalMC = t->GetLeaf("roSignalMC")->GetValue();
    point.rw = t->GetLeaf("rw")->GetValue();
    point.knn01TrkActivePlanes = t->GetLeaf("knn01TrkActivePlanes")->GetValue();
    point.knn10TrkMeanPh = t->GetLeaf("knn10TrkMeanPh")->GetValue();
    point.knn20LowHighPh = t->GetLeaf("knn20LowHighPh")->GetValue();
    point.knn40TrkPhFrac = t->GetLeaf("knn40TrkPhFrac")->GetValue();

    testPoints.push_back(point);
  }

  int randomSeed = 2;
  std::cout << "\t" << "Shuffling the Test Queries with randomSeed is " << randomSeed << "..." << std::endl;
  std::srand((unsigned int)randomSeed); // Random Seed = 2
  std::random_shuffle(testPoints.begin(), testPoints.end());

  std::cout << "\t \t" << "- Weight for knn01TrkActivePlanes : " << wts[0] << std::endl;
  std::cout << "\t \t" << "- Weight for knn10TrkMeanPh       : " << wts[1] << std::endl;
  std::cout << "\t \t" << "- Weight for knn20LowHighPh       : " << wts[2] << std::endl;
  std::cout << "\t \t" << "- Weight for knn40TrkPhFrac       : " << wts[3] << std::endl;
  std::cout << "\t" << "Applying Weights to kNN Variables... " << std::endl;
  for(int i = 0; i < testPoints.size(); i++) { testPoints[i].knn01TrkActivePlanes *= wts[0]; }
  for(int i = 0; i < testPoints.size(); i++) { testPoints[i].knn10TrkMeanPh *= wts[1]; }
  for(int i = 0; i < testPoints.size(); i++) { testPoints[i].knn20LowHighPh *= wts[2]; }
  for(int i = 0; i < testPoints.size(); i++) { testPoints[i].knn40TrkPhFrac *= wts[3]; }
  std::cout << "\t" << "Done Applying Weights to kNN Variables... " << std::endl;

  // Calculate DUNGPID for different kNN values
  // Change the values of k that you want. Here, I choose k = [50-160]
  std::cout << "\t" << "Producing roID with k = [60; 120; 2]..." << std::endl;
  for (int k = 60; k < 120; k++) {
    for(int i = 0; i < testPoints.size(); i++) {
      std::pair<int, double> p_temp(k, GetPID(testPoints, i, k, IntensityType));
      testPoints[i].dungpid.push_back(p_temp);
    }
    std::cout << "\t \t" << "- Done with k = " << k << "." << std::endl;
  }

  f->Close();
  return testPoints;
}

double GetDistributionWidth(std::vector<double> vec, double width) {
  double quantileBeg = (1. - width) / 2.;
  double quantileEnd = quantileBeg + width;

  int indexBeg = (int)(vec.size() * quantileBeg);
  std::nth_element(vec.begin(), vec.begin() + indexBeg, vec.end());
  double beg = vec[indexBeg];

  int indexEnd = (int)(vec.size() * quantileEnd);
  std::nth_element(vec.begin(), vec.begin() + indexEnd, vec.end());
  double end = vec[indexEnd];

  return end - beg;
}

double DistancePID(const Point &p1, const Point &p2){
  double sumSq = 0.;
  sumSq = pow(p1.knn01TrkActivePlanes - p2.knn01TrkActivePlanes, 2)
        + pow(p1.knn10TrkMeanPh - p2.knn10TrkMeanPh, 2)
        + pow(p1.knn20LowHighPh - p2.knn20LowHighPh, 2)
        + pow(p1.knn40TrkPhFrac - p2.knn40TrkPhFrac, 2);
  return sqrt(sumSq);
}

double GetPID(std::vector<Point> testPoints, int i, int testNN, int IntensityType){
  std::vector<Point> results;
  std::vector<double> distances;

  Point point = testPoints[i];
  if (IntensityType == 1) {
    HItree.search(point, testNN, &results, &distances);
  } else if (IntensityType == 2) {
    LItree.search(point, testNN, &results, &distances);
  } else if (IntensityType == 3) {
    SItree.search(point, testNN, &results, &distances);
  }

  double sum = 0.;
  for(int j = 0; j < results.size(); j++) {
    if (results[j].signalMC) { sum++; }
  }
  return sum/(double)testNN;
}

// Make kNN Variable Plots on the same Canvas
std::vector<TH1D> MakeVariableHistogram(std::vector<Point> trainPoints, std::string Intensity) {
  std::string str_h_knn01TrkActivePlanes = "Histogram for knn01TrkActivePlanes at " + Intensity + " Intensity";
  std::string str_h_knn10TrkMeanPh = "Histogram for knn10TrkMeanPh at " + Intensity + " Intensity";
  std::string str_h_knn20LowHighPh = "Histogram for knn20LowHighPh at " + Intensity + " Intensity";
  std::string str_h_knn40TrkPhFrac = "Histogram for knn40TrkPhFrac at " + Intensity + " Intensity";
  std::string str_hS_knn01TrkActivePlanes = "Histogram for knn01TrkActivePlanes (Signal) at " + Intensity + " Intensity";
  std::string str_hS_knn10TrkMeanPh = "Histogram for knn10TrkMeanPh (Signal) at " + Intensity + " Intensity";
  std::string str_hS_knn20LowHighPh = "Histogram for knn20LowHighPh (Signal) at " + Intensity + " Intensity";
  std::string str_hS_knn40TrkPhFrac = "Histogram for knn40TrkPhFrac (Signal) at " + Intensity + " Intensity";
  std::string str_hB_knn01TrkActivePlanes = "Histogram for knn01TrkActivePlanes (Background) at " + Intensity + " Intensity";
  std::string str_hB_knn10TrkMeanPh = "Histogram for knn10TrkMeanPh (Background) at " + Intensity + " Intensity";
  std::string str_hB_knn20LowHighPh = "Histogram for knn20LowHighPh (Background) at " + Intensity + " Intensity";
  std::string str_hB_knn40TrkPhFrac = "Histogram for knn40TrkPhFrac (Background) at " + Intensity + " Intensity";

  std::string str_hname_knn01TrkActivePlanes = "h_knn01TrkActivePlanes_" + Intensity;
  std::string str_hname_knn10TrkMeanPh = "h_knn10TrkMeanPh_" + Intensity;
  std::string str_hname_knn20LowHighPh = "h_knn20LowHighPh_" + Intensity;
  std::string str_hname_knn40TrkPhFrac = "h_knn40TrkPhFrac_" + Intensity;
  std::string str_hSname_knn01TrkActivePlanes = "hS_knn01TrkActivePlanes_" + Intensity;
  std::string str_hSname_knn10TrkMeanPh = "hS_knn10TrkMeanPh_" + Intensity;
  std::string str_hSname_knn20LowHighPh = "hS_knn20LowHighPh_" + Intensity;
  std::string str_hSname_knn40TrkPhFrac = "hS_knn40TrkPhFrac_" + Intensity;
  std::string str_hBname_knn01TrkActivePlanes = "hB_knn01TrkActivePlanes_" + Intensity;
  std::string str_hBname_knn10TrkMeanPh = "hB_knn10TrkMeanPh_" + Intensity;
  std::string str_hBname_knn20LowHighPh = "hB_knn20LowHighPh_" + Intensity;
  std::string str_hBname_knn40TrkPhFrac = "hB_knn40TrkPhFrac_" + Intensity;

  // Define a good binning scheme
  Double_t binsch_knn10[35];
  for (int i = 0; i < 26; i++) { binsch_knn10[i] = i*0.2; }
  for (int i = 0; i < 06; i++) { binsch_knn10[25+i] = 5+i*1; }
  for (int i = 0; i < 06; i++) { binsch_knn10[30+i] = 10+i*2; }


  TH1D* h_knn01TrkActivePlanes = new TH1D(str_hname_knn01TrkActivePlanes.c_str(), str_h_knn01TrkActivePlanes.c_str(), 80, 0, 2.2);
  TH1D* h_knn10TrkMeanPh = new TH1D(str_hname_knn10TrkMeanPh.c_str(), str_h_knn10TrkMeanPh.c_str(), 34, binsch_knn10);
  TH1D* h_knn20LowHighPh = new TH1D(str_hname_knn20LowHighPh.c_str(), str_h_knn20LowHighPh.c_str(), 80, 0, 3);
  TH1D* h_knn40TrkPhFrac = new TH1D(str_hname_knn40TrkPhFrac.c_str(), str_h_knn40TrkPhFrac.c_str(), 80, 0, 2);
  TH1D* hS_knn01TrkActivePlanes = new TH1D(str_h_knn01TrkActivePlanes.c_str(), str_hS_knn01TrkActivePlanes.c_str(), 80, 0, 2.2);
  TH1D* hS_knn10TrkMeanPh = new TH1D(str_hSname_knn10TrkMeanPh.c_str(), str_hS_knn10TrkMeanPh.c_str(), 34, binsch_knn10);
  TH1D* hS_knn20LowHighPh = new TH1D(str_hSname_knn20LowHighPh.c_str(), str_hS_knn20LowHighPh.c_str(), 80, 0, 3);
  TH1D* hS_knn40TrkPhFrac = new TH1D(str_hSname_knn40TrkPhFrac.c_str(), str_hS_knn40TrkPhFrac.c_str(), 80, 0, 2);
  TH1D* hB_knn01TrkActivePlanes = new TH1D(str_hBname_knn01TrkActivePlanes.c_str(), str_hB_knn01TrkActivePlanes.c_str(), 80, 0, 2.2);
  TH1D* hB_knn10TrkMeanPh = new TH1D(str_hBname_knn10TrkMeanPh.c_str(), str_hB_knn10TrkMeanPh.c_str(), 34, binsch_knn10);
  TH1D* hB_knn20LowHighPh = new TH1D(str_hBname_knn20LowHighPh.c_str(), str_hB_knn20LowHighPh.c_str(), 80, 0, 3);
  TH1D* hB_knn40TrkPhFrac = new TH1D(str_hBname_knn40TrkPhFrac.c_str(), str_hB_knn40TrkPhFrac.c_str(), 80, 0, 2);

  for (int i = 0; i < trainPoints.size(); i++) {
    h_knn01TrkActivePlanes->Fill(trainPoints[i].knn01TrkActivePlanes);
    h_knn10TrkMeanPh->Fill(trainPoints[i].knn10TrkMeanPh);
    h_knn20LowHighPh->Fill(trainPoints[i].knn20LowHighPh);
    h_knn40TrkPhFrac->Fill(trainPoints[i].knn40TrkPhFrac);
    if (trainPoints[i].signalMC == true) {
      hS_knn01TrkActivePlanes->Fill(trainPoints[i].knn01TrkActivePlanes);
      hS_knn10TrkMeanPh->Fill(trainPoints[i].knn10TrkMeanPh);
      hS_knn20LowHighPh->Fill(trainPoints[i].knn20LowHighPh);
      hS_knn40TrkPhFrac->Fill(trainPoints[i].knn40TrkPhFrac);
    } else {
      hB_knn01TrkActivePlanes->Fill(trainPoints[i].knn01TrkActivePlanes);
      hB_knn10TrkMeanPh->Fill(trainPoints[i].knn10TrkMeanPh);
      hB_knn20LowHighPh->Fill(trainPoints[i].knn20LowHighPh);
      hB_knn40TrkPhFrac->Fill(trainPoints[i].knn40TrkPhFrac);
    }
  }

  std::vector<TH1D> kNNVarHistCollection;
  kNNVarHistCollection.push_back(*h_knn01TrkActivePlanes);
  kNNVarHistCollection.push_back(*h_knn10TrkMeanPh);
  kNNVarHistCollection.push_back(*h_knn20LowHighPh);
  kNNVarHistCollection.push_back(*h_knn40TrkPhFrac);
  kNNVarHistCollection.push_back(*hS_knn01TrkActivePlanes);
  kNNVarHistCollection.push_back(*hS_knn10TrkMeanPh);
  kNNVarHistCollection.push_back(*hS_knn20LowHighPh);
  kNNVarHistCollection.push_back(*hS_knn40TrkPhFrac);
  kNNVarHistCollection.push_back(*hB_knn01TrkActivePlanes);
  kNNVarHistCollection.push_back(*hB_knn10TrkMeanPh);
  kNNVarHistCollection.push_back(*hB_knn20LowHighPh);
  kNNVarHistCollection.push_back(*hB_knn40TrkPhFrac);

  h_knn01TrkActivePlanes = NULL;
  h_knn10TrkMeanPh = NULL;
  h_knn20LowHighPh = NULL;
  h_knn40TrkPhFrac = NULL;
  hS_knn01TrkActivePlanes = NULL;
  hS_knn10TrkMeanPh = NULL;
  hS_knn20LowHighPh = NULL;
  hS_knn40TrkPhFrac = NULL;
  hB_knn01TrkActivePlanes = NULL;
  hB_knn10TrkMeanPh = NULL;
  hB_knn20LowHighPh = NULL;
  hB_knn40TrkPhFrac = NULL;

  delete h_knn01TrkActivePlanes;
  delete h_knn10TrkMeanPh;
  delete h_knn20LowHighPh;
  delete h_knn40TrkPhFrac;
  delete hS_knn01TrkActivePlanes;
  delete hS_knn10TrkMeanPh;
  delete hS_knn20LowHighPh;
  delete hS_knn40TrkPhFrac;
  delete hB_knn01TrkActivePlanes;
  delete hB_knn10TrkMeanPh;
  delete hB_knn20LowHighPh;
  delete hB_knn40TrkPhFrac;

  return kNNVarHistCollection;
}

void MakekNNroIDROOTFile(std::vector<Point> HI, std::vector<Point> LI, std::vector<Point> SI) {
  TFile f("kNNroID.root", "recreate");
  TTree t_HI("t_HI","roID for HIGH intensity");
  TTree t_LI("t_LI","roID for LOW intensity");
  TTree t_SI("t_SI","roID for SINGLE intensity");

  bool signalMC;
  std::vector< std::pair<int, double> > dungpid;
  Float_t knn01TrkActivePlanes;
  Float_t knn10TrkMeanPh;
  Float_t knn20LowHighPh;
  Float_t knn40TrkPhFrac;

  t_HI.Branch("signalMC", &signalMC,"signalMC/O");
  t_HI.Branch("knn01TrkActivePlanes", &knn01TrkActivePlanes,"knn01TrkActivePlanes/F");
  t_HI.Branch("knn10TrkMeanPh", &knn10TrkMeanPh,"knn10TrkMeanPh/F");
  t_HI.Branch("knn20LowHighPh", &knn20LowHighPh,"knn20LowHighPh/F");
  t_HI.Branch("knn40TrkPhFrac", &knn40TrkPhFrac,"knn40TrkPhFrac/F");
  
}

void PlotkNNVariables(std::vector<TH1D> HI, std::vector<TH1D> LI, std::vector<TH1D> SI) {
  // knn01TrkActivePlanes ==================================================================================================================
  TCanvas* c_knn01 = new TCanvas();
  HI[0].SetTitle("Distribution of TrkActivePlanes (Signal + Background)");
  HI[0].GetXaxis()->SetTitle("Number of planes in a track (Weighted)");
  HI[0].GetXaxis()->CenterTitle();
  HI[0].GetXaxis()->SetTitleOffset(1.2);
  HI[0].SetLineColor(1);
  LI[0].SetLineColor(2);
  SI[0].SetLineColor(3);
  HI[0].SetStats(0);
  LI[0].SetStats(0);
  SI[0].SetStats(0);
  TLegend* leg_knn01 = new TLegend(0.67,0.72,0.87,0.87);
  leg_knn01->AddEntry(&HI[0], "High Intensity", "l");
  leg_knn01->AddEntry(&LI[0], "Low Intensity", "l");
  leg_knn01->AddEntry(&SI[0], "Single", "l");
  HI[0].Draw();
  LI[0].Draw("same");
  SI[0].Draw("same");
  leg_knn01->Draw();
  c_knn01->SetLogy();
  c_knn01->SaveAs("knn01.eps");

  TCanvas* c_knn01S = new TCanvas();
  HI[4].SetTitle("Distribution of TrkActivePlanes (Signal)");
  HI[4].GetXaxis()->SetTitle("Number of planes in a track (Weighted)");
  HI[4].GetXaxis()->CenterTitle();
  HI[4].GetXaxis()->SetTitleOffset(1.2);
  HI[4].SetLineColor(1);
  LI[4].SetLineColor(2);
  SI[4].SetLineColor(3);
  HI[4].SetStats(0);
  LI[4].SetStats(0);
  SI[4].SetStats(0);
  TLegend* leg_knn01S = new TLegend(0.67,0.72,0.87,0.87);
  leg_knn01S->AddEntry(&HI[4], "High Intensity", "l");
  leg_knn01S->AddEntry(&LI[4], "Low Intensity", "l");
  leg_knn01S->AddEntry(&SI[4], "Single", "l");
  HI[4].Draw();
  LI[4].Draw("same");
  SI[4].Draw("same");
  leg_knn01S->Draw();
  c_knn01S->SetLogy();
  c_knn01S->SaveAs("knn01S.eps");

  TCanvas* c_knn01B = new TCanvas();
  HI[8].SetTitle("Distribution of TrkActivePlanes (Background)");
  HI[8].GetXaxis()->SetTitle("Number of planes in a track (Weighted)");
  HI[8].GetXaxis()->CenterTitle();
  HI[8].GetXaxis()->SetTitleOffset(1.2);
  HI[8].SetLineColor(1);
  LI[8].SetLineColor(2);
  SI[8].SetLineColor(3);
  HI[8].SetStats(0);
  LI[8].SetStats(0);
  SI[8].SetStats(0);
  TLegend* leg_knn01B = new TLegend(0.67,0.72,0.87,0.87);
  leg_knn01B->AddEntry(&HI[8], "High Intensity", "l");
  leg_knn01B->AddEntry(&LI[8], "Low Intensity", "l");
  leg_knn01B->AddEntry(&SI[8], "Single", "l");
  HI[8].Draw();
  LI[8].Draw("same");
  SI[8].Draw("same");
  leg_knn01B->Draw();
  c_knn01B->SetLogy();
  c_knn01B->SaveAs("knn01B.eps");

  // knn10TrkMeanPh ========================================================================================================================
  TCanvas* c_knn10 = new TCanvas();
  HI[1].SetTitle("Distribution of TrkMeanPh (Signal + Background)");
  HI[1].GetXaxis()->SetTitle("Mean PH per track hit (Weighted)");
  HI[1].GetXaxis()->CenterTitle();
  HI[1].GetXaxis()->SetTitleOffset(1.2);
  HI[1].SetLineColor(1);
  LI[1].SetLineColor(2);
  SI[1].SetLineColor(3);
  HI[1].SetStats(0);
  LI[1].SetStats(0);
  SI[1].SetStats(0);
  TLegend* leg_knn10 = new TLegend(0.67,0.72,0.87,0.87);
  leg_knn10->AddEntry(&HI[1], "High Intensity", "l");
  leg_knn10->AddEntry(&LI[1], "Low Intensity", "l");
  leg_knn10->AddEntry(&SI[1], "Single", "l");
  HI[1].Draw();
  LI[1].Draw("same");
  SI[1].Draw("same");
  leg_knn10->Draw();
  c_knn10->SetLogy();
  c_knn10->SaveAs("knn10.eps");

  TCanvas* c_knn10S = new TCanvas();
  HI[5].SetTitle("Distribution of TrkMeanPh (Signal)");
  HI[5].GetXaxis()->SetTitle("Mean PH per track hit (Weighted)");
  HI[5].GetXaxis()->CenterTitle();
  HI[5].GetXaxis()->SetTitleOffset(1.2);
  HI[5].SetLineColor(1);
  LI[5].SetLineColor(2);
  SI[5].SetLineColor(3);
  HI[5].SetStats(0);
  LI[5].SetStats(0);
  SI[5].SetStats(0);
  TLegend* leg_knn10S = new TLegend(0.67,0.72,0.87,0.87);
  leg_knn10S->AddEntry(&HI[5], "High Intensity", "l");
  leg_knn10S->AddEntry(&LI[5], "Low Intensity", "l");
  leg_knn10S->AddEntry(&SI[5], "Single", "l");
  HI[5].Draw();
  LI[5].Draw("same");
  SI[5].Draw("same");
  leg_knn10S->Draw();
  c_knn10S->SetLogy();
  c_knn10S->SaveAs("knn10S.eps");

  TCanvas* c_knn10B = new TCanvas();
  HI[9].SetTitle("Distribution of TrkActivePlanes (Background)");
  HI[9].GetXaxis()->SetTitle("Mean PH per track hit (Weighted)");
  HI[9].GetXaxis()->CenterTitle();
  HI[9].GetXaxis()->SetTitleOffset(1.2);
  HI[9].SetLineColor(1);
  LI[9].SetLineColor(2);
  SI[9].SetLineColor(3);
  HI[9].SetStats(0);
  LI[9].SetStats(0);
  SI[9].SetStats(0);
  TLegend* leg_knn10B = new TLegend(0.67,0.72,0.87,0.87);
  leg_knn10B->AddEntry(&HI[9], "High Intensity", "l");
  leg_knn10B->AddEntry(&LI[9], "Low Intensity", "l");
  leg_knn10B->AddEntry(&SI[9], "Single", "l");
  HI[9].Draw();
  LI[9].Draw("same");
  SI[9].Draw("same");
  leg_knn10B->Draw();
  c_knn10B->SetLogy();
  c_knn10B->SaveAs("knn10B.eps");

  // knn20LowHighPh ========================================================================================================================
  TCanvas* c_knn20 = new TCanvas();
  HI[2].SetTitle("Distribution of LowHighPh (Signal + Background)");
  HI[2].GetXaxis()->SetTitle("Low/High Pulse Height (Weighted)");
  HI[2].GetXaxis()->CenterTitle();
  HI[2].GetXaxis()->SetTitleOffset(1.2);
  HI[2].SetLineColor(1);
  LI[2].SetLineColor(2);
  SI[2].SetLineColor(3);
  HI[2].SetStats(0);
  LI[2].SetStats(0);
  SI[2].SetStats(0);
  TLegend* leg_knn20 = new TLegend(0.67,0.72,0.87,0.87);
  leg_knn20->AddEntry(&HI[2], "High Intensity", "l");
  leg_knn20->AddEntry(&LI[2], "Low Intensity", "l");
  leg_knn20->AddEntry(&SI[2], "Single", "l");
  HI[2].Draw();
  LI[2].Draw("same");
  SI[2].Draw("same");
  leg_knn20->Draw();
  c_knn20->SetLogy();
  c_knn20->SaveAs("knn20.eps");

  TCanvas* c_knn20S = new TCanvas();
  HI[6].SetTitle("Distribution of LowHighPh (Signal)");
  HI[6].GetXaxis()->SetTitle("Low/High Pulse Height (Weighted)");
  HI[6].GetXaxis()->CenterTitle();
  HI[6].GetXaxis()->SetTitleOffset(1.2);
  HI[6].SetLineColor(1);
  LI[6].SetLineColor(2);
  SI[6].SetLineColor(3);
  HI[6].SetStats(0);
  LI[6].SetStats(0);
  SI[6].SetStats(0);
  TLegend* leg_knn20S = new TLegend(0.67,0.72,0.87,0.87);
  leg_knn20S->AddEntry(&HI[6], "High Intensity", "l");
  leg_knn20S->AddEntry(&LI[6], "Low Intensity", "l");
  leg_knn20S->AddEntry(&SI[6], "Single", "l");
  HI[6].Draw();
  LI[6].Draw("same");
  SI[6].Draw("same");
  leg_knn20S->Draw();
  c_knn20S->SetLogy();
  c_knn20S->SaveAs("knn20S.eps");

  TCanvas* c_knn20B = new TCanvas();
  HI[10].SetTitle("Distribution of LowHighPh (Background)");
  HI[10].GetXaxis()->SetTitle("Low/High Pulse Height (Weighted)");
  HI[10].GetXaxis()->CenterTitle();
  HI[10].GetXaxis()->SetTitleOffset(1.2);
  HI[10].SetLineColor(1);
  LI[10].SetLineColor(2);
  SI[10].SetLineColor(3);
  HI[10].SetStats(0);
  LI[10].SetStats(0);
  SI[10].SetStats(0);
  TLegend* leg_knn20B = new TLegend(0.67,0.72,0.87,0.87);
  leg_knn20B->AddEntry(&HI[10], "High Intensity", "l");
  leg_knn20B->AddEntry(&LI[10], "Low Intensity", "l");
  leg_knn20B->AddEntry(&SI[10], "Single", "l");
  HI[10].Draw();
  LI[10].Draw("same");
  SI[10].Draw("same");
  leg_knn20B->Draw();
  c_knn20B->SetLogy();
  c_knn20B->SaveAs("knn20B.eps");

  // knn40TrkPhFrac ========================================================================================================================
  TCanvas* c_knn40 = new TCanvas();
  HI[3].SetTitle("Distribution of TrkPhFrac (Signal + Background)");
  HI[3].GetXaxis()->SetTitle("Fraction of Track Hits (Weighted)");
  HI[3].GetXaxis()->CenterTitle();
  HI[3].GetXaxis()->SetTitleOffset(1.2);
  HI[3].SetLineColor(1);
  LI[3].SetLineColor(2);
  SI[3].SetLineColor(3);
  HI[3].SetStats(0);
  LI[3].SetStats(0);
  SI[3].SetStats(0);
  TLegend* leg_knn40 = new TLegend(0.17,0.72,0.37,0.87);
  leg_knn40->AddEntry(&HI[3], "High Intensity", "l");
  leg_knn40->AddEntry(&LI[3], "Low Intensity", "l");
  leg_knn40->AddEntry(&SI[3], "Single", "l");
  HI[3].Draw();
  LI[3].Draw("same");
  SI[3].Draw("same");
  leg_knn40->Draw();
  c_knn40->SetLogy();
  c_knn40->SaveAs("knn40.eps");

  TCanvas* c_knn40S = new TCanvas();
  HI[7].SetTitle("Distribution of TrkPhFrac (Signal)");
  HI[7].GetXaxis()->SetTitle("Fraction of Track Hits (Weighted)");
  HI[7].GetXaxis()->CenterTitle();
  HI[7].GetXaxis()->SetTitleOffset(1.2);
  HI[7].SetLineColor(1);
  LI[7].SetLineColor(2);
  SI[7].SetLineColor(3);
  HI[7].SetStats(0);
  LI[7].SetStats(0);
  SI[7].SetStats(0);
  TLegend* leg_knn40S = new TLegend(0.17,0.72,0.37,0.87);
  leg_knn40S->AddEntry(&HI[7], "High Intensity", "l");
  leg_knn40S->AddEntry(&LI[7], "Low Intensity", "l");
  leg_knn40S->AddEntry(&SI[7], "Single", "l");
  HI[7].Draw();
  LI[7].Draw("same");
  SI[7].Draw("same");
  leg_knn40S->Draw();
  c_knn40S->SetLogy();
  c_knn40S->SaveAs("knn40S.eps");

  TCanvas* c_knn40B = new TCanvas();
  HI[11].SetTitle("Distribution of TrkPhFrac (Background)");
  HI[11].GetXaxis()->SetTitle("Fraction of Track Hits (Weighted)");
  HI[11].GetXaxis()->CenterTitle();
  HI[11].GetXaxis()->SetTitleOffset(1.2);
  HI[11].SetLineColor(1);
  LI[11].SetLineColor(2);
  SI[11].SetLineColor(3);
  HI[11].SetStats(0);
  LI[11].SetStats(0);
  SI[11].SetStats(0);
  TLegend* leg_knn40B = new TLegend(0.17,0.72,0.37,0.87);
  leg_knn40B->AddEntry(&HI[11], "High Intensity", "l");
  leg_knn40B->AddEntry(&LI[11], "Low Intensity", "l");
  leg_knn40B->AddEntry(&SI[11], "Single", "l");
  HI[11].Draw();
  LI[11].Draw("same");
  SI[11].Draw("same");
  leg_knn40B->Draw();
  c_knn40B->SetLogy();
  c_knn40B->SaveAs("knn40B.eps");
}

int main() {
  gErrorIgnoreLevel = kError;
  Welcome();

  // Create Data Structure containing TRAINING SET and TEST QUERIES for HIGH-LOW-SINGLE
  HIPoints.clear();
  LIPoints.clear();
  SIPoints.clear();
  HIPoints = Initialize("./I4.9E14fullDST.root", 220000, 2, 1);
  LIPoints = Initialize("./I2.5E15fullDST.root", 220000, 2, 2);
  SIPoints = Initialize("./ISinglefullDST.root", 220000, 2, 3);

  // Make kNN Variable Histograms for HIGH-LOW-SINGLE
  std::vector<TH1D> HIkNNVarHistCollection;
  std::vector<TH1D> LIkNNVarHistCollection;
  std::vector<TH1D> SIkNNVarHistCollection;
  std::vector<TH1D> HIkNNVarHistCollectionCopy1;
  std::vector<TH1D> LIkNNVarHistCollectionCopy1;
  std::vector<TH1D> SIkNNVarHistCollectionCopy1;
  std::vector<TH1D> HIkNNVarHistCollectionCopy2;
  std::vector<TH1D> LIkNNVarHistCollectionCopy2;
  std::vector<TH1D> SIkNNVarHistCollectionCopy2;
  HIkNNVarHistCollection = MakeVariableHistogram(HIPoints.at(0), "High");
  LIkNNVarHistCollection = MakeVariableHistogram(LIPoints.at(0), "Low");
  SIkNNVarHistCollection = MakeVariableHistogram(SIPoints.at(0), "Single");
  HIkNNVarHistCollectionCopy1 = HIkNNVarHistCollection;
  LIkNNVarHistCollectionCopy1 = LIkNNVarHistCollection;
  SIkNNVarHistCollectionCopy1 = SIkNNVarHistCollection;
  HIkNNVarHistCollectionCopy2 = HIkNNVarHistCollection;
  LIkNNVarHistCollectionCopy2 = LIkNNVarHistCollection;
  SIkNNVarHistCollectionCopy2 = SIkNNVarHistCollection;
  PlotkNNVariables(HIkNNVarHistCollection, LIkNNVarHistCollection, SIkNNVarHistCollection);


  return 0;
}
