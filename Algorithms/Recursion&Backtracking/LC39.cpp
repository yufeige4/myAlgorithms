#include <bits/stdc++.h>

using namespace std;

// 39. 组合总和

// 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。

// 你可以按 任意顺序 返回这些组合。

// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。

class Solution {
public:
    void backtrack(vector<int>& arr,vector<vector<int>>& result,vector<int>& temp,int target,int& n,int idx){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(target<0||idx>=n){
            return;
        }
        // 选该数，保持原地
        temp.push_back(arr[idx]);
        backtrack(arr,result,temp,target-arr[idx],n,idx);
        // 不选该数，继续下一个数
        temp.pop_back();
        backtrack(arr,result,temp,target,n,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int size = candidates.size();
        backtrack(candidates,result,temp,target,size,0);

        return result;
    }
};