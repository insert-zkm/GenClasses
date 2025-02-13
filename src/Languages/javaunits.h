#ifndef JAVAUNITS_H
#define JAVAUNITS_H

#include <memory>

#include "classunit.h"
#include "languagefactory.h"
#include "methodunit.h"
#include "printoperationunit.h"

class JavaClassUnit : public ClassUnit {
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit JavaClassUnit(const std::string& name);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;

    std::string compile(unsigned int level = 0) const override;
};

class JavaMethodUnit : public MethodUnit {
public:
    JavaMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) : MethodUnit(name, returnType, flags) {};

    std::string compile(unsigned int level = 0) const override;
};

class JavaOperationUnit : public PrintOperationUnit {
public:
    JavaOperationUnit(const std::string& text) : PrintOperationUnit(text) {};

    std::string compile(unsigned int level = 0) const override;
};


#endif // JAVAUNITS_H
