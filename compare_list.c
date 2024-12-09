#include "apc.h"
int compare_lists(Dlist** head1, Dlist** tail1, Dlist** head2, Dlist** tail2) {
    Dlist *p1 = *head1, *p2 = *head2;

    // Remove leading zeros in both lists
    while (p1 && p1->data == 0) {
        Dlist* temp = p1;
        p1 = p1->next;
        free(temp);
        if (p1) p1->prev = NULL;
    }
    while (p2 && p2->data == 0) {
        Dlist* temp = p2;
        p2 = p2->next;
        free(temp);
        if (p2) p2->prev = NULL;
    }

    // Check if lists are empty after removing leading zeros
    if (!p1 && !p2) return 0;  // Both numbers are zero
    if (!p1) return -1;        // List1 is smaller
    if (!p2) return 1;         // List2 is smaller

    // Compare lengths
    int len1 = 0, len2 = 0;
    for (Dlist* temp = p1; temp; temp = temp->next) len1++;
    for (Dlist* temp = p2; temp; temp = temp->next) len2++;

    if (len1 > len2) return 1;  // List1 is greater
    if (len1 < len2) return -1; // List2 is greater

    // Compare digit by digit
    while (p1 && p2) {
        if (p1->data > p2->data) return 1; // List1 is greater
        if (p1->data < p2->data) return -1; // List2 is greater
        p1 = p1->next;
        p2 = p2->next;
    }

    return 0; // Lists are equal
}
