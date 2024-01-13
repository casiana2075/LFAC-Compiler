/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "limbaj.y"


#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include "AST.h"
#include "IdList.h"
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


#line 124 "limbaj.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BGINPROGR = 3,                  /* BGINPROGR  */
  YYSYMBOL_ENDPROGR = 4,                   /* ENDPROGR  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_BGINCLASS = 6,                  /* BGINCLASS  */
  YYSYMBOL_ENDCLASS = 7,                   /* ENDCLASS  */
  YYSYMBOL_CONST = 8,                      /* CONST  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_BGINGLOBAL = 12,                /* BGINGLOBAL  */
  YYSYMBOL_ENDGLOBAL = 13,                 /* ENDGLOBAL  */
  YYSYMBOL_BGINFUNC = 14,                  /* BGINFUNC  */
  YYSYMBOL_ENDFUNC = 15,                   /* ENDFUNC  */
  YYSYMBOL_EVAL = 16,                      /* EVAL  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_GE = 20,                        /* GE  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_NEQ = 22,                       /* NEQ  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_ID = 26,                        /* ID  */
  YYSYMBOL_TYPE = 27,                      /* TYPE  */
  YYSYMBOL_TYPEOF = 28,                    /* TYPEOF  */
  YYSYMBOL_INT = 29,                       /* INT  */
  YYSYMBOL_FLOAT = 30,                     /* FLOAT  */
  YYSYMBOL_BOOL = 31,                      /* BOOL  */
  YYSYMBOL_CHAR = 32,                      /* CHAR  */
  YYSYMBOL_STRING = 33,                    /* STRING  */
  YYSYMBOL_CLASS = 34,                     /* CLASS  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '^'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_progr = 50,                     /* progr  */
  YYSYMBOL_user_defined_data_types = 51,   /* user_defined_data_types  */
  YYSYMBOL_class_list = 52,                /* class_list  */
  YYSYMBOL_clasa = 53,                     /* clasa  */
  YYSYMBOL_list_class_fields = 54,         /* list_class_fields  */
  YYSYMBOL_methods = 55,                   /* methods  */
  YYSYMBOL_param = 56,                     /* param  */
  YYSYMBOL_global_variables = 57,          /* global_variables  */
  YYSYMBOL_global_variables_list = 58,     /* global_variables_list  */
  YYSYMBOL_decl = 59,                      /* decl  */
  YYSYMBOL_functions = 60,                 /* functions  */
  YYSYMBOL_functions_list = 61,            /* functions_list  */
  YYSYMBOL_decl_func = 62,                 /* decl_func  */
  YYSYMBOL_list1 = 63,                     /* list1  */
  YYSYMBOL_statement1 = 64,                /* statement1  */
  YYSYMBOL_expr = 65,                      /* expr  */
  YYSYMBOL_op = 66,                        /* op  */
  YYSYMBOL_list_param = 67,                /* list_param  */
  YYSYMBOL_main = 68,                      /* main  */
  YYSYMBOL_list = 69,                      /* list  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_statement_eval = 71,            /* statement_eval  */
  YYSYMBOL_statement_typeof = 72,          /* statement_typeof  */
  YYSYMBOL_list_param_call = 73,           /* list_param_call  */
  YYSYMBOL_param_call = 74,                /* param_call  */
  YYSYMBOL_declarations = 75,              /* declarations  */
  YYSYMBOL_array_list = 76,                /* array_list  */
  YYSYMBOL_assignments = 77,               /* assignments  */
  YYSYMBOL_eval = 78,                      /* eval  */
  YYSYMBOL_expression = 79                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,    37,    35,    48,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
      47,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    93,    94,    97,    98,   101,   104,   105,
     108,   109,   112,   115,   116,   119,   120,   123,   131,   132,
     135,   136,   139,   140,   141,   144,   145,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   161,   164,
     165,   166,   167,   170,   171,   174,   178,   179,   185,   191,
     197,   200,   201,   202,   203,   204,   207,   212,   232,   233,
     236,   237,   238,   239,   242,   248,   269,   276,   283,   287,
     294,   316,   332,   348,   364,   380,   396,   413,   414,   416,
     435,   455,   474,   494,   516,   522,   536,   550,   564,   577,
     582,   587,   592,   597,   602,   607,   612,   617,   622,   627,
     628,   629,   630,   631
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BGINPROGR",
  "ENDPROGR", "ASSIGN", "BGINCLASS", "ENDCLASS", "CONST", "IF", "ELSE",
  "WHILE", "BGINGLOBAL", "ENDGLOBAL", "BGINFUNC", "ENDFUNC", "EVAL", "LT",
  "LE", "GT", "GE", "EQ", "NEQ", "AND", "OR", "NOT", "ID", "TYPE",
  "TYPEOF", "INT", "FLOAT", "BOOL", "CHAR", "STRING", "CLASS", "'+'",
  "'-'", "'*'", "'/'", "'^'", "'('", "')'", "'['", "']'", "'{'", "'}'",
  "';'", "'<'", "','", "$accept", "progr", "user_defined_data_types",
  "class_list", "clasa", "list_class_fields", "methods", "param",
  "global_variables", "global_variables_list", "decl", "functions",
  "functions_list", "decl_func", "list1", "statement1", "expr", "op",
  "list_param", "main", "list", "statement", "statement_eval",
  "statement_typeof", "list_param_call", "param_call", "declarations",
  "array_list", "assignments", "eval", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,  -141,    10,    17,    11,  -141,  -141,     9,  -141,     1,
    -141,    -5,  -141,    30,     7,  -141,    41,    25,    23,  -141,
    -141,  -141,  -141,  -141,  -141,    43,    52,   209,    48,    62,
    -141,  -141,    80,    71,    73,    98,     6,   117,    34,    99,
    -141,  -141,  -141,  -141,   118,   120,   126,    31,   148,    34,
      34,    34,   258,    50,   151,   156,    34,  -141,  -141,  -141,
    -141,    34,  -141,   210,  -141,   159,   161,  -141,   179,   171,
    -141,    20,   211,   132,   140,   165,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,   178,   174,   180,   192,
    -141,   173,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,   197,  -141,  -141,  -141,   182,
     197,   245,   222,   223,  -141,   219,    50,   268,   242,  -141,
     265,   265,   265,   265,   244,   244,   233,   221,   102,   102,
     247,   247,  -141,    29,     8,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,   -25,   288,   250,   279,
     267,   269,   301,   282,  -141,   264,    92,    -2,     4,  -141,
    -141,   270,  -141,   306,    91,    91,   266,  -141,  -141,  -141,
     302,  -141,    96,    97,   284,  -141,  -141,  -141,  -141,   274,
     271,   275,  -141,  -141,  -141,  -141,  -141,  -141,   273,  -141,
    -141,    86,  -141,  -141,   276,    91,   277,  -141,  -141,   106,
    -141,  -141,  -141,    28,  -141,  -141,   101,    88,  -141,   309,
    -141,   278,  -141,   121,  -141
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     5,     0,    13,     0,     1,    15,    18,     4,     0,
       6,     0,    20,     0,     0,    14,     0,     0,    22,    50,
       2,     9,    17,    16,    19,     0,     0,     0,    11,     0,
      21,    45,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    51,    52,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,     0,   103,   100,   101,
     102,     0,    54,    57,    46,    12,     0,     8,     0,     0,
      43,     0,    78,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    63,    60,    61,    62,     0,    59,     0,     0,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,    12,    26,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,    99,
      93,    94,    95,    96,    97,    98,    90,    91,    85,    86,
      87,    88,    89,     0,     0,    26,    44,    79,    80,    81,
      82,    83,    50,    50,    55,    58,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     0,     0,    76,
      77,     0,    26,     0,     0,     0,     0,    27,    25,    23,
      47,    49,     0,     0,     0,    39,    40,    41,    42,     0,
       0,     0,    28,    29,    30,    33,    32,    31,     0,    68,
      69,     0,    10,    34,     0,     0,     0,    50,    65,     0,
      26,    38,    50,     0,    66,    67,     0,     0,    48,    35,
      37,     0,    26,     0,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,  -141,  -141,  -141,   -28,  -141,  -141,
    -141,  -141,  -141,  -141,  -134,  -141,   158,   129,   220,  -141,
    -140,  -141,  -141,  -141,   212,  -141,  -141,  -141,  -141,  -141,
      -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    10,    28,    45,    70,     7,    11,
      17,    13,    18,    26,   134,   155,   179,   180,    71,    20,
      27,    39,    40,    62,    86,    87,    41,   191,    42,    43,
      63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,   156,   157,   158,   159,   160,    32,    33,    15,    34,
       5,    52,    32,    33,    35,    34,   149,   150,     8,   151,
      35,     1,    16,    12,    36,    37,    38,    14,   173,     6,
      36,    37,    38,    19,   152,   153,    32,    33,    24,    34,
      73,    74,    75,   170,    35,     9,    53,    90,    54,   171,
      25,    21,    91,   154,    36,    37,    38,   203,    68,    56,
      57,   109,   207,    58,    59,    60,   206,    22,   110,    29,
     148,    23,    69,   208,    61,    44,    82,   110,   213,    83,
      84,    85,   136,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    32,    33,    30,    34,
     149,   150,    47,   151,    35,   149,   150,    48,   151,   149,
     150,    49,   151,    50,    36,    37,    38,   175,   152,   153,
     176,   177,   178,   152,   153,   189,   190,   152,   153,   149,
     150,   198,   151,   210,   199,   204,   205,   169,    51,   102,
     103,   104,   192,    55,    65,    64,   209,   152,   153,    92,
      93,    94,    95,    96,    97,    98,    99,    92,    93,    94,
      95,    96,    97,    98,    99,    66,   214,   100,   101,   102,
     103,   104,    67,   112,    72,   100,   101,   102,   103,   104,
      88,   113,    92,    93,    94,    95,    96,    97,    98,    99,
      92,    93,    94,    95,    96,    97,    98,    99,    89,   105,
     100,   101,   102,   103,   104,   107,   114,   106,   100,   101,
     102,   103,   104,    31,   119,   108,   111,    32,    33,   115,
      34,   118,   116,   117,    68,    35,   135,    92,    93,    94,
      95,    96,    97,    98,    99,    36,    37,    38,    92,    93,
      94,    95,    96,    97,    98,   100,   101,   102,   103,   104,
      92,    93,    94,    95,    96,    97,   100,   101,   102,   103,
     104,    92,    93,    94,    95,   144,   142,   143,   100,   101,
     102,   103,   104,   146,   137,   138,   139,   140,   141,   100,
     101,   102,   103,   104,    76,   147,   104,    77,    78,    79,
      80,    81,   182,   161,   162,   183,   184,   185,   186,   187,
     100,   101,   102,   103,   104,   163,   166,   164,   167,   165,
     168,   174,   188,   193,   172,   194,   196,   197,   195,   211,
     200,   202,   212,   181,   201,   133,     0,     0,   145
};

