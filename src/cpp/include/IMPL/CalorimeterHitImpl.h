#ifndef EVENT_CALORIMETERHITIMPL_H
#define EVENT_CALORIMETERHITIMPL_H 1


#include "EVENT/MCParticle.h"
#include "EVENT/CalorimeterHit.h"
#include <vector>
#include "AccessChecked.h"

namespace IMPL {
  
  
/** Implementation of the real data CalorimeterHit.
 * 
 * @author gaede
 * @version $Id: CalorimeterHitImpl.h,v 1.16 2008-06-04 17:37:16 engels Exp $
 */

  class CalorimeterHitImpl : public EVENT::CalorimeterHit , public AccessChecked {
    
  public: 
    
    /** Default constructor, initializes values to 0.
     */
    CalorimeterHitImpl() ;

    CalorimeterHitImpl(const IMPL::CalorimeterHitImpl&) = default ;
    CalorimeterHitImpl& operator=(const IMPL::CalorimeterHitImpl&) = default ;

    /// Destructor.
    ~CalorimeterHitImpl() override ;
    
    int id() const override { return simpleUID() ; }

    /**Returns the detector specific (geometrical) cell id.
     */
    int getCellID0() const override ;
    
    /**Returns the second detector specific (geometrical) cell id.
     *  0 if information is not stored -  check the flag word (bit RCHBIT_ID1) 
     *  of the collection. Default is to store only cellid0.
     */
    int getCellID1() const override ;
    
    /** Returns the energy of the hit.
     */
    float getEnergy() const override ;
    
    /** Returns the error of the hit energy. Optional, check/set
     *  flag(LCIO::RCHBIT_ENERGY_ERROR)==1.
     */
    float getEnergyError() const override ;
 
    /** Returns the time of the hit in [ns]. Optional, check/set 
     *  flag(LCIO::RCHBIT_TIME)==1.
     */
    float getTime() const override ;

    /** Returns the position of the hit in world coordinates.
     *  NULL if information is not stored. Ask collection for flag, only 
     * available if bit LCIO.RCHBIT_LONG is set.
     */
    
    const float * getPosition() const override ;

    /** Type of hit. Mapping of integer types to type names
     * through collection parameters "CalorimeterHitTypeNames"
     * and "CalorimeterHitTypeValues".
     */
    int getType() const override ;

    /** The RawCalorimeterHit. As in the future there might be other types of 
     *  raw calorimeter hits the return type is LCObject.
     */
    EVENT::LCObject * getRawHit() const override ;

    // setters

    /** Sets the first cell id;
     */
    void setCellID0(int id0) ;

    /** Sets the second cell id;
     *  Only store if the flag word (bit RCHBIT_ID1) 
     *  of the collection is set. Default is to store only cellid0.
     */
    void setCellID1(int id1) ;
    
    /** Sets the energy/amplitude.
     */
    void setEnergy(float en) ;

    /** Sets the error of the hit energy.
     *  Not stored if flag RCHBIT_ENERGY_ERROR isn't set
     */
    void setEnergyError(float enerr) ;

    /** Sets the time.
     */
    void setTime(float t) ;
    
    /** Sets the position. Not stored if LCIO.RCHBIT_LONG isn't set.
     */
    void setPosition(const float pos[3])  ;
    
    void setType(int type) ;

    void setRawHit(EVENT::LCObject* rawHit ) ;

  protected:

    int _cellID0{0} ;
    int _cellID1{0} ;
    float _energy{0.} ;
    float _energyError{0.} ;
    float _time{0.} ;
    float _position[3] ;
    int _type{0} ;

    EVENT::LCObject* _rawHit{nullptr} ;
    
  }; // class
} // namespace IMPL
#endif /* ifndef EVENT_CALORIMETERHITIMPL_H */
