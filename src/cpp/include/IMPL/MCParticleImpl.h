// -*- C++ -*-
#ifndef IMPL_MCPARTICLEIMPL_H
#define IMPL_MCPARTICLEIMPL_H 1
#include <vector>

#include "EVENT/LCIO.h"
#include "AccessChecked.h"

#include "EVENT/MCParticle.h"
#include <bitset>

namespace IMPL {
  
  // fg 01042004 : changed to use vector of pointers !
  //   typedef std::vector<EVENT::MCParticle**> MCParticlePVec ;
  // use  pointers to pointer to MCParticle 
  // as SIO needs the address of the pointer for pointer reallocation....

  /** Implementation of MCParticle.
   * 
   * @author gaede
   * @version $Id: MCParticleImpl.h,v 1.24 2010-01-21 16:28:25 gaede Exp $
   */
  class MCParticleImpl : public EVENT::MCParticle, public AccessChecked {
    
  public: 

    MCParticleImpl() ;

//     /** Copy c'tor */
//     MCParticleImpl(const EVENT::MCParticle& p) ;
    
    /// Destructor.
    ~MCParticleImpl() override ;

    int id() const override { return simpleUID() ; }

    /** Returns the parents of this particle. 
     */
    const EVENT::MCParticleVec & getParents() const override ;

    /** Returns the daughters of this particle. 
     */
    const EVENT::MCParticleVec & getDaughters() const override ;


    // /** Returns the i-th daughter of this particle.
    //  * Same as getDaughter() except for return type.
    //  *
    //  * @see getNumberOfDaughters
    //  */
    // virtual EVENT::MCParticle * getDaughter(int i) const ;


    // /** Returns the number of parents of this particle - 0 if mother.
    //  */
    // virtual int getNumberOfParents() const ;


    // /** Returns the i-th parent of this particle.
    //  */
    // virtual EVENT::MCParticle * getParent(int i) const ;


    /** Returns the endpoint of the particle in [mm] - returns NULL if
     *  undefined (not set). 
     *  Definition of the enpoint depends on the application that created 
     *  the particle, e.g. the start point of the shower in a calorimeter.
     */
    const double* getEndpoint() const override ;

    // /** Returns the number of daughters of this particle.
    //  */
    // virtual int getNumberOfDaughters() const ;


    /** Returns the PDG code of the particle.
     */
    int getPDG() const override ;

    /** Returns the status for particles from the generator
     * <br> 0  empty line
     * <br> 1  undecayed particle, stable in the generator
     * <br> 2  particle decayed in the generator
     * <br> 3  documentation line
     */
    int getGeneratorStatus() const override ;

    /** Returns the status for particles from the simulation, e.g.
     * decayed in flight. Bits 31-16 are used to decode the information.
     * Use  the followng boolean functions to determine the 
     * proper simulator status:<br>
     * @see isCreatedInSimulation() 
     * @see isBackscatter() 
     * @see vertexIsNotEndpointOfParent() 
     * @see isDecayedInTracker() 
     * @see isDecayedInCalorimeter() 
     * @see hasLeftDetector() 
     * @see isStopped() 
     * @see isOverlay() 
     */
    int getSimulatorStatus() const override ;

    /** True if the particle has been created by the simulation program (rather than the generator).
     */
    bool isCreatedInSimulation() const override ;

    /** True if the particle is the result of a backscatter from a calorimeter shower.
     */
    bool isBackscatter() const override ;

    /** True if the particle's vertex is not the endpoint of the  parent particle.
     */
    bool vertexIsNotEndpointOfParent() const override ;

    /** True if the particle has interacted in a tracking region.
     */
    bool isDecayedInTracker() const override ;

    /** True if the particle has interacted in a calorimeter region.
     */
    bool isDecayedInCalorimeter() const override ;

    /** True if the particle has left the world volume undecayed.
     */
    bool hasLeftDetector() const override ;

    /** True if the particle has been stopped by the simulation program.
     */
    bool isStopped() const override ;

