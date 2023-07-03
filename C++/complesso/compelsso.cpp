#include <iostream>
#include "complesso.h"
#include <cmath>

class complesso
{
private:
    double re, im;

public:
    void inizializza(double, double);
    double reale();
    double immaginario();
};

void complesso::inizializza(double r, double i)
{
    re = r;
    im = i;
}

double complesso::reale()
{
    return re;
}
double complesso::immaginario()
{
    return im;
}
comp inizialiizzaComp(double re, double im)
{
    comp x;
    x.re = re;
    x.im = im;
    return x;
}

double reale(comp x)
{
    return x.re;
}

double immag(comp x)
{
    return x.im;
}

comp somma(comp x, comp y)
{
    comp z;
    z.re = x.re + y.re;
    z.im = x.im + y.im;
    return z;
}

int main()
{
    comp z1;
    comp x1 = inizialiizzaComp(0.3, 3.1);
    comp y1 = inizialiizzaComp(3, 6.3);
    z1 = somma(x1, y1);

    //dichiarazione basso livello interna ADT
    comp x2 = {0.3, 3.1}, y2 = {3, 6.3};
    comp z2;
    z2.re = x2.re + y2.re;
    z2.im = x2.im + y2.im;

    std::cout << "z1 => " << reale(z1) << ", " << immag(z1) << "\n";
}