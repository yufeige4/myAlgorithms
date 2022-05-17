#include <bits/stdc++.h>

using namespace std;

// 45. 跳跃游戏 II

// 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。

// 假设你总是可以到达数组的最后一个位置。

class Solution {
public:
    // 暴力破
    int jump1(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<size;++i){
            int k = nums[i];
            for(int j=i+1;j<=i+k&&j<size;++j){
                dp[j] = min(dp[j],dp[i]+1);
            }
        }
        return dp[size-1];
    }
    // 贪心 + dp
    int jump(vector<int>& nums) {
        int end = nums.size()-1;
        int maxDistance = 0;
        int jumpIndex = 0;
        int count = 0;
        // 无需访问最后一个台阶
        for(int i=0;i<end;++i){
            // 更新可跳跃距离
            maxDistance = max(maxDistance,i+nums[i]);
            // 到达了跳跃前的最远距离
            if(i==jumpIndex){
                // 更新目前可跳跃最远距离为下次跳跃前的最远距离
                jumpIndex = maxDistance;
                ++count;
            }
        }
        return count;
    }
};