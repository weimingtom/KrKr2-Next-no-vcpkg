// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 9 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"

#include <cstdlib>

#include "tjsTypes.h"
#include "tjsError.h"
#include "tjsArray.h"
#include "tjsDictionary.h"
#include "tjsInterCodeGen.h"
#include "tjsScriptBlock.h"

/* current context */
#define cc (ptr->GetCurrentContext())

/* current node */
#define cn (cc->GetCurrentNode())

/* lexical analyzer */
#define lx (ptr->GetLexicalAnalyzer())

#line 59 "tjs.tab.cpp"




#include "tjs.tab.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
namespace TJS {
#line 140 "tjs.tab.cpp"

  /// Build a parser object.
  parser::parser (tTJSScriptBlock *ptr_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      ptr (ptr_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}


  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, ptr));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 3: // $@1: %empty
#line 202 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { ptr->PushContextStack(TJS_W("global"),
												ctTopLevel); }
#line 598 "tjs.tab.cpp"
    break;

  case 4: // global_list: $@1 def_list
#line 204 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { ptr->PopContextStack(); }
#line 604 "tjs.tab.cpp"
    break;

  case 7: // def_list: def_list error ";"
#line 211 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { if(ptr->CompileErrorCount>20)
												YYABORT;
											  else yyerrok; }
#line 612 "tjs.tab.cpp"
    break;

  case 11: // statement: expr ";"
#line 225 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->CreateExprCode((yystack_[1].value.np)); }
#line 618 "tjs.tab.cpp"
    break;

  case 17: // statement: "break" ";"
#line 231 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->DoBreak(); }
#line 624 "tjs.tab.cpp"
    break;

  case 18: // statement: "continue" ";"
#line 232 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->DoContinue(); }
#line 630 "tjs.tab.cpp"
    break;

  case 19: // statement: "debugger" ";"
#line 233 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->DoDebugger(); }
#line 636 "tjs.tab.cpp"
    break;

  case 30: // $@2: %empty
#line 248 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->EnterBlock(); }
#line 642 "tjs.tab.cpp"
    break;

  case 31: // block: "{" $@2 def_list "}"
#line 250 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->ExitBlock(); }
#line 648 "tjs.tab.cpp"
    break;

  case 32: // $@3: %empty
#line 255 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->EnterWhileCode(false); }
#line 654 "tjs.tab.cpp"
    break;

  case 33: // $@4: %empty
#line 256 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->CreateWhileExprCode((yystack_[1].value.np), false); }
#line 660 "tjs.tab.cpp"
    break;

  case 34: // while: "while" $@3 "(" expr ")" $@4 block_or_statement
#line 257 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cc->ExitWhileCode(false); }
#line 666 "tjs.tab.cpp"
    break;

  case 35: // $@5: %empty
#line 262 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->EnterWhileCode(true); }
#line 672 "tjs.tab.cpp"
    break;

  case 36: // $@6: %empty
#line 265 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->CreateWhileExprCode((yystack_[1].value.np), true); }
#line 678 "tjs.tab.cpp"
    break;

  case 37: // do_while: "do" $@5 block_or_statement "while" "(" expr ")" $@6 ";"
#line 266 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->ExitWhileCode(true); }
#line 684 "tjs.tab.cpp"
    break;

  case 38: // $@7: %empty
#line 271 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->EnterIfCode(); }
#line 690 "tjs.tab.cpp"
    break;

  case 39: // $@8: %empty
#line 272 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->CreateIfExprCode((yystack_[0].value.np)); }
#line 696 "tjs.tab.cpp"
    break;

  case 40: // if: "if" "(" $@7 expr $@8 ")" block_or_statement
#line 273 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cc->ExitIfCode(); }
#line 702 "tjs.tab.cpp"
    break;

  case 41: // $@9: %empty
#line 278 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->EnterElseCode(); }
#line 708 "tjs.tab.cpp"
    break;

  case 42: // if_else: if "else" $@9 block_or_statement
#line 279 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cc->ExitElseCode(); }
#line 714 "tjs.tab.cpp"
    break;

  case 43: // for: "for" "(" for_first_clause ";" for_second_clause ";" for_third_clause ")" block_or_statement
#line 288 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cc->ExitForCode(); }
#line 720 "tjs.tab.cpp"
    break;

  case 44: // for_first_clause: %empty
#line 294 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->EnterForCode(); }
#line 726 "tjs.tab.cpp"
    break;

  case 45: // $@10: %empty
#line 295 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { cc->EnterForCode(); }
#line 732 "tjs.tab.cpp"
    break;

  case 47: // for_first_clause: expr
#line 297 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->EnterForCode();
											  cc->CreateExprCode((yystack_[0].value.np)); }
#line 739 "tjs.tab.cpp"
    break;

  case 48: // for_second_clause: %empty
#line 303 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->CreateForExprCode(NULL); }
#line 745 "tjs.tab.cpp"
    break;

  case 49: // for_second_clause: expr
#line 304 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->CreateForExprCode((yystack_[0].value.np)); }
#line 751 "tjs.tab.cpp"
    break;

  case 50: // for_third_clause: %empty
#line 309 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->SetForThirdExprCode(NULL); }
#line 757 "tjs.tab.cpp"
    break;

  case 51: // for_third_clause: expr
#line 310 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->SetForThirdExprCode((yystack_[0].value.np)); }
#line 763 "tjs.tab.cpp"
    break;

  case 57: // variable_id: T_SYMBOL variable_type
#line 333 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cc->AddLocalVariable(
												lx->GetString((yystack_[1].value.num))); }
#line 770 "tjs.tab.cpp"
    break;

  case 58: // variable_id: T_SYMBOL variable_type "=" expr_no_comma
#line 335 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { cc->InitLocalVariable(
											  lx->GetString((yystack_[3].value.num)), (yystack_[0].value.np)); }
#line 777 "tjs.tab.cpp"
    break;

  case 66: // $@11: %empty
#line 352 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { ptr->PushContextStack(
												lx->GetString((yystack_[0].value.num)),
											  ctFunction);
											  cc->EnterBlock();}
#line 786 "tjs.tab.cpp"
    break;

  case 67: // func_def: "function" T_SYMBOL $@11 func_decl_arg_opt variable_type block
#line 357 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->ExitBlock(); ptr->PopContextStack(); }
#line 792 "tjs.tab.cpp"
    break;

  case 68: // $@12: %empty
#line 362 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { ptr->PushContextStack(
												TJS_W("(anonymous)"),
											  ctExprFunction);
											  cc->EnterBlock(); }
#line 801 "tjs.tab.cpp"
    break;

  case 69: // func_expr_def: "function" $@12 func_decl_arg_opt variable_type block
#line 367 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->ExitBlock();
											  tTJSVariant v(cc);
											  ptr->PopContextStack();
											  (yylhs.value.np) = cc->MakeNP0(token::T_CONSTVAL);
											  (yylhs.value.np)->SetValue(v); }
#line 811 "tjs.tab.cpp"
    break;

  case 78: // func_decl_arg: T_SYMBOL variable_type
#line 394 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cc->AddFunctionDeclArg(
												lx->GetString((yystack_[1].value.num)), NULL); }
#line 818 "tjs.tab.cpp"
    break;

  case 79: // func_decl_arg: T_SYMBOL variable_type "=" expr_no_comma
#line 396 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { cc->AddFunctionDeclArg(
												lx->GetString((yystack_[3].value.num)), (yystack_[0].value.np)); }
#line 825 "tjs.tab.cpp"
    break;

  case 80: // func_decl_arg_collapse: "*"
#line 401 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->AddFunctionDeclArgCollapse(
												NULL); }
#line 832 "tjs.tab.cpp"
    break;

  case 81: // func_decl_arg_collapse: T_SYMBOL variable_type "*"
#line 403 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { cc->AddFunctionDeclArgCollapse(
												lx->GetString((yystack_[2].value.num))); }
#line 839 "tjs.tab.cpp"
    break;

  case 82: // $@13: %empty
#line 415 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { ptr->PushContextStack(
												lx->GetString((yystack_[1].value.num)),
												ctProperty); }
#line 847 "tjs.tab.cpp"
    break;

  case 83: // property_def: "property" T_SYMBOL "{" $@13 property_handler_def_list "}"
#line 419 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { ptr->PopContextStack(); }
#line 853 "tjs.tab.cpp"
    break;

  case 88: // $@14: %empty
#line 430 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { ptr->PushContextStack(
												TJS_W("(setter)"),
												ctPropertySetter);
											  cc->EnterBlock();
											  cc->SetPropertyDeclArg(
												lx->GetString((yystack_[2].value.num))); }
