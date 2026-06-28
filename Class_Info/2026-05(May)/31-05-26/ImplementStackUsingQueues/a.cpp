class MyStack {
private:
    queue<int> list;

    int shift(bool is_top = false) {
        int size = list.size();        
        for (int _ = 0; _ < size - 1; _++) {
            list.push(list.front());
            list.pop();
        }

        int ans = list.front();
        list.pop();
        
        if (is_top) list.push(ans);
        return ans;
    }

public:
    MyStack() {}
    
    void push(int x) {
        list.push(x);
    }
    
    int pop() {
        return shift();
    }
    
    int top() {
        return shift(true);
    }
    
    bool empty() {
        return list.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */