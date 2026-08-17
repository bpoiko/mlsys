#include <stdio.h>

void swap(int *a, int *b){
    int *temp = a;
    *a = *b;
    *b = temp;
    // pointer deference to swap two integers
}
int main(void){
    int age = 43;
    int *ptr = &age;
    // compile like this, gcc -Wextra -g <file>.c -o pointers.exe just like csc35
    // .<file>.exe
    // % must match the number of arguments after the screen
    printf("Value of age %d\n", age);
    printf("Address of age %p\n", (void *)&age);
    printf("ptr holds: %p\n",(void *) ptr);
    printf("value via ptr %d\n", *ptr); // <- derefencing
    

    //so when you want value, %d, address %p, (void *) is necessary with accessing those 

    *ptr = 44; // write through the pointer

    printf("age is now: %d", age); // changed without touching the variable age
    
    // null checks
    
    if(ptr != NULL ){
        // safe, pass *ptr to get value
    }else{
        // print.. null skipping dereference
    }

    // pointer arithmetic     
    // New address = Current Adress + (int value * sizeof(Type))

    // general info: char* 1 byte, int* 4 bytes, double* 8 bytes
    // so, ptr +1 increases char by 1 byte, int by 4 bytes, and double by 8 bytes\

    // there is four possible arithmetic operations in C

    // basis increment and decrement (++/--)
    int arr[3] = {10,20,30};
    int *ptr2 = arr; // points to the first element in arr
    
    ptr2++; // now points to the first element, address moved 4 bytes
    ptr2--; //now points to 

    printf("first element of arr is: %d",*ptr2);

    //other options, addition of an integer, + or +=

    int arre[5] = {1,2,3,4,5};

    int *ptr3 = arre;

    int *third_elem = ptr3 + 2; // moves forward 8 bytes

    // same thing can be done with subtraction

    // you can also subtract two pointers that point to the same array
    int arrd[5] = {10, 20, 30, 40, 50};
    int *p1 = &arrd[1];
    int *p2 = &arrd[4];

    char lmfao[4] = {'a','b','c','d'};

    //swap exercise
    
   // p, normal variable
   // *p pointer variable to something
   // &p address of p?


    return 0;
}