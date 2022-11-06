#include "exo9.hpp"
#include <list>
#include <string.h>

/* classe de notre dictionnaire*/
class Mot
{
public:
    char *val;
    Mot(){};
    Mot(char *val)
    {
        this->val = val;
    };
};

class Dictionnaire
{
public:
    std::list<Mot> mots; // tableau de mots
    int n = 0;           // nomnbres de mots dans le dictionnaire
    Dictionnaire(){};
    Dictionnaire(char *fileName)
    {
        this->load(fileName);
    }
    /* charge des mots depuis un fichier*/
    void load(char *fileName)
    {
        std::ifstream fin(fileName);
        char *val;
        this->n = 0;
        while (fin)
        {
            val = newString(10);
            fin >> val;
            this->mots.push_back(Mot(val));
            this->n++;
        }
        fin.close();
    }
    void display()
    {
        for (Mot m : this->mots)
        {
            std::cout << m.val
                      << "\n";
        }
    }
    bool exist(char *mot)
    {
        for (Mot m : this->mots)
        {
            if (strcmp(mot, m.val) == 0)
            {
                return true;
            }
        }
        return false;
    }
};
/*
    notre classe pour connaitre si une suite de 
    caracteres est une phrase correct
*/
class CorrectPhrase
{
public:
    char*t;// notre suite de caracteres
    int n=0;// taille de notre chaine
    Dictionnaire dict;// notre dictionnaire
    bool*f;

    bool iscorrectPhrase(){
        this->n=strlen(this->t);
        this->f=newArrayBool(this->n*this->n);
        // par taille
        for(int j =0;j<this->n;j++){
            for(int i =0;i<=this->n-1-j;i++){
                bool val=this->dict.exist(this->getSubString(i,i+j));
                this->setF(i,i+j,val);
                int k=i;
                while(!this->getF(i,i+j)&&k<i+j){
                    bool val= this->getF(i,k)&&this->getF(k+1,i+j);
                    this->setF(i,i+j,val);
                    k++;
                }
            }
        }
        
        return this->getF(0,this->n-1);
    }
    /* renvoie la sous chaine de t allant de i a j*/
    char* getSubString(int i,int j){
        char*m=newString(j-i+1);
        strncpy(m,&this->t[i],j-i+1);
        return m;
    }
    void setF(int i,int j,bool val){
        int index=i*this->n+j;
        this->f[index]=val;
    }
    bool getF(int i,int j){
        int index=i*this->n+j;
        return this->f[index];
    }
};
void exo9()
{
    Dictionnaire dico = Dictionnaire();
    dico.load("data/exo9/dictionnaire.txt");
    CorrectPhrase correct= CorrectPhrase();
    correct.dict=dico;
    correct.t=newString(10);
    std::ifstream fin("data/exo9/mot.txt");
    fin >> correct.t;
    fin.close();
    if( correct.iscorrectPhrase()){
        std::cout<<correct.t<< " est une phrase correct"<< "\n";
    }else{
        std::cout<<correct.t<< "n'est pas une phrase correct "<< "\n";
    }
    // std::cout << correct.getSubString(0,4)<< "\n";
    // Mot a[10];
}