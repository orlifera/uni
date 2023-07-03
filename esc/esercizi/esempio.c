#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARDS 52
#define FACES 13

typedef struct //definisce la struct Card
{
    char *face;
    char *suit;
} Card;

void fillDeck(Card *const wDeck, const char *wFace[], const char *wSuit[]); //prototipi
void shuffle(Card *const wDeck);
void deal(const Card *const wDeck);

int main()
{
    Card deck[CARDS];
    const char *face[] = {"ace", "duece", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "Jack",
                          "Queen", "King"};

    const char *suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    srand(time(NULL));
    fillDeck(deck, face, suits);
    shuffle(deck);
    deal(deck);
}

void fillDeck(Card *const wDeck, const char *wFace[], const char *wSuit[])
{ // effettua un'iterazione attraverso wDeck48
    for (size_t i = 0; i < CARDS; ++i)
    {
        wDeck[i].face = wFace[i % FACES];
        wDeck[i].suit = wSuit[i / FACES];
    }
}
// mescola le carte55
void shuffle(Card *const wDeck)
{

    // effettua un'iterazione attraverso wDeck scambiando a caso le carte58
    for (size_t i = 0; i < CARDS; ++i)
    {
        size_t j = rand() % CARDS;
        Card temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}
// distribuisci le carte67
void deal(const Card *const wDeck)
{
    // effettua un'iterazione attraverso wDeck70
    for (size_t i = 0; i < CARDS; ++i)
    {
        printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? "  " : "\n");
    }
}
