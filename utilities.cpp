#include "utilities.hpp"

/**
 * ! creer un nouveau tableau de n float
*/
float * newArrayFloat(int n){
    return (float*) malloc(n*sizeof(float));
}
/*
    creer un nouveau tableau de n entier
*/
int *newArrayInt(int n){
   return (int*) malloc(n*sizeof(int));
}

void displayArrayFloat(float*tab,int taille){
     for(int i=0;i<taille;i++){
       std::cout << tab[i]<<" : ";
    }
    std::cout<<"\n";
}
/*
    affiche un tableau d'entier
*/
void displayArrayInt(int*tab,int taille){
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

int countLengthArrayIntFromFile(char*fileName){
      int rno;
      int count=0;
      std::ifstream fin(fileName);
      //read data from the file student
      fin>>rno; 
      while(fin){
        count++;fin>>rno; 
      }
      fin.close();
      return count;
}

int countLengthArrayFloatFromFile(char*fileName){
      float rno;
      int count=0;
      std::ifstream fin(fileName);
      //read data from the file student
      fin>>rno; 
      while(fin){
        count++;fin>>rno; 
      }
      fin.close();
      return count;
}

float* readArrayFloatFromFile(char*fileName){
      float rno=2,fee=3;
      int count=countLengthArrayFloatFromFile(fileName);
      float*tab=newArrayFloat(count);
      std::ifstream fin(fileName);
      for(int i=0;i<count;i++){
         fin>>tab[i]; 
      }
      fin.close();
    return tab;
}
int * readArrayIntFromFile(char*fileName){
      int rno=2,fee=3;
      int count=countLengthArrayIntFromFile(fileName);
      int*tab=newArrayInt(count);
      std::ifstream fin(fileName);
      for(int i=0;i<count;i++){
         fin>>tab[i]; 
      }
      fin.close();
    return tab;
}