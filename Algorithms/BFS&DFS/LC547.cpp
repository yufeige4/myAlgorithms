#include <bits/stdc++.h>

using namespace std;

// 547. 省份数量

// 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

// 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

// 给你一个 n x n 的矩阵 isConnected ，
// 其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，
// 而 isConnected[i][j] = 0 表示二者不直接相连。

// 返回矩阵中 省份 的数量。

class Solution {
public:
    // BFS
    int findCircleNum1(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        int count = 0;
        vector<int> visited(size,0);
        queue<int> q;
        int temp;
        for(int i=0;i<size;++i){
            if(visited[i]==0){
                ++count;
                q.push(i);
                while(!q.empty()){
                    temp = q.front();
                    visited[temp] = 1;
                    q.pop();
                    for(int j=0;j<size;++j){
                        if(visited[j]==0&&isConnected[temp][j]==1){
                            q.push(j);
                        }
                    }
                }
            }
        }
        return count;
    }
    // dfs
    void dfs(vector<vector<int>>& isConnected,vector<int>& visited,int& size,int x){
        if(visited[x]==1){
            return;
        }
        visited[x] = 1;
        for(int i=0;i<size;++i){
            if(isConnected[i][x]==1){
                dfs(isConnected,visited,size,i);
            }
        }
    }
    int findCircleNum2(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        int count = 0;
        vector<int> visited(size,0);
        for(int i=0;i<size;++i){
            if(visited[i]==0){
                ++count;
                dfs(isConnected,visited,size,i);
            }
        }
        return count;
    }
};
