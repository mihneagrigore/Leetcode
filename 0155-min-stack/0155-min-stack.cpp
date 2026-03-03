class MinStack {

private:
    stack<int> s_val, s_min;

public:
    MinStack() {
    }
    
    void push(int val) {
        s_val.push(val);
        if(!s_min.empty())
            if(s_min.top() < val) {
                int elem = s_min.top();
                s_min.push(elem);
            }
            else
                s_min.push(val);
        else
            s_min.push(val);
    }
    
    void pop() {
        s_val.pop();
        s_min.pop();
    }
    
    int top() {
        return s_val.top();
    }
    
    int getMin() {
        return s_min.top();
    }
};