static const yytype_int16 yycheck[] =
{
      28,   135,   142,   143,    29,    30,     8,     9,    13,    11,
       0,     5,     8,     9,    16,    11,     8,     9,     7,    11,
      16,     6,    27,    14,    26,    27,    28,    26,   162,    12,
      26,    27,    28,     3,    26,    27,     8,     9,    15,    11,
      49,    50,    51,    45,    16,    34,    40,    56,    42,    45,
      27,    44,    61,    45,    26,    27,    28,   197,    27,    25,
      26,    41,   202,    29,    30,    31,   200,    26,    48,    26,
      41,    46,    41,    45,    40,    27,    26,    48,   212,    29,
      30,    31,   110,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     8,     9,    46,    11,
       8,     9,    40,    11,    16,     8,     9,    27,    11,     8,
       9,    40,    11,    40,    26,    27,    28,    26,    26,    27,
      29,    30,    31,    26,    27,    29,    30,    26,    27,     8,
       9,    45,    11,    45,    48,    29,    30,    45,    40,    37,
      38,    39,    45,    26,    26,    46,    45,    26,    27,    17,
      18,    19,    20,    21,    22,    23,    24,    17,    18,    19,
      20,    21,    22,    23,    24,    45,    45,    35,    36,    37,
      38,    39,    46,    41,    26,    35,    36,    37,    38,    39,
      29,    41,    17,    18,    19,    20,    21,    22,    23,    24,
      17,    18,    19,    20,    21,    22,    23,    24,    42,    40,
      35,    36,    37,    38,    39,    26,    41,    46,    35,    36,
      37,    38,    39,     4,    41,    44,     5,     8,     9,    41,
      11,    29,    48,    43,    27,    16,    44,    17,    18,    19,
      20,    21,    22,    23,    24,    26,    27,    28,    17,    18,
      19,    20,    21,    22,    23,    35,    36,    37,    38,    39,
      17,    18,    19,    20,    21,    22,    35,    36,    37,    38,
      39,    17,    18,    19,    20,    46,    44,    44,    35,    36,
      37,    38,    39,     5,    29,    30,    31,    32,    33,    35,
      36,    37,    38,    39,    26,    43,    39,    29,    30,    31,
      32,    33,    26,     5,    44,    29,    30,    31,    32,    33,
      35,    36,    37,    38,    39,    26,     5,    40,    26,    40,
      46,     5,    10,    29,    44,    41,    41,    44,    47,    10,
      44,    44,    44,   165,   195,   105,    -1,    -1,   116
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    50,    51,    52,     0,    12,    57,     7,    34,
      53,    58,    14,    60,    26,    13,    27,    59,    61,     3,
      68,    44,    26,    46,    15,    27,    62,    69,    54,    26,
      46,     4,     8,     9,    11,    16,    26,    27,    28,    70,
      71,    75,    77,    78,    27,    55,    56,    40,    27,    40,
      40,    40,     5,    40,    42,    26,    25,    26,    29,    30,
      31,    40,    72,    79,    46,    26,    45,    46,    27,    41,
      56,    67,    26,    79,    79,    79,    26,    29,    30,    31,
      32,    33,    26,    29,    30,    31,    73,    74,    29,    42,
      79,    79,    17,    18,    19,    20,    21,    22,    23,    24,
      35,    36,    37,    38,    39,    40,    46,    26,    44,    41,
      48,     5,    41,    41,    41,    41,    48,    43,    29,    41,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    67,    63,    44,    56,    29,    30,    31,
      32,    33,    44,    44,    46,    73,     5,    43,    41,     8,
       9,    11,    26,    27,    45,    64,    63,    69,    69,    29,
      30,     5,    44,    26,    40,    40,     5,    26,    46,    45,
      45,    45,    44,    63,     5,    26,    29,    30,    31,    65,
      66,    65,    26,    29,    30,    31,    32,    33,    10,    29,
      30,    76,    45,    29,    41,    47,    41,    44,    45,    48,
      44,    66,    44,    69,    29,    30,    63,    69,    45,    45,
      45,    10,    44,    63,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    54,    54,
      55,    55,    56,    57,    57,    58,    58,    59,    60,    60,
      61,    61,    62,    62,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    66,
      66,    66,    66,    67,    67,    68,    69,    69,    69,    69,
      69,    70,    70,    70,    70,    70,    71,    72,    73,    73,
      74,    74,    74,    74,    75,    75,    76,    76,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     3,     0,     2,     7,     3,     0,
       8,     0,     2,     0,     3,     0,     3,     2,     0,     3,
       0,     3,     0,     8,     7,     3,     0,     2,     3,     3,
       3,     3,     3,     3,     4,     7,    11,     7,     3,     1,
       1,     1,     1,     1,     3,     3,     3,     8,    12,     8,
       0,     1,     1,     1,     2,     5,     1,     1,     3,     1,
       1,     1,     1,     1,     2,     9,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     6,     6,     3,     5,
       5,     5,     5,     5,     4,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* progr: user_defined_data_types global_variables functions main  */
#line 88 "limbaj.y"
                                                               { 
                                                                    cout <<"The program is correct!\n";
                                                                    ids.printVars();
                                                               }
#line 1356 "limbaj.tab.c"
    break;

  case 17: /* decl: TYPE ID  */
#line 123 "limbaj.y"
               { 
                    if(!ids.existsVar((yyvsp[0].string))) 
                    {   //int x;
                        ids.addVar((yyvsp[-1].string),(yyvsp[0].string),NULL,NULL,NULL,false);
                    }
               }
#line 1367 "limbaj.tab.c"
    break;

  case 38: /* expr: op '<' op  */
#line 161 "limbaj.y"
                { }
#line 1373 "limbaj.tab.c"
    break;

  case 47: /* list: list IF '(' expression ')' '{' list '}'  */
#line 179 "limbaj.y"
                                                {
                                                    if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                                                        {
                                                            yyerror("'if' accepts only boolean expressions");
                                                        }
                                                }
#line 1384 "limbaj.tab.c"
    break;

  case 48: /* list: list IF '(' expression ')' '{' list '}' ELSE '{' list '}'  */
#line 185 "limbaj.y"
                                                                 {
                                                                       if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                                                                            {
                                                                                yyerror("'if' accepts only boolean expressions");
                                                                            }
                                                                 }
#line 1395 "limbaj.tab.c"
    break;

  case 49: /* list: list WHILE '(' expression ')' '{' list '}'  */
#line 191 "limbaj.y"
                                                  {
                                                        if (ast.evaluateTree()!="true"&&ast.evaluateTree()!="false")
                                                            {
                                                                 yyerror("'while' accepts only boolean expressions");
                                                            }
                                                  }
#line 1406 "limbaj.tab.c"
    break;

  case 56: /* statement_eval: eval  */
#line 207 "limbaj.y"
                     {
                         cout << "Eval value: " << ast.evaluateTree() << endl; ast.printTree(); 
                     }
#line 1414 "limbaj.tab.c"
    break;

  case 57: /* statement_typeof: expression  */
#line 212 "limbaj.y"
                             {  
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
#line 1437 "limbaj.tab.c"
    break;

  case 64: /* declarations: TYPE ID  */
#line 242 "limbaj.y"
                     {   //int x; float y; bool z; char c; string str;
                        if(!ids.existsVar((yyvsp[0].string)))   
                            {    
                                ids.addVar((yyvsp[-1].string),(yyvsp[0].string),NULL,NULL,NULL,false);
                            }
                     }
#line 1448 "limbaj.tab.c"
    break;

  case 65: /* declarations: TYPE ID '[' INT ']' ASSIGN '{' array_list '}'  */
#line 249 "limbaj.y"
                            {
                                char* token = strtok((yyvsp[-1].string), " ");
                                int index = 0;
                                while (token != NULL) 
                                    {
                                        if (token[0] != '\0') 
                                            {
                                                ids.addVar((yyvsp[-8].string), (string((yyvsp[-7].string)) + "[" + to_string(index) + "]").c_str(), token, NULL, NULL, false);
                                                index++;
                                                if(index>(yyvsp[-5].num))
                                                    {   
                                                        string err="Array's '"+string((yyvsp[-7].string))+"' max size is: "+to_string((yyvsp[-5].num));
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        token = strtok(NULL, " ");
                                    }
                            }
#line 1471 "limbaj.tab.c"
    break;

  case 66: /* array_list: array_list ',' INT  */
#line 270 "limbaj.y"
                {
                     (yyval.string) = (char*)malloc(strlen((yyvsp[-2].string)) + strlen(to_string((yyvsp[0].num)).c_str()) + 2); // +2 for the space and null terminator
                     strcpy((yyval.string), (yyvsp[-2].string));
                     strcat((yyval.string), to_string((yyvsp[0].num)).c_str());
                     strcat((yyval.string), " ");
                }
#line 1482 "limbaj.tab.c"
    break;

  case 67: /* array_list: array_list ',' FLOAT  */
#line 277 "limbaj.y"
                {
                     (yyval.string) = (char*)malloc(strlen((yyvsp[-2].string)) + strlen(to_string((yyvsp[0].num_cu_pct)).c_str()) + 2); // +2 for the space and null terminator
                     strcpy((yyval.string), (yyvsp[-2].string));
                     strcat((yyval.string), to_string((yyvsp[0].num_cu_pct)).c_str());
                     strcat((yyval.string), " ");
                }
#line 1493 "limbaj.tab.c"
    break;

  case 68: /* array_list: INT  */
#line 284 "limbaj.y"
                {
                     (yyval.string) = strdup(to_string((yyvsp[0].num)).c_str()); strcat((yyval.string)," ");
                }
#line 1501 "limbaj.tab.c"
    break;

  case 69: /* array_list: FLOAT  */
#line 288 "limbaj.y"
                {
                     (yyval.string) = strdup(to_string((yyvsp[0].num_cu_pct)).c_str()); strcat((yyval.string)," ");
                }
#line 1509 "limbaj.tab.c"
    break;

  case 70: /* assignments: ID ASSIGN ID  */
#line 295 "limbaj.y"
                        {    
                              if(!ids.existsVar((yyvsp[-2].string)))
                                    { 
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              else if(!ids.existsVar((yyvsp[0].string)))
                                    { 
                                        string err="Variable '"+string((yyvsp[0].string))+"' was not declared ";   
                                        yyerror(err.c_str());
                                    }
                              else if(ids.TypeOf((yyvsp[-2].string))!=ids.TypeOf((yyvsp[0].string))) 
                                    {   
                                        string err="Variables '"+string((yyvsp[-2].string))+"' and '"+string((yyvsp[0].string))+"' have different types";    
                                        yyerror(err.c_str());
                                    }
                              else  { //x:=y;
                                        string val=ids.get_val((yyvsp[0].string));
                                        ids.addVal((yyvsp[-2].string),val.c_str());
                                    }     
                        }
#line 1535 "limbaj.tab.c"
    break;

  case 71: /* assignments: ID ASSIGN INT  */
#line 317 "limbaj.y"
                        { 
                              if(!ids.existsVar((yyvsp[-2].string)))
                                    {
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf((yyvsp[-2].string))!="int")
                                    {
                                        string err="Cannot assign 'int' to an '"+ids.TypeOf((yyvsp[-2].string))+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal((yyvsp[-2].string),to_string((yyvsp[0].num)).c_str());
                                    }             
                        }
#line 1555 "limbaj.tab.c"
    break;

  case 72: /* assignments: ID ASSIGN FLOAT  */
#line 333 "limbaj.y"
                        { 
                              if(!ids.existsVar((yyvsp[-2].string)))
                                    { 
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf((yyvsp[-2].string))!="float")
                                    {
                                        string err="Cannot assign 'float' to an '"+ids.TypeOf((yyvsp[-2].string))+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal((yyvsp[-2].string),to_string((yyvsp[0].num_cu_pct)).c_str());
                                    }             
                        }
#line 1575 "limbaj.tab.c"
    break;

  case 73: /* assignments: ID ASSIGN BOOL  */
#line 349 "limbaj.y"
                        {   
                              if(!ids.existsVar((yyvsp[-2].string)))
                                    {
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf((yyvsp[-2].string))!="bool")
                                    {
                                        string err="Cannot assign 'bool' to an'"+ids.TypeOf((yyvsp[-2].string))+"''";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal((yyvsp[-2].string),to_string((yyvsp[0].bul)).c_str()? "true" : "false");
                                    }             
                        }
#line 1595 "limbaj.tab.c"
    break;

  case 74: /* assignments: ID ASSIGN CHAR  */
#line 365 "limbaj.y"
                        { 
                              if(!ids.existsVar((yyvsp[-2].string)))
                                    { 
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf((yyvsp[-2].string))!="char")
                                    {
                                        string err="Cannot assign 'char' to an '"+ids.TypeOf((yyvsp[-2].string))+"''";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        string str(1,(yyvsp[0].chr));ids.addVal((yyvsp[-2].string),str.c_str());
                                    }             
                        }
#line 1615 "limbaj.tab.c"
    break;

  case 75: /* assignments: ID ASSIGN STRING  */
#line 381 "limbaj.y"
                        {   
                              if(!ids.existsVar((yyvsp[-2].string)))
                                    { 
                                        string err="Variable '"+string((yyvsp[-2].string))+"' was not declared ";
                                        yyerror(err.c_str());
                                    }
                              if(ids.TypeOf((yyvsp[-2].string))!="string")
                                    {
                                        string err="Cannot assign 'string' to an'"+ids.TypeOf((yyvsp[-2].string))+"'";
                                        yyerror(err.c_str());
                                    }
                              else  {
                                        ids.addVal((yyvsp[-2].string),(yyvsp[0].string));
                                    }             
                        }
#line 1635 "limbaj.tab.c"
    break;

  case 76: /* assignments: ID '[' INT ']' ASSIGN INT  */
#line 397 "limbaj.y"
                        {
                              string id=string((yyvsp[-5].string))+"["+to_string((yyvsp[-3].num))+"]";
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
                                         ids.addVal(id.c_str(),to_string((yyvsp[0].num)).c_str());
                                    }
                        }
#line 1656 "limbaj.tab.c"
    break;

  case 78: /* assignments: CONST TYPE ID  */
#line 415 "limbaj.y"
                    { yyerror("Constant must have value assigned at declaration!");}
#line 1662 "limbaj.tab.c"
    break;

  case 79: /* assignments: CONST TYPE ID ASSIGN INT  */
#line 417 "limbaj.y"
                                    {   
                                         if(!ids.existsVar((yyvsp[-2].string)))   
                                             {        
                                                if(strcmp((yyvsp[-3].string),"int")==0)
                                                    {
                                                        ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),to_string((yyvsp[0].num)).c_str(),NULL,NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yyvsp[-2].string)) + " has type " + (yyvsp[-3].string) + ", assigned value has type int"; 
                                                        yyerror(err.c_str());
                                                    }
                                             }                    
                                         else 
                                             {  
                                                yyerror("variable already declared");
                                             }
                                    }
#line 1685 "limbaj.tab.c"
    break;

  case 80: /* assignments: CONST TYPE ID ASSIGN FLOAT  */
#line 436 "limbaj.y"
                                    {   
                                        if(!ids.existsVar((yyvsp[-2].string)))   
                                            {   
                                                if(strcmp((yyvsp[-3].string),"float")==0)
                                                    {
                                                        ids.addVar((yyvsp[-3].string),(yyvsp[-2].string),to_string((yyvsp[0].num_cu_pct)).c_str(),NULL,NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yyvsp[-3].string)) + " has type " + (yyvsp[-3].string) + ", assigned value has type float"; 
                                                        yyerror(err.c_str());
                                                    }
                                            }                    
                                        else 
                                            {  
                                                yyerror("variable already declared");
                                            }    

                                    }