#line 864 "tjs.tab.cpp"
    break;

  case 89: // property_handler_setter: "setter" "(" T_SYMBOL variable_type ")" $@14 block
#line 436 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->ExitBlock();
											  ptr->PopContextStack(); }
#line 871 "tjs.tab.cpp"
    break;

  case 90: // $@15: %empty
#line 441 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { ptr->PushContextStack(
												TJS_W("(getter)"),
												ctPropertyGetter);
											  cc->EnterBlock(); }
#line 880 "tjs.tab.cpp"
    break;

  case 91: // property_handler_getter: property_getter_handler_head $@15 block
#line 445 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->ExitBlock();
											  ptr->PopContextStack(); }
#line 887 "tjs.tab.cpp"
    break;

  case 94: // $@16: %empty
#line 457 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { ptr->PushContextStack(
												lx->GetString((yystack_[0].value.num)),
												ctClass); }
#line 895 "tjs.tab.cpp"
    break;

  case 95: // class_def: "class" T_SYMBOL $@16 class_extender block
#line 461 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { ptr->PopContextStack(); }
#line 901 "tjs.tab.cpp"
    break;

  case 97: // class_extender: "extends" expr_no_comma
#line 466 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cc->CreateExtendsExprCode((yystack_[0].value.np), true); }
#line 907 "tjs.tab.cpp"
    break;

  case 98: // $@17: %empty
#line 467 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { cc->CreateExtendsExprCode((yystack_[1].value.np), false); }
#line 913 "tjs.tab.cpp"
    break;

  case 102: // extends_name: expr_no_comma
#line 477 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->CreateExtendsExprCode((yystack_[0].value.np), false); }
#line 919 "tjs.tab.cpp"
    break;

  case 103: // return: "return" ";"
#line 482 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->ReturnFromFunc(NULL); }
#line 925 "tjs.tab.cpp"
    break;

  case 104: // return: "return" expr ";"
#line 483 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->ReturnFromFunc((yystack_[1].value.np)); }
#line 931 "tjs.tab.cpp"
    break;

  case 105: // $@18: %empty
#line 490 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->EnterSwitchCode((yystack_[1].value.np)); }
#line 937 "tjs.tab.cpp"
    break;

  case 106: // switch: "switch" "(" expr ")" $@18 block
#line 491 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->ExitSwitchCode(); }
#line 943 "tjs.tab.cpp"
    break;

  case 107: // $@19: %empty
#line 497 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->EnterWithCode((yystack_[1].value.np)); }
#line 949 "tjs.tab.cpp"
    break;

  case 108: // with: "with" "(" expr ")" $@19 block_or_statement
#line 498 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cc->ExitWithCode(); }
#line 955 "tjs.tab.cpp"
    break;

  case 109: // case: "case" expr ":"
#line 503 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->ProcessCaseCode((yystack_[1].value.np)); }
#line 961 "tjs.tab.cpp"
    break;

  case 110: // case: "default" ":"
#line 504 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->ProcessCaseCode(NULL); }
#line 967 "tjs.tab.cpp"
    break;

  case 111: // $@20: %empty
#line 509 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->EnterTryCode(); }
#line 973 "tjs.tab.cpp"
    break;

  case 112: // try: "try" $@20 block_or_statement catch block_or_statement
#line 512 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cc->ExitTryCode(); }
#line 979 "tjs.tab.cpp"
    break;

  case 113: // catch: "catch"
#line 516 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { cc->EnterCatchCode(NULL); }
#line 985 "tjs.tab.cpp"
    break;

  case 114: // catch: "catch" "(" ")"
#line 517 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->EnterCatchCode(NULL); }
#line 991 "tjs.tab.cpp"
    break;

  case 115: // catch: "catch" "(" T_SYMBOL ")"
#line 518 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cc->EnterCatchCode(
												lx->GetString((yystack_[1].value.num))); }
#line 998 "tjs.tab.cpp"
    break;

  case 116: // throw: "throw" expr ";"
#line 524 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cc->ProcessThrowCode((yystack_[1].value.np)); }
#line 1004 "tjs.tab.cpp"
    break;

  case 117: // expr_no_comma: assign_expr
#line 529 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1010 "tjs.tab.cpp"
    break;

  case 118: // expr: comma_expr
#line 533 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1016 "tjs.tab.cpp"
    break;

  case 119: // expr: comma_expr "if" expr
#line 534 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP2(token::T_IF, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1022 "tjs.tab.cpp"
    break;

  case 120: // comma_expr: assign_expr
#line 539 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1028 "tjs.tab.cpp"
    break;

  case 121: // comma_expr: comma_expr "," assign_expr
#line 540 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_COMMA, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1034 "tjs.tab.cpp"
    break;

  case 122: // assign_expr: cond_expr
#line 545 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1040 "tjs.tab.cpp"
    break;

  case 123: // assign_expr: cond_expr "<->" assign_expr
#line 546 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_SWAP, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1046 "tjs.tab.cpp"
    break;

  case 124: // assign_expr: cond_expr "=" assign_expr
#line 547 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP2(token::T_EQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1052 "tjs.tab.cpp"
    break;

  case 125: // assign_expr: cond_expr "&=" assign_expr
#line 548 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_AMPERSANDEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1058 "tjs.tab.cpp"
    break;

  case 126: // assign_expr: cond_expr "|=" assign_expr
#line 549 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_VERTLINEEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1064 "tjs.tab.cpp"
    break;

  case 127: // assign_expr: cond_expr "^=" assign_expr
#line 550 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_CHEVRONEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1070 "tjs.tab.cpp"
    break;

  case 128: // assign_expr: cond_expr "-=" assign_expr
#line 551 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_MINUSEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1076 "tjs.tab.cpp"
    break;

  case 129: // assign_expr: cond_expr "+=" assign_expr
#line 552 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_PLUSEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1082 "tjs.tab.cpp"
    break;

  case 130: // assign_expr: cond_expr "%=" assign_expr
#line 553 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_PERCENTEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1088 "tjs.tab.cpp"
    break;

  case 131: // assign_expr: cond_expr "/=" assign_expr
#line 554 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_SLASHEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1094 "tjs.tab.cpp"
    break;

  case 132: // assign_expr: cond_expr "\\=" assign_expr
#line 555 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_BACKSLASHEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1100 "tjs.tab.cpp"
    break;

  case 133: // assign_expr: cond_expr "*=" assign_expr
#line 556 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_ASTERISKEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1106 "tjs.tab.cpp"
    break;

  case 134: // assign_expr: cond_expr "||=" assign_expr
#line 557 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_LOGICALOREQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1112 "tjs.tab.cpp"
    break;

  case 135: // assign_expr: cond_expr "&&=" assign_expr
#line 558 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_LOGICALANDEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1118 "tjs.tab.cpp"
    break;

  case 136: // assign_expr: cond_expr ">>=" assign_expr
#line 559 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_RARITHSHIFTEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1124 "tjs.tab.cpp"
    break;

  case 137: // assign_expr: cond_expr "<<=" assign_expr
#line 560 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_LARITHSHIFTEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1130 "tjs.tab.cpp"
    break;

  case 138: // assign_expr: cond_expr ">>>=" assign_expr
#line 561 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_RBITSHIFTEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1136 "tjs.tab.cpp"
    break;

  case 139: // cond_expr: logical_or_expr
#line 566 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1142 "tjs.tab.cpp"
    break;

  case 140: // cond_expr: logical_or_expr "?" cond_expr ":" cond_expr
#line 569 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { (yylhs.value.np) = cc->MakeNP3(token::T_QUESTION, (yystack_[4].value.np), (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1148 "tjs.tab.cpp"
    break;

  case 141: // logical_or_expr: logical_and_expr
#line 575 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1154 "tjs.tab.cpp"
    break;

  case 142: // logical_or_expr: logical_or_expr "||" logical_and_expr
#line 576 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { (yylhs.value.np) = cc->MakeNP2(token::T_LOGICALOR, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1160 "tjs.tab.cpp"
    break;

  case 143: // logical_and_expr: inclusive_or_expr
#line 580 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1166 "tjs.tab.cpp"
    break;

  case 144: // logical_and_expr: logical_and_expr "&&" inclusive_or_expr
#line 582 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_LOGICALAND, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1172 "tjs.tab.cpp"
    break;

  case 145: // inclusive_or_expr: exclusive_or_expr
#line 586 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1178 "tjs.tab.cpp"
    break;

  case 146: // inclusive_or_expr: inclusive_or_expr "|" exclusive_or_expr
#line 587 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { (yylhs.value.np) = cc->MakeNP2(token::T_VERTLINE, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1184 "tjs.tab.cpp"
    break;

  case 147: // exclusive_or_expr: and_expr
