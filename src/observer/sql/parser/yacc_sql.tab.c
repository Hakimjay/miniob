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


#define TRUE 1
#define FALSE 0

#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  size_t select_length;
  size_t condition_length;
  size_t from_length;
  size_t value_length;
  size_t orderby_length;
  size_t groupby_length;
  size_t aggrfunc_length;
  Value values[MAX_NUM];
  Condition conditions[MAX_NUM];
  OrderBy orderbys[MAX_NUM];
  GroupBy groupbys[MAX_NUM];
  AggrFuncType aggrfunctype;
  CompOp comp;
	char id[MAX_NUM];
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

//从字符串指定位置开始，查找指定字符第一次出现的位置
int find(const char *s, int b, const char *t)
{
  int i;
  for (i = b; i < strlen(s); i++) {
	if (s[i] == *t)	return i;
  }
  return -1;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->condition_length = 0;
  context->from_length = 0;
  context->select_length = 0;
  context->value_length = 0;
  context->orderby_length = 0;
  context->ssql->sstr.insertion.value_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)


#line 148 "yacc_sql.tab.c"

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

#include "yacc_sql.tab.h"
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
  YYSYMBOL_SELECT = 9,                     /* SELECT  */
  YYSYMBOL_DESC = 10,                      /* DESC  */
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
  YYSYMBOL_ADD = 25,                       /* ADD  */
  YYSYMBOL_SUB = 26,                       /* SUB  */
  YYSYMBOL_DIV = 27,                       /* DIV  */
  YYSYMBOL_DATE_T = 28,                    /* DATE_T  */
  YYSYMBOL_ASC = 29,                       /* ASC  */
  YYSYMBOL_ORDER = 30,                     /* ORDER  */
  YYSYMBOL_BY = 31,                        /* BY  */
  YYSYMBOL_GROUP = 32,                     /* GROUP  */
  YYSYMBOL_AGGR_MAX = 33,                  /* AGGR_MAX  */
  YYSYMBOL_AGGR_MIN = 34,                  /* AGGR_MIN  */
  YYSYMBOL_AGGR_SUM = 35,                  /* AGGR_SUM  */
  YYSYMBOL_AGGR_AVG = 36,                  /* AGGR_AVG  */
  YYSYMBOL_AGGR_COUNT = 37,                /* AGGR_COUNT  */
  YYSYMBOL_NULL_VALUE = 38,                /* NULL_VALUE  */
  YYSYMBOL_NULLABLE = 39,                  /* NULLABLE  */
  YYSYMBOL_NOT = 40,                       /* NOT  */
  YYSYMBOL_HELP = 41,                      /* HELP  */
  YYSYMBOL_EXIT = 42,                      /* EXIT  */
  YYSYMBOL_DOT = 43,                       /* DOT  */
  YYSYMBOL_INTO = 44,                      /* INTO  */
  YYSYMBOL_VALUES = 45,                    /* VALUES  */
  YYSYMBOL_FROM = 46,                      /* FROM  */
  YYSYMBOL_WHERE = 47,                     /* WHERE  */
  YYSYMBOL_AND = 48,                       /* AND  */
  YYSYMBOL_SET = 49,                       /* SET  */
  YYSYMBOL_ON = 50,                        /* ON  */
  YYSYMBOL_LOAD = 51,                      /* LOAD  */
  YYSYMBOL_DATA = 52,                      /* DATA  */
  YYSYMBOL_INFILE = 53,                    /* INFILE  */
  YYSYMBOL_EQ = 54,                        /* EQ  */
  YYSYMBOL_LT = 55,                        /* LT  */
  YYSYMBOL_GT = 56,                        /* GT  */
  YYSYMBOL_LE = 57,                        /* LE  */
  YYSYMBOL_GE = 58,                        /* GE  */
  YYSYMBOL_NE = 59,                        /* NE  */
  YYSYMBOL_NUMBER = 60,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 61,                     /* FLOAT  */
  YYSYMBOL_ID = 62,                        /* ID  */
  YYSYMBOL_PATH = 63,                      /* PATH  */
  YYSYMBOL_SSS = 64,                       /* SSS  */
  YYSYMBOL_STAR = 65,                      /* STAR  */
  YYSYMBOL_STRING_V = 66,                  /* STRING_V  */
  YYSYMBOL_DATE_STR = 67,                  /* DATE_STR  */
  YYSYMBOL_YYACCEPT = 68,                  /* $accept  */
  YYSYMBOL_commands = 69,                  /* commands  */
  YYSYMBOL_command = 70,                   /* command  */
  YYSYMBOL_exit = 71,                      /* exit  */
  YYSYMBOL_help = 72,                      /* help  */
  YYSYMBOL_sync = 73,                      /* sync  */
  YYSYMBOL_begin = 74,                     /* begin  */
  YYSYMBOL_commit = 75,                    /* commit  */
  YYSYMBOL_rollback = 76,                  /* rollback  */
  YYSYMBOL_drop_table = 77,                /* drop_table  */
  YYSYMBOL_show_tables = 78,               /* show_tables  */
  YYSYMBOL_desc_table = 79,                /* desc_table  */
  YYSYMBOL_create_index = 80,              /* create_index  */
  YYSYMBOL_drop_index = 81,                /* drop_index  */
  YYSYMBOL_show_index = 82,                /* show_index  */
  YYSYMBOL_create_table = 83,              /* create_table  */
  YYSYMBOL_attr_def_list = 84,             /* attr_def_list  */
  YYSYMBOL_attr_def = 85,                  /* attr_def  */
  YYSYMBOL_number = 86,                    /* number  */
  YYSYMBOL_type = 87,                      /* type  */
  YYSYMBOL_ID_get = 88,                    /* ID_get  */
  YYSYMBOL_insert = 89,                    /* insert  */
  YYSYMBOL_value_list = 90,                /* value_list  */
  YYSYMBOL_mul_expr = 91,                  /* mul_expr  */
  YYSYMBOL_add_expr = 92,                  /* add_expr  */
  YYSYMBOL_condition = 93,                 /* condition  */
  YYSYMBOL_unary_expr = 94,                /* unary_expr  */
  YYSYMBOL_aggr_func_type = 95,            /* aggr_func_type  */
  YYSYMBOL_aggr_func_expr = 96,            /* aggr_func_expr  */
  YYSYMBOL_value = 97,                     /* value  */
  YYSYMBOL_delete = 98,                    /* delete  */
  YYSYMBOL_update = 99,                    /* update  */
  YYSYMBOL_select = 100,                   /* select  */
  YYSYMBOL_select_attr = 101,              /* select_attr  */
  YYSYMBOL_attr_list = 102,                /* attr_list  */
  YYSYMBOL_rel_list = 103,                 /* rel_list  */
  YYSYMBOL_where = 104,                    /* where  */
  YYSYMBOL_condition_list = 105,           /* condition_list  */
  YYSYMBOL_sort_unit = 106,                /* sort_unit  */
  YYSYMBOL_sort_list = 107,                /* sort_list  */
  YYSYMBOL_opt_order_by = 108,             /* opt_order_by  */
  YYSYMBOL_groupby_unit = 109,             /* groupby_unit  */
  YYSYMBOL_groupby_list = 110,             /* groupby_list  */
  YYSYMBOL_opt_group_by = 111,             /* opt_group_by  */
  YYSYMBOL_comOp = 112,                    /* comOp  */
  YYSYMBOL_load_data = 113                 /* load_data  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   189,   189,   191,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   216,   221,   226,   232,   238,   244,   250,   256,
     262,   269,   277,   285,   292,   301,   303,   307,   318,   330,
     337,   344,   351,   360,   363,   364,   365,   366,   369,   378,
     394,   396,   402,   405,   420,   427,   437,   438,   445,   455,
     464,   471,   480,   489,   493,   499,   502,   505,   508,   511,
     517,   525,   548,   551,   554,   557,   561,   565,   575,   581,
     591,   601,   628,   634,   640,   647,   649,   655,   661,   668,
     670,   674,   676,   680,   682,   689,   698,   707,   716,   725,
     734,   744,   748,   753,   755,   763,   770,   779,   783,   788,
     790,   797,   798,   799,   800,   801,   802,   806
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "INDEX", "SELECT", "DESC", "SHOW", "SYNC",
  "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "ADD",
  "SUB", "DIV", "DATE_T", "ASC", "ORDER", "BY", "GROUP", "AGGR_MAX",
  "AGGR_MIN", "AGGR_SUM", "AGGR_AVG", "AGGR_COUNT", "NULL_VALUE",
  "NULLABLE", "NOT", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM",
  "WHERE", "AND", "SET", "ON", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT",
  "LE", "GE", "NE", "NUMBER", "FLOAT", "ID", "PATH", "SSS", "STAR",
  "STRING_V", "DATE_STR", "$accept", "commands", "command", "exit", "help",
  "sync", "begin", "commit", "rollback", "drop_table", "show_tables",
  "desc_table", "create_index", "drop_index", "show_index", "create_table",
  "attr_def_list", "attr_def", "number", "type", "ID_get", "insert",
  "value_list", "mul_expr", "add_expr", "condition", "unary_expr",
  "aggr_func_type", "aggr_func_expr", "value", "delete", "update",
  "select", "select_attr", "attr_list", "rel_list", "where",
  "condition_list", "sort_unit", "sort_list", "opt_order_by",
  "groupby_unit", "groupby_list", "opt_group_by", "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -136,     2,  -136,    78,    79,     4,   -57,    88,     6,   -12,
     -21,   -15,    48,    96,   101,   104,   110,    70,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,    65,    66,    69,
      73,   103,   116,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,   112,  -136,   138,  -136,   -19,     9,  -136,   141,  -136,
    -136,   115,   155,   159,   120,  -136,   106,   111,   123,  -136,
    -136,  -136,  -136,  -136,   121,   165,   125,   179,   181,   142,
      -7,    37,  -136,  -136,  -136,     8,    41,  -136,   153,   153,
     103,   103,  -136,    56,   130,  -136,  -136,   134,   150,   151,
     137,   139,   140,   143,  -136,  -136,   144,  -136,  -136,  -136,
    -136,   138,   158,   138,     9,  -136,  -136,   -19,   -19,   187,
      35,   189,   205,   193,   103,   207,   157,   168,  -136,   198,
     102,   202,  -136,    18,  -136,  -136,  -136,  -136,   160,   151,
    -136,   133,    89,   171,  -136,   133,   215,   140,   206,  -136,
    -136,  -136,  -136,    15,   162,   138,   189,   195,   208,  -136,
    -136,  -136,  -136,  -136,  -136,   103,   103,  -136,   151,   166,
     198,   224,   169,  -136,   192,   214,  -136,  -136,   201,   203,
     133,   216,    84,   171,   231,   233,  -136,  -136,  -136,   220,
    -136,   235,   177,   209,   238,   208,   239,  -136,  -136,  -136,
      72,  -136,    19,   225,  -136,   182,  -136,  -136,  -136,  -136,
     210,  -136,  -136,   183,   177,   204,   228,  -136,  -136,    16,
    -136,   188,   182,  -136,  -136,  -136,  -136
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    21,
      20,    15,    16,    17,    18,     9,    10,    11,    12,    13,
      14,     8,     5,     7,     6,     4,    19,     0,     0,     0,
       0,     0,     0,    65,    66,    67,    68,    69,    78,    72,
      74,    61,    76,    85,    77,    56,    85,    52,     0,    64,
      60,     0,     0,     0,     0,    24,     0,     0,     0,    25,
      26,    27,    23,    22,     0,     0,     0,     0,     0,    61,
       0,     0,    72,    74,    53,     0,     0,    82,     0,     0,
       0,     0,    84,     0,     0,    30,    29,     0,     0,    91,
       0,     0,     0,     0,    28,    32,     0,    63,    73,    75,
      62,    85,    61,    85,    85,    55,    54,    57,    58,     0,
       0,    89,     0,     0,     0,     0,     0,     0,    48,    35,
       0,     0,    83,     0,    86,    88,    71,    70,     0,    91,
      33,     0,     0,    93,    79,     0,     0,     0,     0,    44,
      45,    46,    47,    38,     0,    85,    89,   103,    50,   111,
     112,   113,   114,   115,   116,     0,     0,    92,    91,     0,
      35,     0,     0,    42,     0,     0,    87,    90,     0,   109,
       0,     0,    59,    93,     0,     0,    36,    34,    43,     0,
      41,     0,     0,     0,     0,    50,     0,    94,    80,   117,
      37,    31,    95,   102,   104,     0,    81,    51,    49,    40,
       0,    97,    98,     0,     0,   105,   108,   110,    39,    96,
     101,     0,     0,    99,   100,   106,   107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,    81,   105,  -136,  -136,
    -136,  -136,    54,    43,    -5,    87,   -39,  -136,  -136,  -117,
    -136,  -136,  -136,  -136,   -55,    98,  -135,    74,  -136,    42,
    -136,  -136,    33,  -136,  -136,  -136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   148,   129,   189,   153,
     130,    32,   181,    55,   142,   143,    57,    58,    59,    60,
      33,    34,    35,    61,    87,   139,   125,   167,   203,   204,
     179,   216,   217,   194,   165,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    92,     2,    84,   157,    62,     3,     4,    88,    65,
     107,     5,     6,     7,     8,     9,    10,    11,    90,    91,
      41,    12,    13,    14,   158,    67,   223,    86,   168,   211,
      42,   172,    66,   184,    90,    91,    80,    43,    44,    45,
      46,    47,    48,    15,    16,   224,    89,    68,   212,   115,
     116,    69,   137,    17,   173,   174,   132,    41,   134,   135,
      90,    91,   213,   195,    49,    50,    51,    42,    52,    53,
     110,    54,    41,   111,    43,    44,    45,    46,    47,    48,
     110,   114,    42,   155,    37,    39,    38,    40,   120,    43,
      44,    45,    46,    47,    48,    63,    64,   108,   109,    70,
     176,    49,    50,   112,    71,    52,   113,    72,    54,    90,
      91,   209,   210,    73,    90,    91,    49,    50,    79,    41,
      52,   119,    74,    54,   149,   150,   151,    75,    76,    42,
     152,    77,    41,   117,   118,    78,    43,    44,    45,    46,
      47,    48,    81,   159,   160,   161,   162,   163,   164,    43,
      44,    45,    46,    47,    48,    85,    86,    93,    95,    81,
     182,    94,    96,    49,    50,    79,    97,    52,    98,    41,
      54,    48,   100,    99,   101,   103,    82,    83,    79,    81,
      52,   102,   104,    54,   105,   106,    43,    44,    45,    46,
      47,    48,   121,    49,    50,   123,   122,    52,   124,   126,
      54,   133,   128,   127,   136,   131,   110,   138,   140,   141,
     144,   145,   146,    49,    50,    79,   147,    52,   154,   166,
      54,   169,   156,   171,   175,   178,   180,   187,   185,   188,
     190,   191,   192,   196,   198,   193,   199,   200,   201,   202,
     205,   206,   208,   214,   215,   219,   222,   221,   218,   207,
     225,   186,   170,   183,   177,   226,   220,   197
};

static const yytype_uint8 yycheck[] =
{
       5,    56,     0,    42,   139,    62,     4,     5,    27,     3,
      17,     9,    10,    11,    12,    13,    14,    15,    25,    26,
      16,    19,    20,    21,   141,    46,    10,    18,   145,    10,
      26,    16,    44,   168,    25,    26,    41,    33,    34,    35,
      36,    37,    38,    41,    42,    29,    65,    62,    29,    88,
      89,     3,    17,    51,    39,    40,   111,    16,   113,   114,
      25,    26,    43,   180,    60,    61,    62,    26,    64,    65,
      62,    67,    16,    65,    33,    34,    35,    36,    37,    38,
      62,    86,    26,    65,     6,     6,     8,     8,    93,    33,
      34,    35,    36,    37,    38,     7,     8,    60,    61,     3,
     155,    60,    61,    62,     3,    64,    65,     3,    67,    25,
      26,    39,    40,     3,    25,    26,    60,    61,    62,    16,
      64,    65,    52,    67,    22,    23,    24,    62,    62,    26,
      28,    62,    16,    90,    91,    62,    33,    34,    35,    36,
      37,    38,    26,    54,    55,    56,    57,    58,    59,    33,
      34,    35,    36,    37,    38,    43,    18,    16,     3,    26,
     165,    46,     3,    60,    61,    62,    46,    64,    62,    16,
      67,    38,    49,    62,    53,    50,    60,    61,    62,    26,
      64,    16,     3,    67,     3,    43,    33,    34,    35,    36,
      37,    38,    62,    60,    61,    45,    62,    64,    47,    62,
      67,    43,    62,    64,    17,    62,    62,    18,     3,    16,
       3,    54,    44,    60,    61,    62,    18,    64,    16,    48,
      67,     6,    62,    17,    62,    30,    18,     3,    62,    60,
      38,    17,    31,    17,     3,    32,     3,    17,     3,    62,
      31,     3,     3,    18,    62,    62,    18,    43,    38,   195,
      62,   170,   147,   166,   156,   222,   214,   183
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    69,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    41,    42,    51,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    89,    98,    99,   100,   113,     6,     8,     6,
       8,    16,    26,    33,    34,    35,    36,    37,    38,    60,
      61,    62,    64,    65,    67,    91,    92,    94,    95,    96,
      97,   101,    62,     7,     8,     3,    44,    46,    62,     3,
       3,     3,     3,     3,    52,    62,    62,    62,    62,    62,
      92,    26,    60,    61,    94,    43,    18,   102,    27,    65,
      25,    26,   102,    16,    46,     3,     3,    46,    62,    62,
      49,    53,    16,    50,     3,     3,    43,    17,    60,    61,
      62,    65,    62,    65,    92,    94,    94,    91,    91,    65,
      92,    62,    62,    45,    47,   104,    62,    64,    62,    85,
      88,    62,   102,    43,   102,   102,    17,    17,    18,   103,
       3,    16,    92,    93,     3,    54,    44,    18,    84,    22,
      23,    24,    28,    87,    16,    65,    62,   104,    97,    54,
      55,    56,    57,    58,    59,   112,    48,   105,    97,     6,
      85,    17,    16,    39,    40,    62,   102,   103,    30,   108,
      18,    90,    92,    93,   104,    62,    84,     3,    60,    86,
      38,    17,    31,    32,   111,    97,    17,   105,     3,     3,
      17,     3,    62,   106,   107,    31,     3,    90,     3,    39,
      40,    10,    29,    43,    18,    62,   109,   110,    38,    62,
     107,    43,    18,    10,    29,    62,   110
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    84,    85,    85,    85,
      85,    85,    85,    86,    87,    87,    87,    87,    88,    89,
      90,    90,    91,    91,    91,    91,    92,    92,    92,    93,
      94,    94,    94,    94,    94,    95,    95,    95,    95,    95,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    98,
      99,   100,   101,   101,   101,   102,   102,   102,   102,   103,
     103,   104,   104,   105,   105,   106,   106,   106,   106,   106,
     106,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   112,   112,   112,   112,   113
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       3,     9,     4,     5,     8,     0,     3,     5,     2,     7,
       6,     4,     3,     1,     1,     1,     1,     1,     1,     9,
       0,     3,     1,     2,     3,     3,     1,     3,     3,     3,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       4,     4,     1,     2,     1,     2,     1,     1,     1,     5,
       8,     9,     2,     4,     2,     0,     3,     5,     3,     0,
       3,     0,     3,     0,     3,     1,     3,     2,     2,     4,
       4,     3,     1,     0,     3,     1,     3,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     8
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
        yyerror (scanner, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner);
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
                 int yyrule, void *scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *scanner)
{
  YY_USE (yyvaluep);
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
yyparse (void *scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

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
      yychar = yylex (&yylval, scanner);
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
  case 22: /* exit: EXIT SEMICOLON  */
