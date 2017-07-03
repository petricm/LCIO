#ifndef IMPL_CLUSTERIMPL_H
#define IMPL_CLUSTERIMPL_H 1


#include "EVENT/Cluster.h"
#include "AccessChecked.h"
#include <map>
#include <bitset>

#define NERRPOS 6
#define NERRDIR 3

#define NSHAPE_OLD 6

namespace IMPL {


/** Implementation of Cluster.
 *
 * @see Cluster
 * @author gaede
 * @version $Id: ClusterImpl.h,v 1.13 2006-08-04 16:52:46 gaede Exp $
 */
  class ClusterImpl : public EVENT::Cluster, public AccessChecked {
    
  public: 
    
    /** Default constructor, initializes values to 0.
     */
    ClusterImpl() ;
    
    /// Destructor.
    ~ClusterImpl() override ; 

    int id() const override { return simpleUID() ; }

    /** Flagword that defines the type of cluster. Bits 0-15 can be used to denote the subdetectors
     *  that have contributed hits to the cluster. The definition of the bits has to be done 
     *  elsewhere, e.g. in the run header. Bits 16-31 are used internally.
     */
    int getType() const override ;

    /** Energy of the cluster.
     */
    float getEnergy() const override ;

    /** Returns the error on the energy of the cluster.
     */
    float getEnergyError() const override ;

    /** Position of the cluster.
     */
    const float* getPosition() const override ;

    /** Covariance matrix of the position (6 Parameters)
    */
    const EVENT::FloatVec & getPositionError() const override ;

    /** Intrinsic direction of cluster at position: Theta.
     */
    float getITheta() const override ;

    /** Intrinsic direction of cluster at position: Phi.
     */
    float getIPhi() const override ;

    /** Covariance matrix of the direction (3 Parameters)
     */
    const EVENT::FloatVec & getDirectionError() const override ;

    /** Shape parameters - check/set  collection parameter
     *  ClusterShapeParameters for size and names of parameters.
     */
    const EVENT::FloatVec & getShape() const override ;

//     /** Type hypotheses: 3 Parameters: compatible with EM, HAD, muon cluster
//      */
//     virtual const EVENT::FloatVec & getParticleType() const ;


    /** The particle Id's sorted by their probability.
     * @see ParticleID
     */
    const EVENT::ParticleIDVec & getParticleIDs() const override ;


    /** The clusters that have been combined to this cluster.
     */
    const EVENT::ClusterVec & getClusters() const override ;


    /** The hits that have been combined to this cluster.
     */
    const EVENT::CalorimeterHitVec & getCalorimeterHits() const override ;

    /** Returns the energy contribution of the hits 
     * Runs parallel to the CalorimeterHitVec from getCalorimeterHits()
     */
    const EVENT::FloatVec & getHitContributions() const override ;


    /** A vector that holds the energy observed in a particular subdetectors.
     *  The mapping of indices to subdetectors is implementation dependent.
     *  To be used as convenient information or if hits are not stored in 
     *  the data set, e.g. DST or FastMC. 
     *  Check/set collection parameter ClusterSubdetectorNames for decoding the
     *  indices of the array.
     */
    const EVENT::FloatVec & getSubdetectorEnergies() const override ;

    //setters 
    void setTypeBit( int index , bool val=true) ;
    void setEnergy(float energy ) ;
    void setEnergyError(float energyError ) ;
    void setPosition(const float* position) ;
    void setPositionError(const EVENT::FloatVec &errpos) ;
    void setPositionError(const float* errpos) ;
    void setITheta(float theta) ;
    void setIPhi(float phi) ;
    void setDirectionError(const EVENT::FloatVec &errdir) ;
    void setDirectionError(const float* errdir) ;
    //    void setShape(const float* shape) ;
    void setShape(const EVENT::FloatVec &shape) ;

    void addParticleID( EVENT::ParticleID*  pid ) ;

//     void setEMWeight(float emWeight ) ;
//     void setHADWeight(float hadWeight ) ;
//     void setMuonWeight(float muonWeight ) ;

    void addCluster(EVENT::Cluster* cluster) ;
    void addHit(EVENT::CalorimeterHit* hit  , float contribution) ;


    /** To be used for modifying the subdetector energies, e.g.<br>
     *  clu->subdetectorEnergies().resize(3) ;
     *  clu->subdetectorEnergies()[0] = 123.4567 ;
     *  clu->subdetectorEnergies()[1] = 12.34567 ;
     *  clu->subdetectorEnergies()[2] = 1.234567 ;
     */
    EVENT::FloatVec& subdetectorEnergies() ;

  protected:
    void setType(int type ) ; 

    std::bitset<32> _type{0} ;
    float _energy{0} ;
    float _energyError{0} ;
    float _position[3]={0,0,0} ;
    EVENT::FloatVec _errpos ;
    float _theta{0};
    float _phi{0} ;
    EVENT::FloatVec _errdir ;
    EVENT::FloatVec _shape{} ;
    EVENT::ParticleIDVec _pid{} ;
    EVENT::ClusterVec _clusters{} ;
    EVENT::CalorimeterHitVec _hits{} ;
    EVENT::FloatVec _weights{} ;
    EVENT::FloatVec _subdetectorEnergies{} ;

}; // class

} // namespace IMPL
#endif /* ifndef IMPL_CLUSTERIMLP_H */
