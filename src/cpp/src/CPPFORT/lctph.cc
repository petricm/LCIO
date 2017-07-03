#include "CPPFORT/lctph.h"

#include "lcio.h" 
#include "IMPL/TPCHitImpl.h"

using namespace lcio ;

PTRTYPE lctphcreate(){
  auto* hit = new TPCHitImpl ;
  return C2F_POINTER( LCObject*, hit ) ;
}

int lctphdelete( PTRTYPE hit ){
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  delete tph ;
  return LCIO::SUCCESS ;
}

int lctphid( PTRTYPE hit )  {
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  return tph->id() ;
}

int lctphgetcellid( PTRTYPE hit ){
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  return tph->getCellID() ;
}
float lctphgettime( PTRTYPE hit ){
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  return tph->getTime() ;
}

float lctphgcharge( PTRTYPE hit ){
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  return tph->getCharge() ;
}
int lctphgetquality( PTRTYPE hit ) {
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  return tph->getQuality() ;
}

int lctphgetnrawdatawords( PTRTYPE hit ) {
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  return tph->getNRawDataWords() ;
}
int lctphgetrawdataword( PTRTYPE hit, int i) {
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  return tph->getRawDataWord( i-1 ) ;
}


int lctphsetcellid( PTRTYPE hit, int id ){
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  tph->setCellID( id ) ;
  return LCIO::SUCCESS ;
}
int lctphsettime( PTRTYPE hit, float t ){
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  tph->setTime( t ) ;
  return LCIO::SUCCESS ;
}
int lctphsetcharge( PTRTYPE hit, float c ){
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  tph->setCharge( c ) ;
  return LCIO::SUCCESS ;
}
int lctphsetquality( PTRTYPE hit, int q ){
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  tph->setQuality( q ) ;
  return LCIO::SUCCESS ;
} 
int lctphsetrawdata( PTRTYPE hit, int* rawData, int size ){
  auto* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
  tph->setRawData( rawData, size ) ;
  return LCIO::SUCCESS ;
}
// int lctphinitrawdataarray( PTRTYPE hit, int size ){
//   TPCHitImpl* tph = f2c_pointer<TPCHitImpl,LCObject>( hit ) ;
//   tph->initRawDataArray( size ) ;
//   return LCIO::SUCCESS ;
// }




