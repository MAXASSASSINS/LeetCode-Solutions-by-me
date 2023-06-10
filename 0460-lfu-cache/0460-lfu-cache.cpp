struct Node{
    int key;
    int value;
    int count;
    Node *next;
    Node *prev;
    
    Node(int key_,int val){
        key = key_;
        value = val;
        count = 1;
        next = nullptr;
        prev = nullptr;
    }
};

struct List{
    Node *head;
    Node *tail;
    int size;
    
    List(){
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node *node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }
    
    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};



class LFUCache {
    private:
        int cap;
        unordered_map<int, Node*> keyNode;
        unordered_map<int, List *> freqListMap; 
        int minFreq;
        int currSize;
    
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        currSize = 0;
    }
    
    void updateFreqListMap(Node *temp){
        int key = temp->key;
        keyNode.erase(key);
        int freq = temp->count;
        List *lst = freqListMap[freq];
        lst->deleteNode(temp);
        
        if(freq == minFreq && lst->size == 0){
            minFreq++;
        }
            
        List* nextHigherFreqList = new List();
        if(freqListMap.find(freq + 1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[freq + 1];
        }
            
        freq += 1;
        temp->count = freq;
        nextHigherFreqList->addNode(temp);
        freqListMap[freq] = nextHigherFreqList;
        keyNode[temp->key] = temp;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node *temp = keyNode[key];
            int val = temp->value;
            updateFreqListMap(temp);
            return val;
        }
        return -1;
    }
    
    void put(int key, int val) {
        if(cap == 0) return;
        
        if(keyNode.find(key) != keyNode.end()){
            Node *temp = keyNode[key];
            temp->value = val;
            updateFreqListMap(temp);
        }
        else{
            if(currSize == cap){
                List *lst = freqListMap[minFreq];
                keyNode.erase(lst->tail->prev->key);
                lst->deleteNode(lst->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List *lstFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                lstFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, val);
            lstFreq->addNode(node);
            keyNode[key] = node;
            freqListMap[minFreq] = lstFreq;
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */