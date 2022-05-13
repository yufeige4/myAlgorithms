#include <bits/stdc++.h>

using namespace std;

// 22. 括号生成

// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

class Solution {
public:
    void backtrack(vector<string>& result,string& temp,int left,int right){
        if(left>right){
            return;
        }
        if(left==0&&right==0){
            result.push_back(temp);
            return;
        }else if(left==0){
            temp.push_back(')');
            backtrack(result,temp,left,right-1);
        }else if(right==0){
            temp.push_back('(');
            backtrack(result,temp,left-1,right);
        }else{
            temp.push_back('(');
            backtrack(result,temp,left-1,right);
            temp.pop_back();

            temp.push_back(')');
            backtrack(result,temp,left,right-1);
        }
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str;
        backtrack(result,str,n,n);

        return result;
    }
};