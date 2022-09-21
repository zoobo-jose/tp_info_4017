#include "tp1.hpp"

/* algorithme de karatsuba*/
float *karatsuba(float *p, float *q, int degreeP, int degreeQ)
{
    // cas de base
    if (degreeP <= 1 && degreeQ <= 1)
    {
        float *newP = newArrayFloat(3);
        p = completer(p, degreeP, 1);
        q = completer(q, degreeQ, 1);
        newP[0] = p[0] * q[0];
        newP[1] = p[0] * q[1] + p[1] * q[0];
        newP[2] = p[1] * q[1];
        return newP;
    }
    else
    {
        int degree = degreeP;
        // completer
        if (degreeP > degreeQ)
        {
            q = completer(q, degreeQ, degreeP);
        }
        else if (degreeP < degreeQ)
        {
            p = completer(p, degreeP, degreeQ);
            degree = degreeQ;
        }
        // karatsuba
        int degreeFp = degreeFirstPart(degree);
        int degreeLp = degreeLastPart(degree);
        float *p1 = lastPart(p, degree, degreeLp);
        float *p2 = firstPart(p, degree, degreeFp, degreeLp);
        float *q1 = lastPart(q, degree, degreeLp);
        float *q2 = firstPart(q, degree, degreeFp, degreeLp);
        float *r1 = karatsuba(p1, q1, degreeLp, degreeLp);
        float *r2 = karatsuba(p2, q2, degreeFp, degreeFp);
        float *r3 = karatsuba(
            additionSameDegree(p1, p2, degreeLp, degreeFp),
            additionSameDegree(q1, q2, degreeLp, degreeFp),
            degreeFp, degreeFp);
        float *somme = additionSameDegree(r3, negation(r1, degree), degree, degree);
        somme = additionSameDegree(somme, negation(r2, degree), degree, degree);
        float *resultat = addition(r2, somme, 2 * degree, 2 * (degree - degreeFp),
                                   2 * degreeFp + degree - degreeFp, degree - degreeFp);
        return addition(resultat, r1, 2 * degree, degree - degreeFp, 2 * degreeLp, 0);
    }
}
/* algorithme de strassen*/
float*strassen(float*A,float*B,int dim){
 //cas de base
   if(dim<=3){
        float*C= newSquaredMatrice(dim);
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                 setElementMatrice(C,dim,i,j,0);
                for(int k=0;k<dim;k++){
                    float val=getElementMatrice(C,dim,i,j);
                    val+=getElementMatrice(A,dim,i,k)*getElementMatrice(B,dim,k,j);
                    setElementMatrice(C,dim,i,j,val);
                }
            }
        }
        return C;
   }
   //strassen
        //completer
    int oldDim=dim;
    if(dim%2!=0){
        A=completeToPair(A,dim);
        B=completeToPair(B,dim);
        dim++;
    }
        //decoupe de A
    float*a=subMatrice1(A,dim);
    float*b=subMatrice2(A,dim);
    float*c=subMatrice3(A,dim);
    float*d=subMatrice4(A,dim);
        //decoupe de B
    float*e=subMatrice1(B,dim);
    float*f=subMatrice2(B,dim);
    float*g=subMatrice3(B,dim);
    float*h=subMatrice4(B,dim);
        //calcule des X
    float* x1= strassen( 
        additionMatrice(b,negationMatrice(d,dim/2),dim/2),
        additionMatrice(g,h,dim/2),dim/2);
    float* x2= strassen( 
        additionMatrice(a,d,dim/2),
        additionMatrice(e,h,dim/2),dim/2);
    float* x3= strassen( 
        additionMatrice(a,negationMatrice(c,dim/2),dim/2),
        additionMatrice(e,f,dim/2),dim/2);
    float* x4= strassen(additionMatrice(a,b,dim/2),h,dim/2);
    float* x5= strassen(a,
        additionMatrice(f,negationMatrice(h,dim/2),dim/2),dim/2);
    float* x6= strassen(d,
        additionMatrice(g,negationMatrice(e,dim/2),dim/2),dim/2);
    float* x7= strassen(additionMatrice(c,d,dim/2),e,dim/2);
        //calcule des parties
    float*p1= additionMatrice(x1,x2,dim/2);
    p1=additionMatrice(p1,negationMatrice(x4,dim/2),dim/2);
    p1=additionMatrice(p1,x6,dim/2);
    float*p2=additionMatrice(x4,x5,dim/2);
    float*p3=additionMatrice(x6,x7,dim/2);
    float*p4=additionMatrice(x2,negationMatrice(x3,dim/2),dim/2);
    p4=additionMatrice(p4,x5,dim/2);
    p4=additionMatrice(p4,negationMatrice(x7,dim/2),dim/2);
        //resultat
    float*C=rassembler(p1,p2,p3,p4,dim/2);
    return subMatrice(C,dim,oldDim);
}

