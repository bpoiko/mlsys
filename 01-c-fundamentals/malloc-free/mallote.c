#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *make_array(int n){
    int *p = malloc(n * sizeof(int));
    if(p == NULL){
        free(p);
        return NULL;
    }
    for(int i =0; i < n; i++)p[i] = i;
    return p; // valid, heap outlives the function.. so cool
}

int main(void){
    int *p = malloc(sizeof *p);
    if(p == NULL){
        free(p);
        return 1;
    }
    *p = 7;
    int *q = p;
    p = NULL;
    printf("%d", *q);
    free(q);
    q = NULL;
    int n = 10;
    int *a = malloc(n * sizeof(int));
    if(a == NULL) return 1;
    for(int i = 0; i < n; i++){
        a[i] = i*i;
        printf("%d\n",a[i]);
    }



    //heap memory indexes exactly like a stack array
    //however it needs to be freed up at the end

    int *b = a; // same block, two names
    int *c = malloc(n * sizeof(int));
    if(c == NULL){
        free(a);
        return 1;
    }
    memcpy(c,a,n * sizeof(int)); // real copy
    a[0] = 999; // notice, b[0] is 999, c[0] is not
    printf("%d\n",b[0]);
    printf("%d\n", c[0]);
    free(a);
    a = NULL;
    free(c);
    c = NULL;


    //what matters to me, 2D flat matrix!
    int rows = 3, cols = 4;
    float *m = malloc(rows * cols * sizeof(float));
    if(m == NULL){
        free(m);
        return 1;
    }
    for(int i = 0; i < rows; i++){
        for(int j =0; j < cols; j++){
            m[i * cols + j] = i + j;
            // i * cols skips past i complete rows, + j walks j into current row


        }
    }
    free(m);

    a = calloc(n,sizeof(int));
    if( a == NULL) return 1;

    for(int i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }

    //realloc - resize an exisitng allocation
    int new_n = 15;
    int *tmp = realloc(a, new_n * sizeof(int));
    if(tmp == NULL){
        free(a);
        return 1;
    }
    a = tmp;
    free(a);
    return 0;

}
