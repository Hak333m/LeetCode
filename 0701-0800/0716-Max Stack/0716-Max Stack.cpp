class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        St.push(x);
        if (maxSt.empty() || x >= maxSt.top()) {
            maxSt.push(x);
        }
    }
    
    int pop() {
        int val = St.top();
        St.pop();
        if (val == maxSt.top()) {
            maxSt.pop();
        }
        return val;
    }
    
    int top() {
        return St.top();
    }
    
    int peekMax() {
        return maxSt.top();
    }
    
    int popMax() {
        int val = maxSt.top();
        maxSt.pop();
        stack<int> temp;
        while (St.top() != val) {
            temp.push(St.top());
            St.pop();
        }
        
        St.pop();
        while (!temp.empty()) {
            push(temp.top());
            temp.pop();
        }
        return val;
    }
    
private:
    stack<int> St;
    stack<int> maxSt;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        St.push_front(x);
        table[x].push_back(St.begin());
    }
    
    int pop() {
        int val = top();
        St.pop_front();
        table[val].pop_back();
        if (table[val].size() == 0) {
            table.erase(val);
        }
        return val;
    }
    
    int top() {
        return *(St.begin());
    }
    
    int peekMax() {
        return table.rbegin()->first;
    }
    
    int popMax() {
        int val = peekMax();
        St.erase(table.rbegin()->second.back());
        table.rbegin()->second.pop_back();
        if (table.rbegin()->second.size() == 0) {
            table.erase(val);
        }
        return val;
    }
    
private:
    map<int, vector<list<int>::iterator>> table;
    list<int> St;
};
