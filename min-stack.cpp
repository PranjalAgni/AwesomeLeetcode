class MinStack {
public:
    /** initialize your data structure here. */
    //stack<int> mystack;
    vector<int> mystack;
    int top_elt;
    int size;
    MinStack() {
        top_elt = -1;
        size = 0;
    }
    
    void push(int x) {
         mystack.push_back(x);
         top_elt += 1;
         size += 1;
    }
    
    void pop() {
        if (top_elt != -1) {
            mystack.erase(mystack.begin() + top_elt);
            top_elt -= 1;
        }
         
    }
    
    int top() {
        if (top_elt == -1) {
            cout << "Invalid" << endl;
            return 0;
        }
        return mystack[top_elt];
    }
    
    int getMin() {
        if (top_elt == -1) {
            cout << "xxxx" << endl;
            return 0;
        }
        int min = INT_MAX;
        for (int i = 0; i <= top_elt; i++) {
            if (mystack[i] < min) {
                min = mystack[i];
            }
        }
        return min;
    }
};



/**
["MinStack","push","push",
"push","top","pop","getMin","pop","getMin","pop",
"push","top","getMin",
"push","top","getMin","pop","getMin"]


[[],[2147483646],[2147483646],
[2147483647],[],[],[],[],[],[],
[2147483647],[],[],
[-2147483648],[],[],[],[]]

[2147483646,2147483646,2147483647,2147483647]
top = 0
size = 3

push,push,push,pop,pop,top,pop,push,getmin
[3,2,1,4]
top = -1
// now top should become vect.size() - 1
[3,2,1]
top = -1

**/