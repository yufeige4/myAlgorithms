#include <bits/stdc++.h>

using namespace std;

// 209. 长度最小的子数组

// 给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。

// 如果不存在符合条件的子数组，返回 0 。

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int len = 0;
        int temp = 0;
        int start = 0;
        int end = 0;
        int size = nums.size();
        while(end<size){
            temp += nums[end];
            while(start<=end&&temp>=target){
                len = end-start+1;
                if(len<minLen) minLen = len;
                temp -= nums[start];
                ++start;
            }
            ++end;
        }
        minLen = minLen==INT_MAX ? 0 : minLen;
        return minLen;
    }
};