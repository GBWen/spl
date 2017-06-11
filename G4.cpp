#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <string>
#include <map>
#include <assert.h>
#include "G4.h"
using namespace std;

//map<string,int> jump;

string Generate4::NewVar()
{
	int i = Vars.size();
	string Str1 = "Temp";
	char buf[10];
	sprintf(buf, "%d", i);
	string Str2 = buf;
	string NewVariable = Str1.append(Str2);
	Vars.push_back(NewVariable);
	return NewVariable;
}

string Generate4::VisitNode(TreeNode* Node,SymbolTable* Tree)
{
	string op,arg1,arg2,result;
	//Node->print(1);
	//printf("Type : %d ---------\n", Node->type);
	if (Node->type == 1)
	{
		vector<TreeNode*>::iterator iter;
		for (iter=Node->Children.begin(); iter!=Node->Children.end(); iter++)
		{
			VisitNode(*iter,Tree);
		}
		return "";
	}

	else if (Node->type == 2)
	{
		int num=0;
		vector<TreeNode*>::iterator iter;
		if (Node->Children.size() > 0)
		{
			for (iter=Node->Children[1]->Children.begin(); iter!=Node->Children[1]->Children.end(); iter++)
			{
				result = VisitNode(*iter,Tree);
				Code4* NewCode = new Code4(Number++,"para","","",result,Tree);
				Code.push_back(NewCode);
			}
		}
		result = Node->name;
		Code4* NewCode = new Code4(Number++,"call","","",result,Tree);
		Code.push_back(NewCode);
		string NewVariable = NewVar();
		Code4* NewCode2 = new Code4(Number++,"return","","",NewVariable,Tree);
		Code.push_back(NewCode2);
		return NewVariable;
	}

	else if (Node->type == 3)
	{
		if (Node->name == ":=")
		{
			result = VisitNode(Node->Children[0],Tree);
			arg1 = VisitNode(Node->Children[1],Tree);
			Code4* NewCode = new Code4(Number++,":=",arg1,"",result,Tree);
			Code.push_back(NewCode);
			if (Node->Children[0]->Children.size() ==0 )
			{				
				Code4* NewCode2 = new Code4(Number++,":=",result,"",Node->Children[0]->name,Tree);
				Code.push_back(NewCode2);	
			}
			else
			{
				string str = "";
				vector<TreeNode*>::iterator iter;
				if  (Node->Children[0]->type == 4)
				{
					str = Node->Children[0]->name;
					for (iter=Node->Children[0]->Children.begin(); iter!=Node->Children[0]->Children.end(); iter++)
					{
						str = str + VisitNode(*iter,Tree);
					}					
				}
//				else
//				{
//					str  =  Node->Children[0]->Children[0]->name + "." + Node->Children[0]->Children[1]->name;
//				}
				Code4* NewCode2 = new Code4(Number++,":=",result,"",str,Tree);
				Code.push_back(NewCode2);	
			}
			return result;
		}
		else
		{
			// if (Node->name == "plus")
			// 	op = "+";
			// else if (Node->name == "minus")
			// 	op = "-";
			// else if (Node->name == "or")
			// 	op = "or";
			// else if (Node->name == "mul")
			// 	op = "*";
			// else if (Node->name == "div")
			// 	op = "/";
			// else if (Node->name == "mod")
			// 	op = "mod";
			// else if (Node->name == "and")
			// 	op = "and";
			// else if (Node->name == "not")
			// 	op = "not";
			// else if (Node->name == "GE")
			// 	op = ">=";
			// else if (Node->name == "GT")
			// 	op = ">";
			// else if (Node->name == "LE")
			// 	op = "<=";
			// else if (Node->name == "LE")
			// 	op = "<";
			// else if (Node->name == "EQUAL")
			// 	op = "==";
			// else if (Node->name == "UNEQUAL")
			// 	op = "!=";
			op = Node->name;
			arg1 = VisitNode(Node->Children[0],Tree);
			if (Node->Children.size()>=2)
				arg2 = VisitNode(Node->Children[1],Tree);
			string NewVariable = NewVar();
			Code4* NewCode = new Code4(Number++,op,arg1,arg2,NewVariable,Tree);
			Code.push_back(NewCode);
			return NewVariable;
		}
	}

	else if (Node->type == 4)
	{
		string Str  = Node->name;
		if (Tree->lookupDecl(Str) == NULL)
		{
			cout<<"error: ‘"<<Str<<"’ was not declared in this scope"<<endl;
		}
		// bool Flag = true;
		// int Str2Num = 0;
		// for(int i=0 ; i<Str.size() ; i++)
		// {
		// 	if ((Str.at(i)>'9') || (Str.at(i)<'0') )
		// 	{
		// 		Flag = false;
		// 	}
		// 	else
		// 	{
		// 		Str2Num = Str2Num*10 + Str.at(i)-'0';
		// 	}
		// }
		if (Node->Children.size() == 0)
		{
			// if (Flag == false)
			// 	return Str;
			// else
			// {
				string NewVariable = NewVar();
				Code4* NewCode = new Code4(Number++,":=",Node->name,"",NewVariable,Tree);
				Code.push_back(NewCode);
				return NewVariable;
			// }
		}
		else
		{
			// string Index = VisitNode(Node->Children[1]);
			// string NewVariable = NewVar();
			// Code4* NewCode = new Code4(Number++,":=",Index,"",NewVariable);
			// Code.push_back(NewCode);
			string str = "";
			vector<TreeNode*>::iterator iter;
			for (iter=Node->Children.begin(); iter!=Node->Children.end(); iter++)
			{
				str = str + VisitNode(*iter,Tree);
			}
			return Node->name+str;
		}
	}

	else if (Node->type == 5)
	{
		// if (Node->name == "read")
		// {
		// 	result = VisitNode(Node->Children[0]);
		// 	Code4* NewCode = new Code4(Number++,"read","","",result);
		// 	Code.push_back(NewCode);
		// 	return "";
		// }
		// else if (Node->name == "write")
		// {
		// 	result = VisitNode(Node->Children[0]);
		// 	Code4* NewCode = new Code4(Number++,"write","","",result);
		// 	Code.push_back(NewCode);
		// 	return "";
		// }
		//
		if (Node->name == "goto")
		{
			op = "call";
			// map<string,int>::iterator it;
// 			it = jump.find(Node->Children[0]->name);
// 			char str[10];
// 			if (it != jump.end())
// 			{
// 				int t;
// 				t = it->second;
// 				sprintf(str,"%d",t);
// //				cout<<it->second<<endl;
// //				cout<<str<<endl;
// 			}
			Code4* NewCode = new Code4(Number++,op,"","",Node->Children[0]->name,Tree);
			Code.push_back(NewCode);
			return "";
		}
		else if (Node->name == "if")
		{
			string Exp = VisitNode(Node->Children[1],Tree);
			op = "jnz";
			char str[10];
			sprintf(str,"%d",Number+2);
			Code4* NewCode = new Code4(Number++,op,Exp,"",str,Tree);
			Code.push_back(NewCode);
			int station = Number;
			op = "j";
			int Sum = 0;
			vector<TreeNode*>::iterator iter;
			for (iter=Node->Children[2]->Children.begin(); iter!=Node->Children[2]->Children.end(); iter++)
			{
				Sum = Sum +GetNum(*iter,Tree);
			}
			sprintf(str,"%d",Sum+Number+2);
			Code4* NewCode2 = new Code4(Number++,op,"","",str,Tree);
			Code.push_back(NewCode2);
			for (iter=Node->Children[2]->Children.begin(); iter!=Node->Children[2]->Children.end(); iter++)
			{
				VisitNode(*iter,Tree);
			}
			// VisitNode(Node->Children[3]);
			if (Node->Children.size()>3)
			{
				op = "jnz";
				arg1 = Exp;
				char str[10];
				sprintf(str,"%d",GetNum(Node->Children[3],Tree)+Number+1);
				Code4* NewCode2 = new Code4(Number++,op,arg1,"",str,Tree);
				Code.push_back(NewCode2);
				VisitNode(Node->Children[3],Tree);
			}
			return "";
		}
		else if (Node->name == "else")
		{
			vector<TreeNode*>::iterator iter;
			for (iter=Node->Children.begin(); iter!=Node->Children.end(); iter++)
			{
				VisitNode(*iter,Tree);
			}
			return "";
		}
		else if (Node->name == "for")
		{
			// result = VisitNode(Node->Children[1]);
			// arg1 = VisitNode(Node->Children[3]);
			// arg2 = VisitNode(Node->Children[5]);
			// Code4* NewCode = new Code4(Number++,"for",arg1,arg2,result);
			// Code.push_back(NewCode);
			// Code4* NewCode1 = new Code4(Number++,"begin","","","");
			// Code.push_back(NewCode1);
			// vector<TreeNode*>::iterator iter;
			// for (iter=Node->Children[6]->Children.begin(); iter!=Node->Children[6]->Children.end(); iter++)
			// {
			// 	VisitNode(*iter);
			// }
			// Code4* NewCode2 = new Code4(Number++,"end","","","");
			// Code.push_back(NewCode2);
			// return "";

			int Num = this->Number;
			string NewVariable = NewVar();
			Code4* NewCode = new Code4(Number++,":=",Node->Children[3]->name,"",NewVariable,Tree);
			Code.push_back(NewCode);
			vector<TreeNode*>::iterator iter;
			for (iter=Node->Children[6]->Children.begin(); iter!=Node->Children[6]->Children.end(); iter++)
			{
				VisitNode(*iter,Tree);
			}
			string n = VisitNode(Node->Children[5],Tree);
			arg1 = NewVar();
			if (Node->Children[4]->name == "to")
			{
				Code4* NewCode3 = new Code4(Number++,"<",NewVariable ,n,arg1,Tree);
				Code.push_back(NewCode3);
			}
			else
			{
				Code4* NewCode3 = new Code4(Number++,">",NewVariable ,n,arg1,Tree);
				Code.push_back(NewCode3);
			}
			if (Node->Children[4]->name == "to")
				op = "+";
			else
				op = "-";
			Code4* NewCode2 = new Code4(Number++,"+",NewVariable,"1",NewVariable,Tree);
			Code.push_back(NewCode2);
			char str[10];
			sprintf(str,"%d",Num+1);
			Code4* NewCode4 = new Code4(Number++,"jnz",arg1,"",str,Tree);
			Code.push_back(NewCode4);
			return "";
		}
		else if (Node->name == "while")
		{
			string Exp = VisitNode(Node->Children[1],Tree);
			op = "jnz";
			char str[10];
			sprintf(str,"%d",Number+2);
			Code4* NewCode = new Code4(Number++,op,Exp,"",str,Tree);
			Code.push_back(NewCode);
			int station = Number;
			op = "j";
			int Sum = 0;
			vector<TreeNode*>::iterator iter;
			for (iter=Node->Children[2]->Children.begin(); iter!=Node->Children[2]->Children.end(); iter++)
			{
				Sum = Sum +GetNum(*iter,Tree);
			}
			sprintf(str,"%d",Sum+Number+2);
			Code4* NewCode2 = new Code4(Number++,op,"","",str,Tree);
			Code.push_back(NewCode2);
			// cout<<Node->Children[2]->Children.size();
			for (iter=Node->Children[2]->Children.begin(); iter!=Node->Children[2]->Children.end(); iter++)
			{
				VisitNode(*iter,Tree);
			}
			sprintf(str,"%d",station-1);
			Code4* NewCode3 = new Code4(Number++,op,"","",str,Tree);
			Code.push_back(NewCode3);
			return "";
		}
		else if (Node->name == "repeat")
		{
			int Num = this->Number;
			vector<TreeNode*>::iterator iter;
			for (iter=Node->Children[0]->Children.begin(); iter!=Node->Children[0]->Children.end(); iter++)
			{
				VisitNode(*iter,Tree);
			}
			arg1 = VisitNode(Node->Children[1]->Children[0],Tree);
			char str[10];
			sprintf(str,"%d",Num);
			Code4* NewCode3 = new Code4(Number++,"jnz",arg1,"",str,Tree);
			Code.push_back(NewCode3);
			return "";
		}
		else if (Node->name == "case")
		{
			string Exp = VisitNode(Node->Children[1],Tree);
			string NewVariable = NewVar();
			Code4* NewCode = new Code4(Number++,":=",Exp,"",NewVariable,Tree);
			Code.push_back(NewCode);
			for (int i=0;i<Node->Children[2]->Children[0]->Children.size();i++)
			{
				string comp = NewVar();
				Code4* NewCode = new Code4(Number++,"==",NewVariable,Node->Children[2]->Children[0]->Children[i]->Children[0]->name,comp,Tree);
				Code.push_back(NewCode);
				vector<TreeNode*>::iterator iter;
				int Sum = 0;
				char str[10];
				for (iter=Node->Children[2]->Children[0]->Children[i]->Children.begin()+1; iter!=Node->Children[2]->Children[0]->Children[i]->Children.end(); iter++)
				{
					Sum = Sum + GetNum(*iter,Tree);
				}
				sprintf(str,"%d",Sum+Number+1);
				Code4* NewCode2 = new Code4(Number++,"jz",comp,"",str,Tree);
				Code.push_back(NewCode2);
				for (iter=Node->Children[2]->Children[0]->Children[i]->Children.begin()+1; iter!=Node->Children[2]->Children[0]->Children[i]->Children.end(); iter++)
				{
					VisitNode(*iter,Tree);
				}
			}
			return "";
		}
		else if (Node->name == ":")
		{
			//jump[Node->Children[0]->name] = Number;
			// cout<<Node->Children[0]->name<<" "<<Number+1<<endl;
			Code4* NewCode = new Code4(Number++,"label","","",Node->Children[0]->name,Tree);
			Code.push_back(NewCode);
			vector<TreeNode*>::iterator iter;
			for (iter=Node->Children.begin()+1; iter!=Node->Children.end(); iter++)
			{
				VisitNode(*iter,Tree);
			}
			return "";
		}
		else if (Node->name == ".")
		{
//			string NewVariable = NewVar();
//			Code4* NewCode = new Code4(Number++,":=",Node->name,"",NewVariable,Tree);
//			Code.push_back(NewCode);
			return Node->Children[0]->name + "." + Node->Children[1]->name;
		}
		else if (Node->name == "exit")
		{
			string str = VisitNode(Node->Children[0],Tree);
			Code4* NewCode = new Code4(Number++,"exit","","",str,Tree);
			Code.push_back(NewCode);
			return "";
		}
		else if (Node->name =="read" || Node->name =="readln")
		{
			vector<TreeNode*>::iterator iter;
			for (iter=Node->Children[1]->Children.begin(); iter!=Node->Children[1]->Children.end(); iter++)
			{
				result = VisitNode(*iter,Tree);
				op = "read";
				Code4* NewCode = new Code4(Number++,op,"","",result);
				Code.push_back(NewCode);
			}
			if (Node->name =="readln")
			{
				Code4* NewCode = new Code4(Number++,"readln","","","");
				Code.push_back(NewCode);
			}
			return "";
		}
		else if (Node->name =="write" || Node->name =="writeln")
		{
			vector<TreeNode*>::iterator iter;
			if (Node->Children.size() > 0)
			{
				for (iter=Node->Children[1]->Children.begin(); iter!=Node->Children[1]->Children.end(); iter++)
				{
					result = VisitNode(*iter,Tree);
					op = "write";
					Code4* NewCode = new Code4(Number++,op,"","",result);
					Code.push_back(NewCode);
				}
			}
			if (Node->name =="writeln")
			{
				Code4* NewCode = new Code4(Number++,"writeln","","","");
				Code.push_back(NewCode);
			}
			return "";
		}
	}
	else if (Node->type == 6)
	{
		return Node->name;
	}
	else if (Node->type == 7)
	{
		string NewVariable = NewVar();
		Code4* NewCode = new Code4(Number++,":=",Node->name,"",NewVariable,Tree);
		Code.push_back(NewCode);
		return NewVariable;
	}
//	else if (Node->type == 8)
//	{
//
//	}
	assert(false);
}

