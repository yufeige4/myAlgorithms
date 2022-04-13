#include <bits/stdc++.h>

using namespace std;

// 28. 实现 strStr()

// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

class Solution {
public:
    int strStr(string haystack, string needle) {
        int sizeA = haystack.size();
        int sizeB = needle.size();
        int len = sizeA - sizeB + 1;
        if(sizeB==0) return 0;
        for(int i=0;i<len;++i){
            int j = 0;
            while(j<sizeB){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                ++j;
            }
            if(j==sizeB){
                return i;
            }
        }
        return -1;
    }
};