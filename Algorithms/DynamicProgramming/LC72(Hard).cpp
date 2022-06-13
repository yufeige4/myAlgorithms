#include <bits/stdc++.h>

using namespace std;

// 72. 编辑距离

// 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

// 你可以对一个单词进行如下三种操作：
// 插入一个字符
// 删除一个字符
// 替换一个字符

class Solution {
public:
    // 考虑text2不变 只修改text1
    int minDistance(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // 表示区间text1[0,i]和区间text2[0,j]所需要的操作数
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // 和空字符串所需操作次数为此字符长度
        for(int i=1;i<=m;++i){
            dp[i][0] = i;
        }
        for(int i=1;i<=n;++i){
            dp[0][i] = i;
        }

        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(text1[i-1]==text2[j-1]){
                    // 结果和word1和word2分别去掉i-1和j-1位一样
                    // 继承前一位
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    // 可以修改text1使该位相同
                    // 可由删除(dp[i-i][j])或添加(dp[i][j-1])或替换(dp[i-1][j-1])得来
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }
        }
        return dp[m][n];
    }
};