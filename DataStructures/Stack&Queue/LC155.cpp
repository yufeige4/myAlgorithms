#include <bits/stdc++.h>

using namespace std;

// 155. 最小栈

// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

// 实现 MinStack 类:

// MinStack() 初始化堆栈对象。
// void push(int val) 将元素val推入堆栈。
// void pop() 删除堆栈顶部的元素。
// int top() 获取堆栈顶部的元素。
// int getMin() 获取堆栈中的最小元素。

class MinStack {

private:
    stack<int> stk;
    // 设置一个辅助栈 进栈时根据情况添加栈顶元素
    // 出栈时同步出栈
    stack<int> minStk;
public:
    MinStack() {
        minStk.push(INT_MAX);
    }
    
    void push(int val) {
        int minVal = minStk.top();
        if(val<minVal){
            minStk.push(val);
        }else{
            minStk.push(minVal);
        }
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
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