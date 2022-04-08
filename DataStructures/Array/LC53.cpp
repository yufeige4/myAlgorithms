#include <bits/stdc++.h>

using namespace std;

// 53. 最大子数组和

// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 子数组 是数组中的一个连续部分。

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // dp 
        int temp = 0;
        int maxVal  = INT_MIN;
        for(const auto &i : nums){
            temp = max(temp+i,i);
            maxVal = max(temp,maxVal);
        }
        return maxVal;
    }
};