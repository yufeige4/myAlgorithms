#include <bits/stdc++.h>

using namespace std;

// 22. 括号生成

// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

class Solution {
public:
    // 根据左括号剩余个数left和右括号剩余个数right进行递归
    void backtrack(vector<string>& result,string& temp,int left,int right){
        // 右括号使用的比左括号多 无论继续怎么添加左括号 都是无效的
        if(left>right){
            return;
        }

        if(left==0&&right==0){
            // n对括号的合法组合
            result.push_back(temp);
            return;
        }else if(left==0){
            // 左括号用完
            temp.push_back(')');
            backtrack(result,temp,left,right-1);
        // 右括号用完 实际并不会出现这个情况
        // }else if(right==0){
        //     temp.push_back('(');
        //     backtrack(result,temp,left-1,right);
        }else{
            // 左右括号都有剩余
            // 先添加左括号
            temp.push_back('(');
            backtrack(result,temp,left-1,right);
            temp.pop_back();
            // 先添加右括号
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