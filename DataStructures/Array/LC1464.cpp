#include <bits/stdc++.h>

using namespace std;

// 1464. 数组中两元素的最大乘积

// 给你一个整数数组 nums，请你选择数组的两个不同下标 i 和 j，使 (nums[i]-1)*(nums[j]-1) 取得最大值。

// 请你计算并返回该式的最大值。

class Solution {
public:
    // sort O(nlogn)
    int maxProduct1(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();

        return (nums[size-1]-1)*(nums[size-2]-1);
    }

    // hold largest and second largest O(n)
    int maxProduct2(vector<int>& nums) {
        int maxNum = nums[0];
        int secondMaxNum = nums[1];
        if(maxNum<secondMaxNum){
            swap(maxNum,secondMaxNum);
        }
        int size = nums.size();
        for(int i=2;i<size;++i){
            int num = nums[i];
            if(num>maxNum){
                secondMaxNum = maxNum;
                maxNum = num;
            }else if(num>secondMaxNum){
                secondMaxNum = num;
            }
        }
        return (maxNum-1)*(secondMaxNum-1);
    }
};