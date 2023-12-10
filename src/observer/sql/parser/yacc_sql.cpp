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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}


#line 115 "yacc_sql.cpp"

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

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_INDEX = 8,                      /* INDEX  */
  YYSYMBOL_CALC = 9,                       /* CALC  */
  YYSYMBOL_SELECT = 10,                    /* SELECT  */
  YYSYMBOL_SHOW = 11,                      /* SHOW  */
  YYSYMBOL_SYNC = 12,                      /* SYNC  */
  YYSYMBOL_INSERT = 13,                    /* INSERT  */
  YYSYMBOL_DELETE = 14,                    /* DELETE  */
  YYSYMBOL_UPDATE = 15,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 16,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 17,                    /* RBRACE  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 19,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 20,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 21,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 22,                     /* INT_T  */
  YYSYMBOL_STRING_T = 23,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 24,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 25,                    /* DATE_T  */
  YYSYMBOL_HELP = 26,                      /* HELP  */
  YYSYMBOL_EXIT = 27,                      /* EXIT  */
  YYSYMBOL_DOT = 28,                       /* DOT  */
  YYSYMBOL_INTO = 29,                      /* INTO  */
  YYSYMBOL_VALUES = 30,                    /* VALUES  */
  YYSYMBOL_FROM = 31,                      /* FROM  */
  YYSYMBOL_WHERE = 32,                     /* WHERE  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_SET = 34,                       /* SET  */
  YYSYMBOL_ON = 35,                        /* ON  */
  YYSYMBOL_LOAD = 36,                      /* LOAD  */
  YYSYMBOL_DATA = 37,                      /* DATA  */
  YYSYMBOL_INFILE = 38,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 39,                   /* EXPLAIN  */
  YYSYMBOL_EQ = 40,                        /* EQ  */
  YYSYMBOL_LT = 41,                        /* LT  */
  YYSYMBOL_GT = 42,                        /* GT  */
  YYSYMBOL_LE = 43,                        /* LE  */
  YYSYMBOL_GE = 44,                        /* GE  */
  YYSYMBOL_NE = 45,                        /* NE  */
  YYSYMBOL_MAX = 46,                       /* MAX  */
  YYSYMBOL_MIN = 47,                       /* MIN  */
  YYSYMBOL_COUNT = 48,                     /* COUNT  */
  YYSYMBOL_AVG = 49,                       /* AVG  */
  YYSYMBOL_SUM = 50,                       /* SUM  */
  YYSYMBOL_UNIQUE = 51,                    /* UNIQUE  */
  YYSYMBOL_IS_T = 52,                      /* IS_T  */
  YYSYMBOL_NOT = 53,                       /* NOT  */
  YYSYMBOL_NULL_T = 54,                    /* NULL_T  */
  YYSYMBOL_NULLABLE = 55,                  /* NULLABLE  */
  YYSYMBOL_INNER = 56,                     /* INNER  */
  YYSYMBOL_JOIN = 57,                      /* JOIN  */
  YYSYMBOL_ORDER = 58,                     /* ORDER  */
  YYSYMBOL_BY = 59,                        /* BY  */
  YYSYMBOL_ASC_T = 60,                     /* ASC_T  */
  YYSYMBOL_DESC_T = 61,                    /* DESC_T  */
  YYSYMBOL_GROUP = 62,                     /* GROUP  */
  YYSYMBOL_NUMBER = 63,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 64,                     /* FLOAT  */
  YYSYMBOL_DATE = 65,                      /* DATE  */
  YYSYMBOL_ID = 66,                        /* ID  */
  YYSYMBOL_SSS = 67,                       /* SSS  */
  YYSYMBOL_68_ = 68,                       /* '+'  */
  YYSYMBOL_69_ = 69,                       /* '-'  */
  YYSYMBOL_70_ = 70,                       /* '*'  */
  YYSYMBOL_71_ = 71,                       /* '/'  */
  YYSYMBOL_UMINUS = 72,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 73,                  /* $accept  */
  YYSYMBOL_commands = 74,                  /* commands  */
  YYSYMBOL_command_wrapper = 75,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 76,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 77,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 78,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 79,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 80,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 81,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 82,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 83,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 84,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 85,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 86,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 87,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 88,             /* attr_def_list  */
  YYSYMBOL_attr_def = 89,                  /* attr_def  */
  YYSYMBOL_number = 90,                    /* number  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_insert_stmt = 92,               /* insert_stmt  */
  YYSYMBOL_raw_tuple_list = 93,            /* raw_tuple_list  */
  YYSYMBOL_raw_tuple = 94,                 /* raw_tuple  */
  YYSYMBOL_value_list = 95,                /* value_list  */
  YYSYMBOL_value = 96,                     /* value  */
  YYSYMBOL_delete_stmt = 97,               /* delete_stmt  */
  YYSYMBOL_update_stmt = 98,               /* update_stmt  */
  YYSYMBOL_select_stmt = 99,               /* select_stmt  */
  YYSYMBOL_order = 100,                    /* order  */
  YYSYMBOL_order_node_list = 101,          /* order_node_list  */
  YYSYMBOL_order_node = 102,               /* order_node  */
  YYSYMBOL_group = 103,                    /* group  */
  YYSYMBOL_group_node_list = 104,          /* group_node_list  */
  YYSYMBOL_group_node = 105,               /* group_node  */
  YYSYMBOL_order_type = 106,               /* order_type  */
  YYSYMBOL_join_list = 107,                /* join_list  */
  YYSYMBOL_join_node = 108,                /* join_node  */
  YYSYMBOL_calc_stmt = 109,                /* calc_stmt  */
  YYSYMBOL_expression_list = 110,          /* expression_list  */
  YYSYMBOL_expression = 111,               /* expression  */
  YYSYMBOL_select_exprs = 112,             /* select_exprs  */
  YYSYMBOL_select_expr = 113,              /* select_expr  */
  YYSYMBOL_select_expr_list = 114,         /* select_expr_list  */
  YYSYMBOL_aggr_func = 115,                /* aggr_func  */
  YYSYMBOL_aggr_func_type = 116,           /* aggr_func_type  */
  YYSYMBOL_select_attr = 117,              /* select_attr  */
  YYSYMBOL_rel_attr = 118,                 /* rel_attr  */
  YYSYMBOL_attr_list = 119,                /* attr_list  */
  YYSYMBOL_rel_list = 120,                 /* rel_list  */
  YYSYMBOL_where = 121,                    /* where  */
  YYSYMBOL_condition_list = 122,           /* condition_list  */
  YYSYMBOL_condition = 123,                /* condition  */
  YYSYMBOL_comp_op = 124,                  /* comp_op  */
  YYSYMBOL_load_data_stmt = 125,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 126,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 127,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 128             /* opt_semicolon  */
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   229

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
       2,     2,    70,    68,     2,    69,     2,    71,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    72
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   221,   221,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   252,   258,   263,   269,   275,   281,   287,
     294,   300,   308,   320,   335,   345,   364,   367,   380,   389,
     398,   407,   416,   425,   437,   440,   441,   442,   443,   446,
     460,   463,   474,   486,   489,   500,   504,   508,   511,   514,
     522,   534,   549,   577,   608,   611,   618,   621,   626,   632,
     641,   644,   651,   654,   659,   665,   671,   674,   677,   683,
     686,   697,   708,   718,   723,   734,   737,   740,   743,   746,
     750,   753,   761,   770,   782,   787,   796,   799,   812,   824,
     827,   830,   833,   836,   842,   849,   861,   870,   880,   885,
     896,   899,   913,   916,   929,   932,   938,   941,   946,   953,
     965,   977,   989,  1004,  1005,  1006,  1007,  1008,  1009,  1010,
    1011,  1015,  1028,  1036,  1046,  1047
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "INDEX", "CALC", "SELECT", "SHOW", "SYNC",
  "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET",
  "ON", "LOAD", "DATA", "INFILE", "EXPLAIN", "EQ", "LT", "GT", "LE", "GE",
  "NE", "MAX", "MIN", "COUNT", "AVG", "SUM", "UNIQUE", "IS_T", "NOT",
  "NULL_T", "NULLABLE", "INNER", "JOIN", "ORDER", "BY", "ASC_T", "DESC_T",
  "GROUP", "NUMBER", "FLOAT", "DATE", "ID", "SSS", "'+'", "'-'", "'*'",
  "'/'", "UMINUS", "$accept", "commands", "command_wrapper", "exit_stmt",
  "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "desc_table_stmt",
  "create_index_stmt", "drop_index_stmt", "create_table_stmt",
  "attr_def_list", "attr_def", "number", "type", "insert_stmt",
  "raw_tuple_list", "raw_tuple", "value_list", "value", "delete_stmt",
  "update_stmt", "select_stmt", "order", "order_node_list", "order_node",
  "group", "group_node_list", "group_node", "order_type", "join_list",
  "join_node", "calc_stmt", "expression_list", "expression",
  "select_exprs", "select_expr", "select_expr_list", "aggr_func",
  "aggr_func_type", "select_attr", "rel_attr", "attr_list", "rel_list",
  "where", "condition_list", "condition", "comp_op", "load_data_stmt",
  "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-160)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,    21,    15,    -1,    48,     9,  -160,    -7,     2,   -23,
    -160,  -160,  -160,  -160,  -160,   -19,    17,    -2,   -14,    69,
      67,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,     5,    14,    77,    20,    22,    -1,  -160,  -160,  -160,
    -160,  -160,    -1,  -160,  -160,     8,  -160,  -160,  -160,  -160,
    -160,    59,  -160,    61,    72,  -160,    96,  -160,  -160,    47,
      49,    91,    97,    98,  -160,  -160,  -160,  -160,  -160,   122,
     104,    74,  -160,   106,   -13,  -160,    -1,    -1,    -1,    -1,
      -1,    76,    78,    53,  -160,   -35,   113,   114,    79,    63,
      80,    82,    83,   115,    85,  -160,  -160,   -29,   -29,  -160,
    -160,  -160,   -12,    72,   134,   136,   137,   138,    57,  -160,
     116,  -160,   128,   110,   140,   143,    94,  -160,    95,   105,
     107,   114,  -160,    99,  -160,    99,  -160,    63,   146,    64,
      64,  -160,   133,    63,   163,  -160,  -160,  -160,  -160,    12,
      82,   153,   108,   155,   154,   109,   114,   107,   111,   137,
     137,   158,   138,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
     124,    57,    57,    57,   114,   112,   117,   125,  -160,   140,
    -160,   164,   118,  -160,   147,   111,  -160,   126,   129,  -160,
    -160,    63,   166,   146,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,   169,  -160,  -160,  -160,   171,    57,   129,
      99,   130,  -160,   158,  -160,  -160,   -17,  -160,  -160,  -160,
    -160,   172,  -160,    99,  -160,   139,  -160,    99,  -160,   173,
     -10,  -160,  -160,    99,  -160,  -160,  -160,  -160
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    25,     0,     0,     0,
      26,    27,    28,    24,    23,     0,     0,     0,     0,     0,
     134,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,     0,    58,    55,    56,
      57,    59,     0,    91,    82,    83,    99,   100,   101,   102,
     103,   108,    92,     0,    96,    95,     0,    94,    30,     0,
       0,     0,     0,     0,   132,    31,     1,   135,     2,     0,
       0,     0,    29,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,    93,   107,     0,   114,     0,     0,
       0,     0,     0,     0,     0,    89,    84,    85,    86,    87,
      88,   109,   112,    96,   104,     0,   110,     0,   116,    60,
       0,   133,     0,     0,    36,     0,     0,    34,     0,     0,
      79,   114,    97,     0,    98,     0,   106,     0,    50,     0,
       0,   115,   117,     0,     0,    45,    46,    47,    48,    39,
       0,     0,     0,     0,   112,     0,   114,    79,    70,   110,
     110,    53,     0,    49,   123,   124,   125,   126,   127,   128,
     129,     0,     0,   116,   114,     0,     0,     0,    43,    36,
      35,     0,     0,   113,     0,    70,    80,     0,    64,   105,
     111,     0,     0,    50,   130,   120,   122,   119,   121,   118,
      61,   131,    44,     0,    41,    37,    32,     0,   116,    64,
      72,     0,    62,    53,    52,    51,    38,    33,    81,    63,
      71,    73,    75,    66,    54,     0,    42,    72,    65,    67,
      76,    40,    74,    66,    77,    78,    69,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,   175,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,    16,    44,  -160,  -160,  -160,
       3,    35,   -15,   -98,  -160,  -160,  -160,    -9,   -34,  -160,
      18,   -26,  -160,  -160,    45,    92,  -160,   119,    -6,  -160,
     120,   101,  -160,  -160,  -160,    -4,   -99,    54,  -126,  -159,
    -160,    70,  -160,  -160,  -160,  -160
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   151,   124,   203,   149,    33,
     163,   138,   192,    53,    34,    35,    36,   212,   228,   229,
     188,   220,   221,   236,   156,   157,    37,    54,    55,    63,
      64,    94,    65,    66,   115,   140,   136,   131,   119,   141,
     142,   171,    38,    39,    40,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      67,   121,     1,     2,   105,   158,   128,     3,     4,     5,
       6,     7,     8,     9,   199,    46,    68,    10,    11,    12,
     139,    44,    69,    45,    13,    14,    86,    41,   176,    42,
     185,    61,    15,    70,    16,   114,   225,    17,   226,   161,
      84,    89,    90,    71,   129,   174,    85,    72,   200,   218,
     234,   235,    75,    47,    73,    87,    88,    89,    90,    18,
     189,   190,    48,    49,    50,   177,    51,   178,    52,    76,
      77,    79,    43,   195,   197,   139,    87,    88,    89,    90,
      80,   107,   108,   109,   110,    81,    82,    91,    83,    67,
      93,   116,    92,   213,    56,    57,    58,    59,    60,    56,
      57,    58,    59,    60,   164,   165,   166,   167,   168,   169,
     139,    47,    95,    96,    61,    97,   170,    47,    62,    61,
      48,    49,    50,    61,    51,    98,    48,    49,    50,   159,
      51,   160,   145,   146,   147,   148,   100,    99,   101,   102,
     103,   104,   111,   117,   112,   120,   118,   122,   123,   125,
     126,   127,   133,   134,   137,   135,   143,   144,   150,   152,
     153,   154,   155,   129,   162,    61,   173,   196,   198,   175,
     180,   182,   128,   187,   181,   184,   191,   194,   201,   204,
     202,   206,   208,   214,   207,   210,   216,   211,   217,   223,
     227,   233,    74,   231,   179,   205,   215,   193,   224,   237,
     219,   232,   186,   209,   130,   106,   222,     0,   183,     0,
     172,     0,     0,   113,   132,     0,     0,     0,     0,   230,
       0,     0,     0,   222,     0,     0,     0,     0,     0,   230
};

