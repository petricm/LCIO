
#include "CPPFORT/lcrnv.h"
#include "UTIL/LCRelationNavigator.h"

#include "lcio.h"
#include "IMPL/LCRelationImpl.h"
#include "EVENT/LCCollection.h"
#include "EVENT/LCObject.h"
#include "LCIOSTLTypes.h"

#include <iostream>

using namespace lcio ;

 PTRTYPE lcrnvcreate( const char* fromType, const char* toType ){
   LCRelationNavigator*  relation = new LCRelationNavigator( fromType, toType ) ;
   return reinterpret_cast<PTRTYPE>( relation ) ;

 }

 int lcrnvdelete( PTRTYPE relation ){
   auto* rel = reinterpret_cast<LCRelationNavigator*>( relation ) ;
   delete rel ;
   return LCIO::SUCCESS ;

 }

 PTRTYPE lcrnvcreatefromcollection( PTRTYPE collection ){
   auto*  col = reinterpret_cast<LCCollection*>( collection ) ;
   auto*  relation = new LCRelationNavigator( col ) ;
   return reinterpret_cast<PTRTYPE>( relation ) ;

 }

 char* lcrnvgetfromtype( PTRTYPE relation ){
   auto* rel = reinterpret_cast<LCRelationNavigator*>( relation ) ;
   return const_cast<char*>(rel->getFromType().c_str() ) ;
 }

 char* lcrnvgettotype( PTRTYPE relation ){
   auto* rel = reinterpret_cast<LCRelationNavigator*>( relation ) ;
   return const_cast<char*>(rel->getToType().c_str() ) ;
 }

 PTRTYPE lcrnvgetrelatedtoobjects( PTRTYPE relation, PTRTYPE object ){
   auto* rel = reinterpret_cast<LCRelationNavigator*>( relation ) ;
   auto* obj       = f2c_pointer<LCObject,LCObject>( object ) ;
   const LCObjectVec& vec    = rel->getRelatedToObjects( obj ) ;
   return reinterpret_cast<PTRTYPE>( &vec ) ;
 }

 PTRTYPE lcrnvgetrelatedfromobjects( PTRTYPE relation, PTRTYPE object ){
   auto* rel = reinterpret_cast<LCRelationNavigator*>( relation ) ;
   auto* obj       = f2c_pointer<LCObject,LCObject>( object ) ;
   const LCObjectVec& vec    = rel->getRelatedFromObjects( obj ) ;
   return reinterpret_cast<PTRTYPE>( &vec ) ;
 }

 PTRTYPE lcrnvgetrelatedtoweights ( PTRTYPE relation, PTRTYPE object ){
   auto* rel = reinterpret_cast<LCRelationNavigator*>( relation ) ;
   auto* obj       = f2c_pointer<LCObject,LCObject>( object ) ;
   const FloatVec &  vec     = rel->getRelatedToWeights( obj ) ;
   return reinterpret_cast<PTRTYPE>( &vec ) ;
 }

 PTRTYPE lcrnvgetrelatedfromweights ( PTRTYPE relation, PTRTYPE object ){
   auto* rel = reinterpret_cast<LCRelationNavigator*>( relation ) ;
   auto* obj       = f2c_pointer<LCObject,LCObject>( object ) ;
   const FloatVec &  vec     = rel->getRelatedFromWeights( obj ) ;
   return reinterpret_cast<PTRTYPE>( &vec ) ;
 }

 int lcrnvgaddrelation(PTRTYPE relation, PTRTYPE objectfrom, PTRTYPE objectto, float weight ){
   auto* rel = reinterpret_cast<LCRelationNavigator*>( relation ) ;
   auto* objf      = f2c_pointer<LCObject,LCObject>( objectfrom ) ;
   auto* objt      = f2c_pointer<LCObject,LCObject>( objectto ) ;
   rel->addRelation( objf, objt, weight ) ;
   return LCIO::SUCCESS ;
 }

 int lcrnvgremoverelation(PTRTYPE relation, PTRTYPE objectfrom, PTRTYPE objectto ){
   auto* rel = reinterpret_cast<LCRelationNavigator*>( relation ) ;
   auto* objf      = f2c_pointer<LCObject,LCObject>( objectfrom ) ;
   auto* objt      = f2c_pointer<LCObject,LCObject>( objectto ) ;
   rel->removeRelation( objf, objt ) ;
   return LCIO::SUCCESS ;
 }

 PTRTYPE lcrnvcreatecollection(PTRTYPE relation ){
   auto* rel = reinterpret_cast<LCRelationNavigator*>( relation ) ;
   LCCollection*  col = rel->createLCCollection() ;
   return reinterpret_cast<PTRTYPE>( col ) ;

 }


