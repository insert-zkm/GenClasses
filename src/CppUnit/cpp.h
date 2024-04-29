#ifndef CPP_H
#define CPP_H
#include <memory>

#include "classunit.h"
#include "languagefactory.h"
#include "methodunit.h"
#include "printoperationunit.h"

class CppClassUnit : public ClassUnit {
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit CppClassUnit(const std::string& name);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;

    std::string compile(unsigned int level = 0) const override;
};

class CppMethodUnit : public MethodUnit {
public:
    CppMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) : MethodUnit(name, returnType, flags) {};

    std::string compile(unsigned int level = 0) const override;
};

class CppOperationUnit : public PrintOperationUnit {
public:
    CppOperationUnit(const std::string& text) : PrintOperationUnit(text) {};

    std::string compile(unsigned int level = 0) const override;
};
#endif // CPP_H
