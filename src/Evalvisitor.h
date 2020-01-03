#ifndef PYTHON_INTERPRETER_EVALVISITOR_H
#define PYTHON_INTERPRETER_EVALVISITOR_H


#include "Python3BaseVisitor.h"
#include"Int.h"
#include<stack>
#include<map>
#include<vector>
#include"dvar.h"
#include"Int.h"
#include<algorithm>
using std::vector, std::string,std::cout, std::endl;
enum flowName{is_break, is_return, is_continue};
std::stack<std::map<std::string, dvar>> the_stack; //variables
std::map<std::string , Python3Parser::SuiteContext*> suite; // suite of function
std::map<std::string, Python3Parser::TypedargslistContext*> tyarg; // argslist of function
void ass(vector<dvar> & v)
{
  for(int i = 0; i < v.size(); ++i)
  if(v[i].gettype() == is_varname) v[i] = the_stack.top()[v[i].getstring()];
}
bool check(const antlrcpp::Any &tmp)
{
  return (tmp.is<vector<dvar>>()) ? true:false;
}
struct OP
{
  int flag;
  int place;
};
bool cp(OP x, OP y)
{
  return (x.place < y.place);
}


class EvalVisitor: public Python3BaseVisitor {

//todo:override all methods of Python3BaseVisitor
virtual antlrcpp::Any visitFile_input(Python3Parser::File_inputContext *ctx) override {
    std::map<string,dvar>v1;
    the_stack.push(v1);
    vector<flowName> v;
    antlrcpp::Any tmp;

    for(int i = 0; i < ctx->stmt().size(); ++i)
    {
      tmp = visit(ctx->stmt(i));
      if(tmp.is<vector<flowName>>())
      {
        v = tmp.as<vector<flowName>>();
        if (v[0] == is_return) return nullptr;
      }
      
    }
    return nullptr;
  }

  virtual antlrcpp::Any visitFuncdef(Python3Parser::FuncdefContext *ctx) override {
  suite[ctx->NAME()->toString()] = ctx->suite();
  tyarg[ctx->NAME()->toString()] = ctx->parameters()->typedargslist();
  return nullptr;

  }

  virtual antlrcpp::Any visitParameters(Python3Parser::ParametersContext *ctx) override {
    return visit(ctx->typedargslist());
  }

