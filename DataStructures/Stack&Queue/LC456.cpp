#include <bits/stdc++.h>

using namespace std;

// 456. 132 模式

// 给你一个整数数组 nums ，数组中共有 n 个整数。
// 132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k] 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。

// 如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 可以根据阈值弹出元素的单调递减栈
        stack<int> monoStk;
        int size = nums.size();
        monoStk.push(nums[size-1]);
        // i,j,k 为 1 3 2 pattern
        int max_k = INT_MIN;
        // 从右往左遍历数组
        for(int idx=size-2;idx>=0;--idx){
           int i = nums[idx];
           if(i<max_k){
               // 根据传递性,栈顶元素一定大于max_k
               return true;
           }else if(i>monoStk.top()){
               // i为新的j
               while(!monoStk.empty() && i>monoStk.top()){
                   max_k = max(max_k,monoStk.top());
                   monoStk.pop();
               }
               monoStk.push(i);
           }else if(i>max_k){
               //i作为候选k
               monoStk.push(i);
           }
        }
        return false;
    }
};