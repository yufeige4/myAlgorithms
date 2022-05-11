#include <bits/stdc++.h>

using namespace std;

// 78. 子集

// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>& result,vector<int>& temp,int& n,int i){
        if(i==n){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        backtrack(nums,result,temp,n,i+1);

        temp.pop_back();
        backtrack(nums,result,temp,n,i+1);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        int size = nums.size();

        backtrack(nums,result,temp,size,0);

        return result;
    }
};