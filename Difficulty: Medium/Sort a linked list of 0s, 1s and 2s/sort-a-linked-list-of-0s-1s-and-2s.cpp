/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node zeroDummy(-1);
        Node oneDummy(-1);
        Node twoDummy(-1);
        
        Node* zero = &zeroDummy;
        Node* one = &oneDummy;
        Node* two = &twoDummy;
        
        while(head){
            if(head->data == 1){
                one->next = head;
                one = one->next;
            }
            else if(head->data == 2){
                two->next = head;
                two = two->next;
            }
            else{
                zero->next = head;
                zero = zero->next;
            }
            head = head->next;
        }
        
        if(oneDummy.next) zero->next = oneDummy.next;
        else zero->next = twoDummy.next;
        
        if(twoDummy.next){
            one->next = twoDummy.next;
            two->next = nullptr;
        }else one->next = nullptr;
        
        return zeroDummy.next;
    }
};