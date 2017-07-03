
#include "CPPFORT/lcrel.h"

#include "lcio.h"
#include "IMPL/LCRelationImpl.h"
#include <iostream>

using namespace lcio ;

PTRTYPE lcrelcreate0(){
  auto* relation = new LCRelationImpl() ;
  return reinterpret_cast<PTRTYPE>( relation ) ;
}

PTRTYPE lcrelcreate(  PTRTYPE objectfrom, PTRTYPE objectto, float weight ){
  auto* objf      = f2c_pointer<LCObject,LCObject>( objectfrom ) ;
  auto* objt      = f2c_pointer<LCObject,LCObject>( objectto ) ;
  auto* relation = new LCRelationImpl( objf, objt, weight ) ;
  return reinterpret_cast<PTRTYPE>( relation ) ;
}

int lcreldelete( PTRTYPE relation ){
  auto* rel = reinterpret_cast<LCRelationImpl*>( relation ) ;
  delete rel ;
  return LCIO::SUCCESS ;
}

int lcrelid( PTRTYPE relation ){
  auto* rel = reinterpret_cast<LCRelationImpl*>( relation ) ;
  return rel->id() ;
}

PTRTYPE lcrelgetfrom( PTRTYPE relation ){
  auto* rel = reinterpret_cast<LCRelationImpl*>( relation ) ;
  LCObject* object    = rel->getFrom() ;
  return reinterpret_cast<PTRTYPE>( object ) ;
}

PTRTYPE lcrelgetto( PTRTYPE relation ){
  auto* rel = reinterpret_cast<LCRelationImpl*>( relation ) ;
  LCObject* object    = rel->getTo() ;
  return reinterpret_cast<PTRTYPE>( object ) ;
}

float lcrelgetweight( PTRTYPE relation ){
  auto* rel = reinterpret_cast<LCRelationImpl*>( relation ) ;
  return rel->getWeight() ;
}

int lcrelsetfrom(PTRTYPE relation, PTRTYPE object ){
  auto* rel = reinterpret_cast<LCRelationImpl*>( relation ) ;
  auto* obj       = f2c_pointer<LCObject,LCObject>( object ) ;
  rel->setFrom( obj ) ;
  return LCIO::SUCCESS ;
}

int lcrelsetto(PTRTYPE relation, PTRTYPE object ){
  auto* rel = reinterpret_cast<LCRelationImpl*>( relation ) ;
  auto* obj       = f2c_pointer<LCObject,LCObject>( object ) ;
  rel->setTo( obj ) ;
  return LCIO::SUCCESS ;
}

int lcrelsetweight(PTRTYPE relation, float weight ){
  auto* rel = reinterpret_cast<LCRelationImpl*>( relation ) ;
  rel->setWeight( weight ) ;
  return LCIO::SUCCESS ;
}

