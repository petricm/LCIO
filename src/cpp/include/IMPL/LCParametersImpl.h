// -*- C++ -*-
#ifndef EVENT_LCPARAMETERSIMPL_H
#define EVENT_LCPARAMETERSIMPL_H 1

#include "EVENT/LCParameters.h"
#include "IMPL/AccessChecked.h"

#include <map>
#include <vector>

namespace IMPL {


  class LCRunHeaderImpl ;
  class LCEventImpl ;
  class LCCollectionVec ;

  typedef std::map< std::string, EVENT::IntVec >    IntMap ;
  typedef std::map< std::string, EVENT::FloatVec >  FloatMap ;
  typedef std::map< std::string, EVENT::StringVec > StringMap ;
  

  /** Implementation of Simple interface to store generic named parameters of type
   *  int, float and string. 
   *  It can be used  to store (user) meta data that is 
   *  run, event or collection dependent. 
   * 
   * @author gaede 
   * @version Jun 23, 2004
   * @see LCRunHeader.parameters()
   * @see LCEvent.parameters()
   * @see LCCollection.parameters()
   */
  
  class LCParametersImpl : public EVENT::LCParameters , public AccessChecked{

    friend class LCRunHeaderImpl ;
    friend class LCEventImpl ;
    friend class LCCollectionVec ;
    
  public: 
    
    LCParametersImpl() ; 
    
    /// Destructor.
    ~LCParametersImpl() override { /* nop */; }
    
    /** Returns the first integer value for the given key.
     */
    int getIntVal(const std::string & key) const override  ;
    
    /** Returns the first float value for the given key.
     */
    float getFloatVal(const std::string & key) const override ;
    
    /** Returns the first string value for the given key.
     */
    const std::string & getStringVal(const std::string & key) const override ;
    
    /** Adds all integer values for the given key to values.
     *  Returns a reference to values for convenience.
     */
    EVENT::IntVec & getIntVals(const std::string & key, EVENT::IntVec & values) const override ;
    
    /** Adds all float values for the given key to values.
     *  Returns a reference to values for convenience.
     */
    EVENT::FloatVec & getFloatVals(const std::string & key, EVENT::FloatVec & values) const override ;
    
    /** Adds all float values for the given key to values.
     *  Returns a reference to values for convenience.
     */
     EVENT::StringVec & getStringVals(const std::string & key, EVENT::StringVec & values) const override ;
    
    /** Returns a list of all keys of integer parameters.
     */
    const EVENT::StringVec & getIntKeys( EVENT::StringVec & keys) const override  ;

    /** Returns a list of all keys of float parameters.
     */
    const EVENT::StringVec & getFloatKeys(EVENT::StringVec & keys)  const override ;

    /** Returns a list of all keys of string parameters.
     */
    const EVENT::StringVec & getStringKeys(EVENT::StringVec & keys)  const override ;
    
    /** The number of integer values stored for this key.
     */ 
    int getNInt(const std::string & key) const override ;
    
    /** The number of float values stored for this key.
     */ 
    int getNFloat(const std::string & key) const override ;
    
    /** The number of string values stored for this key.
     */ 
    int getNString(const std::string & key) const override ;
    
    /** Set integer value for the given key.
     */
    void setValue(const std::string & key, int value) override ;

    /** Set float value for the given key.
     */
    void setValue(const std::string & key, float value) override ;

    /** Set string value for the given key.
     */
    void setValue(const std::string & key, const std::string & value) override ;

    /** Set integer values for the given key.
     */
    void setValues(const std::string & key, const EVENT::IntVec & values) override;

    /** Set float values for the given key.
     */
    void setValues(const std::string & key, const EVENT::FloatVec & values) override;

    /** Set string values for the given key.
     */
    void setValues(const std::string & key, const EVENT::StringVec & values) override;


  protected:

    mutable IntMap _intMap{} ;
    mutable FloatMap _floatMap{} ;
    mutable StringMap _stringMap{} ;
    
  }; // class
} // namespace IMPL
#endif /* ifndef EVENT_LCPARAMETERSIMPL_H */
