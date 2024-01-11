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
    UNIQUE = 280,                  /* UNIQUE  */
    ADD = 281,                     /* ADD  */
    SUB = 282,                     /* SUB  */
    DIV = 283,                     /* DIV  */
    DATE_T = 284,                  /* DATE_T  */
    ASC = 285,                     /* ASC  */
    ORDER = 286,                   /* ORDER  */
    BY = 287,                      /* BY  */
    GROUP = 288,                   /* GROUP  */
    HAVING = 289,                  /* HAVING  */
    AGGR_MAX = 290,                /* AGGR_MAX  */
    AGGR_MIN = 291,                /* AGGR_MIN  */
    AGGR_SUM = 292,                /* AGGR_SUM  */
    AGGR_AVG = 293,                /* AGGR_AVG  */
    AGGR_COUNT = 294,              /* AGGR_COUNT  */
    NULL_VALUE = 295,              /* NULL_VALUE  */
    NULLABLE = 296,                /* NULLABLE  */
    NOT = 297,                     /* NOT  */
    IS = 298,                      /* IS  */
    IN = 299,                      /* IN  */
    EXISTS = 300,                  /* EXISTS  */
    HELP = 301,                    /* HELP  */
    EXIT = 302,                    /* EXIT  */
    DOT = 303,                     /* DOT  */
    INTO = 304,                    /* INTO  */
    VALUES = 305,                  /* VALUES  */
    FROM = 306,                    /* FROM  */
    WHERE = 307,                   /* WHERE  */
    AND = 308,                     /* AND  */
    SET = 309,                     /* SET  */
    ON = 310,                      /* ON  */
    LOAD = 311,                    /* LOAD  */
    DATA = 312,                    /* DATA  */
    INFILE = 313,                  /* INFILE  */
    EQ = 314,                      /* EQ  */
    LT = 315,                      /* LT  */
    GT = 316,                      /* GT  */
    LE = 317,                      /* LE  */
    GE = 318,                      /* GE  */
    NE = 319,                      /* NE  */
    NUMBER = 320,                  /* NUMBER  */
    FLOAT = 321,                   /* FLOAT  */
    ID = 322,                      /* ID  */
    PATH = 323,                    /* PATH  */
    SSS = 324,                     /* SSS  */
    STAR = 325,                    /* STAR  */
    STRING_V = 326,                /* STRING_V  */
    DATE_STR = 327                 /* DATE_STR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 171 "yacc_sql.y"

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

#line 158 "yacc_sql.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void *scanner);


#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */
