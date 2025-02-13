#include "csunits.h"

const std::vector<std::string> CsClassUnit::ACCESS_MODIFIERS =
    { "public", "protected", "private", "private protected", "iternal", "protected internal" };

CsClassUnit::CsClassUnit(const std::string& name) : ClassUnit(name) {
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void CsClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags) {
    int accessModifier = PRIVATE;
    if(flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

std::string CsClassUnit::compile(unsigned int level) const {
    std::string result = "class " + m_name + " {\n";
    for(int i = 0; i < ACCESS_MODIFIERS.size(); i++) {
        if(m_fields[i].empty()) {
            continue;
        }

        for(int j = 0; j < m_fields[i].size(); j++) {
            result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + m_fields[i][j]->compile(level + 1) + "\n";
        }
    }

    result += generateShift(level) + "}\n";
    return result;
}

std::string CsMethodUnit::compile(unsigned int level) const {
    std::string result = "";
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";

    if(m_flags & CONST) {
        result += " const";
    }
    result += " {\n";
    for(int i = 0; i < m_body.size(); i++) {
        result += m_body[i]->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}

std::string CsOperationUnit::compile(unsigned int level) const {
    return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
}
