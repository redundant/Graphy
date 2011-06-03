#include "nonimic.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>


NonIMIC::NonIMIC(std::string file){
    std::ifstream in(file.c_str());
    std::string input;
    int size;
    std::string* row;

    if(in.is_open()){
        std::getline(in, input);
        size  = atoi(input.c_str());
        int** matrix = new int*[size];
        
        for(int i=0; i < size; i++){
            matrix[i] = new int[size];
        }
        while(getline(in,input)){
            for(int i = 0; i < size; i++){
	        while(getline(in,input) && input ==""){}
                
                std::istringstream iss(input);
	        for(int j = 0; j < size; j++){
	            std::string value;
		    iss >> value;
	            matrix[i][j] = atoi(value.c_str());
                }
            }        
            Graph* g = new Graph(size);
            Graph* gc = new Graph(size);
            g->CreateFromAdjMatrix(matrix);
            for(int i = 0; i < size; i++){
                for(int j = 0; j < i; j++){
                    if(i != j){
                        if(matrix[i][j] == 1){
                            matrix[i][j] = 0;
                            matrix[j][i] = 0;
                        }
                        else{
                            matrix[i][j] = 1;
                            matrix[j][i] = 1;
                        }
                    }
                }
            }
            gc->CreateFromAdjMatrix(matrix);
	    graphs.push_back(g);
            complements.push_back(gc);
        }       

        in.close();
        for(int i = 0; i < size; i++){
            delete[] matrix[i];
        }

        delete matrix;
    }
    else std::cout<<"Unable to open file";
}

NonIMIC::~NonIMIC(){
    for(int i = 0; i < graphs.size(); i++){
        delete graphs[i];
        delete complements[i];
    }
}
