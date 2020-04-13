#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int ansa =0, anso = 0, ansx =0;
  for(int i =1;i<=n;i++){
      for(int j = i+1;j<=n;j++){
          if((i&j) > ansa && (i&j) < k){
              ansa = i&j;
          }
          if((i|j) > anso && (i|j) < k){
              anso = i|j;
          }
          if((i^j) > ansx && (i^j) < k){
              ansx = i^j;
          }
      }
  }
  printf("%d\n%d\n%d\n", ansa, anso, ansx);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
