#include <bits/stdc++.h>

using namespace std;

// 44. 通配符匹配

// 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

// '?' 可以匹配任何单个字符。
// '*' 可以匹配任意字符串（包括空字符串）。
// 两个字符串完全匹配才算匹配成功。

// 说明:

// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。





class Solution {
public:
    // 递归 正确但超时
    bool matchHelper(string& s,string& p,int& m,int& n,int x,int y){
        if(x>=m&&y>=n){
            return true;
        }else if(y>=n){
            return false;
        }else if(x>=m){
            if(p[y]=='*'){
                while(y<n&&p[y]=='*'){
                    ++y;
                }
                return matchHelper(s,p,m,n,x,y);
            }else{
                return false;
            }
        }
        char ch_s = s[x];
        char ch_p = p[y];
        // 判断ch_p是否为'*'
        if(ch_p=='*'){
            // 若ch_p为最后一个字符
            if(y+1==n){
                return true;
            }
            char ch_next_p = p[y+1];
            if(ch_next_p=='*'){
                return matchHelper(s,p,m,n,x,y+1);
            }else if(ch_next_p!='?'){
                // 找到与p中下一位字符匹配的s位字符
                while(x+1<m&&s[x]!=ch_next_p){
                    ++x;
                }
            }
            return matchHelper(s,p,m,n,x,y+1) || matchHelper(s,p,m,n,x+1,y);
        }
        return (ch_s==ch_p||ch_p=='?') && matchHelper(s,p,m,n,x+1,y+1);
    }
    bool isMatch1(string s, string p) {
        int m = s.size();
        int n = p.size();
        return matchHelper(s,p,m,n,0,0);
    }

    // 我的DP
    bool isMatch2(string s, string p) {
        int m = s.size();
        int n = p.size();
        if(m==0&&n==0){
            return true;
        }else if(m==0){
            while(n-1>=0){
                if(p[n-1]!='*'){
                    return false;
                }
                --n;
            }
            return true;
        }else if(n==0){
            return false;
        }
        // 假设dp[i][j]表示 s[i,m-1] p[j,n-1] 的匹配结果
        vector<vector<bool>> dp(m,vector<bool>(n,false));
        // 最后一位字符匹配
        dp[m-1][n-1] = p[n-1]=='*' || p[n-1]=='?' || s[m-1]==p[n-1];
        // 最后一位不匹配直接返回
        if(!dp[m-1][n-1]) return false;
        // 初始化dp
        for(int i=m-2;i>=0;--i){
            dp[i][n-1] = p[n-1]=='*';
        }
        // s->p 一对多 是否用掉那唯一一个实体字符
        bool used = p[n-1]!='*';
        for(int j=n-2;j>=0;--j){
            if(!dp[m-1][j+1]){
                dp[m-1][j] = false;
            }else if(p[j]=='*'){
                dp[m-1][j] = true;
            }else{
                // 此位不为'*'
                if(!used&&(p[j]=='?'||p[j]==s[m-1])){
                    used = true;
                    dp[m-1][j] = true;
                }else{
                    dp[m-1][j] = false;
                }
            }
        }

        for(int i=m-2;i>=0;--i){
            for(int j=n-2;j>=0;--j){
                char ch_s = s[i];
                char ch_p = p[j];
                if(ch_p=='*'){
                    dp[i][j] = dp[i][j+1] || dp[i+1][j] || dp[i+1][j+1];
                }else{
                    dp[i][j] = (ch_s==ch_p||ch_p=='?') && dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];
    }
    // 其实从dp分配 (m+1)X(n+1)个格子并从前往后遍历更方便
};