#line 216 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1424 "yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 221 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1432 "yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 226 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1440 "yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 232 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1448 "yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 238 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1456 "yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 244 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1464 "yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 250 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1473 "yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 256 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1481 "yacc_sql.tab.c"
    break;

  case 30: /* desc_table: DESC ID SEMICOLON  */
#line 262 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1490 "yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID RBRACE SEMICOLON  */
#line 270 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string));
		}
#line 1499 "yacc_sql.tab.c"
    break;

  case 32: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 278 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1508 "yacc_sql.tab.c"
    break;

  case 33: /* show_index: SHOW INDEX FROM ID SEMICOLON  */
#line 285 "yacc_sql.y"
                                             {
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
		}
#line 1517 "yacc_sql.tab.c"
    break;

  case 34: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 293 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1529 "yacc_sql.tab.c"
    break;

  case 36: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 303 "yacc_sql.y"
                                   {    }
#line 1535 "yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 308 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-3].number), (yyvsp[-1].number), FALSE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1550 "yacc_sql.tab.c"
    break;

  case 38: /* attr_def: ID_get type  */
#line 319 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 4, FALSE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1565 "yacc_sql.tab.c"
    break;

  case 39: /* attr_def: ID_get type LBRACE number RBRACE NOT NULL_VALUE  */
