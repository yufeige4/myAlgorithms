#include <bits/stdc++.h>

using namespace std;

// 567. 字符串的排列

// 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。

// 换句话说，s1 的排列之一是 s2 的 子串 。

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sizeA = s1.size();
        int sizeB = s2.size();
        if(sizeA>sizeB){
            return false;
        }
        int correct[26];
        memset(correct,0,sizeof(correct));
        for(int i=0;i<sizeA;++i){
            --correct[s1[i]-'a'];
        }
        int i = 0;
        int ch_index;
        // 滑动窗口，直到正确字符串的窗口大小正好符合要求
        for(int j=0;j<sizeB;++j){
            ch_index = s2[j] - 'a';
            ++correct[ch_index];
            while(correct[ch_index]>0){
                --correct[s2[i]-'a'];
                ++i;
            }
            if(j-i+1==sizeA){
                return true;
            }

        }
        return false;
    }
};