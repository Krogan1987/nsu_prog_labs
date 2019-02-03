#include <stdio.h>
#include <string.h>					
									
int main (void) {
	char a[18], buf[260];		
	fgets(a, 18, stdin);
	size_t nread;
	nread=fread(buf, 1, 256, stdin);
	buf[nread]=0;
	int N=0, M=0;										
	M=(int)strlen(a);
	N=(int)strlen(buf);	
	if (N<2) return 0;
	int count=0;
	do {
		int i=0;  			
		i=M-2;
		int j=0, k=0;
		do {
			j=M-2;
			k=i;
			printf("%d ", k+1+count);
			int sum=0;
			while ((j>0) && (a[j]==buf[k])) {
				k--;
				j--;
				printf("%d ", k+1+count);
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
		nread=fread(buf, 1, 256, stdin);
		buf[nread]=0;
		N=(int)strlen(buf);
		count+=256;
	} while (N>0);
	return 0;
}
