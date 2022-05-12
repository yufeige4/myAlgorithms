#include <bits/stdc++.h>

using namespace std;

// 40. 组合总和 II

// 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的每个数字在每个组合中只能使用 一次 。

// 注意：解集不能包含重复的组合。 

class Solution {
public:
    void backtrack(vector<int>& arr,vector<vector<int>>& result,vector<int>& temp,int target,int& n, int idx){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(target<0||idx>=n){
            return;
        }

        for(int i=idx;i<n;++i){
            // 去重，保证同一个数在同一层中不会被重复选择
            if(i>idx && arr[i]==arr[i-1]){
                continue;
            }
            temp.push_back(arr[i]);
            backtrack(arr,result,temp,target-arr[i],n,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        int size = candidates.size();
        backtrack(candidates,result,temp,target,size,0);

        return result;
    }
};