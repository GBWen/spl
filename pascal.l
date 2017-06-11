%{
#include "SymbolTable.hpp"
#include "pascal_yacc.hpp"
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

ValueNode* makeIntegerNode(char* integer){
    ValueNode* tmp = new ValueNode();
    tmp->type = VT_INT;
    tmp->name = string(integer);
    return tmp;
}

ValueNode* makeRealNode(char* real){
    ValueNode* tmp = new ValueNode();
    tmp->type = VT_REAL;
    tmp->name = string(real);
    return tmp;
}

ValueNode* makeCharNode(char* ch){
    ValueNode* tmp = new ValueNode();
    tmp->type = VT_CHAR;
    tmp->name = string();
    tmp->name += '"';
    tmp->name += ch[1];
    tmp->name += '"';
    return tmp;
}

ValueNode* makeBooleanNode(char* boolean){
    ValueNode* tmp = new ValueNode();
    tmp->type = VT_BOOL;
    tmp->name = string(boolean);
    return tmp;
}

ValueNode* makeStringNode(char* str){
    ValueNode* tmp = new ValueNode();
    tmp->type = VT_STRING;
    tmp->name = string(str);
    return tmp;
}

ValueNode* makeTokenNode(char* token){
    ValueNode* tmp = new ValueNode();
    tmp->type = VT_TOKEN;
    tmp->name = string(token);
    return tmp;
}

ValueNode* makeNameNode(char* name){
    ValueNode* tmp = new ValueNode();
    tmp->type = VT_NAME;
    tmp->name = string(name);
    return tmp;
}

%}

letter			[A-Za-z]
digit			[0-9]
identifier		{letter}({letter}|{digit})*
digits			{digit}+
sign			[\+\-]

optimalFraction	(\.{digits})?
optimalExponent	([Ee]{sign}?{digits})?

const_integer	[\-]?([1-9]{digit}*|0)
const_char		\'.\'
const_real		{const_integer}{optimalFraction}{optimalExponent}
const_boolean	true|false
const_string	'(?:[^']+|'')*'

%option yylineno

%%

program		{
    yylval.value = makeTokenNode(yytext);
    return TOK_PROGRAM;
}
procedure	{
    yylval.value = makeTokenNode(yytext);
    return TOK_PROCEDURE;
}
function	{
    yylval.value = makeTokenNode(yytext);
    return TOK_FUNCTION;
}
exit        {
    yylval.value = makeTokenNode(yytext);
    return TOK_EXIT;
}

label   {
    yylval.value = makeTokenNode(yytext);
    return TOK_LABEL;
}
const	{
    yylval.value = makeTokenNode(yytext);
    return TOK_CONST;
}
type    {
    yylval.value = makeTokenNode(yytext);
    return TOK_TYPE;
}
var		{
    yylval.value = makeTokenNode(yytext);
    return TOK_VAR;
}
array	{
    yylval.value = makeTokenNode(yytext);
    return TOK_ARRAY;
}
record	{
    yylval.value = makeTokenNode(yytext);
    return TOK_RECORD;
}
integer	{
    yylval.value = makeTokenNode(yytext);
    return TOK_INTEGER;
}
real	{
    yylval.value = makeTokenNode(yytext);
    return TOK_REAL;
}
char	{
    yylval.value = makeTokenNode(yytext);
    return TOK_CHAR;
}
string {
    yylval.value = makeTokenNode(yytext);
    return TOK_STRING;
}
boolean	{
    yylval.value = makeTokenNode(yytext);
    return TOK_BOOLEAN;
}

begin	{
    yylval.value = makeTokenNode(yytext);
    return TOK_BEGIN;
}
end		{
    yylval.value = makeTokenNode(yytext);
    return TOK_END;
}

if		{
    yylval.value = makeTokenNode(yytext);
    return TOK_IF;
}
then	{
    yylval.value = makeTokenNode(yytext);
    return TOK_THEN;
}
else	{
    yylval.value = makeTokenNode(yytext);
    return TOK_ELSE;
}

for		{
    yylval.value = makeTokenNode(yytext);
    return TOK_FOR;
}
to		{
    yylval.value = makeTokenNode(yytext);
    return TOK_TO;
}
downto	{
    yylval.value = makeTokenNode(yytext);
    return TOK_DOWNTO;
}
do		{
    yylval.value = makeTokenNode(yytext);
    return TOK_DO;
}

case	{
    yylval.value = makeTokenNode(yytext);
    return TOK_CASE;
}
of		{
    yylval.value = makeTokenNode(yytext);
    return TOK_OF;
}

while	{
    yylval.value = makeTokenNode(yytext);
    return TOK_WHILE;
}
repeat	{
    yylval.value = makeTokenNode(yytext);
    return TOK_REPEAT;
}
until	{
    yylval.value = makeTokenNode(yytext);
    return TOK_UNTIL;
}

goto	{
    yylval.value = makeTokenNode(yytext);
    return TOK_GOTO;
}

or		{
    yylval.value = makeTokenNode(yytext);
    return TOK_OR;
}
and		{
    yylval.value = makeTokenNode(yytext);
    return TOK_AND;
}
xor		{
    yylval.value = makeTokenNode(yytext);
    return TOK_XOR;
}
not		{
    yylval.value = makeTokenNode(yytext);
    return TOK_NOT;
}
div     {
    yylval.value = makeTokenNode(yytext);
    return TOK_DIV;
}
mod		{
    yylval.value = makeTokenNode(yytext);
    return TOK_MOD;
}
shl		{
    yylval.value = makeTokenNode(yytext);
    return TOK_SHL;
}
shr		{
    yylval.value = makeTokenNode(yytext);
    return TOK_SHR;
}

writeln	{
    yylval.value = makeTokenNode(yytext);
    return TOK_WRITELN;
}
write	{
    yylval.value = makeTokenNode(yytext);
    return TOK_WRITE;
}

read	{
    yylval.value = makeTokenNode(yytext);
    return TOK_READ;
}
readln	{
    yylval.value = makeTokenNode(yytext);
    return TOK_READLN;
}

maxint  {
    yylval.value = makeTokenNode(yytext);
    return TOK_MAXINT;
}

abs		{
    yylval.value = makeTokenNode(yytext);
    return TOK_ABS;
}
chr		{
    yylval.value = makeTokenNode(yytext);
    return TOK_CHR;
}
odd		{
    yylval.value = makeTokenNode(yytext);
    return TOK_ODD;
}
ord		{
    yylval.value = makeTokenNode(yytext);
    return TOK_ORD;
}
pred	{
    yylval.value = makeTokenNode(yytext);
    return TOK_PRED;
}
sqr		{
    yylval.value = makeTokenNode(yytext);
    return TOK_SQR;
}
sqrt	{
    yylval.value = makeTokenNode(yytext);
    return TOK_SQRT;
}
succ	{
    yylval.value = makeTokenNode(yytext);
    return TOK_SUCC;
}

{const_integer} {
    yylval.value = makeIntegerNode(yytext);
    return CONST_INTEGER;
}
{const_char}    {
    yylval.value = makeCharNode(yytext);
    return CONST_CHAR;
}
{const_string}  {
    yylval.value = makeStringNode(yytext);
    return CONST_STRING;
}
{const_real}    {
    yylval.value = makeRealNode(yytext);
    return CONST_REAL;
}
{const_boolean} {
    yylval.value = makeBooleanNode(yytext);
    return CONST_BOOLEAN;
}
{identifier}    {
    yylval.value = makeNameNode(yytext);
    return NAME;
}

\(      {
    yylval.value = makeTokenNode(yytext);
    return TOK_LP;
}
\)      {
    yylval.value = makeTokenNode(yytext);
    return TOK_RP;
}
\[      {
    yylval.value = makeTokenNode(yytext);
    return TOK_LB;
}
\]      {
    yylval.value = makeTokenNode(yytext);
    return TOK_RB;
}
\.      {
    yylval.value = makeTokenNode(yytext);
    return TOK_DOT;
}
\;      {
    yylval.value = makeTokenNode(yytext);
    return TOK_SEMI;
}
\,      {
    yylval.value = makeTokenNode(yytext);
    return TOK_COMMA;
}
\:      {
    yylval.value = makeTokenNode(yytext);
    return TOK_COLON;
}
\*      {
    yylval.value = makeTokenNode(yytext);
    return TOK_MUL;
}
\/      {
    yylval.value = makeTokenNode(yytext);
    return TOK_DIV;
}
\+      {
    yylval.value = makeTokenNode(yytext);
    return TOK_PLUS;
}
\-      {
    yylval.value = makeTokenNode(yytext);
    return TOK_MINUS;
}
\>\=    {
    yylval.value = makeTokenNode(yytext);
    return TOK_GE;
}
\>      {
    yylval.value = makeTokenNode(yytext);
    return TOK_GT;
}
\<\=    {
    yylval.value = makeTokenNode(yytext);
    return TOK_LE;
}
\<      {
    yylval.value = makeTokenNode(yytext);
    return TOK_LT;
}
\=      {
    yylval.value = makeTokenNode(yytext);
    return TOK_EQUAL;
}
\<\>    {
    yylval.value = makeTokenNode(yytext);
    return TOK_UNEQUAL;
}
\:\=    {
    yylval.value = makeTokenNode(yytext);
    return TOK_ASSIGN;
}

\/\/[^\n]* {
    //printf("line comment %s\n", yytext);
}
\{[^\}]*\} {
    //printf("block comment %s\n", yytext);
}

[ \n\r\t] {}

%%
