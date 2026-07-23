struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

class MyLinkedList {
public:
    Node* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* curr = head;

        while (curr && index) {
            curr = curr->next;
            index--;
        }

        if (!curr) return -1;
        return curr->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
    }

    void addAtTail(int val) {
        if (!head) {
            addAtHead(val);
            return;
        }

        Node* curr = head;
        while (curr->next) curr = curr->next;

        curr->next = new Node(val);
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* curr = head;

        while (curr && index > 1) {
            curr = curr->next;
            index--;
        }

        if (!curr) return;

        Node* node = new Node(val);
        node->next = curr->next;
        curr->next = node;
    }

    void deleteAtIndex(int index) {
        if (!head) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;

        while (curr && index > 1) {
            curr = curr->next;
            index--;
        }

        if (!curr || !curr->next) return;

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    ~MyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};