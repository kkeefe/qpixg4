// -----------------------------------------------------------------------------
//  G4_QPIX | PrimaryGeneration.h
//
//  Class for the definition of the primary generation action.
//   * Author: Everybody is an author!
//   * Creation date: 14 Aug 2019
// -----------------------------------------------------------------------------

#ifndef PRIMARY_GENERATION_H
#define PRIMARY_GENERATION_H

// GEANT4 includes
#include "G4VUserPrimaryGeneratorAction.hh"

#include "G4Box.hh"
#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4String.hh"

// ROOT includes
#include "Math/SVector.h"
#include "Math/SMatrix.h" 

// Q-Pix includes
#include "Supernova.h"
#include "SupernovaTiming.h"

// ROOT includes
#include "Math/SVector.h"
#include "Math/SMatrix.h" 

// C++ includes
#include <random>

class G4ParticleDefinition;
class G4GenericMessenger;

class PrimaryGeneration : public G4VUserPrimaryGeneratorAction
{

  public:

    PrimaryGeneration();
    virtual ~PrimaryGeneration();
    virtual void GeneratePrimaries(G4Event*);


  protected:

    // GEANT4 dictionary of particles
    G4ParticleTable* particle_table_;

  private:

    G4GenericMessenger* msg_; // Messenger for configuration parameters
    G4String Particle_Type_;
    bool PrintParticleInfo_;
    //double Particle_Energy_;

    bool decay_at_time_zero_;
    bool isotropic_;
    bool override_vertex_position_;
    double vertex_x_;
    double vertex_y_;
    double vertex_z_;

    // rotation angle
    double axis_x_ = 1;
    double axis_y_ = 0;
    double axis_z_ = 0;

    // get a specific neutrino event
    int nEvt_ = -1;
    int fsPdg_ = 0;
    int fsEnergy_ = -1;
    int fsFHC_ = -1;
    int fsRun_ = -1;

    G4GeneralParticleSource * particle_gun_;

    SupernovaTiming * supernova_timing_;

    Supernova * super;

    double detector_length_x_;
    double detector_length_y_;
    double detector_length_z_;

    G4Box* detector_solid_vol_;
    std::string Particle_infoRoot_Path;

    void MARLEYGeneratePrimaries(G4Event*);
    void GENIEGeneratePrimaries(G4Event*);
    void ROOTGeneratePrimaries(G4Event * event);

    std::default_random_engine generator_;
    std::normal_distribution< double > distribution_;

    ROOT::Math::SMatrix< double, 3 > Rotation_Matrix(G4ThreeVector, G4ThreeVector);
    ROOT::Math::SMatrix< double, 3 > Rotation_Matrix(G4ThreeVector, G4ThreeVector);
};

void rotateParticle(const ROOT::Math::SMatrix< double, 3 >&, G4PrimaryParticle*);

#endif
