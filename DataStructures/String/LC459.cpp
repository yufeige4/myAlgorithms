#include <bits/stdc++.h>

using namespace std;

// 459. 重复的子字符串

// 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。


class Solution {
public:
    // O(n^2) 暴力枚举
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        for(int i=0;i<size/2;++i){
            int len = i+1;
            if(size%len!=0) continue;
            int j = 0;
            while(j+len<size){
                if(s[j%len]==s[j+len]){
                    ++j;
                }else{
                    break;
                }
            }
            if(j+len==size) return true;
        }
        return false;
    }

    // 待学习 KMP算法 O(n)
};