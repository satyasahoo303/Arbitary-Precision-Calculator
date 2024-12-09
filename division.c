/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int division(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, Dlist** headR, Dlist** tailR) {
    // Division by zero check
    if (!(*head2) || ((*head2)->data == 0 && !(*head2)->next)) {
        printf("Error: Division by zero.\n");
        return FAILURE;
    }

    // Compare dividend and divisor
    int cmp = compare_lists(head1, tail1, head2, tail2);
    if (cmp < 0) {
        append(headR, tailR, 0);
        return SUCCESS;
    }
    if (cmp == 0) {
        append(headR, tailR, 1);
        return SUCCESS;
    }

    // Initialize quotient and remainder
    Dlist* quotient = NULL;
    Dlist* quotient_tail = NULL;
    Dlist* remainder = NULL;
    Dlist* remainder_tail = NULL;

    Dlist* current = *head1;

    while (current) {
        // Bring down the next digit into the remainder
        append(&remainder, &remainder_tail, current->data);

        // Remove leading zeros from the remainder
        while (remainder && remainder->data == 0 && remainder->next) {
            Dlist* temp = remainder;
            remainder = remainder->next;
            if (remainder) remainder->prev = NULL;
            free(temp);
            temp = NULL;
        }

        // Calculate the quotient digit
        int digit = 0;
        while (compare_lists(&remainder, &remainder_tail, head2, tail2) >= 0) {
            Dlist* temp_remainder = NULL;
            Dlist* temp_remainder_tail = NULL;

            subtraction(&remainder, &remainder_tail, head2, tail2, &temp_remainder, &temp_remainder_tail);

            free_list(remainder);
            remainder = NULL;

            remainder = temp_remainder;
            remainder_tail = temp_remainder_tail;
            digit++;
        }

        // Append the digit to the quotient
        append(&quotient, &quotient_tail, digit);

        // Move to the next digit
        current = current->next;
    }

    // Handle leading zeros in the quotient
    while (quotient && quotient->data == 0 && quotient->next) {
        Dlist* temp = quotient;
        quotient = quotient->next;
        if (quotient) quotient->prev = NULL;
        free(temp);
        temp = NULL;
    }

    // Edge case: If quotient is empty, append 0
    if (!quotient) {
        append(&quotient, &quotient_tail, 0);
    }

    *headR = quotient;
    *tailR = quotient_tail;

    // Free remainder memory
    if (remainder) {
        free_list(remainder);
        remainder = NULL;
        remainder_tail = NULL;
    }

    return SUCCESS;
}
