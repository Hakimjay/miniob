/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_SQL_TAB_H_INCLUDED
# define YY_YY_YACC_SQL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    CREATE = 259,                  /* CREATE  */
    DROP = 260,                    /* DROP  */
    TABLE = 261,                   /* TABLE  */
    TABLES = 262,                  /* TABLES  */
    INDEX = 263,                   /* INDEX  */
    SELECT = 264,                  /* SELECT  */
    DESC = 265,                    /* DESC  */
    SHOW = 266,                    /* SHOW  */
    SYNC = 267,                    /* SYNC  */
    INSERT = 268,                  /* INSERT  */
    DELETE = 269,                  /* DELETE  */
    UPDATE = 270,                  /* UPDATE  */
    LBRACE = 271,                  /* LBRACE  */
    RBRACE = 272,                  /* RBRACE  */
    COMMA = 273,                   /* COMMA  */
    TRX_BEGIN = 274,               /* TRX_BEGIN  */
    TRX_COMMIT = 275,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 276,            /* TRX_ROLLBACK  */
    INT_T = 277,                   /* INT_T  */
    STRING_T = 278,                /* STRING_T  */
    FLOAT_T = 279,                 /* FLOAT_T  */
    ADD = 280,                     /* ADD  */
    SUB = 281,                     /* SUB  */
    DIV = 282,                     /* DIV  */
    DATE_T = 283,                  /* DATE_T  */
    ASC = 284,                     /* ASC  */
    ORDER = 285,                   /* ORDER  */
    BY = 286,                      /* BY  */
    GROUP = 287,                   /* GROUP  */
    HAVING = 288,                  /* HAVING  */
    AGGR_MAX = 289,                /* AGGR_MAX  */
    AGGR_MIN = 290,                /* AGGR_MIN  */
    AGGR_SUM = 291,                /* AGGR_SUM  */
    AGGR_AVG = 292,                /* AGGR_AVG  */
    AGGR_COUNT = 293,              /* AGGR_COUNT  */
    NULL_VALUE = 294,              /* NULL_VALUE  */
    NULLABLE = 295,                /* NULLABLE  */
    NOT = 296,                     /* NOT  */
    IS = 297,                      /* IS  */
    IN = 298,                      /* IN  */
    EXISTS = 299,                  /* EXISTS  */
    HELP = 300,                    /* HELP  */
    EXIT = 301,                    /* EXIT  */
    DOT = 302,                     /* DOT  */
    INTO = 303,                    /* INTO  */
    VALUES = 304,                  /* VALUES  */
    FROM = 305,                    /* FROM  */
    WHERE = 306,                   /* WHERE  */
    AND = 307,                     /* AND  */
    SET = 308,                     /* SET  */
    ON = 309,                      /* ON  */
    LOAD = 310,                    /* LOAD  */
    DATA = 311,                    /* DATA  */
    INFILE = 312,                  /* INFILE  */
    EQ = 313,                      /* EQ  */
    LT = 314,                      /* LT  */
    GT = 315,                      /* GT  */
    LE = 316,                      /* LE  */
    GE = 317,                      /* GE  */
    NE = 318,                      /* NE  */
    NUMBER = 319,                  /* NUMBER  */
    FLOAT = 320,                   /* FLOAT  */
    ID = 321,                      /* ID  */
    PATH = 322,                    /* PATH  */
    SSS = 323,                     /* SSS  */
    STAR = 324,                    /* STAR  */
    STRING_V = 325,                /* STRING_V  */
    DATE_STR = 326                 /* DATE_STR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 169 "yacc_sql.y"

  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;

  struct _UnaryExpr* uexp1;
  struct _Expr* exp1;
  struct _Expr* exp2;
  struct _Expr* exp3;
  struct _Expr* exp4;
  struct _Expr* exp6;
  struct _Expr* exp7;
  struct _FromInfo* from_info;

  char *string;
  int number;
  float floats;
  int cur_len;
  int comp_op;
char *position;

#line 157 "yacc_sql.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void *scanner);


#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */
