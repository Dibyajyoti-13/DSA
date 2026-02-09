/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //create node and insert in between
        if(!head) return head;

        Node* temp = head;
        while(temp){    
            Node* t = new Node(temp->val);
            t->next = temp->next;
            temp->next = t;
            temp = temp->next->next;
        }

        Node* result = head->next;

        //assign random
        temp = head;
        while(temp){
            if(temp->random){
                temp->next->random = temp->random->next;
            }
            else temp->next->random = NULL;
            temp = temp->next->next;
        }

        //fix both linkedList
        temp = head;
        while(temp && temp->next){
            Node* t2 = temp->next;
            temp->next = t2->next;
            if(t2->next) t2->next = t2->next->next;
            temp = temp->next;
        }
        return result;
    }
};