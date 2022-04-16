#include <bits/stdc++.h>

using namespace std;

// 59. 螺旋矩阵 II

// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

class Solution {
public:

    int directV[4] = {0,1,0,-1};
    int directH[4] = {1,0,-1,0};

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int direct = 0;
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int count = 0;
        while(top<=bottom&&left<=right){
            if(direct==0){
                for(int j=left;j<=right;++j){
                    matrix[top][j] = ++count;
                }
                ++top;
            }else if(direct==1){
                for(int i=top;i<=bottom;++i){
                    matrix[i][right] = ++count;
                }
                --right;
            }else if(direct==2){
                for(int j=right;j>=left;--j){
                    matrix[bottom][j] = ++count;
                }
                --bottom;
            }else{
                for(int i=bottom;i>=top;--i){
                    matrix[i][left] = ++count;
                }
                ++left;
            }
            direct = (direct+1)%4;
        }
        return matrix;
    }
};
