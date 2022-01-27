#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.tscott5.h"

int insertPart(PartRecord **listHead, int partNumber, int quantity, char *partName) {

    // If head of list is null, do nothing
    if (&(*listHead) == NULL) {
        return 1;
    }

    // If head of list is not null, insert part
    else {

        // Points to "inner" pointer of listHead
        PartRecord *curr = *listHead;
        PartRecord *prev = NULL;

        // New list memory allocation and field initializations
        PartRecord *newList = (PartRecord *) malloc(sizeof(PartRecord));
        newList->partNumber = partNumber;
        newList->quantity = quantity;
        newList->next = NULL;
        strcpy(newList->partName, partName);

        if (curr == NULL) {
            *listHead = newList;
        }

        else {

            while (curr != NULL && partNumber > curr->partNumber) {
                prev = curr;
                curr = curr->next;
            }

            // If part is in list, don't add part
            if (curr != NULL && partNumber == curr->partNumber) {
                return 1;
            }
        
            newList->next = curr;

            if (prev != NULL) {
                prev->next = newList;
            }
            
            else {
                *listHead = newList;
            }
        }
    }
    return 0;
}

int deletePart(PartRecord **theList, int partNumber) {
    PartRecord *curr = *theList;
    PartRecord *prev = NULL;

    while (curr != NULL && curr->partNumber != partNumber) {
        prev = curr;
        curr = curr->next;

    }

    if (curr == NULL) {
        return 1;
    }

    else {
        if (prev != NULL) {
            prev->next = curr->next;
        }
        else {
            *theList = curr->next;
        }

        //free(curr);
        return 0;
    }
}

PartRecord *findPart(PartRecord *head, int partNum) {

    PartRecord *curr = head;

    int found = 0;

    while (curr != NULL && !found) {
        if (curr->partNumber == partNum) {
            found = 1;
        } 
        else {
            curr = curr->next;
        }
    }

    if (found) {
        return curr;
    }
    else {
        return NULL;
    }
}

void printParts(PartRecord *theList){

    while (theList != NULL) {
        printf("\nnumber = %d, quantity = %d, name = | %s |", theList->partNumber, theList->quantity, theList->partName);       
        theList = theList->next;
    }

    printf("\n");

}

void printPartList(PartRecord *theList){

    while (theList != NULL) {
        printf("\nnumber = %d, quantity = %d, name = | %s |", theList->partNumber, theList->quantity, theList->partName);       
        theList = theList->next;
    }

    printf("\n");

}