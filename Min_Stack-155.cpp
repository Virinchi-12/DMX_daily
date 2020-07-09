/*
155. Min Stack
Easy

3407

333

Add to List

Share
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
*/

//Using 2 stacks
class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> a;
    stack<int> b;
    MinStack() {
        
    }
    
    void push(int x) {
        a.push(x);
        
        if(b.empty() || x<=getMin())
            b.push(x);
    }
    
    void pop() {
        if(a.top()==getMin())
            b.pop();
        
        a.pop();
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
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//using single stack
class MinStack {
public:
    /** initialize your data structure here. */
    int min=INT_MAX;
    stack<int> s;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if(x<=min)
        {
            s.push(min);
            min=x;
        }
        s.push(x);
        
    }
    
    void pop() {
        if(s.top()==min)
        {
            s.pop();
            min=s.top();
            s.pop();
        }
        else s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
