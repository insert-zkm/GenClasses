#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include "classunit.h"
#include "languagefactory.h"
#include "methodunit.h"
#include "printoperationunit.h"
#include "unit.h"

#include "cppunits.h"

class CppFactory : public LanguageFactory
{
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name) const override;
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType = "void", Unit::Flags flags = 0) const override;
    std::shared_ptr<PrintOperationUnit> createPrintOperation(const std::string& text) const override;

};

#endif // CPPFACTORY_H
