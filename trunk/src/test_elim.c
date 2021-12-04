#include "gauss.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>

int isCorrect(Matrix *a){
	int n=a->r;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a->data[i][j]!=0.0)
				return 1;
		}
	}
	return 0;
}

int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);

	res = eliminate(A,b);
	if(res!=0){
		fprintf(stderr,"Blad Wprowadzonych danych\n");
		return 1;
	}
	printToScreen(A);
	int corr=isCorrect(A);
	if(corr==1){
		fprintf(stderr,"Algorytm dziala blednie!\n");
		return 1;
	}
	else{
		fprintf(stderr, "Algorytm dziala poprawnie\n");
		return 0;
	}
	return 0;
}
