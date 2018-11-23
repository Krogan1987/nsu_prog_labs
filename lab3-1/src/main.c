#include <stdlib.h>
#include <stdio.h>
typedef int key;
void qSort (key a[], int l, int r) {
	key x, w;
	int i, j;
	i=l;
	j=r;
	x=a[(l+r)/2];
	do {
		while (a[i]<x) i++;
		while (x<a[j]) j--;
		if (i<=j) {
			w=a[i];
			a[i]=a[j];
			a[j]=w;
			i++;
			j--;
		}
	} while (i<j);
	if (l<j) qSort (a, l, j);
	if (i<r) qSort (a, i, r);
}
int main(void) {
	int i, N;
	scanf("%d", &N);
	int *arr=NULL;
	arr=(int*) malloc (N*sizeof(int));
	for(i=0; i<N; ++i) 
		scanf("%d", &arr[i]);
	qSort (arr, 0, N-1);
	for(i=0; i<N; ++i) 
		printf("%d ", arr[i]);
	free(arr);
	return EXIT_SUCCESS;
}
