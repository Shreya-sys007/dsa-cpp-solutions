/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    bool isSorted(Node* head) {
        // code here
        Node* temp = head;
        if(head == NULL || head->next == NULL){
            return true;
        }
        Node* t = head;
        
        while(t->next != NULL && t->data == t->next->data){
            t = t->next;
        }
        
        if( t->next == NULL){
            return true;
        }
        bool inc = (t->data > t->next->data);
        
        while(temp->next != NULL){
            if(inc){ //decreasing
                if(temp->data < temp->next->data){
                    return false;
                }
                temp = temp->next;
            }
            else if(!inc){ //increasing
                if(temp->data > temp->next->data){
                    return false;
                }
                temp = temp->next;
            }
        }
        return true;
    }
};
