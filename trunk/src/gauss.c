#include "gauss.h"
#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
  * Zwraca 1 - macierz osobliwa - dzielenie przez 0
   */
  double
ABS (double a)
{
  if (a >= 0)
    return a;
  else
    return -a;
}

int
eliminate (Matrix * mat, Matrix * b)
{
  if (mat->c != mat->r)
    return 1;
  int n = mat->c;
  double q;
  if (b->r != n)
    {
      return 2;
    }
  int k, w, i;
  int maxInd;			//potrzebne
  for (k = 0; k < n - 1; k++)
    {
      //start
      maxInd = k;
      for (w = k + 1; w <= n; w++)
	if (ABS (mat->data[w][k]) > ABS (mat->data[maxInd][k]))
	  maxInd = w;
      if (maxInd != k)
	{
	  double *tmp;
	  tmp = mat->data[maxInd];
	  mat->data[maxInd] = mat->data[k];
	  mat->data[k] = tmp;
	  tmp = b->data[maxInd];
	  b->data[maxInd] = b->data[k];
	  b->data[k] = tmp;
	}			//koniec
      for (w = k + 1; w < n; w++)
	{
	  if (mat->data[k][k] == 0)
	    return 1;
	  q = mat->data[w][k] / mat->data[k][k];
	  for (i = 0; i < n; i++)
	    mat->data[w][i] -= q * mat->data[k][i];
	  b->data[w][0] -= q * b->data[k][0];
	}
    }
  return 0;
}
