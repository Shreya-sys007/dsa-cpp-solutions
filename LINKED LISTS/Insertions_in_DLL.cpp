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
void insertion(Node* prev_node, int new_data){
    if(prev_node == NULL){
        return;
    }

    Node* new_node = new Node(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if(new_node->next != NULL){
        new_node->next->prev = new_node;
    }
}
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head->next->prev = head;
    head->next->next->prev = head->next;
    head->next->next->next->prev = head->next->next;

    insertion(head->next->next, 50);
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

//Add a node after a given node in a DLL
void insertion(Node* &head, Node* next_node, int new_data){
    if(next_node == NULL){
        return;
    }
    Node* new_node = new Node(new_data);
    new_node->prev = next_node->prev;
    new_node->next = next_node;
    next_node->prev = new_node;
    if(new_node->prev != NULL){
        new_node->prev->next = new_node;
    }
    else{
        head = new_node;
    }
    return;
}
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    //head->prev = NULL;
    head->next->prev = head;
    head->next->next->prev = head->next;
    head->next->next->next->prev = head->next->next;
    insertion(head, head->next->next, 50);
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}





