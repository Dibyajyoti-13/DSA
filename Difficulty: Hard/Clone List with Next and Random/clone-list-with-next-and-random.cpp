/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        // code here
        if (head == nullptr) {
            return nullptr;
        }
        Node* curr = head;
        while(curr != nullptr){
            Node* newNode = new Node(curr->data);
            newNode->next = curr->next;
            curr->next = newNode;
            
            curr = newNode->next;
        }
        
        curr = head;
        while(curr != nullptr){
            Node* clone = curr->next;
            if (curr->random != nullptr) clone->random = curr->random->next;
            
            curr = clone->next;
        }
        
        curr = head;
        Node* clonehead = curr->next;
        Node* clone = clonehead;
        
        while(clone->next != nullptr){
            curr->next = clone->next;
            clone->next = curr->next->next;
            
            curr = curr->next;
            clone=clone->next;
        }
        
        curr->next = nullptr;
        clone->next = nullptr;
        
        return clonehead;
    }
};
    
    