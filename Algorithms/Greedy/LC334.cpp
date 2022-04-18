#include <bits/stdc++.h>

using namespace std;

// 334. 递增的三元子序列

// 给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

// 如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。

class Solution {
public:
    // 双向遍历 空间复杂度O(n)
    bool increasingTriplet1(vector<int>& nums) {
        int size = nums.size();

        vector<int> leftMin(size);
        leftMin[0] = nums[0];
        for(int i=1;i<size;++i){
            leftMin[i] = leftMin[i-1]>nums[i] ? nums[i] : leftMin[i-1];
        }

        vector<int> rightMax(size);
        rightMax[size-1] = nums[size-1];
        for(int i=size-2;i>=0;--i){
            rightMax[i] = rightMax[i+1] < nums[i] ? nums[i] : rightMax[i+1];
        }
        
        for(int i=1;i<size-1;++i){
            if(nums[i]>leftMin[i-1]&&nums[i]<rightMax[i+1]){
                return true;
            }
        }
        return false;
    }
    // 贪心 空间复杂度O(1)
    bool increasingTriplet2(vector<int>& nums) {
        int size = nums.size();
        if(size<3)  return false;
        int i = nums[0];
        int j = INT_MAX;
        int temp;
        for(int x=1;x<size;++x){
            temp = nums[x];
            if(temp>j){
                return true;
            }else if(temp<=i){
                i = temp;
            }else{
                j = temp;
            }
        }
        return false;
    }
};