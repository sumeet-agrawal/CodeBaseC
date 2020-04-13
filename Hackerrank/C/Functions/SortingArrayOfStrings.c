#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b,a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int ar[26]={0},br[26]={0};
    int ca = 0,cb = 0;
    for(int i = 0;a[i]!='\0';i++){
        if(!ar[a[i]-'a']){
            ar[a[i]-'a']++;
            ca++;
        }
    }
    for(int i = 0;b[i]!='\0';i++){
        if(!br[b[i]-'a']){
            br[b[i]-'a']++;
            cb++;
        }
    }
    if(ca<cb)   return -1;
    else if(ca>cb)  return 1;
    return lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int diff = strlen(a) - strlen(b);
    return diff ? diff : lexicographic_sort(a,b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i =0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if(cmp_func(arr[j+1],arr[j]) < 0){
                char *temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
