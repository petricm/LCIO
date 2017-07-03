#include "CPPFORT/lcvec.h"
#include "EVENT/LCIntVec.h"
#include "EVENT/LCFloatVec.h"

using namespace EVENT ;

// define an interface to read a LC string/int/float vector

int lcsvcgetlength(PTRTYPE strvec){
  auto* strVec = reinterpret_cast<LCStrVec*>(strvec) ;
  return strVec->size() ;
}

char* lcsvcgetstringat(PTRTYPE strvec, int index){
  auto* strVec = reinterpret_cast<LCStrVec*>(strvec) ;
  return const_cast<char*>( (*strVec)[index-1].c_str() );
}

int lcivcgetlength(PTRTYPE intvec){
  auto* intVec =  reinterpret_cast<LCIntVec*>(intvec) ;
  return intVec->size() ;
}

int lcivcgetintat(PTRTYPE intvec, int index){
  auto* intVec =  reinterpret_cast<LCIntVec*>(intvec) ;
  return (*intVec)[index-1] ;
}

int lcfvcgetlength(PTRTYPE floatvec){
  auto* floatVec =  reinterpret_cast<LCFloatVec*>(floatvec) ;
  return floatVec->size() ;
}

float lcfvcgetfloatat(PTRTYPE floatvec, int index){
  auto* floatVec =  reinterpret_cast<LCFloatVec*>(floatvec) ;
  return (*floatVec)[index-1] ;
}

// define an interface to read a standard string/int/float vector

int stringvectorgetlength(PTRTYPE strvec){
  auto* strVec = reinterpret_cast<StringVec*>(strvec) ;
  return strVec->size() ;
}

char* stringvectorgetelement(PTRTYPE strvec, int index){
  auto* strVec = reinterpret_cast<StringVec*>(strvec) ;
  return const_cast<char*>( (*strVec)[index-1].c_str() );
}

int intvectorgetlength(PTRTYPE intvec){
  auto* intVec =  reinterpret_cast<IntVec*>(intvec) ;
  return intVec->size() ;
}

int intvectorgetelement(PTRTYPE intvec, int index){
  auto* intVec =  reinterpret_cast<IntVec*>(intvec) ;
  return (*intVec)[index-1] ;
}

int pointervectorgetlength(PTRTYPE pointervec){
  auto* pointerVec =  reinterpret_cast<PointerVec*>(pointervec) ;
  return pointerVec->size() ;
}

PTRTYPE pointervectorgetelement(PTRTYPE pointervec, int index){
  auto* pointerVec =  reinterpret_cast<PointerVec*>(pointervec) ;
  return (*pointerVec)[index-1] ;
}

int floatvectorgetlength(PTRTYPE floatvec){
  auto* floatVec =  reinterpret_cast<FloatVec*>(floatvec) ;
  return floatVec->size() ;
}                          \

float floatvectorgetelement(PTRTYPE floatvec, int index){
  auto* floatVec =  reinterpret_cast<FloatVec*>(floatvec) ;
  return (*floatVec)[index-1] ;
}

