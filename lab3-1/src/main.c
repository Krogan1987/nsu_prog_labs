#include <stdlib.h>
#include <stdio.h>

typedef int key;

static void quick_sort (key a[], int l, int r) {
	int i=0;
	i=l;
	int j=0;
	j=r;
	key x=0;
	x=a[(l+r)/2];
	key w=0;
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
	if (l<j) quick_sort (a, l, j);
	if (i<r) quick_sort (a, i, r);
}

int main(void) {
	int N=0;
	scanf("%d", &N);
	int *arr=NULL;
	arr=malloc (N*sizeof *arr);
	if (arr==NULL) exit (1); 
	int i=0;
	for(i=0; i<N; ++i) 
		scanf("%d", &arr[i]);
	quick_sort (arr, 0, N-1);
	for(i=0; i<N; ++i) 
		printf("%d ", arr[i]);
	free(arr);
	return 0;
}