static const yytype_int16 yycheck[] =
{
       4,    99,     4,     5,    17,   131,    18,     9,    10,    11,
      12,    13,    14,    15,   173,    16,     7,    19,    20,    21,
     118,     6,    29,     8,    26,    27,    18,     6,    16,     8,
     156,    66,    34,    31,    36,    70,    53,    39,    55,   137,
      46,    70,    71,    66,    56,   143,    52,    66,   174,   208,
      60,    61,    66,    54,    37,    68,    69,    70,    71,    61,
     159,   160,    63,    64,    65,    53,    67,    55,    69,     0,
       3,    66,    51,   171,   172,   173,    68,    69,    70,    71,
      66,    87,    88,    89,    90,     8,    66,    28,    66,    93,
      18,    95,    31,   191,    46,    47,    48,    49,    50,    46,
      47,    48,    49,    50,    40,    41,    42,    43,    44,    45,
     208,    54,    16,    66,    66,    66,    52,    54,    70,    66,
      63,    64,    65,    66,    67,    34,    63,    64,    65,   133,
      67,   135,    22,    23,    24,    25,    38,    40,    16,    35,
      66,    35,    66,    30,    66,    66,    32,    67,    66,    66,
      35,    66,    18,    17,    16,    18,    40,    29,    18,    16,
      66,    66,    57,    56,    18,    66,    33,   171,   172,     6,
      17,    16,    18,    62,    66,    66,    18,    53,    66,    54,
      63,    17,    35,    17,    66,    59,    17,    58,    17,    59,
      18,    18,    17,    54,   150,   179,   193,   162,   213,   233,
     209,   227,   157,   185,   112,    86,   210,    -1,   154,    -1,
     140,    -1,    -1,    93,   113,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,   233
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     9,    10,    11,    12,    13,    14,    15,
      19,    20,    21,    26,    27,    34,    36,    39,    61,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    92,    97,    98,    99,   109,   125,   126,
     127,     6,     8,    51,     6,     8,    16,    54,    63,    64,
      65,    67,    69,    96,   110,   111,    46,    47,    48,    49,
      50,    66,    70,   112,   113,   115,   116,   118,     7,    29,
      31,    66,    66,    37,    75,    66,     0,     3,   128,    66,
      66,     8,    66,    66,   111,   111,    18,    68,    69,    70,
      71,    28,    31,    18,   114,    16,    66,    66,    34,    40,
      38,    16,    35,    66,    35,    17,   110,   111,   111,   111,
     111,    66,    66,   113,    70,   117,   118,    30,    32,   121,
      66,    96,    67,    66,    89,    66,    35,    66,    18,    56,
     108,   120,   114,    18,    17,    18,   119,    16,    94,    96,
     118,   122,   123,    40,    29,    22,    23,    24,    25,    91,
      18,    88,    16,    66,    66,    57,   107,   108,   121,   118,
     118,    96,    18,    93,    40,    41,    42,    43,    44,    45,
      52,   124,   124,    33,    96,     6,    16,    53,    55,    89,
      17,    66,    16,   120,    66,   121,   107,    62,   103,   119,
     119,    18,    95,    94,    53,    96,   118,    96,   118,   122,
     121,    66,    63,    90,    54,    88,    17,    66,    35,   103,
      59,    58,   100,    96,    17,    93,    17,    17,   122,   100,
     104,   105,   118,    59,    95,    53,    55,    18,   101,   102,
     118,    54,   104,    18,    60,    61,   106,   101
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    85,    86,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    90,    91,    91,    91,    91,    92,
      93,    93,    94,    95,    95,    96,    96,    96,    96,    96,
      97,    98,    99,    99,   100,   100,   101,   101,   101,   102,
     103,   103,   104,   104,   104,   105,   106,   106,   106,   107,
     107,   108,   109,   110,   110,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   116,
     116,   116,   116,   116,   117,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   123,
     123,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     124,   125,   126,   127,   128,   128
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     8,     9,     5,     7,     0,     3,     5,     2,
       7,     4,     6,     3,     1,     1,     1,     1,     1,     6,
       0,     3,     4,     0,     3,     1,     1,     1,     1,     1,
       4,     7,     8,     9,     0,     3,     0,     1,     3,     2,
       0,     3,     0,     1,     3,     1,     0,     1,     1,     0,
       2,     5,     2,     1,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     2,     1,     1,     0,     3,     4,     1,
       1,     1,     1,     1,     1,     4,     2,     0,     1,     3,
       0,     3,     0,     3,     0,     2,     0,     1,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     7,     2,     4,     0,     1
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
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 222 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1809 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 252 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1818 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 258 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1826 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 263 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1834 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 269 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1842 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 275 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1850 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 281 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1858 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 287 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1868 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 294 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1876 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC_T ID  */
#line 300 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1886 "yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID RBRACE  */
#line 309 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_name = (yyvsp[-1].string);
      create_index.unique=false;
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 1902 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID RBRACE  */
#line 321 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_name = (yyvsp[-1].string);
      create_index.unique=true;
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 1918 "yacc_sql.cpp"
    break;

  case 34: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 336 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 1930 "yacc_sql.cpp"
    break;

  case 35: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 346 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-1].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-2].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-2].attr_info);
    }
