#include "run.hh"

MyRunAction::MyRunAction()
{

    G4GenericAnalysisManager *man = G4GenericAnalysisManager::Instance();
    man->SetDefaultFileType("root");
    man->CreateNtuple("Hits", "Hits");
    man->CreateNtupleIColumn("fEvent");
    man->CreateNtupleDColumn("fX");
    man->CreateNtupleDColumn("fY");
    man->CreateNtupleDColumn("fZ");
    man->FinishNtuple(0);
}

MyRunAction::~MyRunAction() {}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
    G4int runNum = run->GetRunID();
    std::stringstream strRunID;
    strRunID << runNum;
    G4GenericAnalysisManager *man = G4GenericAnalysisManager::Instance();
    man->OpenFile("output" + strRunID.str() + ".root");
}

void MyRunAction::EndOfRunAction(const G4Run *)
{

    G4GenericAnalysisManager *man = G4GenericAnalysisManager::Instance();

    // man->FillNtupleIColumn(0, 12);
    // man->FillNtupleIColumn(1, 2);
    // man->FillNtupleIColumn(2, 3);
    // man->FillNtupleIColumn(3, 4);
    // man->AddNtupleRow();
    man->Write();
    man->CloseFile();
}