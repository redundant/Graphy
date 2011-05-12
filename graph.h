#ifndef INCLUDED_GRAPH
#define INCLUDED_GRAPH
#include <vector>

class Graph{
    private:
        int n;
        int**  adjacency;
        void connect(int i, int j);
        ~Graph();
    public:
        Graph(int v);
};
#endif
