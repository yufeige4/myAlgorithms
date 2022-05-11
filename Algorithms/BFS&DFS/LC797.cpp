#include <bits/stdc++.h>

using namespace std;

// 797. 所有可能的路径

// 给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

//  graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。

class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& result,vector<int>& path,int& target,int p){
        path.push_back(p);
        if(p==target){
            result.push_back(path);
            path.pop_back();
            return;
        }
        int size = graph[p].size();
        for(int i=0;i<size;++i){
            dfs(graph,result,path,target,graph[p][i]);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size()-1;
        vector<vector<int>> result;
        vector<int> path;
        
        dfs(graph,result,path,n,0);

        return result;
    }
};