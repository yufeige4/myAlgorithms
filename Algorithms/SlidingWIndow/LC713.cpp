#include <bits/stdc++.h>

using namespace std;

// 713. 乘积小于 K 的子数组

// 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0;
        int size = nums.size();
        int start = 0;
        int end = 0;
        int temp = 1;
        while(end<size){
            temp *= nums[end];
            while(start<=end&&temp>=k){
                temp /= nums[start];
                ++start;
            }
            // 区间[start,end]中的连续子数组都成立
            // 多出end-start个和nums[end]结合的新连续子数组, 以及nums[end]数本身
            // 共多end-start+1个
            result += end-start+1;
            ++end;
        }
        return result;
    }
};