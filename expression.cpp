#include "expression.h"

int Sum::evaluate(){
    int temp = 0;
    for(int a= 2; a  < g->size(); a++){
        for(int b = 1; b < a; b++){
            for(int c = 0; c < b; c++)
                temp+= term->evaluate(g,a,b,c);
        }
    }
    return temp;
}

int Expression::evaluate(Graph* g, int a, int b, int c){
    return 0;
}

// inefficient, may replace with better way if needed later (unlikely)
int Choose::factorial(int n){
    if(n < 0)
        return 0; //meh
    if(n = 0)
        return 1;
    return n*factorial(n-1);
}

int Choose::evaluate(Graph* g, int e, int f, int h){
    int a = left->evaluate(g, e, f, h);
    int b = right->evaluate(g, e, f, h);
    if( a < b)
        return 0;
    float temp = factorial(a)/(factorial(b)*factorial(a-b));
    return (int) temp;
}
