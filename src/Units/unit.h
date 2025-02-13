#ifndef UNIT_H
#define UNIT_H

#include <memory>

class Unit {
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags ) {
        throw std::runtime_error("Nesting is not supported");
    }
    virtual std::string compile(unsigned int level = 0) const = 0;

protected:
    virtual std::string generateShift(unsigned int level, char shift_char = ' ', int shift_size = 4) const;
};
#endif // UNIT_H
