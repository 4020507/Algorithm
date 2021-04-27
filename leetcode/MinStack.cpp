class MinStack {
public:
    /** initialize your data structure here. */
    int arr[30000];
    int curr;
    MinStack() {
        curr = 0;
    }
    
    void push(int val) {
        if(curr>30000)
            return;
        arr[curr] = val;
        curr++;
    }
    
    void pop() {
            curr--;
    }
    
    int top() {
        return arr[curr-1];
    }
    
    int getMin() {
        int min = 2147483647;
        
        for(int i = 0;i<curr;i++)
        {
            if(min > arr[i])
            {
                min = arr[i];
            }
        }
        
        return min;
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
