/*
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
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        Node* next;
        
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
        
    }
    
    bool isPalindrome(Node *head) {
        //  code here
        Node* fast = head;
        Node* slow = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow = reverse(slow);
        
        Node* curr = head;
        while(slow != nullptr && curr != nullptr){
            if(curr->data != slow->data) return false;
            
            slow = slow->next;
            curr = curr->next;
        }
        return true;
    }
};