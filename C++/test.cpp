#include <iostream>
using namespace std;

class C
{
public:
    string s;
    C(string x = "1") : s(x) {}
    ~C() { cout << s << "~C "; }
};

C F(C p) { return p; }
C w("3");

class D
{
public:
    static C c;
};

C D::c("4");

int main()
{
    C x("5"), y("6");
    D d;
    y = F(x);
    cout << "UNO\n";
    C z = F(x);
    cout << "DUE\n";
}