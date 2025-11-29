#include <cmath>

#include "MathFunctions.h"

#ifdef USE_MYMATH
#include "Table.h"
#include "mysqrt.h" // declaration in namespace detail
#endif

namespace mathfunctions {

#ifdef USE_MYMATH
namespace detail {
double mysqrt(double x);
}
#endif

double sqrt(double x) {
#ifndef USE_MYMATH
  return std::sqrt(x);
#else
  return detail::mysqrt(x);
#endif
}

} // namespace mathfunctions
