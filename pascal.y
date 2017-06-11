%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sstream>
#include <assert.h>
#include "SymbolTable.hpp"
#include "G4.h"
#include "GS.h"
using namespace std;

SymbolTable* programTable = new SymbolTable(NULL);
SymbolTable* current = programTable;

int errorCount = 0;

%}

%union {
	ValueNode* value;
    TreeNode* tree;
}

%token<value> TOK_LP TOK_RP TOK_LB TOK_RB TOK_DOT TOK_COMMA TOK_SEMI TOK_COLON

%token<value> TOK_MUL TOK_DIV TOK_PLUS TOK_MINUS

%token<value> TOK_GE TOK_GT TOK_LE TOK_LT TOK_EQUAL TOK_UNEQUAL TOK_ASSIGN

%token<value> TOK_PROGRAM TOK_PROCEDURE TOK_FUNCTION TOK_EXIT

%token<value> TOK_LABEL TOK_CONST TOK_TYPE TOK_VAR TOK_ARRAY TOK_RECORD

%token<value> TOK_INTEGER TOK_REAL TOK_CHAR TOK_STRING TOK_BOOLEAN

%token<value> TOK_BEGIN TOK_END

%token<value> TOK_IF TOK_THEN TOK_ELSE

%token<value> TOK_FOR TOK_TO TOK_DOWNTO TOK_DO

%token<value> TOK_CASE TOK_OF

%token<value> TOK_WHILE TOK_REPEAT TOK_UNTIL

%token<value> TOK_GOTO

%token<value> TOK_OR TOK_AND TOK_XOR TOK_NOT TOK_MOD TOK_SHL TOK_SHR

%token<value> TOK_WRITELN TOK_WRITE

%token<value> TOK_MAXINT

%token<value> TOK_READ TOK_READLN

%token<value> TOK_ABS TOK_CHR TOK_ODD TOK_ORD TOK_PRED TOK_SQR TOK_SQRT TOK_SUCC

%token<value> NAME CONST_INTEGER CONST_REAL CONST_CHAR CONST_STRING CONST_BOOLEAN

// ------------ ^ token node   v tree node

%type<tree> program program_head routine sub_routine routine_head routine_body

%type<tree> label_part label_list single_label

%type<tree> const_part const_expr_list const_expr const_value SYS_CON

%type<tree> type_part type_decl_list type_definition type_decl

%type<tree> simple_type_decl name_list SYS_TYPE

%type<tree> array_type_decl

%type<tree> record_type_decl field_decl_list field_decl

%type<tree> var_part var_decl_list var_decl

%type<tree> routine_part

%type<tree> function_decl function_head

%type<tree> procedure_decl procedure_head

%type<tree> parameters para_decl_list para_type_list var_para_list val_para_list

%type<tree> compound_stmt stmt_list stmt non_label_stmt

%type<tree> assign_stmt

%type<tree> proc_stmt SYS_PROC

%type<tree> if_stmt else_clause

%type<tree> repeat_stmt

%type<tree> while_stmt

%type<tree> for_stmt direction

%type<tree> case_stmt case_expr_list case_expr

%type<tree> goto_stmt

%type<tree> expression expression_list args_list expr term factor SYS_FUNCT

%type<tree> error

%%

program :
    program_head routine TOK_DOT {
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
        $$->insert($2);
        $$->insert(new TreeNode($3));
        current->self = $$;
    }
    ;

program_head :
    TOK_PROGRAM NAME TOK_SEMI {
        $$ = new TreeNode(ProgrameNode);
        $$->insert(new TreeNode($1));
        $$->insert(new TreeNode($2));
        $$->insert(new TreeNode($3));
    }
	| error {

	} TOK_SEMI {
		$$ = NULL;
	}
    ;

routine :
    routine_head routine_body {
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
        $$->insert($2);
    }
    ;

sub_routine :
    routine_head routine_body {
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
        $$->insert($2);
    }
    ;

routine_head :
    label_part const_part type_part var_part routine_part {
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
        $$->insert($2);
        $$->insert($3);
        $$->insert($4);
        $$->insert($5);
    }
    ;

