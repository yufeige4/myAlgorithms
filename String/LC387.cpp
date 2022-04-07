#include <bits/stdc++.h>

using namespace std;

// 387. 字符串中的第一个唯一字符

// 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。

class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        if(size==1){
            return 0;
        }
        // 手动hash
        int hash[26];
        int index;
        memset(hash,0,sizeof(hash));
        for(int i=0;i<size;++i){
            index = s[i]-'a';
            ++hash[index];
        }

        for(int i=0;i<size;++i){
            index = s[i]-'a';
            if(hash[index]==1){
                return i;
            }
        }
        return -1;
    }
};