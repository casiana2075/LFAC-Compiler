%{

#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include "AST.h"
#include "IdList.h"
#include "FunctionList.h"
#include "limbaj.tab.h"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yyleng;
extern int yylex();

void yyerror(const char * s);

using namespace std;

class IdList ids;
class AST ast;
class FunctionList fs;
string scope;
string altscope;


bool isInteger(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    } catch (const std::invalid_argument& ia) {
        return false;
    } catch (const std::out_of_range& oor) {
        return false;
    }
}

bool isFloat(const std::string& str) {
    try {
        std::stof(str);
        return true;
    } catch (const std::invalid_argument& ia) {
        return false;
    } catch (const std::out_of_range& oor) {
        return false;
    }
}

bool isBoolean(const std::string& str) {
    return (str == "true" || str == "false");
}

%}

%union {
    int num;
    float num_with_dot;
    bool bolean;
    char chr;
    char* string;
struct Node *nod;
struct ParamInfo *parametru;
struct FunctionInfo *functie;
}

%token           BGINMAIN ENDMAIN ASSIGN BGINCLASS ENDCLASS CONST IF ELSE WHILE FOR BGINGLOBAL ENDGLOBAL BGINFUNC ENDFUNC EVAL
%token           LT LE GT GE EQ NEQ AND OR NOT 
%token<string>   ID TYPE TYPEOF
%token<num>      INT 
%token<num_with_dot> FLOAT   
%token<bolean>        BOOL 
%token<chr>        CHAR 
%token<string>     STRING CLASS

%type<nod> eval expression
%type<string> array_list
%type<parametru> param param_call
%type<functie> list_param list_param_call

%left OR
%left AND
%left EQ NEQ
%left GT LT LE GE
%left '+' '-' 
%left '*' '/' 
%left '^' 
%left NOT
%left '(' ')' '[' ']'

%start progr

%%
progr: user_defined_data_types global_variables functions main { 
                                                                    cout <<"The program works!! (ง ͡ʘ ͜ʖ ͡ʘ)ง \n";
                                                                    ids.printVars();
                                                                    fs.printFunctions();
                                                               };

user_defined_data_types:
                       | BGINCLASS class_list ENDCLASS
                       ;

class_list :
                | class_list clasa 
                ;

clasa: CLASS ID '{' list_class_fields methods'}' ';' 
           ;

list_class_fields :  list_class_fields param_class ';'
                   |
                   ; 

param_class: TYPE ID
           ;

methods: TYPE ID '(' list_param_class ')' '{' list1 '}' ;     //int get_doors() { }
       |
       ;
       
list_param_class : param_class
                | list_param_class ',' param_class
                ;

global_variables:
                | BGINGLOBAL global_variables_list ENDGLOBAL
                ;

global_variables_list :     
	      |  global_variables_list decl ';'   
	      ;

decl:  TYPE ID { 
                    if(!ids.existsVar($2)) 
                    {   //int x;
                        ids.addVar($1,$2,NULL,NULL,NULL,false);
                    }
               }
       ;
       
functions:
          | BGINFUNC functions_list ENDFUNC
          ;

functions_list :     
	      |  functions_list decl_func 
	      ;

decl_func  : TYPE ID '(' list_param ')' '{' list1 '}'      //int cmmdc(int param) { }
              {
                altscope = scope; 
                scope = $2; 
            
                if (fs.existsFunction(scope.c_str())) {
                    yyerror("Function redefinition");
                } else {
                    FunctionInfo funcInfo;
                    funcInfo.name = $2;
                    funcInfo.returnType = $1;
                    funcInfo.parameters= $4->parameters;
                    
                    fs.addFunction(funcInfo);
                 }
                scope = altscope; // restore
              } 
           |TYPE ID '(' ')' '{' list1 '}'                 //int cmmdc( ) { }
              {
                altscope = scope; 
                scope = $2; 

                if (fs.existsFunction(scope.c_str())) {
                    yyerror("Function redefinition");
                } else {
                    FunctionInfo funcInfo;
                    funcInfo.name = $2;
                    funcInfo.returnType = $1;
                    fs.addFunction(funcInfo);
                 }
                scope = altscope; // restore
              } 
           ;

list_param : param    {
                         $$=new FunctionInfo;
                         $$->parameters.push_back(*$1);
                      }
            | list_param ','  param {
                                    $$->parameters.push_back(*$3);
                                    }
            ;        

