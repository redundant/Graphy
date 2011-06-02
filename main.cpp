#include "nonimic.h"
#include "expression.h"
#include <string>
#include <iostream>
#include <fstream>

int main(){
    Number a(4);
    Number b(5);
    Multiplication c(&a,&b);
    Addition d(&a,&c);
    Expression* e = &a;
    return 0;
}
