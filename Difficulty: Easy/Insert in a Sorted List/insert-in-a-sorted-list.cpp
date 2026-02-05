/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int key) {
        // Code here
        Node* newNode = new Node(key);
        
        if(!head || head->data > key){
            newNode->next = head;
            head = newNode;
            return head;
        }
        
        Node* curr = head;
        while(curr->next != NULL && curr->next->data < key){
            curr = curr->next;
        }
        
        newNode->next = curr->next;
        curr->next = newNode;
        return head;
    }
};