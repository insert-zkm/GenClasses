#include "cppfactory.h"


std::shared_ptr<ClassUnit> CppFactory::createClass(const std::string &name) const {
    return std::make_shared<CppClassUnit>(name);
}

std::shared_ptr<MethodUnit> CppFactory::createMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const {
    return std::make_shared<CppMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperationUnit> CppFactory::createPrintOperation(const std::string &text) const {
    return std::make_shared<CppOperationUnit>(text);
}
