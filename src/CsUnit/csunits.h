#ifndef LK_H
#define LK_H

#include <memory>

#include "classunit.h"
#include "languagefactory.h"
#include "methodunit.h"
#include "printoperationunit.h"

class CsClassUnit : public ClassUnit {
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit CsClassUnit(const std::string& name);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;

    std::string compile(unsigned int level = 0) const override;
};

class CsMethodUnit : public MethodUnit {
public:
    CsMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) : MethodUnit(name, returnType, flags) {};

    std::string compile(unsigned int level = 0) const override;
};

class CsOperationUnit : public PrintOperationUnit {
public:
    CsOperationUnit(const std::string& text) : PrintOperationUnit(text) {};

    std::string compile(unsigned int level = 0) const override;
};

#endif // LK_H