#line 331 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-5].number), (yyvsp[-3].number), FALSE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1576 "yacc_sql.tab.c"
    break;

  case 40: /* attr_def: ID_get type LBRACE number RBRACE NULLABLE  */
#line 338 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-4].number), (yyvsp[-2].number), TRUE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1587 "yacc_sql.tab.c"
    break;

  case 41: /* attr_def: ID_get type NOT NULL_VALUE  */
#line 345 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-2].number), 4, FALSE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1598 "yacc_sql.tab.c"
    break;

  case 42: /* attr_def: ID_get type NULLABLE  */
#line 352 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-1].number), 4, TRUE);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
#line 1609 "yacc_sql.tab.c"
    break;

  case 43: /* number: NUMBER  */
#line 360 "yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1615 "yacc_sql.tab.c"
    break;

  case 44: /* type: INT_T  */
#line 363 "yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1621 "yacc_sql.tab.c"
    break;

  case 45: /* type: STRING_T  */
#line 364 "yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1627 "yacc_sql.tab.c"
    break;

  case 46: /* type: FLOAT_T  */
#line 365 "yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1633 "yacc_sql.tab.c"
    break;

  case 47: /* type: DATE_T  */
#line 366 "yacc_sql.y"
                    { (yyval.number)=DATES; }
