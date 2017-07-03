// -*- C++ -*-
#ifndef IMPL_RECONSTRUCTEDPARTICLEIMPL_H
#define IMPL_RECONSTRUCTEDPARTICLEIMPL_H 1


#include "EVENT/ReconstructedParticle.h"
#include "AccessChecked.h"


#define NCOVARIANCE 10


namespace IMPL {


/** Implementation of ReconstructedParticle.
 *
 * @see ReconstructedParticle
 * @author gaede
 * @version Mar 30, 2003
 */
  class ReconstructedParticleImpl : public EVENT::ReconstructedParticle, public AccessChecked {
    
  public: 
    
    /** Default constructor, initializes values to 0.
     */
    ReconstructedParticleImpl() ;
    
    /// default copy constructor - use with care
    ReconstructedParticleImpl(const ReconstructedParticleImpl&) = default ;

    /// default assignment operator - use with care
    ReconstructedParticleImpl& operator=(const ReconstructedParticleImpl&) = default ;

    /// Destructor.
    ~ReconstructedParticleImpl() override ; 

    int id() const override { return simpleUID() ; }


    /** Type of reconstructed particle.
     *  Check/set collection parameterrs ReconstructedParticleTypeNames and 
     *  ReconstructedParticleTypeValues.
     */
    int getType() const override ;

    /** Convenient method - same as (getParticles().size() > 0 ).
     */
    bool isCompound() const override { return getParticles().size() > 0 ; }

    /** The magnitude of the reconstructed particle's momentum,
     */
    const double* getMomentum() const override ;

    /** Energy of the  reconstructed particle.
     */
    double getEnergy() const override ;

    /** Covariance matrix of the reconstructed particle's 4vector (10 parameters).
     */
    const EVENT::FloatVec & getCovMatrix() const override ;

    /** Mass of the  reconstructed particle, set independently from four vector quantities.
     */
    double getMass() const override ;

    /** Charge of the reconstructed particle.
     */
    float getCharge() const override ;

    /** Reference point of the reconstructedParticle parameters.
     */
    const float* getReferencePoint() const override ;

    /** The particle Id's sorted by their likelihood.
     * @see ParticleID
     */
    const EVENT::ParticleIDVec & getParticleIDs() const override ;

    /** The particle Id used for the kinematics of this particle.
     * @see ParticleID
     */
     EVENT::ParticleID * getParticleIDUsed() const override ;


    /** The overall goodness of the PID on a scale of [0;1].
     */
    float getGoodnessOfPID() const override ;

    /** The reconstructed particles that have been combined to this particle.
     */
    const EVENT::ReconstructedParticleVec & getParticles() const override ;

    /** The clusters that have been used for this particle.
     */
    const EVENT::ClusterVec & getClusters() const override ;


    /** The tracks that have been used for this particle.
     */
    const EVENT::TrackVec & getTracks() const override ;

    /** The start vertex associated to this particle
    */
    EVENT::Vertex * getStartVertex() const override ;

    /** The vertex where the particle decays
     *  This method actually returns the start vertex from the first daughter particle found
    */
    EVENT::Vertex * getEndVertex() const override ;


    // setters
    void setType(int type) ;
    //     void setPrimary(bool primary) ;
    //    void setTypeFlag( int typeFlag)  ;
    void setMomentum( const float* momentum ) ;
    void setMomentum( const double* momentum ) ;
    void setEnergy( float energy) ;
    void setCovMatrix( const float* cov ) ;
    void setCovMatrix( const EVENT::FloatVec& ) ;
    void setMass( float mass ) ;
    void setCharge( float charge ) ;
    void setReferencePoint( const float* reference ) ;
    void addParticleID( EVENT::ParticleID*  pid ) override ;
    void setParticleIDUsed( EVENT::ParticleID*  pid ) ;
    void setGoodnessOfPID( float goodness ) ;
    void addParticle( EVENT::ReconstructedParticle* particle ) override ;
    void addCluster( EVENT::Cluster* cluster) override ;
    void addTrack( EVENT::Track* track) override ;
//     void addMCParticle( EVENT::MCParticle* mcParticle , float weight = 1.0 ) ;
    void setStartVertex( EVENT::Vertex * sv ) ;
    //void setEndVertex( EVENT::Vertex * ev ) ;

  protected:

    int _type{0} ;
    double _momentum[3] = {0.,0.,0.} ;
    double _energy{0.} ;
    EVENT::FloatVec _cov{} ;
    double _mass{0.} ;
    float _charge{} ;
    float _reference[3] = {0.,0.,0.}  ;
    EVENT::ParticleID* _pidUsed{ nullptr} ;
    float _goodnessOfPID{0.} ;
    EVENT::ParticleIDVec _pid{} ;
    EVENT::ReconstructedParticleVec _particles{} ;
    EVENT::ClusterVec _clusters{} ;
    EVENT::TrackVec _tracks{} ;
    EVENT::Vertex* _sv{} ;

    
}; // class

} // namespace IMPL
#endif /* ifndef IMPL_RECONSTRUCTEDPARTICLEIMLP_H */
