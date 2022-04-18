#include <bits/stdc++.h>

using namespace std;

// 560. 和为 K 的子数组

// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int count = 0;
        // 利用leftSum来计算左加和
        int leftSum = 0;
        // hash存储 加和与出现次数的map
        unordered_map<int,int> hash;
        hash[0] = 1;
        for(int i=0;i<size;++i){
            leftSum += nums[i];
            // 若满足leftSum[right]-leftSum[left-1]==k
            // 则该子数组符合条件
            if(hash.find(leftSum-k)!=hash.end()){
                count+=hash[leftSum-k];
            }
            // 将左加和存入map
            hash[leftSum]++;
        }
        return count;
    }
};