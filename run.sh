lex -o pascal_lex.cpp pascal.l
yacc -d -v -o pascal_yacc.cpp pascal.y
g++ pascal_lex.cpp pascal_yacc.cpp SymbolTable.cpp G4.cpp GS.cpp -ll -g
