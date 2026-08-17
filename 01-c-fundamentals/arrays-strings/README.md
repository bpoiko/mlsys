# Arrays & Strings

**Goal:** Understand how arrays sit in memory, how they relate to pointers, and how C strings work (they're just char arrays ending in `\0`).

## Concepts
- [ ] Arrays are contiguous memory; `a[i]` == `*(a + i)`
- [ ] Array-to-pointer "decay" when passed to functions
- [ ] Why `sizeof(array)` works locally but not after decay
- [ ] C strings = `char[]` terminated by `'\0'`
- [ ] The difference between `char s[] = "hi"` (mutable) and `char *s = "hi"` (read-only)
- [ ] Off-by-one / buffer overrun bugs and why they're dangerous
- [ ] `strlen`, `strcpy`, `strcmp` — and their safer `strn*` versions
- [ ] Multi-dimensional arrays and row-major layout

## Exercises
- [ ] Implement `my_strlen`, `my_strcmp`, `my_strcpy` from scratch
- [ ] Reverse a string in place
- [ ] Count words in a sentence
- [ ] Write a function to check if a string is a palindrome
- [ ] Loop over a 2D array and print it row-major, then column-major

## Resources
- Beej's Guide — Arrays (ch. 7) and Strings (ch. 8)
- Stanford "Essential C" PDF: http://cslibrary.stanford.edu/101/
- K&R ch. 1.9 (character arrays), ch. 5.5

## Done when
- [ ] My `my_strlen` matches the real `strlen` on several inputs
- [ ] I can explain why `a[i]` and `*(a+i)` are identical
