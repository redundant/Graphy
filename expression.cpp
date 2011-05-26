#include "expression.h"

// inefficient, may replace with better way if needed later (unlikely)
int Choose::factorial(int n){
    if(n < 0)
        return 0; // not actually right, but make the hack in choose's evaluate work
    if(n = 0)
        return 1;
    return n*factorial(n-1);
}

int Choose::evaluate(){
    int a = left.evaluate();
    int b = right.evaluate();
    float temp = factorial(a)/(factorial(b)*factorial(a-b));
    return (int) temp;
}
