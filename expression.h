#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "graph.h"

class Expression{
    public:
        virtual int evaluate(Graph* g, int a, int b, int c);
};

class Sum{
    private:
        Expression* term;
        Graph* g;
    public:
        Sum(Expression* summand, Graph* graph){g = graph; term = summand;}
        int evaluate(); 
};

class Addition: public Expression{
    private:
        Expression* left;
        Expression* right;
    public:
        Addition(Expression* a, Expression* b){left = a; right = b;}
        int evaluate(Graph* g, int a, int b, int c){return left->evaluate(g,a,b,c) * right->evaluate(g,a,b,c);}
};

class Multiplication: public Expression{
    private:
        Expression* left;
        Expression* right;
    public:
        Multiplication(Expression* a, Expression* b){left = a; right = b;}
        int evaluate(Graph* g, int a, int b, int c){return left->evaluate(g,a,b,c) * right->evaluate(g,a,b,c);}
};

class Choose: public Expression{
    private:
        int factorial(int n);
        Expression* left;
        Expression*  right;
    public:
        Choose(Expression* a, Expression* b){left = a; right = b;}
        int evaluate(Graph* g, int a, int b, int c);
};

class Number: public Expression{
    private:
        int val;
    public:
        Number (int a) { val = a;}
        int evaluate(Graph* g, int a, int b, int c){return val;}
};

class A: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->A(a,b,c);}
};

class B1: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->B1(a,b,c);}
};

class B2: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->B2(a,b,c);}
};

class B3: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->B3(a,b,c);}
};

class C1: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->C1(a,b,c);}
};

class C2: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->C2(a,b,c);}
};

class C3: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->C3(a,b,c);}
};

class D: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->D(a,b,c);}
};

class E1: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->E1(a,b,c);}
};

class E2: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->E2(a,b,c);}
};

class F: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->F(a,b,c);}
};

class G1: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->G1(a,b,c);}
};

class G2: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->G2(a,b,c);}
};

class G3: public Expression{
    public:
        int Evaluate(Graph* g, int a, int b, int c){return g->G3(a,b,c);}
};
#endif