    /** True if the particle has been overlayed by the simulation (or digitization)  program.
     */
    bool isOverlay() const override ;

    /** Returns the production vertex of the particle.
     */
    const double* getVertex() const override ;

    /** The creation time of the particle in [ns] wrt. the event,
     *  e.g. for preassigned decays or decays in flight from 
     *  the simulator.
     */
    float getTime() const override ;

    /** Returns the particle momentum at the production vertex.
     */
    const double * getMomentum() const override ;


    /** Returns the particle momentum at the endpoint.
     */
    const double* getMomentumAtEndpoint() const override ;

    /** Returns the mass of the particle in [GeV].
     */
    double getMass() const override ;

    /** Returns the particle's charge.
     */
    float getCharge() const override ;


    /** Returns the energy of the particle (at the vertex) in [GeV] computed from
     * the particle's momentum and mass.
     */
    double getEnergy() const override ;

   /** Returns the spin
     */
    const float* getSpin() const override ;


   /** Returns the color flow
     */
    const int* getColorFlow() const override ;


    // set methods
    /** Adds a parent particle. 
     */
    void addParent(  EVENT::MCParticle *mom ) ;

//     // set methods
//     /** Sets the parent. 
//      */
//     void setParent(  EVENT::MCParticle *mom0 ) ;

//     /** Sets a second parent.
//      */
//     void setSecondParent(  EVENT::MCParticle *mom1 ) ;


    /** Sets the PDG code.
     */
    void setPDG(int pdg ) ;

    /** Sets the Generator status.
     */
    void setGeneratorStatus( int status ) ;

    /** Sets the Simulator status.
     */
    void setSimulatorStatus( int status ) ;

     /** Sets the production vertex.
     */
    void setVertex( const double vtx[3] ) ;
    
    /** Sets the createion time.
     */
    void setTime( float time) ;

     /** Sets the particle endpoint.
      *  
      */
    void setEndpoint( const double pnt[3] ) ;
    
    /** Sets the momentum.
      */
    void setMomentum( const float p[3] );

    /** Sets the momentum.
     */
    void setMomentum( const double p[3] );

    /** Sets the momentum at the endpoint.
      */
    void setMomentumAtEndpoint( const float p[3] );

    /** Sets the momentum at the endpoint.
      */
    void setMomentumAtEndpoint( const double p[3] );

    /** Sets the mass.
     */
    void setMass( float m ) ;

    /** Sets the charge.
     */
    void setCharge( float c ) ;

    /** Sets the spin
      */
    void setSpin( const float spin[3] );

    /** Sets the color flow
      */
    void setColorFlow( const int cflow[2] );



    // setters for simulator status
    virtual void setCreatedInSimulation(bool val) ;

    virtual void setBackscatter(bool val) ;

    virtual void setVertexIsNotEndpointOfParent(bool val) ;

    virtual void setDecayedInTracker(bool val) ;

    virtual void setDecayedInCalorimeter(bool val) ;

    virtual void setHasLeftDetector(bool val) ;

    virtual void setStopped(bool val) ;

    virtual void setOverlay(bool val) ;

  protected:

    /** Adds a daughter particle - only called from addParent().
     */
    void addDaughter(  EVENT::MCParticle* daughter) ;

//     EVENT::MCParticle* _mother0 ;
//     EVENT::MCParticle* _mother1 ;
    int _pdg{0} ;
    int _genstatus{0} ;
    //    int _simstatus ;
    std::bitset<32> _simstatus ;
    double _vertex[3] ;
    double _endpoint[3] ;
    double _pEndpoint[3] ;
    double _p[3] ;
    double _mass{0} ;
    float _charge{0} ;
    float _time{0} ;
    EVENT::MCParticleVec _parents ;
    EVENT::MCParticleVec _daughters ;
    bool _endpointSet{false} ;
    float _spin[3] ;
    int _colorFlow[2] ;

}; // class
} // namespace IMPL
#endif /* ifndef IMPL_MCPARTICLEIMPL_H */
