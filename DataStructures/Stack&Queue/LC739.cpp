#include <bits/stdc++.h>

using namespace std;

// 739. 每日温度

// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指在第 i 天之后，才会有更高的温度。
// 如果气温在这之后都不会升高，请在该位置用 0 来代替。

// 可以维护一个存储下标的单调栈，从栈底到栈顶的下标对应的温度列表中的温度依次递减。
// 如果一个下标在单调栈里，则表示尚未找到下一次温度更高的下标。

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 自栈底向栈顶存储的下标温度递减的单调栈
        stack<int> stk;
        int size = temperatures.size();
        vector<int> result(size,0);
        for(int i=0;i<size;++i){
            // 将所有栈中比当前温度低的元素全部弹出
            // 并更新结果
            while(!stk.empty()&&temperatures[i]>temperatures[stk.top()]){
                result[stk.top()] = i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};