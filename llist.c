#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/mman.h>
#include "llist.h"

// void llist_insert_head(struct node **head, struct node *n) {
//     // TODO: code to insert at head
// }

// void node *llist_delete_head(struct node **head) {

// }

// void llist_insert_tail(struct node **head, struct node *n) {

// }

void llist_print(struct node *head) {
    struct node* p = head;
    while (p) {
        printf("%d -> ", p->value);
        p = p->next;
    }
    printf("NULL");
}

// void llist_free(struct node **head) {

// }

struct node *node_alloc(int value) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;
    return node;
}

// void node_free(struct node *n) {

// }

int main(int argc, char *argv[]) {

    struct node *head = NULL;

    struct node *n = node_alloc(10);
    llist_insert_head(&head, n);
    
    return 0;
}

# if 0
write command line parser
    make sure youre getting the right numbers with the right
    commands. 
    either parse the whole command into some structure first, 
    or you can just run list commands as you process argv
write node_alloc() to allocate a note with a given value
write node_free() to free the node
get llist_print() in place
    maybe test it by allocating a quick node to your head
    pointer and passing it in
write llist_insert_head() and get it working
followed by the other ones
    ih: insert the next number on the command line at the
        head of the list
    it: insert the next number on the command line at the
        tail fo the list
    dh: delete the node from the head of the list; does 
        nothing if the list is empty
    f: free the entire list
    p: print the list to standard output

head pointer will point directly to a linked list node, or
will be NULL indicating the list is empty
# endif