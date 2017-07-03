// -*- C++ -*-

/**Typedefs for std::vectors of basic types used in LCIO
 */

#ifndef LCIO_STD_TYPES
#define LCIO_STD_TYPES 1


#include <string>
#include <vector>

namespace EVENT
{
/**Vector of strings.*/
using StringVec = std::vector<std::string> ;
/**Vector of floats.*/
using FloatVec = std::vector<float> ;
/**Vector of doubles.*/
using DoubleVec = std::vector<double> ;
/**Vector of ints.*/
using IntVec = std::vector<int> ;
/**Vector of shorts.*/
using ShortVec = std::vector<short> ;

}

#endif
