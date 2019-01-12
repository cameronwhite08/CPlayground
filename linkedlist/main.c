#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* head;
struct node* curr;

struct node* createNode(int value){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->value = value;
    return newNode;
}

//currently walks entire list
void insertLast(int value)
{
    curr = head;
    //want to stay on last node in list
    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    struct node* newNode = createNode(value);
    curr->next = newNode;
}

void insertFirst(int value)
{
    struct node* newNode = createNode(value);
    newNode->next = head;

    head = newNode;
}

void insertAfter(int value, struct node* start)
{
    struct node* newNode = createNode(value);
    newNode->next = start->next;

    start->next = newNode;
}

void printList(struct node* start)
{
    int used = 0;
    curr = start;
    //walk entire list
    while(curr != NULL)
    {
        used = 1;
        printf("%d\t", curr->value);
        curr = curr->next;
    }
    
    printf("\n");

    if(used == 1){
        printf("The list is empty");
    }
}

struct node* findNode(int key){
    curr = head;

    while(curr != NULL){
        if(curr->value == key){
            return curr;
        }

        curr = curr->next;
    }
    return NULL;
}

void cleanupList()
{
    curr = head;
    while (curr != NULL){
        curr = curr->next;

        free(head);

        head = curr;
    }
}

int main() {
    //reset stdout for some reason??
    setbuf(stdout, 0);

    head = createNode(2);

    insertLast(3);
    insertLast(4);

    insertFirst(0);

    struct node* curr = findNode(0);
    insertAfter(1, curr);

    printList(head);

    cleanupList();

    printList(head);

    return 0;
}