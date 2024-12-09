/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
int addition(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, Dlist** headR, Dlist** tailR) {
    int carry = 0, sum;
    Dlist *p1 = *tail1, *p2 = *tail2;

    while (p1 || p2 || carry) {
        sum = carry + (p1 ? p1->data : 0) + (p2 ? p2->data : 0);
        carry = sum / 10;
        prepend(headR, tailR, sum % 10);

        if (p1) p1 = p1->prev;
        if (p2) p2 = p2->prev;
    }

    return 1; // SUCCESS
}
