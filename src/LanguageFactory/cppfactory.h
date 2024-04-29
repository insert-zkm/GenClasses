#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include "classunit.h"
#include "languagefactory.h"
#include "methodunit.h"
#include "printoperationunit.h"
#include "unit.h"

// cpp language units
#include "cpp.h"

class CppFactory : public LanguageFactory
{
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name) const override;
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override;
    std::shared_ptr<PrintOperationUnit> createPrintOperation(const std::string& text) const override;

};

#endif // CPPFACTORY_H
