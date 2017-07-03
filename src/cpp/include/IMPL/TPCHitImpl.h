#ifndef IMPL_TPCHITIMPL_H
#define IMPL_TPCHITIMPL_H 1

#include "EVENT/TPCHit.h"
#include "AccessChecked.h"

namespace IMPL {

/** Implementation of the real data TPCHit.
 * 
 * @author gaede
 * @version Sep 11, 2003
 */

class TPCHitImpl :  public EVENT::TPCHit , public AccessChecked {

public: 

  /** Default Constructor - initializes all data to 0's. 
   */
  TPCHitImpl() ;

  /// default copy constructor - use with care
  TPCHitImpl(const TPCHitImpl&) = default ;

  /// default assignment operator - use with care
  TPCHitImpl& operator=(const TPCHitImpl&) = default ;

  /// Destructor.
  ~TPCHitImpl() override ;
  
  int id() const override { return simpleUID() ; }
    
  /** Returns the detector specific cell id.
   */
  int getCellID() const override;
  
  /** Returns the  time of the hit.
   */
  float getTime() const override;
  
  /** Returns the integrated charge of the hit.
   */
  float getCharge() const override;
  
  /** Returns a quality flag for the hit.
   */
  int getQuality() const override;
  
  /** Return the number of raw data (32-bit) words stored for the hit.
   *  Check the flag word (bit TPCBIT_RAW) of the collection if raw data is
   *  stored at all.
   */
  int getNRawDataWords()const override;
  
  /** Return the raw data (32-bit) word at i.
   *  Check the flag word (bit TPCBIT_RAW) of the collection if raw data is
   *  stored at all.
   */
  int getRawDataWord(int i) const override;

  /** Set the cell id.
   */
  virtual void setCellID(int cellID) ;

  /** Set the time.
   */
  virtual void setTime(float time);

  /** Set the charge.
   */
  virtual void setCharge(float charge);

  /** Set the cell quality word.
   */
  virtual void setQuality(int quality);

  /** Set the raw data.
   */
  virtual void setRawData(const int* raw, int size ) ;

protected:
  /** initialize the raw data array - for faster reading
   */
  virtual void initRawArray(int size) ;


  int _cellID{0} ;
  float _time{0} ;
  float _charge{0} ;
  int _quality{0} ;
  int _rawSize{0} ;
  int* _rawArray{nullptr} ;

}; // class
} // namespace IMPL
#endif /* ifndef IMPL_TPCHITIMPL_H */
