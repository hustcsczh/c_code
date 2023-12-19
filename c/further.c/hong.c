#include <stdio.h>

#define CHANGE 1

#ifdef CHANGE
    #if CHANGE == 1
        #define TRANSFORM(x) (x >= 'a' && x <= 'z' ? x - 'a' + 'A' : (x >= 'A' && x <= 'Z' ? x - 'A' + 'a' : x))
    #else
        #define TRANSFORM(x) (x)
    #endif


#else
    #define TRANSFORM(x) (x)
#endif

int main() 
{
    char str[100];
    gets(str);

    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", TRANSFORM(str[i]));
    }

    return 0;
}