label_part :
    label_list {
        $$ = new TreeNode(TypeNode);
        $$->insert($1);
    }
    | {
        $$ = new TreeNode(TypeNode);
    }
    ;

label_list :
    label_list single_label {
        $$ = $1;
        $$->insert($2);
    }
    | single_label {
        $$ = new TreeNode(TypeNode);
        $$->insert($1);
    }
    ;

single_label :
    TOK_LABEL CONST_INTEGER TOK_SEMI {
        // add label to decl
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
        $$->insert(new TreeNode($2));
        $$->insert(new TreeNode($3));
        current->insertDecl($2->name, $$);
    }
	| error {
		//yyerror("Label declaration error.");
	} TOK_SEMI {
		$$ = NULL;
	}
    ;

const_part :
    TOK_CONST const_expr_list {
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
        $$->insert($2);
    }
    | {
        $$ = new TreeNode(TypeNode);
    }
    ;

const_expr_list :
    const_expr_list const_expr {
        $$ = $1;
        $$->insert($2);
    }
    | const_expr {
        $$ = new TreeNode(TypeNode);
        $$->insert($1);
    }
    ;

const_expr :
    NAME TOK_EQUAL const_value TOK_SEMI {
        // add const to decl
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
        current->insertDecl($1->name, $3);
    }
	| error {
		//yyerror("Const declaration error.");
	} TOK_SEMI {
		$$ = NULL;
	}
    ;

const_value :
    CONST_INTEGER {
        $$ = new TreeNode($1);
    }
    | CONST_REAL{
        $$ = new TreeNode($1);
    }
    | CONST_CHAR {
        $$ = new TreeNode($1);
    }
    | CONST_STRING {
        $$ = new TreeNode($1);
    }
    | SYS_CON {
        $$ = $1;
    }
    ;

SYS_CON :
    TOK_MAXINT {
        $$ = new TreeNode($1, ValNode);
    }
    | CONST_BOOLEAN {
        $$ = new TreeNode($1);
    }
    ;

type_part :
    TOK_TYPE type_decl_list {
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
        $$->insert($2);
    }
    | {
        $$ = new TreeNode(TypeNode);
    }
    ;

type_decl_list :
    type_decl_list type_definition {
        $$ = $1;
        $$->insert($2);
    }
    | type_definition {
        $$ = new TreeNode(TypeNode);
        $$->insert($1);
    }
    ;

type_definition :
    NAME TOK_EQUAL type_decl TOK_SEMI {
        // add type to decl
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
        current->insertDecl($1->name, $3);
    }
	| error {
		//yyerror("Type declaration error.");
	} TOK_SEMI {
		$$ = NULL;
	}
    ;

type_decl :
    simple_type_decl {
        $$ = $1;
    }
    | array_type_decl {
        $$ = $1;
    }
    | record_type_decl {
        $$ = $1;
    }
    ;

simple_type_decl :
    SYS_TYPE {
        $$ = new TreeNode(TypeNode);
        $$->insert($1);
    }
    | NAME {
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
    }
    | TOK_LP name_list TOK_RP {
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
        $$->insert($2);
        $$->insert(new TreeNode($3));
    }
    | const_value TOK_DOT TOK_DOT const_value {
        $$ = new TreeNode(TypeNode);
        $$->insert($1);
        $$->insert(new TreeNode($2));
        $$->insert(new TreeNode($3));
        $$->insert($4);
    }
    | TOK_MINUS const_value TOK_DOT TOK_DOT const_value {
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
        $$->insert($2);
        $$->insert(new TreeNode($3));
        $$->insert(new TreeNode($4));
        $$->insert($5);
    }
    | TOK_MINUS const_value TOK_DOT TOK_DOT TOK_MINUS const_value {
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
        $$->insert($2);
        $$->insert(new TreeNode($3));
        $$->insert(new TreeNode($4));
        $$->insert(new TreeNode($5));
        $$->insert($6);
    }
    | NAME TOK_DOT TOK_DOT NAME {
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
        $$->insert(new TreeNode($2));
        $$->insert(new TreeNode($3));
        $$->insert(new TreeNode($4));
    }
    ;

