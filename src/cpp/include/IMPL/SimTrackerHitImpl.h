#ifndef IMPL_SIMTRACKERHITIMPL_H
#define IMPL_SIMTRACKERHITIMPL_H 1


#include "EVENT/SimTrackerHit.h"
#include "EVENT/MCParticle.h"
#include "AccessChecked.h"


namespace IMPL {


/** Implementation of SimTrackerHit.
 *
 * @see SimTrackerHit
 * @author gaede
 * @version Mar 6, 2003
 */

  class SimTrackerHitImpl : public EVENT::SimTrackerHit, public AccessChecked {
    
  public: 
    
    /** Default constructor, initializes values to 0.
     */
    SimTrackerHitImpl() ;

    /// default copy constructor - use with care
    SimTrackerHitImpl(const SimTrackerHitImpl&) = default ;

    /// default assignment operator - use with care
    SimTrackerHitImpl& operator=(const SimTrackerHitImpl&) = default ;

    /// Destructor.
    ~SimTrackerHitImpl() override ; 
    
    int id() const override { return simpleUID() ; }

    /** DEPRECATED: use @getCellID0()
     */
    int getCellID() const override ;

    /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     */
    int getCellID0() const override ;

    /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     *  0 if information is not stored -  check the flag word (bit THBIT_ID1) 
     *  of the collection. Default is to store only cellid0.
     */
    int getCellID1() const override ;

    /** Returns the hit  position.	
     */
          
    const double * getPosition() const override ;

    /** Returns  the dE/dx of the hit.
     *  @deprecated
     *  @see getEDep()
     */ 	
    float getdEdx() const override ;

    /** Returns the deposited energy of the hit [GeV]
     */ 	
    float getEDep() const override ;


    /** Returns the  time of the hit. TO DO needs definition.
     */
    float getTime() const override ;


    /** Returns the MC particle that caused the hit.
     * @see MCParticle
     */
    EVENT::MCParticle * getMCParticle() const override ;


    /** Returns the 3-momentum of the particle at the hits position in [GeV] - 
     * optional, only if bit LCIO::THBIT_MOMENTUM is set.	
     */ 
    const float* getMomentum() const override ;

    /** The path length of the particle in the sensitive material that resulted in this hit.
     *  This is only stored together with momentum, i.e. if  LCIO::THBIT_MOMENTUM is set.
     */
    float getPathLength() const override ;

    /** The quality bit flag of the hit.
     */
    int getQuality() const override { return _quality ; }

    // ---------- setters ------------------------

    /** Sets the first cell id;
     */
    void setCellID0(int id0) ;

    /** Sets the second cell id;
     *  Only store if the flag word (bit THBIT_ID1) 
     *  of the collection is set. Default is to store only cellid0.
     */
    void setCellID1(int id1) ;

    /** Sets the position.
     */
    void setPosition( const double pos[3])  ;

    /** Sets dE/dx.
     *  @deprecated
     *  @see setEDep()
     */
    void setdEdx( float dEdX ) ;

    /** Sets EDep
     */
    void setEDep( float e )  ;

    /** Sets the time.
     */
    void setTime( float t )  ;

    /** Sets the MCParticle that caused the hit.
     */
    void setMCParticle( EVENT::MCParticle* particle)  ;

    /** Sets the momentum of the particle at the hit's position.
     */
    void setMomentum( const float p[3] ) ;

    /** Sets the momentum of the particle at the hit's position.
     */
    void setMomentum( float px, float py, float pz )  ;

	/* Set the path length.
	 */	
    void setPathLength(float pathLength);

    /* Set the quality flag of the hit.
     */
    void setQuality( int quality ) ;

    /* Set a quality bit of the hit.
     */
    void setQualityBit( int bit , bool val=true ) ;

    /** True if the hit has been overlayed by the simulation (or digitization)  program.
     */
    bool isOverlay() const override ;

    /** True if the particle has been created by a secondary particle that is not stored in the MCParticle collection.
     */
    bool isProducedBySecondary() const override ;

    // setters for quality bits
    void setOverlay(bool val) ;

    void setProducedBySecondary(bool val) ;

  protected:
    int _cellID0{0} ;
    int _cellID1{0} ;
    double _pos[3] ;
    float _EDep{0} ;
    float _time{0} ;
    EVENT::MCParticle* _particle{nullptr} ;   //! <-- fixme: ROOT cannot handle this pointer !!????
    float _p[3] ;
    float _pathLength{0} ;
    int _quality{0} ;

}; // class
} // namespace IMPL
#endif /* ifndef IMPL_SIMTRACKERHITIMLP_H */
