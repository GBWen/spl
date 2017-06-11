#include "GS.h"

GS::GS(Generate4 &Gen, SymbolTable* st):g(Gen), current(st), floatNum(0), stringNum(0), paraNum(0)
{
	prepareStack();
	cout << "main: " << endl;
	cout << "or $fp, $sp, $0" << endl;
	cout << "addi $sp, $sp, -" << current->stackLength+4 << endl;

	vector<Code4*>::iterator itg;
	for (itg=g.Code.begin(); itg!=g.Code.end(); itg++)
	{
		//(*itg)->Table = (*(itg+1))->Table;
		if (itg+1!=g.Code.end())
			GenASM(*itg, *(itg+1));
		else
			GenASM(*itg, *itg);	
	}
}

int GS::getType(TreeNode *name)
{
	if (name->type == 8)
	{
		if (name->Children[0]->name == "integer")
			return INTEGER;
		if (name->Children[0]->name == "real")
			return REAL;
		if (name->Children[0]->name == "char")
			return CHAR;
		if (name->Children[0]->name == "boolean")
			return BOOLEAN;
		if (name->Children[0]->name == "array")
			return ARRAY;
		if (name->Children[0]->name == "record")
			return RECORD;
	}
}

int GS::TempToRegNum(string &Temp)
{
	int ti;
	stringstream ts;
	ts << Temp.substr(4);
	ts >> ti;
	return ti%16+10;
}

int GS::TempToFloatNum(string &Temp)
{
	int ti;
	stringstream ts;
	ts << Temp.substr(4);
	ts >> ti;
	return ti%15*2+2;
}

