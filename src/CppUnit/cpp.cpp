#include "cpp.h"

const std::vector<std::string> CppClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };

CppClassUnit::CppClassUnit(const std::string& name) : ClassUnit(name) {
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void CppClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags) {
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}

std::string CppClassUnit::compile(unsigned int level) const {
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}

std::string CppMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift( level );
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( m_flags & CONST ) {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body ) {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

std::string CppOperationUnit::compile(unsigned int level) const {
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
