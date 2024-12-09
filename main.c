/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"

// Helper to create a node
Dlist* create_node(int data) {
    Dlist* new_node = (Dlist*)malloc(sizeof(Dlist));
    if (!new_node) return NULL;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Append a digit to the list //Insert Last
void append(Dlist** head, Dlist** tail, int data) {
    Dlist* new_node = create_node(data);
    if (!*head) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }
}

// Prepend a digit to the list   //insert before
void prepend(Dlist** head, Dlist** tail, int data) {
    Dlist* new_node = create_node(data);
    if (!*head) {
        *head = *tail = new_node;
    } else {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}

// Convert string to doubly linked list
Dlist* string_to_list(const char* num) {
    Dlist *head = NULL, *tail = NULL;
    for (int i = 0; num[i]; i++) {
        append(&head, &tail, num[i] - '0');
    }
    return head;
}

// Print list as a number
void print_list(Dlist* head) {
    if (!head) {
        printf("0");
        return;
    }
    while (head) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

// Free list memory
void free_list(Dlist* head) {
    while (head) {
        Dlist* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char num1[1024], num2[1024], operator;
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    printf("Enter the first number: ");
    scanf("%s", num1);
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter the second number: ");
    scanf("%s", num2);

    head1 = string_to_list(num1);
    head2 = string_to_list(num2);
    tail1 = head1;
    while (tail1->next) tail1 = tail1->next;
    tail2 = head2;
    while (tail2->next) tail2 = tail2->next;

    switch (operator) {
        case '+':
            addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Result: ");
            print_list(headR);
            break;

        case '-':
            subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Result: ");
            print_list(headR);
            break;

        case '*':
            multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Result: ");
            print_list(headR);
            break;

        case '/':
            division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Result: ");
            print_list(headR);
            break;

        default:
            printf("Invalid operator!\n");
            break;
    }

    free_list(head1);
    free_list(head2);
    free_list(headR);

    return 0;
}