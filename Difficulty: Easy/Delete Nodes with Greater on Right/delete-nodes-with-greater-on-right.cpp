/* Structure of a Linked List node
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
	
	Node* compute(Node* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		
		head = reverse(head);
		
		int maxSoFar = head->data;
		Node* curr = head;
		
		while (curr != nullptr && curr->next != nullptr) {
			
			if (curr->next->data < maxSoFar) {
				
				Node* temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else {
				
				curr = curr->next;
				maxSoFar = curr->data;
			}
		}
		
		return reverse(head);
	}
};
