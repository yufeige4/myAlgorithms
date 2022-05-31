#include <bits/stdc++.h>

using namespace std;

// 214. 最短回文串

// 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。


class Solution {
public:
    // KMP算法获取next数组
    vector<int> getNext(string& pattern){
        int size = pattern.size();
        // next[0] = -1
        vector<int> next(size,-1);
        
        for(int i=1;i<size;++i){
            // 上一位匹配字符失败该去的位置k
            int k = next[i-1];
            while(k!=-1 && pattern[k+1]!=pattern[i]){
                k = next[k];
            }
            // 位置k的字符与当前匹配字符相同时
            // 直接去k的下一位字符
            if(pattern[i]==pattern[k+1]){
                next[i] = k+1;
            }
        }
        return next;
    }

    string shortestPalindrome(string s) {
        int size = s.size();
        vector<int> next = getNext(s);
        // 利用KMP算法 找到从左端开始的最长回文串
        // 从右往左遍历把s当作是反序s'
        // s的前bestIndex个字符与s‘的后bestIndex个字符相匹配
        int bestIndex = -1;
        for(int i=size-1;i>=0;--i){
            while(bestIndex!=-1 && s[bestIndex+1]!=s[i]){
                bestIndex = next[bestIndex]; 
            }
            if(s[bestIndex+1]==s[i]){
                ++bestIndex;
            }
        }
        // add为从最长回文串右边剩余字符的反序
        // 将之加在原字符串左边即为最短回文串
        string add = (bestIndex == size - 1 ? "" : s.substr(bestIndex + 1, size));
        reverse(add.begin(), add.end());
        return add + s;
    }
};