#ifndef SIO_SIOSTRVECHANDLER_H
#define SIO_SIOSTRVECHANDLER_H 1

#include "SIO/SIOObjectHandler.h"


namespace SIO {
    
    
/** Implementation of SIOObjectHandler to handle IO of StrVecs.
 *
 * @author vogt
 * @version $Id: SIOStrVecHandler.h,v 1.3 2005-04-15 08:37:43 gaede Exp $
 */
  class SIOStrVecHandler : public SIOObjectHandler {
	
  public:
	
    /** Reads objects from an SIO stream.
     */
    unsigned int read(SIO_stream* stream, 
			      EVENT::LCObject** objP) override  ;
	
    /** Writes lcio objects to an SIO stream.
     */
    unsigned int write(SIO_stream* stream, 
			       const EVENT::LCObject* obj) override ;
	
  }; // class
} // namespace

#endif /* ifndef SIO_SIOSTRVECHANDLER_H */
