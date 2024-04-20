#include "unit.h"

std::string Unit::generateShift(unsigned int level) const {
    static const std::string DEFAULT_SHIFT = "\t";
    std::string result;
    for( unsigned int i = 0; i < level; ++i ) {
        result += DEFAULT_SHIFT;
    }
    return result;
}