#line 591 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1190 "tjs.tab.cpp"
    break;

  case 148: // exclusive_or_expr: exclusive_or_expr "^" and_expr
#line 592 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_CHEVRON, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1196 "tjs.tab.cpp"
    break;

  case 149: // and_expr: identical_expr
#line 596 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1202 "tjs.tab.cpp"
    break;

  case 150: // and_expr: and_expr "&" identical_expr
#line 597 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_AMPERSAND, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1208 "tjs.tab.cpp"
    break;

  case 151: // identical_expr: compare_expr
#line 601 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1214 "tjs.tab.cpp"
    break;

  case 152: // identical_expr: identical_expr "!=" compare_expr
#line 602 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_NOTEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1220 "tjs.tab.cpp"
    break;

  case 153: // identical_expr: identical_expr "==" compare_expr
#line 603 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_EQUALEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1226 "tjs.tab.cpp"
    break;

  case 154: // identical_expr: identical_expr "!==" compare_expr
#line 604 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_DISCNOTEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1232 "tjs.tab.cpp"
    break;

  case 155: // identical_expr: identical_expr "===" compare_expr
#line 605 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_DISCEQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1238 "tjs.tab.cpp"
    break;

  case 156: // compare_expr: shift_expr
#line 609 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1244 "tjs.tab.cpp"
    break;

  case 157: // compare_expr: compare_expr "<" shift_expr
#line 610 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_LT, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1250 "tjs.tab.cpp"
    break;

  case 158: // compare_expr: compare_expr ">" shift_expr
#line 611 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_GT, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1256 "tjs.tab.cpp"
    break;

  case 159: // compare_expr: compare_expr "<=" shift_expr
#line 612 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_LTOREQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1262 "tjs.tab.cpp"
    break;

  case 160: // compare_expr: compare_expr ">=" shift_expr
#line 613 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_GTOREQUAL, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1268 "tjs.tab.cpp"
    break;

  case 161: // shift_expr: add_sub_expr
#line 617 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1274 "tjs.tab.cpp"
    break;

  case 162: // shift_expr: shift_expr ">>" add_sub_expr
#line 618 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_RARITHSHIFT, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1280 "tjs.tab.cpp"
    break;

  case 163: // shift_expr: shift_expr "<<" add_sub_expr
#line 619 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_LARITHSHIFT, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1286 "tjs.tab.cpp"
    break;

  case 164: // shift_expr: shift_expr ">>>" add_sub_expr
#line 620 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_RBITSHIFT, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1292 "tjs.tab.cpp"
    break;

  case 165: // add_sub_expr: mul_div_expr
#line 625 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1298 "tjs.tab.cpp"
    break;

  case 166: // add_sub_expr: add_sub_expr "+" mul_div_expr
#line 626 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_PLUS, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1304 "tjs.tab.cpp"
    break;

  case 167: // add_sub_expr: add_sub_expr "-" mul_div_expr
#line 627 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_MINUS, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1310 "tjs.tab.cpp"
    break;

  case 168: // mul_div_expr: unary_expr
#line 631 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1316 "tjs.tab.cpp"
    break;

  case 169: // mul_div_expr: mul_div_expr "%" unary_expr
#line 632 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_PERCENT, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1322 "tjs.tab.cpp"
    break;

  case 170: // mul_div_expr: mul_div_expr "/" unary_expr
#line 633 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_SLASH, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1328 "tjs.tab.cpp"
    break;

  case 171: // mul_div_expr: mul_div_expr "\\" unary_expr
#line 634 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_BACKSLASH, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1334 "tjs.tab.cpp"
    break;

  case 172: // mul_div_expr: mul_div_expr_and_asterisk unary_expr
#line 635 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { (yylhs.value.np) = cc->MakeNP2(token::T_ASTERISK, (yystack_[1].value.np), (yystack_[0].value.np)); }
#line 1340 "tjs.tab.cpp"
    break;

  case 173: // mul_div_expr_and_asterisk: mul_div_expr "*"
#line 639 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[1].value.np); }
#line 1346 "tjs.tab.cpp"
    break;

  case 174: // unary_expr: incontextof_expr
#line 643 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1352 "tjs.tab.cpp"
    break;

  case 175: // unary_expr: "!" unary_expr
#line 644 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_EXCRAMATION, (yystack_[0].value.np)); }
#line 1358 "tjs.tab.cpp"
    break;

  case 176: // unary_expr: "~" unary_expr
#line 645 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_TILDE, (yystack_[0].value.np)); }
#line 1364 "tjs.tab.cpp"
    break;

  case 177: // unary_expr: "--" unary_expr
#line 646 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_DECREMENT, (yystack_[0].value.np)); }
#line 1370 "tjs.tab.cpp"
    break;

  case 178: // unary_expr: "++" unary_expr
#line 647 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_INCREMENT, (yystack_[0].value.np)); }
#line 1376 "tjs.tab.cpp"
    break;

  case 179: // unary_expr: "new" func_call_expr
#line 648 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = (yystack_[0].value.np); (yylhs.value.np)->SetOpcode(token::T_NEW); }
#line 1382 "tjs.tab.cpp"
    break;

  case 180: // unary_expr: "invalidate" unary_expr
#line 649 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_INVALIDATE, (yystack_[0].value.np)); }
#line 1388 "tjs.tab.cpp"
    break;

  case 181: // unary_expr: "isvalid" unary_expr
#line 650 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_ISVALID, (yystack_[0].value.np)); }
#line 1394 "tjs.tab.cpp"
    break;

  case 182: // unary_expr: incontextof_expr "isvalid"
#line 651 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_ISVALID, (yystack_[1].value.np)); }
#line 1400 "tjs.tab.cpp"
    break;

  case 183: // unary_expr: "delete" unary_expr
#line 652 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_DELETE, (yystack_[0].value.np)); }
#line 1406 "tjs.tab.cpp"
    break;

  case 184: // unary_expr: "typeof" unary_expr
#line 653 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_TYPEOF, (yystack_[0].value.np)); }
#line 1412 "tjs.tab.cpp"
    break;

  case 185: // unary_expr: "#" unary_expr
#line 654 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_SHARP, (yystack_[0].value.np)); }
#line 1418 "tjs.tab.cpp"
    break;

  case 186: // unary_expr: "$" unary_expr
#line 655 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_DOLLAR, (yystack_[0].value.np)); }
#line 1424 "tjs.tab.cpp"
    break;

  case 187: // unary_expr: "+" unary_expr
#line 656 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_UPLUS, (yystack_[0].value.np)); }
#line 1430 "tjs.tab.cpp"
    break;

  case 188: // unary_expr: "-" unary_expr
#line 657 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_UMINUS, (yystack_[0].value.np)); }
#line 1436 "tjs.tab.cpp"
    break;

  case 189: // unary_expr: "&" unary_expr
#line 658 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_IGNOREPROP, (yystack_[0].value.np)); }
#line 1442 "tjs.tab.cpp"
    break;

  case 190: // unary_expr: "*" unary_expr
#line 659 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_PROPACCESS, (yystack_[0].value.np)); }
#line 1448 "tjs.tab.cpp"
    break;

  case 191: // unary_expr: incontextof_expr "instanceof" unary_expr
#line 660 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { (yylhs.value.np) = cc->MakeNP2(token::T_INSTANCEOF, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1454 "tjs.tab.cpp"
    break;

  case 192: // unary_expr: incontextof_expr "in" unary_expr
#line 661 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_IN, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1460 "tjs.tab.cpp"
    break;

  case 193: // unary_expr: "(" "int" ")" unary_expr
#line 662 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_INT, (yystack_[0].value.np)); }
#line 1466 "tjs.tab.cpp"
    break;

  case 194: // unary_expr: "int" unary_expr
#line 663 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_INT, (yystack_[0].value.np)); }
#line 1472 "tjs.tab.cpp"
    break;

  case 195: // unary_expr: "(" "real" ")" unary_expr
#line 664 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_REAL, (yystack_[0].value.np)); }
#line 1478 "tjs.tab.cpp"
    break;

  case 196: // unary_expr: "real" unary_expr
#line 665 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_REAL, (yystack_[0].value.np)); }
#line 1484 "tjs.tab.cpp"
    break;

  case 197: // unary_expr: "(" "string" ")" unary_expr
#line 666 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_STRING, (yystack_[0].value.np)); }
#line 1490 "tjs.tab.cpp"
    break;

  case 198: // unary_expr: "string" unary_expr
#line 667 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_STRING, (yystack_[0].value.np)); }
#line 1496 "tjs.tab.cpp"
    break;

  case 199: // incontextof_expr: priority_expr
