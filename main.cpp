#include <iostream>
#include <memory>

#include "classunit.h"
#include "methodunit.h"

#include "printoperationunit.h"
#include "languagefactory.h"

#include "cppfactory.h"
#include "cppunits.h"

#include "csfactory.h"
#include "csunits.h"

#include "javafactory.h"
#include "javaunits.h"

std::string generateProgram(std::shared_ptr<LanguageFactory> lf) {
    std::shared_ptr<ClassUnit> myClass = lf->createClass("myClass");

    myClass->add(
                lf->createMethod("testFunc", "void", 0 ),
                ClassUnit::PUBLIC
                );
    myClass->add(
                lf->createMethod( "testFunc1", "void", 0 ),
                ClassUnit::PUBLIC
                );
    myClass->add(
                lf->createMethod( "testFunc2", "void", MethodUnit::STATIC ),
                ClassUnit::PRIVATE
                );
    myClass->add(
                lf->createMethod( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),
                ClassUnit::PUBLIC
                );

    std::shared_ptr<MethodUnit> method = lf->createMethod("testFunc4", "void", MethodUnit::STATIC );
    method->add( lf->createPrintOperation( "Hello, world!\\n" ) );
    myClass->add( method, ClassUnit::PROTECTED );
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
