#ifndef TEST_HPP
#define TEST_HPP
#include <fstream>
#include <iostream>

/*
    creer un nouveau tableau de n float
*/
float *newArrayFloat(int n);
/*
    affiche un tableau de float
*/
void displayArrayFloat(float*tab,int taille);
void indent(int n);
int countLengthArrayFloatFromFile(char*fileName);
float* readArrayFloatFromFile(char*fileName);
#endif