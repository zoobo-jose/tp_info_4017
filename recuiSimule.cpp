#include "recuiSimule.hpp"
#include <list>
#include <string.h>
class Point
{
public:
    float x = 0;
    float y = 0;
    Point(){};
    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    float distance(Point p)
    {
        return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
    }
};
class RecuitSimuleTSL
{
public:
    std::list<Point> s; // solution , ensemble de points
    float e = 0;        // energie de la solution
    float t = 100;      // la temperature
    float alpha = 0.95; // coeffiscient pour faire varier la temperature
    int kmax = 200;     // nombre d'iteration maximale
    RecuitSimuleTSL(){};
    RecuitSimuleTSL(std::list<Point> s, float t)
    {
        this->s = s;
        this->t = t;
    }
    /* genere un voisin de s par permutation de 2 element*/
    std::list<Point> voisin(std::list<Point> s)
    {
        int taille = s.size()-1;
        int i = round((double)(this->random() * taille));
        int j = round((double)(this->random() * taille));
        while (j==i)
        {
            j = round((double)(this->random() * taille));
        }
        std::list<Point> s2;
        int k = 0;
        Point b,c;
        for (Point m : s)
        {
            if (k == i)
            {
                b = m;
            }
            if (k == j)
            {
                c = m;
            }
            k++;
        }
        k = 0;
        for (Point m : s)
        {
            if (k == i)
            {
                s2.push_back(c);
            }
            else
            {
                if (k == j)
                {
                    s2.push_back(b);
                }
                else
                {
                    s2.push_back(m);
                }
            }
            k++;
        }
        return s2;
    }
    /* calcule l'energie de s*/
    float energie(std::list<Point> s){
        int k=0;
        float e=0;
        Point p,f;
        for (Point m : s)
        {
            if(k!=0){
                e+=p.distance(m);
            }else{
                f=m;
            }
             p=m;
            k++;
        }
        e+=f.distance(p);
        return e;
    }
    /* renvoie un nombre aleatoire entre 0 et 1*/
    float random()
    {
        return ((float)rand() / (RAND_MAX));
    }
    /* 
    renvoie la probabilite
        en: energie de la nouvelle solution
        e : energie de la solution precedente
        t: temperature du nouveau system
    */
    float proba(float en,float e,float t){
        float k= (e-en)/t;
        return (float)exp((double)k);
    }
    /* application du recuit simuler*/
    std::list<Point>  search(){
        //solution initial
         std::list<Point> s=this->s;
         float e=this->energie(s);
         float t=this->t;
        // meilleur solution global
         std::list<Point> sg=this->s;
         float eg=e;
         int k=0;
         while(k<this->kmax){
             std::list<Point> sn=this->voisin(s);
             float en=this->energie(sn);
             float r=this->random();
             if(en<e || r<this->proba(en,e,t)){
                s=sn;
                e=en;
                if(e<eg){
                    eg=e;
                    sg=s;
                    this->displayPath(s);
                }
             }
             t=t*this->alpha;
             k++;
         }
         this->displayPath(sg);
        return sg;
    }
    /* affiche un chemin*/
    void displayPath(std::list<Point> s){
        for (Point m : s)
        {
           std::cout <<m.x<<" "<<m.y<<" - ";
        }
        std::cout << "\n"<<" energie="<<this->energie(s)<< "\n";
    }

};

std::list<Point> getPointsFromFile(char*fileName){
    float *x = readArrayFloatFromFile(fileName);
    int n= countLengthArrayFloatFromFile(fileName);
    std::cout <<n<< "\n";
    std::list<Point> s;
    for(int i=0;i<n;i+=2){
        if(i+1<n){
            s.push_back(Point(x[i],x[i+1]));
        }
    }
    return s;
}

void recuiSimule()
{
    std::cout << "\n";
    std::list<Point> s={Point(9,0),Point(11,1),Point(4.4,2),Point(10,3),Point(1,4)};
    s=getPointsFromFile("data/recuiSimuleTSL/villes.txt");
    RecuitSimuleTSL A = RecuitSimuleTSL(s,1000);
    A.search();
}   