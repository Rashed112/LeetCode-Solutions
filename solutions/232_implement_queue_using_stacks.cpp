//Time: O(1) amortized
//Space: O(2*N)

class MyQueue {
public:
    stack<int>input, output;

    void push(int x) {
        input.push(x);    
    }
    
    int pop() {
        int val = peek();
        output.pop();
        return val;
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        } 
    }
    
    bool empty() {
        return input.empty() && output.empty();
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
