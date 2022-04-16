#include <bits/stdc++.h>

using namespace std;

// 150. 逆波兰表达式求值

// 根据 逆波兰表示法，求表达式的值。

class Solution {
public:

    bool isOperation(const string& str){
        return str.size()==1 && (str[0]<'0' || str[0]>'9');
    }
    int calculate(int left,int right,const string& op){
        char ch= op[0];
        int result = 0;
        switch(ch){
            case '+':
                result = left+right;
                break;
            case '-':
                result = left-right;
                break;
            case '*':
                result = left*right;
                break;
            case '/':
                result = left/right;
        }
        return result;
    }
    int toNum(const string& str){
        int size = str.size();
        bool negSign = str[0]=='-';
        int result = 0;
        for(int i=0;i<size;++i){
            if(negSign&&i==0){
                continue;
            }
            result*= 10;
            result += (str[i]-'0');
        }
        result = negSign ? -result : result;
        return result;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(const auto& token : tokens){
            if(isOperation(token)){
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                stk.push(calculate(left,right,token));
            }else{
                stk.push(toNum(token));
            }          
        }
        return stk.top();
    }
};