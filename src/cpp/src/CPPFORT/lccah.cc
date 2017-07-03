#include "CPPFORT/lccah.h"

#include "lcio.h" 
#include "IMPL/CalorimeterHitImpl.h"

using namespace lcio ;


PTRTYPE lccahcreate(){
  auto* hit = new CalorimeterHitImpl ;
  return C2F_POINTER( LCObject*, hit ) ; 
}
int lccahdelete( PTRTYPE calhit ) {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  delete hit ;
  return LCIO::SUCCESS ;
}
int lccahid( PTRTYPE calhit )  {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  return hit->id() ;
}

int lccahgetcellid0( PTRTYPE calhit )  {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  return hit->getCellID0() ;
}
int lccahgetcellid1( PTRTYPE calhit )  {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  return hit->getCellID1() ;
}
float lccahgetenergy( PTRTYPE calhit )  {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  return hit->getEnergy() ;
}
float lccahgetenergyerr( PTRTYPE calhit )  {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  return hit->getEnergyError() ;
}
float lccahgettime( PTRTYPE calhit )  {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  return hit->getTime() ;
}
int lccahgetposition( PTRTYPE calhit, float *pos)  {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  for(int i=0;i<3; *pos++ = hit->getPosition()[i++] ) ;
  return LCIO::SUCCESS ;
}
int lccahgettype( PTRTYPE calhit )  {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  return hit->getType() ;
}

PTRTYPE lccahgetrawhit( PTRTYPE calhit )  {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  return C2F_POINTER( LCObject*, hit->getRawHit() ) ;
}

int lccahsetcellid0( PTRTYPE calhit, int id0) {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  hit->setCellID0( id0 ) ;
  return  LCIO::SUCCESS ;
}
int lccahsetcellid1( PTRTYPE calhit, int id1) {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  hit->setCellID1( id1 ) ;
  return  LCIO::SUCCESS ;
}
int lccahsetenergy( PTRTYPE calhit, float en) {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  hit->setEnergy( en ) ;
  return  LCIO::SUCCESS ;
}
int lccahsetenergyerr( PTRTYPE calhit, float enerr) {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  hit->setEnergyError( enerr ) ;
  return  LCIO::SUCCESS ;
}
int lccahsettime( PTRTYPE calhit, float time) {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  hit->setTime( time ) ;
  return  LCIO::SUCCESS ;
}
int lccahsetposition( PTRTYPE calhit, float pos[3])  {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  hit->setPosition( pos ) ;
  return  LCIO::SUCCESS ;
}
int lccahsettype( PTRTYPE calhit, int type) {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  hit->setType( type ) ;
  return LCIO::SUCCESS ;
}
int lccahsetrawhit(PTRTYPE calhit, PTRTYPE rawHit) {
  auto* hit = f2c_pointer<CalorimeterHitImpl,LCObject>( calhit ) ;
  hit->setRawHit( f2c_pointer<LCObject,LCObject>( rawHit ) ) ; 
  return LCIO::SUCCESS ;
}

