#include <bits/stdc++.h>

using namespace std;

// 118. 杨辉三角
// 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows,vector<int>());
        result[0].push_back(1);
        int count;
        for(int i=1;i<numRows;++i){
            count = 0;
            result[i].resize(i+1);
            result[i].assign(i+1,1);
            // 完全模拟
            for(int j=1;j<i;++j){
                result[i][j] = result[i-1][count]+result[i-1][count+1];
                count++;
            }
        }
        return result;
    }
};