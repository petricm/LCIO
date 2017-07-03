// -*- C++ -*-
#ifndef EVENT_LCWGTRELATIONIMPL_H
#define EVENT_LCWGTRELATIONIMPL_H 1

#include <vector>
#include <map>

#include "EVENT/LCRelation.h"
#include "EVENT/LCObject.h"
#include "AccessChecked.h"



namespace IMPL {
  
  /** Implementation of the LCRelation.
   * 
   * @author gaede 
   * @version $id: $
   */
  class LCRelationImpl : public EVENT::LCRelation, public AccessChecked {
    
    public:

    LCRelationImpl()  = default;
    LCRelationImpl( EVENT::LCObject* from, EVENT::LCObject* to , float weight=1.0f ) : _from(from),
											  _to(to),
											  _weight(weight) {}
    /// default copy constructor - use with care
    LCRelationImpl(const LCRelationImpl&) = default ;

    /// default assignment operator - use with care
    LCRelationImpl& operator=(const LCRelationImpl&) = default ;

    ~LCRelationImpl() override= default;

    int id() const override { return simpleUID() ; }

    EVENT::LCObject * getFrom() const override { return _from ; }
    EVENT::LCObject * getTo() const override { return _to ; } 
    float getWeight() const override { return _weight ; } 
    
    void setFrom( EVENT::LCObject* from ) { _from = from ; }
    void setTo( EVENT::LCObject* to ) { _to = to ; }
    void setWeight( float weight ) { _weight = weight ; }
    

  protected:
    EVENT::LCObject* _from{nullptr} ;
    EVENT::LCObject* _to{nullptr} ;
    float _weight{1.0f} ;

}; // class
} // namespace IMPL
#endif /* ifndef EVENT_LCRELATIONIMPL_H */
