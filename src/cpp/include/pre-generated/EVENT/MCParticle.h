// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef EVENT_MCPARTICLE_H
#define EVENT_MCPARTICLE_H 1

#include "EVENT/LCObject.h"
#include "EVENT/MCParticle.h"
#include "empty_ignore.h"

#include <vector>

namespace EVENT {


class MCParticle ;
/**Vector of (pointers to) MCParticles.*/
using MCParticleVec = std::vector<MCParticle *> ;
/** The LCIO Monte Carlo particle. 
 * 
 * @author gaede
 * @version $Id: MCParticle.aid,v 1.26 2006-08-03 16:53:34 gaede Exp $
 */
class MCParticle : public LCObject {

public: 
    /// Destructor.
    ~MCParticle() override { /* nop */; }


    /** Useful typedef for template programming with LCIO */
    using lcobject_type = EVENT::MCParticle ;

    /** Returns the energy of the particle (at the vertex) in [GeV] computed from
     * the particle's momentum and mass - only float used in files.
     */
    virtual double getEnergy() const = 0;

    /** Returns the spin (helicity) vector of the particle.
     */
    virtual const float* getSpin() const = 0;

    /** Returns the color flow as defined by the generator.
     */
    virtual const int* getColorFlow() const = 0;

    /** Returns the parents of this particle. 
     */
    virtual const MCParticleVec & getParents() const = 0;

    /** Returns the daughters of this particle. 
     */
    virtual const MCParticleVec & getDaughters() const = 0;

    /** Returns the PDG code of the particle.
     */
    virtual int getPDG() const = 0;

    /** Returns the status for particles as defined by  the generator, typically
     * <br> 0  empty line
     * <br> 1  undecayed particle, stable in the generator
     * <br> 2  particle decayed in the generator
     * <br> 3  documentation line
     */
    virtual int getGeneratorStatus() const = 0;

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
    virtual int getSimulatorStatus() const = 0;

    // define the bit positions for the simulation flag

    static const int BITEndpoint = 31 ;
    static const int BITCreatedInSimulation = 30 ;
    static const int BITBackscatter = 29 ;
    static const int BITVertexIsNotEndpointOfParent = 28 ;
    static const int BITDecayedInTracker = 27 ;
    static const int BITDecayedInCalorimeter = 26 ;
    static const int BITLeftDetector = 25 ;
    static const int BITStopped = 24 ;
    static const int BITOverlay = 23 ;

    /** True if the particle has been created by the simulation program (rather than the generator).
     */
    virtual bool isCreatedInSimulation() const = 0;

    /** True if the particle was created by the simulator as a result of an interaction or decay in 
     * non-tracking region, e.g. a calorimeter. By convention, such particles are not saved. However, 
     * if this particle creates a tracker hit, the particle is added to the MCParticle list with 
     * this flag set, and the parent set to the particle that initially decayed or interacted in 
     * a non-tracking region.
     */
    virtual bool isBackscatter() const = 0;

    /** True if the particle was created as a result of a continuous process where the parent 
     *  particle continues, i.e. hard ionization, Bremsstrahlung, elastic interactions, etc. 
     */
    virtual bool vertexIsNotEndpointOfParent() const = 0;

    /** True if the particle decayed or interacted in a tracking region.
     */
    virtual bool isDecayedInTracker() const = 0;

    /** True if the particle decayed or interacted (non-continuous interaction, particle terminated) 
     * in non-tracking region.
     */
    virtual bool isDecayedInCalorimeter() const = 0;

    /** True if the particle left the world volume undecayed.
     */
    virtual bool hasLeftDetector() const = 0;

    /** True if the particle lost all kinetic energy inside the world volume and did not decay
     */
    virtual bool isStopped() const = 0;

    /** True if the particle has been overlayed by the simulation (or digitization)  program.
     */
    virtual bool isOverlay() const = 0;

    // corresponding setters
//     public void setCreatedInSimulation(boolean val)   ; 
//     public void setBackscatter(boolean val)   ; 
//     public void setVertexIsNotEndpointOfParent(boolean val)   ; 
//     public void setDecayedInTracker(boolean val)   ; 
//     public void setDecayedInCalorimeter(boolean val)   ; 
//     public void setHasLeftDetector(boolean val)   ; 
//     public void setStopped(boolean val)   ; 
//     public void setOverlay(boolean val)   ; 
    /** Returns the production vertex of the particle in [mm].
     */
    virtual const double* getVertex() const = 0;

    /** The creation time of the particle in [ns] wrt. the event,
     *  e.g. for preassigned decays or decays in flight from 
     *  the simulator.
     */
    virtual float getTime() const = 0;

    /** Returns the endpoint of the particle in [mm] if
     *  the  endpoint has been set explicetly.
     *  If not, the vertex of the first daughter that 
     *  has vertexIsNotEndpointOfParent==false is returned.
     *  If no such daughter exists (0,0,0) is returned.
     */
    virtual const double* getEndpoint() const = 0;

    /** Returns the particle's 3-momentum at the production vertex in [GeV] 
     *  - only float used in files.
     */
    virtual const double* getMomentum() const = 0;

    /** Returns the particle's 3-momentum at the endpoint in [GeV] 
     *  Only float used in files. 
     */
    virtual const double* getMomentumAtEndpoint() const = 0;

    /** Returns the mass of the particle in [GeV] - only float used in files.
     */
    virtual double getMass() const = 0;

    /** Returns the particle's charge.
     */
    virtual float getCharge() const = 0;

}; // class
} // namespace EVENT
#endif /* ifndef EVENT_MCPARTICLE_H */
