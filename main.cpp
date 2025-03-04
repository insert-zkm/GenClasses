#include <iostream>
#include <memory>

#include "classunit.h"
#include "methodunit.h"
#include "printoperationunit.h"

#include "languagefactory.h"
#include "cppfactory.h"
#include "csfactory.h"
#include "javafactory.h"

std::string generateProgram(std::shared_ptr<LanguageFactory> lf) {
    std::shared_ptr<ClassUnit> myClass = lf->createClass("myClass");
    std::shared_ptr<ClassUnit> subClass = lf->createClass("subClass");


    std::shared_ptr<Unit> method1 = lf->createMethod("testFunc1");
    std::shared_ptr<Unit> method2 = lf->createMethod("testFunc2");
    std::shared_ptr<Unit> method3 = lf->createMethod("testFunc3");
    std::shared_ptr<Unit> method4 = lf->createMethod("testFunc4");

    myClass->add(method1, ClassUnit::PUBLIC);
    myClass->add(method2, ClassUnit::PUBLIC);
    myClass->add(method3, ClassUnit::PRIVATE);
    myClass->add(method4, ClassUnit::PUBLIC);
    subClass->add(method1, ClassUnit::PRIVATE);

    std::shared_ptr<MethodUnit> method = lf->createMethod("testFunc4", "void", MethodUnit::STATIC);

    method->add(lf->createPrintOperation("Hello, world!\\n"));
    myClass->add(method, ClassUnit::PROTECTED);
    myClass->add(subClass, ClassUnit::PRIVATE);
    return myClass->compile();
}

int main()
{
    std::shared_ptr<LanguageFactory> lf = std::make_shared<CppFactory>();
    std::cout << generateProgram(lf) << std::endl;

    lf = std::make_shared<CsFactory>();
    std::cout << generateProgram(lf) << std::endl;

    lf = std::make_shared<JavaFactory>();
    std::cout << generateProgram(lf) << std::endl;
    return 0;
}
