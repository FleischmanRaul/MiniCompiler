%{
#include <iostream>
#include <cstdlib>
#include <map>
#include <stack>       
#include "kodgen.h"
#include "errors.h"
using namespace std ;

extern int yylex();


int eqnum = 0;                                  //we need the numbers and stacks to know how to label the jumps
int while_start_num = 0;                        
int if_num = 0;
std::stack<int> whilestack;
std::stack<int> ifstack;

int line_num = 1;                               // for keeping track of line numbers in the program we are parsing
map <string ,int>varmap;                        // map from variable name to value
%}

%union                                          //to keep track of declared variables
{
    int ival;
    char* sval;
};

%token NUMBER
%token NUM
%token VARIABLE
%token ENDLINE
%token FUNCTION_DEF
%token FUNCTION_END
%token WHILE
%token ENDWHILE
%token LISTEN
%token SPEAK
%token ELSEIF
%token ELSE
%token ENDIF
%token IF
%token EQUAL
%token TCEQ
%token TCNE
%token TCLE
%token TCGE
%token TCL
%token TCG
%token ERROR
%token TEXT
%token AND
%token OR
%start program
%left '+' '-'
%left '*' '/'

%type<ival> NUMBER kif
%type<sval> VARIABLE
%%
program : function program
        | function
;

function : FUNCTION_DEF commands FUNCTION_END 
;

commands : expression
         | whilestatement
         | whilestatement commands
         | ifstatement
         | ifstatement commands
         | myio
         | myio commands
         | declaration
         | declaration commands
         | ENDLINE
;
whilestatement : WHILE {while_start(while_start_num);} '(' logop ')' {while_start2(while_start_num);whilestack.push(while_start_num); while_start_num++;} commands ENDWHILE {while_end(whilestack.top());whilestack.pop()}
;

ifstatement : IF '(' logop ')' {if_num++; if_start(if_num); ifstack.push(if_num);} commands ifs 
;
ifs : ENDIF  {if_end(ifstack.top()); ifstack.pop();}
    | ELSE   {if_else(ifstack.top()); ifstack.pop(); if_num++; ifstack.push(if_num)} commands ENDIF {if_end(ifstack.top()); ifstack.pop();}
;
equation    : kif {pushEAX();} TCEQ kif {pushEAX(); tceq(eqnum);eqnum++;}   
            | kif {pushEAX();} TCNE kif {pushEAX(); tcne(eqnum);eqnum++;} 
            | kif {pushEAX();} TCLE kif {pushEAX(); tcle(eqnum);eqnum++;} 
            | kif {pushEAX();} TCGE kif {pushEAX(); tcge(eqnum);eqnum++;} 
            | kif {pushEAX();} TCL kif  {pushEAX(); tcl(eqnum);eqnum++;} 
            | kif {pushEAX();} TCG kif  {pushEAX(); tcg(eqnum);eqnum++;} 
;
logop   : equation AND logop{log_link_and();}
        | equation OR logop {log_link_or();}
        | equation {popEAX();}
;

myio : SPEAK kif ENDLINE                    {
                                                print_numexpr();
                                            }
     | SPEAK '(' logop ')' ENDLINE          {
                                                print_numexpr();
                                            }
     | SPEAK ENDLINE                        {print_nl();}
     | LISTEN VARIABLE EQUAL NUMBER ENDLINE {movEAX_num($4); let_var($2);}
; 
declaration : NUM VARIABLE EQUAL kif ENDLINE {  if (varmap.count($2)) AllreadyDeclared($2, line_num); 
                                                else 
                                                {
                                                    varmap.insert(pair<string,int>($2,$4));
                                                    define_var($<sval>2);
                                                    let_var($<sval>2);
                                                }
                                             }
            | NUM VARIABLE ENDLINE           {  if (varmap.count($2)) AllreadyDeclared($2, line_num); 
                                                else 
                                                {
                                                    varmap.insert(pair<string,int>($2,0));
                                                    define_var($<sval>2);
                                                }
                                             }
            | VARIABLE EQUAL kif ENDLINE     {  if (!varmap.count($1)) UndeclaredVariableError($1, line_num); 
                                                else 
                                                {
                                                    varmap[$1] = $3;
                                                    let_var($<sval>1);
                                                }
                                             }
; 
expression: kif ENDLINE
    | expression kif ENDLINE
;

kif: NUMBER     {movEAX_num($<ival>1);}                             
   | VARIABLE   {
                    if (!varmap.count($1)) {UndeclaredVariableError($1, line_num);} 
                    else
                    {  
                        movEAX_var($<sval>1);
                    }
                }                              
   | kif '+' {pushEAX();} kif {popEBX(); add();}
   | kif '-' {pushEAX();} kif {popEBX(); sub();}
   | kif '*' {pushEAX();} kif {popEBX(); mul();}
   | kif '/' {pushEAX();} kif {pushEAX(); div();}
   | '('kif')' {$$ = $2;}
;

%%

int main() 
{
    init_asm();
	if (yyparse() == 0){
		fprintf(stderr, "Assembly file created .\n");
	}
	generate_asm();
}
