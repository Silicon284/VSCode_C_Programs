#include <stdio.h>
#include <stdlib.h>

struct list {
    struct list *prev;
    int data;
    struct list *next;
};

void add_entry (int); 
void add_node (void);
void print_node (void);

struct list *head   = NULL;
struct list *tail   = NULL;
struct list *one    = NULL;
struct list *two    = NULL;
struct list *three  = NULL;
struct list *four   = NULL;
struct list *five   = NULL;

struct list *new_node       = NULL;
struct list *previous_node  = NULL;

void add_entry (int value) {
    
    if ((head != NULL) && (tail != NULL)) {
        previous_node           = new_node;
        new_node                = malloc(sizeof(struct list));
        previous_node -> next   = new_node;
        new_node -> prev        = previous_node;
        new_node -> data        = value;
        new_node -> next        = NULL;
        tail                    = new_node;
    }

    if((head == NULL) && (tail == NULL)) {

        new_node            = malloc(sizeof(struct list));
        new_node -> prev    = NULL;
        new_node -> data    = value;
        new_node -> next    = NULL;
        head                = new_node;
        tail                = new_node;
    }

    printf ("Node Addition \t");
    printf ("Head: %x \r", (int) head);
    printf ("Tail: %x \n\r", (int) tail);
}

void add_node (void) {
    
    one     = malloc (sizeof (struct list));
    two     = malloc (sizeof (struct list));
    three   = malloc (sizeof (struct list));
    four    = malloc (sizeof (struct list));
    five    = malloc (sizeof (struct list));

    head = one;

    one -> prev = NULL;
    one -> data = 1;
    one -> next = two;

    two -> prev = one;
    two -> data = 2;
    two -> next = three;

    three -> prev = two;
    three -> data = 3;
    three -> next = four;

    four -> prev = three;
    four -> data = 4;
    four -> next = five;

    five -> prev = four;
    five -> data = 5;
    five -> next = NULL;

    tail = five;
}

void rem_node (void) {
    
}

void print_node (void) {

    struct list *l_temp = head;

    printf("Front printing \n\r");
    while (l_temp->next != NULL) {        
        printf("Data : %d \n\r", l_temp -> data);
        l_temp = l_temp -> next;
    }   
    printf("Data : %d \n\r", l_temp -> data);
    
    l_temp = tail;
    printf("Back printing \n\r");
    while (l_temp->prev != NULL) {    
        printf("Data : %d \n\r", l_temp -> data);
        l_temp = l_temp -> prev;
    }    
    printf("Data : %d \n\r", l_temp -> data);

}

void sortLL_acsend (struct list *temp_head) {

    struct list *l_temp_current = head;
    struct list *l_temp_next = temp_head -> next;
    struct list *l_temp_swap = NULL;
    
    while (l_temp_next != NULL) {
        if (l_temp_current > l_temp_next) {
            l_temp_swap     = l_temp_current;
            l_temp_current  = l_temp_next;
            l_temp_next     = l_temp_swap;
            l


        }
    }


}
int main (void) {

    //add_node();
    //print_node();

    add_entry(11);
    add_entry(20);
    add_entry(3);
    add_entry(44);
    add_entry(15);
    print_node();

    return 0;
}