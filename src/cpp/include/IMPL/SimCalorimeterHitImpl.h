#ifndef IMPL_SIMCALORIMETERHITIMPL_H
#define IMPL_SIMCALORIMETERHITIMPL_H 1


#include "EVENT/MCParticle.h"
#include "EVENT/SimCalorimeterHit.h"
#include "AccessChecked.h"
#include <vector>

namespace IMPL {
  

  // helper class for particle contributions to hits
  struct MCParticleCont{
    MCParticleCont()
       {   
      StepPosition[0] = 0. ;
      StepPosition[1] = 0. ;
      StepPosition[2] = 0. ;
    }

    MCParticleCont( EVENT::MCParticle* part,  float e,float t,int pdg, const float* step ) :
      Particle( part ) ,
      Energy(e) ,
      Time(t) ,
      PDG(pdg)  {   
      StepPosition[0] = step[0] ;
      StepPosition[1] = step[1] ;
      StepPosition[2] = step[2] ;
    }
    
    EVENT::MCParticle* Particle{nullptr} ;
    float Energy{0.} ;
    float Time{0.} ;
    int   PDG{0} ;
    float StepPosition[3] ;
  } ;
  
  using MCParticleContVec = std::vector<IMPL::MCParticleCont *> ;
  
/** Implementation of the generic SimCalorimeterHit.
 * 
 * @author gaede
 * @version Mar 5, 2003
 */

  class SimCalorimeterHitImpl : public EVENT::SimCalorimeterHit
			      , public AccessChecked {
    
  public: 
    
    /** Default constructor, initializes values to 0.
     */
    SimCalorimeterHitImpl() ;

    /** Copy constructor - shallow copy. 
     */
    SimCalorimeterHitImpl(const EVENT::SimCalorimeterHit& hit) ;

    /// Destructor.
    ~SimCalorimeterHitImpl() override ;
    
    int id() const override { return simpleUID() ; }

//     /** Create a deep copy of itself.
//      * Overwrites return type in LCObject::clone().
//      * Not yet - as AID genereates virtual inheritance and
//      * g++ doesn't support virtual constructors with virtual inheritance
//      * TODO - change org.freehep.aid.CPPHeaderGenerator !
//      */
//     //virtual  SimCalorimeterHit* clone() const;
//     virtual LCObject* clone() const;
    
    /**Returns the detector specific (geometrical) cell id.
     */
    int getCellID0() const override ;
    
    /**Returns the second detector specific (geometrical) cell id.
     *  0 if information is not stored -  check the flag word (bit CHBIT_ID1) 
     *  of the collection. Default is to store only cellid0.
     */
    int getCellID1() const override ;
    
    /** Returns the energy of the hit.
     */
    float getEnergy() const override ;
    
    /** Returns the position of the hit in world coordinates.
     *  NULL if information is not stored. Ask collection for flag, only 
     * available if bit LCIO.CHBIT_LONG is set.
     */
    
    const float * getPosition() const override ;


    /** Returns the position where the energy deposited (step) occurred
     * optional, only if bit LCIO::CHBIT_STEP is set.
     */
    const float* getStepPosition( int i ) const override ;

    
    /** Returns the number of MC contributions to the hit. 0 if 
     * information is not stored. Renamed to getNMCContributions.
     * @deprecated
     * @see getNMCContributions()
     */
    int getNMCParticles() const override ;
    
    /** Returns the number of MC contributions to the hit. 0 if 
     * information is not stored. There are two levels of detail: if 
     * collection flag bit LCIO.CHBIT_STEP==1 then all simulator steps' 
     * contributions to the hit are stored, otherwise there is only one 
     * contribution for every particle entering the calorimeter.
     */
    int getNMCContributions() const override ;

    /** Returns the energy in [GeV] of the i-th contribution to the hit.
     * @see getNMCContributions()
     */ 
    float getEnergyCont(int i) const override ;

    /** Returns the time of the i-th in [ns]  contribution to the hit.
     * @see getNMCContributions()
     */ 
    float getTimeCont(int i) const override ;

    /** Returns the PDG code of the shower particle that caused this contribution.
     *  Check the flag word bit LCIO.CHBIT_STEP of the collection whether this information 
     *  is available. 
     * @see getNMCContributions()
     */ 
    int getPDGCont(int i) const override ;

    /** Returns the MCParticle that caused the shower responsible for this contribution to the hit.
     *  This is the particle that flew into the calorimeter and not the shower particle that made the 
     *  energy deposition.
     * @see getNMCContributions()
     */
    EVENT::MCParticle * getParticleCont(int i) const override ;

    // setters
    /** Sets the first cell id;
     */
    void setCellID0(int id0) ;

    /** Sets the second cell id;
     *  Only store if the flag word (bit CHBIT_ID1) 
     *  of the collection is set. Default is to store only cellid0.
     */
    void setCellID1(int id1) ;
    
    /** Sets the energy.
     */
    void setEnergy(float en) ;
    
    /** Sets the position. Not stored if LCIO.CHBIT_LONG isn't set.
     */
    void setPosition(const float pos[3])  ;
    

    /** Adds an MCParticle contribution to the hit - contributions for the same MCParticle are combined into one,
     *  where the energy is accumulated and the time is the energy weighted mean time.
     *  Use this method for the standard LCIO mode, where one energy contribution per primary particle entering the 
     *  calorimeter is stored.
     */
    void addMCParticleContribution( EVENT::MCParticle *p,
				    float en,
				    float t ) ; 
    

    /** Adds a detailed MCParticle contribution to the hit. This method should be used for the detailed mode, where 
     *  one MCParticleContribution is stored for every simulator step.<br>
     *  If stepPos==0, (0,0,0) will be stored.
     *  NB: The flag word bit LCIO::CHBIT_STEP (or LCIO::CHBIT_PDG) has to be set, in order for the PDG and step 
     *  position to be stored. 
     */
    void addMCParticleContribution( EVENT::MCParticle *p,
				    float en,
				    float t,
				    int pdg, 
				    float* stepPos=nullptr
				    ) ; 
    
    


  protected:

    int _cellID0{0} ;
    int _cellID1{0} ;
    float _energy{0} ;
    float _position[3] ;

    MCParticleContVec _vec{} ;
    
  }; // class
} // namespace IMPL
#endif /* ifndef IMPL_SIMCALORIMETERHITIMPL_H */
