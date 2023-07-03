#ifndef ARRAY_H
#define ARRAY_H

/*
    Funzioni di utilità per array.
 */


void copia_array(int A[], int B[], int dim);
    /*
        PRE dim è il numero di elementi di A e B.
        POST B è una copia di A
     */


void stampaArray(int A[], int dim);
    /*
     * PRE: A ha dimensione almeno dim
     * POST stampa a video gli elementi di A su 
     * una riga separati da spazi e poi va a capo. 
     */


#endif
