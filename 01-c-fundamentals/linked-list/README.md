# Linked List

**Goal:** Build a dynamic data structure from structs + pointers + malloc. This ties together everything in `01-c-fundamentals`.

> Do `pointers`, `structs`, and `malloc-free` first — a linked list is those three combined.

## Concepts
- [ ] Node = struct holding data + a `next` pointer to the same struct type
- [ ] The `head` pointer; an empty list is `head == NULL`
- [ ] Traversal with a `while (cur != NULL)` loop
- [ ] Insert at head (easy) vs. insert at tail (walk to end)
- [ ] Delete a node and free it without leaking or losing the rest
- [ ] Why deletion needs a "previous" pointer (or pointer-to-pointer)
- [ ] Freeing the entire list (walk + free, saving `next` first)

## Exercises
- [ ] `push_front(Node **head, int val)`
- [ ] `print_list(Node *head)`
- [ ] `int length(Node *head)`
- [ ] `append(Node **head, int val)` (insert at tail)
- [ ] `delete_value(Node **head, int val)`
- [ ] `free_list(Node **head)` — verify clean under Valgrind/ASan
- [ ] Stretch: reverse the list in place

## Resources
- Stanford "Linked List Basics" PDF: http://cslibrary.stanford.edu/103/
- Stanford "Linked List Problems" PDF (18 problems): http://cslibrary.stanford.edu/105/
- Beej's Guide — pointers + structs chapters

## Done when
- [ ] I can build, print, insert, delete, and fully free a list
- [ ] Valgrind/ASan reports zero leaks after `free_list`
