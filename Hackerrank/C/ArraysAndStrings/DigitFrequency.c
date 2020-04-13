#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char ch[1000];
    scanf("%s",ch);
    int arr[10] = {0};
    for(int i =0;i<strlen(ch);i++){
        if(ch[i]<='9' && ch[i]>= '0'){
            arr[ch[i]-'0']++;
        }
    } 
    for(int i=0;i<=9;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
