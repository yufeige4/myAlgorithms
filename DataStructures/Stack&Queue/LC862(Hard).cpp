#include <bits/stdc++.h>

using namespace std;

// 862. 和至少为 K 的最短子数组

// 给你一个整数数组 nums 和一个整数 k ，找出 nums 中和至少为 k 的 最短非空子数组 ，并返回该子数组的长度。
// 如果不存在这样的 子数组 ，返回 -1 。

// 子数组 是数组中 连续 的一部分。

class Solution {
public:
    // 前缀和+暴力破 超时
    int shortestSubarray1(vector<int>& nums, int k) {
        int minLen = INT_MAX;
        int size = nums.size();
        vector<long long> prefixSum(size+1,0);
        for(int i=0;i<size;++i){
            prefixSum[i+1] = prefixSum[i]+nums[i];
        }
        for(int i=0;i<=size;++i){
            for(int j=0;j<i;++j){
                if(i-j>minLen){
                    continue;
                }
                if(prefixSum[i]-prefixSum[j]>=k){
                    minLen = min(minLen,i-j);
                }
            }
        }
        return minLen==INT_MAX ? -1 : minLen;
    }

    // 由于 性质：1) 若x2>x1且prefixSum[x2]<=prefixSum[x1], 则x1必然不为对于某一y的最优解
    //          2) 若某一y的最优解为x，则x再也需要考虑，因为即便为其他y的最优解，也不会是最小值(从左往右遍历)
    int shortestSubarray2(vector<int>& nums, int k) {
        int minLen = INT_MAX;
        int size = nums.size();
        vector<long long> prefixSum(size+1,0);
        for(int i=0;i<size;++i){
            prefixSum[i+1] = prefixSum[i]+nums[i];
        }
        // 单调递增双端队列
        deque<int> myQ;
        for(int i=0;i<=size;++i){
            while(!myQ.empty() && prefixSum[i]-prefixSum[myQ.front()]>=k){
                // 当前和满足条件 将队列左出 性质2
                minLen = min(minLen,i-myQ.front());
                myQ.pop_front();
            }
            while(!myQ.empty() &&  prefixSum[i]<=prefixSum[myQ.back()]){
                // 当前新加入的元素不满足递增 将队列右出直到满足递增 性质1
                myQ.pop_back();
            }
            myQ.push_back(i);
        }
        return minLen!=INT_MAX ? minLen : -1;
    }
};