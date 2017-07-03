/**Fortran interface - define the length of pointers
 * this has to made machine independent ...
 * 
 * @author Vogt
 * @version Sep 30, 2003
 * @modif   Mar 19, 2004 (PTRTYPE changed to long - 64bit compatibility
 *
 */
#ifndef CPOINTER_H
#define CPOINTER_H 1

using PTRTYPE = long ;
#define CFORTRANPNTR LONG
#define CFORTRANPNTRV LONGV

#include <vector>
using PointerVec = std::vector<PTRTYPE> ;

/** Template for casting from integers to LCIO classes 
 * First template is the resulting type, second argument is the original 
 * type that was used when the pointer was passed to fortran.
 */

template<class T, class O> T* f2c_pointer(PTRTYPE ptr){

  if(! (ptr) ) return nullptr  ; 

  auto*  o_ptr = reinterpret_cast<O*>( ptr ) ;

  return dynamic_cast<T*>( o_ptr ) ; 
}

#define C2F_POINTER(T,ptr) reinterpret_cast<PTRTYPE>( dynamic_cast<T>( (ptr) ) )

#endif
