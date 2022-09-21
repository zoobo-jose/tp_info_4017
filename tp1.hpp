#ifndef TP1_HPP
#define TP1_HPP
#include <iostream>
#include "utilities.hpp"

/* algorithme de karatsuba*/
float*karatsuba(float*p,float*q,int degreeP,int degreeQ);
/* algorithme de strassen*/
void strassen();
/**
 * ! complete le polynome p pour qu'il soit de degree n
 * @param p polynome
 * @param degreeP degree du polynome
*/
float * completer(float*p,int degreeP,int n);
/*
*/
int degreeFirstPart(int degree);
/**/
int degreeLastPart(int degree);
/**
 *retourne la premiere partie du polynome
 *@param degreeFp degree de la premiere partie
 *@param degreeLp degree de la derniere partie
*/
float * firstPart(float*p,int degreeP,int degreeFp,int degreeLp);
/**
 *retourne la derniere partie du polynome
 *@param degreeFp degree de la premiere partie
 *@param degreeLp degree de la derniere partie
*/
float * lastPart(float*p,int degreeP,int degreeLp);
/*
    additionne 2 polynomes p et q tel que le plus petit monome de p est
    plus grand que le plus grand monome de q
*/
float*addition(float*p,float*q,int degreeMaxP,int degreeMinP,int degreeMaxQ,int degreeMinQ);
/*
    addition deux polynome p et q tel que le degree du plus petit monome de p 
    soit aussi celui du plus petit monome de q
*/
float*additionSameDegree(float*p,float*q,int degreeP,int degreeQ);
/*
    mulptiplie par -1 , les coeffiscient d'un polynome
*/
float*negation(float*p,int degreeP);
/*
    application de karatsuba
*/
void part1();
#endif