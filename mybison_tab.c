
/*  A Bison parser, made from mybison.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

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

#line 1 "mybison.y"

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

#line 23 "mybison.y"
typedef union                                          //to keep track of declared variables
{
    int ival;
    char* sval;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		107
#define	YYFLAG		-32768
#define	YYNTBASE	34

#define YYTRANSLATE(x) ((unsigned)(x) <= 282 ? yytranslate[x] : 60)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
    33,    30,    28,     2,    29,     2,    31,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     5,     9,    11,    13,    16,    18,    21,    23,
    26,    28,    31,    33,    34,    35,    44,    45,    53,    55,
    56,    61,    62,    67,    68,    73,    74,    79,    80,    85,
    86,    91,    92,    97,   101,   105,   107,   111,   117,   120,
   126,   132,   136,   141,   144,   148,   150,   152,   153,   158,
   159,   164,   165,   170,   171,   176
};

static const short yyrhs[] = {    35,
    34,     0,    35,     0,     7,    36,     8,     0,    54,     0,
    37,     0,    37,    36,     0,    40,     0,    40,    36,     0,
    52,     0,    52,    36,     0,    53,     0,    53,    36,     0,
     6,     0,     0,     0,     9,    38,    32,    51,    33,    39,
    36,    10,     0,     0,    16,    32,    51,    33,    41,    36,
    42,     0,    15,     0,     0,    14,    43,    36,    15,     0,
     0,    55,    45,    18,    55,     0,     0,    55,    46,    19,
    55,     0,     0,    55,    47,    20,    55,     0,     0,    55,
    48,    21,    55,     0,     0,    55,    49,    22,    55,     0,
     0,    55,    50,    23,    55,     0,    44,    26,    51,     0,
    44,    27,    51,     0,    44,     0,    12,    55,     6,     0,
    12,    32,    51,    33,     6,     0,    12,     6,     0,    11,
     5,    17,     3,     6,     0,     4,     5,    17,    55,     6,
     0,     4,     5,     6,     0,     5,    17,    55,     6,     0,
    55,     6,     0,    54,    55,     6,     0,     3,     0,     5,
     0,     0,    55,    28,    56,    55,     0,     0,    55,    29,
    57,    55,     0,     0,    55,    30,    58,    55,     0,     0,
    55,    31,    59,    55,     0,    32,    55,    33,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    61,    62,    65,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    79,    79,    79,    82,    82,    84,    85,
    85,    87,    87,    88,    88,    89,    89,    90,    90,    91,
    91,    92,    92,    94,    95,    96,    99,   102,   105,   106,
   108,   116,   123,   131,   132,   135,   136,   143,   143,   144,
   144,   145,   145,   146,   146,   147
};

static const char * const yytname[] = {   "$","error","$undefined.","NUMBER",
"NUM","VARIABLE","ENDLINE","FUNCTION_DEF","FUNCTION_END","WHILE","ENDWHILE",
"LISTEN","SPEAK","ELSEIF","ELSE","ENDIF","IF","EQUAL","TCEQ","TCNE","TCLE","TCGE",
"TCL","TCG","ERROR","TEXT","AND","OR","'+'","'-'","'*'","'/'","'('","')'","program",
"function","commands","whilestatement","@1","@2","ifstatement","@3","ifs","@4",
"equation","@5","@6","@7","@8","@9","@10","logop","myio","declaration","expression",
"kif","@11","@12","@13","@14",""
};
#endif

static const short yyr1[] = {     0,
    34,    34,    35,    36,    36,    36,    36,    36,    36,    36,
    36,    36,    36,    38,    39,    37,    41,    40,    42,    43,
    42,    45,    44,    46,    44,    47,    44,    48,    44,    49,
    44,    50,    44,    51,    51,    51,    52,    52,    52,    52,
    53,    53,    53,    54,    54,    55,    55,    56,    55,    57,
    55,    58,    55,    59,    55,    55
};

static const short yyr2[] = {     0,
     2,     1,     3,     1,     1,     2,     1,     2,     1,     2,
     1,     2,     1,     0,     0,     8,     0,     7,     1,     0,
     4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
     4,     0,     4,     3,     3,     1,     3,     5,     2,     5,
     5,     3,     4,     2,     3,     1,     1,     0,     4,     0,
     4,     0,     4,     0,     4,     3
};

static const short yydefact[] = {     0,
     0,     2,    46,     0,    47,    13,    14,     0,     0,     0,
     0,     0,     5,     7,     9,    11,     4,     0,     1,     0,
     0,     0,     0,    47,    39,     0,     0,     0,     0,     3,
     6,     8,    10,    12,     0,    44,    48,    50,    52,    54,
    42,     0,     0,     0,     0,    36,     0,    22,    37,     0,
    22,    56,    45,     0,     0,     0,     0,     0,    43,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    17,    49,    51,    53,    55,    41,    15,    40,    34,    35,
    38,     0,     0,     0,     0,     0,     0,     0,     0,    23,
    25,    27,    29,    31,    33,     0,     0,    20,    19,    18,
    16,     0,     0,    21,     0,     0,     0
};

static const short yydefgoto[] = {    19,
     2,    12,    13,    22,    89,    14,    88,   100,   102,    46,
    65,    66,    67,    68,    69,    70,    47,    15,    16,    17,
    18,    54,    55,    56,    57
};

static const short yypact[] = {    -2,
    22,    -2,-32768,    25,     0,-32768,-32768,    27,     4,     3,
     8,    45,    22,    22,    22,    22,     8,    16,-32768,    12,
     8,    28,    50,-32768,-32768,     8,    35,     8,    94,-32768,
-32768,-32768,-32768,-32768,    42,-32768,-32768,-32768,-32768,-32768,
-32768,     8,    55,     8,    56,   -12,    29,    75,-32768,    36,
    90,-32768,-32768,     8,     8,     8,     8,    62,-32768,    54,
    68,     8,     8,    82,    89,    95,    96,   105,    93,   106,
-32768,   -11,   -11,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,     8,     8,     8,     8,     8,     8,    22,    22,    71,
    71,    71,    71,    71,    71,    41,   107,-32768,-32768,-32768,
-32768,    22,   113,-32768,   130,   131,-32768
};

static const short yypgoto[] = {   132,
-32768,   -13,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   -20,-32768,-32768,-32768,
    -5,-32768,-32768,-32768,-32768
};


#define	YYLAST		132


static const short yytable[] = {    31,
    32,    33,    34,    27,     1,    29,     3,    50,    24,    25,
     3,    35,    24,    62,    63,    43,    21,    41,    39,    40,
    48,    36,    51,    60,     3,     4,     5,     6,    42,    20,
     7,    23,     8,     9,    28,    26,    58,    10,    51,    11,
    49,    79,    80,    37,    38,    39,    40,    53,    72,    73,
    74,    75,    30,    11,    98,    99,    51,    51,    61,    44,
    59,    64,    37,    38,    39,    40,    45,    76,    71,    37,
    38,    39,    40,    78,    96,    97,    90,    91,    92,    93,
    94,    95,    37,    38,    39,    40,    77,    81,   103,    37,
    38,    39,    40,   -24,   -26,   -28,   -30,   -32,    37,    38,
    39,    40,    37,    38,    39,    40,    82,    52,   -24,   -26,
   -28,   -30,   -32,    83,    86,    84,   101,    37,    38,    39,
    40,    37,    38,    39,    40,    85,    52,   104,    87,   106,
   107,   105
};

static const short yycheck[] = {    13,
    14,    15,    16,     9,     7,    11,     3,    28,     5,     6,
     3,    17,     5,    26,    27,    21,    17,     6,    30,    31,
    26,     6,    28,    44,     3,     4,     5,     6,    17,     5,
     9,     5,    11,    12,    32,    32,    42,    16,    44,    32,
     6,    62,    63,    28,    29,    30,    31,     6,    54,    55,
    56,    57,     8,    32,    14,    15,    62,    63,     3,    32,
     6,    33,    28,    29,    30,    31,    17,     6,    33,    28,
    29,    30,    31,     6,    88,    89,    82,    83,    84,    85,
    86,    87,    28,    29,    30,    31,    33,     6,   102,    28,
    29,    30,    31,    19,    20,    21,    22,    23,    28,    29,
    30,    31,    28,    29,    30,    31,    18,    33,    19,    20,
    21,    22,    23,    19,    22,    20,    10,    28,    29,    30,
    31,    28,    29,    30,    31,    21,    33,    15,    23,     0,
     0,     0
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 14:
#line 79 "mybison.y"
{while_start(while_start_num);;
    break;}
case 15:
#line 79 "mybison.y"
{while_start2(while_start_num);whilestack.push(while_start_num); while_start_num++;;
    break;}
case 16:
#line 79 "mybison.y"
{while_end(whilestack.top());whilestack.pop();
    break;}
case 17:
#line 82 "mybison.y"
{if_num++; if_start(if_num); ifstack.push(if_num);;
    break;}
case 19:
#line 84 "mybison.y"
{if_end(ifstack.top()); ifstack.pop();;
    break;}
case 20:
#line 85 "mybison.y"
{if_else(ifstack.top()); ifstack.pop(); if_num++; ifstack.push(if_num);
    break;}
case 21:
#line 85 "mybison.y"
{if_end(ifstack.top()); ifstack.pop();;
    break;}
case 22:
#line 87 "mybison.y"
{pushEAX();;
    break;}
case 23:
#line 87 "mybison.y"
{pushEAX(); tceq(eqnum);eqnum++;;
    break;}
case 24:
#line 88 "mybison.y"
{pushEAX();;
    break;}
case 25:
#line 88 "mybison.y"
{pushEAX(); tcne(eqnum);eqnum++;;
    break;}
case 26:
#line 89 "mybison.y"
{pushEAX();;
    break;}
case 27:
#line 89 "mybison.y"
{pushEAX(); tcle(eqnum);eqnum++;;
    break;}
case 28:
#line 90 "mybison.y"
{pushEAX();;
    break;}
case 29:
#line 90 "mybison.y"
{pushEAX(); tcge(eqnum);eqnum++;;
    break;}
case 30:
#line 91 "mybison.y"
{pushEAX();;
    break;}
case 31:
#line 91 "mybison.y"
{pushEAX(); tcl(eqnum);eqnum++;;
    break;}
case 32:
#line 92 "mybison.y"
{pushEAX();;
    break;}
case 33:
#line 92 "mybison.y"
{pushEAX(); tcg(eqnum);eqnum++;;
    break;}
case 34:
#line 94 "mybison.y"
{log_link_and();;
    break;}
case 35:
#line 95 "mybison.y"
{log_link_or();;
    break;}
case 36:
#line 96 "mybison.y"
{popEAX();;
    break;}
case 37:
#line 99 "mybison.y"
{
                                                print_numexpr();
                                            ;
    break;}
case 38:
#line 102 "mybison.y"
{
                                                print_numexpr();
                                            ;
    break;}
case 39:
#line 105 "mybison.y"
{print_nl();;
    break;}
case 40:
#line 106 "mybison.y"
{movEAX_num(yyvsp[-1].ival); let_var(yyvsp[-3].sval);;
    break;}
case 41:
#line 108 "mybison.y"
{  if (varmap.count(yyvsp[-3].sval)) AllreadyDeclared(yyvsp[-3].sval, line_num); 
                                                else 
                                                {
                                                    varmap.insert(pair<string,int>(yyvsp[-3].sval,yyvsp[-1].ival));
                                                    define_var(yyvsp[-3].sval);
                                                    let_var(yyvsp[-3].sval);
                                                }
                                             ;
    break;}
case 42:
#line 116 "mybison.y"
{  if (varmap.count(yyvsp[-1].sval)) AllreadyDeclared(yyvsp[-1].sval, line_num); 
                                                else 
                                                {
                                                    varmap.insert(pair<string,int>(yyvsp[-1].sval,0));
                                                    define_var(yyvsp[-1].sval);
                                                }
                                             ;
    break;}
case 43:
#line 123 "mybison.y"
{  if (!varmap.count(yyvsp[-3].sval)) UndeclaredVariableError(yyvsp[-3].sval, line_num); 
                                                else 
                                                {
                                                    varmap[yyvsp[-3].sval] = yyvsp[-1].ival;
                                                    let_var(yyvsp[-3].sval);
                                                }
                                             ;
    break;}
case 46:
#line 135 "mybison.y"
{movEAX_num(yyvsp[0].ival);;
    break;}
case 47:
#line 136 "mybison.y"
{
                    if (!varmap.count(yyvsp[0].sval)) {UndeclaredVariableError(yyvsp[0].sval, line_num);} 
                    else
                    {  
                        movEAX_var(yyvsp[0].sval);
                    }
                ;
    break;}
case 48:
#line 143 "mybison.y"
{pushEAX();;
    break;}
case 49:
#line 143 "mybison.y"
{popEBX(); add();;
    break;}
case 50:
#line 144 "mybison.y"
{pushEAX();;
    break;}
case 51:
#line 144 "mybison.y"
{popEBX(); sub();;
    break;}
case 52:
#line 145 "mybison.y"
{pushEAX();;
    break;}
case 53:
#line 145 "mybison.y"
{popEBX(); mul();;
    break;}
case 54:
#line 146 "mybison.y"
{pushEAX();;
    break;}
case 55:
#line 146 "mybison.y"
{pushEAX(); div();;
    break;}
case 56:
#line 147 "mybison.y"
{yyval.ival = yyvsp[-1].ival;;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 150 "mybison.y"


int main() 
{
    init_asm();
	if (yyparse() == 0){
		fprintf(stderr, "Assembly file created .\n");
	}
	generate_asm();
}