#line 1709 "limbaj.tab.c"
    break;

  case 81: /* assignments: CONST TYPE ID ASSIGN BOOL  */
#line 456 "limbaj.y"
                                    { 
                                        if (!ids.existsVar((yyvsp[-2].string))) 
                                            {
                                                if (strcmp((yyvsp[-3].string), "bool") == 0) 
                                                    {
                                                        ids.addVar((yyvsp[-3].string), (yyvsp[-2].string), (yyvsp[0].bul) ? "true" : "false", NULL, NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yyvsp[-2].string)) + " has type " + (yyvsp[-3].string) + ", assigned value has type bool";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }
                                    }
#line 1732 "limbaj.tab.c"
    break;

  case 82: /* assignments: CONST TYPE ID ASSIGN CHAR  */
#line 475 "limbaj.y"
                                    {
                                        if (!ids.existsVar((yyvsp[-2].string))) 
                                            {
                                                if (strcmp((yyvsp[-3].string), "char") == 0) 
                                                    {
                                                        string str(1,(yyvsp[0].chr));
                                                        ids.addVar((yyvsp[-3].string), (yyvsp[-2].string), str.c_str(), NULL, NULL,true);
                                                    }
                                                else 
                                                    {
                                                        string err = "Constant " + string((yyvsp[-2].string)) + " has type " + (yyvsp[-3].string) + ", assigned value has type char";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }
                                    }
#line 1756 "limbaj.tab.c"
    break;

  case 83: /* assignments: CONST TYPE ID ASSIGN STRING  */
#line 495 "limbaj.y"
                                    {
                                        if (!ids.existsVar((yyvsp[-2].string))) 
                                            {
                                                if (strcmp((yyvsp[-3].string), "string") == 0) 
                                                    {
                                                        ids.addVar((yyvsp[-3].string), (yyvsp[-2].string), (yyvsp[0].string), NULL, NULL,true);
                                                    } 
                                                else 
                                                    {
                                                        string err = "Constant " + string((yyvsp[-2].string)) + " has type " + (yyvsp[-3].string) + ", assigned value has type string";
                                                        yyerror(err.c_str());
                                                    }
                                            }
                                        else 
                                            {
                                                yyerror("Variable already declared");
                                            }                                            
                                    }
#line 1779 "limbaj.tab.c"
    break;

  case 84: /* eval: EVAL '(' expression ')'  */
#line 517 "limbaj.y"
        {
           (yyval.nod) = (yyvsp[-1].nod);  
        }
#line 1787 "limbaj.tab.c"
    break;

  case 85: /* expression: expression '+' expression  */
#line 523 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                            {
                                string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' + '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yyval.nod) = new Node { (yyvsp[-2].nod), (yyvsp[0].nod), "+",(yyvsp[-2].nod)->type }; 
                        ast.AddNode("+",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);
                    }
