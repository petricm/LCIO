#ifndef EVENT_LCFLAGIMPL_H
#define EVENT_LCFLAGIMPL_H 1

#include "EVENT/LCFlag.h"

namespace IMPL {

/** Implementation of helper class to create and interpret the 32-bit flag word in LCCollections.
 *  Bits are defined in class LCIO.
 *
 * @see LCIO
 * @author gaede 
 * @version May 6, 2003
 */
class LCFlagImpl : public EVENT::LCFlag {

private:
  int _flag{0} ;

public: 
    
  /** Constructor initializing flag with 0.
   */
  LCFlagImpl() ;

  /**Constructor for evaluating an existing flag word.
   */
  LCFlagImpl(int flag) ;

  /// Destructor.
  ~LCFlagImpl() override { /* nop */; }
  
  /** Returns true if bit at given index is set.
   */
  bool bitSet(int index) const override ;
  
  /**Returns the flag word.
   */
  int getFlag() const override ;

  /** Sets bit to 1.
   */
  void setBit(int bit) override ;
  
  /** Sets bit to 0.
   */
  void unsetBit(int bit) override ;
  
}; // class
} // namespace EVENT
#endif /* ifndef EVENT_LCFLAGIMPL_H */
