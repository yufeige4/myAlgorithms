#include <bits/stdc++.h>

using namespace std;

// 673. 最长递增子序列的个数

// 给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。

// 注意 这个数列必须是 严格 递增的。

class Solution {
public:
    // DP O(n^2)
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size<1) return 0;
        // 以该元素为结尾的最长序列长度
        vector<int> dp(size,1);
        // 以该元素为结尾的最长序列个数
        vector<int> count(size,1);
        int maxLen = 1;
        int maxCount = 0;
        for(int j=1;j<size;++j){
            for(int i=0;i<j;++i){
                if(nums[j]>nums[i]){
                    if(dp[i]+1>dp[j]){
                        dp[j] = dp[i] + 1;
                        count[j] = count[i];
                    }else if(dp[i]+1==dp[j]){
                        count[j] += count[i];
                    }
                }
            }
            maxLen = max(maxLen,dp[j]);
        }
        for(int i=0;i<size;++i){
            if(dp[i]==maxLen){
                maxCount += count[i];
            }
        }
        return maxCount;
    }
    // 可使用LC300的贪心方法实现O(nlogn) 暂未能够理解
};
