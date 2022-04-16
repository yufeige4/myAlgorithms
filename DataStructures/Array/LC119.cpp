#include <bits/stdc++.h>

using namespace std;

// 119. 杨辉三角 II

// 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。

class Solution {
public:
    // DP
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1,1);
        for(int m=1;m<=rowIndex;++m){
            dp[m] = 1L*dp[m-1]*(rowIndex-m+1)/m;
        }
        return dp;
    }
};