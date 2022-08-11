#include <bits/stdc++.h>

using namespace std;

// 1417. 重新格式化字符串

// 给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。

// 请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。

// 请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 。

class Solution {
public:
    string reformat(string s) {
        vector<char> numIndices;
        vector<char> charIndices;

        for(const auto& ch : s){
            if(ch>='a'&&ch<='z'){
                charIndices.push_back(ch);
            }else{
                numIndices.push_back(ch);
            }
        }
        
        int m = numIndices.size();
        int n = charIndices.size();
        
        if(abs(m-n)>1) return "";

        string result;
        int i = 0;
        int j = 0;
        bool flag = m-n>=0;
        while(i<m&&j<n){
            if(flag){
                result.push_back(numIndices[i]);
                ++i;
                flag = !flag;
            }else{
                result.push_back(charIndices[j]);
                ++j;
                flag = !flag;
            }
        }
        if(i<m){
            result.push_back(numIndices[i]);
        }else{
            result.push_back(charIndices[j]);
        }
        return result;
    }
};