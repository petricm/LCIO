// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef EVENT_TRACKERDATA_H
#define EVENT_TRACKERDATA_H 1

#include "EVENT/LCObject.h"
#include "LCIOSTLTypes.h"

namespace EVENT {

/** TrackerData contains the corrected (calibrated) raw tracker data.
 *  @see TrackerRawData
 *  @see TrackerPulse
 * 
 * @author gaede
 * @version $Id: TrackerData.aid,v 1.2 2006-03-24 13:25:53 gaede Exp $
 */

class TrackerData : public LCObject {

public: 
    /// Destructor.
    ~TrackerData() override { /* nop */; }


    /** Useful typedef for template programming with LCIO */
    using lcobject_type = EVENT::TrackerData ;

    /** Returns the first detector specific (geometrical) cell id.
     */
    virtual int getCellID0() const = 0;

    /** Returns the second detector specific (geometrical) cell id. Optional, check/set 
     *  flag(LCIO::TRAWBIT_ID1)==1.
     */
    virtual int getCellID1() const = 0;

    /** Returns a time measurement associated with the adc values, e.g. the 
     *  t0 of the spectrum for the TPC. Subdetector dependent.
     */
    virtual float getTime() const = 0;

    /** The corrected (calibrated) FADC spectrum. 
     */
    virtual const FloatVec & getChargeValues() const = 0;
}; // class
} // namespace EVENT
#endif /* ifndef EVENT_TRACKERDATA_H */
