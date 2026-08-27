/*
class Node {
    int data;
    Node prev, next;
    Node(int data) {
        this.data = data;
        this.prev = this.next = null;
    }
}
*/
class Solution2 {
    public Node sortedInsert(Node head, int x) {
        // add your code here
        Node new_node = new Node(x);
        
        if(x <= head.data){
            new_node.next = head.next;
            new_node.prev = head;
            head.next = new_node;
            head= new_node;
            return head;
        }
            
        for(Node temp = head; temp.next != null; temp = temp.next){
            if(temp.next.data >= x){
                new_node.next = temp.next;
                new_node.prev = temp;
                temp.next.prev = new_node;
                temp.next = new_node;
                break;
            }
        }
        return head;
    }
}
