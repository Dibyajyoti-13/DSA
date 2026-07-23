struct Node{
    int val;
    int min;
    Node* next;
    Node(int v, int x) : val(v), min(x), next(nullptr) {}
};

class MinStack {
public:
    Node* head;
    MinStack() {
        head = nullptr;
    }
    
    void push(int value) {
        int x = value;
        if(head != nullptr) x = min(head->min, x);
        Node* temp = new Node(value, x);
        temp->next = head;
        head = temp;
    }
    
    void pop() {
        if(head == nullptr) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        return head ? head->val : -1;
    }

    int getMin() {
        return head ? head->min : -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */