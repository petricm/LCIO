#include "CPPFORT/lcsch.h"

#include "lcio.h" 
#include "IMPL/SimCalorimeterHitImpl.h"
#include "IMPL/MCParticleImpl.h"


using namespace lcio ;


PTRTYPE lcschcreate(){
  auto* hit = new SimCalorimeterHitImpl ;
  return C2F_POINTER( LCObject*, hit ) ; 
}
int lcschdelete( PTRTYPE simcalhit ) {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  delete hit ;
  return LCIO::SUCCESS ;
}

// get Methods

int lcschid( PTRTYPE simcalhit ) {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  return hit->id() ;
}

int lcschgetcellid0( PTRTYPE simcalhit )  {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  return hit->getCellID0() ;
}
int lcschgetcellid1( PTRTYPE simcalhit )  {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  return hit->getCellID1() ;
}
float lcschgetenergy( PTRTYPE simcalhit )  {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  return hit->getEnergy() ;
}
int lcschgetposition( PTRTYPE simcalhit, float *pos)  {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  for(int i=0;i<3; *pos++ = hit->getPosition()[i++] ) ;
  return LCIO::SUCCESS ;
}
int lcschgetnmcparticles( PTRTYPE simcalhit )  {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  return hit->getNMCContributions() ;
}

int lcschgetnmccontributions( PTRTYPE simcalhit )  {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  return hit->getNMCContributions() ;
}

PTRTYPE lcschgetparticlecont( PTRTYPE simcalhit, int i)  {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  return C2F_POINTER( LCObject*, hit->getParticleCont( i-1 ) ) ;
}
float lcschgetenergycont( PTRTYPE simcalhit, int i)  {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  return hit->getEnergyCont( i-1 ) ;
}
float lcschgettimecont( PTRTYPE simcalhit, int i)  {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  return hit->getTimeCont( i-1 ) ;
}
int lcschgetpdgcont( PTRTYPE simcalhit, int i)  {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  return hit->getPDGCont( i-1 ) ;
}

// set,add Methods

int lcschsetcellid0( PTRTYPE simcalhit, int id0) {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  hit->setCellID0( id0 ) ;
  return  LCIO::SUCCESS ;
}
int lcschsetcellid1( PTRTYPE simcalhit, int id1) {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  hit->setCellID1( id1 ) ;
  return  LCIO::SUCCESS ;
}
int lcschsetenergy( PTRTYPE simcalhit, float en) {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  hit->setEnergy( en ) ;
  return  LCIO::SUCCESS ;
}
int lcschsetposition( PTRTYPE simcalhit, float pos[3])  {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  hit->setPosition( pos ) ;
  return  LCIO::SUCCESS ;
}
int lcschaddmcparticlecontribution( PTRTYPE simcalhit, PTRTYPE mcparticle, float en, float t, int pdg ) {
  auto* hit = f2c_pointer<SimCalorimeterHitImpl,LCObject>( simcalhit ) ;
  auto* mcp = f2c_pointer<MCParticleImpl,LCObject>( mcparticle ) ;
  hit->addMCParticleContribution( mcp, en, t, pdg ) ;
  return  LCIO::SUCCESS ;
} 