  virtual antlrcpp::Any visitTypedargslist(Python3Parser::TypedargslistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTfpdef(Python3Parser::TfpdefContext *ctx) override {
    return ctx->NAME()->toString();
  }

  virtual antlrcpp::Any visitStmt(Python3Parser::StmtContext *ctx) override {
    if(ctx->simple_stmt()) return visit(ctx->simple_stmt());
    if(ctx->compound_stmt()) return visit(ctx->compound_stmt());
  }

  virtual antlrcpp::Any visitSimple_stmt(Python3Parser::Simple_stmtContext *ctx) override {
    if(ctx->small_stmt())
    return visit(ctx->small_stmt());
    return nullptr;
  }

  virtual antlrcpp::Any visitSmall_stmt(Python3Parser::Small_stmtContext *ctx) override {
    if(ctx->expr_stmt()) return visit(ctx->expr_stmt());
    if(ctx->flow_stmt()) return visit(ctx->flow_stmt());
  }

  virtual antlrcpp::Any visitExpr_stmt(Python3Parser::Expr_stmtContext *ctx) override {
    vector<dvar>v1,v2;
    v1 = visit(ctx->testlist(ctx->testlist().size() - 1)).as<vector<dvar>>();
    if(ctx->testlist().size() == 1) return nullptr;
    if(ctx->augassign())
    {
      v2 = visit(ctx->testlist(0)).as<vector<dvar>>();
      ass(v1);
      switch (ctx->augassign()->getText()[0])
      {
        case '+':
        for(int i = 0; i < v1.size(); ++i)
        {
          the_stack.top()[v2[i].getstring()] += v1[i];
        }
        break;

        case '-':
        for(int i = 0; i < v1.size(); ++i)
        {
          the_stack.top()[v2[i].getstring()] -= v1[i];
        }
        break;

        case '*':
        for(int i = 0; i < v1.size(); ++i)
        {
          the_stack.top()[v2[i].getstring()] *= v1[i];
        }
        break;

        case '%':
        for(int i = 0; i < v1.size(); ++i)
        {
          the_stack.top()[v2[i].getstring()] %= v1[i];
        }
        break;

        case '/':
        if(ctx->augassign()->getText()[1] == '/')
        for(int i = 0; i < v1.size(); ++i)
        {
          the_stack.top()[v2[i].getstring()] /= v1[i];
        }
        else
        {
            for(int i = 0; i < v1.size(); ++i)
            {
              the_stack.top()[v2[i].getstring()] = dvar((double)the_stack.top()[v2[i].getstring()] /(double)v1[i]);
            }
        }
        break;
      }
      return nullptr;
    }

    else// assignment
    {
      ass(v1);
      for(int i = ctx->testlist().size() - 2; i >= 0; --i)
      {
        v2 = visit(ctx->testlist(i)).as<vector<dvar>>();
        for(int j = 0; j < v2.size();++j)
        the_stack.top()[v2[j].getstring()] = v1[j];
      }
      return nullptr;
    }
  }

  virtual antlrcpp::Any visitAugassign(Python3Parser::AugassignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlow_stmt(Python3Parser::Flow_stmtContext *ctx) override {
    vector<flowName> v;
    if(ctx->break_stmt()) 
    {
      v.push_back(is_break);
      return v;
    }
    if(ctx->continue_stmt())
    {
      v.push_back(is_continue);
      return v;
    }
    if(ctx->return_stmt())
    return visit(ctx->return_stmt());
    return nullptr;
  }

  virtual antlrcpp::Any visitBreak_stmt(Python3Parser::Break_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContinue_stmt(Python3Parser::Continue_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn_stmt(Python3Parser::Return_stmtContext *ctx) override {
    if(ctx->testlist() == nullptr) return (vector<flowName>(1,is_return));
    vector<dvar> v=visit(ctx->testlist()).as<vector<dvar>>();ass(v);
    //cout << v[0];
    return v;
  }

  virtual antlrcpp::Any visitCompound_stmt(Python3Parser::Compound_stmtContext *ctx) override {
    if(ctx->if_stmt())  return visit(ctx->if_stmt());
    if(ctx->while_stmt()) return visit(ctx->while_stmt());
    if(ctx->funcdef()) return visit(ctx->funcdef());
  }

  virtual antlrcpp::Any visitIf_stmt(Python3Parser::If_stmtContext *ctx) override {
    vector<dvar>v;
    antlrcpp::Any tmp;
    int i = 0;
    for(; i < ctx->test().size(); ++i)
    {
      v = visit(ctx->test(i)).as<vector<dvar>>();
      if(v[0].getbool()) 
      {
        tmp = visit(ctx->suite(i));
        if(tmp.is<vector<dvar>>() && !tmp.as<vector<dvar>>().empty())
          return tmp;
          return nullptr;
      }
    }
    if(ctx->ELSE())
    tmp =  visit(ctx->suite(i));
    return nullptr;
  }

  virtual antlrcpp::Any visitWhile_stmt(Python3Parser::While_stmtContext *ctx) override {
    vector<flowName> v; antlrcpp::Any tmp;
    while(visit(ctx->test()).as<vector<dvar>>()[0].getbool())
    {
      tmp = visit(ctx->suite());
      if(tmp.is<vector<flowName>>())
      {
        v = tmp.as<vector<flowName>>();
        if (v[0] == is_break) break;
        if (v[0] == is_continue) continue;
        if (v[0] == is_return) return v;

      }
      if(tmp.is<vector<dvar>>() && !tmp.as<vector<dvar>>().empty())
      return tmp;
    }
    return nullptr;
  }

  virtual antlrcpp::Any visitSuite(Python3Parser::SuiteContext *ctx) override {
    if(ctx->simple_stmt()) return visit(ctx->simple_stmt());
    antlrcpp::Any tmp;
    for (int i = 0; i < ctx->stmt().size(); ++i)
    {
      tmp = visit(ctx->stmt(i));
      if(tmp.is<vector<flowName>>() || ( tmp.is<vector<dvar>>() && !tmp.as<vector<dvar>>().empty()))
      return tmp;
    }
    return nullptr;
  }

  virtual antlrcpp::Any visitTest(Python3Parser::TestContext *ctx) override {
    return visit(ctx->or_test());
  }

  virtual antlrcpp::Any visitOr_test(Python3Parser::Or_testContext *ctx) override {
    vector<dvar> v ;
    if(ctx->and_test().size() == 1) return visit(ctx->and_test(0));
    for(int i = 0; i < ctx->and_test().size(); ++i)
    {
      v = visit(ctx->and_test(i)).as<vector<dvar>>();
      ass(v);
      v[0].to_bool();
      if(v[0].getbool()) return v;
    }
    return v;
  }

  virtual antlrcpp::Any visitAnd_test(Python3Parser::And_testContext *ctx) override {
    vector<dvar> v ;
    if(ctx->not_test().size() == 1) return visit(ctx->not_test(0));
    for(int i = 0; i < ctx->not_test().size(); ++i)
    {
      v = visit(ctx->not_test(i)).as<vector<dvar>>();
      ass(v);
      v[0].to_bool();
      if(!v[0].getbool()) return v;
    }
    return v;
    
  }

  virtual antlrcpp::Any visitNot_test(Python3Parser::Not_testContext *ctx) override {
    if(ctx->not_test() == nullptr)  return visit(ctx->comparison());
    vector<dvar> v = visit(ctx->not_test()).as<vector<dvar>>();
    ass(v);
    v[0].to_bool();
    v[0] = dvar(!v[0].getbool());
    return v;
  }

  virtual antlrcpp::Any visitComparison(Python3Parser::ComparisonContext *ctx) override {
    if(ctx->arith_expr().size() == 1) return visit(ctx->arith_expr(0));
    vector<dvar> v1,v2,v;
    string Op;
    for(int i = 1; i < ctx->arith_expr().size(); ++i)
    {
      v1 = visit(ctx->arith_expr(i - 1)).as<vector<dvar>>();
      v2 = visit(ctx->arith_expr(i)).as<vector<dvar>>();
      ass(v1);ass(v2);
      Op = visit(ctx->comp_op(i - 1)).as<vector<dvar>>()[0].getstring();
      switch (Op[0])
      {
        case '=':
        v = (v1[0] == v2[0]) ? vector<dvar>(1,dvar(true)):vector<dvar>(1,dvar(false));
        break;

        case '!':
        v = (v1[0] == v2[0]) ? vector<dvar>(1,dvar(false)):vector<dvar>(1,dvar(true));
        break;

        case '>':
        if(Op.length() > 1)
        v = (v1[0] >= v2[0]) ? vector<dvar>(1,dvar(true)):vector<dvar>(1,dvar(false));
        else
        v = (v1[0] > v2[0]) ? vector<dvar>(1,dvar(true)):vector<dvar>(1,dvar(false));
        break;

        case '<':
        if(Op.length() > 1)
        v = (v1[0] <= v2[0]) ? vector<dvar>(1,dvar(true)):vector<dvar>(1,dvar(false));
        else
        v = (v1[0] < v2[0]) ? vector<dvar>(1,dvar(true)):vector<dvar>(1,dvar(false));
        break;
      }
      if(!v[0].getbool()) return v;
    }
    return v;
  }

  virtual antlrcpp::Any visitComp_op(Python3Parser::Comp_opContext *ctx) override {
    vector<dvar>v;
    if(ctx->LESS_THAN()) {v.push_back(dvar(string("\"<\"")));return v;}
    if(ctx->GREATER_THAN()) {v.push_back(dvar(string("\">\"")));return v;}
    if(ctx->GT_EQ()) {v.push_back(dvar(string("\">=\"")));return v;}
    if(ctx->LT_EQ()) {v.push_back(dvar(string("\"<=\"")));return v;}
    if(ctx->NOT_EQ_2()) {v.push_back(dvar(string("\"!=\"")));return v;}
    if(ctx->EQUALS()) {v.push_back(dvar(string("\"==\"")));return v;}
    
  }

  virtual antlrcpp::Any visitArith_expr(Python3Parser::Arith_exprContext *ctx) override {
    int cnt1  = ctx->ADD().size(), cnt2 = ctx->MINUS().size(),i = 0;
    antlrcpp::Any an = visit(ctx->term(0));
    vector<dvar> v2,v1;
    if(an.is<vector<dvar>>())
    v1 = an.as<vector<dvar>>();
    
    if(ctx->term().size() == 1) return v1;
    ass(v1);
    vector<OP> am;
    for(int i = 0; i < cnt1; ++i)
    am.push_back({1, ctx->ADD(i)->getSymbol()->getTokenIndex()});
    for(int i = 0; i < cnt2; ++i)
    am.push_back({0,ctx->MINUS(i)->getSymbol()->getTokenIndex()});
    std:sort(am.begin(),am.end(),cp);
    dvar tmp = v1[0];
    for(int i = 0; i < am.size() ; ++i)
    {
      v2 = visit(ctx->term(i + 1)).as<vector<dvar>>();
      ass(v2);
      if(am[i].flag == 1) 
        tmp += v2[0];
      else 
        tmp -= v2[0];
    }
    
    return (vector<dvar>(1,tmp));
    
  }

  virtual antlrcpp::Any visitTerm(Python3Parser::TermContext *ctx) override {
    antlrcpp::Any an = visit(ctx->factor(0));
    vector<dvar> v2,v1;
    if(an.is<vector<dvar>>())
    v1 = an.as<vector<dvar>>();
    
    if(ctx->factor().size() == 1) return v1;
    ass(v1);
    int c1 = ctx->STAR().size(), c2 = ctx->DIV().size(), c3 = ctx->IDIV().size(), c4 = ctx->MOD().size();
    vector<OP> am;
    OP TMP;
    for(int i = 0; i < c1; ++i)
    am.push_back({1, ctx->STAR(i)->getSymbol()->getTokenIndex()});
    for(int i = 0; i < c2; ++i)
    am.push_back({2,ctx->DIV(i)->getSymbol()->getTokenIndex()});
    for(int i = 0; i < c3; ++i)
    am.push_back({3, ctx->IDIV(i)->getSymbol()->getTokenIndex()});
    for(int i = 0; i < c4; ++i)
    am.push_back({4,ctx->MOD(i)->getSymbol()->getTokenIndex()});
    std::sort(am.begin(), am.end(),cp);
    dvar tmp = v1[0];
    for(int i = 0; i < am.size() ; ++i)
    {
      v2 = visit(ctx->factor(i + 1)).as<vector<dvar>>();
      ass(v2);
      switch (am[i].flag)
      {
        case 1:
        tmp *= v2[0];
        break;

        case 2:
        tmp = dvar((double)tmp / (double)v2[0]);
        break;

        case 3:
        tmp /= v2[0];
        break;
        
        case 4:
        tmp %= v2[0];
        break;
      }
    }
    return (vector<dvar>(1,tmp));
  }

  virtual antlrcpp::Any visitFactor(Python3Parser::FactorContext *ctx) override {
    if(ctx->atom_expr()) 
    return visit(ctx->atom_expr());
    vector<dvar>v = visit(ctx->factor()).as<vector<dvar>>();
    ass(v);
    if(ctx->MINUS()) 
    {
      dvar mi(string("-1"));
      v[0] *= mi;
    }
    return v;

  }

  virtual antlrcpp::Any visitAtom_expr(Python3Parser::Atom_exprContext *ctx)  {
    if(ctx->trailer()) 
    {
        string funcname = ctx->atom()->NAME()->toString();
        if(funcname == string("print"))
        { 
            int n = ctx->trailer()->arglist()->argument().size();
            vector<dvar> v;
            vector<dvar> tmp;
            for(int i = 0; i < n; ++i) 
            {
              tmp = visit(ctx->trailer()->arglist()->argument(i)->test()).as<vector<dvar>>();
              for(int j = 0; j < tmp.size(); ++j)
              v.push_back(tmp[j]); 
            }
            ass(v);
            for(int i = 0;i < v.size(); ++i)
            {
              cout << v[i];
              if(i != v.size() - 1) cout << ' ';
            }
            cout << '\n';
            if(!v.empty())
            v.clear();
            return v;

        }
        else if (funcname == string("int"))
        {
          vector <dvar> v = visit(ctx->trailer()->arglist()->argument()[0]->test()) .as<vector<dvar>>();
          if(v[0].gettype() == is_varname)  v[0] = the_stack.top()[v[0].getstring()];
          v[0].to_Int();
          return v;
        }

        else if (funcname == string("float"))
        {
          vector <dvar> v = visit(ctx->trailer()->arglist()->argument()[0]->test()) .as<vector<dvar>>();
          if(v[0].gettype() == is_varname)  v[0] = the_stack.top()[v[0].getstring()];
          v[0].to_double();
          return v;
        }

        else if(funcname == string("str"))
        {
          vector <dvar> v = visit(ctx->trailer()->arglist()->argument()[0]->test()) .as<vector<dvar>>();
          if(v[0].gettype() == is_varname)  v[0] = the_stack.top()[v[0].getstring()];
          v[0].to_string();
          return v;
        }
        else if(funcname == string("bool"))
        {
          vector <dvar> v = visit(ctx->trailer()->arglist()->argument()[0]->test()) .as<vector<dvar> >();
          if(v[0].gettype() == is_varname)  v[0] = the_stack.top()[v[0].getstring()];
          v[0].to_bool();
          return v;
        }
        else // func
        {
          vector<dvar> v1;
          std::map<string,dvar> curvar;
          if(tyarg[funcname])
          {
            int i = 0;
            for(i = 0; i < tyarg[funcname]->tfpdef().size() - tyarg[funcname]->test().size(); ++i)
            curvar[tyarg[funcname]->tfpdef(i)->NAME()->toString()] = dvar(false);
            for(i = 0; i < tyarg[funcname]->test().size(); ++i)
            {
              v1 = visit(tyarg[funcname]->test(i)).as<vector<dvar>>();
              ass(v1);
              size_t count = i + tyarg[funcname]->tfpdef().size() - tyarg[funcname]->test().size();
              curvar[tyarg[funcname]->tfpdef(count)->NAME()->toString()] = v1[0];
            }
            
            for(i = 0; i < ctx->trailer()->arglist()->argument().size(); ++i)
            {
              if(ctx->trailer()->arglist()->argument(i)->NAME())
              {
                v1 = visit(ctx->trailer()->arglist()->argument(i)->test()).as<vector<dvar>>();
                ass(v1);
                curvar[ctx->trailer()->arglist()->argument(i)->NAME()->toString()] = v1[0];

              }

              else
              {
                v1 = visit(ctx->trailer()->arglist()->argument(i)->test()).as<vector<dvar>>();
                ass(v1);
                string tmp111 = tyarg[funcname]->tfpdef(i)->NAME()->toString();
                curvar[tyarg[funcname]->tfpdef(i)->NAME()->toString()] = v1[0];
              }
              
            }
          }
          std::map<string,dvar>::iterator iter;
          std::map<string,dvar> globalvar = the_stack.top();
          iter = globalvar.begin();
          while(iter != globalvar .end())
          {
            curvar[iter->first] = iter->second;
            ++iter;
            
          }
          the_stack.push(curvar);
          antlrcpp::Any tmp = visit(suite[funcname]);
          if(tmp.is<vector<dvar>>())
          {
            vector<dvar> vre = tmp.as<vector<dvar>>();
            the_stack.pop();
            return vre;
          }  
          the_stack.pop();
          if(!v1.empty())
          v1.clear();
          if(check(tmp)) return tmp.as<vector<dvar>>();
          return v1;
        }
        

    }
    

    else // atom
    {
      return visit(ctx->atom());
    }
    
    
  }

   virtual antlrcpp::Any visitTrailer(Python3Parser::TrailerContext *ctx) override {
     return visit(ctx->arglist());
   }

  virtual antlrcpp::Any visitAtom(Python3Parser::AtomContext *ctx) override {
    vector<dvar> v;
    if (ctx->NAME()) 
    {
      dvar tmp;
      tmp.inivar(ctx->NAME()->toString());
      return vector<dvar>(1,tmp);
    }

     if (ctx->NUMBER()) 
    {
      return vector<dvar>(1,dvar(ctx->NUMBER()->toString()));
    }
    if (ctx->STRING(0)) 
    {
      std::string tmpString;
      for (int i = 0; i < ctx->STRING().size(); i++) 
      {
        tmpString += ctx->STRING(i)->toString();
      }
      return vector<dvar>(1,dvar(tmpString));
    }

    if(ctx->NONE())
    {
      return vector<dvar>(1,dvar(ctx->NONE()->toString()));
    }

      if(ctx->TRUE())
    {
      return vector<dvar>(1,dvar(ctx->TRUE()->toString()));
    }

      if(ctx->FALSE())
    {
      return vector<dvar>(1,dvar(ctx->FALSE()->toString()));
    }
       if(ctx->test())
    {
      return visit(ctx->test());
    }

    return v;
    
  }

  virtual antlrcpp::Any visitTestlist(Python3Parser::TestlistContext *ctx) override {
    vector<dvar> v1,v2;
    dvar tmp;
    for (int i = 0; i < ctx->test().size(); ++i)
    {
      v1 = visit(ctx->test(i)).as<vector<dvar>>();
      if(!v1.empty())
      {
        tmp = v1[0];
        v2.push_back(tmp);
      }
    }
    return v2;
  }

  // virtual antlrcpp::Any visitArglist(Python3Parser::ArglistContext *ctx) override {
  //   return visit(ctx->argument(0));
  // }

  // virtual antlrcpp::Any visitArgument(Python3Parser::ArgumentContext *ctx) override {
  //   return visit(ctx->test());
  // }


};


#endif //PYTHON_INTERPRETER_EVALVISITOR_H
