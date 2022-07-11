class MyStack {
private:
    queue<int> first;
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
            int val = first.front();
            first.pop();
            first.push(val);
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