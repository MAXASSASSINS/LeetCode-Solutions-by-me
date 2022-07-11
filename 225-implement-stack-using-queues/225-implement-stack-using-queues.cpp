class MyStack {
private:
    queue<int> first;
    queue<int> second;
public:
    MyStack() {}

    void push(int x) {
        first.push(x);
    }

    int pop() {
        int size = first.size();

        if (size == 0){
            return -1;
        }
        
        while (size - 1 != 0) {
            second.push(first.front());
            first.pop();
            first.push(second.front());
            second.pop();
            size--;
        }
        int firstFront = first.front();
        first.pop();
        return firstFront;
    }

    int top() {
        return first.back();
    }

    bool empty() {
        return first.empty();
    }
};