#line 671 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1502 "tjs.tab.cpp"
    break;

  case 200: // incontextof_expr: priority_expr "incontextof" incontextof_expr
#line 673 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_INCONTEXTOF, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1508 "tjs.tab.cpp"
    break;

  case 201: // priority_expr: factor_expr
#line 677 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1514 "tjs.tab.cpp"
    break;

  case 202: // priority_expr: "(" expr ")"
#line 678 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[1].value.np); }
#line 1520 "tjs.tab.cpp"
    break;

  case 203: // priority_expr: priority_expr "[" expr "]"
#line 679 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP2(token::T_LBRACKET, (yystack_[3].value.np), (yystack_[1].value.np)); }
#line 1526 "tjs.tab.cpp"
    break;

  case 204: // priority_expr: func_call_expr
#line 680 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1532 "tjs.tab.cpp"
    break;

  case 205: // $@21: %empty
#line 681 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { lx->SetNextIsBareWord(); }
#line 1538 "tjs.tab.cpp"
    break;

  case 206: // priority_expr: priority_expr "." $@21 T_SYMBOL
#line 682 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { tTJSExprNode * node = cc->MakeNP0(token::T_CONSTVAL);
												  node->SetValue(lx->GetValue((yystack_[0].value.num)));
												  (yylhs.value.np) = cc->MakeNP2(token::T_DOT, (yystack_[3].value.np), node); }
#line 1546 "tjs.tab.cpp"
    break;

  case 207: // priority_expr: priority_expr "++"
#line 685 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_POSTINCREMENT, (yystack_[1].value.np)); }
#line 1552 "tjs.tab.cpp"
    break;

  case 208: // priority_expr: priority_expr "--"
#line 686 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_POSTDECREMENT, (yystack_[1].value.np)); }
#line 1558 "tjs.tab.cpp"
    break;

  case 209: // priority_expr: priority_expr "!"
#line 687 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_EVAL, (yystack_[1].value.np)); }
#line 1564 "tjs.tab.cpp"
    break;

  case 210: // $@22: %empty
#line 688 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { lx->SetNextIsBareWord(); }
#line 1570 "tjs.tab.cpp"
    break;

  case 211: // priority_expr: "." $@22 T_SYMBOL
#line 689 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                    { tTJSExprNode * node = cc->MakeNP0(token::T_CONSTVAL);
												  node->SetValue(lx->GetValue((yystack_[0].value.num)));
												  (yylhs.value.np) = cc->MakeNP1(token::T_WITHDOT, node); }
#line 1578 "tjs.tab.cpp"
    break;

  case 212: // factor_expr: T_CONSTVAL
#line 696 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = cc->MakeNP0(token::T_CONSTVAL);
												  (yylhs.value.np)->SetValue(lx->GetValue((yystack_[0].value.num))); }
#line 1585 "tjs.tab.cpp"
    break;

  case 213: // factor_expr: T_SYMBOL
#line 698 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { (yylhs.value.np) = cc->MakeNP0(token::T_SYMBOL);
												  (yylhs.value.np)->SetValue(tTJSVariant(
													lx->GetString((yystack_[0].value.num)))); }
#line 1593 "tjs.tab.cpp"
    break;

  case 214: // factor_expr: "this"
#line 701 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { (yylhs.value.np) = cc->MakeNP0(token::T_THIS); }
#line 1599 "tjs.tab.cpp"
    break;

  case 215: // factor_expr: "super"
#line 702 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { (yylhs.value.np) = cc->MakeNP0(token::T_SUPER); }
#line 1605 "tjs.tab.cpp"
    break;

  case 216: // factor_expr: func_expr_def
#line 703 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1611 "tjs.tab.cpp"
    break;

  case 217: // factor_expr: "global"
#line 704 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { (yylhs.value.np) = cc->MakeNP0(token::T_GLOBAL); }
#line 1617 "tjs.tab.cpp"
    break;

  case 218: // factor_expr: "void"
#line 705 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { (yylhs.value.np) = cc->MakeNP0(token::T_VOID); }
#line 1623 "tjs.tab.cpp"
    break;

  case 219: // factor_expr: inline_array
#line 706 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1629 "tjs.tab.cpp"
    break;

  case 220: // factor_expr: inline_dic
#line 707 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1635 "tjs.tab.cpp"
    break;

  case 221: // factor_expr: const_inline_array
#line 708 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1641 "tjs.tab.cpp"
    break;

  case 222: // factor_expr: const_inline_dic
#line 709 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1647 "tjs.tab.cpp"
    break;

  case 223: // $@23: %empty
#line 710 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { lx->SetStartOfRegExp(); }
#line 1653 "tjs.tab.cpp"
    break;

  case 224: // factor_expr: "/=" $@23 T_REGEXP
#line 711 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { (yylhs.value.np) = cc->MakeNP0(token::T_REGEXP);
												  (yylhs.value.np)->SetValue(lx->GetValue((yystack_[0].value.num))); }
#line 1660 "tjs.tab.cpp"
    break;

  case 225: // $@24: %empty
#line 713 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { lx->SetStartOfRegExp(); }
#line 1666 "tjs.tab.cpp"
    break;

  case 226: // factor_expr: "/" $@24 T_REGEXP
#line 714 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                                        { (yylhs.value.np) = cc->MakeNP0(token::T_REGEXP);
												  (yylhs.value.np)->SetValue(lx->GetValue((yystack_[0].value.num))); }
#line 1673 "tjs.tab.cpp"
    break;

  case 227: // func_call_expr: priority_expr "(" call_arg_list ")"
#line 721 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { (yylhs.value.np) = cc->MakeNP2(token::T_LPARENTHESIS, (yystack_[3].value.np), (yystack_[1].value.np)); }
#line 1679 "tjs.tab.cpp"
    break;

  case 228: // call_arg_list: "..."
#line 726 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP0(token::T_OMIT); }
#line 1685 "tjs.tab.cpp"
    break;

  case 229: // call_arg_list: call_arg
#line 727 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_ARG, (yystack_[0].value.np)); }
#line 1691 "tjs.tab.cpp"
    break;

  case 230: // call_arg_list: call_arg_list "," call_arg
#line 728 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                { (yylhs.value.np) = cc->MakeNP2(token::T_ARG, (yystack_[0].value.np), (yystack_[2].value.np)); }
#line 1697 "tjs.tab.cpp"
    break;

  case 231: // call_arg: %empty
#line 732 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = NULL; }
#line 1703 "tjs.tab.cpp"
    break;

  case 232: // call_arg: "*"
#line 733 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_EXPANDARG, NULL); }
#line 1709 "tjs.tab.cpp"
    break;

  case 233: // call_arg: mul_div_expr_and_asterisk
#line 734 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { (yylhs.value.np) = cc->MakeNP1(token::T_EXPANDARG, (yystack_[0].value.np)); }
#line 1715 "tjs.tab.cpp"
    break;

  case 234: // call_arg: expr_no_comma
#line 735 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = (yystack_[0].value.np); }
#line 1721 "tjs.tab.cpp"
    break;

  case 235: // $@25: %empty
#line 741 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { tTJSExprNode *node =
										  cc->MakeNP0(token::T_INLINEARRAY);
										  cc->PushCurrentNode(node); }
#line 1729 "tjs.tab.cpp"
    break;

  case 236: // inline_array: "[" $@25 array_elm_list "]"
#line 745 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cn; cc->PopCurrentNode(); }
#line 1735 "tjs.tab.cpp"
    break;

  case 237: // array_elm_list: array_elm
#line 750 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cn->Add((yystack_[0].value.np)); }
#line 1741 "tjs.tab.cpp"
    break;

  case 238: // array_elm_list: array_elm_list "," array_elm
#line 751 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                { cn->Add((yystack_[0].value.np)); }
#line 1747 "tjs.tab.cpp"
    break;

  case 239: // array_elm: %empty
#line 756 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_ARRAYARG, NULL); }
#line 1753 "tjs.tab.cpp"
    break;

  case 240: // array_elm: expr_no_comma
#line 757 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { (yylhs.value.np) = cc->MakeNP1(token::T_ARRAYARG, (yystack_[0].value.np)); }
#line 1759 "tjs.tab.cpp"
    break;

  case 241: // $@26: %empty
#line 762 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { tTJSExprNode *node =
										  cc->MakeNP0(token::T_INLINEDIC);
										  cc->PushCurrentNode(node); }
#line 1767 "tjs.tab.cpp"
    break;

  case 242: // inline_dic: "%" "[" $@26 dic_elm_list dic_dummy_elm_opt "]"
