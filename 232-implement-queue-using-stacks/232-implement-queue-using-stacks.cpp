class MyQueue {
    
    stack<int> input,output;
public:
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        input.push(x);
        
        
    }
    
    int pop() 
    {
        int ans = peek();
        output.pop();
        
        return ans;
    }
    
    int peek() {
        
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        
        return output.top();
        
    }
    
    bool empty() {
        return input.empty() && output.empty();
        
    }
};

// to understand
// I have one input stack, onto which I push the incoming elements, and one output stack, from which I peek/pop. I move elements from input stack to output stack when needed, i.e., when I need to peek/pop but the output stack is empty. When that happens, I move all elements from input to output stack, thereby reversing the order so it's the correct order for peek/pop.

// The loop in peek does the moving from input to output stack. Each element only ever gets moved like that once, though, and only after we already spent time pushing it, so the overall amortized cost for each operation is O(1).

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */