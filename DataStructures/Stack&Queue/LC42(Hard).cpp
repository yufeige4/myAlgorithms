#include <bits/stdc++.h>

using namespace std;

// 42. 接雨水

// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int size = height.size();
        // 单调栈 高度小于等于栈顶元素则下标进栈
        stack<int> leftStk;
        for(int i=0;i<size;++i){
            int h = height[i];
            // 栈不为空 且 出现高于栈顶的高度时
            while(!leftStk.empty() && height[leftStk.top()]<h){
                int mid = height[leftStk.top()];
                while(!leftStk.empty() && height[leftStk.top()]==mid){
                    leftStk.pop();
                }
                if(leftStk.empty()) continue;
                // 找到 高,低,高这个形式 的下标
                // 计算出该层的蓄水量
                int leftIndex = leftStk.top();
                int left = height[leftIndex];
                sum += min(h-mid,left-mid)*(i-leftIndex-1);
            }
            leftStk.push(i);
        }
        return sum;
    }
};