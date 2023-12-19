#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* multiply(char* num1, char* num2)
{
    int la,lb,lc;
    int a[10]={0};
    int b[10]={0};
    int c[11]={0};
    la=strlen(num1);
    lb=strlen(num2);
    for(int i=0;i<la;i++)
    {
        a[la-i-1]=num1[i]-'0';
    }
    for(int i=0;i<lb;i++)
    {
        b[lb-i-1]=num2[i]-'0';
    }
    lc=la+lb;
    for(int i=0;i<la;i++)
    {
        for(int j=0;j<lb;j++)
        {
            c[i+j]+=a[i]*b[j];
            c[i+j+1]+=c[i+j]/10;
            c[i+j]%=10;
        }
    }
    while(c[lc]==0&&lc>0)lc--;
    char *re=(char *)malloc(sizeof(char)*(lc+2));
    for(int i=lc;i>=0;i--){
        re[lc-i]=c[i]+'0';
    }
    re[lc+1]=0;
    return re;
}
int main(){
	char num1[102];
    char num2[102];
    scanf("%s", num1);
    scanf("%s", num2);
    char* num = multiply(num1, num2);
    printf("%s", num);
    free(num);
	return 0;
}
