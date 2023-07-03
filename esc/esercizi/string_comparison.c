#include <stdio.h>

/*
 * Definire una funzione ricorsiva che confronti
 * albeticamente due stringhe. La funzione prende
 * le stringhe come argomento e restituisce -1 se
 * la prima è minore della seconda, 0 se sono uguali,
 * 1 se la seconda è minore della prima. 
 * Ad esempio: ciao < dado; ciao > cia; ciao = ciao
 * Le due stringhe sono lette da tastiera nel main. 
 * Se le stringhe in input sono "ciao", "hello", si
 * stampa:  
   ciao < hello

 * In caso di dubbi sulla definizione di confronto
 * alfabetico tra due caratteri, fate riferimento al
 * risultato del confronto dei valori numerici
 * associati ai caratteri stessi, ovvero usate 
 * semplicemente 'a' < 'b' (vero), 'A'<'a' ecc... 
 * 
 */

int confronta_stringhe(char *s1, char *s2, int somma_stringa_1, int somma_stringa_2);

int main(void)
{

  char a[50];
  char b[50];
  printf("Inserire due stringhe\n");
  scanf("%s\n%s", a, b);

  printf("%s %c %s\n", a, 61 + confronta_stringhe(a, b, 0, 0), b);
  //valori numerici dei caratteri: 60(<), 61(=), 62(>)
}
int confronta_stringhe(char *s1, char *s2, int somma_stringa_1, int somma_stringa_2)
{
  if (*s1 == '\0' && *s2 == '\0')
  {
    if (somma_stringa_1 == somma_stringa_2)
    {
      return 0;
    }

    return somma_stringa_1 < somma_stringa_2 ? -1 : 1;
  }

  if (*s1 != '\0')
  {
    s1 += 1;
    somma_stringa_1 += (int)*s1;
    printf("somma1: %d\n", somma_stringa_1);
  }

  if (*s2 != '\0')
  {
    s2 += 1;
    somma_stringa_2 += (int)*s2;
    printf("somma2: %d\n", somma_stringa_2);
  }

  return confronta_stringhe(s1, s2, somma_stringa_1, somma_stringa_2);
}
