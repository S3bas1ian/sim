#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name) {}

MySensitiveDetector::~MySensitiveDetector() {}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
    G4Track *track = aStep->GetTrack();

    track->SetTrackStatus(fStopAndKill);

    G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

    G4ThreeVector posPhoton = preStepPoint->GetPosition();

    // G4cout << "Photon position: " << posPhoton << G4endl;  //not accesible in reality

    const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

    G4int copyNo = touchable->GetCopyNumber();

    // G4cout << "Copy Number: " << copyNo <<G4endl;   //Detector that got triggered

    G4ThreeVector posDetector = touchable->GetVolume()->GetTranslation();

    G4cout << "Detector position: " << posDetector << G4endl;

     // I added this line outside of the tutorial, because the make command raised a warning

    G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

    G4GenericAnalysisManager *man = G4GenericAnalysisManager::Instance();
    man->FillNtupleIColumn(0, evt);
    man->FillNtupleDColumn(1, posDetector[0]);
    man->FillNtupleDColumn(2, posDetector[1]);
    man->FillNtupleDColumn(3, posDetector[2]);
    man->AddNtupleRow();

    return true;
}
