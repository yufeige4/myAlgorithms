#include <bits/stdc++.h>

using namespace std;

// 17. 电话号码的字母组合

// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

class Solution {
public:
    unordered_map<char,string> hash = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    void backtrack(string& digits,vector<string>& result,string& temp,int &n,int i){
        if(i==n){
            result.push_back(temp);
        }
        string str = hash[digits[i]];
        for(auto& ch : str){
            temp.push_back(ch);
            backtrack(digits,result,temp,n,i+1);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int size = digits.size();
        if(size==0){
            return result;
        }
        string temp;
        backtrack(digits,result,temp,size,0);

        return result;
    }
};