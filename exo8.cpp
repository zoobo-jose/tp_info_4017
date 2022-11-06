#include "exo8.hpp"
/*
    notre classe pour chercher la sous suite d'un tableau de nombres dont la somme
    est maximale
*/
class MaxSum
{
    public:
    int*t;//tableau d'entier relatifs
    int n=0;//taille de notre tableau d'entier
    /*
        tableau d'entier tel que s[i] contient la somme maximal d'une sous-suite des nombre
         de t compris entre 0 et i
    */
    int*s;
    int debut;// index a laquel commence notre sous suite
    int fin;// index ou se termine notre sous suite
    //constructeur
    MaxSum(int*t, int n){
        this->t=t;
        this->n=n;
        this->s=newArrayInt(n);
    }
    /*
        algorithme qui recherche notre somme maximal
    */
    void searchMaxSum(){
        s[0]=t[0];
        debut=fin=0;
        for(int i=0;i<this->n;i++){
            this->s[i]=this->s[i-1];
            // calcul et comparaison avec les sommes
            for(int j=0;j<=i;j++){
                    int sum=0;
                    // calcule de somme
                    for(int k=j;k<=i;k++){
                        sum+=this->t[k];
                    }
                    //comparaison
                    if(sum>this->s[i]){
                        this->s[i]=sum;
                        this->debut=j;
                        this->fin=i;
                    }
            }
        }
    }

};
void exo8(){
    int *tab = readArrayIntFromFile("data/exo8.txt");
    int n = countLengthArrayIntFromFile("data/exo8.txt");
    MaxSum a= MaxSum(tab,n);
    a.searchMaxSum();
    std::cout << "suite d'entiers " <<"\n ";
    displayArrayInt(tab,n);
    std::cout << " somme =" <<a.s[n-1]<<" ;\n";
    std::cout << " debut =" <<a.debut<<" ;\n";
    std::cout << " fin =" <<a.fin<<" ;\n";
}