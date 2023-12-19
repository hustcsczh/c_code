#include<stdio.h>
int fun(int n)
{
	int t=0;
	static int a=1;
	if(n==1){
		int a=3;t+=a; 
	}else{
		int a=4;t+=a;
	}
	printf("a=%d\n",a);
	printf("t=%d\n",t);
	return t+a++;
} 
unsigned long fac_sum(int n)
{
	unsigned long s=0,f=1;
    int i=1;
	do{
		f*=i++;
		s+=f;
	} while(i<=n);
	return s; 
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", fac_sum(n));
}