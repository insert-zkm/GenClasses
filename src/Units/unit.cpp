#include "unit.h"

std::string Unit::generateShift(unsigned int level, char shift_char, int shift_size) const {
    return std::string(shift_size * level, shift_char);
}
