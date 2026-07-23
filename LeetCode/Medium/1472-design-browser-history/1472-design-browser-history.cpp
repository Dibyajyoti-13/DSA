struct Node{
    string url;
    Node* next;
    Node* prev;
    Node(string s) : url(s), next(nullptr), prev(nullptr) {}
};

class BrowserHistory {
public:
    Node* curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp = curr->next;
        while(temp != nullptr){
            Node* t = temp;
            temp = temp->next;
            delete t;
        }

        curr->next = new Node(url);
        curr->next->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(curr->prev && steps--) curr = curr->prev;
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next && steps--) curr = curr->next;
        return curr->url;
    }
};
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */