#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}
    
    void push(int x) {
        q1.push(x);
        
    }
    
    int pop() {
        int res = q1.back();
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        } 

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        q2.pop();

        return res;       
    }
    
    int top() {
        return q1.back();
        
    }
    
    bool empty() {
        return q1.empty();
    }
};