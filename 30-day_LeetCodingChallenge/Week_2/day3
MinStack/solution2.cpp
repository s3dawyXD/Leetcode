struct node
{
    int val ;
    node * next;
};

class MinStack {
public:
    /** initialize your data structure here. */
    
    node * Head;
    node * pp;
    
    MinStack() {
        Head = NULL;
    }
    
    void push(int x) {
        
        node *temp = new node ;
		temp->val = x;
		temp->next = Head ; 
		Head = temp;
        pp = Head;
    }
    
    void pop() {
        
        node * old = Head;
		Head = Head->next;
        pp = Head ;
		delete old;
    }
    
    int top() {
        
        return Head->val;
    }
    
    int getMin() {
        int min = INT_MAX;
        while(pp)
        {
            if(pp->val < min) min = pp->val;
            pp = pp->next;
        }
        pp = Head;
        return min ;
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