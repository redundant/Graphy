#include "lincomb.h"
#include "expression.h"
#include "nonimic.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

Expression* parseExpression(std::string expr){
    // Assumes string is nonempty and valid PN with everything in parens
	
    expr = expr.substr(0,expr.length()-1);
    expr = expr.substr(1,expr.length());

        
    std::string left; // left and right things operated on by value
    std::string right; 
    
    int j = (int)expr.find("(");
    
    if(j == std::string::npos){
        if(expr.compare("N")==0)
            return new N();
        if(expr.compare("A")==0)
            return new A();   
        if(expr.compare("B1")==0)
            return new B1();
        if(expr.compare("B2")==0)
            return new B2();
        if(expr.compare("B3")==0)
            return new B3();
        if(expr.compare("B")==0)
            return new B();
        if(expr.compare("C1")==0)
            return new C1();
        if(expr.compare("C2")==0)
            return new C2();
        if(expr.compare("C3")==0)
            return new C3();
        if(expr.compare("C")==0)
            return new C();
        if(expr.compare("D")==0)
            return new D();
        if(expr.compare("E1")==0)
            return new E1();
        if(expr.compare("E2")==0)
            return new E2();
        if(expr.compare("E")==0)
            return new E();
        if(expr.compare("F")==0)
            return new F();
        if(expr.compare("G1")==0)
            return new G1();
        if(expr.compare("G2")==0)
            return new G2();
        if(expr.compare("G")==0)
            return new G();
        if(expr.compare("H")==0)
            return new H();
        return new Number(atoi(expr.c_str()));
    }

    int depth = 0;
    int i = j;
    while( j < expr.length()){
        if(expr.at(j)=='(')
            depth++;
        if(expr.at(j)==')')
            depth--;
        if(depth == 0)
            break;
        j++;
    }// Break into two parts
    
    left = expr.substr(i,j-1);// Have to be careful to remove spaces
    right = expr.substr(j+2);
    
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

int evaluateOnGraph(Expression* expr, Graph* graph){
    
    int val = 0;
	int temp = 0;

    for(int j = 2; j < graph->size(); j++){
        for(int k = 1; k < j; k++){
            for(int m = 0; m < k; m++){
                temp = expr->evaluate(graph,j,k,m);
                val+=temp;    
            }
        }
    }
    return val;
}

std::vector<int> evaluateOnGraphs(Expression* expr, NonIMIC* graphs){
    std::vector<int> temp;
    for(int i = 0; i < graphs->numOfGraphs(); i++){
        Graph* tempGraph = graphs->getGraph(i);
        temp.push_back(evaluateOnGraph(expr,tempGraph));
    }

    return temp;
}

std::vector<int> evaluateOnComplements(Expression* expr, NonIMIC* graphs){
    std::vector<int> temp;
    for(int i = 0; i < graphs->numOfGraphs(); i++){
        Graph* tempGraph = graphs->getComplementGraph(i);
        temp.push_back(evaluateOnGraph(expr,tempGraph));
    }

    return temp;
}

std::vector<std::vector<int> > createDependencyMatrix(std::vector<Expression*> expressions, NonIMIC* graphs){
    std::vector<std::vector<int> > temp;
    for(int i = 0; i < expressions.size(); i++){
        temp.push_back(evaluateOnGraphs(expressions[i],graphs));
    }

   for(int i = 0; i < expressions.size(); i++){
       temp.push_back(evaluateOnComplements(expressions[i],graphs));
   }
   

    return temp;
}