SYS_TYPE :
    TOK_BOOLEAN {
        $$ = new TreeNode($1);
    }
    | TOK_CHAR {
        $$ = new TreeNode($1);
    }
    | TOK_INTEGER {
        $$ = new TreeNode($1);
    }
    | TOK_REAL {
        $$ = new TreeNode($1);
    }
    | TOK_STRING {
        $$ = new TreeNode($1);
    }
    ;

array_type_decl :
    TOK_ARRAY TOK_LB simple_type_decl TOK_RB TOK_OF type_decl {
        $$ = new TreeNode(ProgrameNode);
        $$->insert(new TreeNode($1));
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
        $$->insert(new TreeNode($5));
        $$->insert($6);
    }
    ;

record_type_decl :
    TOK_RECORD field_decl_list TOK_END {
        $$ = new TreeNode(ProgrameNode);
        $$->insert(new TreeNode($1));
        $$->insert($2);
        $$->insert(new TreeNode($3));
    }
    ;

field_decl_list :
    field_decl_list field_decl {
        $$ = $1;
        $$->insert($2);
    }
    | field_decl {
        $$ = new TreeNode(TypeNode);
        $$->insert($1);
    }
    ;

field_decl :
    name_list TOK_COLON type_decl TOK_SEMI {
        $$ = new TreeNode(TypeNode);
        $$->insert($1);
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
    }
	| error {
		//yyerror("Record declaration error.");
	} TOK_SEMI {
		$$ = NULL;
	}
    ;

name_list :
    name_list TOK_COMMA NAME {
        $$ = $1;
        $$->insert(new TreeNode($3));
    }
    | NAME {
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
    }
    ;

var_part :
    TOK_VAR var_decl_list {
        $$ = new TreeNode(TypeNode);
        $$->insert(new TreeNode($1));
        $$->insert($2);
    }
    | {
        $$ = new TreeNode(TypeNode);
    }
    ;

var_decl_list :
    var_decl_list var_decl {
        $$ = $1;
        $$->insert($2);
    }
    | var_decl {
        $$ = new TreeNode(TypeNode);
        $$->insert($1);
    }
    ;

var_decl :
    name_list TOK_COLON type_decl TOK_SEMI {
        // add var to decl
        $$ = new TreeNode(TypeNode);
        $$->insert($1);
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
        for (int i=0; i< $1->Children.size(); i++){
            TreeNode *name = $1->Children[i];
            current->insertDecl(name->name, $3);
        }
    }
	| error {
		//yyerror("Variable declaration error.");
	} TOK_SEMI {
		$$ = NULL;
	}
    ;

routine_part :
    routine_part function_decl {
        $$ = $1;
        $$->insert($2);
    }
    | routine_part procedure_decl {
        $$ = $1;
        $$->insert($2);
    }
    | function_decl {
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
    }
    | procedure_decl {
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
    }
    | {
        $$ = new TreeNode(ProgrameNode);
    }
	| routine_part error {
		$$ = $1;
		//yyerror("Procedure / Function declaration error.");
	}
    ;

function_decl :
    function_head TOK_SEMI sub_routine TOK_SEMI {
        // change the SymbolTable to sub-program
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
        current->self = $$;
        current = current->father;
    }
    ;

function_head :
    TOK_FUNCTION NAME {
        // add the function to father's SymbolTable
        SymbolTable* tmp = new SymbolTable(current);
        current->insertProc($2->name, tmp);
        current = tmp;
    } parameters TOK_COLON simple_type_decl {
        $$ = new TreeNode(ProgrameNode);
        $$->insert(new TreeNode($1));
        $$->insert(new TreeNode($2));
        $$->insert($4);
        $$->insert(new TreeNode($5));
        $$->insert($6);
    }
    ;

procedure_decl :
    procedure_head TOK_SEMI sub_routine TOK_SEMI {
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
        current->self = $$;
        current = current->father;
    }
    ;

