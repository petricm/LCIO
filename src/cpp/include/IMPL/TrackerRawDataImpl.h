#ifndef IMPL_TrackerRawDataImpl_H
#define IMPL_TrackerRawDataImpl_H 1

#include "EVENT/TrackerRawData.h"
#include "AccessChecked.h"

namespace IMPL {

/** Default implementation of TrackerRawData.
 * 
 * @author gaede
 * @version $Id: TrackerRawDataImpl.h,v 1.2 2006-08-04 16:52:47 gaede Exp $
 */

class TrackerRawDataImpl :  public EVENT::TrackerRawData , public AccessChecked {

public: 

  /** Default Constructor - initializes all data to 0's. 
   */
  TrackerRawDataImpl() ;
  
  /// Destructor.
  ~TrackerRawDataImpl() override ;
  
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
  int getTime() const override { return _time ; } 
  
  /** The measured ADC values.
   */
  const EVENT::ShortVec & getADCValues() const override { return _adc ; }
  
  void setCellID0( int cellID0 ) ; 
  void setCellID1( int cellID1 ) ; 
  void setTime( int time ) ; 

  /** Set the ADC vector by copying the values. 
   */
  void setADCValues( const EVENT::ShortVec & adc ) ;

  /** Allows direct access to the adc vector.
   *  Can be used e.g. to set the values:
   *  raw->adcValues().clear() ;
   *  raw->adcValues().resize( n ) ;
   *  raw->adcValues()[i] = 42 ;
   */
  EVENT::ShortVec & adcValues() ;
  

protected:

  int _cellID0{0} ;
  int _cellID1{0} ;
  int _channelID{0} ;
  int  _time{0} ;
  EVENT::ShortVec _adc{} ;
  
}; // class
} // namespace IMPL
#endif /* ifndef IMPL_TrackerRawDataImpl_H */
