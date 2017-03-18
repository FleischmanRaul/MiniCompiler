bison -dvt mybison.y
flex lexi.lex
g++ lex.yy.c mybison_tab.c