param : TYPE ID {
                     $$ = new ParamInfo;    
                     $$->type = $1;
                     $$->name = $2;
                }
      ;  

           
list1: list1 statement1 ';'
     | list1 IF '(' expr ')' '{' list1 '}'
     | list1 IF '(' expr ')' '{' list1 '}' ELSE '{' list1 '}' 
     | list1 WHILE '(' expr ')' '{' list '}'
     | list1 FOR '(' expr_for ')' '{' list '}'
     |
     ;

statement1: TYPE ID
          |ID ASSIGN ID
          |ID ASSIGN INT
          |ID ASSIGN FLOAT
          |ID ASSIGN STRING
          |ID ASSIGN CHAR
          |ID ASSIGN BOOL
          |CONST ID ASSIGN INT
          ;
          
expr: op GT op
    | op LT op
    | op GE op
    | op LE op
    | op EQ op
    | op NEQ op
    ;

expr_for: ID ASSIGN INT ';' ID LT INT ';' ID '+'
    | ID ASSIGN INT ';' ID LE INT ';' ID '+'
    | ID ASSIGN INT ';' ID GT INT ';' ID '-'
    | ID ASSIGN INT ';' ID GE INT ';' ID '-'
    ;

op : ID 
   | INT 
   | FLOAT 
   | BOOL
   ;

main : BGINMAIN list ENDMAIN 
     ;
     
     
list : list statement ';'
     | list IF '(' expression ')' '{' list '}'  {
                                                    if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                                                        {
                                                            yyerror("'if' accepts only boolean expressions");
                                                        }
                                                }
     | list IF '(' expression ')' '{' list '}' ELSE '{' list '}' {
                                                                       if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                                                                            {
                                                                                yyerror("'if' accepts only boolean expressions");
                                                                            }
                                                                 }
     | list WHILE '(' expression ')' '{' list '}' {
                                                        if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                                                            {
                                                                 yyerror("'while' accepts only boolean expressions");
                                                            }
                                                  }
     | list FOR '(' expr_for ')' '{' list '}' 
     | 
     ;
     
statement: declarations
         | assignments
         | statement_eval
         | TYPEOF statement_typeof
        |ID '(' list_param_call ')' {
            FunctionInfo *func = fs.getFunction($1); // presupunem că există o metodă getFunction care returnează informații despre funcția cu numele dat
            if (func == nullptr) {
                yyerror(("Undefined function: " + std::string($1)).c_str());
            } else {
                if (func->parameters.size() != $3->parameters.size()) {
                    yyerror(("Incorrect number of arguments for function: " + std::string($1)).c_str());
                } else {
                    for (size_t i = 0; i < func->parameters.size(); ++i) {
                        if (func->parameters[i].type != $3->parameters[i].type) {
                            yyerror(("Argument type mismatch in function " + std::string($1) + " for parameter " + std::to_string(i+1) + ": expected " + func->parameters[i].type + ", got " + $3->parameters[i].type).c_str());
                        }
                    }
                }
            }
        }
         // de comparat vectorul din function table cu vectorul din $3->parameters si de vazut daca pe aceleasi pozitii sunt aceleasi tipuri
         ;

statement_eval: eval {
                         cout << "Eval value: " << ast.evaluateTree() << endl; ast.printTree(); 
                     }
                     ;
                     
statement_typeof: expression {  
                                cout << "TypeOf value: ";
                                string resultValue = ast.evaluateTree();

                                // Assuming your evaluateTree() function returns a string representation of the result

                                if (isInteger(resultValue)) {
                                    cout << "Integer" << endl;
                                } else if (isFloat(resultValue)) {
                                    cout << "Float" << endl;
                                } else if (isBoolean(resultValue)) {
                                    cout << "Boolean" << endl;
                                } else {
                                    cout << "Unknown" << endl;
                                }

                                ast.printTree();         
                             }
                             ;
                             
list_param_call: list_param_call  ',' param_call{
                                    $$->parameters.push_back(*$3);
                                    }
               | param_call {
                         $$=new FunctionInfo;
                         $$->parameters.push_back(*$1);
                      }
               ;

