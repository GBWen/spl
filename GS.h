#ifndef __GS_H__
#define __GS_H__

#include "SymbolTable.hpp"
#include "G4.h"
#include <sstream>

#define INTEGER 1
#define REAL 2
#define CHAR 3
#define BOOLEAN 4
#define ARRAY 5
#define RECORD 6

using namespace std;

class GS
{
public:
	GS(Generate4 &Gen, SymbolTable* st = programTable);
	int GenASM(Code4* Code, Code4* NCode);
	void prepareStack();
	int TempToRegNum(string &Temp);
	int TempToFloatNum(string &Temp);
	int getType(TreeNode *name);//type: 1:integer 2:real 3:char 4:boolean 5:array 6:record

	SymbolTable *current;
	Generate4 &g;
	int floatNum;
	int stringNum;
	int paraNum;
};

#endif