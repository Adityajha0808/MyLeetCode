class MyQueue {
public:
    stack<int> s,t;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        int x = t.top();
        t.pop();
        while(!t.empty()) {
            s.push(t.top());
            t.pop();
        }
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        while(!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        int x = t.top();
        while(!t.empty()) {
            s.push(t.top());
            t.pop();
        }
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (s.empty() ? true : false);
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