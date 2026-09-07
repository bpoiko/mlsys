# Notes — Dynamic Allocation

- Contract for `make_array` (inputs, output, ownership, failure):
- Owner and aliases after each statement:
- `calloc` guarantee and what it does not guarantee:
- Safe `realloc` state transition:
- Evidence from warnings/sanitizers/leak checker:


At line 13:
- n is just the number 10, no memory owned
- malloc creates a seperate **heap** allocation large enough for 10 int objects
- a stores the starting address of that allocation
- We can say a is the owner, as the program gives it responsiblity for eventually freeing the allocation; Ownership is more so a programming convetion not C's exclusive tracking

At 19-20:
- a is freed from the heap
- immediately after free, a still contains the old address 
- a = NULL simply changes the pointer value, doesn't free anything else 

Line 26:
- b copies the current value in a
- A is already null, b is now null
- b does not refer to a itself, both are independent

Line 27:
- c = malloc(...) creates another seperate allocation
- c contains the starting address
- c cannot point to the same thing as *a due to types being different 

Key notation:

- a stored address, type int *
- *a the actual value located at that address, if valid
- &a the address of the pointer variable itself, type int **

Dereferncing does not ask for an address, follows an address to access the object there. You can store an address in a pointer variable. Deref is invalid here because a == NULL, so theres no int object for *a to access

Prediction for p and q example:

- allocate enough memory for one int
- now say follow the address and change the value to 7
- make a int pointer value copy the address from p
- actual varible doesn't point to anything anymore
- q still holds the previously stored address in p
- no nothing had ended we haven't freed a single thing