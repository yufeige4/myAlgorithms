#include <bits/stdc++.h>

using namespace std;

// 79. 单词搜索

// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

class Solution {
public:
    int directX[4] = {0,1,0,-1};
    int directY[4] = {1,0,-1,0};

    bool dfs(vector<vector<char>>& board,vector<vector<int>>& visited,string& word,int& k,int i,int& m,int& n,int x,int y){
        if(x<0 || x>=m || y<0 || y>=n || visited[x][y]==1 || board[x][y]!=word[i]){
            return false;
        }
        if(i+1==k){
            return true;
        }
        visited[x][y] = 1;
        bool result = false;
        int newX,newY;
        for(int j=0;j<4;++j){
            newX = x + directX[j];
            newY = y + directY[j];
            result = result || dfs(board,visited,word,k,i+1,m,n,newX,newY);
        }
        visited[x][y] = 0;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int size = word.size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        bool result = false;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                result = result || dfs(board,visited,word,size,0,m,n,i,j);
            }
        }
        return result;
    }
};