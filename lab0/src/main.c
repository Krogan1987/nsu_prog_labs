#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void)
{
	int i, b1, b2, C[12+1]={0}, A[12]={0}, B[12]={0}, NUM[48]={0};
	char s[12+1+1]={0}, NUM_1[48+1]={0}, NUM_2[12+1]={0}, x[16+1]="0123456789ABCDEF";
	scanf("%d%d%13s", &b1, &b2, s);
	int len=(int)strlen(s);
	if (b1<2 || b1>16 || b2<2 || b2>16) {
		printf("bad input");
		return 0;
	}
	for(i=0; i<len; ++i) {
		if (s[i]=='.') C[i]=-1;
		else if((int)s[i]-'0'<10) C[i]=(int)s[i]-'0';
		else if((int)s[i]>=65 && (int)s[i]<=70) C[i]=(int)s[i]-'7';
		else if((int)s[i]>=97 && (int)s[i]<=102) C[i]=(int)s[i]-'W';
		else {
			printf("bad input");
			return 0;
		}
		if(C[i]>=b1) {
			printf("bad input");
			return 0;
		}
	}
	if(C[0]==-1 || C[len-1]==-1) {
		printf("bad input");
		return 0;
	}
	int k=0, j=0, n=0;
	for(i=0; i<len; ++i) if(C[i]==-1) ++n;
	if(n>1) {
		printf("bad input");
		return 0;
	}
	for(i=0; i<len && C[i]!=-1; ++i) {
		A[i]=C[i];
		++k;
	}
	for(i=k+1; i<len && C[i]!=-1; ++i) {
		B[j]=C[i];
		++j;	
	}	
	long long num1=0;
	for(i=0; i<k; ++i) num1=num1*b1+A[i];
	double num2=0;
	for(i=j-1; i>=0; --i) num2=(double)num2/b1+B[i];
	num2=num2/b1;	
	i=0;
	long long dc=num1;	
	while(num1>0) {
		NUM[i]=num1%b2;
		num1/=b2;
		++i;
	}
	for(j=0; j<i/2; ++j) NUM[j] ^= NUM[i-1-j] ^= NUM[j] ^= NUM[i-1-j];
	for(j=0; j<i; ++j) 	NUM_1[j]=x[NUM[j]];
	double p;
	for(i=0; i<12 && num2!=0; ++i) {
		modf(num2*b2, &p);
		NUM[i]=(int)p;
		num2=num2*b2-NUM[i];
	}
	for(j=0; j<i; ++j) 	NUM_2[j]=x[NUM[j]];
	if(dc>0) printf("%s", NUM_1);
	else printf("%d", 0);
	int db=0;
	for(i=0; i<12; i++) if(B[i]>0) ++db;
	if(db>0) printf(".%s", NUM_2);
	return 0;
}
