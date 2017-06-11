#ifndef __PASCAL_H__
#define __PASCAL_H__
#include <string>
#include <vector>

extern "C" {
    int yywrap(void);
    int yylex(void);
    void yyerror(const char*);
}

extern char* yytext;
extern int yylineno;

enum ValueType {
	VT_INT, VT_REAL, VT_CHAR, VT_BOOL, VT_STRING,
    VT_TOKEN,
    VT_NAME
};

struct ValueNode{
	enum ValueType type;
    std::string name;
};

#endif
