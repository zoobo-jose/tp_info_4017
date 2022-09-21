#ifndef TP1_HPP
#define TP1_HPP
#include <iostream>
#include "utilities.hpp"

/* algorithme de karatsuba*/
float*karatsuba(float*p,float*q,int degreeP,int degreeQ);
/* algorithme de strassen*/
float*strassen(float*A,float*B,int dim);
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

/* ********************************* utilitaire pour strassen ****************************************/
/* cree une matrice carre de dimension nxn*/
float * newSquaredMatrice(int n);
/* met a jour l'element de la matrice */
void setElementMatrice(float*M,int dimM,int i,int j,float val);
/* retourne l'element de la matrice */
float getElementMatrice(float*M,int dimM,int i,int j);
/* affiche la matrice */
void displayMatrice(float*M,int dimM);
/*
    complete la matrice pour au'elle soit une matrice de taille pair
    en ajoutant evantuellement une ligne en bas et une colonne a droite
*/
float*completeToPair(float*M,int dimM);
/*
    decoupe retire une matrice carre A de taille dimM/2
    de la matrice M tel que A[i][j]=M[i+deltaI][j+deltaJ]
    N.B: dimM doit est de preference paire
*/
float*decoupeMatrice(float*M,int dimM,int deltaI,int deltaJ);
/*
    retourne la sous matrice a de taille dimM/2 tel que 
    a[i][j]=M[i][j]
*/
float*subMatrice1(float*M,int dimM);
/*
    retourne la sous matrice b de taille dimM/2 tel que 
    b[i][j]=M[i][j+dimM/2]
*/
float*subMatrice2(float*M,int dimM);
/*
    retourne la sous matrice c de taille dimM/2 tel que 
    c[i][j]=M[i+dimM/2][j];
*/
float*subMatrice3(float*M,int dimM);
/*
    retourne la sous matrice d de taille dimM/2 tel que 
    d[i][j]=M[i+dimM/2][j+dimM/2];
*/
float*subMatrice4(float*M,int dimM);
/*
    additionne 2 matrice carre de meme dimension
*/
float*additionMatrice(float*A,float*B,int dim);
/*
    retourne  une matrice contenant les negation des elements
    de la matrice M
*/
float*negationMatrice(float*M,int dimM);
/*
    rassemble 4 matrice carree a ,b ,c et d de meme dimmention en une
    matrice M tel que  M=|a  b|
                         |c  d|
*/
float*rassembler(float*A,float*B,float*C,float*D,int dim);
/*
    retourne une matrice A de dimention dim contenant les elements de M tel
    que A[i][j]=M[i][j] avec 0<=i<=dim et  0<=j<=dim
*/
float* subMatrice(float*M,int dimM,int dim);
/*
    application de strassen
*/
void part2();
#endif