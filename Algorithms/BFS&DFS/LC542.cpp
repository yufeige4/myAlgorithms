#include <bits/stdc++.h>

using namespace std;

// 542. 01 矩阵

// 给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

// 两个相邻元素间的距离为 1 。

class Solution {
public:
    int directX[4] = {-1,1,0,0};
    int directY[4] = {0,0,-1,1};

    // BFS + 污染算法
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m,vector<int>(n,0));
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> myQ;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==0){
                    myQ.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        while(!myQ.empty()){
            auto x = myQ.front().first;
            auto y = myQ.front().second;
            myQ.pop();
            for(int i=0;i<4;++i){
                int newX = x + directX[i];
                int newY = y + directY[i];
                if(newX>=0 && newX<m && newY>=0 && newY<n && visited[newX][newY]!=1){
                    result[newX][newY] = 1 + result[x][y];
                    visited[newX][newY] = 1;
                    myQ.push({newX,newY});
                }
            }
        }
        return result;
    }
};