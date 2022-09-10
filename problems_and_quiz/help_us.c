/******************************************************************************

Welcome Friend!
It seems like the implementation of strcmp in the c standard library has
been lost in my universe. 
Please help us to implement it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int strcmp_new(const char *str1, const char *str2) 
{
    while(*str1 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int main()
{
    const char *str1 = "";
    const char *str2 = "a"; 
    const char *str3 = "ab";
    const char *str4 = "abc";
    const char *str5 = "ab";
    // const char *nullstr1 = NULL;
    // const char *nullstr2 = NULL;

    // Segmentation fault
    // printf("strcmp(nullstr1, nullstr2) = %d\n", strcmp(nullstr1, nullstr2));
    // printf("strcmp(nullstr1, str1) = %d\n", strcmp(nullstr1, str1));

    printf("compare (\"%s\", \"%s\") strcmp: %d strcmp_new: %d\n", str1, str1, strcmp(str1, str1), strcmp_new(str1, str1));
    printf("compare (\"%s\", \"%s\") strcmp: %d strcmp_new: %d\n", str1, str2, strcmp(str1, str2), strcmp_new(str1, str2));
    printf("compare (\"%s\", \"%s\") strcmp: %d strcmp_new: %d\n", str2, str3, strcmp(str2, str3), strcmp_new(str2, str3));
    printf("compare (\"%s\", \"%s\") strcmp: %d strcmp_new: %d\n", str3, str2, strcmp(str3, str2), strcmp_new(str3, str2));
    printf("compare (\"%s\", \"%s\") strcmp: %d strcmp_new: %d\n", str4, str5, strcmp(str4, str5), strcmp_new(str4, str5));

    // Segmentation fault
    // printf("strcmp_new(nullstr1, nullstr2) = %d\n", strcmp_new(nullstr1, nullstr2));
    // printf("strcmp_new(nullstr1, str1) = %d\n", strcmp_new(nullstr1, str1));

    return 0;
}
