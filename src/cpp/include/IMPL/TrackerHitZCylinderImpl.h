// -*- C++ -*-
#ifndef IMPL_TrackerHitZCylinderImpl_H
#define IMPL_TrackerHitZCylinderImpl_H 1

#include <string>

#include "EVENT/TrackerHitZCylinder.h"
#include "IMPL/AccessChecked.h"

#define TRKHITZCYLNCOVMATRIX 6

namespace IMPL {

/** Implementation of the tracker hit on a cylindrical surface parallel to z. 
 * 
 * @author gaede
 * @version $Id: $
 */

  class TrackerHitZCylinderImpl : public EVENT::TrackerHitZCylinder , public AccessChecked {

  public: 
    // C'tor
    TrackerHitZCylinderImpl() ;
    
    /// Destructor.
    ~TrackerHitZCylinderImpl() override ; 


    int id() const override { return simpleUID() ; }

    /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     */
    int getCellID0() const override { return _cellID0; }

    /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     *  0 if information is not stored -  check the flag word (bit RTHZBIT_ID1) 
     *  of the collection. Default is to store only cellid0.
     */
    int getCellID1() const override { return _cellID1; }


    /** The hit  position in [mm].	
     */
    const double* getPosition() const override  {  return _pos ; }  ;

    /** Radius of cylinder.
     */
    //virtual const float getR() const {  return _r ; }  ;

    /** Center of cylinder in RPhi-plane - given as (x,y).
     */
    const float* getCenter() const override {  return _center ; }  ;

    /** Measurement error along RPhi */
    float getdRPhi() const override {  return _drphi ; }  ;

    /** Measurement error along z */
    float getdZ() const override {  return _dz ; }  ;


    /**Covariance of the position (x,y,z)
     */
    const EVENT::FloatVec & getCovMatrix() const override ;

    /** The dE/dx of the hit in [GeV/mm].
     *  @deprecated
     *  @see getEDep()
     */ 	
    float getdEdx() const override ;

    /** The deposited energy of the hit [GeV]
     */
    float getEDep() const override { return _EDep ; }

    /** The error measured on EDep [GeV]
     */
    float getEDepError() const override { return _EDepError ; }

    /** The  time of the hit in [ns]. Is this needed ?
     */
    float getTime() const override  { return _time ; } ;

    /** Type of hit. Mapping of integer types to type names
     * through collection parameters "TrackerHitTypeNames"
     * and "TrackerHitTypeValues".
     */
    int getType() const override { return _type ; }


    /** The quality bit flag of the hit.
     */
    int getQuality() const override { return _quality ; }

    /** The raw data hits. 
     * Check getType() to get actual data type.
     */
    const EVENT::LCObjectVec & getRawHits() const override { return _rawHits ; }


    /** Use to manipulate the raw hits.
     */
    virtual EVENT::LCObjectVec & rawHits() { return _rawHits ; }


    // setters 

    /** Sets the first cell id;
     */
    void setCellID0(int id0) ;

    /** Sets the second cell id;
     *  Only store if the flag word (bit RTHZBIT_ID1) 
     *  of the collection is set. Default is to store only cellid0.
     */
    void setCellID1(int id1) ;

    void setType(int type) ;
    void setPosition( const double pos[3]) ;
    void setCenter( const float c[2] ) { setCenter( c[0] , c[1] ) ; };
    void setCenter( float xc, float yc);
    //void setR( float r );
    void setdRPhi( float drphi );
    void setdZ( float dz );
    void setEDep( float e ) ;
    void setEDepError( float e ) ;
    void setTime( float t ) ;
    void setQuality( int quality ) ;
    void setQualityBit( int bit , bool val=true ) ;
    //void setCovMatrix( const EVENT::FloatVec& cov );
    //void setCovMatrix( float cov[TRKHITZCYLNCOVMATRIX]  );


protected:
  
    int _cellID0{0} ;
    int _cellID1{0} ;

    int _type{0} ;
    double _pos[3] = {0,0,0} ;
    float  _center[2]  = {0,0};
    float  _drphi{0} ;
    float  _dz{0} ;
    float _EDep{0} ;
    float _EDepError{0} ;
    float _time{0} ;
    int _quality{0} ;
    mutable EVENT::FloatVec _cov ;
    EVENT::LCObjectVec _rawHits ;
    

}; // class
} // namespace IMPL
#endif // #ifndef IMPL_TrackerHitZCylinderImpl_H

