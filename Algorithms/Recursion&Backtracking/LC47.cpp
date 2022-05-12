#include <bits/stdc++.h>

using namespace std;

// 47. 全排列 II

// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>& result,vector<int>& temp,vector<int>& visited,int& n){
        if(temp.size()==n){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<n;++i){
            // 保证了重复值依次填入的顺序是从左到右
            if(visited[i] || (i>0 && nums[i]==nums[i-1] && !visited[i-1])){
                continue;
            }
            
            visited[i] = 1;
            temp.push_back(nums[i]);
            backtrack(nums,result,temp,visited,n);

            visited[i] = 0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int size = nums.size();
        vector<int> temp;
        vector<int> visited(size,0);
        backtrack(nums,result,temp,visited,size);

        return result;
    }
};