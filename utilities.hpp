#ifndef TEST_HPP
#define TEST_HPP
#include <fstream>
#include <iostream>

/*
    creer un nouveau tableau de n float
*/
float *newArrayFloat(int n);
/*
    creer un nouveau tableau de n entier
*/
int *newArrayInt(int n);
/*
    creer un nouveau tableau de n booleen
*/
bool *newArrayBool(int n);
/*
    affiche un tableau de float
*/
void displayArrayFloat(float*tab,int taille);
/*
    affiche un tableau d'entier
*/
void displayArrayInt(int*tab,int taille);
void indent(int n);
int countLengthArrayFloatFromFile(char*fileName);
int countLengthArrayIntFromFile(char*fileName);
float* readArrayFloatFromFile(char*fileName);
int* readArrayIntFromFile(char*fileName);
/*
    creer un nouveau mot vide
*/
char *newString(int n);
#endif