procedure_head :
    TOK_PROCEDURE NAME {
        SymbolTable* tmp = new SymbolTable(current);
        current->insertProc($2->name, tmp);
        current = tmp;
    } parameters {
        $$ = new TreeNode(ProgrameNode);
        $$->insert(new TreeNode($1));
        $$->insert(new TreeNode($2));
        $$->insert($4);
    }
    ;

parameters :
    TOK_LP para_decl_list TOK_RP {
        $$ = new TreeNode(ProgrameNode);
        $$->insert(new TreeNode($1));
        $$->insert($2);
        $$->insert(new TreeNode($3));
    }
    | {
        $$ = new TreeNode(ProgrameNode);
    }
    ;

para_decl_list :
    para_decl_list TOK_SEMI para_type_list {
        $$ = $1;
        $$->insert($3);
    }
    | para_type_list {
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
    }
	| para_decl_list TOK_SEMI error {
		$$ = $1;
		//yyerror("Parameter declaration error.");
	}
    ;

para_type_list :
    var_para_list TOK_COLON simple_type_decl {
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
        $$->insert(new TreeNode($2));
        $$->insert($3);
		TreeNode* tmp = $1->Children[1];
		for (int i=0; i<tmp->Children.size(); i++){
			current->insertParameter(tmp->Children[i]->name, 1, $3);
		}
    }
    | val_para_list TOK_COLON simple_type_decl {
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
        $$->insert(new TreeNode($2));
        $$->insert($3);
		TreeNode* tmp = $1->Children[0];
		for (int i=0; i<tmp->Children.size(); i++){
			current->insertParameter(tmp->Children[i]->name, 0, $3);
		}
    }
    ;

var_para_list :
    TOK_VAR name_list {
        $$ = new TreeNode(ProgrameNode);
        $$->insert(new TreeNode($1));
        $$->insert($2);
    }
    ;

val_para_list :
    name_list {
        $$ = new TreeNode(ProgrameNode);
        $$->insert($1);
    }
    ;

routine_body :
    compound_stmt {
        $$ = $1;
    }
    ;

compound_stmt :
    TOK_BEGIN stmt_list TOK_END {
        $$ = $2;
    }
    ;

stmt_list :
    stmt_list stmt TOK_SEMI {
        $$ = $1;
        $$->insert($2);
    }
    | {
        $$ = new TreeNode(ProgrameNode);
    }
    ;

stmt :
    CONST_INTEGER TOK_COLON non_label_stmt {
        $$ = new TreeNode($2, StatementNode);
        $$->insert(new TreeNode($1));
        $$->insert($3);
    }
    | non_label_stmt {
        $$ = $1;
    }
    ;

non_label_stmt :
    assign_stmt {
        $$ = $1;
    }
    | proc_stmt {
        $$ = $1;
    }
    | compound_stmt {
        $$ = $1;
    }
    | if_stmt {
        $$ = $1;
    }
    | repeat_stmt {
        $$ = $1;
    }
    | while_stmt {
        $$ = $1;
    }
    | for_stmt {
        $$ = $1;
    }
    | case_stmt {
        $$ = $1;
    }
    | goto_stmt {
        $$ = $1;
    }
	| error {
		$$ = NULL;
		//yyerror("Statement Error.");
	}
    ;

assign_stmt :
    NAME TOK_ASSIGN expression {
        $$ = new TreeNode($2, ExpressionNode);
        $$->insert(new TreeNode($1));
        $$->insert($3);
    }
    | NAME TOK_LB expression_list TOK_RB TOK_ASSIGN expression {
        $$ = new TreeNode($5, ExpressionNode);
		TreeNode *name = new TreeNode($1);
        name->insert(new TreeNode($2));
        name->insertChild($3);
        name->insert(new TreeNode($4));
        $$->insert(name);
        $$->insert($6);

    }
    | NAME TOK_DOT NAME TOK_ASSIGN expression {
        $$ = new TreeNode($4, ExpressionNode);
		TreeNode *dot = new TreeNode($2, StatementNode);
		dot->insert(new TreeNode($1));
		dot->insert(new TreeNode($3));
		$$->insert(dot);
        $$->insert($5);
    }
    ;

