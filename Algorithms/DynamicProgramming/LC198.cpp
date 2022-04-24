#include <bits/stdc++.h>

using namespace std;

// 198. 打家劫舍

// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size==1) return nums[0]; 
        int dp[size];
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for(int i=2;i<size;++i){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[size-1];
    }
};