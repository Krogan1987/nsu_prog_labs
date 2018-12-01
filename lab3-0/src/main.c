#include <stdlib.h>
#include <stdio.h>

typedef int key;

static void sift (key a[], int i, int n) {
	i++;
	int l=0, r=0, k=0;
	key t=0;
	while ((l=2*i)<=n) {
		r=(l+1<=n)? l+1 : i;
		if ((a[i-1]>=a[l-1]) && (a[i-1]>=a[r-1]))
			return;
		k=(a[l-1]>=a[r-1]) ? l : r;
		t=a[i-1];
		a[i-1]=a[k-1];
		a[k-1]=t;
		i=k;
	}
}

static void heap_sort (key a[], int N) {
	int i=0;
	for (i=N/2; i>=0; i--)
		sift (a, i, N);
	key t=0;
	for (i=N-1; i>0; i--) {
		t=a[0];
		a[0]=a[i];
		a[i]=t;
		sift (a, 0, i);
	}
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
	heap_sort (arr, N);
	for(i=0; i<N; ++i) 
		printf("%d ", arr[i]);
	free(arr);
	return 0;
}
