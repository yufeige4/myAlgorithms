#include <bits/stdc++.h>

using namespace std;

// 238. 除自身以外数组的乘积

// 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

// 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

class Solution {
public:
    // 计算左右成绩和 O(n)空间复杂度
    vector<int> productExceptSelf1(vector<int>& nums) {
        int size = nums.size();
        vector<int> left(size);
        vector<int> right(size);
        vector<int> result(size);
        // 左乘积和
        left[0] = nums[0];
        for(int i=1;i<size;++i){
            left[i] = nums[i]*left[i-1];
        }
        // 右乘积和
        right[size-1] = nums[size-1];
        for(int i=size-2;i>=0;--i){
            right[i] = nums[i]*right[i+1];
        }

        result[0] = right[1];
        result[size-1] = left[size-2];
        for(int i=1;i<size-1;++i){
            result[i] = left[i-1]*right[i+1];
        }
        return result;
    }
    // 常数空间复杂度
    vector<int> productExceptSelf2(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        // 利用输出数组来储存左乘积和
        result[0] = nums[0];
        for(int i=1;i<size;++i){
            result[i] = nums[i]*result[i-1];
        }
        // 利用right来记录右乘积和
        int right = 1;
        // 从右手边遍历
        // 计算right的同时更新输出数组
        for(int j=size-1;j>0;--j){
            result[j] = result[j-1]*right;
            right*= nums[j];
        }
        result[0] = right;
        return result;
    }
};