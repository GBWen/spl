#ifndef __G4_H__
#define __G4_H__
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <map>
#include "SymbolTable.hpp"
using namespace std;

class Code4
{
public:
	Code4(int num,string op,string arg1,string arg2,string result,SymbolTable* table = NULL,int label = 0):Num(num),Op(op),Arg1(arg1),Arg2(arg2),Result(result),Table(table),Label(label)
	{
	}
	int	Num;
	int	Label;
	string	Op,Arg1,Arg2,Result;
	SymbolTable* Table;
};

class Generate4
{
public:
	Generate4()
	{
		Number = 0;
		Code.clear();
		Vars.clear();
	}
	//string	VisitNode(TreeNode* Node);
	string	VisitNode(TreeNode* Node , SymbolTable* Tree);
	void 	VisitTree(SymbolTable* Tree);
	string	NewVar();
	int 	GetNum(TreeNode* Node , SymbolTable* Tree);
	void	Print();
//private:
	int Number;
	vector<Code4*> Code;
	vector<string> Vars;
};

#endif
