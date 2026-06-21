class MinStack {
public:

    private:
        std::vector<std::pair<int, int>> stack;

    public: 

    MinStack() {

    }
    
    void push(int value){
        if (stack.size() == 0)
            stack.emplace_back(value, value);
        else {
            int min = std::min(value, stack.back().second);
            stack.emplace_back(value, min);
        }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */