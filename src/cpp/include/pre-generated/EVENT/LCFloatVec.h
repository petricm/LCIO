// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef EVENT_LCFLOATVEC_H
#define EVENT_LCFLOATVEC_H 1

#include "EVENT/LCObject.h"
#include "LCIOSTLTypes.h"

 #include "IMPL/AccessChecked.h" // FIXME: EVENT shouldn't  depend on IMPL ...

namespace EVENT {

/** Float vector used for user extensions.
 * The cpp implementation is a std::vector<float>
 * 
 * @author gaede 
 * @version Mar 12, 2003
 * @see LCObject
 */

class LCFloatVec : public LCObject, public FloatVec {

public: 
    /// Destructor.
    ~LCFloatVec() override { /* nop */; }


    using lcobject_type = EVENT::LCFloatVec ;

    public:
      int id() const override { return _acc.simpleUID() ; } 
    protected:
      IMPL::AccessChecked _acc{} ;
}; // class
} // namespace EVENT
#endif /* ifndef EVENT_LCFLOATVEC_H */
