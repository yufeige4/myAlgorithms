#include <bits/stdc++.h>

using namespace std;

// 784. 字母大小写全排列

// 给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，我们可以获得一个新的字符串。

// 返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。

class Solution {
public:
    void backtrack(string& str, vector<string>& result, int curr, int size){
        if(curr==size){
            result.push_back(str);
            return;
        }
        
        char ch = str[curr];
        // 非字母时
        if(ch>='0'&&ch<='9'){
            backtrack(str,result,curr+1,size);
            return;
        }

        // ch为字母
        // 不变
        backtrack(str,result,curr+1,size);
        // 转变大小写
        str[curr] += ch>'Z' ? -32 : 32;
        backtrack(str,result,curr+1,size);
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        int size = s.size();
        backtrack(s,result,0,size);

        return result;
    }
};