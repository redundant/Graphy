#include "nonimic.h"
#include "expression.h"
#include "lincomb.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]){
    NonIMIC* graphs = new NonIMIC(argv[1]);
    std::vector<Expression*> expressions = parseFile(argv[2]);
    std::vector<std::vector<int> > matrix = createDependencyMatrix(expressions, graphs);    
    std::cout<<"{{"<<matrix[0][0];
    for(int j = 1; j < matrix[0].size(); j++){
        std::cout<<","<<matrix[0][j];
    }
    std::cout<<"}";
    for(int i = 1; i < matrix.size(); i++){
        std::cout<<",{"<<matrix[i][0];
        for(int j = 1; j < matrix[i].size(); j++){
            std::cout<<","<<matrix[i][j];
        }
        std::cout<<"}";
    }
    std::cout<<"}\n";
    for(int i = 0; i < expressions.size(); i++)
        delete expressions[i];    

    delete graphs;
    return 0;
}