#line 1950 "yacc_sql.cpp"
    break;

  case 36: /* attr_def_list: %empty  */
#line 364 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 1958 "yacc_sql.cpp"
    break;

  case 37: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 368 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 1972 "yacc_sql.cpp"
    break;

  case 38: /* attr_def: ID type LBRACE number RBRACE  */
#line 381 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-3].number);
      (yyval.attr_info)->name = (yyvsp[-4].string);
      (yyval.attr_info)->length = (yyvsp[-1].number);
      (yyval.attr_info)->nullable=false;
      free((yyvsp[-4].string));
    }
#line 1985 "yacc_sql.cpp"
    break;

  case 39: /* attr_def: ID type  */
#line 390 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[0].number);
      (yyval.attr_info)->name = (yyvsp[-1].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable=false;
      free((yyvsp[-1].string));
    }
#line 1998 "yacc_sql.cpp"
    break;

  case 40: /* attr_def: ID type LBRACE number RBRACE NOT NULL_T  */
#line 399 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-5].number);
      (yyval.attr_info)->name = (yyvsp[-6].string);
      (yyval.attr_info)->length = (yyvsp[-3].number);
      (yyval.attr_info)->nullable=false;
      free((yyvsp[-6].string));
    }
#line 2011 "yacc_sql.cpp"
    break;

  case 41: /* attr_def: ID type NOT NULL_T  */