param_call: INT     { $$=new ParamInfo; $$->type="int"; }
          | FLOAT  { $$=new ParamInfo; $$->type="float"; }
          | BOOL  { $$=new ParamInfo; $$->type="bool"; }
          | ID      { 
            if(!ids.existsVar($1)){string err="Variable '"+string($1)+"' was not declared!"; yyerror(err.c_str());}
            else {$$=new ParamInfo; $$->type=ids.TypeOf($1);}       
                    }
          ;

declarations:TYPE ID {   //int x; float y; bool z; char c; string str;
                        if(!ids.existsVar($2))   
                            {    
                                ids.addVar($1,$2,NULL,NULL,NULL,false);
                            }
                     }                   
            | TYPE ID '[' INT ']' ASSIGN '{' array_list '}' 
                            {
                                char* token = strtok($8, " ");
                                int index = 0;
                                while (token != NULL) 
                                    {
                                        if (token[0] != '\0') 
                                            {
                                                ids.addVar($1, (string($2) + "[" + to_string(index) + "]").c_str(), token, NULL, NULL, false);
                                                index++;
                                                if(index>$4)
                                                    {   
                                                        string err="Array's '"+string($2)+"' max size is: "+to_string($4);
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        token = strtok(NULL, " ");
                                    }
                            }
                            ;

array_list : array_list ',' INT 
                {
                     $$ = (char*)malloc(strlen($1) + strlen(to_string($3).c_str()) + 2); // +2 for the space and null terminator
                     strcpy($$, $1);
                     strcat($$, to_string($3).c_str());
                     strcat($$, " ");
                }
            |array_list ',' FLOAT 
                {
                     $$ = (char*)malloc(strlen($1) + strlen(to_string($3).c_str()) + 2); // +2 for the space and null terminator
                     strcpy($$, $1);
                     strcat($$, to_string($3).c_str());
                     strcat($$, " ");
                }
            | INT 
                {
                     $$ = strdup(to_string($1).c_str()); strcat($$," ");
                }
            | FLOAT 
                {
                     $$ = strdup(to_string($1).c_str()); strcat($$," ");
                }
                ;
          
  
assignments : ID ASSIGN ID
                        {    
                              if(!ids.existsVar($1))
                                    { 
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(!ids.existsVar($3))
                                    { 
                                        string err="Variable '"+string($3)+"' was not declared ";   
                                        yyerror(err.c_str());
                                    }
                              else if(ids.TypeOf($1)!=ids.TypeOf($3)) 
                                    {   
                                        string err="Variables '"+string($1)+"' and '"+string($3)+"' have different types";    
                                        yyerror(err.c_str());
                                    }
                              else  { //x:=y;
                                        string val=ids.get_val($3);
                                        ids.addVal($1,val.c_str());
                                    }     
                        }
                |ID ASSIGN INT 
                        { 
                              if(!ids.existsVar($1))
                                    {
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf($1)!="int")
                                    {
                                        string err="Cannot assign 'int' to an '"+ids.TypeOf($1)+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal($1,to_string($3).c_str());
                                    }             
                        } 
           |ID ASSIGN FLOAT     
                        { 
                              if(!ids.existsVar($1))
                                    { 
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf($1)!="float")
                                    {
                                        string err="Cannot assign 'float' to an '"+ids.TypeOf($1)+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal($1,to_string($3).c_str());
                                    }             
                        }
           |ID ASSIGN BOOL 
                        {   
                              if(!ids.existsVar($1))
                                    {
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf($1)!="bool")
                                    {
                                        string err="Cannot assign 'bool' to an'"+ids.TypeOf($1)+"''";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal($1,to_string($3).c_str()? "true" : "false");
                                    }             
                        }
           |ID ASSIGN CHAR 
                        { 
                              if(!ids.existsVar($1))
                                    { 
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf($1)!="char")
                                    {
                                        string err="Cannot assign 'char' to an '"+ids.TypeOf($1)+"''";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        string str(1,$3);ids.addVal($1,str.c_str());
                                    }             
                        }
           |ID ASSIGN STRING 
                        {   
                              if(!ids.existsVar($1))
                                    { 
                                        string err="Variable '"+string($1)+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf($1)!="string")
                                    {
                                        string err="Cannot assign 'string' to an'"+ids.TypeOf($1)+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal($1,$3);
                                    }             
                        }
           |ID '[' INT ']' ASSIGN INT  
                        {
                              string id=string($1)+"["+to_string($3)+"]";
                              if(!ids.existsVar(id.c_str()))
                                    {
                                         string err="Variable '"+ string(id.c_str())+"' was not declared ";
                                         yyerror(err.c_str());
                                    }
                              if(ids.TypeOf(id.c_str())!="int")
                                    {
                                         string err="Cannot assign 'int' to an '"+ids.TypeOf(id.c_str())+"'";
                                         yyerror(err.c_str());
                                    }
                              else  {
                                         ids.addVal(id.c_str(),to_string($6).c_str());
                                    }
                        }
           | CONST TYPE ID 
                    { yyerror("Constant must have value assigned at declaration!");}
           | CONST TYPE ID ASSIGN INT 
                                    {   
                                         if(!ids.existsVar($3))   
                                             {        
                                                if(strcmp($2,"int")==0)
                                                    {
                                                        ids.addVar($2,$3,to_string($5).c_str(),NULL,NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string($3) + " has type " + $2 + ", assigned value has type int"; 
                                                        yyerror(err.c_str());
                                                    }
                                             }                    
                                         else 
                                             {  
                                                yyerror("variable already declared");
                                             }
                                    }
          | CONST TYPE ID ASSIGN FLOAT 
                                    {   
                                        if(!ids.existsVar($3))   
                                            {   
                                                if(strcmp($2,"float")==0)
                                                    {
                                                        ids.addVar($2,$3,to_string($5).c_str(),NULL,NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string($2) + " has type " + $2 + ", assigned value has type float"; 
                                                        yyerror(err.c_str());
                                                    }
                                            }                    
                                        else 
                                            {  
                                                yyerror("variable already declared");
                                            }    

                                    }
          |CONST TYPE ID ASSIGN BOOL 
                                    { 
                                        if (!ids.existsVar($3)) 
                                            {
                                                if (strcmp($2, "bool") == 0) 
                                                    {
                                                        ids.addVar($2, $3, $5 ? "true" : "false", NULL, NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string($3) + " has type " + $2 + ", assigned value has type bool";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }
                                    }
          |CONST TYPE ID ASSIGN CHAR 
                                    {
                                        if (!ids.existsVar($3)) 
                                            {
                                                if (strcmp($2, "char") == 0) 
                                                    {
                                                        string str(1,$5);
                                                        ids.addVar($2, $3, str.c_str(), NULL, NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string($3) + " has type " + $2 + ", assigned value has type char";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }
                                    }
          |CONST TYPE ID ASSIGN STRING
                                    {
                                        if (!ids.existsVar($3)) 
                                            {
                                                if (strcmp($2, "string") == 0) 
                                                    {
                                                        ids.addVar($2, $3, $5, NULL, NULL,true);
                                                    } 
                                                else 
                                                    {
                                                        string err = "Constant " + string($3) + " has type " + $2 + ", assigned value has type string";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }                                            
                                    }           
                                    ;


eval : EVAL '(' expression ')'   //Eval
        {
           $$ = $3;  
        }
        ;
        
expression : expression '+' expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            {
                                string err="Operands have different types! '"+$1->type+"' + '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                        $$ = new Node { $1, $3, "+",$1->type }; 
                        ast.AddNode("+",$1,$3,$1->type);
                    }
           | expression '-' expression  
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                            { 
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type) 
                            {
                                string err="Operands have different types! '"+$1->type+"' - '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                        $$ = new Node { $1, $3, "-",$1->type }; 
                        ast.AddNode("-",$1,$3,$1->type);
                    }
           | expression '*' expression  
                    { 
                        if($1->type=="bool"||$3->type=="bool")  
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            {
                                string err="Operands have different types! '"+$1->type+"' * '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                        $$ = new Node { $1, $3, "*",$1->type }; 
                        ast.AddNode("*",$1,$3,$1->type);
                    }
           | expression '/' expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            {   
                                string err="Operands have different types! '"+$1->type+"' / '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                        $$ = new Node { $1, $3, "/",$1->type }; 
                        ast.AddNode("/",$1,$3,$1->type);}
           | expression '^' expression 
                   { 
                        if($1->type=="bool"||$3->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            {
                                string err="Operands have different types! '"+$1->type+"' ^ '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                        $$ = new Node{$1, $3, "^",$1->type}; 
                        ast.AddNode("^",$1,$3,$1->type);
                    }
           | expression AND expression
                   {
                        if($1->type=="int"||$1->type=="float"||$3->type=="int"||$3->type=="float")
                            {
                                string err="Operation && only supports bool operands ! '"+$1->type+"' && '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                            $$ = new Node{$1, $3,"&&",$1->type}; 
                            ast.AddNode("&&",$1,$3,$1->type);
                    }
           | expression OR expression
                   {
                         if($1->type=="int"||$1->type=="float"||$3->type=="int"||$3->type=="float")
                            {
                                string err="Operation || only supports bool operands ! '"+$1->type+"' || '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                            $$ = new Node{$1, $3,"||",$1->type}; 
                            ast.AddNode("||",$1,$3,$1->type);
                    }
           | NOT expression
                    {
                        if($2->type=="int"||$2->type=="float")
                            {
                                string err="Operation ! only supports bool operand! !'"+$2->type+"''";
                                yyerror(err.c_str());
                            }
                            $$ = new Node{$2, NULL,"!",$2->type}; 
                            ast.AddNode("!",$2,NULL,$2->type); }
           | expression LT expression
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            { 
                                string err="Operands have different types! '"+$1->type+"' < '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                            $$ = new Node{$1, $3, "<","bool"}; 
                            ast.AddNode("<",$1,$3,"bool");}
           | expression LE expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                            { 
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if($1->type!=$3->type)
                            {
                                string err="Operands have different types! '"+$1->type+"' <= '"+$3->type+"'";
                                yyerror(err.c_str());
                            }
                            $$ = new Node{$1, $3, "<=","bool"}; 
                            ast.AddNode("<=",$1,$3,"bool");}
           | expression GT expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if($1->type!=$3->type)
                        {
                            string err="Operands have different types! '"+$1->type+"' > '"+$3->type+"'";
                            yyerror(err.c_str());
                        }
                        $$ = new Node{$1, $3, ">","bool"}; 
                        ast.AddNode(">",$1,$3,"bool");}
           | expression GE expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if($1->type!=$3->type)
                        {
                            string err="Operands have different types! '"+$1->type+"' >= '"+$3->type+"'";
                            yyerror(err.c_str());
                        }
                        $$ = new Node{$1, $3, ">=","bool"}; 
                        ast.AddNode(">=",$1,$3,"bool");}
           | expression EQ expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if($1->type!=$3->type)
                        {
                            string err="Operands have different types! '"+$1->type+"' == '"+$3->type+"'";
                            yyerror(err.c_str());
                        }
                        $$ = new Node{$1, $3, "==","bool"}; 
                        ast.AddNode("==",$1,$3,"bool");
                    }
           | expression NEQ expression 
                    { 
                        if($1->type=="bool"||$3->type=="bool")
                        {
                            yyerror("Cannot perform mathematical operations on type 'bool'");
                        }
                        if($1->type!=$3->type)
                        {
                            string err="Operands have different types! '"+$1->type+"' != '"+$3->type+"'";
                            yyerror(err.c_str());
                        }
                        $$ = new Node{$1, $3, "!=","bool"}; 
                        ast.AddNode("!=",$1,$3,"bool");}
           | '(' expression ')'
                        {
                            $$=$2;
                        }
           | INT   
                        { 
                            $$ = new Node{NULL, NULL, to_string($1),"int"}; 
                            ast.AddNode(to_string($1),NULL,NULL,"int");
                        }
           | FLOAT 
                        {
                            $$=new Node{NULL,NULL,to_string($1),"float"};
                            ast.AddNode(to_string($1),NULL,NULL,"float");
                        }
           | BOOL      
                        {
                            $$=new Node{NULL,NULL,$1?"true":"false","bool"};
                            ast.AddNode($1?"true":"false",NULL,NULL,"bool");
                        }
           | ID
                        {
                        if(!ids.existsVar($1))
                            {
                                string err="Variable '"+string($1)+"' was not declared!";
                                yyerror(err.c_str());
                            }
                        $$=new Node{NULL,NULL,ids.get_val($1),ids.TypeOf($1)}; 
                        ast.AddNode(ids.get_val($1),NULL,NULL,ids.TypeOf($1));
                        }
           ;




%%

void yyerror(const char * s)
    {
        printf("error: %s line:%d\n",s,yylineno);
    }  

int main(int argc, char** argv)
{
     yyin=fopen(argv[1],"r");
     yyparse();
} 
