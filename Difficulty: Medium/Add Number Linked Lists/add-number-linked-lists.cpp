/*
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
	Node* reverse(Node* head) {
		Node* prev = nullptr;
		Node* curr = head;
		
		while (curr != nullptr) {
			Node* next = curr->next;
			
			curr->next = prev;
			
			prev = curr;
			curr = next;
		}
		return prev;
	}
	
	Node* addTwoLists(Node* head1, Node* head2) {
		head1 = reverse(head1);
		head2 = reverse(head2);
		
		int carry = 0;
		
		Node dummy(0);
		Node* curr = &dummy;
		
		while (head1 || head2 || carry) {
			int sum = carry;
			
			if (head1) {
				sum += head1->data;
				head1 = head1->next;
			}
			
			if (head2) {
				sum += head2->data;
				head2 = head2->next;
			}
			
			curr->next = new Node(sum % 10);
			
			carry = sum / 10;
			curr = curr->next;
		}
		Node* head3 = reverse(dummy.next);
		
		while(true){
		    if(head3->data == 0 && head3->next){
		        head3 = head3->next;
		    }
		    else return head3;
		}
	}
};
