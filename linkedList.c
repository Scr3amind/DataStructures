#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node_t;

node_t* createNode(int nValue)
{
    node_t* newNode = NULL;
    
    newNode = malloc(sizeof(node_t));
    
    if(!newNode)
    {
        
        return NULL;
        
    }
    
    newNode->value = nValue;
    newNode->next = NULL;
    
    return newNode;

}

int insertNode(node_t** head,int nValue){
    
    node_t* iNode;
    iNode = createNode(nValue);
    iNode->next = *head;
    *head = iNode;
    return 0;   
    
    
}

node_t* findValue(node_t* head, int nValue)
{

    node_t* current = head;
    while(current)
    {
        if(current->value==nValue)
        {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}


void deleteNode(node_t* head, int nValue)
{
    node_t* nodeDir;
    node_t* current;

    nodeDir = findValue(head,nValue);
    current = head;
    if(!nodeDir)
    {
        return;
    }
    
    while(current)
    {
        if(current->next==nodeDir)
        {
            current->next = nodeDir->next;
            free(nodeDir);
            return;    
        }

        current = current->next;
    }
    

}

void deleteList(node_t* head)
{
    
}



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

    node_t* current = head_n;

    while(current)
    {
        printf("Value : %i \n",current->value);
        current = current->next;
    }

    if(findValue(head_n,85))
    {
        printf("Found!\n");
    }
    
    printf("Deleting node 45\n");
    deleteNode(head_n,45);
    
    current=head_n;
    while(current)
    {
        printf("Value : %i \n",current->value);
        current = current->next;
    }

    
    return 0;
}