#line 1805 "limbaj.tab.c"
    break;

  case 86: /* expression: expression '-' expression  */
#line 537 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                            { 
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type) 
                            {
                                string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' - '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yyval.nod) = new Node { (yyvsp[-2].nod), (yyvsp[0].nod), "-",(yyvsp[-2].nod)->type }; 
                        ast.AddNode("-",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);
                    }
#line 1823 "limbaj.tab.c"
    break;

  case 87: /* expression: expression '*' expression  */
#line 551 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")  
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                            {
                                string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' * '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yyval.nod) = new Node { (yyvsp[-2].nod), (yyvsp[0].nod), "*",(yyvsp[-2].nod)->type }; 
                        ast.AddNode("*",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);
                    }
#line 1841 "limbaj.tab.c"
    break;

  case 88: /* expression: expression '/' expression  */
#line 565 "limbaj.y"
                    { 
                        if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool")
                            {
                                yyerror("Cannot perform mathematical operations on type 'bool'");
                            }
                        if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type)
                            {   
                                string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' / '"+(yyvsp[0].nod)->type+"'";
                                yyerror(err.c_str());
                            }
                        (yyval.nod) = new Node { (yyvsp[-2].nod), (yyvsp[0].nod), "/",(yyvsp[-2].nod)->type }; 
                        ast.AddNode("/",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);}