/* ********************************* utilitaire pour karatsuba ****************************************/

/* complete le polynome p pour qu'il soit de degree n*/
float *completer(float *p, int degreeP, int n)
{
    float *newP = newArrayFloat(n);
    for (int i = 0; i <= n; i++)
    {
        if (i <= degreeP)
        {
            newP[i] = p[i];
        }
        else
        {
            newP[i] = 0;
        }
    }
    return newP;
}
/**/
int degreeFirstPart(int degree)
{
    return degree - degreeLastPart(degree) - 1;
}

int degreeLastPart(int degree)
{
    return (degree + 1) / 2 - 1;
}

float *firstPart(float *p, int degreeP, int degreeFp, int degreeLp)
{
    float *newP = newArrayFloat(degreeFp + 1);
    for (int i = 0; i <= degreeFp; i++)
    {
        newP[i] = p[i + degreeLp + 1];
    }
    return newP;
}

float *lastPart(float *p, int degreeP, int degreeLp)
{
    float *newP = newArrayFloat(degreeLp + 1);
    for (int i = 0; i <= degreeLp; i++)
    {
        newP[i] = p[i];
    }
    return newP;
}

float *addition(float *p, float *q, int degreeMaxP, int degreeMinP, int degreeMaxQ, int degreeMinQ)
{
    int min = degreeMinP;
    int max = degreeMaxP;
    if (min > degreeMinQ)
    {
        min = degreeMinQ;
    }
    if (max < degreeMaxQ)
    {
        max = degreeMaxQ;
    }
    float *newP = newArrayFloat(max - min + 1);
    for (int i = 0; i <= max - min; i++)
    {
        int index = i + min;
        newP[i] = 0;
        if (index >= degreeMinP && index <= degreeMaxP)
        {
            newP[i] += p[index - degreeMinP];
        }
        if (index >= degreeMinQ && index <= degreeMaxQ)
        {
            newP[i] += q[index - degreeMinQ];
        }
    }
    return newP;
}
float *additionSameDegree(float *p, float *q, int degreeP, int degreeQ)
{
    int degree = degreeP;
    if (degreeQ > degreeP)
    {
        degree = degreeQ;
    }
    float *newP = newArrayFloat(degree + 1);
    for (int i = 0; i <= degree; i++)
    {
        newP[i] = 0;
        if (i <= degreeP)
        {
            newP[i] += p[i];
        }
        if (i <= degreeQ)
        {
            newP[i] += q[i];
        }
    }
    return newP;
}
float *negation(float *p, int degreeP)
{
    float *newP = newArrayFloat(degreeP + 1);
    for (int i = 0; i <= degreeP; i++)
    {
        newP[i] = p[i] * -1;
    }
    return newP;
}
/*
    application de karatsuba
*/
void part1()
{
    float *p = readArrayFloatFromFile("data/polynome1.txt");
    float *q = readArrayFloatFromFile("data/polynome2.txt");
    int degreeP = countLengthArrayFloatFromFile("data/polynome1.txt") - 1;
    int degreeQ = countLengthArrayFloatFromFile("data/polynome2.txt") - 1;
    float *resultat = karatsuba(p, q, degreeP, degreeQ);
    displayArrayFloat(resultat, degreeP + degreeQ + 1);
}
/* ********************************* utilitaire pour strassen ****************************************/
/* cree une matrice carre de dimension nxn*/
float *newSquaredMatrice(int n)
{
    return newArrayFloat(n * n);
}
void setElementMatrice(float *M, int dimM, int i, int j, float val)
{
    int index = dimM * i + j;
    M[index] = val;
}
float getElementMatrice(float *M, int dimM, int i, int j)
{
    int index = dimM * i + j;
    return M[index];
}

void displayMatrice(float *M, int dimM)
{
    for (int i = 0; i < dimM; i++)
    {
        for (int j = 0; j < dimM; j++)
        {
            std::cout << getElementMatrice(M, dimM, i, j) << " ";
        }
        std::cout << "\n";
    }
}

