#include "graph.h"
#include <sstream>

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
        delete[] adjacency[i];
    }
    delete adjacency;
}

void Graph::connect(int i, int j){
    adjacency[i][j]=1;
    adjacency[j][i]=1;
}

void Graph::disconnect(int i, int j){
    adjacency[i][j] = 0;
    adjacency[j][i] = 0;
}

//Make sure to actually pass an nxn matrix here, or die
void Graph::CreateFromAdjMatrix(int** matrix){
    for(int i = 0; i < n; i++){
        for(int j=0; j < i; j++){
            if(matrix[i][j] == 1)
                connect(i,j);
            if(matrix[i][j] == 0)
                disconnect(i,j);
        }
    }
}

bool Graph::isConnected(int i, int j){
    if(adjacency[i][j] == 1)
        return true;
    return false;
}

std::string Graph::toString(){
    std::ostringstream oss;
    for(int i= 0; i < n; i++){
        for(int j= 0; j < n; j++){
            oss<<adjacency[i][j]<<" ";
            oss.flush();
        }
        oss<<std::endl;
    }
    return oss.str();
}

int Graph::A(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==1){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[a][i]==1&&adjacency[b][i]==1&&adjacency[c][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}

int Graph::B1(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==1){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[b][i]==1&&adjacency[c][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}

int Graph::B2(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==1){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[a][i]==1&&adjacency[c][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}
int Graph::B3(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[a][i]==1&&adjacency[b][i]==1&&adjacency[c][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}

int Graph::C1(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==1){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[a][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}

int Graph::C2(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==1){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[b][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}

int Graph::C3(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==1){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[c][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}

int Graph::D(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==0){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[a][i]==1&&adjacency[b][i]==1&&adjacency[c][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}


int Graph::E1(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==0){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[a][i]==1 && adjacency[b][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}

int Graph::E2(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==0){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[a][i]==1 && adjacency[c][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}

int Graph::F(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==0){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[b][i]==1 && adjacency[c][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}

int Graph::G1(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==0){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[a][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}

int Graph::G2(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==0){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[b][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}

int Graph::G3(int a, int b, int c){
    int temp = 0;
    if(adjacency[a][b]==1 && adjacency[a][c]==1 && adjacency[b][c]==0){
        for(int i = 0; i < n; i++){
            if(i!=a && i!=b && i !=c){
                if(adjacency[c][i]==1)
                    temp++;
            }
        }
    }
    return temp;
}
