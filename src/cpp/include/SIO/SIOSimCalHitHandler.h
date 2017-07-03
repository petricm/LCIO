#ifndef SIO_SIOSIMCALHITHANDLER_H
#define SIO_SIOSIMCALHITHANDLER_H 1

#include "SIO/SIOObjectHandler.h"


namespace SIO {
    
    
  /** Implementation of SIOObjectHandler to handle IO of SimCalorimeterHits.
   *
   * @author gaede
   * @version $Id: SIOSimCalHitHandler.h,v 1.6 2005-04-15 08:37:43 gaede Exp $
   */
  class SIOSimCalHitHandler : public SIOObjectHandler {
	
  public:
	
    /** Reads lcio calorimeter hit objects from an SIO stream.
     */
    unsigned int read(SIO_stream* stream, 
			      EVENT::LCObject** objP) override  ;
	
    /** Writes lcio objects to an SIO stream.
     */
    unsigned int write(SIO_stream* stream, 
			       const EVENT::LCObject* obj) override ;
	
  }; // class
} // namespace

#endif /* ifndef hep_lcio_event_SIOCALHITHANDLER_H */
