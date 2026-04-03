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
#line 7 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"

#include <cstdlib>

#include "tjsTypes.h"
#include "tjsDateParser.h"

#line 46 "tjsdate.tab.cpp"




#include "tjsdate.tab.hpp"




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

#line 5 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
namespace TJSDate {
#line 127 "tjsdate.tab.cpp"

  /// Build a parser object.
  parser::parser (tTJSDateParser *ptr_yyarg)
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
  case 3: // date_time_string: wday_omittable DP_NUMBER month DP_NUMBER time tz_omittable
#line 60 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                {	ptr->SetMDay((yystack_[4].value.val));
															ptr->SetYear((yystack_[2].value.val)); }
#line 585 "tjsdate.tab.cpp"
    break;

  case 4: // date_time_string: wday_omittable DP_NUMBER '-' month DP_NUMBER time tz_omittable
#line 67 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                {	ptr->SetMDay((yystack_[5].value.val));
															ptr->SetYear((yystack_[2].value.val)); }
#line 592 "tjsdate.tab.cpp"
    break;

  case 5: // date_time_string: wday_omittable DP_NUMBER '-' month '-' DP_NUMBER time tz_omittable
#line 74 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                {	ptr->SetMDay((yystack_[6].value.val));
															ptr->SetYear((yystack_[2].value.val)); }
#line 599 "tjsdate.tab.cpp"
    break;

  case 6: // date_time_string: wday_omittable month DP_NUMBER DP_NUMBER time tz_omittable
#line 81 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                {	ptr->SetMDay((yystack_[3].value.val));
															ptr->SetYear((yystack_[2].value.val)); }
#line 606 "tjsdate.tab.cpp"
    break;

  case 7: // date_time_string: wday_omittable month '-' DP_NUMBER DP_NUMBER time tz_omittable
#line 88 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                {	ptr->SetMDay((yystack_[3].value.val));
															ptr->SetYear((yystack_[2].value.val)); }
#line 613 "tjsdate.tab.cpp"
    break;

  case 8: // date_time_string: wday_omittable month '-' DP_NUMBER '-' DP_NUMBER time tz_omittable
#line 95 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                {	ptr->SetMDay((yystack_[4].value.val));
															ptr->SetYear((yystack_[2].value.val)); }
#line 620 "tjsdate.tab.cpp"
    break;

  case 9: // date_time_string: wday_omittable DP_NUMBER month time DP_NUMBER tz_omittable
#line 103 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                {	ptr->SetMDay((yystack_[4].value.val));
															ptr->SetYear((yystack_[1].value.val)); }
#line 627 "tjsdate.tab.cpp"
    break;

  case 10: // date_time_string: wday_omittable DP_NUMBER '-' month time DP_NUMBER tz_omittable
#line 111 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                {	ptr->SetMDay((yystack_[5].value.val));
															ptr->SetYear((yystack_[1].value.val)); }
#line 634 "tjsdate.tab.cpp"
    break;

  case 11: // date_time_string: wday_omittable month DP_NUMBER time DP_NUMBER tz_omittable
#line 118 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                {	ptr->SetMDay((yystack_[3].value.val));
															ptr->SetYear((yystack_[1].value.val)); }
#line 641 "tjsdate.tab.cpp"
    break;

  case 12: // date_time_string: wday_omittable month '-' DP_NUMBER time DP_NUMBER tz_omittable
#line 125 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                {	ptr->SetMDay((yystack_[3].value.val));
															ptr->SetYear((yystack_[1].value.val)); }
#line 648 "tjsdate.tab.cpp"
    break;

  case 13: // date_time_string: wday_omittable DP_NUMBER hyphen_or_slash DP_NUMBER hyphen_or_slash DP_NUMBER time tz_omittable
#line 133 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                {	ptr->SetMonth((yystack_[4].value.val)-1);
															ptr->SetYear((yystack_[6].value.val));
															ptr->SetMDay((yystack_[2].value.val)); }
