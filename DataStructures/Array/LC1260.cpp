#include <bits/stdc++.h>

using namespace std;

// 1260. 二维网格迁移

// 给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。

// 每次「迁移」操作将会引发下述活动：

// 位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
// 位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
// 位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。
// 请你返回 k 次迁移操作后最终得到的 二维网格。

class Solution {
public:
    // 每次迁移即每个元素向后移动一格
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalNum = m*n;
        k = k%totalNum;
        vector<vector<int>> result(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int prevIdx = (i*n+j+totalNum-k)%totalNum;
                result[i][j] = grid[prevIdx/n][prevIdx%n];
            }
        }

        return result;
    }
};