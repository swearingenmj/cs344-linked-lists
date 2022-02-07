#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/mman.h>
#include "llist.h"

void llist_insert_head(struct node **head, struct node *n) {
    // insert n at head of list
    n->next = *head;    // sets the next pointer of the new node to point to the current head of the list
    *head = n;  // change head pointer to point to the new node
}

struct node *llist_delete_head(struct node **head) {
    struct node *temp;

    // if the list is empty return NULL
    if (head == NULL || *head == NULL) {
        return NULL;
    }

    temp = *head; // store the head in a temp variable
    *head = (*head)->next; // have the head point to the next node
    return temp; // return the temp variable
}

void llist_insert_tail(struct node **head, struct node *n) {
    // find tail of list and insert n
    struct node* current = *head;

    if (current == NULL) {
        *head = n;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = n;
    }
}

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
    // allocate a new struct node with a
        // value of 3490 and a
        // nect of NULL
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;
    return node;
}

// void node_free(struct node *n) {
    // call for every node in the list


    // head will be set to NULL


// }

int main(void) { // int argc, char *argv[]) {

    // struct node *head = NULL;

    // struct node *n = node_alloc(10);
    // llist_insert_head(&head, n);
    
    // char *s = "16";

    // int x = atoi(s);

    // printf("%d\n", x * 2);  // 32
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