#line 1639 "yacc_sql.tab.c"
    break;

  case 48: /* ID_get: ID  */
#line 370 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1648 "yacc_sql.tab.c"
    break;

  case 49: /* insert: INSERT INTO ID VALUES LBRACE value value_list RBRACE SEMICOLON  */
#line 379 "yacc_sql.y"
                {
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-6].string), CONTEXT->values, CONTEXT->value_length);

      //临时变量清零
      CONTEXT->value_length=0;
    }
#line 1667 "yacc_sql.tab.c"
    break;

  case 51: /* value_list: COMMA value value_list  */
#line 396 "yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1675 "yacc_sql.tab.c"
    break;

  case 52: /* mul_expr: unary_expr  */
#line 402 "yacc_sql.y"
               {
      (yyval.exp2) = (yyvsp[0].exp1);
    }
#line 1683 "yacc_sql.tab.c"
    break;

  case 53: /* mul_expr: SUB unary_expr  */
#line 405 "yacc_sql.y"
                     {
      Value * tmp_val = malloc(sizeof(Value));
      value_init_integer(tmp_val, -1);
      UnaryExpr * tmp_uexpr = malloc(sizeof(UnaryExpr));
      unary_expr_init_value(tmp_uexpr, tmp_val);
      Expr * tmp_expr = malloc(sizeof(Expr));
      expr_init_unary(tmp_expr, tmp_uexpr);

      Expr * expr = malloc(sizeof(Expr));
      BinaryExpr * b_expr = malloc(sizeof(BinaryExpr));
      binary_expr_init(b_expr, MUL_OP, tmp_expr, (yyvsp[0].exp1));
      binary_expr_set_minus(b_expr);
      expr_init_binary(expr, b_expr);
      (yyval.exp2) = expr;
    }
