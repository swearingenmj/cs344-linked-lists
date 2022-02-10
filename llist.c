#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "llist.h"

int main(int argc, char *argv[]) {

    struct node *head = NULL;

    // Test!!
    // llist_insert_head(&head, node_alloc(10));
    // llist_insert_head(&head, node_alloc(1));
    // llist_insert_head(&head, node_alloc(15));
    // llist_print(head);
    // llist_delete_head(&head);
    // llist_print(head);
    // llist_insert_tail(&head, node_alloc(100));
    // llist_print(head);
    // llist_free(&head);
    // llist_print(head);

    for (int i = 1; i < argc; i++) {

        if (strcmp(argv[i], "ih") == 0) {
            int x = atoi(argv[++i]);
            llist_insert_head(&head, node_alloc(x));
        } else if (strcmp(argv[i], "it") == 0) {
            int x = atoi(argv[++i]);
            llist_insert_tail(&head, node_alloc(x));
        } else if (strcmp(argv[i], "dh") == 0) {
            llist_delete_head(&head);
        } else if (strcmp(argv[i], "f") == 0) {
            llist_free(&head);
        } else if (strcmp(argv[i], "p") == 0) {
            llist_print(head);
        }
    }
}

    // ih: insert the next number on the command line at the
    //     head of the list
    // it: insert the next number on the command line at the
    //     tail fo the list
    // dh: delete the node from the head of the list; does 
    //     nothing if the list is empty
    // f: free the entire list
    // p: print the list to standard output

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
    while (p != NULL) {
        printf("%d", p->value);
        if (p->next != NULL) {
            printf(" -> ");
        } 
        p = p->next;
    }
    printf("\n");
}

void llist_free(struct node **head) {
    struct node *temp;
    // call node_free() for each node
    while (*head != NULL) {
        temp = *head;
        *head = temp->next;
        node_free(temp);
    }
}

struct node *node_alloc(int value) {
    // allocate a new struct node with a
        // value of 3490 and a
        // nect of NULL
    struct node* node = (struct node*) malloc(sizeof(struct node)); // allocate the node
    node->value = value; // set the new nodes value
    node->next = NULL; // set the new node's next struct to NULL
    return node;
}

void node_free(struct node *n) {
    // free node that was allocated
    free(n);
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