#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    
    // these nodes will hold integer data
    int data;
    struct Node *next;
} node;

node *head_ref = NULL;

// first function is the add to head, or push 
void addToHead(int x) {
    node *temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = head_ref;
    head_ref = temp;
}
// finds a position and inserts node there
void Insert(int x, int pos) {
    node *temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    if (pos == 1) {
        temp->next = head_ref;
        head_ref = temp;
        return;
    }
    node *temp2 = head_ref;
    //traverse to the postion   
    for (int i = 0; i < pos - 2; i++) {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}

void Append(int x) {
    node *temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;

    node *curr = head_ref;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    return;
}

void Print() {
    node *curr = head_ref;
    while(curr != NULL) {
        printf(" %d ", curr->data);
        curr = curr->next;
    }
}



int main() {

    addToHead(124);
    addToHead(12);
    addToHead(454);
    addToHead(3);
    Append(12345);
    Insert(9999, 3);
    Print();
    return 0;
}