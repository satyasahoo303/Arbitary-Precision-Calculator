/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int multiplication(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2, Dlist** headR, Dlist** tailR) {
    Dlist *res = NULL, *res_tail = NULL;
    Dlist *p2 = *tail2;
    int shift = 0;

    while (p2) {
        Dlist *p1 = *tail1;
        Dlist *partial_res = NULL, *partial_res_tail = NULL;
        int carry = 0, product;

        while (p1 || carry) {
            product = carry + (p1 ? p1->data : 0) * p2->data;
            carry = product / 10;
            prepend(&partial_res, &partial_res_tail, product % 10);

            if (p1) p1 = p1->prev;
        }

        for (int i = 0; i < shift; i++) {
            append(&partial_res, &partial_res_tail, 0);
        }

        Dlist *new_res = NULL, *new_res_tail = NULL;
        addition(&res, &res_tail, &partial_res, &partial_res_tail, &new_res, &new_res_tail);
        free_list(res);
        res = new_res;
        res_tail = new_res_tail;
        free_list(partial_res);

        p2 = p2->prev;
        shift++;
    }

    *headR = res;
    *tailR = res_tail;
    return 1; // SUCCESS
}
