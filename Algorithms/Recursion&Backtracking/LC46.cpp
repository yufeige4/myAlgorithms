#include <bits/stdc++.h>

using namespace std;

// 46. 全排列

// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

class Solution {
public:
    void backtrack(vector<int>& arr, vector<int>& temp, vector<int>& visited, vector<vector<int>>& result){
        int size = arr.size();
        if(temp.size()==size){
            result.push_back(temp);
            return;
        }

        int curr;
        for(int i=0;i<size;++i){
            if(visited[i]==0){
                temp.push_back(arr[i]);
                visited[i] = 1;
                backtrack(arr,temp,visited,result);
                //还原
                temp.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        vector<int> temp;
        vector<int> visited(size,0);

        backtrack(nums,temp,visited,result);
        return result;
    }
};