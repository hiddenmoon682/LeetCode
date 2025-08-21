//如果压入当前栈的值不是最小值，则再往栈里压入一个最小值，让a在弹出最小值的时候，b也弹出最小值
class MinStack {
public:

    stack<int> a,b;
    MinStack() {
        
    }
    
    void push(int val) {
        a.push(val);
        if(b.empty()) b.push(val);
        else b.push(min(val, b.top()));     
    }
    
    void pop() {
        a.pop();
        b.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */