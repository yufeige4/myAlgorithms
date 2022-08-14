#include <bits/stdc++.h>

using namespace std;

// 1422. 分割字符串的最大得分

// 给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即 左 子字符串和 右 子字符串）所能获得的最大得分。

// 「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。

class Solution {
public:
    // 两次遍历
    int maxScore(string s) {
        int size = s.size();
        int score = s[0]=='0' ? 1 : 0;
        for(int j=size-1;j>0;--j){
            if(s[j]=='1'){
                ++score;
            }
        }
        int maxScore = score;
        for(int i=1;i<size-1;++i){
            if(s[i]=='0'){
                ++score;
            }else{
                --score;
            }
            maxScore=max(maxScore,score);
        }
        return maxScore;
    }
};