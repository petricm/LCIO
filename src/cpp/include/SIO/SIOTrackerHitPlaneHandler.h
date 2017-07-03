#ifndef SIO_SIOTRACKERHITPLANEHANDLER_H
#define SIO_SIOTRACKERHITPLANEHANDLER_H 1

#include "SIO/SIOObjectHandler.h"


namespace SIO {
    
    
/** Implementation of SIOObjectHandler to handle IO of TrackerHitPlane.
 *
 * @author engels
 * @version $Id:$
 */

  class SIOTrackerHitPlaneHandler : public SIOObjectHandler {
	
  public:
	
    /** Reads lcio object from an SIO stream.
     */
    unsigned int read(SIO_stream* stream, 
			      EVENT::LCObject** objP) override  ;
	
    /** Writes lcio object to an SIO stream.
     */
    unsigned int write(SIO_stream* stream, 
			       const EVENT::LCObject* obj) override ;
	
  }; // class
} // namespace

#endif /* ifndef SIO_SIOTRACKERHITPLANEHANDLER_H */
