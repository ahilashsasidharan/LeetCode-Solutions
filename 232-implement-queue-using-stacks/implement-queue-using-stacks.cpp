class MyQueue {

protected:

stack<int> insert;
stack<int> extract;

public:

    MyQueue() {
        
    }
    
    void push(int x) {
        insert.push(x);
    }
    
    int pop() {
        if(extract.empty()){
            while(!insert.empty()){
                extract.push(insert.top());
                insert.pop();
            }
        }
        int top = extract.top();
        extract.pop();
        return top;
    }
    
    int peek() {
        if(extract.empty()){
            while(!insert.empty()){
                extract.push(insert.top());
                insert.pop();
            }
        }
        return extract.top();
    }
    
    bool empty() {
        return insert.empty() && extract.empty();
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