#line 408 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-2].number);
      (yyval.attr_info)->name = (yyvsp[-3].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable=false;
      free((yyvsp[-3].string));
    }
#line 2024 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID type LBRACE number RBRACE NULLABLE  */
#line 417 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->nullable=true;
      free((yyvsp[-5].string));
    }
#line 2037 "yacc_sql.cpp"
    break;

  case 43: /* attr_def: ID type NULLABLE  */
#line 426 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable=true;
      free((yyvsp[-2].string));
    }
#line 2050 "yacc_sql.cpp"
    break;

  case 44: /* number: NUMBER  */
#line 437 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2056 "yacc_sql.cpp"
    break;

  case 45: /* type: INT_T  */
#line 440 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2062 "yacc_sql.cpp"
    break;

  case 46: /* type: STRING_T  */
#line 441 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2068 "yacc_sql.cpp"
    break;

  case 47: /* type: FLOAT_T  */
#line 442 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2074 "yacc_sql.cpp"
    break;

  case 48: /* type: DATE_T  */
#line 443 "yacc_sql.y"
               { (yyval.number)=DATES; }
#line 2080 "yacc_sql.cpp"
    break;

  case 49: /* insert_stmt: INSERT INTO ID VALUES raw_tuple raw_tuple_list  */
#line 447 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-3].string);
      if ((yyvsp[0].raw_tuple_list) != nullptr) {
        (yyval.sql_node)->insertion.tuples.swap(*(yyvsp[0].raw_tuple_list));
      }
      (yyval.sql_node)->insertion.tuples.emplace_back(*(yyvsp[-1].raw_tuple));
      std::reverse((yyval.sql_node)->insertion.tuples.begin(), (yyval.sql_node)->insertion.tuples.end());
      free((yyvsp[-3].string));
    }
