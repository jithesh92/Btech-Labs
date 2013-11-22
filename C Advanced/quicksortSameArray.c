#include <stdio.h>
#define LENGTH 9999999 

void exchange(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *A, int p, int r) {
	int x = A[r];
	int i = p - 1, j;
	for(j = p; j <= r-1; j++) {
		if(A[j] <= x) {
			i++;
			exchange(&A[i], &A[j]);
		}
	}
	exchange(&A[i+1], &A[r]);
	return i+1;
}

void quick_sort(int *A, int p, int r) {
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
	}
}

int main()
{
	int A[LENGTH+1];
	int i;
	for (i = 1; i <= LENGTH; i += 1)
		scanf("%d", &A[i]);

	//printf("\nInitial array: ");
	/*for (i = 1; i <= LENGTH; i++)
		printf("%d ", A[i]);*/

	quick_sort(A, 1, LENGTH);

	printf("\nFinal array  :\n");
	for (i = 1; i <= LENGTH; i++)
		printf("%d\n", A[i]);

	printf("\n");

	return 0;
}
