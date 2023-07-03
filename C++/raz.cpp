#include <iostream>
#include <cmath>

class Raz
{
private:
    int num, den; //rappresentazione multiple, invariante di istanza: den != 0

public:
    Raz(int n = 0, int d = 1);
    Raz inverso() const;
    operator double() const; //const perché non faccio sideffect
    Raz operator++(int);     //postfisso, ritorna prima dell'incremento
    Raz &operator++();       //prefisso, ritorna dopo l'incremento
    static Raz unTerzo();
    Raz operator+(const Raz &) const;
    Raz operator*(const Raz &) const;
    bool operator==(const Raz &) const;
};

bool operator==(const Raz &, const Raz &);
std::ostream &operator<<(std::ostream &, const Raz &);

//Raz.cpp

Raz::Raz(int n, int d) : num(n), den(d == 0 ? 1 : d){};
Raz Raz::inverso() const
{
    return Raz(den, num);
};

Raz::operator double() const
{
    return static_cast<double>(num) / static_cast<double>(den);
};

Raz Raz::operator++(int)
{
    Raz r(*this);
    num += den;
    return r;
};
Raz &Raz::operator++()
{
    num += den;
    return *this;
};

Raz Raz::unTerzo()
{
    return Raz(1, 3);
};

Raz Raz::operator+(const Raz &r) const
{
    return Raz(num * r.den + r.num * den, den * r.den); //r1.num * r2.den + r2.num * r1.den, r1.den * r2.den inaccessibili
}

Raz Raz::operator*(const Raz &r) const
{
    return Raz(num * r.num, den * r.den);
};

bool Raz::operator==(const Raz &r) const
{
    return num * r.den == r.num * den;
};

std::ostream &operator<<(std::ostream &os, const Raz &r)
{
    return os << "il raz. come double e' = " << r.operator double();
};

int main()
{
}