int Generate4::GetNum(TreeNode* Node , SymbolTable* Tree)
{
	Generate4 TempGen;
	TempGen.VisitNode(Node,Tree);
	return TempGen.Number;
}

void Generate4::Print()
{
	vector<Code4*>::iterator iter;
	for (iter=Code.begin(); iter!=Code.end(); iter++)
	{
		cout<<"("<<(*iter)->Num<<")    ";
		cout<<(*iter)->Op<<",";
		cout<<(*iter)->Arg1<<",";
		cout<<(*iter)->Arg2<<",";
		cout<<(*iter)->Result<<endl;
		//cout<<(*iter)->Label<<endl;
		//cout<<(*iter)->Table<<endl;
	}
}

void Generate4::VisitTree(SymbolTable* Tree)
{
	SymbolTable * Table[1000] ;
	int  l = 0;
	int  r = 1;
	Table[r] = Tree;
	while (l<r)
	{
		l++;
		int i=2;
		if (Table[l] == programTable)
			i = 1;
		VisitNode(Table[l] ->self->Children[i]->Children[1],Table[l] );
		if (i!=1)
		{
			Code4* NewCode2 = new Code4(Number++,"exit","","","",Table[l]);
			Code.push_back(NewCode2);
		}
		if (i==1)
		{
			Code4* NewCode = new Code4(Number++,"end","","","",Table[l]);
			Code.push_back(NewCode);
		}
		map<string, SymbolTable*>::iterator it;
		for (it = Table[l]->proc.begin(); it != Table[l]->proc.end(); it++)
		{
			Code4* NewCode = new Code4(Number++,"proc","","",it->first.c_str(),Table[l]);
			Code.push_back(NewCode);
			//VisitTree(it->second);
			r++;
			Table[r] = it->second;
//			Code4* NewCode2 = new Code4(Number++,"exit","","","",Table[l]);
//			Code.push_back(NewCode2);
		}
	}

//	int i=2;
//	if (Tree == programTable)
//		i = 1;
//	VisitNode(Tree->self->Children[i]->Children[1],Tree);
//	if (i==1)
//	{
//		Code4* NewCode = new Code4(Number++,"end","","","",Tree);
//		Code.push_back(NewCode);
//	}
//	map<string, SymbolTable*>::iterator it;
//	for (it = Tree->proc.begin(); it != Tree->proc.end(); it++)
//	{
//		Code4* NewCode = new Code4(Number++,"proc","","",it->first.c_str(),Tree);
//		Code.push_back(NewCode);
//		VisitTree(it->second);
//		Code4* NewCode2 = new Code4(Number++,"exit","","","",Tree);
//		Code.push_back(NewCode2);
//	}
	vector<Code4*>::iterator iter;
	for (iter=Code.begin(); iter!=Code.end(); iter++)
	{
		if ((*iter)->Op == "j" ||(*iter)->Op == "jz" || (*iter)->Op =="jnz")
		{
			string Str = (*iter)->Result;
			int Str2Num = 0;
			for(int i=0 ; i<Str.size() ; i++)
			{
				Str2Num = Str2Num*10 + Str.at(i)-'0';
			}
			if (Str2Num < Code.size())
			{
				Code[Str2Num]->Label =1;
			}
			else
			{
				//cout<<Str2Num<<endl;
				//printf("error jump to unknow area.\n");
			}
		}
	}
}

