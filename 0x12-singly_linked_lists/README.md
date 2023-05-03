Singly Linked Lists
This project involves the implementation of a singly linked list data structure in C.

Description
A singly linked list is a linear data structure where each element is a separate object with a data part and a reference to the next element. The last element has a reference to NULL. The entry point into a linked list is called the head of the list.

In this project, we will implement several functions to manipulate a singly linked list, including functions to add elements to the list, remove elements from the list, and print the elements of the list.

Files
lists.h: Header file containing the definition of the list_t structure and the prototypes of the functions.
0-print_list.c: Function that prints all the elements of a list_t list.
1-list_len.c: Function that returns the number of elements in a list_t list.
2-add_node.c: Function that adds a new node at the beginning of a list_t list.
3-add_node_end.c: Function that adds a new node at the end of a list_t list.
4-free_list.c: Function that frees a list_t list.
Usage
To use the singly linked list data structure and its associated functions, include the lists.h header file in your source code and compile your code with the source files listed above.

#include "lists.h"

int main(void)
{
    list_t *head = NULL;

    /* Add elements to the list */
    add_node_end(&head, "Hello");
    add_node_end(&head, "World");

    /* Print the elements of the list */
    print_list(head);

    /* Free the list */
    free_list(head);

    return (0);
}