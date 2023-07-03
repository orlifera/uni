#include <iostream>

using namespace std;
class orario
{
private:     //livello di accessibilità del campo dati.
    int sec; //si definisce la giornata in secondi == 24*60*(60-1). 60 - 1
             //perché quando 23.59 scatta si ha una nuova ora
public:
    orario();
    orario(int, int);
    orario(int, int, int);
    int Ore();
    int Min();
    int Sec();
};
orario::orario() //costruttore di default
{
    sec = 0;
}
orario::orario(int o, int m)
{
    if (o < 0 || o > 23 || m < 0 || m > 59)
    {
        sec = 0;
    }
    else
    {
        sec = o * 3600 + m * 60;
    }
}

orario::orario(int o, int m, int s)
{
    if (o < 0 || o > 23 || m < 0 || m > 59 || s < 0 || s > 59)
    {
        sec = 0;
    }
    else
    {
        sec = o * 3600 + m * 60 + s;
    }
}

int orario::Ore()
{
    return sec / 3600;
}
int orario::Min()
{
    return (sec / 60) % 60; //toglie le ore
}
int orario::Sec()
{
    return sec % 60;
}

int main()
{
    orario mezzanotte; //viene invocato il costruttore
    cout << mezzanotte.Ore() << endl;

    orario adesso_preciso(14, 25, 47);
    cout << adesso_preciso.Ore() << endl;
    //orario preciso = orario(14, 25, 47); equivalente a sopra, costruttore di copia

    orario t; //oggetto temporaneo anonimo senza l-value
    t = orario(12, 33, 25);
    cout << t.Ore() << ":" << t.Min() << ":" << t.Sec() << endl;

    orario *ptr = new orario;
    orario *ptr1 = new orario(14, 15);
    cout << ptr->Ore() << endl;
    cout << ptr1->Ore() << endl;
}