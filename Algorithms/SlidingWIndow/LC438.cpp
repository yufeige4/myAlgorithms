#include <bits/stdc++.h>

using namespace std;

// 438. 找到字符串中所有字母异位词

// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

class Solution {
public:
    // 手动hash+优化
    vector<int> findAnagrams(string s, string p) {
        int sizeA = s.size();
        int sizeB = p.size();
        if(sizeB>sizeA){
            return {};
        }
        vector<int> result;
        int hash[26];
        memset(hash,0,sizeof(hash));
        int start = 0;
        int diff = 0;
        for(int i=0;i<sizeB;++i){
            hash[p[i]-'a']++;
            hash[s[i]-'a']--;

        }
        for(int i=0;i<26;++i){
            if(hash[i]!=0){
                ++diff;
            }
        }
        if(diff==0) result.push_back(start); 
        char leftCh,rightCh;
        for(int j=sizeB;j<sizeA;++j){
            leftCh = s[start]-'a';
            rightCh = s[j]-'a';
            if(hash[leftCh]==0){
                ++diff;
            }
            if(hash[rightCh]==0){
                ++diff;
            }
            hash[leftCh]++;
            hash[rightCh]--;
            if(hash[leftCh]==0){
                --diff;
            }
            if(hash[rightCh]==0){
                --diff;
            }
            ++start;
            if(diff==0) result.push_back(start); 
        }

        return result;
    }
};