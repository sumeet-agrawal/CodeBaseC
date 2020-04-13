#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
      int arr[2000][2000]= {0};
    for(int x=0;x<n;x++){
    for(int i =x;i<(2*n)-1-x;i++){
        for(int j=x;j<(2*n)-1-x;j++){
            arr[i][j] = n-x;
        }
    }
    }
    for(int i =0;i<(2*n)-1;i++){
        for(int j = 0;j<(2*n)-1;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
