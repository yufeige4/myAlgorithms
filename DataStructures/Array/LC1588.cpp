#include <bits/stdc++.h>

using namespace std;

// 1588. 所有奇数长度子数组的和

// 给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

// 子数组 定义为原数组中的一个连续子序列。

// 请你返回 arr 中 所有奇数长度子数组的和 。

class Solution {
public:
    // 前缀和+暴力 O(n^2)
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size();
        int result = 0;
        int temp = 0;
        vector<int> prefixSum(size+1,0);
        for(int i=0;i<size;++i){
            prefixSum[i+1] = prefixSum[i]+arr[i];
        }
        for(int right=1;right<=size;++right){
            for(int left=0;left<right;++left){
                if((right-left)%2!=0){
                    result += prefixSum[right]-prefixSum[left];
                }
            }
        }
        return result;
    }
    // 可以利用数学公式优化到O(n) 未能理解
};