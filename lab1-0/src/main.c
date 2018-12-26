#include <stdio.h>
#include <string.h>					
									
int main (void) {	
	char a[18], buf[256];			
	fgets(a, 18, stdin);
	size_t nread;
	nread=fread(buf, 1, 255, stdin);
	buf[nread]=0;
	int N=0, M=0;										
	M=(int)strlen(a);
	N=(int)strlen(buf);
	if (N<2) return 0;
	int i=0;  			
	i=M-2;
	int j=0, k=0;
	do {
		j=M-2;
		k=i;
		printf("%d ", k+1);
		int sum=0;
		while ((j>0) && (a[j]==buf[k])) {
			k--;
			j--;
			printf("%d ", k+1);
			sum++;
		}
		if (j==0) i=i+M-1;	
		else {
			int x=3;
			while((x<=M) && (buf[k+sum]!=a[M-x])) {
				x++;
				i++;
			}
			i=i+1;
		}
	} while (i<N);
	return 0;
}
