//
// Created by Ahmed Yakout on 5/10/17.
//

#ifndef SIC_ASSEMBLER_ORG_DIRECTIVE_H
#define SIC_ASSEMBLER_ORG_DIRECTIVE_H

#include <string>
#include <directives/directive.h>

class org_directive: public directive {
public:
    org_directive(std::string);
    virtual void handle();
};

#endif