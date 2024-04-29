#include "csfactory.h"

std::shared_ptr<ClassUnit> CsFactory::createClass(const std::string &name) const {
    return std::make_shared<CsClassUnit>(name);
}

std::shared_ptr<MethodUnit> CsFactory::createMethod(const std::string &name, const std::string &returnType, Unit::Flags flags) const {
    return std::make_shared<CsMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperationUnit> CsFactory::createPrintOperation(const std::string &text) const {
    return std::make_shared<CsOperationUnit>(text);
}
