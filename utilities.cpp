#include "utilities.hpp"

/**
 * ! creer un nouveau tableau de n float
*/
float * newArrayFloat(int n){
    return (float*) malloc(n*sizeof(n));
}

void displayArrayFloat(float*tab,int taille){
     for(int i=0;i<taille;i++){
       std::cout << tab[i]<<" : ";
    }
    std::cout<<"\n";
}
void indent(int n){
    for(int i=0;i<n;i++){
       std::cout <<"         ";
    }
}