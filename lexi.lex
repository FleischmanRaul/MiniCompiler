%{
#include "mybison_tab.h"
#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */
using namespace std;
extern int line_num;
%}

%option noyywrap
%option yylineno
%x COMMENT

%%

\n                          {line_num++;}
\/\*                        {BEGIN(COMMENT);}
<COMMENT>\*\/               {BEGIN(0);}
<COMMENT>.                  {}
<COMMENT>\n                 {line_num++;}
elseif                      {return ELSEIF;   }
else                        {return ELSE;     }
endif                       {return ENDIF;    }
if                          {return IF;       }
while                       {return WHILE;    }
endwhile                    {return ENDWHILE; }
num                         {return NUM;      }
listen                      {return LISTEN;   }
speak                       {return SPEAK;    }
func                        {return FUNCTION_DEF;}
endfunc                     {return FUNCTION_END;}
"("|")"|"{"|"}"             {return yytext[0];}    
[a-zA-Z][a-zA-Z0-9]*        {yylval.sval = strdup(yytext); return VARIABLE; }
[-]?[1-9][0-9]*             {yylval.ival = atoi(yytext);return NUMBER;}
0                           {yylval.ival = atoi(yytext);return NUMBER;}
[\+\-\*\/]{1}               {return yytext[0];}
&                           {return AND;      }
\|                          {return OR;       }
"=="                        {return TCEQ;     }
"!="                        {return TCNE;     }    
"<="                        {return TCLE;     }
">="                        {return TCGE;     }
"<"                         {return TCL;      }
">"                         {return TCG;      }
"="                         {return EQUAL;    }
\".*\"                      {return TEXT;     }                         
;                           {return ENDLINE;  }
[ \t]                       {}
[^\n]                       {return ERROR;    }
%%