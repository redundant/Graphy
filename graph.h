#ifndef INCLUDED_GRAPH
#define INCLUDED_GRAPH
#include <string>

class Graph{
    private:
        int n;
        int**  adjacency;
        void connect(int i, int j);
        void disconnect(int i, int j);
    public:
        Graph(int v);
        ~Graph();
        void CreateFromAdjMatrix(int**  matrix);
        bool isConnected(int i, int j);
        std::string toString();
};
#endif
