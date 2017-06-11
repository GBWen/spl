#include "SymbolTable.hpp"
#include <stdio.h>
#include <assert.h>
using namespace std;

void printTab(int times){
	if (times < 0) times = 0;
	for (int i=0; i<times; i++){
		printf("\t");
	}
}

TreeNode::TreeNode(ValueNode* val, int type){
	assert(val != NULL);
	this->type = type;
	this->name = val->name;
	this->val = val;
	if (type == -1){
		if (val->type == VT_NAME){
			this->type = VariableNode;
		}else if (val->type == VT_TOKEN){
			this->type = TokenNode;
		}else{
			this->type = ValNode;
		}
	}
	Children.clear();
}

TreeNode::TreeNode(int type) : type(type){
	this->name = "";
	this->val = NULL;
	Children.clear();
}

TreeNode::TreeNode(const TreeNode& node){
	this->name = node.name;
	this->val = node.val;
	this->pos = node.pos;
	this->type = node.type;
	Children.clear();
	this->insertChild(node);
}

void TreeNode::insert(TreeNode* node){
    Children.push_back(node);
}

void TreeNode::insertChild(TreeNode* node){
	insertChild(*node);
}

void TreeNode::insertChild(const TreeNode& node){
	for (int i=0; i<node.Children.size(); i++){
    	Children.push_back(node.Children[i]);
	}
}

void TreeNode::print(int type, int level){
	if (name.size() > 0){
		printTab(level);
		printf("%s\n", name.c_str());
	}
	for (int i=0; i<Children.size(); i++){
		assert(Children[i] != NULL);
		if (type >= 2){
			printTab(level);
			printf("%d >> %s\n", i, name.c_str());
		}
		Children[i]->print(type, level+1);
		if (type >= 2){
			printTab(level);
			printf("%d << %s\n", i, name.c_str());
		}
	}
}




SymbolTable::SymbolTable(SymbolTable* fa):father(fa){
	Children.clear();
}

bool SymbolTable::insertDecl(string name, TreeNode* node){
	//printf("Insert Decl : %s\n", name.c_str());
	//node->print(0, 0);
	decl[name] = new TreeNode(*node);
}

TreeNode* SymbolTable::lookupDecl(string name, int* count){
	SymbolTable *tmp = this;
	if (count != NULL)
		*count = 0;
	while (tmp != NULL){
		map<string, TreeNode*>::iterator it;
		it = tmp->decl.find(name);
		if (it != tmp->decl.end()){
			return it->second;
		}
		if (count != NULL)
			(*count)++;
		tmp = tmp->father;
	}
	return NULL;
}

bool SymbolTable::insertProc(string name, SymbolTable* node){
	Children.push_back(node);
	proc[name] = node;
}

SymbolTable* SymbolTable::lookupProc(string name, int* count){
	SymbolTable *tmp = this;
	if (count != NULL)
		*count = 0;
	while (tmp != NULL){
		map<string, SymbolTable*>::iterator it;
		it = tmp->proc.find(name);
		if (it != tmp->proc.end()){
			return it->second;
		}
		if (count != NULL)
			(*count)++;
		tmp = tmp->father;
	}
	return NULL;
}
void SymbolTable::insertParameter(string name, bool reference, TreeNode* type){
	parameters.push_back(new Parameter(name, reference, type));
	insertDecl(name, type);
}

void SymbolTable::print(int type, int level){
	printTab(level);
	printf("Sub-program number %zu\n", Children.size());

	if (type >= 1){
		printTab(level);
		printf("-----print Header-----\n");
	}
	self->Children[0]->print(type, level);

	if (type >= 1){
		printTab(level);
		printf("-----print Decl-----\n");
	}
	printDecl(type, level);

	if (type >= 1){
		printTab(level);
		printf("-----print Proc-----\n");
	}
	printProc(type, level);

	if (type >= 1){
		printTab(level);
		printf("-----print Param-----\n");
	}
	printParam(type, level);

	if (type >= 1){
		printTab(level);
		printf("-----print Block-----\n");
	}
	printBlock(type, level);

	if (type >= 1){
		printTab(level);
		printf("-----end Block-----\n");
	}
	//self->print(type, level);
	// for (int i=0; i< Children.size(); i++){
	// 	Children[i]->print(type, level+1);
	// }
}

void SymbolTable::printDecl(int type, int level){
	map<string, TreeNode*>::iterator it;
	for (it = decl.begin(); it != decl.end(); it++){
		printTab(level);
		printf("Decl : %s %p\n", it->first.c_str(), it->second);
		it->second->print(type, level);
	}
}

void SymbolTable::printProc(int type, int level){
	map<string, SymbolTable*>::iterator it;
	for (it = proc.begin(); it != proc.end(); it++){
		printTab(level);
		printf("Proc : %s\n", it->first.c_str());
		it->second->print(type, level+1);
	}
}

void SymbolTable::printParam(int type, int level){
	for (int i=0; i<parameters.size(); i++){
		printTab(level);
		printf("name: %s reference: %d\n", parameters[i]->name.c_str(), parameters[i]->reference);
		parameters[i]->type->print(type, level);
	}
}

void SymbolTable::printBlock(int type, int level){
	// root -> routine -> routine_body
	// self->Children[1]->Children[1]->print(type, level);
	if (this == programTable){
		self->Children[1]->Children[1]->print(type, level);
	}else{
		self->Children[2]->Children[1]->print(type, level);
	}
}
