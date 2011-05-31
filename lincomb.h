#ifndef LINCOMB_H
#define LINCOMB_H

#include "expression.h"
#include "nonimic.h"
#include <string>
#include <vector>

//Make sure to clean up memory, this uses new
Expression* parseExpression(std::string expr);

std::vector<Expression*> parseFile(std::string filename);

std::vector<int> evaluateOnGraphs(Expression* expr, NonIMIC* graphs);

std::vector<std::vector<int> > createDependencyMatrix(std::vector<Expression*> expressions, NonIMIC* graphs);

#endif 
