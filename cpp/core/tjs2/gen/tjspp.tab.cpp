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
#line 10 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"

#include <cstdlib>

#include "tjsTypes.h"
#include "tjs.h"
#include "tjsCompileControl.h"

#define YYMALLOC	::malloc
#define YYREALLOC	::realloc
#define YYFREE		::free


#line 52 "tjspp.tab.cpp"




#include "tjspp.tab.hpp"




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

#line 6 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
namespace TJSPP {
#line 133 "tjspp.tab.cpp"

  /// Build a parser object.
  parser::parser (tTJSPPExprParser *ptr_yyarg)
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
  case 2: // input: expr
#line 86 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                        { ptr->Result = (yystack_[0].value.val); }
#line 590 "tjspp.tab.cpp"
    break;

  case 3: // expr: expr "," expr
#line 90 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[0].value.val); }
#line 596 "tjspp.tab.cpp"
    break;

  case 4: // expr: PT_SYMBOL "=" expr
#line 91 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                        { ptr->GetTJS()->SetPPValue(ptr->GetString((yystack_[2].value.nv)), (yystack_[0].value.val)); (yylhs.value.val) = (yystack_[0].value.val); }
#line 602 "tjspp.tab.cpp"
    break;

  case 5: // expr: expr "!=" expr
#line 92 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) != (yystack_[0].value.val); }
#line 608 "tjspp.tab.cpp"
    break;

  case 6: // expr: expr "==" expr
#line 93 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) == (yystack_[0].value.val); }
#line 614 "tjspp.tab.cpp"
    break;

  case 7: // expr: expr "||" expr
#line 94 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) || (yystack_[0].value.val); }
#line 620 "tjspp.tab.cpp"
    break;

  case 8: // expr: expr "&&" expr
#line 95 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) && (yystack_[0].value.val); }
#line 626 "tjspp.tab.cpp"
    break;

  case 9: // expr: expr "|" expr
#line 96 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) | (yystack_[0].value.val); }
#line 632 "tjspp.tab.cpp"
    break;

  case 10: // expr: expr "^" expr
#line 97 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) ^ (yystack_[0].value.val); }
#line 638 "tjspp.tab.cpp"
    break;

  case 11: // expr: expr "&" expr
#line 98 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) & (yystack_[0].value.val); }
#line 644 "tjspp.tab.cpp"
    break;

  case 12: // expr: expr "<" expr
#line 99 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) < (yystack_[0].value.val); }
#line 650 "tjspp.tab.cpp"
    break;

  case 13: // expr: expr ">" expr
#line 100 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) > (yystack_[0].value.val); }
#line 656 "tjspp.tab.cpp"
    break;

  case 14: // expr: expr ">=" expr
#line 101 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) >= (yystack_[0].value.val); }
#line 662 "tjspp.tab.cpp"
    break;

  case 15: // expr: expr "<=" expr
#line 102 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) <= (yystack_[0].value.val); }
#line 668 "tjspp.tab.cpp"
    break;

  case 16: // expr: expr "+" expr
#line 103 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) + (yystack_[0].value.val); }
#line 674 "tjspp.tab.cpp"
    break;

  case 17: // expr: expr "-" expr
#line 104 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) - (yystack_[0].value.val); }
#line 680 "tjspp.tab.cpp"
    break;

  case 18: // expr: expr "%" expr
#line 105 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) % (yystack_[0].value.val); }
#line 686 "tjspp.tab.cpp"
    break;

  case 19: // expr: expr "*" expr
#line 106 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[2].value.val) * (yystack_[0].value.val); }
#line 692 "tjspp.tab.cpp"
    break;

  case 20: // expr: expr "/" expr
#line 107 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { if((yystack_[0].value.val)==0) { YYABORT; } else { (yylhs.value.val) = (yystack_[2].value.val) / (yystack_[0].value.val); } }
#line 698 "tjspp.tab.cpp"
    break;

  case 21: // expr: "!" expr
#line 108 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                        { (yylhs.value.val) = ! (yystack_[0].value.val); }
#line 704 "tjspp.tab.cpp"
    break;

  case 22: // expr: "+" expr
#line 109 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                        { (yylhs.value.val) = + (yystack_[0].value.val); }
#line 710 "tjspp.tab.cpp"
    break;

  case 23: // expr: "-" expr
#line 110 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                        { (yylhs.value.val) = - (yystack_[0].value.val); }
#line 716 "tjspp.tab.cpp"
    break;

  case 24: // expr: "(" expr ")"
#line 111 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                { (yylhs.value.val) = (yystack_[1].value.val); }
#line 722 "tjspp.tab.cpp"
    break;

  case 25: // expr: PT_NUM
#line 112 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                        { (yylhs.value.val) = (yystack_[0].value.val); }
#line 728 "tjspp.tab.cpp"
    break;

  case 26: // expr: PT_SYMBOL
#line 113 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
                                                        { (yylhs.value.val) = ptr->GetTJS()->GetPPValue(ptr->GetString((yystack_[0].value.nv))); }
#line 734 "tjspp.tab.cpp"
    break;


#line 738 "tjspp.tab.cpp"

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









  const signed char parser::yypact_ninf_ = -16;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      28,    28,    28,    28,    28,     6,   -16,    41,    70,    52,
     -16,   -16,   -16,    28,   -16,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,   -16,   166,    86,    17,    17,   102,   118,   134,
     150,   166,   -15,   -15,   -15,   -15,   -12,   -12,   -16,   -16,
     -16
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,    26,    25,     0,     2,     0,
      22,    23,    21,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,     4,     3,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    15,    14,    16,    17,    19,    20,
      18
  };

  const signed char
  parser::yypgoto_[] =
  {
     -16,   -16,    -1
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     7,     8
  };

  const signed char
  parser::yytable_[] =
  {
       9,    10,    11,    12,    27,    28,    29,    30,    31,    29,
      30,    31,    33,    13,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    14,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,    32,     0,    15,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    15,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      16,    17,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    16,    17,     0,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    16,    17,     0,     0,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    16,    17,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    16,    17,     0,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31
  };

  const signed char
  parser::yycheck_[] =
  {
       1,     2,     3,     4,    19,    20,    21,    22,    23,    21,
      22,    23,    13,     7,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     3,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    24,    -1,    26,    27,     4,    -1,     6,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     6,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       8,     9,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     8,     9,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     8,     9,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     8,     9,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    19,    20,    24,    26,    27,    29,    30,    30,
      30,    30,    30,     7,     0,     6,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     4,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    28,    29,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"(\"", "\")\"",
  "PT_ERROR", "\",\"", "\"=\"", "\"!=\"", "\"==\"", "\"||\"", "\"&&\"",
  "\"|\"", "\"^\"", "\"&\"", "\"<\"", "\">\"", "\"<=\"", "\">=\"", "\"+\"",
  "\"-\"", "\"*\"", "\"/\"", "\"%\"", "\"!\"", "PT_UN", "PT_SYMBOL",
  "PT_NUM", "$accept", "input", "expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  parser::yyrline_[] =
  {
       0,    86,    86,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113
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
    const signed char
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
      25,    26,    27
    };
    // Last valid token kind.
    const int code_max = 282;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 6 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
} // TJSPP
#line 1144 "tjspp.tab.cpp"

#line 116 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjspp.y"
