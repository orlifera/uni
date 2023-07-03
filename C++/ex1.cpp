/*Creare una classe Lampadina per rappresentare le lampadine che sono
caratterizzate dalla propria potenza e dal fatto che emanino luce calda o
fredda. Creare una classe lampadario in cui sono presenti tre lampadine tutte
con la medesima potenza e con lo stesso tipo di luce. Far sì che si possa
sostituire una lampadina di un lampadario con un’altra (anche con
caratteristiche diverse). Creare un lampadario con lampadine con luce fredda e
45 watt di potenza, poi sostituire la lampadina 1 con un’ulteriore lampadina con
luce calda e potenza scelta dall’utente, infine dire la potenza totale del
lampadario.*/

#include <iostream>
#define DIM 3

class Lampadina
{
private:
    int potenza;
    bool luceFredda; // TRUE == FREDDA FALSE == CALDA

public:
    Lampadina(int potenza = 45, bool luceFredda = true);
};

Lampadina::Lampadina(int potenza, bool luceFredda){};

class Lampadario
{
private:
    Lampadina lamp[DIM];

public:
    Lampadario(int = 0, bool = true);
    void cambiaLamp(int pos, Lampadina lamp);
};

void Lampadario::cambiaLamp(int pos, Lampadina lamp)
{
    this->lamp[pos] = lamp;
}

int main()
{
    Lampadario lampadario(45, true);
    lampadario.cambiaLamp(3, );
}
