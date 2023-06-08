class Node{
    friend class LRUCache;
    private:
        int key;
        int val;
        Node *next;
        Node *prev;
    public:
        Node(int k, int v){
            val = v;
            key = k;
            next = nullptr;
            prev = nullptr;
        }
};


Node *head = new Node(-1, -1);
Node *tail = new Node(-1, -1);


class LRUCache {
    int cap;
    unordered_map<int, Node*> um;
    
    
    void deleteNode(Node* node){
        Node *prev = node->prev;
        Node *next = node->next;
        
        prev->next = next;
        next->prev = prev;
        
        delete(node);
    }
    
    void addNode(int key, int value){
        Node *node = new Node(key, value);
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto it = um.find(key);
        if(it != um.end()){
            Node* node = it->second;
            int key = node->key;
            int value = node->val;
            um.erase(key);
            deleteNode(node);
            addNode(key, value);
            um.insert({key, head->next});
            return value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        auto it = um.find(key);
        if(it == um.end()){
            if(um.size() == cap){
                um.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
        }
        else{
            Node *node = it->second;
            deleteNode(node);
            um.erase(key);
        }
        addNode(key, value);
        um.insert({key, head->next});
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */