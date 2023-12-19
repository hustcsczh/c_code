
#include<stdio.h>
#include<string.h>//删除子串
#define SIZE 50
void copy(char* a, char* b, int len2);
int main()
{
	char str[SIZE] = { 0 };
	char substr[SIZE] = { 0 };
	char* p = str;
	int i = 0;

	while ((str[i++] = getchar()) != '\n');
	str[i-1] = '\0';
	gets(substr);
	int len2 = strlen(substr);
	int len1 = strlen(str);
	char cmp[SIZE] = { 0 };
	int flag = 0;
	for (int i = 0; i < len1 - len2; i++)
    {
		copy(p, cmp, len2);
		if (!strcmp(cmp, substr)) {
			flag = 1;
			char* p1, *p2;
			for (p1 = p,p2 = p + len2; *p2 != '\0';p2++) {
				*p1++ = *p2;
			}
			*p1 = '\0';
            p--;
		}
		p++;
	}
    puts(str);
    printf("%d", flag);
	return 0;
}

void copy(char *a, char* b, int len2)
{
	for (int i = 0; i < len2; i++)
		*b++ = *a++;
}