#line 1703 "yacc_sql.tab.c"
    break;

  case 54: /* mul_expr: mul_expr STAR unary_expr  */
#line 420 "yacc_sql.y"
                               {
      Expr * expr = malloc(sizeof(Expr));
      BinaryExpr * b_expr = malloc(sizeof(BinaryExpr));
      binary_expr_init(b_expr, MUL_OP, (yyvsp[-2].exp2), (yyvsp[0].exp1));
      expr_init_binary(expr, b_expr);
      (yyval.exp2) = expr;
    }
#line 1715 "yacc_sql.tab.c"
    break;

  case 55: /* mul_expr: mul_expr DIV unary_expr  */
#line 427 "yacc_sql.y"
                              {
    	Expr * expr = malloc(sizeof(Expr));
      BinaryExpr * b_expr = malloc(sizeof(BinaryExpr));
      binary_expr_init(b_expr, DIV_OP, (yyvsp[-2].exp2), (yyvsp[0].exp1));
      expr_init_binary(expr, b_expr);
      (yyval.exp2) = expr;
    }
#line 1727 "yacc_sql.tab.c"
    break;

  case 56: /* add_expr: mul_expr  */
#line 437 "yacc_sql.y"
             { (yyval.exp3) = (yyvsp[0].exp2); }
