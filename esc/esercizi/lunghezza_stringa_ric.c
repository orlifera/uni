#include <stdio.h>

/*
 * Scrivere una funzione ricorsiva che calcoli la 
 * lunghezza di una stringa. 
 * Scegliete voi il nome ed il prototipo della 
 * funzione. 
 * Nel main leggete da tastiera la stringa di cui
 * calcolar la lunghezza. 
 * Ad esempio se la stringa in input è "ciao", viene
 * stampato:
   4

 */

int lunghezza(int lunghezza_s, char *s);
void lunghezzaPunt(int *lunghezza, char *s);

int main(void)
{

  char s[100]; //lunghezza massima stringa in input
  scanf("%s", s);

  int lunghezza_s = 0;

  //lunghezza_s = lunghezza(lunghezza_s, s);
  lunghezzaPunt(&lunghezza_s, s); //indirizzo di un valore == puntatore
  printf("%d\n", lunghezza_s);
}

int lunghezza(int lunghezza_s, char *s) //puntatore perché passo la stringa che è array di caratteri
{
  //caso base

  if (*s == '\0') //valore dentro puntatore == '\0'
  {
    return lunghezza_s;
  }

  return lunghezza(lunghezza_s + 1, s + 1);
}

void lunghezzaPunt(int *lunghezza, char *s)
{
  if (*s == '\0')
  {
    return;
  }
  lunghezzaPunt(*lunghezza + 1, s + 1);
}
