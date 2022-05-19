#include <bits/stdc++.h>

using namespace std;

// 583. 两个字符串的删除操作

// 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

// 每步 可以删除任意一个字符串中的一个字符。

class Solution {
public:
    int minDistance(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // 表示区间text1[0,i]和区间text2[0,j]所需要的删除次数
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        // 和空字符串所需删除次数为此字符长度
        for(int i=1;i<=m;++i){
            dp[i][0] = i;
        }
        for(int i=1;i<=n;++i){
            dp[0][i] = i;
        }

        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(text1[i-1]==text2[j-1]){
                    // 无需删除
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    // 选择删除次数少的那一段区间并删除该字符
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        }
        return dp[m][n];
    }
};