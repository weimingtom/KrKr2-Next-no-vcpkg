// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file tjs.tab.hpp
 ** Define the TJS::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_TJS_TAB_HPP_INCLUDED
# define YY_YY_TJS_TAB_HPP_INCLUDED
// "%code requires" blocks.
#line 37 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"

namespace TJS {
    class tTJSExprNode;
}

#line 55 "tjs.tab.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 6 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
namespace TJS {
#line 191 "tjs.tab.hpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
    /// Symbol semantic values.
    union value_type
    {
#line 32 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"

	tjs_int			num;
	tTJSExprNode *		np;

#line 214 "tjs.tab.hpp"

    };
#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    T_COMMA = 258,                 // ","
    T_EQUAL = 259,                 // "="
    T_AMPERSANDEQUAL = 260,        // "&="
    T_VERTLINEEQUAL = 261,         // "|="
    T_CHEVRONEQUAL = 262,          // "^="
    T_MINUSEQUAL = 263,            // "-="
    T_PLUSEQUAL = 264,             // "+="
    T_PERCENTEQUAL = 265,          // "%="
    T_SLASHEQUAL = 266,            // "/="
    T_BACKSLASHEQUAL = 267,        // "\\="
    T_ASTERISKEQUAL = 268,         // "*="
    T_LOGICALOREQUAL = 269,        // "||="
    T_LOGICALANDEQUAL = 270,       // "&&="
    T_RBITSHIFTEQUAL = 271,        // ">>>="
    T_LARITHSHIFTEQUAL = 272,      // "<<="
    T_RARITHSHIFTEQUAL = 273,      // ">>="
    T_QUESTION = 274,              // "?"
    T_LOGICALOR = 275,             // "||"
    T_LOGICALAND = 276,            // "&&"
    T_VERTLINE = 277,              // "|"
    T_CHEVRON = 278,               // "^"
    T_AMPERSAND = 279,             // "&"
    T_NOTEQUAL = 280,              // "!="
    T_EQUALEQUAL = 281,            // "=="
    T_DISCNOTEQUAL = 282,          // "!=="
    T_DISCEQUAL = 283,             // "==="
    T_SWAP = 284,                  // "<->"
    T_LT = 285,                    // "<"
    T_GT = 286,                    // ">"
    T_LTOREQUAL = 287,             // "<="
    T_GTOREQUAL = 288,             // ">="
    T_RARITHSHIFT = 289,           // ">>"
    T_LARITHSHIFT = 290,           // "<<"
    T_RBITSHIFT = 291,             // ">>>"
    T_PERCENT = 292,               // "%"
    T_SLASH = 293,                 // "/"
    T_BACKSLASH = 294,             // "\\"
    T_ASTERISK = 295,              // "*"
    T_EXCRAMATION = 296,           // "!"
    T_TILDE = 297,                 // "~"
    T_DECREMENT = 298,             // "--"
    T_INCREMENT = 299,             // "++"
    T_NEW = 300,                   // "new"
    T_DELETE = 301,                // "delete"
    T_TYPEOF = 302,                // "typeof"
    T_PLUS = 303,                  // "+"
    T_MINUS = 304,                 // "-"
    T_SHARP = 305,                 // "#"
    T_DOLLAR = 306,                // "$"
    T_ISVALID = 307,               // "isvalid"
    T_INVALIDATE = 308,            // "invalidate"
    T_INSTANCEOF = 309,            // "instanceof"
    T_LPARENTHESIS = 310,          // "("
    T_DOT = 311,                   // "."
    T_LBRACKET = 312,              // "["
    T_THIS = 313,                  // "this"
    T_SUPER = 314,                 // "super"
    T_GLOBAL = 315,                // "global"
    T_RBRACKET = 316,              // "]"
    T_CLASS = 317,                 // "class"
    T_RPARENTHESIS = 318,          // ")"
    T_COLON = 319,                 // ":"
    T_SEMICOLON = 320,             // ";"
    T_LBRACE = 321,                // "{"
    T_RBRACE = 322,                // "}"
    T_CONTINUE = 323,              // "continue"
    T_FUNCTION = 324,              // "function"
    T_DEBUGGER = 325,              // "debugger"
    T_DEFAULT = 326,               // "default"
    T_CASE = 327,                  // "case"
    T_EXTENDS = 328,               // "extends"
    T_FINALLY = 329,               // "finally"
    T_PROPERTY = 330,              // "property"
    T_PRIVATE = 331,               // "private"
    T_PUBLIC = 332,                // "public"
    T_PROTECTED = 333,             // "protected"
    T_STATIC = 334,                // "static"
    T_RETURN = 335,                // "return"
    T_BREAK = 336,                 // "break"
    T_EXPORT = 337,                // "export"
    T_IMPORT = 338,                // "import"
    T_SWITCH = 339,                // "switch"
    T_IN = 340,                    // "in"
    T_INCONTEXTOF = 341,           // "incontextof"
    T_FOR = 342,                   // "for"
    T_WHILE = 343,                 // "while"
    T_DO = 344,                    // "do"
    T_IF = 345,                    // "if"
    T_VAR = 346,                   // "var"
    T_CONST = 347,                 // "const"
    T_ENUM = 348,                  // "enum"
    T_GOTO = 349,                  // "goto"
    T_THROW = 350,                 // "throw"
    T_TRY = 351,                   // "try"
    T_SETTER = 352,                // "setter"
    T_GETTER = 353,                // "getter"
    T_ELSE = 354,                  // "else"
    T_CATCH = 355,                 // "catch"
    T_OMIT = 356,                  // "..."
    T_SYNCHRONIZED = 357,          // "synchronized"
    T_WITH = 358,                  // "with"
    T_INT = 359,                   // "int"
    T_REAL = 360,                  // "real"
    T_STRING = 361,                // "string"
    T_OCTET = 362,                 // "octet"
    T_FALSE = 363,                 // "false"
    T_NULL = 364,                  // "null"
    T_TRUE = 365,                  // "true"
    T_VOID = 366,                  // "void"
    T_NAN = 367,                   // "NaN"
    T_INFINITY = 368,              // "Infinity"
    T_UPLUS = 369,                 // T_UPLUS
    T_UMINUS = 370,                // T_UMINUS
    T_EVAL = 371,                  // T_EVAL
    T_POSTDECREMENT = 372,         // T_POSTDECREMENT
    T_POSTINCREMENT = 373,         // T_POSTINCREMENT
    T_IGNOREPROP = 374,            // T_IGNOREPROP
    T_PROPACCESS = 375,            // T_PROPACCESS
    T_ARG = 376,                   // T_ARG
    T_EXPANDARG = 377,             // T_EXPANDARG
    T_INLINEARRAY = 378,           // T_INLINEARRAY
    T_ARRAYARG = 379,              // T_ARRAYARG
    T_INLINEDIC = 380,             // T_INLINEDIC
    T_DICELM = 381,                // T_DICELM
    T_WITHDOT = 382,               // T_WITHDOT
    T_THIS_PROXY = 383,            // T_THIS_PROXY
    T_WITHDOT_PROXY = 384,         // T_WITHDOT_PROXY
    T_CONSTVAL = 385,              // T_CONSTVAL
    T_SYMBOL = 386,                // T_SYMBOL
    T_REGEXP = 387,                // T_REGEXP
    T_VARIANT = 388,               // T_VARIANT
    LOWER_ELSE = 389               // LOWER_ELSE
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 135, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_T_COMMA = 3,                           // ","
        S_T_EQUAL = 4,                           // "="
        S_T_AMPERSANDEQUAL = 5,                  // "&="
        S_T_VERTLINEEQUAL = 6,                   // "|="
        S_T_CHEVRONEQUAL = 7,                    // "^="
        S_T_MINUSEQUAL = 8,                      // "-="
        S_T_PLUSEQUAL = 9,                       // "+="
        S_T_PERCENTEQUAL = 10,                   // "%="
        S_T_SLASHEQUAL = 11,                     // "/="
        S_T_BACKSLASHEQUAL = 12,                 // "\\="
        S_T_ASTERISKEQUAL = 13,                  // "*="
        S_T_LOGICALOREQUAL = 14,                 // "||="
        S_T_LOGICALANDEQUAL = 15,                // "&&="
        S_T_RBITSHIFTEQUAL = 16,                 // ">>>="
        S_T_LARITHSHIFTEQUAL = 17,               // "<<="
        S_T_RARITHSHIFTEQUAL = 18,               // ">>="
        S_T_QUESTION = 19,                       // "?"
        S_T_LOGICALOR = 20,                      // "||"
        S_T_LOGICALAND = 21,                     // "&&"
        S_T_VERTLINE = 22,                       // "|"
        S_T_CHEVRON = 23,                        // "^"
        S_T_AMPERSAND = 24,                      // "&"
        S_T_NOTEQUAL = 25,                       // "!="
        S_T_EQUALEQUAL = 26,                     // "=="
        S_T_DISCNOTEQUAL = 27,                   // "!=="
        S_T_DISCEQUAL = 28,                      // "==="
        S_T_SWAP = 29,                           // "<->"
        S_T_LT = 30,                             // "<"
        S_T_GT = 31,                             // ">"
        S_T_LTOREQUAL = 32,                      // "<="
        S_T_GTOREQUAL = 33,                      // ">="
        S_T_RARITHSHIFT = 34,                    // ">>"
        S_T_LARITHSHIFT = 35,                    // "<<"
        S_T_RBITSHIFT = 36,                      // ">>>"
        S_T_PERCENT = 37,                        // "%"
        S_T_SLASH = 38,                          // "/"
        S_T_BACKSLASH = 39,                      // "\\"
        S_T_ASTERISK = 40,                       // "*"
        S_T_EXCRAMATION = 41,                    // "!"
        S_T_TILDE = 42,                          // "~"
        S_T_DECREMENT = 43,                      // "--"
        S_T_INCREMENT = 44,                      // "++"
        S_T_NEW = 45,                            // "new"
        S_T_DELETE = 46,                         // "delete"
        S_T_TYPEOF = 47,                         // "typeof"
        S_T_PLUS = 48,                           // "+"
        S_T_MINUS = 49,                          // "-"
        S_T_SHARP = 50,                          // "#"
        S_T_DOLLAR = 51,                         // "$"
        S_T_ISVALID = 52,                        // "isvalid"
        S_T_INVALIDATE = 53,                     // "invalidate"
        S_T_INSTANCEOF = 54,                     // "instanceof"
        S_T_LPARENTHESIS = 55,                   // "("
        S_T_DOT = 56,                            // "."
        S_T_LBRACKET = 57,                       // "["
        S_T_THIS = 58,                           // "this"
        S_T_SUPER = 59,                          // "super"
        S_T_GLOBAL = 60,                         // "global"
        S_T_RBRACKET = 61,                       // "]"
        S_T_CLASS = 62,                          // "class"
        S_T_RPARENTHESIS = 63,                   // ")"
        S_T_COLON = 64,                          // ":"
        S_T_SEMICOLON = 65,                      // ";"
        S_T_LBRACE = 66,                         // "{"
        S_T_RBRACE = 67,                         // "}"
        S_T_CONTINUE = 68,                       // "continue"
        S_T_FUNCTION = 69,                       // "function"
        S_T_DEBUGGER = 70,                       // "debugger"
        S_T_DEFAULT = 71,                        // "default"
        S_T_CASE = 72,                           // "case"
        S_T_EXTENDS = 73,                        // "extends"
        S_T_FINALLY = 74,                        // "finally"
        S_T_PROPERTY = 75,                       // "property"
        S_T_PRIVATE = 76,                        // "private"
        S_T_PUBLIC = 77,                         // "public"
        S_T_PROTECTED = 78,                      // "protected"
        S_T_STATIC = 79,                         // "static"
        S_T_RETURN = 80,                         // "return"
        S_T_BREAK = 81,                          // "break"
        S_T_EXPORT = 82,                         // "export"
        S_T_IMPORT = 83,                         // "import"
        S_T_SWITCH = 84,                         // "switch"
        S_T_IN = 85,                             // "in"
        S_T_INCONTEXTOF = 86,                    // "incontextof"
        S_T_FOR = 87,                            // "for"
        S_T_WHILE = 88,                          // "while"
        S_T_DO = 89,                             // "do"
        S_T_IF = 90,                             // "if"
        S_T_VAR = 91,                            // "var"
        S_T_CONST = 92,                          // "const"
        S_T_ENUM = 93,                           // "enum"
        S_T_GOTO = 94,                           // "goto"
        S_T_THROW = 95,                          // "throw"
        S_T_TRY = 96,                            // "try"
        S_T_SETTER = 97,                         // "setter"
        S_T_GETTER = 98,                         // "getter"
        S_T_ELSE = 99,                           // "else"
        S_T_CATCH = 100,                         // "catch"
        S_T_OMIT = 101,                          // "..."
        S_T_SYNCHRONIZED = 102,                  // "synchronized"
        S_T_WITH = 103,                          // "with"
        S_T_INT = 104,                           // "int"
        S_T_REAL = 105,                          // "real"
        S_T_STRING = 106,                        // "string"
        S_T_OCTET = 107,                         // "octet"
        S_T_FALSE = 108,                         // "false"
        S_T_NULL = 109,                          // "null"
        S_T_TRUE = 110,                          // "true"
        S_T_VOID = 111,                          // "void"
        S_T_NAN = 112,                           // "NaN"
        S_T_INFINITY = 113,                      // "Infinity"
        S_T_UPLUS = 114,                         // T_UPLUS
        S_T_UMINUS = 115,                        // T_UMINUS
        S_T_EVAL = 116,                          // T_EVAL
        S_T_POSTDECREMENT = 117,                 // T_POSTDECREMENT
        S_T_POSTINCREMENT = 118,                 // T_POSTINCREMENT
        S_T_IGNOREPROP = 119,                    // T_IGNOREPROP
        S_T_PROPACCESS = 120,                    // T_PROPACCESS
        S_T_ARG = 121,                           // T_ARG
        S_T_EXPANDARG = 122,                     // T_EXPANDARG
        S_T_INLINEARRAY = 123,                   // T_INLINEARRAY
        S_T_ARRAYARG = 124,                      // T_ARRAYARG
        S_T_INLINEDIC = 125,                     // T_INLINEDIC
        S_T_DICELM = 126,                        // T_DICELM
        S_T_WITHDOT = 127,                       // T_WITHDOT
        S_T_THIS_PROXY = 128,                    // T_THIS_PROXY
        S_T_WITHDOT_PROXY = 129,                 // T_WITHDOT_PROXY
        S_T_CONSTVAL = 130,                      // T_CONSTVAL
        S_T_SYMBOL = 131,                        // T_SYMBOL
        S_T_REGEXP = 132,                        // T_REGEXP
        S_T_VARIANT = 133,                       // T_VARIANT
        S_LOWER_ELSE = 134,                      // LOWER_ELSE
        S_YYACCEPT = 135,                        // $accept
        S_program = 136,                         // program
        S_global_list = 137,                     // global_list
        S_138_1 = 138,                           // $@1
        S_def_list = 139,                        // def_list
        S_block_or_statement = 140,              // block_or_statement
        S_statement = 141,                       // statement
        S_block = 142,                           // block
        S_143_2 = 143,                           // $@2
        S_while = 144,                           // while
        S_145_3 = 145,                           // $@3
        S_146_4 = 146,                           // $@4
        S_do_while = 147,                        // do_while
        S_148_5 = 148,                           // $@5
        S_149_6 = 149,                           // $@6
        S_if = 150,                              // if
        S_151_7 = 151,                           // $@7
        S_152_8 = 152,                           // $@8
        S_if_else = 153,                         // if_else
        S_154_9 = 154,                           // $@9
        S_for = 155,                             // for
        S_for_first_clause = 156,                // for_first_clause
        S_157_10 = 157,                          // $@10
        S_for_second_clause = 158,               // for_second_clause
        S_for_third_clause = 159,                // for_third_clause
        S_variable_def = 160,                    // variable_def
        S_variable_def_inner = 161,              // variable_def_inner
        S_variable_id_list = 162,                // variable_id_list
        S_variable_id = 163,                     // variable_id
        S_variable_type = 164,                   // variable_type
        S_func_def = 165,                        // func_def
        S_166_11 = 166,                          // $@11
        S_func_expr_def = 167,                   // func_expr_def
        S_168_12 = 168,                          // $@12
        S_func_decl_arg_opt = 169,               // func_decl_arg_opt
        S_func_decl_arg_list = 170,              // func_decl_arg_list
        S_func_decl_arg_at_least_one = 171,      // func_decl_arg_at_least_one
        S_func_decl_arg = 172,                   // func_decl_arg
        S_func_decl_arg_collapse = 173,          // func_decl_arg_collapse
        S_property_def = 174,                    // property_def
        S_175_13 = 175,                          // $@13
        S_property_handler_def_list = 176,       // property_handler_def_list
        S_property_handler_setter = 177,         // property_handler_setter
        S_178_14 = 178,                          // $@14
        S_property_handler_getter = 179,         // property_handler_getter
        S_180_15 = 180,                          // $@15
        S_property_getter_handler_head = 181,    // property_getter_handler_head
        S_class_def = 182,                       // class_def
        S_183_16 = 183,                          // $@16
        S_class_extender = 184,                  // class_extender
        S_185_17 = 185,                          // $@17
        S_extends_list = 186,                    // extends_list
        S_extends_name = 187,                    // extends_name
        S_return = 188,                          // return
        S_switch = 189,                          // switch
        S_190_18 = 190,                          // $@18
        S_with = 191,                            // with
        S_192_19 = 192,                          // $@19
        S_case = 193,                            // case
        S_try = 194,                             // try
        S_195_20 = 195,                          // $@20
        S_catch = 196,                           // catch
        S_throw = 197,                           // throw
        S_expr_no_comma = 198,                   // expr_no_comma
        S_expr = 199,                            // expr
        S_comma_expr = 200,                      // comma_expr
        S_assign_expr = 201,                     // assign_expr
        S_cond_expr = 202,                       // cond_expr
        S_logical_or_expr = 203,                 // logical_or_expr
        S_logical_and_expr = 204,                // logical_and_expr
        S_inclusive_or_expr = 205,               // inclusive_or_expr
        S_exclusive_or_expr = 206,               // exclusive_or_expr
        S_and_expr = 207,                        // and_expr
        S_identical_expr = 208,                  // identical_expr
        S_compare_expr = 209,                    // compare_expr
        S_shift_expr = 210,                      // shift_expr
        S_add_sub_expr = 211,                    // add_sub_expr
        S_mul_div_expr = 212,                    // mul_div_expr
        S_mul_div_expr_and_asterisk = 213,       // mul_div_expr_and_asterisk
        S_unary_expr = 214,                      // unary_expr
        S_incontextof_expr = 215,                // incontextof_expr
        S_priority_expr = 216,                   // priority_expr
        S_217_21 = 217,                          // $@21
        S_218_22 = 218,                          // $@22
        S_factor_expr = 219,                     // factor_expr
        S_220_23 = 220,                          // $@23
        S_221_24 = 221,                          // $@24
        S_func_call_expr = 222,                  // func_call_expr
        S_call_arg_list = 223,                   // call_arg_list
        S_call_arg = 224,                        // call_arg
        S_inline_array = 225,                    // inline_array
        S_226_25 = 226,                          // $@25
        S_array_elm_list = 227,                  // array_elm_list
        S_array_elm = 228,                       // array_elm
        S_inline_dic = 229,                      // inline_dic
        S_230_26 = 230,                          // $@26
        S_dic_elm_list = 231,                    // dic_elm_list
        S_dic_elm = 232,                         // dic_elm
        S_dic_dummy_elm_opt = 233,               // dic_dummy_elm_opt
        S_const_inline_array = 234,              // const_inline_array
        S_235_27 = 235,                          // $@27
        S_const_array_elm_list_opt = 236,        // const_array_elm_list_opt
        S_const_array_elm_list = 237,            // const_array_elm_list
        S_const_array_elm = 238,                 // const_array_elm
        S_const_inline_dic = 239,                // const_inline_dic
        S_240_28 = 240,                          // $@28
        S_const_dic_elm_list = 241,              // const_dic_elm_list
        S_const_dic_elm = 242                    // const_dic_elm
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value (std::move (that.value))
      {}
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);
      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    YY_RVREF (value_type) v);

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {};

    /// Build a parser object.
    parser (tTJSScriptBlock *ptr_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0




  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const short yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const unsigned char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 1526,     ///< Last index in yytable_.
      yynnts_ = 108,  ///< Number of nonterminal symbols.
      yyfinal_ = 4 ///< Termination state number.
    };


    // User arguments.
    tTJSScriptBlock *ptr;

  };


#line 6 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
} // TJS
#line 1135 "tjs.tab.hpp"




#endif // !YY_YY_TJS_TAB_HPP_INCLUDED
