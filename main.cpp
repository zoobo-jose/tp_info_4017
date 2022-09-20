using namespace std;
#include <iostream>
#include "tp1.hpp"

int main()
{
    float p[]={1,1,1};
    float q[]={1,1,1};
    float*resultat=karatsuba(p,q,2,2);
    displayArrayFloat(resultat,10);
    return 0;
}