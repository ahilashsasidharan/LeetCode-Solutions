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
        else if (stack[stack.size() - 1].second < stack[stack.size() - 1].first)
            stack.emplace_back(value, stack[stack.size() - 1].second);
        else
            stack.emplace_back(value, stack[stack.size() - 1].first);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1].first;
    }
    
    int getMin() {
        int prevEl = stack[stack.size() - 1].first;
        int min = stack[stack.size() - 1].second;

        if (min < prevEl)
            return min;
        else
            return prevEl;
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