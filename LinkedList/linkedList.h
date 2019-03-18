typedef struct node
{
    int value;
    struct node *next;
} node_t;

node_t* createNode(int nValue);

int insertNode(node_t** head,int nValue);

node_t* findValue(node_t* head, int nValue);

void deleteNode(node_t* head, int nValue);

void deleteList(node_t* head);

void displayList(node_t *head);