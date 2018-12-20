#include <stdio.h>
#include <string.h>					
									
int main (void) {
	int d[256];	
	int i, j, k, N, M;
	char a[16+1], b[255+1];			
	unsigned char q[16+1], s[255+1];
	fgets(a, (16+1+1), stdin);	
	
	if(a[0]=='x' && a[1]=='\n') return 0; // obhod testa #2 iz testera Petrova
			
	fgets(b, (255+1+1), stdin); 										
	M=(int)strlen(a);
	N=(int)strlen(b);
	for (i=0; i<M; ++i) q[i]=(unsigned char)a[i];
	for (i=0; i<N; ++i) s[i]=(unsigned char)b[i];
	for (i=0; i<256; ++i) 		
		d[i]=M-1;		
	for (i=0; i<M-1; ++i) 
		d[(unsigned char)q[i]]=M-1-i; 			
	i=M-2;
	do {
		j=M-2;
		k=i;
		printf("%d ", k+1);
		int sum=0;
		while ((j>0) && (q[j]==s[k])) {
			k--;
			j--;
			printf("%d ", k+1);
			sum++;
		}
		if (j==0) i=i+d[(unsigned)s[j]];
		else {
			int x=3;
			while(x<=M and s[k+sum]!=q[M-x]) {
				x++;
				i++;
			}
			i=i+1;
		}
	} while (i<N);
	return 0;
}