#line 1858 "limbaj.tab.c"
    break;

  case 89: /* expression: expression '^' expression  */
#line 577 "limbaj.y"
                                       { 
                    if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool"){yyerror("Cannot perform mathematical operations on type 'bool'");}
                    if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type){string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' ^ '"+(yyvsp[0].nod)->type+"'";yyerror(err.c_str());}
                    (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), "^",(yyvsp[-2].nod)->type}; 
                    ast.AddNode("^",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);}
#line 1868 "limbaj.tab.c"
    break;

  case 90: /* expression: expression AND expression  */
#line 582 "limbaj.y"
                                      {
                    if((yyvsp[-2].nod)->type=="int"||(yyvsp[-2].nod)->type=="float"||(yyvsp[0].nod)->type=="int"||(yyvsp[0].nod)->type=="float"){
                         string err="Operation && only supports bool operands ! '"+(yyvsp[-2].nod)->type+"' && '"+(yyvsp[0].nod)->type+"'";yyerror(err.c_str());}
                    (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod),"&&",(yyvsp[-2].nod)->type}; 
                    ast.AddNode("&&",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type); }
#line 1878 "limbaj.tab.c"
    break;

  case 91: /* expression: expression OR expression  */
#line 587 "limbaj.y"
                                     {
                    if((yyvsp[-2].nod)->type=="int"||(yyvsp[-2].nod)->type=="float"||(yyvsp[0].nod)->type=="int"||(yyvsp[0].nod)->type=="float"){
                         string err="Operation || only supports bool operands ! '"+(yyvsp[-2].nod)->type+"' || '"+(yyvsp[0].nod)->type+"'";yyerror(err.c_str());}
                    (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod),"||",(yyvsp[-2].nod)->type}; 
                    ast.AddNode("||",(yyvsp[-2].nod),(yyvsp[0].nod),(yyvsp[-2].nod)->type);}
