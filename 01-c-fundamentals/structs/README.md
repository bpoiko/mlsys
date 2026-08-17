# Structs

**Goal:** Group related data into custom types, pass them around efficiently, and understand memory layout (padding/alignment).

## Concepts
- [ ] Declaring a `struct` and accessing members with `.`
- [ ] Accessing members through a pointer with `->`
- [ ] `typedef` to give a struct a clean name
- [ ] Pass by value (copies whole struct) vs pass by pointer (cheap)
- [ ] Struct padding and alignment — why `sizeof` is bigger than the sum of fields
- [ ] Reordering fields to shrink a struct
- [ ] Nested structs and arrays of structs
- [ ] Structs as the building block for linked lists / trees

## Exercises
- [ ] Define a `Point {int x, y;}` and a function that takes `Point*`
- [ ] Define a `Student` struct; make an array of them and print all
- [ ] Print `sizeof` a struct, then reorder fields and see it change
- [ ] Write a function returning a struct vs. filling one via pointer

## Resources
- Beej's Guide — ch. 11 (structs)
- K&R ch. 6
- "The Lost Art of Structure Packing": http://www.catb.org/esr/structure-packing/

## Done when
- [ ] I can predict a struct's `sizeof` given padding rules
- [ ] I know when to pass a struct by pointer vs. by value
