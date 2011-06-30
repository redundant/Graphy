#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "graph.h"
#include <string>
#include <sstream>

class Expression{
    public:
        virtual int evaluate(Graph* g, int a, int b, int c = 0);
        Expression(){}
        virtual ~Expression(){}
        virtual std::string toString(){}
};

class Addition: public Expression{
    private:
        Expression* left;
        Expression* right;
    public:
        Addition(Expression* a, Expression* b){left = a; right = b;}
	int evaluate(Graph* g, int a, int b, int c){return left->evaluate(g,a,b,c) + right->evaluate(g,a,b,c);}
        ~Addition(){delete left; delete right;}
        std::string toString(){return "("+left->toString()+")"+"+"+"("+right->toString()+")";}
};

class Multiplication: public Expression{
    private:
        Expression* left;
        Expression* right;
    public:
        Multiplication(Expression* a, Expression* b){left = a; right = b;}
	int evaluate(Graph* g, int a, int b, int c){return left->evaluate(g,a,b,c) * right->evaluate(g,a,b,c);}
        ~Multiplication(){delete left; delete right;}
        std::string toString(){return "("+left->toString()+")"+"*"+"("+right->toString()+")";}
};

class Choose: public Expression{
    private:
        int factorial(int n);
        Expression* left;
        Expression*  right;
    public:
        Choose(Expression* a, Expression* b){left = a; right = b;}
        int evaluate(Graph* g, int a, int b, int c);
        ~Choose(){delete left; delete right;}
        std::string toString(){return "Binomial["+left->toString()+","+right->toString()+"]";}
};

class Number: public Expression{
    private:
        int val;
    public:
        Number (int a) { val = a;}
        int evaluate(Graph* g, int a, int b, int c){return val;}
        std::string toString(){std::stringstream ss; ss<< val; return ss.str();}
};

class N: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->size();}
        std::string toString(){return "n";}
};

class A: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->A(a,b,c);}
        std::string toString(){return "A";}
};

class B1: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B1(a,b,c);}
        std::string toString(){return "b";}
};

class B2: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B2(a,b,c);}
        std::string toString(){return "b";}
};

class B3: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B3(a,b,c);}
        std::string toString(){return "b";}
};

class B: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B1(a,b,c)+g->B2(a,b,c)+g->B3(a,b,c);}
        std::string toString(){return "b3";}
};

class C1: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C1(a,b,c);}
        std::string toString(){return "c";}
};

class C2: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C2(a,b,c);}
        std::string toString(){return "c";}
};

class C3: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C3(a,b,c);}
        std::string toString(){return "c";}
};

class C: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C1(a,b,c)+g->C2(a,b,c)+g->C3(a,b,c);}
        std::string toString(){return "c3";}
};

class J: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->J(a,b,c);}
        std::string toString(){return "j";}
};

class D: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->D(a,b,c);}
        std::string toString(){return "D";}
};

class E1: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E1(a,b,c);}
        std::string toString(){return "e";}
};

class E2: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E2(a,b,c);}
        std::string toString(){return "e";}
};

class E: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E1(a,b,c)+g->E2(a,b,c);}
        std::string toString(){return "e2";}
};

class F: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->F(a,b,c);}
        std::string toString(){return "f";}
};

class G1: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G1(a,b,c);}
        std::string toString(){return "g";}
};

class G2: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G2(a,b,c);}
        std::string toString(){return "g";}
};

class G: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G1(a,b,c)+g->G2(a,b,c);}
        std::string toString(){return "g2";}
};

class H: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->H(a,b,c);}
        std::string toString(){return "h";}
};

class I: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->I(a,b,c);}
        std::string toString(){return "I";}
};

class Ab: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Ab(a,b,c);}
        std::string toString(){return "Ab";}
};

class B1b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B1b(a,b,c);}
        std::string toString(){return "bb";}
};

class B2b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B2b(a,b,c);}
        std::string toString(){return "bb";}
};

class B3b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B3b(a,b,c);}
        std::string toString(){return "bb";}
};

class Bb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B1b(a,b,c)+g->B2b(a,b,c)+g->B3b(a,b,c);}
        std::string toString(){return "bb3";}
};

class C1b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C1b(a,b,c);}
        std::string toString(){return "cb";}
};

class C2b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C2b(a,b,c);}
        std::string toString(){return "cb";}
};

class C3b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C3b(a,b,c);}
        std::string toString(){return "cb";}
};

class Cb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C1b(a,b,c)+g->C2b(a,b,c)+g->C3b(a,b,c);}
        std::string toString(){return "cb3";}
};

class Jb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Jb(a,b,c);}
        std::string toString(){return "Jb";}
};

class Db: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Db(a,b,c);}
        std::string toString(){return "Db";}
};

class E1b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E1b(a,b,c);}
        std::string toString(){return "eb";}
};

class E2b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E2b(a,b,c);}
        std::string toString(){return "eb";}
};

class Eb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E1b(a,b,c)+g->E2b(a,b,c);}
        std::string toString(){return "eb2";}
};

class Fb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Fb(a,b,c);}
        std::string toString(){return "fb";}
};

class G1b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G1b(a,b,c);}
        std::string toString(){return "gb";}
};

class G2b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G2b(a,b,c);}
        std::string toString(){return "gb";}
};

class Gb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G1b(a,b,c)+g->G2b(a,b,c);}
        std::string toString(){return "gb2";}
};

class Hb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Hb(a,b,c);}
        std::string toString(){return "hb";}
};

class Ib: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Ib(a,b,c);}
        std::string toString(){return "Ib";}
};

#endif
