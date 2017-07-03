// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef EVENT_TRACKERHITZCYLINDER_H
#define EVENT_TRACKERHITZCYLINDER_H 1

#include "EVENT/TrackerHit.h"
#include "empty_ignore.h"

namespace EVENT {

/** A tracker hit on a cylindrical surface that runs parallel to the z-axis -
 *  the hit is stored as:<br>
 *  x,y,z, center(x,y), dRPhi, dz <br>
 *  where (x,y,z) is the position in global cartesian coordinates,  center(x,y) is the center of the cylinder and
 *  Rphi and z are the measurement errors.
 *  Note the radius of the cylinder is given by R=sqrt( dx^2c+ dy^2 ) and dx=x-x_c, dy=y-y_c.
 *
 * @implements TrackerHit
 * 
 * @author gaede
 * @version $Id:$
 */

class TrackerHitZCylinder : public TrackerHit {

public: 
    /// Destructor.
    ~TrackerHitZCylinder() override { /* nop */; }


    /** Useful typedef for template programming with LCIO */
    using lcobject_type = EVENT::TrackerHitZCylinder ;

   /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     */
    int getCellID0() const override = 0;

    /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     *  Optional, check/set flag(LCIO::RTHZBIT_ID1)==1.
     */
    int getCellID1() const override = 0;

    /** Radius of cylinder.
     */
    //public const float getR() const ;
    /** Center of cylinder in RPhi-plane - given as (x,y).
     */
    virtual const float* getCenter() const = 0;

    /** Measurement error along RPhi */
    virtual float getdRPhi() const = 0;

    /** Measurement error along z */
    virtual float getdZ() const = 0;
}; // class
} // namespace EVENT
#endif /* ifndef EVENT_TRACKERHITZCYLINDER_H */