#line 1733 "yacc_sql.tab.c"
    break;

  case 57: /* add_expr: add_expr ADD mul_expr  */
#line 438 "yacc_sql.y"
                            {
    	Expr * expr = malloc(sizeof(Expr));
      BinaryExpr * b_expr = malloc(sizeof(BinaryExpr));
      binary_expr_init(b_expr, ADD_OP, (yyvsp[-2].exp3), (yyvsp[0].exp2));
      expr_init_binary(expr, b_expr);
      (yyval.exp3) = expr;
    }
#line 1745 "yacc_sql.tab.c"
    break;

  case 58: /* add_expr: add_expr SUB mul_expr  */
#line 445 "yacc_sql.y"
                            {
    	Expr * expr = malloc(sizeof(Expr));
      BinaryExpr * b_expr = malloc(sizeof(BinaryExpr));
      binary_expr_init(b_expr, SUB_OP, (yyvsp[-2].exp3), (yyvsp[0].exp2));
      expr_init_binary(expr, b_expr);
      (yyval.exp3) = expr;
    }
#line 1757 "yacc_sql.tab.c"
    break;

  case 59: /* condition: add_expr comOp add_expr  */
#line 455 "yacc_sql.y"
                           {
      Condition expr;
      condition_init(&expr, CONTEXT->comp, (yyvsp[-2].exp3), (yyvsp[0].exp3));
      condition_print(&expr, 0);
      CONTEXT->conditions[CONTEXT->condition_length++] = expr;
    }
#line 1768 "yacc_sql.tab.c"
    break;

  case 60: /* unary_expr: value  */
#line 464 "yacc_sql.y"
          {
    	Expr *expr = malloc(sizeof(Expr));
      UnaryExpr* u_expr = malloc(sizeof(UnaryExpr));
      unary_expr_init_value(u_expr, &CONTEXT->values[CONTEXT->value_length-1]);
      expr_init_unary(expr, u_expr);
      (yyval.exp1) = expr;
    }
#line 1780 "yacc_sql.tab.c"
    break;

  case 61: /* unary_expr: ID  */
#line 471 "yacc_sql.y"
         {
    	Expr *expr = malloc(sizeof(Expr));
      RelAttr attr;
      relation_attr_init(&attr, NULL, (yyvsp[0].string));
      UnaryExpr* u_expr = malloc(sizeof(UnaryExpr));
      unary_expr_init_attr(u_expr, &attr);
      expr_init_unary(expr, u_expr);
      (yyval.exp1) = expr;
    }
#line 1794 "yacc_sql.tab.c"
    break;

  case 62: /* unary_expr: ID DOT ID  */
#line 480 "yacc_sql.y"
                {
    	Expr *expr = malloc(sizeof(Expr));
      RelAttr attr;
      relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
      UnaryExpr* u_expr = malloc(sizeof(UnaryExpr));
      unary_expr_init_attr(u_expr, &attr);
      expr_init_unary(expr, u_expr);
      (yyval.exp1) = expr;
    }
#line 1808 "yacc_sql.tab.c"
    break;

  case 63: /* unary_expr: LBRACE add_expr RBRACE  */
#line 489 "yacc_sql.y"
                             {
      expr_set_with_brace((yyvsp[-1].exp3));
      (yyval.exp1) = (yyvsp[-1].exp3);
    }
#line 1817 "yacc_sql.tab.c"
    break;

  case 64: /* unary_expr: aggr_func_expr  */
#line 493 "yacc_sql.y"
                     {
      (yyval.exp1) = (yyvsp[0].exp4);
    }
#line 1825 "yacc_sql.tab.c"
    break;

  case 65: /* aggr_func_type: AGGR_MAX  */
#line 499 "yacc_sql.y"
             {
      CONTEXT->aggrfunctype = MAX;
    }
#line 1833 "yacc_sql.tab.c"
    break;

  case 66: /* aggr_func_type: AGGR_MIN  */
#line 502 "yacc_sql.y"
               {
      CONTEXT->aggrfunctype = MIN;
    }
#line 1841 "yacc_sql.tab.c"
    break;

  case 67: /* aggr_func_type: AGGR_SUM  */
#line 505 "yacc_sql.y"
               {
      CONTEXT->aggrfunctype = SUM;
    }
#line 1849 "yacc_sql.tab.c"
    break;

  case 68: /* aggr_func_type: AGGR_AVG  */
#line 508 "yacc_sql.y"
               {
      CONTEXT->aggrfunctype = AVG;
    }
#line 1857 "yacc_sql.tab.c"
    break;

  case 69: /* aggr_func_type: AGGR_COUNT  */
#line 511 "yacc_sql.y"
                 {
      CONTEXT->aggrfunctype = COUNT;
    }
#line 1865 "yacc_sql.tab.c"
    break;

  case 70: /* aggr_func_expr: aggr_func_type LBRACE add_expr RBRACE  */
