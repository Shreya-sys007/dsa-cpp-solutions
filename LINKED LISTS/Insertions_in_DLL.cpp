#include<bits/stdc++.h>
using namespace std;

class Node{
public:

    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

//insertion at the beginning
void insertion(Node** head_ref, int new_data){
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    if(new_node != NULL){
        new_node->prev = NULL;
    }
    if(*head_ref != NULL){
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}

int main() {
    Node* head = NULL;
    insertion(&head, 10);
    insertion(&head, 20);
    insertion(&head, 30);
    insertion(&head, 40);
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

//Add a node before a given node in a DLL



