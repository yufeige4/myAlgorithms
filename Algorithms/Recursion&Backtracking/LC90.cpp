#include <bits/stdc++.h>

using namespace std;

// 90. 子集 II

// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

class Solution {
public:
    // 先排序再利用hash实现去重
    void backtrack(vector<int>& nums,vector<vector<int>>& result,vector<int>& temp,unordered_map<int,int>& hash,int& n,int i){
        if(i==n){
            result.push_back(temp);
            return;
        }
        int val = nums[i];
        temp.push_back(val);
        backtrack(nums,result,temp,hash,n,i+1);

        temp.pop_back();
        // 直接跳到下个不同元素的位置
        backtrack(nums,result,temp,hash,n,hash[val]+1);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 排序
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        int size = nums.size();
        unordered_map<int,int> hash;
        // 利用hash保存每个不同元素最后出现的位置
        for(int i=0;i<size;++i){
            hash[nums[i]] = i;
        }

        backtrack(nums,result,temp,hash,size,0);

        return result;
    }
};