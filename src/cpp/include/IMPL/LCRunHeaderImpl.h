#ifndef EVENT_LCRUNHEADERIMPL_H
#define EVENT_LCRUNHEADERIMPL_H 1

#include <string>

#include "EVENT/LCIO.h"
#include "EVENT/LCRunHeader.h"
#include "AccessChecked.h"
#include "LCParametersImpl.h"

namespace IMPL {

/** Implementation of LCRunHeader.
 * 
 * @author gaede
 * @version Mar 11, 2003
 */
  class LCRunHeaderImpl : public EVENT::LCRunHeader, public AccessChecked {

  public: 

    LCRunHeaderImpl() ;

    /// Destructor.
    ~LCRunHeaderImpl() override ; 

    int id() const override { return simpleUID() ; }

    /** Returns the run number.
     */
    int getRunNumber() const override ;

    /** Returns the name of the detector setup used in the simulation.
     */
    const std::string & getDetectorName() const override ;

    /** Description of the simulation conditions, e.g. physics channels.
     */		 
    const std::string & getDescription() const override ;

    /** Returns the names of the active subdetectors
     *  used in the simulation.
     */ 
    const std::vector<std::string> * getActiveSubdetectors() const override ;


    /** Parameters defined for this run.
     */
    const EVENT::LCParameters & getParameters() const override { return _params ; } 

    /** Parameters defined for this run.
     */
    EVENT::LCParameters & parameters() override { return _params ; } 


    // set methods

    /** Sets the run number.
     */
    void setRunNumber( int rn) ;

    /** Sets the detector name.
     */
    void setDetectorName(const std::string& dn) ;

    /** Sets the description of the run.
     */
    void setDescription(const std::string& dsc) ;

    /** Adds an active sub detector name.
     */
    void addActiveSubdetector(const std::string&  adn) ;


  protected:
    void setReadOnly( bool readOnly ) override ;

  protected:
    
    int _runNumber{0} ;
    std::string _detectorName{} ;
    std::string _description{} ;
    std::vector<std::string> _activeSubdetectors{} ;

    LCParametersImpl _params{} ;

  }; // class
} // namespace IMPL
#endif /* ifndef IMPL_LCRUNHEADERIMPL_H */
