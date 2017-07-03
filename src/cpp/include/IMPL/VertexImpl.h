// -*- C++ -*-
#ifndef IMPL_VERTEXIMPL_H
#define IMPL_VERTEXIMPL_H 1


#include "EVENT/Vertex.h"
#include "AccessChecked.h"

#define VTXCOVMATRIX 6


namespace IMPL {


/** Implementation of Vertex Class.
 *
 * @see Vertex
 * @author gaede, engels
 * @version Aug 09, 2006
 */
  class VertexImpl : public EVENT::Vertex, public AccessChecked {
  
	  
  public: 
    
    /** Default constructor, initializes values to 0.
     */
    VertexImpl() ;

    /// default copy constructor - use with care
    VertexImpl(const VertexImpl&) = default ;

    /// default assignment operator - use with care
    VertexImpl& operator=(const VertexImpl&) = default ;

    
    // Destructor.
    ~VertexImpl() override ; 

    int id() const override { return simpleUID() ; }
    
    /** Checks if the Vertex is the primary vertex of the event.
     *  Only one primary vertex per event is allowed
     */
    bool isPrimary() const override ;
     
    /** Type code for the algorithm that has been used to create the vertex - check/set the
     *  collection parameters AlgorithmName and  AlgorithmType.
     */
    //virtual int getAlgorithmType() const ;
    const std::string& getAlgorithmType() const override ;

    /** Chi squared of the vertex fit.
     */
    float getChi2() const override;
                                                                                                         
    /** Probability of the vertex fit.
     */
    float getProbability() const override;
                                                                                                         
    /** Position of the vertex 
     */
    const float* getPosition() const override;
                                                                                                         
    /** Covariance matrix of the position (stored as lower triangle matrix, i.e.
     *  cov(xx),cov(y,x),cov(y,y) ).
     */
    const EVENT::FloatVec & getCovMatrix() const override;

    /** Additional parameters related to this vertex - check/set the collection
     *  parameter "VertexParameterNames" for the parameters' meaning.
     */
    const EVENT::FloatVec & getParameters() const override;

    /** Returns Reconstructed Particle associated to the Vertex
     */
    EVENT::ReconstructedParticle * getAssociatedParticle() const override;

    // setters
    void setPrimary( bool primary ) ;
    //void setAlgorithmType( int type ) ;
    void setAlgorithmType( std::string type ) ;
    void setChi2( float chi2 ) ;
    void setProbability( float probability ) ;
    void setPosition( const float vpos[3] ) ;
    void setPosition( float px, float py, float pz ) ;
    void setCovMatrix( const float* cov ) ;
    void setCovMatrix( const EVENT::FloatVec & ) ;
    void setAssociatedParticle( EVENT::ReconstructedParticle * aP ) ;
    void addParameter( float p );

  protected:
    int _primary{0} ;
    std::string _type ;
    float _chi2{0} ;
    float _probability{0} ;
    float _vpos[3] ={0,0,0} ;
    EVENT::FloatVec _cov ;
    EVENT::FloatVec _par ;
    EVENT::ReconstructedParticle* _aParticle{nullptr} ;
   
}; // class

} // namespace IMPL
#endif /* ifndef IMPL_VERTEXIMLP_H */