#line 1888 "limbaj.tab.c"
    break;

  case 92: /* expression: NOT expression  */
#line 592 "limbaj.y"
                           {
                    if((yyvsp[0].nod)->type=="int"||(yyvsp[0].nod)->type=="float"){
                         string err="Operation ! only supports bool operand! !'"+(yyvsp[0].nod)->type+"''";yyerror(err.c_str());}
                    (yyval.nod) = new Node{(yyvsp[0].nod), NULL,"!",(yyvsp[0].nod)->type}; 
                    ast.AddNode("!",(yyvsp[0].nod),NULL,(yyvsp[0].nod)->type); }
#line 1898 "limbaj.tab.c"
    break;

  case 93: /* expression: expression LT expression  */
#line 597 "limbaj.y"
                                      { 
                    if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool"){yyerror("Cannot perform mathematical operations on type 'bool'");}
                    if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type){string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' < '"+(yyvsp[0].nod)->type+"'";yyerror(err.c_str());}
                    (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), "<","bool"}; 
                    ast.AddNode("<",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");}
#line 1908 "limbaj.tab.c"
    break;

  case 94: /* expression: expression LE expression  */
#line 602 "limbaj.y"
                                      { 
                    if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool"){yyerror("Cannot perform mathematical operations on type 'bool'");}
                    if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type){string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' <= '"+(yyvsp[0].nod)->type+"'";yyerror(err.c_str());}
                    (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), "<=","bool"}; 
                    ast.AddNode("<=",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");}
#line 1918 "limbaj.tab.c"
    break;

  case 95: /* expression: expression GT expression  */
#line 607 "limbaj.y"
                                      { 
                    if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool"){yyerror("Cannot perform mathematical operations on type 'bool'");}
                    if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type){string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' > '"+(yyvsp[0].nod)->type+"'";yyerror(err.c_str());}
                    (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), ">","bool"}; 
                    ast.AddNode(">",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");}
#line 1928 "limbaj.tab.c"
    break;

  case 96: /* expression: expression GE expression  */
#line 612 "limbaj.y"
                                      { 
                    if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool"){yyerror("Cannot perform mathematical operations on type 'bool'");}
                    if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type){string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' >= '"+(yyvsp[0].nod)->type+"'";yyerror(err.c_str());}
                    (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), ">=","bool"}; 
                    ast.AddNode(">=",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");}
#line 1938 "limbaj.tab.c"
    break;

  case 97: /* expression: expression EQ expression  */
#line 617 "limbaj.y"
                                      { 
                    if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool"){yyerror("Cannot perform mathematical operations on type 'bool'");}
                    if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type){string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' == '"+(yyvsp[0].nod)->type+"'";yyerror(err.c_str());}
                    (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), "==","bool"}; 
                    ast.AddNode("==",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");}
#line 1948 "limbaj.tab.c"
    break;

  case 98: /* expression: expression NEQ expression  */
#line 622 "limbaj.y"
                                       { 
                    if((yyvsp[-2].nod)->type=="bool"||(yyvsp[0].nod)->type=="bool"){yyerror("Cannot perform mathematical operations on type 'bool'");}
                    if((yyvsp[-2].nod)->type!=(yyvsp[0].nod)->type){string err="Operands have different types! '"+(yyvsp[-2].nod)->type+"' != '"+(yyvsp[0].nod)->type+"'";yyerror(err.c_str());}
                    (yyval.nod) = new Node{(yyvsp[-2].nod), (yyvsp[0].nod), "!=","bool"}; 
                    ast.AddNode("!=",(yyvsp[-2].nod),(yyvsp[0].nod),"bool");}
#line 1958 "limbaj.tab.c"
    break;

  case 99: /* expression: '(' expression ')'  */
#line 627 "limbaj.y"
                               {(yyval.nod)=(yyvsp[-1].nod);}
#line 1964 "limbaj.tab.c"
    break;

  case 100: /* expression: INT  */
#line 628 "limbaj.y"
                   { (yyval.nod) = new Node{NULL, NULL, to_string((yyvsp[0].num)),"int"}; ast.AddNode(to_string((yyvsp[0].num)),NULL,NULL,"int");}
#line 1970 "limbaj.tab.c"
    break;

  case 101: /* expression: FLOAT  */
#line 629 "limbaj.y"
                   {(yyval.nod)=new Node{NULL,NULL,to_string((yyvsp[0].num_cu_pct)),"float"};ast.AddNode(to_string((yyvsp[0].num_cu_pct)),NULL,NULL,"float");}
#line 1976 "limbaj.tab.c"
    break;

  case 102: /* expression: BOOL  */
#line 630 "limbaj.y"
                  {(yyval.nod)=new Node{NULL,NULL,(yyvsp[0].bul)?"true":"false","bool"};ast.AddNode((yyvsp[0].bul)?"true":"false",NULL,NULL,"bool");}
#line 1982 "limbaj.tab.c"
    break;

  case 103: /* expression: ID  */
#line 631 "limbaj.y"
                { if(!ids.existsVar((yyvsp[0].string))) {string err="Variable '"+string((yyvsp[0].string))+"' was not declared!";yyerror(err.c_str());}
               (yyval.nod)=new Node{NULL,NULL,ids.get_val((yyvsp[0].string)),ids.TypeOf((yyvsp[0].string))}; ast.AddNode(ids.get_val((yyvsp[0].string)),NULL,NULL,ids.TypeOf((yyvsp[0].string)));}
#line 1989 "limbaj.tab.c"
    break;


#line 1993 "limbaj.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 636 "limbaj.y"


void yyerror(const char * s)
    {
        printf("error: %s line:%d\n",s,yylineno);
    }  

int main(int argc, char** argv)
{
     yyin=fopen(argv[1],"r");
     yyparse();
} 
