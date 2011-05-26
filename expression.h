#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression{
    public:
        virtual int evaluate(){return 0;}
};

class Addition: public Expression{
    private:
        Expression left;
        Expression right;
    public:
        Addition(Expression a, Expression b){left = a; right = b;}
        int evaluate(){return left.evaluate() * right.evaluate();}
};

class Multiplication: public Expression{
    private:
        Expression left;
        Expression right;
    public:
        Multiplication(Expression a, Expression b){left = a; right = b;}
        int evaluate(){return left.evaluate() * right.evaluate();}
};

class Choose: public Expression{
    private:
        int factorial(int n);
        Expression left, right;
    public:
        Choose(Expression a, Expression b){left = a; right = b;}
        int evaluate();
};

class Number: public Expression{
    private:
        int val;
    public:
        Number (int a) { val = a;}
        int evaluate(){return val;}
};


#endif
