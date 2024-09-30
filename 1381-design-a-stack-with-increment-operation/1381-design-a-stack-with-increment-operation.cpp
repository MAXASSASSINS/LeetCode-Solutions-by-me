class CustomStack {
public:
    vector<int> vec;
    int size = 0;
    int ptr = -1;
    CustomStack(int maxSize) {
        size = maxSize;
        for(int i = 0; i < maxSize; i++){
            vec.push_back(-1);
        }
    }
    
    void push(int x) {
        if(ptr + 1 < size){
            ptr++;
            vec[ptr] = x;
        }
    }
    
    int pop() {
        if(ptr < 0){
            return -1;
        }
        int x = vec[ptr];
        vec[ptr] = -1;
        ptr--;
        return x;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, ptr + 1); i++){
            vec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */