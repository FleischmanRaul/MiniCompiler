#ifndef MYERRORS_H
#define MYERRORS_H
#include <iostream>
using namespace std;
void yyerror(char* s, int line_num);
void UndeclaredVariableError (char* s, int line_num);
void AllreadyDeclared (char* s, int line_num);

void yyerror(char* s)
{
    cerr << "stderr: "<< s << endl;
}
void UndeclaredVariableError(char* s, int line_num) 
{
    cerr << "Error :" << s << " Undeclared variable! In line: " << line_num << endl;
}
void AllreadyDeclared(char* s, int line_num) 
{
    cerr << "Error :" << s << " Allready declared variable! In line: " << line_num << endl;
}

#endif
