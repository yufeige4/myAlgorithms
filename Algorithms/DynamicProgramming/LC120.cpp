#include <bits/stdc++.h>

using namespace std;

// 120. 三角形最小路径和

// 给定一个三角形 triangle ，找出自顶向下的最小路径和。

// 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

// 也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

class Solution {
public:
    // DP + 空间复杂度O(n^2)
    int minimumTotal1(vector<vector<int>>& triangle) {
        int depth = triangle.size();
        auto dp = triangle;
        for(int i=1;i<depth;++i){
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            for(int j=1;j<i;++j){
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i-1][i-1] +  triangle[i][i];
        }

        int minTotal = dp[depth-1][0];
        for(int i=0;i<depth;++i){
            minTotal = dp[depth-1][i]<minTotal ? dp[depth-1][i] : minTotal;
        }

        return minTotal;
    }

    // DP + O(n)空间优化
    int minimumTotal2(vector<vector<int>>& triangle) {
        int depth = triangle.size();
        int dp[depth];
        memset(dp,0,sizeof(dp));
        dp[0] = triangle[0][0];
        for(int i=1;i<depth;++i){
            // 从后往前更新 更新当前层的数据同时保留上一层需要的数据
            dp[i] = dp[i-1] + triangle[i][i];
            for(int j=i-1;j>=1;--j){
                dp[j] = min(dp[j],dp[j-1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }

        int minTotal = dp[0];
        for(int i=0;i<depth;++i){
            minTotal = dp[i]<minTotal ? dp[i] : minTotal;
        }

        return minTotal;
    }
};

