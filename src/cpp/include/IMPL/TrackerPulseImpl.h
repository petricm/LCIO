#ifndef IMPL_TrackerPulseImpl_H
#define IMPL_TrackerPulseImpl_H 1

#include "EVENT/TrackerPulse.h"
#include "AccessChecked.h"

#define TRKPULSENCOVMATRIX 3

namespace IMPL {

/** Default implementation of TrackerPulse.
 * 
 * @author gaede
 * @version $Id: TrackerPulseImpl.h,v 1.4 2010-05-12 14:50:00 engels Exp $
 */

  class TrackerPulseImpl :  public EVENT::TrackerPulse , public AccessChecked {
    
  public: 
    
    /** Default Constructor - initializes all data to 0's. 
     */
    TrackerPulseImpl() ;
    
    /// default copy constructor - use with care
    TrackerPulseImpl(const TrackerPulseImpl&) = default ;

    /// default assignment operator - use with care
    TrackerPulseImpl& operator=(const TrackerPulseImpl&) = default ;

    /// Destructor.
    ~TrackerPulseImpl() override ;
    
    int id() const override { return simpleUID() ; }
    

    /** Returns the first detector specific (geometrical) cell id.
     */
    int getCellID0() const override { return _cellID0 ; } 
    
    /** Returns the second detector specific (geometrical) cell id. Optional, check/set 
     *  flag(LCIO::TRAWBIT_ID1)==1.
     */
    int getCellID1() const override { return _cellID1 ; } 
    
    /** The time of the pulse.
     */
    float getTime() const override { return _time ; }

    // The time error
    //virtual float getTimeError() const { return _timeError ; }

    /** The integrated charge of the pulse // FIXME: unit ?.
     */
    float getCharge() const override { return _charge ; }

    //The charge error
    //virtual float getChargeError() const { return _chargeError ; }

    /** Covariance matrix of the charge (c) and time (t) measurements. Stored as lower triangle matrix, i.e.
     *  cov(c,c) , cov(t,c) , cov(t,t).
     *  Optional, check/set flag(LCIO::TRAWBIT_CM)==1.
     */
    const EVENT::FloatVec & getCovMatrix() const override { return _cov ; }


    /** The quality bit flag of the pulse - use the defined constants for referring to the bits.
     */
    int getQuality() const override { return _quality ; }
    
    /** Optionally the TrackerData that has been uesed to create the pulse
     *  can be stored with the pulse - NULL if none. Check the quality bits for reason
     *  why the spectrum has been stored for the pulse.
     */
    EVENT::TrackerData * getTrackerData() const override { return _corrData ; } 
  

    // setter methods
    void setCellID0( int cellID0 ) ; 
    void setCellID1( int cellID1 ) ; 
    void setTime( float time ) ; 
    //void setTimeError( float timeError ) ; 
    void setCharge( float charge ) ; 
    //void setChargeError( float chargeError ) ; 
    //void setCovMatrix( const float cov[TRKPULSENCOVMATRIX] ) ;
    void setCovMatrix( const float* cov ) ;
    void setCovMatrix( const EVENT::FloatVec & ) ;
    void setQuality( int quality ) ; 
    void setQualityBit( int bit , bool val=true ) ; 
    void setTrackerData( EVENT::TrackerData * corrData ) ; 
    
protected:

    int _cellID0{0} ;
    int _cellID1{0} ;
    float _time{0} ;
    float _charge{0} ;
    int   _quality{0} ;
    EVENT::FloatVec _cov ;
    EVENT::TrackerData* _corrData{nullptr} ;
    
  }; // class
} // namespace IMPL
#endif /* ifndef IMPL_TrackerPulseImpl_H */
