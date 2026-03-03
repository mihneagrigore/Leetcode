class MinStack {
private:
    stack<long long> s;
    long long minVal;

public:
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push(0);       
            minVal = val;    
        } else {
            long long diff = (long long)val -(long long)minVal;
            s.push(diff);   
            if (diff < 0)    
                minVal = val;
        }
    }

    void pop() {
        long long diff = s.top();
        s.pop();
        if (diff < 0) {
            minVal -= diff;  
        }
    }

    int top() {
        long long diff = s.top();
        if (diff >= 0)
            return minVal + diff;
        else
            return minVal;  
    }

    int getMin() {
        return minVal;
    }
};