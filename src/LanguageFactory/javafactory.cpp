#include "javafactory.h"

std::shared_ptr<ClassUnit> JavaFactory::createClass(const std::string &name) const {
    return std::make_shared<JavaClassUnit>(name);
}

std::shared_ptr<MethodUnit> JavaFactory::createMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const {
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperationUnit> JavaFactory::createPrintOperation(const std::string &text) const {
    return std::make_shared<JavaOperationUnit>(text);
}
