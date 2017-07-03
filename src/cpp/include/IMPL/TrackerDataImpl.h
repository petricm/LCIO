#ifndef IMPL_TrackerDataImpl_H
#define IMPL_TrackerDataImpl_H 1

#include "EVENT/TrackerData.h"
#include "AccessChecked.h"

namespace IMPL {

/** Default implementation of TrackerData.
 * 
 * @author gaede
 * @version $Id: TrackerDataImpl.h,v 1.2 2006-08-04 16:52:46 gaede Exp $
 */

class TrackerDataImpl :  public EVENT::TrackerData , public AccessChecked {

public: 

  /** Default Constructor - initializes all data to 0's. 
   */
  TrackerDataImpl() ;
  
  /// Destructor.
  ~TrackerDataImpl() override ;
  
  int id() const override { return simpleUID() ; }
  
  /** Returns the first detector specific (geometrical) cell id.
   */
  int getCellID0() const override { return _cellID0 ; } 
  
  /** Returns the second detector specific (geometrical) cell id. Optional, check/set 
   *  flag(LCIO::TRAWBIT_ID1)==1.
   */
  int getCellID1() const override { return _cellID1 ; } 
  
  /** Returns the time.
   */
  float getTime() const override { return _time ; } 
  
  /** The calibrated ADC values.
   */
  const EVENT::FloatVec & getChargeValues() const override { return _charge ; }
  

  void setCellID0( int cellID0 ) ; 
  void setCellID1( int cellID1 ) ; 
  void setTime( float time ) ; 

  /** Set the charge vector by copying the values. 
   */
  void setChargeValues( const EVENT::FloatVec & charge ) ;

  /** Allows direct access to the charge vector.
   *  Can be used e.g. to set the values:
   *  raw->chargeValues().clear() ;
   *  raw->chargeValues().resize( n ) ;
   *  raw->chargeValues()[i] = 42. ;
   */
  EVENT::FloatVec & chargeValues() ;
  

protected:

  int _cellID0{0} ;
  int _cellID1{0} ;
  float  _time{0} ;
  EVENT::FloatVec _charge{} ;
  
}; // class
} // namespace IMPL
#endif /* ifndef IMPL_TrackerDataImpl_H */
