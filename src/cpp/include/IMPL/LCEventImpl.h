#ifndef EVENT_LCEVENTIMPL_H
#define EVENT_LCEVENTIMPL_H 1

#include <string>
#include <map>
#include <set>
#include "EVENT/LCEvent.h"
#include "EVENT/LCCollection.h"
// #include "EVENT/LCRelation.h"
#include "EVENT/LCIO.h"
#include "LCIOTypes.h"
#include "AccessChecked.h"
#include "LCParametersImpl.h"

namespace IMPL{
  
  //class  EVENT::LCCollection ;
  
  typedef std::map<std::string,EVENT::LCCollection*> LCCollectionMap ; 
  using LCCollectionSet = std::set<EVENT::LCCollection *> ;
  //   typedef std::map<std::string,EVENT::LCRelation*> LCRelationMap ; 
  
  /**Implementation of the main event class. This is used by  
   * LCIO for reading events from file.
   * 
   * @author gaede
   * @version Mar 5, 2003
   * @see LCEvent
   * @see LCCollection
   */
  class LCEventImpl : public EVENT::LCEvent, public AccessChecked {
    
  public: 
    LCEventImpl() ;
    /** Copy contructor, creates a deep copy of the event.
     * Not yet - needs pointer chasing ...
     */
    //    LCEventImpl(const EVENT::LCEvent& evt) ;  // copy c'tor
    
    /**Destructor.
     */
    ~LCEventImpl() override ; 
    
    /** Return the run number off this event.
     */
    int getRunNumber() const override ;
    
    /** Returns this event's number .
     */
    int getEventNumber() const override ;
    
    /** Returns the name of the detector setup used in the simulation.
     */
    const std::string & getDetectorName() const override ;
    
    /** Returns the time stamp of the event.
     */
    EVENT::long64 getTimeStamp() const override ;
    
    /** Returns the event weight.
     */
    double getWeight() const override  ;

    /** Returns the names of the collections in the  event.
     */
    const std::vector<std::string>  * getCollectionNames() const override;
    
    /** Returns the collection for the given name.
     *
     * @throws DataNotAvailableException
     */
    EVENT::LCCollection * getCollection(const std::string & name) const 
     throw (EVENT::DataNotAvailableException, std::exception) override ;

    /** Returns the collection for the given name and transfers the ownership of the collection
     *  to the caller. The caller is responsible for deleting the collection _after_ the Event is 
     *  deleted. The collection is still in the event but flagged as transient 
     *  after the call returns.<br>
     *  This is usefull when you want to keep the collection for the next events.<br>
     *  Use with care!
     * @throws DataNotAvailableException
     */
    EVENT::LCCollection * takeCollection(const std::string & name) const 
      throw (EVENT::DataNotAvailableException, std::exception ) override ;

    /** Adds a collection with the given name (has to be a valid C/C++ variable name). 
     *	Throws an exception if the name already
     *  exists in the event. NB: Adding collections is allowed even when the event is 'read only'.
     *
     *@see validateCollectionName
     *@throws EventException
     */ 
    void addCollection(EVENT::LCCollection * col, const std::string & name)  
      throw (EVENT::EventException, std::exception) override ;
    
    /** Removes (and deletes) the collection with name (if it exists in the event). 
     * Throws an exception if the event is 'read only' as defined by the read mode in LCReader.
     *
     *@throws ReadOnlyException
     */ 
    void removeCollection(const std::string & name) throw (EVENT::ReadOnlyException, std::exception) override  ;
    

//     //fg20040528:   added relations to the event
//     /** Returns the names of the relations in the  event.
//      */
//     virtual const std::vector<std::string>  * getRelationNames() const ;

//     /** Returns the relation for the given name.
//      *
//      * @throws DataNotAvailableException
//      */
//     virtual EVENT::LCRelation * getRelation(const std::string & name) const throw (EVENT::DataNotAvailableException, std::exception)  ;

//     /** Adds a relation with the given name. Throws an exception if the name already
//      * exists in the event. NB: Adding relations is allowed even when the event is 'read only'.
//      * 
//      *@throws EventException
//      */ 
//     virtual void addRelation(EVENT::LCRelation * col, const std::string & name) throw (EVENT::EventException, std::exception)  ;

//     /** Removes (and deletes) the relation with name (if it exists in the event). 
//      * Throws an exception if the event is 'read only' as defined by the read mode in LCReader.
//      *
//      *@throws ReadOnlyException
//      */ 
//     virtual void removeRelation(const std::string & name) throw (EVENT::ReadOnlyException, std::exception)  ;

    /** Parameters defined for this event.
     */
    const EVENT::LCParameters & getParameters() const override { return _params ; }

    /** Parameters defined for this run.
     */
    EVENT::LCParameters & parameters() override { return _params ; }

    //---- set methods -----
    /** Sets the run number.
     */
    void setRunNumber( int rn ) ;
    
    /** Sets the event number.
     */
    void setEventNumber( int en ) ;
    
    /** Sets the detector name.
     */
    void setDetectorName(const std::string& dn ) ;
    
    /** Sets the event time stamp.
     */
    void setTimeStamp(EVENT::long64 ts) ;
       
    /** Set the event weight.
     */
    void setWeight(double w) ;
     
  protected:
    void setAccessMode( int accessMode ) ;
    
    /**Tests the validity of a collection name. LCIO only accepts collection names starting with 
     * (regular expression) [A-Za-z_] and continuing with [A-Za-z0-9_] (C/C++ variable name).
     */
    bool validateCollectionName( const char* name ) ;
      
    // data members - declared protected to be accessible 
    // for friends of sub classes ...
    
  protected:  
    int _runNumber{0} ;
    int _eventNumber{0} ;
    EVENT::long64 _timeStamp{0} ;
    std::string _detectorName ;
    
    // map has to be defined mutable in order to use _map[]  for const methods ...
    mutable LCCollectionMap _colMap{} ;
    mutable std::vector<std::string> _colNames{} ;
    
    LCParametersImpl _params{} ;
    
    // set of collections that are not owned by the event anymore
    mutable LCCollectionSet _notOwned{} ;
    

  }; // class

} // namespace IMPL

#endif /* ifndef EVENT_LCEVENTIMPL_H */
