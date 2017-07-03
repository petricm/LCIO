#ifndef EVENT_RAWCALORIMETERHITIMPL_H
#define EVENT_RAWCALORIMETERHITIMPL_H 1


#include "EVENT/MCParticle.h"
#include "EVENT/RawCalorimeterHit.h"
#include <vector>
#include "AccessChecked.h"

namespace IMPL {
  
  
/** Implementation of the real data RawCalorimeterHit.
 * 
 * @author gaede
 * @version $Id: RawCalorimeterHitImpl.h,v 1.3 2006-08-04 16:52:46 gaede Exp $
 */

  class RawCalorimeterHitImpl : public EVENT::RawCalorimeterHit , public AccessChecked {
    
  public: 
    
    /** Default constructor, initializes values to 0.
     */
    RawCalorimeterHitImpl() ;

    /// Destructor.
    ~RawCalorimeterHitImpl() override ;
    
    int id() const override { return simpleUID() ; }

    /** Returns the detector specific (geometrical) cell id.
     */
    int getCellID0() const override ;

    /** Returns the second detector specific (geometrical) cell id. Optional, check/set 
     *  flag(LCIO::RCHBIT_ID1)==1.
     */
    int getCellID1() const override ;

    /** Returns the amplitude of the hit in ADC counts.
     */
    int getAmplitude() const override ;

    /** Returns a time stamp for the hit. Optional, check/set 
     *  flag(LCIO::RCHBIT_TIME)==1.
     */
    int getTimeStamp() const override ;

    
    void setCellID0(int id0) ;

    /** Sets the second cell id;
     *  Only store if the flag word (bit CHBIT_ID1) 
     *  of the collection is set. Default is to store only cellid0.
     */
    void setCellID1(int id1) ;
    
    /** Sets the amplitude.
     */
    void setAmplitude(int amplitude) ;
    
    /** Set the time stamp
     */
    void setTimeStamp(int time) ;

  protected:

    int _cellID0{0} ;
    int _cellID1{0} ;
    int _amplitude{0} ;
    int _timeStamp{0} ;
    
  }; // class
} // namespace IMPL
#endif /* ifndef EVENT_RAWCALORIMETERHITIMPL_H */
