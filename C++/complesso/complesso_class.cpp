

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