#line 518 "yacc_sql.y"
    {
      AggrFuncExpr* afexpr = malloc(sizeof(AggrFuncExpr));
      aggr_func_expr_init(afexpr, CONTEXT->aggrfunctype, (yyvsp[-1].exp3));
      Expr* expr = malloc(sizeof(Expr));
      expr_init_aggr_func(expr, afexpr);
      (yyval.exp4) = expr;
    }
#line 1877 "yacc_sql.tab.c"
    break;

  case 71: /* aggr_func_expr: aggr_func_type LBRACE STAR RBRACE  */
#line 526 "yacc_sql.y"
    {
      if (CONTEXT->aggrfunctype != COUNT) {
        return -1;
      }
      // regard as a string value
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], "*");

    	Expr *param = malloc(sizeof(Expr));
      UnaryExpr* u_expr = malloc(sizeof(UnaryExpr));
      unary_expr_init_value(u_expr, &CONTEXT->values[CONTEXT->value_length-1]);
      expr_init_unary(param, u_expr);

      AggrFuncExpr* afexpr = malloc(sizeof(AggrFuncExpr));
      aggr_func_expr_init(afexpr, COUNT, param);
      Expr* expr = malloc(sizeof(Expr));
      expr_init_aggr_func(expr, afexpr);
      (yyval.exp4) = expr;
    }
#line 1900 "yacc_sql.tab.c"
    break;

  case 72: /* value: NUMBER  */
#line 548 "yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1908 "yacc_sql.tab.c"
    break;

  case 73: /* value: SUB NUMBER  */
#line 551 "yacc_sql.y"
                    {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], -((yyvsp[0].number)));
		}
#line 1916 "yacc_sql.tab.c"
    break;

  case 74: /* value: FLOAT  */
#line 554 "yacc_sql.y"
         {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1924 "yacc_sql.tab.c"
    break;

  case 75: /* value: SUB FLOAT  */
#line 557 "yacc_sql.y"
             {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], -((yyvsp[0].floats)));
		}
#line 1932 "yacc_sql.tab.c"
    break;

  case 76: /* value: SSS  */
#line 561 "yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		}
#line 1941 "yacc_sql.tab.c"
    break;

  case 77: /* value: DATE_STR  */
#line 565 "yacc_sql.y"
                  {
			int p1 = find((yyvsp[0].string),1,"-");
			int p2 = find((yyvsp[0].string),p1+1,"-");
			char *y = substr((yyvsp[0].string),1,p1-1);							// year
			char *m = substr((yyvsp[0].string),p1+1,p2-1);						// month
			char *d = substr((yyvsp[0].string),p2+1,strlen((yyvsp[0].string))-2);		// day
			if (0 != value_init_date(&CONTEXT->values[CONTEXT->value_length++], y, m, d)){
				return -1;
			}
		}
#line 1956 "yacc_sql.tab.c"
    break;

  case 78: /* value: NULL_VALUE  */
#line 575 "yacc_sql.y"
              {
      value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
    }
#line 1964 "yacc_sql.tab.c"
    break;

  case 79: /* delete: DELETE FROM ID where SEMICOLON  */
#line 582 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1976 "yacc_sql.tab.c"
    break;

  case 80: /* update: UPDATE ID SET ID EQ value where SEMICOLON  */
#line 592 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1988 "yacc_sql.tab.c"
    break;

  case 81: /* select: SELECT select_attr FROM ID rel_list where opt_order_by opt_group_by SEMICOLON  */
#line 602 "yacc_sql.y"
                {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			selects_append_orderbys(&CONTEXT->ssql->sstr.selection, CONTEXT->orderbys, CONTEXT->orderby_length);

			selects_append_groupbys(&CONTEXT->ssql->sstr.selection, CONTEXT->groupbys, CONTEXT->groupby_length);

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;

			//临时变量清零
			CONTEXT->groupby_length=0;
      CONTEXT->orderby_length=0;
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
	}
#line 2014 "yacc_sql.tab.c"
    break;

  case 82: /* select_attr: STAR attr_list  */
#line 628 "yacc_sql.y"
                   {  
			ProjectCol project_col;
			projectcol_init_star(&project_col, NULL);
			selects_append_projects(&CONTEXT->ssql->sstr.selection, &project_col);
		}
#line 2024 "yacc_sql.tab.c"
    break;

  case 83: /* select_attr: ID DOT STAR attr_list  */
#line 634 "yacc_sql.y"
                         {
      ProjectCol project_col;
			projectcol_init_star(&project_col, (yyvsp[-3].string));
			selects_append_projects(&CONTEXT->ssql->sstr.selection, &project_col);
    }
#line 2034 "yacc_sql.tab.c"
    break;

  case 84: /* select_attr: add_expr attr_list  */
#line 640 "yacc_sql.y"
                      {
      ProjectCol project_col;
      projectcol_init_expr(&project_col, (yyvsp[-1].exp3));
      selects_append_projects(&CONTEXT->ssql->sstr.selection, &project_col);
    }
#line 2044 "yacc_sql.tab.c"
    break;

  case 86: /* attr_list: COMMA STAR attr_list  */
#line 649 "yacc_sql.y"
                           {  
			ProjectCol project_col;
			projectcol_init_star(&project_col, NULL);
			selects_append_projects(&CONTEXT->ssql->sstr.selection, &project_col);
		}