#line 656 "tjsdate.tab.cpp"
    break;

  case 18: // month: DP_MONTH
#line 150 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                        { ptr->SetMonth((yystack_[0].value.val)); }
#line 662 "tjsdate.tab.cpp"
    break;

  case 21: // time_sub_sec_omittable: '.' DP_NUMBER
#line 160 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                { /* TODO: sub-seconds support */ }
#line 668 "tjsdate.tab.cpp"
    break;

  case 23: // time_hms: DP_NUMBER ':' DP_NUMBER ':' DP_NUMBER time_sub_sec_omittable
#line 168 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                {
			ptr->SetHours((yystack_[5].value.val));
			ptr->SetMin((yystack_[3].value.val));
			ptr->SetSec((yystack_[1].value.val));
		}
#line 678 "tjsdate.tab.cpp"
    break;

  case 24: // time_hms: DP_NUMBER ':' DP_NUMBER
#line 175 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                {
			ptr->SetHours((yystack_[2].value.val));
			ptr->SetMin((yystack_[0].value.val));
			ptr->SetSec(0);
		}
#line 688 "tjsdate.tab.cpp"
    break;

  case 25: // am_or_pm: DP_AM
#line 183 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                        { ptr->SetAMPM(false); }
#line 694 "tjsdate.tab.cpp"
    break;

  case 26: // am_or_pm: DP_PM
#line 184 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                        { ptr->SetAMPM(true); }
#line 700 "tjsdate.tab.cpp"
    break;

  case 30: // tz_name_omittable: DP_TZ
#line 194 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                        { ptr->SetTimeZone((yystack_[0].value.val)); }
#line 706 "tjsdate.tab.cpp"
    break;

  case 32: // tz_offset_omittable: '+' DP_NUMBER
#line 199 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                { ptr->SetTimeZoneOffset((yystack_[0].value.val)); }
#line 712 "tjsdate.tab.cpp"
    break;

  case 33: // tz_offset_omittable: '-' DP_NUMBER
#line 200 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                { ptr->SetTimeZoneOffset(-(yystack_[0].value.val)); }
#line 718 "tjsdate.tab.cpp"
    break;

  case 35: // $@1: %empty
#line 207 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
                                                                                                                { ptr->SkipToRightParenthesis(); }
#line 724 "tjsdate.tab.cpp"
    break;


