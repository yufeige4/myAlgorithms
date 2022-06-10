#include <bits/stdc++.h>

using namespace std;

// 300. 最长递增子序列

// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
// 例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

class Solution {
public:
    // DP O(n^2)
    int lengthOfLIS1(vector<int>& nums) {
        int size = nums.size();
        // 以该元素为结尾的序列最大长度
        vector<int> dp(size,1);
        for(int j=1;j<size;++j){
            for(int i=0;i<j;++i){
                if(nums[j]>nums[i]){
                    dp[j] = max(dp[i]+1,dp[j]);
                }
            }
        }
        int maxLen = 1;
        for(int i=0;i<size;++i){
            maxLen = max(maxLen,dp[i]);
        }
        return maxLen;
    }
    // 二分查找并更新
    // find position that lastEle[i-1]<val<lastEle[i] and make lastEle[i]
    void update(vector<int>& lastEle,int maxLen,int val){
        int left = 1;
        int right = maxLen;
        while(left<right){
            int mid = left+(right-left)/2;
            if(val<=lastEle[mid]){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        lastEle[right] = val;
    }
    // 贪心+二分 O(nlogn)
    int lengthOfLIS2(vector<int>& nums) {
        int size = nums.size();
        int maxLen = 0;
        // min last element for each length
        vector<int> lastEle(size+1,INT_MIN);
        for(int i=0;i<size;++i){
            if(nums[i]>lastEle[maxLen]){
                ++maxLen;
                lastEle[maxLen] = nums[i];
            }else{
                update(lastEle,maxLen,nums[i]);
            }
        }
        return maxLen;
    }
};