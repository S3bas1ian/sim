#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{

    fParticleGun = new G4ParticleGun(4); // arg = particle per event

    pos = new G4ThreeVector(0, 0, 0);

    mom = new G4ThreeVector(0, 0, 1);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{

    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName1 = "proton";
    particle1 = particleTable->FindParticle("proton");
    G4String particleName2 = "electron";
    particle2 = particleTable->FindParticle("neutron");

    G4cout << particle1 << G4endl;

    fParticleGun->SetParticlePosition(*pos);
    fParticleGun->SetParticleMomentumDirection(*mom);
    fParticleGun->SetParticleMomentum(100. * GeV);
    fParticleGun->SetParticleDefinition(particle1);

    fParticleGun->GeneratePrimaryVertex(anEvent);
    G4cout << "particle 1" << G4endl;

    fParticleGun->SetParticlePosition(*pos);
    fParticleGun->SetParticleMomentumDirection(*mom);
    fParticleGun->SetParticleMomentum(100. * GeV);
    fParticleGun->SetParticleDefinition(particle2);

    fParticleGun->GeneratePrimaryVertex(anEvent);
    G4cout << "particle 2" << G4endl;
}