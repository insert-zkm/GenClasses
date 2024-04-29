#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <memory>
#include <string>
#include <vector>

#include "unit.h"

class ClassUnit : public Unit {
public:
    enum AcessModifiers {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        ITERNAL,
        PRTECTED_ITERNAL,
        FINAL
    };

    explicit ClassUnit(const std::string name) : m_name(name) {}

protected:
    std::string m_name;
    using Fieds = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fieds> m_fields;
};

#endif // CLASSUNIT_H
