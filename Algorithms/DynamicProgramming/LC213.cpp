#include <bits/stdc++.h>

using namespace std;

// 213. 打家劫舍 II

// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

class Solution {
public:
    // 返回从[start,end]区间可抢劫最大金额
    int robHelper(vector<int>& arr,int start,int end){
        vector<int> dp(end+1,0);
        dp[start] = arr[start];
        dp[start+1] = max(arr[start],arr[start+1]);
        for(int i=start+2;i<=end;++i){
            dp[i] = max(dp[i-2]+arr[i],dp[i-1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size==1){
            return nums[0];
        }else if(size==2){
            return max(nums[0],nums[1]);
        }
        // 比较[1,n-1]和[0,n-2]的可抢最大金额
        int incFirst = robHelper(nums,0,size-2);
        int excFirst = robHelper(nums,1,size-1);
        return max(incFirst,excFirst);        
    }
};