#include <bits/stdc++.h>

using namespace std;

// 73. 矩阵置零
// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m<1){
            return;
        }
        int n = matrix[0].size();
        int horizon[m];
        int vertical[n];
        memset(horizon,0,sizeof(horizon));
        memset(vertical,0,sizeof(vertical));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]==0){
                    horizon[i] = 1;
                    vertical[j] = 1;
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(horizon[i]==1||vertical[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};