
#include <stdio.h>
#include <stdlib.h>

int *make_array(int n){
    int *p = malloc(n * sizeof(int));
    for(int i =0; i < n; i++)p[i] = i;
    return p; // valid, heap outlives the function.. so cool
}

int main(){
    int n = 10;
    int *a = malloc(n * sizeof(int));
    if(a == NULL) return 1;
    for(int i = 0; i < n; i++){ 
        a[i] = i*i;
        printf("%d\n",a[i]);
    }
    free(a); 
    a = NULL; // makes the variable not point anywhere
    //allocate then free

    //heap memory indexes exactly like a stack array
    //however it needs to be freed up at the end
     
    int *b = a; // same block, two names
    int *c = malloc(n * sizeof(int));
    memcpy(c,a,n * sizeof(int)); // real copy
    a[0] = 999; // notice, b[0] is 999, c[0] is not


    //what matters to me, 2D flat matrix!
    int rows = 3, cols = 4;
    float *m = malloc(rows * cols * sizeof(float));
    for(int i = 0; i < rows; i++){
        for(int j =0; j < cols; j++){
            m[i * cols + j] = i + j;
            // i * cols skips past i complete rows, + j walks j into current row


        }
    }
    free(m);

    int *a = calloc(n, sizeof(int));
    // two differences from malloc, takes count and size as seperate arguments, zeros the memory
    //malloc gives you whatever was in the block before

    //needed when you want a zeroed buffer

    //realloc - resize an exisitng allocation 
    int new_n = 15;
    int *tmp = realloc(a, new_n * sizeof(int));
    if(tmp == NULL) printf("valid"); // still valid
    a = tmp;
    return 0;


    // Example to analyze

    int *p = malloc(sizeof *p);  
    *p = 7;
    int *q = p;
    p = NULL;
}