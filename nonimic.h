#ifndef NONIMIC_H
#define NONIMIC_H

#include "graph.h"
#include <string>
#include <vector>

/*
This class reads in graphs from a file and stores an enumeration of them

It is expected that all graphs will have the same degree. In the usage here,
the graphs are all nonisomorphic
*/
class NonIMIC{
    private:
        std::vector<Graph*> graphs;
        std::vector<Graph*> complements;
        int degree;
    public:
        NonIMIC(std::string file);
        ~NonIMIC();
        int numOfGraphs(){return graphs.size();}
        Graph* getGraph(int n){return graphs[n];}
        Graph* getComplementGraph(int n){return complements[n];}
};

#endif
