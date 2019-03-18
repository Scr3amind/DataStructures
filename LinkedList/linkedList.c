#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


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
   if(!head)
   {
       return;
   } 
   deleteList(head->next);
   free(head);
}

void displayList(node_t *head)
{
    node_t* current = head;

    while(current)
    {
        printf("Value : %i \n",current->value);
        current = current->next;
    }
}