int GS::GenASM(Code4* Code, Code4* NCode)
{
	//cout << Code->Op << ", " << Code->Arg1 << ", " << Code->Arg2 << ", " << Code->Result << ", " << Code->Table << endl;
	current = Code->Table;
	//$9-$25: Tempn n%16+10
	//$v0 is return
	//$f2-30: Tempn n%15*2+2
	if (Code->Label)
	{
		//row_Code->Result:
		cout << "row_" << Code->Num << ":" << endl;
	}
	if (Code->Op == ":=" )
	{
		//Temp -> Temp
		//int -> Temp
		//real -> Temp
		//bool -> Temp
		//char -> Temp
		//decl -> Temp
		//Temp -> decl
		if (Code->Result.substr(0,4) == "Temp")
		{
			if (Code->Arg1 == "true")
			{
				cout << "li $" << TempToRegNum(Code->Result) << ", 1" << endl;
			}
			else if (Code->Arg1 == "false")
			{
				cout << "li $" << TempToRegNum(Code->Result) << ", 0" << endl;
			}
			else if ((Code->Arg1.at(0) >= '0' && Code->Arg1.at(0) <= '9') || Code->Arg1.at(0) == '-')
			{
				if (Code->Arg1.find('.') != string::npos )//real
				{
					float tf;
					stringstream ts;
					cout << ".data" << endl;
					cout << "floatNum" << ++floatNum << ":" << endl;
					ts << Code->Arg1;
					ts >> tf;
					cout << ".float " << tf << endl;
					cout << ".text" << endl;
					cout << "lwc1 $f" << TempToFloatNum(Code->Result) << ", " << "floatNum" << floatNum << endl;
				}
				else//int
				{
					int ti;
					stringstream ts;
					ts << Code->Arg1;
					ts >> ti;
					cout << "li $" << TempToRegNum(Code->Result) << ", " << ti << endl;
				}
			}
			else if (Code->Arg1.substr(0,4) == "Temp")//Temp -> Temp
			{
				cout << "or $" << TempToRegNum(Code->Result) << ", $0, $" << TempToRegNum(Code->Arg1) << endl;
			}
			else if  (Code->Arg1.at(0) == '\"')
			{
				cout << "ori $" << TempToRegNum(Code->Result) << ", $0, " << (short)(Code->Arg1.at(1)) << endl;
			}
			else if  (Code->Arg1.at(0) == '\'')
			{
				cout << ".data" << endl;
				cout << "string" << ++stringNum << ": .asciiz \"" << Code->Arg1.substr(1, Code->Arg1.length()-2) << "\"" << endl;
				cout << ".text" << endl;
				cout << "la $" << TempToRegNum(Code->Result) << ", string" << stringNum << endl;
			}
			else//decl -> Temp
			{
				int count = 0;
				TreeNode *tmp;
				tmp = current->lookupDecl(Code->Arg1, &count);
				if (tmp)
				{
					//cout << "count = " << count << endl;
					cout << "or $" << TempToRegNum(Code->Result) << ", $0, $fp" << endl;
					//lw $temp, 4($temp)
					for (int i=0; i<count; i++)
						cout << "lw $" << TempToRegNum(Code->Result) << ", 4($" << TempToRegNum(Code->Result) << ")" << endl;
					cout << "lw $" << TempToRegNum(Code->Result) << ", " << tmp->pos << "($" << TempToRegNum(Code->Result) << ")" << endl;
				}
				else
				{
					cout << "Error: No this decl -- " << Code->Arg1 << "(current = )" << current << endl;
					//current->printProc() ;
				}
			}
		}
		else//Temp -> decl
		{
			int count = 0;
			TreeNode *tmp;
			tmp = current->lookupDecl(Code->Result, &count);
			if (tmp)
			{
				if (getType(tmp) == REAL)
				{
					cout << "or $v1, $0, $fp" << endl;
					//lw $temp, 4($temp)
					for (int i=0; i<count; i++)
						cout << "lw $v1, 4($v1)" << endl;
					cout << "swc1 $f" << TempToFloatNum(Code->Result) << ", " << tmp->pos << "($v1)" << endl;
				}
				else
				{
					cout << "or $v1, $0, $fp" << endl;
					//lw $temp, 4($temp)
					for (int i=0; i<count; i++)
						cout << "lw $v1, 4($v1)" << endl;
					cout << "sw $" << TempToRegNum(Code->Arg1) << ", " << tmp->pos << "($v1)" << endl;
				}
			}
			else
			{
				cout << "Error: No this decl -- " << Code->Result << "(current = )" << current << endl;
			}
		}
	}
	if (Code->Op == "read")
	{
		/*int count = 0;
		*/
		/*TreeNode *tmp=current->lookupDecl(Code->Result);
		if (tmp)
		{
			switch (getType(tmp))
			{
			case INTEGER:*/
				cout << "li $v0, 5" << endl;
				cout << "syscall" << endl;
		/*		break;
			case REAL:
				cout << "li $v0, 6" << endl;
				cout << "syscall" << endl;
				break;
			}
			cout << "add $" << TempToRegNum(Code->Result) << ", $0, $v0" << endl;
		}
		else
		{
			cout << "Error: No this decl -- " << Code->Result << "(current = )" << current << endl;
			//current->printProc() ;
		}*/
	}
	if (Code->Op == "readln")
	{
		/*TreeNode *tmp=current->lookupDecl(Code->Result);
		if (tmp)
		{
			switch (getType(tmp))
			{
			case INTEGER:*/
				cout << "li $v0, 5" << endl;
				cout << "syscall" << endl;
		/*		break;
			case REAL:
				cout << "li $v0, 6" << endl;
				cout << "syscall" << endl;
				break;
			}
			cout << "add $" << TempToRegNum(Code->Result) << ", $0, $v0" << endl;
			cout << "li $v0, 8" << endl;
			cout << "syscall" << endl;
		}
		else
		{
			cout << "Error: No this decl -- " << Code->Result << "(current = )" << current << endl;
			//current->printProc() ;
		}*/
	}
	if (Code->Op == "write")
	{
		/*TreeNode *tmp=current->lookupDecl(Code->Result);
		if (tmp)
		{
			switch (getType(tmp))
			{
			case INTEGER:*/
		cout << "or $a0, $0, $" << TempToRegNum(Code->Result) << endl;
		cout << "li $v0, 1" << endl;
		cout << "syscall" << endl;
		/*		break;
			case REAL:
				cout << "or $f12, $0, $" << TempToRegNum(Code->Result) << endl;
				cout << "li $v0, 2" << endl;
				cout << "syscall" << endl;
				break;
			}
		}
		else
		{
			cout << "Error: No this decl -- " << Code->Result << "(current = )" << current << endl;
			//current->printProc() ;
		}*/
	}
	if (Code->Op == "writeln")
	{
		cout << ".data" << endl;
		cout << "string" << ++stringNum << ": .asciiz \"\\n\"" << endl;
		cout << ".text" << endl;
		cout << "li $v0, 4" << endl;
		cout << "la $a0, string" << stringNum << endl;
		cout << "syscall" << endl;
		/*TreeNode *tmp=current->lookupDecl(Code->Result);
		if (tmp)
		{
			switch (getType(tmp))
			{
			case INTEGER:
				cout << "or $a0, $0, $" << TempToRegNum(Code->Result) << endl;
				cout << "li $v0, 1" << endl;
				cout << "syscall" << endl;
				break;
			case REAL:
				cout << "or $f12, $0, $" << TempToRegNum(Code->Result) << endl;
				cout << "li $v0, 2" << endl;
				cout << "syscall" << endl;
				break;
			}
		}
		else
		{
			cout << "Error: No this decl -- " << Code->Result << "(current = )" << current << endl;
			//current->printProc() ;
		}*/
	}
	if (Code->Op == "+")
	{
		if (Code->Arg2 == "")
		{
			/*TreeNode *tmp=current->lookupDecl(Code->Result);
			if (tmp)
			{
				switch (getType(tmp))
				{
				case REAL:
					cout << "add.s $" << TempToRegNum(Code->Result) << ", $f31, $" << TempToRegNum(Code->Arg1) << endl;
					break;
				default:*/
					cout << "add $" << TempToRegNum(Code->Result) << ", $0, $" << TempToRegNum(Code->Arg1) << endl;
			/*		break;
				}
			}
			else
			{
				cout << "Error: No this decl -- " << Code->Result << "(current = )" << current << endl;
				//current->printProc() ;
			}*/
		}
		else if (Code->Arg2[0] >= '0' && Code->Arg2[0] <= '9')
		{
			cout << "addi $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", " << Code->Arg2 << endl;
		}
		else
		{
			/*TreeNode *tmp=current->lookupDecl(Code->Result);
			if (tmp)
			{
				switch (getType(tmp))
				{
				case REAL:
					cout << "add.s $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
					break;
				default:*/
					cout << "add $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
			/*		break;
				}
			}
			else
			{
				cout << "Error: No this decl -- " << Code->Result << "(current = )" << current << endl;
				//current->printProc() ;
			}*/
		}
	}
	if (Code->Op == "-")
	{
		if (Code->Arg2 == "")
		{
			/*TreeNode *tmp=current->lookupDecl(Code->Result);
			if (tmp)
			{
				switch (getType(tmp))
				{
				case REAL:
					cout << "sub.s $" << TempToRegNum(Code->Result) << ", $f31, $" << TempToRegNum(Code->Arg1) << endl;
					break;
				default:*/
					cout << "sub $" << TempToRegNum(Code->Result) << ", $0, $" << TempToRegNum(Code->Arg1) << endl;
			/*		break;
				}
			}
			else
			{
				cout << "Error: No this decl -- " << Code->Result << "(current = )" << current << endl;
				//current->printProc() ;
			}*/
		}
		else if (Code->Arg2[0] >= '0' && Code->Arg2[0] <= '9')
		{
			cout << "subi $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", " << Code->Arg2 << endl;
		}
		else
		{
			/*TreeNode *tmp=current->lookupDecl(Code->Result);
			if (tmp)
			{
				switch (getType(tmp))
				{
				case REAL:
					cout << "sub.s $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
					break;
				default:*/
					cout << "sub $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
			/*		break;
				}
			}
			else
			{
				cout << "Error: No this decl -- " << Code->Result << "(current = )" << current << endl;
				//current->printProc() ;
			}*/
		}
	}
	if (Code->Op == "*")
	{
		/*TreeNode *tmp=current->lookupDecl(Code->Result);
		if (tmp)
		{
			switch (getType(tmp))
			{
			case REAL:
				cout << "mul.s $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
				break;
			default:*/
				cout << "mul $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
		/*		break;
			}
		}
		else
		{
			cout << "Error: No this decl -- " << Code->Result << "(current = )" << current << endl;
			//current->printProc() ;
		}*/
	}
	if (Code->Op == "div")
	{
		cout << "div $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == "mod")
	{
		cout << "rem $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == "not")
	{
		cout << "not $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << endl;
	}
	if (Code->Op == "and")
	{
		cout << "and $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == "or")
	{
		cout << "or $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == "xor")
	{
		cout << "xor $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == "label")
	{
		//label_Code->Result:
		cout << "label_" << Code->Result << ":" << endl;
	}
	if (Code->Op == "goto")
	{
		//j label_Code->Result
		cout << "j label_" << Code->Result << endl;
	}
	if (Code->Op == "=")
	{
		cout << "seq $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == "<>")
	{
		cout << "sne $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == "<")
	{
		cout << "slt $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == "<=")
	{
		cout << "sle $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == ">")
	{
		cout << "sgt $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == ">=")
	{
		cout << "sge $" << TempToRegNum(Code->Result) << ", $" << TempToRegNum(Code->Arg1) << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == "jnz")
	{
		//bne $0, $arg1, row_result
		cout << "bne $0, $" << TempToRegNum(Code->Arg1) << ", row_" << Code->Result << endl;
	}
	if (Code->Op == "jz")
	{
		//beq $0, $arg1, row_result
		cout << "beq $0, $" << TempToRegNum(Code->Arg1) << ", row_" << Code->Result << endl;
	}
	if (Code->Op == "j")
	{
		cout << "j row_" << Code->Result << endl;
	}
	if (Code->Op == "para")
	{
		paraNum++;
		//addi $sp, $sp, -4
		//sw $result, 0($sp)
		cout << "addi $sp, $sp, -4" << endl;
		cout << "sw $" << TempToRegNum(Code->Result) << ", 0($sp)" << endl;
	}
	if (Code->Op == "call")
	{
		int count = 0;
		
		if (current->lookupProc(Code->Result, &count))
		{
			cout << "or $v0, $0, $fp" << endl;
			for (int i=0; i<count; i++)
			{
				cout << "lw $v0, 4($v0)" << endl;
			}
			cout << "addi $sp, $sp, -4" << endl;
			cout << "sw $v0, 0($sp)" << endl;
			cout << "addi $sp, $sp, -4" << endl;
			cout << "sw $fp, 0($sp)" << endl;

			cout << "add $fp, $sp, $0" << endl;
			cout << "jal " << Code->Result << endl;
			
			cout << "lw $fp, 0($fp)" << endl;
			cout << "addi $sp, $sp, " << 8 + 4*paraNum << endl;
		}
		else
		{
			cout << "Error: No this function -- " << Code->Result << endl;
			cout << current << endl;
		}
		paraNum = 0;
	}
	if (Code->Op == "return")
	{
		//add $result, $v0, $0
		cout << "add $" << TempToRegNum(Code->Result)<< ", $v0, $0" << endl;
	}
	if (Code->Op == "shl")
	{
		//Result = arg1 << arg2
		//sllv $1,$2,$3
		//$1=$2<<$3
		cout << "sllv $" << TempToRegNum(Code->Result);
		cout << ", $" << TempToRegNum(Code->Arg1);
		cout << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == "shr")
	{
		//Result = arg1 << arg2
		cout << "srav $" << TempToRegNum(Code->Result);
		cout << ", $" << TempToRegNum(Code->Arg1);
		cout << ", $" << TempToRegNum(Code->Arg2) << endl;
	}
	if (Code->Op == "end")
	{
		cout << "li	$v0, 10" << endl;
		cout << "syscall" << endl;
	}
	if (Code->Op == "proc")
	{
		cout << Code->Result << ":" << endl;
		cout << "addi $sp, $sp, -4" << endl;
		cout << "sw $31, 0($sp)" << endl;
		//current = (Code+1)->Table;
		//current->printProc();
		current = NCode->Table;
		prepareStack();//manage stack
		cout << "addi $sp, $sp, -" << current->stackLength << endl;
		//cout << "current: " << NCode->Table << endl;
		//cout << "current->stackLength: " << NCode->Table->stackLength << endl;
	}
	if (Code->Op == "exit")
	{
		if (Code->Result != "")
		{
			// add $v0, $0, $Code-Result
			cout << "add $v0, $0, $" << TempToRegNum(Code->Result) << endl;
		}
		cout << "addi $sp, $sp, " << NCode->Table->stackLength << endl;
		//cout << "current: " << NCode->Table << endl;
		//cout << "current->stackLength: " << NCode->Table->stackLength << endl;
		//pop all args
		cout << "lw $31, 0($sp)" << endl;
		cout << "addi $sp, $sp, 4" << endl;

		cout << "jr $31" << endl;
		current = programTable;
	}
}

void GS::prepareStack()
{
	int total = 0;
	for (int i=0; i<current->parameters.size(); i++)
	{
		if (current->parameters[i]->type->type == 8)
		{
			if (current->parameters[i]->type->Children[0]->name == "integer")
			{
				total+=4;
			}
			if (current->parameters[i]->type->Children[0]->name == "real")
			{
				total+=4;
			}
			if (current->parameters[i]->type->Children[0]->name == "char")
			{
				total+=4;
			}
			if (current->parameters[i]->type->Children[0]->name == "boolean")
			{
				total+=4;
			}
			if (current->parameters[i]->type->Children[0]->name == "string")
			{
				total+=4;
			}
		}
	}
	total+=8;
	for (int i=0; i<current->parameters.size(); i++)
	{
		if (current->parameters[i]->type->type == 8)
		{
			if (current->parameters[i]->type->Children[0]->name == "integer")
			{
				total-=4;
				current->parameters[i]->type->pos = total;
			}
			if (current->parameters[i]->type->Children[0]->name == "real")
			{
				total-=4;
				current->parameters[i]->type->pos = total;
			}
			if (current->parameters[i]->type->Children[0]->name == "char")
			{
				total-=4;
				current->parameters[i]->type->pos = total;
			}
			if (current->parameters[i]->type->Children[0]->name == "boolean")
			{
				total-=4;
				current->parameters[i]->type->pos = total;
			}
			if (current->parameters[i]->type->Children[0]->name == "string")
			{
				total-=4;
				current->parameters[i]->type->pos = total;
			}
		}
	}

	map<string, TreeNode*>::iterator it;
	total = -4;
	int i = 0;
	for (it = current->decl.begin(); it != current->decl.end(); it++, i++){
		if (it->second->type == 8)
		{
			if (it->second->Children[0]->name == "integer")
			{
				total-=4;
			}
			if (it->second->Children[0]->name == "real")
			{
				total-=4;
			}
			if (it->second->Children[0]->name == "char")
			{
				total-=4;
			}
			if (it->second->Children[0]->name == "boolean")
			{
				total-=4;
			}
			if (it->second->Children[0]->name == "string")
			{
				total-=4;
			}
		}
	}
	current->stackLength = -total-4;
	for (it = current->decl.begin(); it != current->decl.end(); it++, i++){
		if (it->second->type == 8)
		{
			if (it->second->Children[0]->name == "integer")
			{
				it->second->pos = total;
				total+=4;
			}
			if (it->second->Children[0]->name == "real")
			{
				it->second->pos = total;
				total+=4;
			}
			if (it->second->Children[0]->name == "char")
			{
				it->second->pos = total;
				total+=4;
			}
			if (it->second->Children[0]->name == "boolean")
			{
				it->second->pos = total;
				total+=4;
			}
			if (it->second->Children[0]->name == "string")
			{
				it->second->pos = total;
				total+=4;
			}
		}
	}
}
