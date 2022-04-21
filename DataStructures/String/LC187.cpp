#include <bits/stdc++.h>

using namespace std;

// 187. 重复的DNA序列

// DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。

// 例如，"ACGAATTCCG" 是一个 DNA序列 。
// 在研究 DNA 时，识别 DNA 中的重复序列非常有用。

// 给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。你可以按 任意顺序 返回答案。

class Solution {
public:
    // 利用hash O(N*L) L在此题中为10
    vector<string> findRepeatedDnaSequences(string s) {
        int end = s.size()-9;
        unordered_map<string,int> hash;
        vector<string> result;
        for(int i=0;i<end;++i){
            string key = s.substr(i,10);
            // 当次数达到2即为重复序列
            if(++hash[key]==2){
                result.push_back(key);
            }
        }
        return result;
    }
};