#include "tp1.hpp"

/* algorithme de karatsuba*/
float*karatsuba(float*p,float*q,int degreeP,int degreeQ){
    //cas de base
    if(degreeP==0&&degreeQ==0){
        float *newP=newArrayFloat(1);
        newP[0]=p[0]*q[0];
        return newP;
    }else{
        int degree=degreeP;
        //completer
        if(degreeP>degreeQ){
            q=completer(q,degreeQ,degreeP);
        }else
        if(degreeP<degreeQ){
            p=completer(p,degreeP,degreeQ);
            degree=degreeQ;
        }
        //karatsuba
        int degreeFp=degreeFirstPart(degree);
        int degreeLp=degreeLastPart(degree);
        float*p1=lastPart(p,degree,degreeLp);
        float*p2=firstPart(p,degree,degreeFp,degreeLp);
        float*q1=lastPart(q,degree,degreeLp);
        float*q2=firstPart(q,degree,degreeFp,degreeLp);
        float*r1=karatsuba(p1,q1,degreeLp,degreeLp);
        float*r2=karatsuba(p2,q2,degreeFp,degreeFp);
        float*r3=karatsuba(
            additionSameDegree(p1,p2,degreeLp,degreeFp),
            additionSameDegree(q1,q2,degreeLp,degreeFp),
            degreeFp,degreeFp
        );
        float*somme=additionSameDegree(r3,negation(r1,2*degreeLp),2*degreeFp,2*degreeLp);
        somme=additionSameDegree(somme,negation(r2,2*degreeFp),2*degreeFp,2*degreeFp);
        float*resultat=addition(r2,somme,2*degreeFp,2*degreeFp);
        return addition(resultat,r1,4*degreeFp+1,2*degreeLp);
    }
}
/* algorithme de strassen*/
void strassen(){
    std::cout << "strassen algorithme !\n";
}

/* ********************************* utilitaire pour karatsuba ****************************************/

/* complete le polynome p pour qu'il soit de degree n*/
float * completer(float*p,int degreeP,int n){
    float *newP=newArrayFloat(n);
    for(int i=0;i<=n;i++){
        if(i<=degreeP){
            newP[i]=p[i];
        }else{
             newP[i]=0;
        }
    }
    return newP;
}
/**/
int degreeFirstPart(int degree){
    return degree-degreeLastPart(degree)-1;
}

int degreeLastPart(int degree){
   return (degree+1)/2-1;
}

float * firstPart(float*p,int degreeP,int degreeFp,int degreeLp){
    float *newP=newArrayFloat(degreeFp+1);
    for(int i=0;i<=degreeFp;i++){
        newP[i]=p[i+degreeLp+1];
    }
    return newP;
}

float * lastPart(float*p,int degreeP,int degreeLp){
    float *newP=newArrayFloat(degreeLp+1);
    for(int i=0;i<=degreeLp;i++){
        newP[i]=p[i];
    }
    return newP;
}

float*addition(float*p,float*q,int degreeP,int degreeQ){
    float *newP=newArrayFloat(degreeP+degreeQ+2);
    for(int i=0;i<=degreeQ;i++){
        newP[i]=q[i];
    }
    for(int i=0;i<=degreeP;i++){
        newP[i+degreeQ+1]=p[i];
    }
    return newP;
}
float*additionSameDegree(float*p,float*q,int degreeP,int degreeQ){
    int degree=degreeP;
    if(degreeQ>degreeP){
        degree=degreeQ;
    }
    float *newP=newArrayFloat(degree+1);
    for(int i=0;i<=degree;i++){
        newP[i]=0;
        if(i<=degreeP){
             newP[i]+=p[i];
        }
        if(i<=degreeQ){
             newP[i]+=q[i];
        }
    }
    return newP;
}
float*negation(float*p,int degreeP){
    float *newP=newArrayFloat(degreeP+1);
    for(int i=0;i<=degreeP;i++){
        newP[i]=p[i]*-1;
    }
    return newP;
}
/* ********************************* utilitaire pour strassen ****************************************/