proc_stmt :
    NAME {
        $$ = new TreeNode($1, ProcedureNode);
    }
    | NAME TOK_LP args_list TOK_RP {
        $$ = new TreeNode($1, ProcedureNode);
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
    }
    | SYS_PROC {
        $$ = $1;
    }
    | SYS_PROC TOK_LP args_list TOK_RP {
        $$ = $1;
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
    }
    | TOK_READ TOK_LP factor TOK_RP {
        $$ = new TreeNode($1, StatementNode);
        $$->insert(new TreeNode($2));
		TreeNode* args = new TreeNode(StatementNode);
		args->insert($3);
        $$->insert(args);
        $$->insert(new TreeNode($4));
    }
	| TOK_EXIT {
        $$ = new TreeNode($1, StatementNode);
	}
    | TOK_EXIT TOK_LP factor TOK_RP {
        $$ = new TreeNode($1, StatementNode);
        $$->insert($3);
    }
    ;

SYS_PROC :
    TOK_WRITE {
        $$ = new TreeNode($1, StatementNode);
    }
    | TOK_WRITELN {
        $$ = new TreeNode($1, StatementNode);
    }
    ;

if_stmt :
    TOK_IF expression TOK_THEN stmt else_clause {
        $$ = new TreeNode($1, StatementNode);
		$$->insert(new TreeNode($1));
        $$->insert($2);
		TreeNode *then = new TreeNode($3);
		then->insert($4);
		$$->insert(then);
		if ($5 != NULL)
			$$->insert($5);
    }
    ;

else_clause :
    TOK_ELSE stmt {
        $$ = new TreeNode($1, StatementNode);
        $$->insert($2);
    }
    | {
        $$ = NULL;
    }
    ;

repeat_stmt :
    TOK_REPEAT stmt_list TOK_UNTIL expression {
        $$ = new TreeNode($1, StatementNode);
		TreeNode *repeat = new TreeNode($1);
		repeat->insert($2);
        $$->insert(repeat);
		TreeNode *until = new TreeNode($3);
		until->insert($4);
        $$->insert(until);
    }
    ;

while_stmt :
    TOK_WHILE expression TOK_DO stmt {
        $$ = new TreeNode($1, StatementNode);
		$$->insert(new TreeNode($1));
        $$->insert($2);
		TreeNode *tok_do = new TreeNode($3);
		tok_do->insert($4);
        $$->insert(tok_do);
    }
    ;

for_stmt :
    TOK_FOR NAME TOK_ASSIGN expression direction expression TOK_DO stmt {
        $$ = new TreeNode($1, StatementNode);
		$$->insert(new TreeNode($1));
        $$->insert(new TreeNode($2));
        $$->insert(new TreeNode($3));
        $$->insert($4);
        $$->insert($5);
        $$->insert($6);
		TreeNode *tok_do = new TreeNode($7);
		tok_do->insert($8);
        $$->insert(tok_do);
    }
    ;

direction :
    TOK_TO {
        $$ = new TreeNode($1);
    }
    | TOK_DOWNTO {
        $$ = new TreeNode($1);
    }
    ;

case_stmt :
    TOK_CASE expression TOK_OF case_expr_list TOK_END {
        $$ = new TreeNode($1, StatementNode);
		$$->insert(new TreeNode($1));
		TreeNode *of = new TreeNode($3);
		of->insert($4);
		$$->insert($2);
        $$->insert(of);
    }
    ;

case_expr_list :
    case_expr_list case_expr {
        $$ = $1;
        $$->insert($2);
    }
    | case_expr {
        $$ = new TreeNode(StatementNode);
        $$->insert($1);
    }
    ;

case_expr :
    const_value TOK_COLON stmt TOK_SEMI {
        $$ = new TreeNode($2);
		// to make the $$->name to be case:
		$$->name = "case" + $$->name;
        $$->insert($1);
		$$->insert($3);
    }
    | NAME TOK_COLON stmt TOK_SEMI {
        $$ = new TreeNode($2);
		$$->name = "case" + $$->name;
		$$->insert(new TreeNode($1));
		$$->insert($3);
    }
	| error {

	} TOK_SEMI {
		$$ = NULL;
	}
    ;

