#include <bits/stdc++.h>

using namespace std;

// 1252. 奇数值单元格的数目
// 给你一个 m x n 的矩阵，最开始的时候，每个单元格中的值都是 0。

// 另有一个二维索引数组?indices，indices[i] = [ri, ci] 指向矩阵中的某个位置，其中 ri 和 ci 分别表示指定的行和列（从 0 开始编号）。

// 对 indices[i] 所指向的每个位置，应同时执行下述增量操作：

// ri 行上的所有单元格，加 1 。
// ci 列上的所有单元格，加 1 。
// 给你 m、n 和 indices 。请你在执行完所有?indices?指定的增量操作后，返回矩阵中 奇数值单元格 的数目。

class Solution {
public:
    // 直接模拟 O(q*m*n+m*n)
    int oddCells1(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(m,vector<int>(n,0));
        for(auto& index : indices){
            for(int i=0;i<n;++i){
                matrix[index[0]][i]++;
            }
            for(int i=0;i<m;++i){
                matrix[i][index[1]]++;
            }
        }
        int result = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]%2!=0){
                    result++;
                }
            }
        }
        return result;
    }
    // 空间模拟优化 O(q+m*n)
    int oddCells2(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m,0);
        vector<int> cols(n,0);
        for(auto& index : indices){
            rows[index[0]]++;
            cols[index[1]]++;
        }
        int result = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if((rows[i]+cols[j])%2!=0){
                    result++;
                }
            }
        }
        return result;
    }
    // 根据容斥原理进行计数优化
    int oddCells3(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m,0);
        vector<int> cols(n,0);
        for(auto& index : indices){
            rows[index[0]]++;
            cols[index[1]]++;
        }
        int oddRows = 0;
        int oddCols = 0;
        for(int i=0;i<m;++i){
            if(rows[i]%2){
                ++oddRows;
            }
        }
        for(int i=0;i<n;++i){
            if(cols[i]%2){
                ++oddCols;
            }
        }
        int evenRows = m - oddRows;
        int evenCols = n - oddCols;
        return evenCols*oddRows+oddCols*evenRows;
    }
};