using namespace std;
#include <iostream>
#include "tp1.hpp"

int main()
{
    float p[]={0,3,0,2};
    float q[]={1,1};
    float*resultat=karatsuba(p,q,3,1,0);
    displayArrayFloat(resultat,7);
    // float*f=addition(p,q,2,0,1,0);
    // displayArrayFloat(f,10);
    return 0;
}