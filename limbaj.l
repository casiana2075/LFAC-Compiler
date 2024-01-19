%{
#include "limbaj.tab.h"
#include <string.h>
#include <stdio.h>
%}

%option noyywrap

%%
"int"|"float"|"char"|"string"|"bool" {yylval.string = strdup(yytext);return TYPE;}
"const"                              {return CONST;}

"begin_class"                        {return BGINCLASS;}
"end_class"                          {return ENDCLASS;}
"begin_mainul"                        {return BGINMAIN;}
"end_mainul"                          {return ENDMAIN;}
"begin_global"                       {return BGINGLOBAL;}
"end_global"                         {return ENDGLOBAL;}
"begin_functions"                    {return BGINFUNC;}
"end_functions"                      {return ENDFUNC;}

"clasul"                              {return CLASS;}

"TypeOf"                             {return TYPEOF;}
"Eval"                               {return EVAL;}

"iful"                                 {return IF;}
"elseul"                               {return ELSE;}
"whileul"                              {return WHILE;}
"forul"                              {return FOR;}  
"tr"                               {yylval.bolean = true; return BOOL; }
"fls"                              {yylval.bolean = false; return BOOL; }
\"[0-9a-zA-Z ]*\"                    {yylval.string = strdup(yytext); return STRING; }
['][0-9a-zA-Z][']                    {yylval.chr= yytext[1]; return CHAR; }
[a-zA-Z][a-zA-Z0-9]*                 {yylval.string = strdup(yytext); return ID;}
":="             {return ASSIGN;}
"=='"            { return EQ; }
"!="             { return NEQ;}
">'"             { return GT; }
"<'"             { return LT; }
">='"            { return GE; }
"<='"            { return LE; }
"&&'"            { return AND;}
"||'"            { return OR; }
"!'"             { return NOT;}
[1-9]+[1-9]*[.][0-9]+[0-9]*         {yylval.num_with_dot= atof(yytext);return FLOAT;}
[0].[0-9]+[0-9]*                    {yylval.num_with_dot = atof(yytext);return FLOAT;}
[1-9][0-9]*                         {yylval.num = atoi(yytext); return INT; }
0                                   {yylval.num = 0; return INT; } 
[ \t]                               ;
\n                                  {yylineno++;}
.                                   {return yytext[0];}
