#include "gauss.h"
#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	if(mat->c!=mat->r)
		return 1;
	int n=mat->c;
	double q;
	if(b->r != n){
		return 2;
	}
	for(int k=0;k<n-1;k++){
		for(int w=k+1;w<n;w++){
			if(mat->data[k][k]==0)
				return 1;
		        q=mat->data[w][k]/mat->data[k][k];
			for(int i=0;i<n;i++)
				mat->data[w][i]-=q*mat->data[k][i];
			b->data[w][0]-=q*b->data[k][0];
		}
	}
	return 0;
}