goto_stmt :
    TOK_GOTO CONST_INTEGER {
        $$ = new TreeNode($1, StatementNode);
        $$->insert(new TreeNode($2));
    }
    ;

expression_list :
    expression_list TOK_COMMA expression {
        $$ = $1;
		$$->insert(new TreeNode($2));
        $$->insert($3);
    }
    | expression {
        $$ = new TreeNode(ExpressionNode);
        $$->insert($1);
    }
    ;

expression :
    expression TOK_GE expr {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | expression TOK_GT expr {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | expression TOK_LE expr {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | expression TOK_LT expr {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | expression TOK_EQUAL expr {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | expression TOK_UNEQUAL expr {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | expr {
        $$ = $1;
    }
    ;

expr :
    expr TOK_PLUS term {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | expr TOK_MINUS term {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | expr TOK_OR term {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | expr TOK_XOR term {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | term {
        $$ = $1;
    }
    ;

term :
    term TOK_MUL factor {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | term TOK_DIV factor {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | term TOK_MOD factor {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | term TOK_AND factor {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | term TOK_SHL factor {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | term TOK_SHR factor {
        $$ = new TreeNode($2, ExpressionNode);
		$$->insert($1);
        $$->insert($3);
    }
    | factor {
        $$ = $1;
    }
    ;

factor :
    NAME {
        $$ = new TreeNode($1);
    }
    | NAME TOK_LP args_list TOK_RP {
        $$ = new TreeNode($1, ProcedureNode);
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
    }
    | NAME TOK_LB expression_list TOK_RB {
        $$ = new TreeNode($1);
        $$->insert(new TreeNode($2));
        $$->insertChild($3);
        $$->insert(new TreeNode($4));
    }
    | SYS_FUNCT {
        $$ = $1;
		$$->type = ProcedureNode;
    }
    | SYS_FUNCT TOK_LP args_list TOK_RP {
        $$ = $1;
		$$->type = ProcedureNode;
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
    }
    | const_value {
		$$ = $1;
    }
    | TOK_LP expression TOK_RP {
        $$ = $2;
    }
    | TOK_NOT factor {
        $$ = new TreeNode($1, ExpressionNode);
		$$->insert($2);
    }
    | TOK_MINUS factor {
        $$ = new TreeNode($1, ExpressionNode);
		$$->insert($2);
    }
    | NAME TOK_LB expression TOK_RB {
        $$ = new TreeNode($1);
        $$->insert(new TreeNode($2));
        $$->insert($3);
        $$->insert(new TreeNode($4));
    }
    | NAME TOK_DOT NAME {
        $$ = new TreeNode($2, StatementNode);
        $$->insert(new TreeNode($1));
        $$->insert(new TreeNode($3));
    }
    ;

SYS_FUNCT :
    TOK_ABS {
        $$ = new TreeNode($1);
    }
    | TOK_CHR {
        $$ = new TreeNode($1);
    }
    | TOK_ODD {
        $$ = new TreeNode($1);
    }
    | TOK_ORD {
        $$ = new TreeNode($1);
    }
    | TOK_PRED {
        $$ = new TreeNode($1);
    }
    | TOK_SQR {
        $$ = new TreeNode($1);
    }
    | TOK_SQRT {
        $$ = new TreeNode($1);
    }
    | TOK_SUCC {
        $$ = new TreeNode($1);
    }
    ;

args_list :
    args_list TOK_COMMA expression {
        $$ = $1;
        $$->insert($3);
    }
    | expression {
        $$ = new TreeNode(ExpressionNode);
        $$->insert($1);
    }
    ;

%%

int main(){
        int result = yyparse();
		if (errorCount == 0){
	        //programTable->print(1);

	        Generate4 Gen;
	        Gen.VisitTree(programTable);
            //Gen.Print();
            new GS(Gen);
		}else{
			fprintf(stderr, "There still have %d error exist(s).\n", errorCount);
		}


        return result;
}

void yyerror(const char* s){
	fprintf(stderr, "ERROR at line %d : %s when parsing (%s)\n", yylineno, s, yytext);
	errorCount++;
}
