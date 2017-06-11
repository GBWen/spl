#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__
#include "pascal.h"
#include <string>
#include <vector>
#include <map>

class Generate4;

const int ProgrameNode = 1;
const int ProcedureNode = 2;
const int ExpressionNode = 3;
const int VariableNode = 4;
const int StatementNode = 5;
const int TokenNode = 6;
const int ValNode = 7;
const int TypeNode = 8;

class TreeNode {
	friend class Generate4;
	friend class Code4;
public:
	TreeNode(ValueNode* val, int type = -1);
    TreeNode(int type);
	TreeNode(const TreeNode& node);
    void insert(TreeNode* node);
	void insertChild(TreeNode* node);
	void insertChild(const TreeNode& node);

	int type;
	int pos;
	std::string name;
	ValueNode* val;
	std::vector<TreeNode*> Children;

	// for debug
	void print(int type=0, int level=0);
};

struct Parameter{
	Parameter(std::string name, bool reference, TreeNode* type) : name(name), reference(reference), type(type){}
	std::string name;
	bool reference;
	TreeNode* type;
};

class SymbolTable{
	friend class Generate4;
	friend class Code4;
public:
	SymbolTable(SymbolTable* fa);
	bool insertDecl(std::string name, TreeNode* node);
	TreeNode* lookupDecl(std::string name, int* count = NULL);
	bool insertProc(std::string name, SymbolTable* node);
	SymbolTable* lookupProc(std::string name, int* count = NULL);
	void insertParameter(std::string name, bool reference, TreeNode* type);
    TreeNode* self;
    SymbolTable* father;
	std::vector<SymbolTable*> Children;
	std::vector<Parameter*> parameters;
	int stackLength;

	std::map<std::string, TreeNode*> decl;
	std::map<std::string, SymbolTable*> proc;
	// for debug
	void print(int type=0, int level=0);
	void printDecl(int type=0, int level=0);
	void printProc(int type=0, int level=0);
	void printParam(int type=0, int level=0);
	void printBlock(int type=0, int level=0);
};

extern SymbolTable* programTable;

#endif