#line 2095 "yacc_sql.cpp"
    break;

  case 50: /* raw_tuple_list: %empty  */
#line 460 "yacc_sql.y"
    {
      (yyval.raw_tuple_list) = nullptr;
    }
#line 2103 "yacc_sql.cpp"
    break;

  case 51: /* raw_tuple_list: COMMA raw_tuple raw_tuple_list  */
#line 463 "yacc_sql.y"
                                      { 
      if ((yyvsp[0].raw_tuple_list) != nullptr) {
        (yyval.raw_tuple_list) = (yyvsp[0].raw_tuple_list);
      } else {
        (yyval.raw_tuple_list) = new std::vector<RawTuple>;
      }
      (yyval.raw_tuple_list)->emplace_back(*(yyvsp[-1].raw_tuple));
      delete (yyvsp[-1].raw_tuple);
    }
#line 2117 "yacc_sql.cpp"
    break;

  case 52: /* raw_tuple: LBRACE value value_list RBRACE  */
#line 474 "yacc_sql.y"
                                   {
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.raw_tuple) = (yyvsp[-1].value_list);
      } else {
        (yyval.raw_tuple) = new RawTuple;
      }
      (yyval.raw_tuple)->emplace_back(*(yyvsp[-2].value));
      std::reverse((yyval.raw_tuple)->begin(), (yyval.raw_tuple)->end());
      delete (yyvsp[-2].value);
    }
#line 2132 "yacc_sql.cpp"
    break;

  case 53: /* value_list: %empty  */
#line 486 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2140 "yacc_sql.cpp"
    break;

  case 54: /* value_list: COMMA value value_list  */
#line 489 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2154 "yacc_sql.cpp"
    break;

  case 55: /* value: NUMBER  */
#line 500 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2163 "yacc_sql.cpp"
    break;

  case 56: /* value: FLOAT  */
#line 504 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2172 "yacc_sql.cpp"
    break;

  case 57: /* value: DATE  */
#line 508 "yacc_sql.y"
          {
      (yyval.value) = new Value((date)(yyvsp[0].dates));
    }
#line 2180 "yacc_sql.cpp"
    break;

  case 58: /* value: NULL_T  */
#line 511 "yacc_sql.y"
            {
      (yyval.value) = new Value(NULLS);
    }
#line 2188 "yacc_sql.cpp"
    break;

  case 59: /* value: SSS  */
#line 514 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2198 "yacc_sql.cpp"
    break;

  case 60: /* delete_stmt: DELETE FROM ID where  */
#line 523 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2212 "yacc_sql.cpp"
    break;

  case 61: /* update_stmt: UPDATE ID SET ID EQ value where  */
#line 535 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-5].string);
      (yyval.sql_node)->update.attribute_name = (yyvsp[-3].string);
      (yyval.sql_node)->update.value = *(yyvsp[-1].value);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
    }
#line 2229 "yacc_sql.cpp"
    break;

  case 62: /* select_stmt: SELECT select_exprs FROM ID rel_list where group order  */
#line 550 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-6].s_expr_node_list) != nullptr) {
        (yyval.sql_node)->selection.select_exprs.swap(*(yyvsp[-6].s_expr_node_list));
        delete (yyvsp[-6].s_expr_node_list);
      }
      if ((yyvsp[-3].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-3].relation_list));
        delete (yyvsp[-3].relation_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-4].string));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());
      
      if ((yyvsp[-2].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-2].condition_list));
        delete (yyvsp[-2].condition_list);
      }
      if ((yyvsp[-1].group_node_list) != nullptr) {
        (yyval.sql_node)->selection.groups.swap(*(yyvsp[-1].group_node_list));
        delete (yyvsp[-1].group_node_list);
      }
      if ((yyvsp[0].order_node_list) != nullptr) {
        (yyval.sql_node)->selection.orders.swap(*(yyvsp[0].order_node_list));
        delete (yyvsp[0].order_node_list);
      }
      free((yyvsp[-4].string));
    }
#line 2261 "yacc_sql.cpp"
    break;

  case 63: /* select_stmt: SELECT select_exprs FROM ID join_node join_list where group order  */
