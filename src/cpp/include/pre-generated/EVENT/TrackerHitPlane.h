// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef EVENT_TRACKERHITPLANE_H
#define EVENT_TRACKERHITPLANE_H 1

#include "EVENT/TrackerHit.h"
#include "empty_ignore.h"

namespace EVENT {

/** A tracker hit on a planar surface -
 *  the hit is stored as:<br>
 *  x,y,z, u(theta, phi), v(theta,phi), du, dv <br>
 *  where (x,y,z) is the position in global cartesian coordinates, u,v are the
 *  the meassurement directions (unit vectors, spanning the plane) and du,dv are
 *  the measurement errors along these directions. The order of u and v should follow 
 *  the global cartesian coordinates x, y and z, e.g. in case of a plane parallel
 *  to the z-axis, u lies in the x-y plane and v is along z.
 * 
 * @implements TrackerHit
 * 
 * @author gaede
 * @version $Id:$
 */

class TrackerHitPlane : public TrackerHit {

public: 
    /// Destructor.
    ~TrackerHitPlane() override { /* nop */; }


    /** Useful typedef for template programming with LCIO */
    using lcobject_type = EVENT::TrackerHitPlane ;

   /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     */
    int getCellID0() const override = 0;

    /** Same name as in CalorimeterHit, even though there are no 'cells' in this case
     *  Optional, check/set flag(LCIO::RTHPBIT_ID1)==1.
     */
    int getCellID1() const override = 0;

    /** Direction of first measurement - given as (theta, phi).
     *  Defines spanning vector of measurement plane. 	
     */
    virtual const float* getU() const = 0;

    /** Direction of second measurement - given as (theta, phi).
     *  Defines spanning vector of measurement plane.	
     */
    virtual const float* getV() const = 0;

    /** Measurement error along u */
    virtual float getdU() const = 0;

    /** Measurement error along v */
    virtual float getdV() const = 0;
}; // class
} // namespace EVENT
#endif /* ifndef EVENT_TRACKERHITPLANE_H */
