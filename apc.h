#ifndef APC_H
#define APC_H
#define FAILURE 0
#define SUCCESS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dlist {
    int data;
    struct Dlist* prev;
    struct Dlist* next;
} Dlist;

Dlist* create_node(int data);
void append(Dlist** head, Dlist** tail, int data);
void prepend(Dlist** head, Dlist** tail, int data);
void print_list(Dlist* head);
void free_list(Dlist* head);
Dlist* string_to_list(const char* num);
int compare_lists(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2);
int addition(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, Dlist** headR, Dlist** tailR);
int subtraction(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, Dlist** headR, Dlist** tailR);
int multiplication(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, Dlist** headR, Dlist** tailR);
int division(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, Dlist** headR, Dlist** tailR);

#endif
