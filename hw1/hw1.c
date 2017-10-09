#include <stdio.h>

int fact(int);
int main()
{
	int n=0;
	int k=0;
	scanf("%d",&n);
	scanf("%d",&k);
//	printf("combine(n,k)");
//	printf("%d\n",fact(5));
	printf("%d\n",fact(n)/(fact(k)*(fact(n-k))));
}

int fact(int f){
	if(f==0)
		return 1;
	return(f*fact(f-1));
}
