#include <bits/stdc++.h>

using namespace std;

// 325. 和等于 k 的最长子数组长度
// 给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长连续子数组长度。
// 如果不存在任意一个符合要求的子数组，则返回 0。

class Solution {
public:
    // 前缀和+暴力枚举 超时
    int maxSubArrayLen1(vector<int>& nums, int k) {
        int maxLen = 0;
        int size = nums.size();
        vector<int> prefixSum(size+1,0);
        for(int i=1;i<=size;++i){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        int len = 0;
        for(int i=0;i<=size;++i){
            for(int j=i;j<=size;++j){
                if(prefixSum[j]-prefixSum[i]==k){
                    len = j-i;
                    maxLen = len>maxLen ? len : maxLen;
                }
            }
        }
        return maxLen;
    }
    // 前缀和+hash优化
    int maxSubArrayLen(vector<int>& nums, int k) {
        int maxLen = 0;
        int size = nums.size();
        // 用sum表示包含该数的和
        long sum = 0;
        // <第i个数之前的前缀和,i>
        unordered_map<long,int> hash(size+1);
        hash[0] = 0;
        for(int i=0;i<size;++i){
            sum += nums[i];
            if(hash.count(sum-k)>0){
                // 若存在[a,b]的和为k,即sum[b]-prefixSum[a]==k
                maxLen = max(i-hash[sum-k]+1,maxLen);
            }
            // 保存该前缀和
            // 若存在相同的前缀和只保存之前出现的
            hash.insert(make_pair(sum,i+1));
        }

        return maxLen;
    }
};