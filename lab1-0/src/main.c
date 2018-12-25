#include <stdio.h>
#include <string.h>					
									
int main (void) {	
	char a[18], b[256];			
	unsigned char q[18], s[256];
	fgets(a, 18, stdin);			
	fgets(b, 256, stdin);
	int N=0, M=0;										
	M=(int)strlen(a);
	N=(int)strlen(b);
	if (N<2) return 0;
	int i=0;  			
	i=M-2;
	int j=0, k=0;
	do {
		j=M-2;
		k=i;
		printf("%d ", k+1);
		int sum=0;
		while ((j>0) && (a[j]==b[k])) {
			k--;
			j--;
			printf("%d ", k+1);
			sum++;
		}
		if (j==0) i=i+M-1;	
		else {
			int x=3;
			while((x<=M) && (b[k+sum]!=a[M-x])) {
				x++;
				i++;
			}
			i=i+1;
		}
	} while (i<N);
	return 0;
}
