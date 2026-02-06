class Node{
    public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
    unordered_map<int, Node*> cache;
    int capacity;
    Node* head;
    Node* tail;

    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToFront(Node* node){
        removeNode(node);
        addToFront(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        Node* temp = cache[key];
        moveToFront(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
        moveToFront(node);
        return;
        }
        if(cache.size() == capacity){
            Node* toDel = tail->prev;
            cache.erase(toDel->key);
            removeNode(toDel);
            delete toDel;
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        addToFront(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */