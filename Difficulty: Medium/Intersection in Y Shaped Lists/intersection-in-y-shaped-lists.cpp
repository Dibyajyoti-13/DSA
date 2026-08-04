/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  code here
        if(!head1 || !head2) return nullptr;
        
        Node *ptr1 = head1;
        Node *ptr2 = head2;
        
        while (ptr1 != ptr2) {
            ptr1 = ptr1 ? ptr1->next : head2;
            ptr2 = ptr2 ? ptr2->next : head1;
        }
    
        return ptr1;
    }
};