#line 767 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cn; cc->PopCurrentNode(); }
#line 1773 "tjs.tab.cpp"
    break;

  case 244: // dic_elm_list: dic_elm
#line 774 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cn->Add((yystack_[0].value.np)); }
#line 1779 "tjs.tab.cpp"
    break;

  case 245: // dic_elm_list: dic_elm_list "," dic_elm
#line 775 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { cn->Add((yystack_[0].value.np)); }
#line 1785 "tjs.tab.cpp"
    break;

  case 246: // dic_elm: expr_no_comma "," expr_no_comma
#line 780 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                { (yylhs.value.np) = cc->MakeNP2(token::T_DICELM, (yystack_[2].value.np), (yystack_[0].value.np)); }
#line 1791 "tjs.tab.cpp"
    break;

  case 247: // dic_elm: T_SYMBOL ":" expr_no_comma
#line 781 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                { tTJSVariant val(lx->GetString((yystack_[2].value.num)));
										  tTJSExprNode *node0 = cc->MakeNP0(token::T_CONSTVAL);
										  node0->SetValue(val);
										  (yylhs.value.np) = cc->MakeNP2(token::T_DICELM, node0, (yystack_[0].value.np)); }
#line 1800 "tjs.tab.cpp"
    break;

  case 250: // $@27: %empty
#line 797 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { tTJSExprNode *node =
										  cc->MakeNP0(token::T_CONSTVAL);
										  iTJSDispatch2 * dsp = TJSCreateArrayObject();
										  node->SetValue(tTJSVariant(dsp, dsp));
										  dsp->Release();
										  cc->PushCurrentNode(node); }
#line 1811 "tjs.tab.cpp"
    break;

  case 251: // const_inline_array: "(" "const" ")" "[" $@27 const_array_elm_list_opt "]"
#line 804 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cn; cc->PopCurrentNode(); }
#line 1817 "tjs.tab.cpp"
    break;

  case 256: // const_array_elm: "-" T_CONSTVAL
#line 822 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cn->AddArrayElement(- lx->GetValue((yystack_[0].value.num))); }
#line 1823 "tjs.tab.cpp"
    break;

  case 257: // const_array_elm: "+" T_CONSTVAL
#line 823 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cn->AddArrayElement(+ lx->GetValue((yystack_[0].value.num))); }
#line 1829 "tjs.tab.cpp"
    break;

  case 258: // const_array_elm: T_CONSTVAL
#line 824 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cn->AddArrayElement(lx->GetValue((yystack_[0].value.num))); }
#line 1835 "tjs.tab.cpp"
    break;

  case 259: // const_array_elm: "void"
#line 825 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { cn->AddArrayElement(tTJSVariant());  }
#line 1841 "tjs.tab.cpp"
    break;

  case 260: // const_array_elm: const_inline_array
#line 826 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { cn->AddArrayElement((yystack_[0].value.np)->GetValue()); }
#line 1847 "tjs.tab.cpp"
    break;

  case 261: // const_array_elm: const_inline_dic
#line 827 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                { cn->AddArrayElement((yystack_[0].value.np)->GetValue()); }
#line 1853 "tjs.tab.cpp"
    break;

  case 262: // $@28: %empty
#line 832 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { tTJSExprNode *node =
										  cc->MakeNP0(token::T_CONSTVAL);
										  iTJSDispatch2 * dsp = TJSCreateDictionaryObject();
										  node->SetValue(tTJSVariant(dsp, dsp));
										  dsp->Release();
										  cc->PushCurrentNode(node); }
#line 1864 "tjs.tab.cpp"
    break;

  case 263: // const_inline_dic: "(" "const" ")" "%" "[" $@28 const_dic_elm_list "]"
#line 839 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                                        { (yylhs.value.np) = cn; cc->PopCurrentNode(); }
#line 1870 "tjs.tab.cpp"
    break;

  case 267: // const_dic_elm: T_CONSTVAL "," "-" T_CONSTVAL
#line 852 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                { cn->AddDictionaryElement(lx->GetValue((yystack_[3].value.num)), - lx->GetValue((yystack_[0].value.num))); }
#line 1876 "tjs.tab.cpp"
    break;

  case 268: // const_dic_elm: T_CONSTVAL "," "+" T_CONSTVAL
#line 853 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                { cn->AddDictionaryElement(lx->GetValue((yystack_[3].value.num)), + lx->GetValue((yystack_[0].value.num))); }
#line 1882 "tjs.tab.cpp"
    break;

  case 269: // const_dic_elm: T_CONSTVAL "," T_CONSTVAL
#line 854 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { cn->AddDictionaryElement(lx->GetValue((yystack_[2].value.num)), lx->GetValue((yystack_[0].value.num))); }
#line 1888 "tjs.tab.cpp"
    break;

  case 270: // const_dic_elm: T_CONSTVAL "," "void"
#line 855 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                        { cn->AddDictionaryElement(lx->GetValue((yystack_[2].value.num)), tTJSVariant()); }
#line 1894 "tjs.tab.cpp"
    break;

  case 271: // const_dic_elm: T_CONSTVAL "," const_inline_array
#line 856 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                { cn->AddDictionaryElement(lx->GetValue((yystack_[2].value.num)), (yystack_[0].value.np)->GetValue()); }
#line 1900 "tjs.tab.cpp"
    break;

  case 272: // const_dic_elm: T_CONSTVAL "," const_inline_dic
#line 857 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
                                                { cn->AddDictionaryElement(lx->GetValue((yystack_[2].value.num)), (yystack_[0].value.np)->GetValue()); }
#line 1906 "tjs.tab.cpp"
    break;


