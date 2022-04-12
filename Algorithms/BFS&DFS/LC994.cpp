#include <bits/stdc++.h>

using namespace std;

// 994. 腐烂的橘子

// 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：

// 值 0 代表空单元格；
// 值 1 代表新鲜橘子；
// 值 2 代表腐烂的橘子。
// 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

// 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

class Solution {
public:

    int directX[4] = {-1,1,0,0};
    int directY[4] = {0,0,-1,1};

    // BFS + 污染算法 从污染源点开始遍历
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> myQ;
        vector<vector<int>> result(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==2){
                    myQ.push({i,j});
                }else if(grid[i][j]==1){
                    result[i][j] = -1;
                    ++count;
                }
            }
        }
        if(count==0) return 0;
        int maxVal = 0;
        int x, y, newX, newY, temp;
        while(!myQ.empty()){
            x = myQ.front().first;
            y = myQ.front().second;
            myQ.pop();
            for(int i=0;i<4;++i){
                newX = x + directX[i];
                newY = y + directY[i];
                if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1){
                    temp = 1 + result[x][y];
                    result[newX][newY] = temp;
                    maxVal = maxVal<temp ? temp : maxVal;
                    grid[newX][newY] = 2;
                    --count;
                    myQ.push({newX,newY});
                }
            }
        }
        return count>0 ? -1 : maxVal;
    }
};