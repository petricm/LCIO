#ifndef SIO_SIOCLUSTERHANDLER_H
#define SIO_SIOCLUSTERHANDLER_H 1

#include "SIO/SIOObjectHandler.h"


namespace SIO {
    
    
/** Implementation of SIOObjectHandler to handle IO of Clusters.
 *
 * @author gaede
 * @version $Id: SIOClusterHandler.h,v 1.4 2005-04-15 08:37:42 gaede Exp $
 */

  class SIOClusterHandler : public SIOObjectHandler {
	
  public:
	
    /** Reads lcio clusterer hit objects from an SIO stream.
     */
    unsigned int read(SIO_stream* stream, 
			      EVENT::LCObject** objP) override  ;
	
    /** Writes lcio objects to an SIO stream.
     */
    unsigned int write(SIO_stream* stream, 
			       const EVENT::LCObject* obj) override ;
	
  }; // class
} // namespace

#endif /* ifndef SIO_SIOCLUSTERHANDLER_H */
