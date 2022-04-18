#include <bits/stdc++.h>

using namespace std;

// 290. 单词规律

// 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

class Solution {
public:
    // 双hash
    bool wordPattern(string pattern, string s) {
        int sizeA = pattern.size();
        int sizeB = s.size();
        unordered_map<char,string> hash1;
        unordered_map<string,char> hash2;
        int index = 0;
        int i = 0;
        int j;
        while(i<sizeB&&index<sizeA){
            j = i;
            while(j<sizeB&&s[j]!=' '){
                ++j;
            }
            int len = j-i;
            char ch = pattern[index];
            ++index;
            string word = s.substr(i,len);
            if(hash1.find(ch)==hash1.end()){
                hash1[ch] = word;
            }else if(hash1[ch]!=word){
                return false;
            }
            if(hash2.find(word)==hash2.end()){
                hash2[word] = ch;
            }else if(hash2[word]!=ch){
                return false;
            }
            i = j+1;
        }
        return i>=sizeB&&index>=sizeA;
    }
};