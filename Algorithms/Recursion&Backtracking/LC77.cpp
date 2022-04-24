#include <bits/stdc++.h>

using namespace std;

// 77. 组合

// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

// 你可以按 任何顺序 返回答案。

class Solution {
public:

    void dfs(vector<vector<int>>& result,vector<int>& temp,int curr,int n,int k){
        // 范围小于需选择数的数量 剪枝
        if(temp.size()+n-curr+1<k){
            return;
        }
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
        // 多余判断 可删除
        // if(curr==n+1){
        //     return;
        // }
        
        // 选择此数
        temp.push_back(curr);
        dfs(result,temp,curr+1,n,k);
        
        // 不选此数
        temp.pop_back();
        dfs(result,temp,curr+1,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(result,temp,1,n,k);

        return result;
    }
};