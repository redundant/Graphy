#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "graph.h"

class Expression{
    public:
        virtual int evaluate(Graph* g, int a, int b, int c);
        Expression(){}
        virtual ~Expression(){}
};

class Addition: public Expression{
    private:
        Expression* left;
        Expression* right;
    public:
        Addition(Expression* a, Expression* b){left = a; right = b;}
	int evaluate(Graph* g, int a, int b, int c){return left->evaluate(g,a,b,c) + right->evaluate(g,a,b,c);}
        ~Addition(){delete left; delete right;}
};

class Multiplication: public Expression{
    private:
        Expression* left;
        Expression* right;
    public:
        Multiplication(Expression* a, Expression* b){left = a; right = b;}
	int evaluate(Graph* g, int a, int b, int c){return left->evaluate(g,a,b,c) * right->evaluate(g,a,b,c);}
        ~Multiplication(){delete left; delete right;}
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
};

class Number: public Expression{
    private:
        int val;
    public:
        Number (int a) { val = a;}
        int evaluate(Graph* g, int a, int b, int c){return val;}
};

class N: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->size();}
};

class A: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->A(a,b,c);}
};

class B1: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B1(a,b,c);}
};

class B2: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B2(a,b,c);}
};

class B3: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B3(a,b,c);}
};

class B: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B1(a,b,c)+g->B2(a,b,c)+g->B3(a,b,c);}
};

class C1: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C1(a,b,c);}
};

class C2: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C2(a,b,c);}
};

class C3: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C3(a,b,c);}
};

class C: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C1(a,b,c)+g->C2(a,b,c)+g->C3(a,b,c);}
};

class J: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->J(a,b,c);}
};

class D: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->D(a,b,c);}
};

class E1: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E1(a,b,c);}
};

class E2: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E2(a,b,c);}
};

class E: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E1(a,b,c)+g->E2(a,b,c);}
};

class F: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->F(a,b,c);}
};

class G1: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G1(a,b,c);}
};

class G2: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G2(a,b,c);}
};

class G: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G1(a,b,c)+g->G2(a,b,c);}
};

class H: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->H(a,b,c);}
};

class I: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->I(a,b,c);}
};

class Ab: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Ab(a,b,c);}
};

class B1b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B1b(a,b,c);}
};

class B2b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B2b(a,b,c);}
};

class B3b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B3b(a,b,c);}
};

class Bb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->B1b(a,b,c)+g->B2b(a,b,c)+g->B3b(a,b,c);}
};

class C1b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C1b(a,b,c);}
};

class C2b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C2b(a,b,c);}
};

class C3b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C3b(a,b,c);}
};

class Cb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->C1b(a,b,c)+g->C2b(a,b,c)+g->C3b(a,b,c);}
};

class Jb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Jb(a,b,c);}
};
class Db: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Db(a,b,c);}
};

class E1b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E1b(a,b,c);}
};

class E2b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E2b(a,b,c);}
};

class Eb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->E1b(a,b,c)+g->E2b(a,b,c);}
};

class Fb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Fb(a,b,c);}
};

class G1b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G1b(a,b,c);}
};

class G2b: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G2b(a,b,c);}
};

class Gb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->G1b(a,b,c)+g->G2b(a,b,c);}
};

class Hb: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Hb(a,b,c);}
};

class Ib: public Expression{
    public:
        int evaluate(Graph* g, int a, int b, int c){return g->Ib(a,b,c);}
};
#endif
