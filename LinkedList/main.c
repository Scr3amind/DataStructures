#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


int main()
{
    node_t* head_n = NULL;
    
    head_n = createNode(1);

    insertNode(&head_n,4);
    insertNode(&head_n,6);
    insertNode(&head_n,74);
    insertNode(&head_n,58);
    insertNode(&head_n,45);
    insertNode(&head_n,85);

    displayList(head_n);

    if(findValue(head_n,85))
    {
        printf("Found!\n");
    }
    
    printf("Deleting node 45\n");
    deleteNode(head_n,45);
    
    displayList(head_n);

    printf("Deleting list\n");
    deleteList(head_n);
    

    
    return 0;
}