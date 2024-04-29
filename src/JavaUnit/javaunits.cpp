#include "javaunits.h"

const std::vector<std::string> JavaClassUnit::ACCESS_MODIFIERS =
    {"public", "protected", "private"};

JavaClassUnit::JavaClassUnit(const std::string &name) : ClassUnit(name) {
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void JavaClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags) {
    int accessModifier = PRIVATE;
    if(flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

std::string JavaClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[i].empty() ) {
            continue;
        }
        for(int j = 0; j < m_fields[i].size(); j++) {
            result += generateShift(level + 1) + ACCESS_MODIFIERS[j] + " " + m_fields[i][j]->compile(level + 1);
        }
        result += "\n";
    }
    result += generateShift(level) + "}\n";
    return result;
}

std::string JavaMethodUnit::compile(unsigned int level) const {
    std::string result = "";
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    } else if(m_flags & FINAL) {
        result += "final ";
    }
    result += m_returnType + " ";
    result += m_name + "()";

    result += " {\n";
    for(int i = 0; i < m_body.size(); i++) {
        result += m_body[i]->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}

std::string JavaOperationUnit::compile(unsigned int level) const {
    return generateShift(level) + "System.out.println(\"" + m_text + "\");\n";
}
