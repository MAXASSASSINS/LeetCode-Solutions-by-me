class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s2.empty()) {
            int p = s2.top();
            s2.pop();
            s1.push(p);
        }
        
        s1.push(x);
        
        while(!s1.empty()){
            int p = s1.top();
            s1.pop();
            s2.push(p);
        }
    }
    
    int pop() {
        int p =  s2.top();
        s2.pop();
        return p;
    }
    
    int peek() {
        return s2.top();
    }
    
    bool empty() {
        if(s2.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */