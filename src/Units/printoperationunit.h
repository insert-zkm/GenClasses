#ifndef PRINTOPERATIONUNIT_H
#define PRINTOPERATIONUNIT_H

#include <string>

#include "unit.h"

class PrintOperationUnit : public Unit {
public:
    PrintOperationUnit( const std::string& text ) : m_text( text ) { }

protected:
    std::string m_text;
};

#endif // PRINTOPERATIONUNIT_H
