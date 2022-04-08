#include <bits/stdc++.h>

using namespace std;

// 977. 有序数组的平方
// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = nums.size()-1;
        vector<int> result = vector<int>(i+1,0);
        int left = 0;
        int right = i;
        int leftVal,rightVal;
        while(i>=0){
            leftVal = nums[left]*nums[left];
            rightVal = nums[right]*nums[right];
            if(leftVal>=rightVal){
                result[i--] = leftVal;
                left++; 
            }else{
                result[i--] = rightVal;
                right--;
            }
        }
        return result;
    }
};