#line 578 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-7].s_expr_node_list) != nullptr) {
        (yyval.sql_node)->selection.select_exprs.swap(*(yyvsp[-7].s_expr_node_list));
        delete (yyvsp[-7].s_expr_node_list);
      }
      if ((yyvsp[-3].join_list) != nullptr) {
        (yyval.sql_node)->selection.joins.swap(*(yyvsp[-3].join_list));
        delete (yyvsp[-3].join_list);
      }
      (yyval.sql_node)->selection.joins.emplace_back(*(yyvsp[-4].join_node));
      std::reverse((yyval.sql_node)->selection.joins.begin(), (yyval.sql_node)->selection.joins.end());
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-5].string));
      if ((yyvsp[-2].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-2].condition_list));
        delete (yyvsp[-2].condition_list);
      }
      if ((yyvsp[-1].group_node_list) != nullptr) {
        (yyval.sql_node)->selection.groups.swap(*(yyvsp[-1].group_node_list));
        delete (yyvsp[-1].group_node_list);
      }
      if ((yyvsp[0].order_node_list) != nullptr) {
        (yyval.sql_node)->selection.orders.swap(*(yyvsp[0].order_node_list));
        delete (yyvsp[0].order_node_list);
      }
      free((yyvsp[-5].string));
    }
#line 2293 "yacc_sql.cpp"
    break;

  case 64: /* order: %empty  */
#line 608 "yacc_sql.y"
    {
      (yyval.order_node_list) = nullptr;
    }
#line 2301 "yacc_sql.cpp"
    break;

  case 65: /* order: ORDER BY order_node_list  */
#line 612 "yacc_sql.y"
    {
      (yyval.order_node_list) = (yyvsp[0].order_node_list);
      std::reverse((yyval.order_node_list)->begin(), (yyval.order_node_list)->end());
    }
#line 2310 "yacc_sql.cpp"
    break;

  case 66: /* order_node_list: %empty  */
#line 618 "yacc_sql.y"
    {
      (yyval.order_node_list) = nullptr;
    }
#line 2318 "yacc_sql.cpp"
    break;

  case 67: /* order_node_list: order_node  */
#line 621 "yacc_sql.y"
                 {
      (yyval.order_node_list) = new std::vector<OrderSqlNode>;
      (yyval.order_node_list)->emplace_back(*(yyvsp[0].order_node));
      delete (yyvsp[0].order_node);
    }
#line 2328 "yacc_sql.cpp"
    break;

  case 68: /* order_node_list: order_node COMMA order_node_list  */
#line 626 "yacc_sql.y"
                                       {
      (yyval.order_node_list) = (yyvsp[0].order_node_list);
      (yyval.order_node_list)->emplace_back(*(yyvsp[-2].order_node));
      delete (yyvsp[-2].order_node);
    }
#line 2338 "yacc_sql.cpp"
    break;

  case 69: /* order_node: rel_attr order_type  */
#line 633 "yacc_sql.y"
    {
      (yyval.order_node) = new OrderSqlNode;
      (yyval.order_node)->type=(yyvsp[0].order_type);
      (yyval.order_node)->attribute=*(yyvsp[-1].rel_attr);
      free((yyvsp[-1].rel_attr));
    }
#line 2349 "yacc_sql.cpp"
    break;

  case 70: /* group: %empty  */
#line 641 "yacc_sql.y"
    {
      (yyval.group_node_list) = nullptr;
    }
#line 2357 "yacc_sql.cpp"
    break;

  case 71: /* group: GROUP BY group_node_list  */
#line 645 "yacc_sql.y"
    {
      (yyval.group_node_list) = (yyvsp[0].group_node_list);
      std::reverse((yyval.group_node_list)->begin(), (yyval.group_node_list)->end());
    }
#line 2366 "yacc_sql.cpp"
    break;

  case 72: /* group_node_list: %empty  */
#line 651 "yacc_sql.y"
    {
      (yyval.group_node_list) = nullptr;
    }
#line 2374 "yacc_sql.cpp"
    break;

  case 73: /* group_node_list: group_node  */
#line 654 "yacc_sql.y"
                 {
      (yyval.group_node_list) = new std::vector<GroupSqlNode>;
      (yyval.group_node_list)->emplace_back(*(yyvsp[0].group_node));
      delete (yyvsp[0].group_node);
    }
#line 2384 "yacc_sql.cpp"
    break;

  case 74: /* group_node_list: group_node COMMA group_node_list  */
#line 659 "yacc_sql.y"
                                       {
      (yyval.group_node_list) = (yyvsp[0].group_node_list);
      (yyval.group_node_list)->emplace_back(*(yyvsp[-2].group_node));
      delete (yyvsp[-2].group_node);
    }
#line 2394 "yacc_sql.cpp"
    break;

  case 75: /* group_node: rel_attr  */
#line 666 "yacc_sql.y"
    {
      (yyval.group_node) = (yyvsp[0].rel_attr);
    }
#line 2402 "yacc_sql.cpp"
    break;

  case 76: /* order_type: %empty  */
#line 671 "yacc_sql.y"
    {
      (yyval.order_type) = ASC;
    }
#line 2410 "yacc_sql.cpp"
    break;

  case 77: /* order_type: ASC_T  */
#line 674 "yacc_sql.y"
            {
      (yyval.order_type) = ASC;
    }
#line 2418 "yacc_sql.cpp"
    break;

  case 78: /* order_type: DESC_T  */
#line 677 "yacc_sql.y"
             {
      (yyval.order_type) = DESC;
    }
#line 2426 "yacc_sql.cpp"
    break;

  case 79: /* join_list: %empty  */
#line 683 "yacc_sql.y"
    {
      (yyval.join_list) = nullptr;
    }
#line 2434 "yacc_sql.cpp"
    break;

  case 80: /* join_list: join_node join_list  */
