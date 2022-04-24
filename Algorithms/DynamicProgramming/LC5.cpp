#include <bits/stdc++.h>

using namespace std;

// 5. 最长回文子串

// 给你一个字符串 s，找到 s 中最长的回文子串。

class Solution {
public:

    // dp
    string longestPalindrome1(string s) {
        int size = s.size();
        if(size<2) return s;
        int dp[size][size];
        memset(dp,0,sizeof(dp));
        int maxLen = 1;
        int start = 0;

        // dp记录子串[i,j]是否为回文
        for(int i=0;i<size;++i){
            dp[i][i] = 1;
            if(i+1<size&&s[i]==s[i+1]){
                dp[i][i+1] = 1;
                maxLen = 2;
                start = i;
            }
        }

        // 以不同步长l对不同起点i进行遍历
        for(int l=3;l<=size;++l){
            for(int i=0;i+l-1<size;++i){
                int j = i+l-1;
                if(s[i]==s[j]&&dp[i+1][j-1]==1){
                    dp[i][j] = 1;
                    maxLen = l;
                    start = i;
                }
            }

        }
        return s.substr(start,maxLen);
        
    }
    // 中心扩散法
    int expandFromMiddle(string& s,int left,int right,int len){
        if(left>right) return 0;
        while(left>=0&&right<len&&s[left]==s[right]){
            --left;
            ++right;
        }
        return right-left-1;
    }
    string longestPalindrome2(string s) {
        int size = s.size();
        if(size<2) return s;
        int start = 0;
        int maxLen = 1;
        int len,len1,len2;

        for(int i=0;i<size;++i){
            len1 = expandFromMiddle(s,i,i,size);
            len2 = expandFromMiddle(s,i,i+1,size);
            len = len1>len2 ? len1 : len2;
            if(len>maxLen){
                maxLen = len;
                start = i - (len-1)/2;
            }
        }

        return s.substr(start,maxLen);
        
    }
};


