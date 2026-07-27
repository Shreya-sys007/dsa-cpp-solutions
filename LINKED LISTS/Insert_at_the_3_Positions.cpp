#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*next;
};

//POSITION: BEGINNING OF SLL
/*head
  |
  |->10 --->20--->30--->NULL
    ^ 
  (insertion)
  */
void insertion(Node** head_ref, int new_data){
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main() {
    Node* head = NULL;
    insertion(&head, 30);
    insertion(&head, 20);
    insertion(&head, 10);
    insertion(&head, 40);
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

//POSITION: SMWHERE AFTER A GIVEN NODE IN SLL
void insertion(Node* previous_node, int new_data){
    if(previous_node == NULL){
        return;
    }
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = previous_node->next;
    previous_node->next = new_node;
}

int main() {
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;
    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 50;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    insertion(second, 40);

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

//POSITION: AT THE END OF SLL
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*next;
};
void insertion(Node** head_ref, int new_data){
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = NULL;
    //empty LL case
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}
int main() {
    Node*head = NULL;
    insertion(&head, 10);
    insertion(&head, 20);
    insertion(&head, 30);

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