#line 686 "yacc_sql.y"
                           { 
      if ((yyvsp[0].join_list) != nullptr) {
        (yyval.join_list) = (yyvsp[0].join_list);
      } else {
        (yyval.join_list) = new std::vector<JoinSqlNode>;
      }
      (yyval.join_list)->emplace_back(*(yyvsp[-1].join_node));
      delete (yyvsp[-1].join_node);
    }
#line 2448 "yacc_sql.cpp"
    break;

  case 81: /* join_node: INNER JOIN ID ON condition_list  */
#line 698 "yacc_sql.y"
    {
      (yyval.join_node) = new JoinSqlNode;
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.join_node)->conditions.swap(*(yyvsp[0].condition_list));
      }
      (yyval.join_node)->relation = (yyvsp[-2].string);
      free((yyvsp[-2].string));
      delete (yyvsp[0].condition_list);
    }
#line 2462 "yacc_sql.cpp"
    break;

  case 82: /* calc_stmt: CALC expression_list  */
#line 709 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2473 "yacc_sql.cpp"
    break;

  case 83: /* expression_list: expression  */
#line 719 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2482 "yacc_sql.cpp"
    break;

  case 84: /* expression_list: expression COMMA expression_list  */
#line 724 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2495 "yacc_sql.cpp"
    break;

  case 85: /* expression: expression '+' expression  */
#line 734 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2503 "yacc_sql.cpp"
    break;

  case 86: /* expression: expression '-' expression  */
#line 737 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2511 "yacc_sql.cpp"
    break;

  case 87: /* expression: expression '*' expression  */
#line 740 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2519 "yacc_sql.cpp"
    break;

  case 88: /* expression: expression '/' expression  */
#line 743 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2527 "yacc_sql.cpp"
    break;

  case 89: /* expression: LBRACE expression RBRACE  */
#line 746 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2536 "yacc_sql.cpp"
    break;

  case 90: /* expression: '-' expression  */
#line 750 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2544 "yacc_sql.cpp"
    break;

  case 91: /* expression: value  */
#line 753 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2554 "yacc_sql.cpp"
    break;

  case 92: /* select_exprs: '*'  */
#line 761 "yacc_sql.y"
        {
      (yyval.s_expr_node_list) = new std::vector<SelectExprSqlNode>;
      SelectExprSqlNode expr;
      expr.type = REL_ATTR_SELECT_T;
      expr.attribute = new RelAttrSqlNode;
      expr.attribute->relation_name  = "";
      expr.attribute->attribute_name = "*";
      (yyval.s_expr_node_list)->emplace_back(expr);
    }
#line 2568 "yacc_sql.cpp"
    break;

  case 93: /* select_exprs: select_expr select_expr_list  */
#line 770 "yacc_sql.y"
                                   {
      if ((yyvsp[0].s_expr_node_list) != nullptr) {
        (yyval.s_expr_node_list) = (yyvsp[0].s_expr_node_list);
      } else {
        (yyval.s_expr_node_list) = new std::vector<SelectExprSqlNode>;
      }
      (yyval.s_expr_node_list)->emplace_back(*(yyvsp[-1].select_expr_node));
      delete (yyvsp[-1].select_expr_node);
    }
#line 2582 "yacc_sql.cpp"
    break;

  case 94: /* select_expr: rel_attr  */
#line 782 "yacc_sql.y"
             {
      (yyval.select_expr_node) = new SelectExprSqlNode;
      (yyval.select_expr_node)->type = REL_ATTR_SELECT_T;
      (yyval.select_expr_node)->attribute = (yyvsp[0].rel_attr);
    }
#line 2592 "yacc_sql.cpp"
    break;

  case 95: /* select_expr: aggr_func  */
#line 787 "yacc_sql.y"
                {
      (yyval.select_expr_node) = new SelectExprSqlNode;
      (yyval.select_expr_node)->type = AGGR_FUNC_SELECT_T;
      (yyval.select_expr_node)->aggrfunc = (yyvsp[0].aggr_func_node);
    }
#line 2602 "yacc_sql.cpp"
    break;

  case 96: /* select_expr_list: %empty  */
#line 796 "yacc_sql.y"
    {
      (yyval.s_expr_node_list) = nullptr;
    }
#line 2610 "yacc_sql.cpp"
    break;

  case 97: /* select_expr_list: COMMA select_expr select_expr_list  */
#line 799 "yacc_sql.y"
                                         {
      if ((yyvsp[0].s_expr_node_list) != nullptr) {
        (yyval.s_expr_node_list) = (yyvsp[0].s_expr_node_list);
      } else {
        (yyval.s_expr_node_list) = new std::vector<SelectExprSqlNode>;
      }

      (yyval.s_expr_node_list)->emplace_back(*(yyvsp[-1].select_expr_node));
      delete (yyvsp[-1].select_expr_node);
    }
#line 2625 "yacc_sql.cpp"
    break;

  case 98: /* aggr_func: aggr_func_type LBRACE select_attr RBRACE  */
#line 812 "yacc_sql.y"
                                             {
      (yyval.aggr_func_node) = new AggrFuncSqlNode;
      (yyval.aggr_func_node)->type = (yyvsp[-3].aggr_func_type);

      if ((yyvsp[-1].rel_attr_list) != nullptr) {
        (yyval.aggr_func_node)->attributes.swap(*(yyvsp[-1].rel_attr_list));
        delete (yyvsp[-1].rel_attr_list);
      }
    }
#line 2639 "yacc_sql.cpp"
    break;

  case 99: /* aggr_func_type: MAX  */
