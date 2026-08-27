/* Structure of linked list Node
class Node {
    public int data;
    public Node next;

    public Node(int x) {
        data = x;
        next = null;
    }
};*/

class Solution {
    public boolean isSorted(Node head) {
        // code here
        Node temp = head;
        if(head == null || head.next == null){
            return true;
        }
        Node t = head;
        
        while(t.next != null && t.data == t.next.data){
            t = t.next;
        }
        
        if( t.next == null){
            return true;
        }
        boolean inc = (t.data > t.next.data);
        
        while(temp.next != null){
            if(inc){ //decreasing
                if(temp.data < temp.next.data){
                    return false;
                }
                temp = temp.next;
            }
            else if(!inc){ //increasing
                if(temp.data > temp.next.data){
                    return false;
                }
                temp = temp.next;
            }
        }
        return true;
    }
}
