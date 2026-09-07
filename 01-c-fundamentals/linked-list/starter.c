#include <stddef.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int push_front(Node **head, int value) {
    /* TODO: return nonzero on allocation failure without changing the list. */
}

int append(Node **head, int value) {
    /* TODO: append while preserving the list on failure. */
}

int delete_value(Node **head, int value) {
    /* TODO: delete the first match and report whether one was found. */
}

void free_list(Node **head) {
    /* TODO: free every node and leave *head as NULL. */
}

int main(void) {
    /* TODO: exercise empty, singleton, head, middle, tail, and missing cases. */
}
