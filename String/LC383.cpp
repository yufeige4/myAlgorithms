#include <bits/stdc++.h>

using namespace std;

// 383. 赎金信

// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

// 如果可以，返回 true ；否则返回 false 。

// magazine 中的每个字符只能在 ransomNote 中使用一次。

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int sizeA = ransomNote.size();
        int sizeB = magazine.size();
        int hash[26];
        int index;
        memset(hash,0,sizeof(hash));
        for(int i=0;i<sizeB;++i){
            index = magazine[i] - 'a';
            ++hash[index];
        }

        for(int i=0;i<sizeA;++i){
            index = ransomNote[i] - 'a';
            --hash[index];
            if(hash[index]<0){
                return false;
            }
        }
        return true;
    }
};