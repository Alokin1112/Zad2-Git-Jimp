#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */

int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
        if (mat->r!=mat->c || b->r!=mat->r || b->c!=1){
                return 2;
        }
        int w;
        int k;
        for (w = 0; w < mat->r ; w++){
                if (mat->data[w][w] == 0 ){
                        return 1;
                }
        }
        double sum;
        for (w = mat->r -1; w>=0 ; w--){
                sum = 0;
                for (k = w + 1; k < mat->r; k++){
                        sum += mat->data[w][k] * b->data[k][0];
                }
                b->data[w][0] = (b->data[w][0] - sum)/mat->data[w][w];

				/**
				 * Tutaj należy umieścić właściwą implemntację.
				 */

				/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */

				int i;
				for (i =0; i < x->r; i++) {
								x->data[i][0] = b->data[i][0];
				}

				return 0;
}


