/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, Dlist** headR, Dlist** tailR) {
    int borrow = 0, diff;
    int is_negative = 0;

    // Compare lists to determine order
    int comparison = compare_lists(head1, tail1, head2, tail2);
    if (comparison < 0) {
        // Swap lists since the result will be negative
        Dlist* temp_head = *head1;
        Dlist* temp_tail = *tail1;
        *head1 = *head2;
        *tail1 = *tail2;
        *head2 = temp_head;
        *tail2 = temp_tail;
        is_negative = 1;
    }

    Dlist* p1 = *tail1; // Pointer for the larger number
    Dlist* p2 = *tail2; // Pointer for the smaller number

    // Subtract digit by digit
    while (p1 || p2) {
        int digit1 = (p1 ? p1->data : 0) - borrow;
        int digit2 = (p2 ? p2->data : 0);

        // Handle borrow if digit1 is less than digit2
        if (digit1 < digit2) {
            borrow = 1;
            digit1 += 10;
        } else {
            borrow = 0;
        }

        // Calculate the difference
        diff = digit1 - digit2;

        // Prepend the result
        prepend(headR, tailR, diff);

        // Move to the previous digits
        if (p1) p1 = p1->prev;
        if (p2) p2 = p2->prev;
    }

    // Remove leading zeros
    while (*headR && (*headR)->data == 0 && (*headR)->next) {
        Dlist* temp = *headR;
        *headR = (*headR)->next;
        if (*headR) (*headR)->prev = NULL;
        free(temp);
    }

    // Handle result being zero
    if (!(*headR)) {
        append(headR, tailR, 0);
    }

    // Add negative sign if needed
    if (is_negative) {
        Dlist* temp_head = *headR;
        while (temp_head) {
            temp_head->data *= -1; // Negate all digits
            temp_head = temp_head->next;
        }
    }

    return SUCCESS;
}
