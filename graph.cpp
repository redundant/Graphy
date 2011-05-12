#include "graph.h"

Graph::Graph(int v){
    n = v;
    adjacency = new int*[n];

    for(int i = 0; i < n; i++)
        adjacency[i] = new int[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            adjacency[i][j]=0;
        }
    }
}

Graph::~Graph(){
    for(int i = 0; i < n; i++){
        delete[] adjacency[n];
    }
    delete adjacency;
}

void Graph::connect(int i, int j){
    adjacency[i][j]=1;
    adjacency[j][i]=1;
}
