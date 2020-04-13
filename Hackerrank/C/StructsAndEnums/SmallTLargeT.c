#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

typedef struct node{
    float area;
    triangle* ptr;
} Node;

void sort_by_area(triangle* tr, int n) {
    Node *nd = (Node*)malloc(n*sizeof(Node));
    for(int i = 0;i<n;i++){
        float p = tr[i].a +tr[i].b+tr[i].c;
        p /= 2.0;
        nd[i].area = p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c);
        nd[i].area = sqrtf(nd[i].area);
        nd[i].ptr = &tr[i];
    }
    for(int j = 0;j<n-1;j++){
        for(int i =0;i<n-1-j;i++){
            if(nd[i].area>nd[i+1].area){
                triangle t = tr[i];
                tr[i] = tr[i+1];
                tr[i+1] = t;
                Node nod = nd[i];
                nd[i] = nd[i+1];
                nd[i+1] = nod;
            }
        }
    }
    
	/**
	* Sort an array a of the length n
	*/
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
