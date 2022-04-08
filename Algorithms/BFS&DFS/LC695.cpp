#include <bits/stdc++.h>

using namespace std;

// 695. 岛屿的最大面积

// 给你一个大小为 m x n 的二进制矩阵 grid 。

// 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

// 岛屿的面积是岛上值为 1 的单元格的数目。

// 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

class Solution {
public:
    int directX[4] = {-1,1,0,0};
    int directY[4] = {0,0,-1,1};

    // DFS + visited
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int m,int n,int x,int y){
        if(visited[x][y]==1){
            return 0;
        }
        visited[x][y] = 1;
        int result = 1;
        int newX,newY;
        for(int i=0;i<4;++i){
            newX = x + directX[i];
            newY = y + directY[i];
            if(newX>=0&&newX<m&&newY>=0&&newY<n){
                if(grid[newX][newY]==1){
                    result += dfs(grid,visited,m,n,newX,newY);
                }
            }
        }
        return result;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int temp;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(visited[i][j]==0&&grid[i][j]==1){
                    temp = dfs(grid,visited,m,n,i,j);
                    maxSize = temp>maxSize ? temp : maxSize;
                }
            }
        }
        return maxSize;
        
    }
};