#line 1910 "tjs.tab.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const short parser::yypact_ninf_ = -337;

  const short parser::yytable_ninf_ = -205;

  const short
  parser::yypact_[] =
  {
    -337,    31,  -337,  -337,  -337,   306,     7,  -337,  1256,    34,
    -337,  1256,  1256,  1256,  1256,  1256,   151,  1256,  1256,  1256,
    1256,  1256,  1256,  1256,  1256,   594,  -337,  -337,  -337,  -337,
    -337,   -45,  -337,  -337,    33,   -29,    48,    64,  1256,    -1,
     690,    66,    81,    85,  -337,  -337,    86,    11,    11,  1256,
    -337,    91,  1256,  1256,  1256,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,    53,  -337,  -337,  -337,    82,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,    88,     2,
    -337,   660,    59,   136,   138,   141,   142,     1,   152,    71,
     -26,   163,  1256,  -337,    16,    68,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,    41,  -337,  -337,  -337,    45,  -337,  -337,
    -337,  -337,  -337,   733,   115,   180,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,   102,   829,   925,  1021,   111,    47,
    1256,  -337,  -337,  -337,  -337,   121,  -337,  -337,   116,   124,
    -337,   122,  -337,  1256,  1064,   137,   498,  -337,   127,   192,
    -337,   192,   131,   498,  1256,  -337,  -337,  -337,  -337,  -337,
    -337,  1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,
    1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,
    1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,
    1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,
    1256,  -337,  -337,  -337,  1256,  1256,  -337,  -337,  -337,  1160,
    -337,  1256,   151,  -337,  1299,  -337,    36,  1256,  1256,  1256,
    -337,  -337,  -337,  -337,    13,  -337,   149,   402,   121,   -32,
     127,  -337,  -337,  -337,   134,   139,    -9,  -337,  1256,   143,
    1256,    44,   225,    11,  -337,   130,   170,   498,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,   174,   136,   138,   141,
     142,     1,   152,   152,   152,   152,    71,    71,    71,    71,
     -26,   -26,   -26,   163,   163,  -337,  -337,  -337,  -337,  -337,
    1256,  -337,  -337,  1256,     8,  -337,   103,   178,  -337,   179,
     241,   242,  -337,   191,  -337,  -337,  -337,  -337,  1256,  -337,
    1256,   188,  -337,   127,  -337,   127,   193,   252,  -337,   194,
     188,    23,  -337,  1256,  -337,   195,   208,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  1256,  -337,   209,   498,  -337,  -337,
    1256,  1395,  -337,  -337,  -337,  1256,  1256,  1299,   207,  -337,
     -30,  -337,   266,  -337,   188,    29,  -337,   -32,  -337,  -337,
     215,   -34,   204,   175,   177,  -337,   188,   210,  -337,  -337,
    1256,   213,  -337,   -54,  -337,   498,  -337,  -337,  -337,  -337,
    -337,  -337,   147,   148,   150,   187,  -337,  -337,  -337,   211,
     280,  -337,  -337,  -337,  -337,  1256,  -337,  -337,   221,   154,
     223,  -337,  -337,  -337,  -337,   188,  -337,  1256,   498,   224,
     498,  -337,   226,  -337,   285,    14,  -337,  -337,  -337,  -337,
     -30,  1256,  -337,  -337,   127,   127,  -337,   227,  -337,  -337,
    -337,  -337,  -337,     3,   147,  -337,  -337,   288,  -337,  -337,
     230,  -337,   498,   229,   165,   166,  -337,  -337,  -337,  -337,
    -337,  1256,  -337,  -337,  -337,  -337,  -337,  -337,   188,  -337
  };

  const short
  parser::yydefact_[] =
  {
       3,     0,     2,     5,     1,     0,     0,   223,     0,     0,
     225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   210,   235,   214,   215,
     217,     0,    10,    30,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    35,     0,     0,     0,     0,
     111,     0,     0,     0,     0,   218,   212,   213,     6,     8,
       9,    14,    15,    12,    13,    16,    20,     0,    21,   216,
      22,    23,    24,    25,    26,    27,    28,    29,     0,   118,
     120,   122,   139,   141,   143,   145,   147,   149,   151,   156,
     161,   165,     0,   168,   174,   199,   201,   204,   219,   220,
     221,   222,     7,     0,    68,   189,   241,     0,   190,   175,
     176,   177,   178,     0,     0,   179,   183,   184,   187,   188,
     185,   186,   181,   180,     0,     0,     0,     0,     0,     0,
     239,    94,     5,    18,    66,    70,    19,   110,     0,     0,
     103,     0,    17,     0,    45,     0,     0,    38,    59,    53,
      55,    54,     0,     0,     0,   194,   196,   198,    41,    52,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   172,   182,     0,     0,   209,   208,   207,   231,
     205,     0,     0,   224,   243,   226,     0,     0,     0,     0,
     202,   211,   240,   117,     0,   237,    96,     0,    70,    74,
      59,   109,    82,   104,     0,     0,     0,    47,     0,     0,
       0,     0,    57,     0,   116,     0,     0,     0,   121,   119,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   138,   137,   136,   123,     0,   142,   144,   146,
     148,   150,   152,   153,   154,   155,   157,   158,   159,   160,
     162,   163,   164,   166,   167,   169,   170,   171,   191,   192,
     232,   228,   234,   233,     0,   229,     0,     0,   200,   213,
       0,   248,   244,     0,   250,   193,   195,   197,   239,   236,
       0,     0,    31,    59,    80,    59,     0,    75,    76,     0,
       0,     0,   105,    48,    46,     0,     0,    39,    62,    63,
      64,    65,    61,    60,     0,    56,   113,     0,   107,    42,
       0,   231,   227,   206,   203,     0,     0,   249,     0,   262,
     252,   238,    97,    95,     0,    78,    72,     0,    71,    69,
       0,    59,     0,    84,    85,    90,     0,     0,    49,    33,
       0,     0,    58,     0,   112,     0,   140,   230,   247,   246,
     245,   242,   264,     0,     0,     0,   259,   258,   260,     0,
     253,   254,   261,    98,    67,     0,    81,    77,     0,     0,
       0,    93,    83,    86,    87,     0,   106,    50,     0,     0,
       0,   114,     0,   108,     0,     0,   265,   257,   256,   251,
       0,     0,    79,    73,    59,    59,    91,     0,    51,    34,
      36,    40,   115,     0,     0,   263,   255,    99,   100,   102,
       0,    92,     0,     0,     0,     0,   270,   269,   271,   272,
     266,     0,    88,    43,    37,   268,   267,   101,     0,    89
  };

  const short
  parser::yypgoto_[] =
  {
    -337,  -337,  -337,  -337,   168,  -143,  -337,  -244,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,    65,   249,    60,  -226,
    -337,  -337,  -337,  -337,    74,  -337,  -337,   -53,   -52,  -337,
    -337,  -337,   -56,  -337,   -51,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -142,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -202,   -25,  -337,  -129,  -177,  -337,   133,
     129,   132,   128,   135,    40,    61,   -78,   -70,  -203,    42,
     104,   299,  -337,  -337,  -337,  -337,  -337,   302,  -337,   -21,
    -337,  -337,  -337,    15,  -337,  -337,  -337,   -23,  -337,  -336,
    -337,  -337,  -337,   -99,  -330,  -337,  -337,  -109
  };

  const short
  parser::yydefgoto_[] =
  {
       0,     1,     2,     3,     5,    58,    59,    60,   132,    61,
     145,   408,    62,   146,   443,    63,   240,   371,    64,   247,
      65,   235,   236,   367,   427,    66,    67,   149,   150,   242,
      68,   228,    69,   135,   230,   316,   317,   318,   319,    70,
     321,   362,   363,   458,   364,   405,   365,    71,   226,   311,
     421,   437,   438,    72,    73,   366,    74,   375,    75,    76,
     153,   337,    77,   222,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   296,   129,    96,   103,   107,    97,   294,   295,
      98,   130,   224,   225,    99,   214,   301,   302,   348,   100,
     350,   389,   390,   391,   101,   382,   415,   416
  };

  const short
  parser::yytable_[] =
  {
     128,   223,   266,   239,   320,   161,   293,   292,   314,   411,
     245,   341,   300,   138,   388,   141,   308,   434,   383,   384,
     392,   400,   196,   197,   152,   385,   185,   186,   187,   188,
     241,     4,   248,   395,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     105,   444,   445,   108,   109,   110,   111,   112,   385,   116,
     117,   118,   119,   120,   121,   122,   123,   353,   203,   396,
     204,   342,   102,   303,   309,   435,   359,   412,   179,   180,
     223,   386,    47,    48,   388,   223,   131,   354,   128,   355,
     392,   106,   162,   304,   155,   156,   157,   448,   133,   315,
     387,   205,   134,   449,   339,   193,   194,   195,   352,   206,
     394,   207,   208,   136,   446,   280,   281,   282,   234,   237,
     360,   361,   406,   209,   210,   211,   283,   284,   137,   246,
     139,   142,   372,   447,   202,   401,   143,   249,   293,   292,
     144,   147,   148,   378,   379,   300,   154,   159,   328,   329,
     330,   331,   158,   160,   212,   332,   206,   181,   207,   208,
     182,   426,     7,   376,   183,   216,   184,   155,   156,   157,
     209,   210,   211,   213,   220,   333,   229,   215,   221,   223,
     231,   223,   189,   190,   191,   192,   297,   233,     9,    10,
     232,   241,   238,   422,   374,   243,   244,   322,   440,   441,
     198,   199,   200,   201,   323,   223,   113,    26,    27,    28,
      29,    30,   223,   325,   459,   327,   223,   223,   223,   439,
     104,  -204,   310,  -204,  -204,   272,   273,   274,   275,   334,
     336,   326,   413,   338,   343,  -204,  -204,  -204,   340,   344,
     285,   286,   287,   345,   346,   347,   288,   289,   349,   439,
     276,   277,   278,   279,    33,   357,   356,   358,   369,   305,
     306,   307,    55,   370,   373,   429,   223,   431,   381,   393,
     399,   402,   419,   361,   360,   407,   410,   414,   417,   124,
     418,    56,    57,   420,   423,   424,   425,   430,   433,   432,
     442,   451,   223,   452,   454,   455,   456,   151,   368,   453,
     227,   324,   313,   335,   397,   398,    -4,     6,   404,   457,
     268,   270,   403,   267,   269,   114,   298,     7,   115,   271,
     377,   436,   223,   351,   380,   450,     0,     0,     0,     0,
       8,     0,   108,     0,     0,   202,     0,     0,     0,     0,
       0,     0,     0,     9,    10,   409,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,    26,    27,    28,    29,    30,     0,    31,     0,
       0,    32,    33,     0,    34,    35,    36,    37,    38,     0,
       0,    39,   428,     0,     0,     0,    40,    41,     0,     0,
      42,     0,     0,    43,    44,    45,    46,    47,    48,     0,
       0,    49,    50,     6,     0,     0,     0,     0,     0,    51,
      52,    53,    54,     7,     0,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,    57,     0,     9,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,    25,    26,    27,
      28,    29,    30,     0,    31,     0,     0,    32,    33,   312,
      34,    35,    36,    37,    38,     0,     0,    39,     0,     0,
       0,     0,    40,    41,     0,     0,    42,     0,     0,    43,
      44,    45,    46,    47,    48,     0,     0,    49,    50,     0,
       0,     0,     0,     0,     0,    51,    52,    53,    54,     7,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    57,     0,     9,    10,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    25,    26,    27,    28,    29,    30,     0,
      31,     0,     0,    32,    33,     0,    34,    35,    36,    37,
      38,     0,     0,    39,     0,     0,     0,     0,    40,    41,
       0,     0,    42,     0,     0,    43,    44,    45,    46,    47,
      48,     0,     0,    49,    50,     0,     0,     0,     0,     0,
       0,    51,    52,    53,    54,     7,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,    57,
       0,     9,    10,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,    27,    28,    29,    30,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
       0,     0,     0,     0,     0,     0,   124,     0,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,   125,   126,
     127,     7,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,     0,     9,    10,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     7,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,   140,     0,     8,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
      27,    28,    29,    30,    52,    53,    54,     0,     0,     0,
       0,    55,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,     0,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
       7,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,     0,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,    27,    28,    29,    30,
       0,     0,   217,     0,     0,     0,     0,     0,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,     7,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
      57,     0,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    26,    27,    28,    29,    30,     0,     0,   218,     0,
       0,     0,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,     7,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    57,     0,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     7,    25,    26,    27,    28,
      29,    30,     0,     0,   219,     0,     0,     0,     8,     0,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,    27,    28,    29,    30,    52,    53,    54,     0,   -44,
       0,     0,    55,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    53,
      54,     7,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,     0,     9,    10,     0,
     290,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,     0,     0,    52,    53,    54,     7,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,     0,     9,    10,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       7,    25,    26,    27,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     8,     0,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,    27,    28,    29,    30,
      52,    53,    54,     0,     0,     0,     0,    55,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,     7,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
     299,     0,     9,    10,     0,   290,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    26,    27,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    54,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    57
  };

  const short
  parser::yycheck_[] =
  {
      25,   130,   179,   146,   230,     3,   209,   209,    40,    63,
     153,     3,   214,    38,   350,    40,     3,     3,    48,    49,
     350,    55,    48,    49,    49,    55,    25,    26,    27,    28,
      64,     0,   161,     4,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       8,    48,    49,    11,    12,    13,    14,    15,    55,    17,
      18,    19,    20,    21,    22,    23,    24,   311,    52,    40,
      54,    63,    65,    37,    61,    61,   320,   131,    19,    20,
     209,   111,    91,    92,   420,   214,   131,   313,   113,   315,
     420,    57,    90,    57,    52,    53,    54,   433,    65,   131,
     130,    85,   131,   433,   247,    34,    35,    36,   310,    41,
     354,    43,    44,    65,   111,   193,   194,   195,   143,   144,
      97,    98,   366,    55,    56,    57,   196,   197,    64,   154,
     131,    65,   334,   130,    92,   361,    55,   162,   341,   341,
      55,    55,   131,   345,   346,   347,    55,    65,   104,   105,
     106,   107,    99,    65,    86,   111,    41,    21,    43,    44,
      22,   405,    11,   340,    23,    63,    24,   125,   126,   127,
      55,    56,    57,   132,    63,   131,    55,   132,   131,   308,
      64,   310,    30,    31,    32,    33,   211,    65,    37,    38,
      66,    64,    55,   395,   337,     3,    65,    63,   424,   425,
      37,    38,    39,    40,    65,   334,    55,    56,    57,    58,
      59,    60,   341,   238,   458,   240,   345,   346,   347,   421,
      69,    41,    73,    43,    44,   185,   186,   187,   188,     4,
     100,    88,   375,    63,   131,    55,    56,    57,    64,    61,
     198,   199,   200,    64,     3,     3,   204,   205,    57,   451,
     189,   190,   191,   192,    66,     3,    63,    63,    63,   217,
     218,   219,   111,    55,    55,   408,   395,   410,    61,     3,
      55,    67,    61,    98,    97,    65,    63,   130,   130,    92,
     130,   130,   131,     3,    63,   131,    63,    63,     3,    63,
      63,     3,   421,    63,    65,   130,   130,    48,   323,   442,
     132,   236,   228,   243,   357,   357,     0,     1,   364,   451,
     181,   183,   363,   180,   182,    16,   212,    11,    16,   184,
     341,   420,   451,   308,   347,   434,    -1,    -1,    -1,    -1,
      24,    -1,   290,    -1,    -1,   293,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,   370,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    -1,    62,    -1,
      -1,    65,    66,    -1,    68,    69,    70,    71,    72,    -1,
      -1,    75,   407,    -1,    -1,    -1,    80,    81,    -1,    -1,
      84,    -1,    -1,    87,    88,    89,    90,    91,    92,    -1,
      -1,    95,    96,     1,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,    11,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    -1,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    84,    -1,    -1,    87,
      88,    89,    90,    91,    92,    -1,    -1,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,    11,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,    -1,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    -1,
      62,    -1,    -1,    65,    66,    -1,    68,    69,    70,    71,
      72,    -1,    -1,    75,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    84,    -1,    -1,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,    11,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,    11,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    11,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    65,    -1,    24,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,   104,   105,   106,    -1,    -1,    -1,
      -1,   111,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
      11,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,    11,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,    -1,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,    11,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,    -1,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    11,    55,    56,    57,    58,
      59,    60,    -1,    -1,    63,    -1,    -1,    -1,    24,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,   104,   105,   106,    -1,    65,
      -1,    -1,   111,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,    11,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,   104,   105,   106,    11,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      11,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
     104,   105,   106,    -1,    -1,    -1,    -1,   111,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,    11,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,    -1,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,   136,   137,   138,     0,   139,     1,    11,    24,    37,
      38,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    55,    56,    57,    58,    59,
      60,    62,    65,    66,    68,    69,    70,    71,    72,    75,
      80,    81,    84,    87,    88,    89,    90,    91,    92,    95,
      96,   103,   104,   105,   106,   111,   130,   131,   140,   141,
     142,   144,   147,   150,   153,   155,   160,   161,   165,   167,
     174,   182,   188,   189,   191,   193,   194,   197,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   219,   222,   225,   229,
     234,   239,    65,   220,    69,   214,    57,   221,   214,   214,
     214,   214,   214,    55,   216,   222,   214,   214,   214,   214,
     214,   214,   214,   214,    92,   104,   105,   106,   199,   218,
     226,   131,   143,    65,   131,   168,    65,    64,   199,   131,
      65,   199,    65,    55,    55,   145,   148,    55,   131,   162,
     163,   162,   199,   195,    55,   214,   214,   214,    99,    65,
      65,     3,    90,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    29,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    48,    49,    37,    38,
      39,    40,   214,    52,    54,    85,    41,    43,    44,    55,
      56,    57,    86,   132,   230,   132,    63,    63,    63,    63,
      63,   131,   198,   201,   227,   228,   183,   139,   166,    55,
     169,    64,    66,    65,   199,   156,   157,   199,    55,   140,
     151,    64,   164,     3,    65,   140,   199,   154,   201,   199,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   202,   204,   205,   206,
     207,   208,   209,   209,   209,   209,   210,   210,   210,   210,
     211,   211,   211,   212,   212,   214,   214,   214,   214,   214,
      40,   101,   198,   213,   223,   224,   217,   199,   215,   131,
     198,   231,   232,    37,    57,   214,   214,   214,     3,    61,
      73,   184,    67,   169,    40,   131,   170,   171,   172,   173,
     164,   175,    63,    65,   161,   199,    88,   199,   104,   105,
     106,   107,   111,   131,     4,   163,   100,   196,    63,   140,
      64,     3,    63,   131,    61,    64,     3,     3,   233,    57,
     235,   228,   198,   142,   164,   164,    63,     3,    63,   142,
      97,    98,   176,   177,   179,   181,   190,   158,   199,    63,
      55,   152,   198,    55,   140,   192,   202,   224,   198,   198,
     232,    61,   240,    48,    49,    55,   111,   130,   234,   236,
     237,   238,   239,     3,   142,     4,    40,   172,   173,    55,
      55,   164,    67,   179,   177,   180,   142,    65,   146,   199,
      63,    63,   131,   140,   130,   241,   242,   130,   130,    61,
       3,   185,   198,    63,   131,    63,   142,   159,   199,   140,
      63,   140,    63,     3,     3,    61,   238,   186,   187,   198,
     164,   164,    63,   149,    48,    49,   111,   130,   234,   239,
     242,     3,    63,   140,    65,   130,   130,   187,   178,   142
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   135,   136,   138,   137,   139,   139,   139,   140,   140,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     143,   142,   145,   146,   144,   148,   149,   147,   151,   152,
     150,   154,   153,   155,   156,   157,   156,   156,   158,   158,
     159,   159,   160,   161,   161,   162,   162,   163,   163,   164,
     164,   164,   164,   164,   164,   164,   166,   165,   168,   167,
     169,   169,   169,   169,   170,   170,   171,   171,   172,   172,
     173,   173,   175,   174,   176,   176,   176,   176,   178,   177,
     180,   179,   181,   181,   183,   182,   184,   184,   185,   184,
     186,   186,   187,   188,   188,   190,   189,   192,   191,   193,
     193,   195,   194,   196,   196,   196,   197,   198,   199,   199,
     200,   200,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   202,
     202,   203,   203,   204,   204,   205,   205,   206,   206,   207,
     207,   208,   208,   208,   208,   208,   209,   209,   209,   209,
     209,   210,   210,   210,   210,   211,   211,   211,   212,   212,
     212,   212,   212,   213,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   215,
     215,   216,   216,   216,   216,   217,   216,   216,   216,   216,
     218,   216,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   220,   219,   221,   219,   222,   223,   223,
     223,   224,   224,   224,   224,   226,   225,   227,   227,   228,
     228,   230,   229,   231,   231,   231,   232,   232,   233,   233,
     235,   234,   236,   236,   237,   237,   238,   238,   238,   238,
     238,   238,   240,   239,   241,   241,   241,   242,   242,   242,
     242,   242,   242
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     0,     2,     3,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     0,     7,     0,     0,     9,     0,     0,
       7,     0,     4,     9,     0,     0,     2,     1,     0,     1,
       0,     1,     2,     2,     2,     1,     3,     2,     4,     0,
       2,     2,     2,     2,     2,     2,     0,     6,     0,     5,
       0,     3,     3,     5,     0,     1,     1,     3,     2,     4,
       1,     3,     0,     6,     1,     1,     2,     2,     0,     7,
       0,     3,     4,     2,     0,     5,     0,     2,     0,     5,
       1,     3,     1,     2,     3,     0,     6,     0,     6,     3,
       2,     0,     5,     1,     3,     4,     3,     1,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       5,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     4,     2,     4,     2,     4,     2,     1,
       3,     1,     3,     4,     1,     0,     4,     2,     2,     2,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     3,     4,     1,     1,
       3,     0,     1,     1,     1,     0,     4,     1,     3,     0,
       1,     0,     6,     0,     1,     3,     3,     3,     0,     1,
       0,     7,     0,     1,     1,     3,     2,     2,     1,     1,
       1,     1,     0,     8,     0,     1,     3,     4,     4,     3,
       3,     3,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\",\"", "\"=\"",
  "\"&=\"", "\"|=\"", "\"^=\"", "\"-=\"", "\"+=\"", "\"%=\"", "\"/=\"",
  "\"\\\\=\"", "\"*=\"", "\"||=\"", "\"&&=\"", "\">>>=\"", "\"<<=\"",
  "\">>=\"", "\"?\"", "\"||\"", "\"&&\"", "\"|\"", "\"^\"", "\"&\"",
  "\"!=\"", "\"==\"", "\"!==\"", "\"===\"", "\"<->\"", "\"<\"", "\">\"",
  "\"<=\"", "\">=\"", "\">>\"", "\"<<\"", "\">>>\"", "\"%\"", "\"/\"",
  "\"\\\\\"", "\"*\"", "\"!\"", "\"~\"", "\"--\"", "\"++\"", "\"new\"",
  "\"delete\"", "\"typeof\"", "\"+\"", "\"-\"", "\"#\"", "\"$\"",
  "\"isvalid\"", "\"invalidate\"", "\"instanceof\"", "\"(\"", "\".\"",
  "\"[\"", "\"this\"", "\"super\"", "\"global\"", "\"]\"", "\"class\"",
  "\")\"", "\":\"", "\";\"", "\"{\"", "\"}\"", "\"continue\"",
  "\"function\"", "\"debugger\"", "\"default\"", "\"case\"", "\"extends\"",
  "\"finally\"", "\"property\"", "\"private\"", "\"public\"",
  "\"protected\"", "\"static\"", "\"return\"", "\"break\"", "\"export\"",
  "\"import\"", "\"switch\"", "\"in\"", "\"incontextof\"", "\"for\"",
  "\"while\"", "\"do\"", "\"if\"", "\"var\"", "\"const\"", "\"enum\"",
  "\"goto\"", "\"throw\"", "\"try\"", "\"setter\"", "\"getter\"",
  "\"else\"", "\"catch\"", "\"...\"", "\"synchronized\"", "\"with\"",
  "\"int\"", "\"real\"", "\"string\"", "\"octet\"", "\"false\"",
  "\"null\"", "\"true\"", "\"void\"", "\"NaN\"", "\"Infinity\"", "T_UPLUS",
  "T_UMINUS", "T_EVAL", "T_POSTDECREMENT", "T_POSTINCREMENT",
  "T_IGNOREPROP", "T_PROPACCESS", "T_ARG", "T_EXPANDARG", "T_INLINEARRAY",
  "T_ARRAYARG", "T_INLINEDIC", "T_DICELM", "T_WITHDOT", "T_THIS_PROXY",
  "T_WITHDOT_PROXY", "T_CONSTVAL", "T_SYMBOL", "T_REGEXP", "T_VARIANT",
  "LOWER_ELSE", "$accept", "program", "global_list", "$@1", "def_list",
  "block_or_statement", "statement", "block", "$@2", "while", "$@3", "$@4",
  "do_while", "$@5", "$@6", "if", "$@7", "$@8", "if_else", "$@9", "for",
  "for_first_clause", "$@10", "for_second_clause", "for_third_clause",
  "variable_def", "variable_def_inner", "variable_id_list", "variable_id",
  "variable_type", "func_def", "$@11", "func_expr_def", "$@12",
  "func_decl_arg_opt", "func_decl_arg_list", "func_decl_arg_at_least_one",
  "func_decl_arg", "func_decl_arg_collapse", "property_def", "$@13",
  "property_handler_def_list", "property_handler_setter", "$@14",
  "property_handler_getter", "$@15", "property_getter_handler_head",
  "class_def", "$@16", "class_extender", "$@17", "extends_list",
  "extends_name", "return", "switch", "$@18", "with", "$@19", "case",
  "try", "$@20", "catch", "throw", "expr_no_comma", "expr", "comma_expr",
  "assign_expr", "cond_expr", "logical_or_expr", "logical_and_expr",
  "inclusive_or_expr", "exclusive_or_expr", "and_expr", "identical_expr",
  "compare_expr", "shift_expr", "add_sub_expr", "mul_div_expr",
  "mul_div_expr_and_asterisk", "unary_expr", "incontextof_expr",
  "priority_expr", "$@21", "$@22", "factor_expr", "$@23", "$@24",
  "func_call_expr", "call_arg_list", "call_arg", "inline_array", "$@25",
  "array_elm_list", "array_elm", "inline_dic", "$@26", "dic_elm_list",
  "dic_elm", "dic_dummy_elm_opt", "const_inline_array", "$@27",
  "const_array_elm_list_opt", "const_array_elm_list", "const_array_elm",
  "const_inline_dic", "$@28", "const_dic_elm_list", "const_dic_elm", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   197,   197,   202,   202,   209,   210,   211,   218,   219,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     248,   248,   255,   256,   255,   262,   265,   262,   271,   272,
     271,   278,   278,   284,   294,   295,   295,   297,   303,   304,
     309,   310,   315,   319,   320,   327,   328,   333,   335,   341,
     342,   343,   344,   345,   346,   347,   352,   352,   362,   362,
     376,   377,   378,   379,   384,   385,   389,   390,   394,   396,
     401,   403,   415,   414,   423,   424,   425,   426,   430,   430,
     441,   441,   450,   451,   457,   457,   465,   466,   467,   467,
     472,   473,   477,   482,   483,   490,   489,   497,   496,   503,
     504,   509,   509,   516,   517,   518,   524,   529,   533,   534,
     539,   540,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   566,
     567,   575,   576,   580,   581,   586,   587,   591,   592,   596,
     597,   601,   602,   603,   604,   605,   609,   610,   611,   612,
     613,   617,   618,   619,   620,   625,   626,   627,   631,   632,
     633,   634,   635,   639,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   657,   658,
     659,   660,   661,   662,   663,   664,   665,   666,   667,   671,
     672,   677,   678,   679,   680,   681,   681,   685,   686,   687,
     688,   688,   696,   698,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   710,   713,   713,   721,   726,   727,
     728,   732,   733,   734,   735,   741,   741,   750,   751,   756,
     757,   762,   762,   773,   774,   775,   780,   781,   789,   790,
     797,   797,   808,   809,   815,   816,   822,   823,   824,   825,
     826,   827,   832,   832,   845,   846,   847,   852,   853,   854,
     855,   856,   857
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const unsigned char
    translate_table[] =
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134
    };
    // Last valid token kind.
    const int code_max = 389;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 6 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
} // TJS
#line 2851 "tjs.tab.cpp"

#line 862 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjs.y"
