#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include "classunit.h"
#include "languagefactory.h"
#include "methodunit.h"
#include "printoperationunit.h"
#include "unit.h"

#include "javaunits.h"

class JavaFactory : public LanguageFactory
{
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name) const override;
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override;
    std::shared_ptr<PrintOperationUnit> createPrintOperation(const std::string &text) const override;
};

#endif // JAVAFACTORY_H
