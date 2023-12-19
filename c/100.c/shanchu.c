#include<stdio.h>
#include<string.h>  //删除重复部分
void shanchu(char *s1, int j, int i,int len1);
int main()
{
	char s1[100]={"\0"};
    char s2[100] = {"\0"};
    gets(s2);
    gets(s1);
	int len1,len2;
	len1=strlen(s1);
	len2=strlen(s2);
	int i,j,k;
	int fl=1;
	int f;
	while(fl)
    {
		for(i=0; i<len1; i++)
		{
            fl=0;
			if(s1[i]==s2[0])
			{
				f=1;
				for(j=i,k=0; k<len2; j++,k++)
					if(s1[j]!=s2[k])
					{
						f=0;  
						break;
					}
				if(f)
				{
                    shanchu(s1, j, i,len1);
                    fl = 1;
                    break;  
				}
			}
			len1=strlen(s1);
		}
    }
	puts(s1);
	return 0; 
}

void shanchu(char* s1,int j,int i,int len1)
{
    for (; j < len1; j++, i++) 
        s1[i] = s1[j];
    for (; i < len1; i++) 
        s1[i] = '\0';
}



