#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include "languagefactory.h"

class JavaFactory : public LanguageFactory
{
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name) const override;
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override;
};

#endif // JAVAFACTORY_H
