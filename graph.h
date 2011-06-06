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
        int size(){return n;}
        void CreateFromAdjMatrix(int**  matrix);
        bool isConnected(int i, int j);
        std::string toString();
        int A(int a, int b, int c);// returns number incident with abc if abc form a K3
        int B1(int a, int b, int c);// similar, but with bc
        int B2(int a, int b, int c);// ac
        int B3(int a, int b, int c);// ab
        int C1(int a, int b, int c);// a
        int C2(int a, int b, int c);// b
        int C3(int a, int b, int c);// c
        int D(int a, int b, int c);// returns number incident with abc if abc form a K3 without edge bc
        int E1(int a, int b, int c);//ab
        int E2(int a, int b, int c);//ac
        int F(int a, int b, int c);//bc
        int G1(int a, int b, int c);//b
        int G2(int a, int b, int c);//c
        int H(int a, int b, int c);//a
        int Ab(int a, int b, int c);// returns number incident with abc if abc form an I3
        int B1b(int a, int b, int c);// similar, but with bc
        int B2b(int a, int b, int c);// ac
        int B3b(int a, int b, int c);// ab
        int C1b(int a, int b, int c);// a
        int C2b(int a, int b, int c);// b
        int C3b(int a, int b, int c);// c
        int Db(int a, int b, int c);// returns number incident with abc if abc form an I3 with edge bc
        int E1b(int a, int b, int c);//ab
        int E2b(int a, int b, int c);//ac
        int Fb(int a, int b, int c);//bc
        int G1b(int a, int b, int c);//b
        int G2b(int a, int b, int c);//c
        int Hb(int a, int b, int c);//a
};
#endif