#line 824 "yacc_sql.y"
        {
      (yyval.aggr_func_type) = MAX_AGGR_T;
    }
#line 2647 "yacc_sql.cpp"
    break;

  case 100: /* aggr_func_type: MIN  */
#line 827 "yacc_sql.y"
          {
      (yyval.aggr_func_type) = MIN_AGGR_T;
    }
#line 2655 "yacc_sql.cpp"
    break;

  case 101: /* aggr_func_type: COUNT  */
#line 830 "yacc_sql.y"
            {
      (yyval.aggr_func_type) = COUNT_AGGR_T;
    }
#line 2663 "yacc_sql.cpp"
    break;

  case 102: /* aggr_func_type: AVG  */
#line 833 "yacc_sql.y"
          {
      (yyval.aggr_func_type) = AVG_AGGR_T;
    }
#line 2671 "yacc_sql.cpp"
    break;

  case 103: /* aggr_func_type: SUM  */
#line 836 "yacc_sql.y"
          {
      (yyval.aggr_func_type) = SUM_AGGR_T;
    }
#line 2679 "yacc_sql.cpp"
    break;

  case 104: /* select_attr: '*'  */
#line 842 "yacc_sql.y"
        {
      (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "*";
      (yyval.rel_attr_list)->emplace_back(attr);
    }
#line 2691 "yacc_sql.cpp"
    break;

  case 105: /* select_attr: '*' COMMA rel_attr attr_list  */
#line 849 "yacc_sql.y"
                                   {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "*";
      (yyval.rel_attr_list)->emplace_back(attr);
    }
#line 2708 "yacc_sql.cpp"
    break;

  case 106: /* select_attr: rel_attr attr_list  */
#line 861 "yacc_sql.y"
                         {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2722 "yacc_sql.cpp"
    break;

  case 107: /* select_attr: %empty  */
#line 870 "yacc_sql.y"
                  {
      (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "";
      (yyval.rel_attr_list)->emplace_back(attr);
    }
#line 2734 "yacc_sql.cpp"
    break;

  case 108: /* rel_attr: ID  */
#line 880 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2744 "yacc_sql.cpp"
    break;

  case 109: /* rel_attr: ID DOT ID  */
#line 885 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2756 "yacc_sql.cpp"
    break;

  case 110: /* attr_list: %empty  */
#line 896 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 2764 "yacc_sql.cpp"
    break;

  case 111: /* attr_list: COMMA rel_attr attr_list  */
#line 899 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2779 "yacc_sql.cpp"
    break;

  case 112: /* rel_list: %empty  */
#line 913 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 2787 "yacc_sql.cpp"
    break;

  case 113: /* rel_list: COMMA ID rel_list  */
#line 916 "yacc_sql.y"
                        {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }

      (yyval.relation_list)->push_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 2802 "yacc_sql.cpp"
    break;

  case 114: /* where: %empty  */
#line 929 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2810 "yacc_sql.cpp"
    break;

  case 115: /* where: WHERE condition_list  */
#line 932 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2818 "yacc_sql.cpp"
    break;

  case 116: /* condition_list: %empty  */
#line 938 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2826 "yacc_sql.cpp"
    break;

  case 117: /* condition_list: condition  */
#line 941 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 2836 "yacc_sql.cpp"
    break;

  case 118: /* condition_list: condition AND condition_list  */
#line 946 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 2846 "yacc_sql.cpp"
    break;

  case 119: /* condition: rel_attr comp_op value  */
#line 954 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].value);
    }
#line 2862 "yacc_sql.cpp"
    break;

  case 120: /* condition: value comp_op value  */
#line 966 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].value);
      delete (yyvsp[0].value);
    }
#line 2878 "yacc_sql.cpp"
    break;

  case 121: /* condition: rel_attr comp_op rel_attr  */
#line 978 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].rel_attr);
    }
#line 2894 "yacc_sql.cpp"
    break;

  case 122: /* condition: value comp_op rel_attr  */
#line 990 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].value);
      delete (yyvsp[0].rel_attr);
    }
#line 2910 "yacc_sql.cpp"
    break;

  case 123: /* comp_op: EQ  */
#line 1004 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 2916 "yacc_sql.cpp"
    break;

  case 124: /* comp_op: LT  */
#line 1005 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 2922 "yacc_sql.cpp"
    break;

  case 125: /* comp_op: GT  */
#line 1006 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 2928 "yacc_sql.cpp"
    break;

  case 126: /* comp_op: LE  */
#line 1007 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 2934 "yacc_sql.cpp"
    break;

  case 127: /* comp_op: GE  */
#line 1008 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 2940 "yacc_sql.cpp"
    break;

  case 128: /* comp_op: NE  */
#line 1009 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 2946 "yacc_sql.cpp"
    break;

  case 129: /* comp_op: IS_T  */
#line 1010 "yacc_sql.y"
           { (yyval.comp) = IS; }
#line 2952 "yacc_sql.cpp"
    break;

  case 130: /* comp_op: IS_T NOT  */
#line 1011 "yacc_sql.y"
               { (yyval.comp) = IS_NOT; }
#line 2958 "yacc_sql.cpp"
    break;

  case 131: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1016 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 2972 "yacc_sql.cpp"
    break;

  case 132: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1029 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 2981 "yacc_sql.cpp"
    break;

  case 133: /* set_variable_stmt: SET ID EQ value  */
#line 1037 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 2993 "yacc_sql.cpp"
    break;


#line 2997 "yacc_sql.cpp"

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
  *++yylsp = yyloc;

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1049 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
