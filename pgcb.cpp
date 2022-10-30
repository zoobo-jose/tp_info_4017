#include "tp1.hpp"
/* notre classe pgcb pour trouver le plus grand carree blanc*/
class Pgcb
{
public:
    /*  matrice carree de 1 et de 0
        image[x,y] est le pixel de ligne x et de colonne y
        si image[x,y]=0 , le pixel est noir
        si image[x,y]=1 , le pixel est blanc
    */
    int *image;
    /* dimension de notre matrice image*/
    int n = 0;
    /* tableau contenant les tailles des plus grand carrees blanc*/
    int *pgcb;
    Pgcb(int *image, int n)
    {
        this->image = image;
        this->n = n;
        this->pgcb = newArrayInt(n * n);
    }
    /*changer la valeur dun element de pgcb*/
    void setElePgcb(int i, int j, float val)
    {
        int index = this->n * i + j;
        this->pgcb[index] = val;
    }
    /*obtenir la valeur dun element de pgcb*/
    int getElePgcb(int i, int j)
    {
        int index = this->n * i + j;
        return this->pgcb[index];
    }
    /*obtenir la valeur d'un pixel de l'image*/
    int getPixelImage(int i, int j)
    {
        int index = this->n * i + j;
        return this->image[index];
    }
    /* retourne si le pixel de l'image est blanc*/
    bool isWhite(int i, int j)
    {
        return this->getPixelImage(i, j) == 1;
    }
    /* retourne si le pixel de l'image est noir*/
    bool isBlack(int i, int j)
    {
        return this->getPixelImage(i, j) == 0;
    }
    /* retourne le minimum entre 3 entier*/
    int min(int a, int b, int c)
    {
        int min = a;
        if (b < min)
        {
            min = b;
        }
        if (c < min)
        {
            min = c;
        }
        return min;
    }
    /* algorithme du plus grand carree blanc*/
    int searchPgcb()
    {
        for (int x = 0; x < this->n; x++)
        {
            for (int y = 0; y < this->n; y++)
            {
                if (this->isBlack(x, y))
                {
                    this->setElePgcb(x, y, 0);
                }
                else
                {
                    if (x == 0 || y == 0)
                    {
                        this->setElePgcb(x, y, 1);
                    }
                    else
                    {
                        int a= this->getElePgcb(x,y-1);
                        int b= this->getElePgcb(x-1,y);
                        int c= this->getElePgcb(x-1,y-1);
                        this->setElePgcb(x, y, 1+this->min(a,b,c));
                    }
                }
            }
        }
        return this->getElePgcb(this->n-1,this->n-1);
    }
};

void test(void)
{
    int *image = readArrayIntFromFile("data/imagePgcb.txt");
    int n = sqrt(countLengthArrayIntFromFile("data/imagePgcb.txt"));
    Pgcb a = Pgcb(image, n);
    std::cout << " pgcb :" << a.searchPgcb() << "\n";
}