#include <bits/stdc++.h>

using namespace std;

// 200. 岛屿数量

// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。

class Solution {
public:
    int directX[4] = {-1,1,0,0};
    int directY[4] = {0,0,-1,1};

    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int& m,int& n,int x,int y){
        if(visited[x][y]==1){
            return;
        }
        visited[x][y] = 1;
        int newX,newY;
        for(int i=0;i<4;++i){
            newX = x + directX[i];
            newY = y + directY[i];
            if(newX>=0&&newX<m&&newY>=0&&newY<n){
                if(grid[newX][newY]=='1'){
                    dfs(grid,visited,m,n,newX,newY);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(visited[i][j]==0&&grid[i][j]=='1'){
                    ++count;
                    dfs(grid,visited,m,n,i,j);
                }
            }
        }

        return count;
    }
};