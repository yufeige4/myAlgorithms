#include <bits/stdc++.h>

using namespace std;

// 1091. 二进制矩阵中的最短路径

// 给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径 的长度。如果不存在这样的路径，返回 -1 。

// 二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角 单元格（即，(n - 1, n - 1)）的路径，该路径同时满足下述要求：

// 路径途经的所有单元格都的值都是 0 。
// 路径中所有相邻的单元格应当在 8 个方向之一 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。
// 畅通路径的长度 是该路径途经的单元格总数。

class Solution {
public:
    // DFS 超时
    int directX[8] = {-1,0,1,1,1,0,-1,-1};
    int directY[8] = {1,1,1,0,-1,-1,-1,0};
    void dfs(vector<vector<int>>& grid,int& n,int x,int y,int& shortest,int count){
        if(grid[x][y]!=0||count>=shortest){
            return;
        }
        if(x==n-1&&y==n-1){
            shortest = count;
            return;
        }
        grid[x][y] = -1;
        int newX,newY;
        for(int i=0;i<8;++i){
            newX = x + directX[i];
            newY = y + directY[i];
            if(newX>=0&&newY>=0&&newX<n&&newY<n){
                if(grid[newX][newY]==0){
                    dfs(grid,n,newX,newY,shortest,count+1);
                }
            }
        }
        grid[x][y] = 0;
    }
    int shortestPathBinaryMatrix1(vector<vector<int>>& grid) {
        int shortest = INT_MAX;
        int n = grid.size();
        dfs(grid,n,0,0,shortest,1);
        return shortest!=INT_MAX ? shortest : -1;
    }
       
    // BFS
    int bfs(vector<vector<int>>& grid,int& n){
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        grid[0][0] = -1;
        int count = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                auto [x,y] = q.front();
                q.pop();
                if(x==n-1&&y==n-1){
                    return count;
                }
                int newX,newY;
                for(int i=0;i<8;++i){
                    newX = x + directX[i];
                    newY = y + directY[i];
                    if(newX>=0&&newX<n&&newY>=0&&newY<n){
                        if(grid[newX][newY]==0){
                            q.push(make_pair(newX,newY));
                            grid[newX][newY] = -1;
                        }
                    }
                }
            }
            ++count;
        }
        return -1;
    }
    int shortestPathBinaryMatrix2(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n<1||grid[0][0]==1||grid[n-1][n-1]==1){
            return -1;
        }else if(n==1){
            return 1;
        }
        return bfs(grid,n);
    }
};
