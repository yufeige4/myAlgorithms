#include <bits/stdc++.h>

using namespace std;

// 130. 被围绕的区域

// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

// 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 

// 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。

// 如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

class Solution {
public:
    int directX[4] = {0,-1,0,1};
    int directY[4] = {-1,0,1,0};

    void dfs(vector<vector<char>>& board,int& m,int& n,int x,int y){
        if(x<0||x>=m||y<0||y>=n||board[x][y]!='O'){
            return;
        }
        board[x][y] = '#';
        int newX,newY;
        for(int i=0;i<4;++i){
            newX = x + directX[i];
            newY = y + directY[i];
            dfs(board,m,n,newX,newY);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        // 对边缘进行dfs将所有被访问到的格子变换为#
        for(int i=0;i<m;++i){
            dfs(board,m,n,i,0);
            dfs(board,m,n,i,n-1);
        }
        for(int j=1;j<n-1;++j){
            dfs(board,m,n,0,j);
            dfs(board,m,n,m-1,j);
        }

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='#'){
                    board[i][j] = 'O';
                }else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};