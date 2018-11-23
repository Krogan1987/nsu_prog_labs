#include <stdlib.h>
#include <stdio.h>
typedef int key;
void Sift (key a[], int i, int n) {
	int l, r, k;
	key t;
	i++;
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
void heap_sort (key a[], int N) {
	int i;
	key t;
	for (i=N/2; i>=0; i--)
		Sift (a, i, N);
	for (i=N-1; i>0; i--) {
		t=a[0];
		a[0]=a[i];
		a[i]=t;
		Sift (a, 0, i);
	}
}
int main(void) {
	int i, N;
	scanf("%d", &N);
	int *arr=NULL;
	arr=(int*) malloc (N*sizeof(int));
	for(i=0; i<N; ++i) 
		scanf("%d", &arr[i]);
	heap_sort (arr, N);
	for(i=0; i<N; ++i) 
		printf("%d ", arr[i]);
	free(arr);
	return EXIT_SUCCESS;
}
