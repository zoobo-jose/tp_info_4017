#include "tp1.hpp"

/* algorithme de karatsuba*/
float*karatsuba(float*p,float*q,int degreeP,int degreeQ,int e){
    indent(e);
    std::cout<<"-------------- karatsuba --"<<e<<"\n";
    indent(e);
    std::cout<<"== p"<<"\n";
    indent(e);
    displayArrayFloat(p,degreeP+1);
    indent(e);
    std::cout<<"== q"<<"\n";
    indent(e);
    displayArrayFloat(q,degreeQ+1);
    //cas de base
    if(degreeP<=1&&degreeQ<=1){
        float *newP=newArrayFloat(3);
        p=completer(p,degreeP,1);
        q=completer(q,degreeQ,1);
        newP[0]=p[0]*q[0];
        newP[1]=p[0]*q[1]+p[1]*q[0];
        newP[2]=p[1]*q[1];
        indent(e);
        std::cout<<"cas de base\n";
        indent(e);
         std::cout<<"fin -------------- karatsuba --"<<e<<"\n";
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

        indent(e);
         std::cout<<"---p1"<<"\n";
         indent(e);
         displayArrayFloat(p1,degreeLp+1);

        float*p2=firstPart(p,degree,degreeFp,degreeLp);

        indent(e);
        std::cout<<"---p2"<<"\n";
        indent(e);
         displayArrayFloat(p2,degreeFp+1);

        float*q1=lastPart(q,degree,degreeLp);

        indent(e);
        std::cout<<"---q1"<<"\n";
        indent(e);
        displayArrayFloat(q1,degreeLp+1);

        float*q2=firstPart(q,degree,degreeFp,degreeLp);

        indent(e);
        std::cout<<"---q2"<<"\n";
        indent(e);
        displayArrayFloat(q2,degreeFp+1);
        indent(e);
        std::cout<<"---p1 + p2"<<"\n";
        indent(e);
         displayArrayFloat(additionSameDegree(p1,p2,degreeLp,degreeFp),degreeFp+1);
        indent(e);
        std::cout<<"---q1 + q2"<<"\n";
        indent(e);
         displayArrayFloat(additionSameDegree(q1,q2,degreeLp,degreeFp),degreeFp+1);

        float*r1=karatsuba(p1,q1,degreeLp,degreeLp,e+1);

        indent(e);
         std::cout<<"---p1 X q1"<<"\n";
         indent(e);
         displayArrayFloat(r1,2*degreeLp+1);

        float*r2=karatsuba(p2,q2,degreeFp,degreeFp,e+1);

        indent(e);
         std::cout<<"---p2 X q2"<<"\n";
         indent(e);
         displayArrayFloat(r2,degree+1);

        float*r3=karatsuba(
            additionSameDegree(p1,p2,degreeLp,degreeFp),
            additionSameDegree(q1,q2,degreeLp,degreeFp),
            degreeFp,degreeFp,e+1
        );
        indent(e);
        std::cout<<"---(p1+p2) X (q1+q2)"<<"\n";
        indent(e);
        displayArrayFloat(r3,degree+1);

        float*somme=additionSameDegree(r3,negation(r1,degree),degree,degree);
        indent(e);
        std::cout<<"---somme1= p12Xq12-p1q1"<<"\n";
        indent(e);
        displayArrayFloat(somme,degree+1);
        somme=additionSameDegree(somme,negation(r2,degree),degree,degree);
         indent(e);
        std::cout<<"---somme :: r2"<<"\n";
        indent(e);
        displayArrayFloat(r2,degree+1);

        indent(e);
        std::cout<<"---somme2= p12Xq12-p2q2"<<"\n";
        indent(e);
        displayArrayFloat(somme,degree+1);

        float*resultat=addition(r2,somme,2*degree,2*(degree-degreeFp),2*degreeFp+degree-degreeFp,degree-degreeFp);
         std::cout<<"---result1 r2 et somme"<<2*degreeFp<<"\n";
        indent(e);
        displayArrayFloat(resultat,2*degree+1);

        indent(e);
        std::cout<<"-- degree = "<<degree<<"\n";
        indent(e);
        std::cout<<"fin -------------- karatsuba --"<<e<<"\n";
        return addition(resultat,r1,2*degree,degree-degreeFp,2*degreeLp,0);
        // return newArrayFloat(1);
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

float*addition(float*p,float*q,int degreeMaxP,int degreeMinP,int degreeMaxQ,int degreeMinQ){
    int min=degreeMinP;
    int max=degreeMaxP;
    if(min>degreeMinQ){min=degreeMinQ;}
    if(max<degreeMaxQ){max=degreeMaxQ;}
    float *newP=newArrayFloat(max-min+1);
    for(int i=0;i<=max-min;i++){
        int index=i+min;
        newP[i]=0;
        if(index>=degreeMinP && index<=degreeMaxP){
            newP[i]+=p[index-degreeMinP];
        }
        if(index>=degreeMinQ && index<=degreeMaxQ){
            newP[i]+=q[index-degreeMinQ];
        }
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