// -*- C++ -*-
#ifndef IMPL_TrackerHitPlaneImpl_H
#define IMPL_TrackerHitPlaneImpl_H 1

#include <string>

#include "EVENT/TrackerHitPlane.h"
#include "IMPL/AccessChecked.h"

#define TRKHITPLANENCOVMATRIX 6

namespace IMPL {

/** Implementation of the planar tracker hit. 
 * 
 * @author gaede
 * @version $Id: $
 */

  class TrackerHitPlaneImpl : public EVENT::TrackerHitPlane , public AccessChecked {

  public: 
    // C'tor
    TrackerHitPlaneImpl() ;
    
    /// Destructor.
    ~TrackerHitPlaneImpl() override ; 


    int id() const override { return simpleUID() ; }


    /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     */
    int getCellID0() const override { return _cellID0; }

    /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     *  0 if information is not stored -  check the flag word (bit RTHPBIT_ID1) 
     *  of the collection. Default is to store only cellid0.
     */
    int getCellID1() const override { return _cellID1; }


    /** The hit  position in [mm].	
     */
    const double* getPosition() const override  {  return _pos ; }  ;

    /** Direction of first measurement - given as (theta, phi).
     *  Defines spanning vector of measurement plane.	
     */
    const float* getU() const override { return _u ; }

    /** Direction of second measurement - given as (theta, phi).
     *  Defines spanning vector of measurement plane.	
     */
    const float* getV() const override  { return _v ; }

    /** Error along u */
    float getdU() const override { return _du ; }

    /** Error along v */
    float getdV() const override  { return _dv ; }


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
     *  Only store if the flag word (bit RTHPBIT_ID1) 
     *  of the collection is set. Default is to store only cellid0.
     */
    void setCellID1(int id1) ;
    void setType(int type) ;
    void setPosition( const double pos[3]) ;
    void setU( const float u[2] ) { setU( u[0] , u[1] ) ; }
    void setU( float theta, float phi);
    void setV( const float v[2] ) { setV( v[0] , v[1] ) ; };
    void setV( float theta, float phi);
    void setdU( float du );
    void setdV( float dv );
    void setEDep( float e ) ;
    void setEDepError( float e ) ;
    void setTime( float t ) ;
    void setQuality( int quality ) ;
    void setQualityBit( int bit , bool val=true ) ;

protected:
  
    int _cellID0{0} ;
    int _cellID1{0} ;

    int    _type{0} ;
    double  _pos[3] = {0,0,0};
    float  _u[2] = {0,0};
    float  _v[2] = {0,0};
    float  _du{0} ;
    float  _dv{0} ;
    float _EDep{0} ;
    float _EDepError{0} ;
    float _time{0} ;
    int _quality{0} ;
    mutable EVENT::FloatVec _cov ;
    EVENT::LCObjectVec _rawHits ;
    

}; // class
} // namespace IMPL
#endif // #ifndef IMPL_TrackerHitPlaneImpl_H 
