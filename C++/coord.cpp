/*definire una classe point i cui oggetti rappresentano i punti nello spazio (x, y, z). Includere un 
costruttore di default, un costruttore a tre argomenti che inizializza un punto, selettori coordinate cartesiane 
un metodo negate() che trasforma un punto nel suo opposto una funzione norm() che restituisce la distanza dall'origine, 
l'overloading degli operatori somma e output. separare interfaccia e implementazione
*/
#include <iostream>
#include <cmath>
class Point
{
private:
    double _x, _y, _z;

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0); //convertitore implicito double => point
    double getX() const;
    double getY() const;
    double getZ() const;
    void negate();
    double norm() const;
};
std::ostream &operator<<(std::ostream &os, const Point &p);
Point operator+(const Point &p, const Point &q);

Point::Point(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

double Point::getX() const
{
    return _x;
}

double Point::getY() const
{
    return _y;
}

double Point::getZ() const
{
    return _z;
}

void Point::negate()
{
    _x *= -1.0;
    _y *= -1.0;
    _z *= -1.0;
}

double Point::norm() const
{
    return sqrt(_x * _x + _y * _y + _z * _z);
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    return os << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << ")";
}

Point operator+(const Point &p, const Point &q)
{
    return Point(p.getX() + q.getX(), p.getY() + q.getY(), p.getZ() + q.getZ());
}

int main()
{
    Point p1, p2(2.4), p3(2, 1.02, 5);
    std::cout << p1 + p2 << std::endl;
    p1.negate();
    std::cout << p1 << std::endl;
    std::cout << p3.norm() << std::endl;
}