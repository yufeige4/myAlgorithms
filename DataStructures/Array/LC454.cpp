#include <bits/stdc++.h>

using namespace std;

// 454. 四数相加 II

// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

class Solution {
public:
    // 分组 再利用hash
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> hash12;
        int count = 0;
        // 将num1+num2看作一个整体
        for(auto& num1 : nums1){
            for(auto& num2 : nums2){
                ++hash12[num1+num2];
            }
        }
        int target;
        for(auto& num3 : nums3){
            for(auto& num4 : nums4){
                target = 0 - num3 - num4;
                if(hash12.find(target)!=hash12.end()){
                    count += hash12[target];
                }
            }
        }

        return count;
    }
};