#include "lincomb.h"
#include "expression.h"
#include "nonimic.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

Expression* parseExpression(std::string expr){
    // Assumes string is nonempty and valid PN with everything in parens
    expr.erase(0,1);
    expr.erase(expr.end()-1, expr.end());

        
    std::string left; // left and right things operated on by value
    std::string right; 
    
    int j = (int)expr.find("(");
    
    if(j == std::string::npos){
        if(expr.compare("A")==0)
            return new A();   
        if(expr.compare("B1")==0)
            return new B1();
        if(expr.compare("B2")==0)
            return new B2();
        if(expr.compare("B3")==0)
            return new B3();
        if(expr.compare("C1")==0)
            return new C1();
        if(expr.compare("C2")==0)
            return new C2();
        if(expr.compare("C3")==0)
            return new C3();
        if(expr.compare("D")==0)
            return new D();
        if(expr.compare("E1")==0)
            return new E1();
        if(expr.compare("E2")==0)
            return new E2();
        if(expr.compare("F")==0)
            return new F();
        if(expr.compare("G1")==0)
            return new G1();
        if(expr.compare("G2")==0)
            return new G2();
        if(expr.compare("G3")==0)
            return new G3();
        return new Number(atoi(expr.c_str()));
    }

    int depth = 0;
    int i = j;
    while( i < expr.length()){
        if(expr.at(i)=='(')
            depth++;
        if(expr.at(i)==')')
            depth--;
        if(depth == 0)
            break;
        i++;
    }// Break into two parts
    
    left = expr.substr(i,j);
    right = expr.substr(j+1);
    
    if(expr.at(0) =='+'){
        return new Addition(parseExpression(left),parseExpression(right));
    }
    
    if(expr.at(0) =='*'){
        return new Multiplication(parseExpression(left),parseExpression(right));
    }

    if(expr.at(0) =='C'){
        return new Choose(parseExpression(left),parseExpression(right));
    }
}

std::vector<Expression*> parseFile(std::string filename){
    std::ifstream in(filename.c_str());
    std::string input;
    std::vector<Expression*> temp;

    if(in.is_open()){
        while(getline(in,input))
            temp.push_back(parseExpression(input));
    }
    
    in.close();    

    return temp;
}

std::vector<int> evaluateOnGraphs(Expression* expr, NonIMIC* graphs){
    std::vector<int> temp;
    
    for(int i = 0; i < graphs->numOfGraphs(); i++){
        Graph* tempGraph = graphs->getGraph(i);
        int val = 0;

        for(int j = 2; j < tempGraph->size(); j++){
            for(int k = 1; k < j; k++){
                for(int m = 0; m < k; m++){
                    val+=expr->evaluate(tempGraph,j,k,m);    
                }
            }
        }
        temp.push_back(val);
    }
    return temp;
}

std::vector<std::vector<int> > createDependencyMatrix(std::vector<Expression*> expressions, NonIMIC* graphs){
    std::vector<std::vector<int> > temp;
    for(int i = 0; i < expressions.size(); i++){
        temp.push_back(evaluateOnGraphs(expressions[i],graphs));
    }

    return temp;
}