float*completeToPair(float*M,int dimM){
    if(dimM%2!=0){
        float*A=newSquaredMatrice(dimM+1);
         for (int i = 0; i < dimM+1; i++){
             for (int j = 0; j < dimM+1; j++){
                if(i<dimM&&j<dimM){
                    float val=getElementMatrice(M,dimM,i,j);
                    setElementMatrice(A,dimM+1,i,j,val);
                }else{
                    setElementMatrice(A,dimM+1,i,j,0);
                }
             }
         }
         return A;
    }
    return M;
}

float*decoupeMatrice(float*M,int dimM,int deltaI,int deltaJ){
    float*A= newSquaredMatrice(dimM/2);
    for (int i = 0; i < dimM/2; i++){
        for (int j = 0; j < dimM/2; j++){
             float val=getElementMatrice(M,dimM,i+deltaI,j+deltaJ);
             setElementMatrice(A,dimM/2,i,j,val);
        }
    }
    return A;
}
/*
    retourne la sous matrice a de taille dimM/2 tel que 
    a[i][j]=M[i][j]
*/
float*subMatrice1(float*M,int dimM){
    return decoupeMatrice(M,dimM,0,0);
}
/*
    retourne la sous matrice b de taille dimM/2 tel que 
    b[i][j]=M[i][j+dimM/2]
*/
float*subMatrice2(float*M,int dimM){
    return decoupeMatrice(M,dimM,0,dimM/2);
}
/*
    retourne la sous matrice c de taille dimM/2 tel que 
    c[i][j]=M[i+dimM/2][j];
*/
float*subMatrice3(float*M,int dimM){
    return decoupeMatrice(M,dimM,dimM/2,0);
}
/*
    retourne la sous matrice d de taille dimM/2 tel que 
    d[i][j]=M[i+dimM/2][j+dimM/2];
*/
float*subMatrice4(float*M,int dimM){
     return decoupeMatrice(M,dimM,dimM/2,dimM/2);
}
/*
    additionne 2 matrice carre de meme dimension
*/
float*additionMatrice(float*A,float*B,int dim){
    float*C= newSquaredMatrice(dim);
    for (int i = 0; i < dim; i++){
         for (int j = 0; j < dim; j++){
            float val=getElementMatrice(A,dim,i,j)+getElementMatrice(B,dim,i,j);
            setElementMatrice(C,dim,i,j,val);
         }
    }
    return C;
}

/*
    retourne  une matrice contenant les negation des elements
    de la matrice M
*/
float*negationMatrice(float*M,int dimM){
    float*A= newSquaredMatrice(dimM);
    for (int i = 0; i < dimM; i++){
         for (int j = 0; j < dimM; j++){
            float val=-1*getElementMatrice(M,dimM,i,j);
            setElementMatrice(A,dimM,i,j,val);
         }
    }
    return A;
}
/*
    rassemble 4 matrice carree a ,b ,c et d de meme dimmention en une
    matrice M tel que  M=|a  b|
                         |c  d|
*/
float*rassembler(float*A,float*B,float*C,float*D,int dim){
    float*M= newSquaredMatrice(2*dim);
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
             float val=getElementMatrice(A,dim,i,j);
             setElementMatrice(M,2*dim,i,j,val);
        }
        for (int j = dim; j < 2*dim; j++){
             float val=getElementMatrice(B,dim,i,j-dim);
             setElementMatrice(M,2*dim,i,j,val);
        }
    }
    for (int i = dim; i < 2*dim; i++){
        for (int j = 0; j < dim; j++){
             float val=getElementMatrice(C,dim,i-dim,j);
             setElementMatrice(M,2*dim,i,j,val);
        }
        for (int j = dim; j < 2*dim; j++){
             float val=getElementMatrice(D,dim,i-dim,j-dim);
             setElementMatrice(M,2*dim,i,j,val);
        }
    }
    return M;
}
/*
    retourne une matrice A de dimention dim contenant les elements de M tel
    que A[i][j]=M[i][j] avec 0<=i<=dim et  0<=j<=dim
*/
float* subMatrice(float*M,int dimM,int dim){
    float*A= newSquaredMatrice(dim);
    for (int i =0; i <dim; i++){
        for (int j = 0; j < dim; j++){
            float val=getElementMatrice(M,dimM,i,j);
            setElementMatrice(A,dim,i,j,val);
        }
    }
    return A;
}

void part2()
{
    int n = 4;
    float *M = newSquaredMatrice(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            setElementMatrice(M, n, i, j, i%2+j%2);
        }
    }
    displayMatrice(M,n);
    std::cout<<"\n";
    displayMatrice(strassen(M,M,n),n);
}