#line 728 "tjsdate.tab.cpp"

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









  const signed char parser::yypact_ninf_ = -22;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
       4,   -22,    14,   -22,    22,    34,   -22,   -22,    11,   -22,
      26,    55,   -22,    47,    40,    51,    57,    24,   -22,   -22,
       3,    39,    58,    59,    -8,     3,    60,    44,     3,    61,
      62,    56,    63,    52,   -22,   -22,    52,   -22,    65,    52,
      52,     3,    66,    67,    52,    54,    52,    64,   -22,    -5,
     -22,   -22,    54,   -22,   -22,    52,    54,    52,   -22,    52,
     -22,    68,    69,    70,    71,    52,   -22,    52,   -22,   -22,
      72,   -22,   -22,   -22,   -22,   -22,   -22,    73,   -22,    74,
     -22,   -22
  };

  const signed char
  parser::yydefact_[] =
  {
      17,    14,     0,     2,    16,     0,     1,    15,     0,    18,
       0,    19,    20,     0,     0,     0,     0,     0,    25,    26,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    29,    28,    31,    19,     0,    31,
      31,     0,     0,     0,    31,     0,    31,    24,    30,    34,
       3,     9,     0,     6,    11,    31,     0,    31,     4,    31,
      10,     0,     0,     0,    37,    31,     7,    31,    12,     5,
      22,    33,    32,    35,    38,    13,     8,     0,    23,     0,
      21,    36
  };

  const signed char
  parser::yypgoto_[] =
  {
     -22,   -22,   -22,   -22,   -22,    13,    75,   -22,    76,    79,
     -15,   -22,   -22,   -22,   -22,   -21
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     5,    10,    14,    78,    21,    22,
      23,    49,    64,    74,    79,    50
  };

  const signed char
  parser::yytable_[] =
  {
      26,    37,    30,    12,    62,    33,    18,    19,    31,    63,
      39,     1,    43,    44,     6,    51,    32,     9,    53,    54,
      11,    13,    12,    58,    17,    60,    55,    18,    19,    28,
      59,    15,     7,    29,    66,    16,    68,    65,    69,     8,
       9,    67,    18,    19,    75,    24,    76,    18,    19,    41,
      18,    19,    20,    42,    18,    19,    25,    18,    19,    31,
      48,     9,    27,    31,    36,    40,    45,    46,    47,    32,
      52,    56,    57,    70,    71,    72,     0,    61,    80,     0,
       0,     0,     0,     0,    77,     0,    73,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,    35,    38,
      34
  };

  const signed char
  parser::yycheck_[] =
  {
      15,     9,    17,    11,     9,    20,     3,     4,     5,    14,
      25,     7,    27,    28,     0,    36,    13,     6,    39,    40,
       9,     8,    11,    44,    11,    46,    41,     3,     4,     5,
      45,     5,    10,     9,    55,     9,    57,    52,    59,     5,
       6,    56,     3,     4,    65,     5,    67,     3,     4,     5,
       3,     4,     5,     9,     3,     4,     5,     3,     4,     5,
       8,     6,     5,     5,     5,     5,     5,     5,     5,    13,
       5,     5,     5,     5,     5,     5,    -1,    13,     5,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    15,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    24,
      21
  };

  const signed char
  parser::yystos_[] =
  {
       0,     7,    18,    19,    20,    21,     0,    10,     5,     6,
      22,     9,    11,    22,    23,     5,     9,    22,     3,     4,
       5,    25,    26,    27,     5,     5,    27,     5,     5,     9,
      27,     5,    13,    27,    26,    25,     5,     9,    23,    27,
       5,     5,     9,    27,    27,     5,     5,     5,     8,    28,
      32,    32,     5,    32,    32,    27,     5,     5,    32,    27,
      32,    13,     9,    14,    29,    27,    32,    27,    32,    32,
       5,     5,     5,    15,    30,    32,    32,    12,    24,    31,
       5,    16
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    17,    18,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    20,    21,    21,    21,    22,    23,
      23,    24,    24,    25,    25,    26,    26,    27,    27,    27,
      28,    28,    29,    29,    29,    31,    30,    30,    32
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     6,     7,     8,     6,     7,     8,     6,
       7,     6,     7,     8,     1,     2,     1,     0,     1,     1,
       1,     2,     0,     6,     3,     1,     1,     1,     2,     2,
       1,     0,     2,     2,     0,     0,     3,     0,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "DP_AM", "DP_PM",
  "DP_NUMBER", "DP_MONTH", "DP_WDAY", "DP_TZ", "'-'", "','", "'/'", "'.'",
  "':'", "'+'", "'('", "')'", "$accept", "input", "date_time_string",
  "wday", "wday_omittable", "month", "hyphen_or_slash",
  "time_sub_sec_omittable", "time_hms", "am_or_pm", "time",
  "tz_name_omittable", "tz_offset_omittable", "tz_desc_omittable", "$@1",
  "tz_omittable", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    46,    46,    56,    63,    70,    77,    84,    91,    98,
     106,   114,   121,   128,   139,   143,   144,   145,   150,   154,
     155,   160,   161,   165,   173,   183,   184,   188,   189,   190,
     194,   195,   199,   200,   201,   207,   207,   209,   213
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
      15,    16,     2,    14,    10,     9,    12,    11,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    13,     2,
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
       5,     6,     7,     8
    };
    // Last valid token kind.
    const int code_max = 263;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
} // TJSDate
#line 1132 "tjsdate.tab.cpp"

#line 219 "/home/wmt/KrKr2-Next/cpp/core/tjs2/bison/tjsdate.y"
