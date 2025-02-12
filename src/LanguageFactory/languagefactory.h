#ifndef LANGUAGEFACTORY_H
#define LANGUAGEFACTORY_H

#include <memory>

#include "classunit.h"
#include "methodunit.h"
#include "printoperationunit.h"
#include "unit.h"

class LanguageFactory
{
public:
    virtual ~LanguageFactory() = default;

    virtual std::shared_ptr<ClassUnit> createClass(const std::string& name) const = 0;
    virtual std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType = "void", Unit::Flags flags = 0) const = 0;
    virtual std::shared_ptr<PrintOperationUnit> createPrintOperation(const std::string& text) const = 0;
};

#endif // LANGUAGEFACTORY_H
