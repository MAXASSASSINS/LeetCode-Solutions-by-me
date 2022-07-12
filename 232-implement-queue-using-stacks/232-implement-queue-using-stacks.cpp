class MyQueue {
private:
    stack<int> first;
    stack<int> second;
public:
    MyQueue() {

    }

    void push(int x) {
        first.push(x);
    }

    int pop() {
        if(second.empty()){
            while(!first.empty()){
                second.push(first.top());
                first.pop();
            }
        }
        int val = second.top();
        second.pop();
        return val;
    }

    int peek() {
        if(second.empty()){
            while(!first.empty()){
                second.push(first.top());
                first.pop();
            }
        }
        int val = second.top();
        return val;
    }

    bool empty() {
        return first.empty() && second.empty();
    }
};