typedef union                                          //to keep track of declared variables
{
    int ival;
    char* sval;
} YYSTYPE;
#define	NUMBER	258
#define	NUM	259
#define	VARIABLE	260
#define	ENDLINE	261
#define	FUNCTION_DEF	262
#define	FUNCTION_END	263
#define	WHILE	264
#define	ENDWHILE	265
#define	LISTEN	266
#define	SPEAK	267
#define	ELSEIF	268
#define	ELSE	269
#define	ENDIF	270
#define	IF	271
#define	EQUAL	272
#define	TCEQ	273
#define	TCNE	274
#define	TCLE	275
#define	TCGE	276
#define	TCL	277
#define	TCG	278
#define	ERROR	279
#define	TEXT	280
#define	AND	281
#define	OR	282


extern YYSTYPE yylval;
