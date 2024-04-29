#ifndef CSFACTORY_H
#define CSFACTORY_H

#include "classunit.h"
#include "languagefactory.h"
#include "methodunit.h"
#include "printoperationunit.h"
#include "unit.h"

class CsFactory : public LanguageFactory
{
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name) const override;
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override;
};

#endif // CSFACTORY_H
