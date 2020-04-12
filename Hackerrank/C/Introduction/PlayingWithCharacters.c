#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch;
    char str[1000],ptr[1000];
    scanf("%c",&ch);
    scanf("%s",str);
    scanf(" %[^\n]*c",ptr);
   // printf("%c\n%s\n%s\n",ch,str,ptr);
   printf("%c\n%s\n",ch,str);
   printf("%s\n",ptr);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
