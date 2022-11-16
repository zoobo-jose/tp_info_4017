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

    }

};
void recuiSimule()
{
   
    std::cout << "\n";
    std::list<Point> s={Point(0,0),Point(0,1),Point(0,2),Point(0,3),Point(1,4)};
    RecuitSimuleTSL A = RecuitSimuleTSL(s,20);
    Point a=Point(0,0);
    Point b=Point(1,1);
    std::cout <<A.proba(10.5,1.11,8)<< "\n";
    std::cout << A.energie(s)<<"\n";

}   