#line 2054 "yacc_sql.tab.c"
    break;

  case 87: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 655 "yacc_sql.y"
                                 {
      ProjectCol project_col;
			projectcol_init_star(&project_col, (yyvsp[-3].string));
			selects_append_projects(&CONTEXT->ssql->sstr.selection, &project_col);
    }
#line 2064 "yacc_sql.tab.c"
    break;

  case 88: /* attr_list: COMMA add_expr attr_list  */
#line 661 "yacc_sql.y"
                              {
      ProjectCol project_col;
      projectcol_init_expr(&project_col, (yyvsp[-1].exp3));
      selects_append_projects(&CONTEXT->ssql->sstr.selection, &project_col);
    }
#line 2074 "yacc_sql.tab.c"
    break;

  case 90: /* rel_list: COMMA ID rel_list  */
#line 670 "yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 2082 "yacc_sql.tab.c"
    break;

  case 92: /* where: WHERE condition condition_list  */
#line 676 "yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2090 "yacc_sql.tab.c"
    break;

  case 94: /* condition_list: AND condition condition_list  */
#line 682 "yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 2098 "yacc_sql.tab.c"
    break;

  case 95: /* sort_unit: ID  */
#line 690 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		OrderBy orderby;
		orderby_init(&orderby, TRUE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2110 "yacc_sql.tab.c"
    break;

  case 96: /* sort_unit: ID DOT ID  */
#line 699 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		OrderBy orderby;
		orderby_init(&orderby, TRUE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2122 "yacc_sql.tab.c"
    break;

  case 97: /* sort_unit: ID DESC  */
#line 708 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		OrderBy orderby;
		orderby_init(&orderby, FALSE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2134 "yacc_sql.tab.c"
    break;

  case 98: /* sort_unit: ID ASC  */
#line 717 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[-1].string));
		OrderBy orderby;
		orderby_init(&orderby, TRUE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2146 "yacc_sql.tab.c"
    break;

  case 99: /* sort_unit: ID DOT ID DESC  */
#line 726 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		OrderBy orderby;
		orderby_init(&orderby, FALSE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2158 "yacc_sql.tab.c"
    break;

  case 100: /* sort_unit: ID DOT ID ASC  */
#line 735 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
		OrderBy orderby;
		orderby_init(&orderby, TRUE, &attr);
		CONTEXT->orderbys[CONTEXT->orderby_length++] = orderby;
	}
#line 2170 "yacc_sql.tab.c"
    break;

  case 101: /* sort_list: sort_unit COMMA sort_list  */
#line 745 "yacc_sql.y"
                {
			
	}
#line 2178 "yacc_sql.tab.c"
    break;

  case 102: /* sort_list: sort_unit  */
#line 749 "yacc_sql.y"
                {
			
	}
#line 2186 "yacc_sql.tab.c"
    break;

  case 104: /* opt_order_by: ORDER BY sort_list  */
#line 756 "yacc_sql.y"
                {

	}
#line 2194 "yacc_sql.tab.c"
    break;

  case 105: /* groupby_unit: ID  */
#line 764 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, NULL, (yyvsp[0].string));
		CONTEXT->groupbys[CONTEXT->groupby_length++] = attr;
	}
#line 2204 "yacc_sql.tab.c"
    break;

  case 106: /* groupby_unit: ID DOT ID  */
#line 771 "yacc_sql.y"
        {
		RelAttr attr;
		relation_attr_init(&attr, (yyvsp[-2].string), (yyvsp[0].string));
		CONTEXT->groupbys[CONTEXT->groupby_length++] = attr;
	}
#line 2214 "yacc_sql.tab.c"
    break;

  case 107: /* groupby_list: groupby_unit COMMA groupby_list  */
#line 780 "yacc_sql.y"
                {
			
	}
#line 2222 "yacc_sql.tab.c"
    break;

  case 108: /* groupby_list: groupby_unit  */
#line 784 "yacc_sql.y"
                {
			
	}
#line 2230 "yacc_sql.tab.c"
    break;

  case 110: /* opt_group_by: GROUP BY groupby_list  */
#line 791 "yacc_sql.y"
                {

	}
#line 2238 "yacc_sql.tab.c"
    break;

  case 111: /* comOp: EQ  */
#line 797 "yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2244 "yacc_sql.tab.c"
    break;

  case 112: /* comOp: LT  */
#line 798 "yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2250 "yacc_sql.tab.c"
    break;

  case 113: /* comOp: GT  */
#line 799 "yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2256 "yacc_sql.tab.c"
    break;

  case 114: /* comOp: LE  */
#line 800 "yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2262 "yacc_sql.tab.c"
    break;

  case 115: /* comOp: GE  */
#line 801 "yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2268 "yacc_sql.tab.c"
    break;

  case 116: /* comOp: NE  */
#line 802 "yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2274 "yacc_sql.tab.c"
    break;

  case 117: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 807 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2283 "yacc_sql.tab.c"
    break;


#line 2287 "yacc_sql.tab.c"

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
      yyerror (scanner, YY_("syntax error"));
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
                      yytoken, &yylval, scanner);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner);
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
  yyerror (scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 812 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
