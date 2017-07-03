// -*- C++ -*-
#ifndef IMPL_TRACKERHITIMPL_H
#define IMPL_TRACKERHITIMPL_H 1

#include <string>

#include "EVENT/TrackerHit.h"
#include "IMPL/AccessChecked.h"
//#include "EVENT/TPCHit.h"

#define TRKHITNCOVMATRIX 6

namespace IMPL {

/** Implementation of the  generic tracker hit. 
 * 
 * @author gaede
 * @version $Id: TrackerHitImpl.h,v 1.15 2010-06-17 12:29:00 engels Exp $
 */

  class TrackerHitImpl : public EVENT::TrackerHit , public AccessChecked {

  public: 
    // C'tor
    TrackerHitImpl() ;
    
    /// Destructor.
    ~TrackerHitImpl() override ; 


    int id() const override { return simpleUID() ; }

    /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     */
    int getCellID0() const override ;

    /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     *  0 if information is not stored -  check the flag word (bit RTHBIT_ID1) 
     *  of the collection. Default is to store only cellid0.
     */
    int getCellID1() const override ;

    /** The hit  position in [mm].	
     */
    const double* getPosition() const override ;

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
    float getTime() const override ;

//     /**Type of raw data hit, either one of<br>
//      * LCIO::TPCHIT<br>
//      * LCIO::SIMTRACKERHIT<br>
//      */
//     virtual const std::string & getType() const ;

    /** Type of hit. Mapping of integer types to type names
     * through collection parameters "TrackerHitTypeNames"
     * and "TrackerHitTypeValues".
     */
    int getType() const override ;

    /** The quality bit flag of the hit.
     */
    int getQuality() const override { return _quality ; }

    /** The raw data hits. 
     * Check getType() to get actual data type.
     */
    const EVENT::LCObjectVec & getRawHits() const override ;


    /** Use to manipulate the raw hits.
     */
    virtual EVENT::LCObjectVec & rawHits() ;


    // setters 

    /** Sets the first cell id;
     */
    void setCellID0(int id0) ;

    /** Sets the second cell id;
     *  Only store if the flag word (bit RTHBIT_ID1) 
     *  of the collection is set. Default is to store only cellid0.
     */
    void setCellID1(int id1) ;
  
    void setType(int type) ;
    void setPosition( const double pos[3]) ;
    void setCovMatrix( const EVENT::FloatVec& cov );
    void setCovMatrix( const float cov[TRKHITNCOVMATRIX]  );
    void setdEdx( float dedx ) ; // DEPRECATED. renamed to setEDep()
    void setEDep( float e ) ;
    void setEDepError( float e ) ;
    void setTime( float t ) ;
    void setQuality( int quality ) ;
    void setQualityBit( int bit , bool val=true ) ;


protected:

    int _cellID0{0} ;
    int _cellID1{0} ;

    int _type{0} ;
    double _pos[3] = {0.,0.,0.} ;
    EVENT::FloatVec _cov{} ;
    float _EDep{0} ;
    float _EDepError{0} ;
    float _time{0} ;
    int _quality{0} ;
    EVENT::LCObjectVec _rawHits{} ;
    

}; // class
} // namespace IMPL
#endif /* ifndef IMPL_TRACKERHITIMPL_H */