/*
int main()
{
	TreeNode* P = new TreeNode(1,"main");
	P->Insert(3,":=");
	P->Children[0]->Insert(4,"a");
	P->Children[0]->Children[0]->Insert(6,"[");
	P->Children[0]->Children[0]->Insert(4,"1");
	P->Children[0]->Children[0]->Insert(6,",");
	P->Children[0]->Children[0]->Insert(4,"1");
	P->Children[0]->Children[0]->Insert(6,"]");
	P->Children[0]->Insert(3,"-");
	P->Children[0]->Children[1]->Insert(7,"1");

	P->Insert(2,"f");
	P->Children[1]->Insert(6,"(");
	P->Children[1]->Insert(5,"args_list");
	P->Children[1]->Insert(6,")");
	P->Children[1]->Children[1]->Insert(4,"b");
	P->Children[1]->Children[1]->Insert(4,"c");
	P->Children[1]->Children[1]->Insert(7,"1");

	P->Insert(5,"goto");
	P->Children[2]->Insert(7,"12345");

	P->Insert(5,"for");
	P->Children[3]->Insert(6,"for");
	P->Children[3]->Insert(4,"i");
	P->Children[3]->Insert(3,":=");
	P->Children[3]->Insert(4,"1");
	P->Children[3]->Insert(6,"to");
	P->Children[3]->Insert(4,"n");
	P->Children[3]->Insert(6,"do");
	P->Children[3]->Children[6]->Insert(3,":=");
	P->Children[3]->Children[6]->Children[0]->Insert(4,"p1");
	P->Children[3]->Children[6]->Children[0]->Insert(3,"+");
	P->Children[3]->Children[6]->Children[0]->Children[1]->Insert(4,"p1");
	P->Children[3]->Children[6]->Children[0]->Children[1]->Insert(4,"1");

	P->Insert(5,"while");
	P->Children[4]->Insert(6,"WHILE");
	P->Children[4]->Insert(3,"==");
	P->Children[4]->Insert(6,"DO");
	P->Children[4]->Children[1]->Insert(4,"i");
	P->Children[4]->Children[1]->Insert(7,"6");
	P->Children[4]->Children[2]->Insert(3,":=");
	P->Children[4]->Children[2]->Insert(3,":=");
	P->Children[4]->Children[2]->Children[0]->Insert(4,"p");
	P->Children[4]->Children[2]->Children[0]->Insert(7,"1");
	P->Children[4]->Children[2]->Children[1]->Insert(4,"i");
	P->Children[4]->Children[2]->Children[1]->Insert(4,"p");

	P->Insert(5,"repeat");
	P->Children[5]->Insert(5,"REPEAT");
	P->Children[5]->Insert(5,"UNTIL");
	P->Children[5]->Children[0]->Insert(3,":=");
	P->Children[5]->Children[0]->Children[0]->Insert(4,"a");
	P->Children[5]->Children[0]->Children[0]->Insert(7,"6");
	P->Children[5]->Children[0]->Insert(3,":=");
	P->Children[5]->Children[0]->Children[1]->Insert(4,"c");
	P->Children[5]->Children[0]->Children[1]->Insert(7,"6");
	P->Children[5]->Children[1]->Insert(3,"==");
	P->Children[5]->Children[1]->Children[0]->Insert(4,"b");
	P->Children[5]->Children[1]->Children[0]->Insert(7,"3");

	P->Insert(5,"if");
	P->Children[6]->Insert(6,"IF");
	P->Children[6]->Insert(3,"GT");
	P->Children[6]->Insert(5,"Then");
	P->Children[6]->Insert(5,"else");
	P->Children[6]->Children[1]->Insert(4,"x");
	P->Children[6]->Children[1]->Insert(4,"y");
	P->Children[6]->Children[2]->Insert(3,":=");
	P->Children[6]->Children[2]->Insert(3,":=");
	P->Children[6]->Children[2]->Children[0]->Insert(4,"a");
	P->Children[6]->Children[2]->Children[0]->Insert(4,"b");
	P->Children[6]->Children[2]->Children[1]->Insert(4,"c");
	P->Children[6]->Children[2]->Children[1]->Insert(7,"1");
	P->Children[6]->Children[3]->Insert(3,":=");
	P->Children[6]->Children[3]->Children[0]->Insert(4,"q");
	P->Children[6]->Children[3]->Children[0]->Insert(7,"1");

	P->Insert(5,"switch");
	P->Children[7]->Insert(6,"SWITCH");
	P->Children[7]->Insert(4,"a");
	P->Children[7]->Insert(5,"of");
	P->Children[7]->Children[2]->Insert(5,"case");
	P->Children[7]->Children[2]->Children[0]->Insert(7,"1");
	P->Children[7]->Children[2]->Children[0]->Insert(3,":=");
	P->Children[7]->Children[2]->Children[0]->Children[1]->Insert(4,"b");
	P->Children[7]->Children[2]->Children[0]->Children[1]->Insert(7,"1");
	P->Children[7]->Children[2]->Insert(5,"case");
	P->Children[7]->Children[2]->Children[1]->Insert(7,"2");
	P->Children[7]->Children[2]->Children[1]->Insert(3,":=");
	P->Children[7]->Children[2]->Children[1]->Children[1]->Insert(4,"b");
	P->Children[7]->Children[2]->Children[1]->Children[1]->Insert(7,"2");

	P->Insert(5,":");
	P->Children[8]->Insert(7,"12345");
	P->Children[8]->Insert(3,":=");
	P->Children[8]->Children[1]->Insert(4,"a");
	P->Children[8]->Children[1]->Insert(7,"66");

	P->Insert(3,":=");
	P->Children[9]->Insert(5,".");
	P->Children[9]->Children[0]->Insert(4,"birth");
	P->Children[9]->Children[0]->Insert(4,"date");
	P->Children[9]->Insert(7,"1");

	Generate4 Gen1,Gen2;
	Gen1.VisitNode(P);
	Gen2.VisitNode(P);
	Gen2.Print();

 	return 0;
}*/
