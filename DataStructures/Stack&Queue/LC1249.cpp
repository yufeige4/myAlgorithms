#include <bits/stdc++.h>

using namespace std;

// 1249. 移除无效的括号

// 给你一个由 '('、')' 和小写字母组成的字符串 s。

// 你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。

// 请返回任意一个合法字符串。

// 有效「括号字符串」应当符合以下 任意一条 要求：

// 空字符串或只包含小写字母的字符串
// 可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
// 可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」

class Solution {
public:
    string minRemoveToMakeValid1(string s) {
        // 利用辅助符号和一个额外的string temp以及stack实现
        string temp,result;
        int i = 0;
        stack<int> stk;
        for(const auto& ch : s){
            if(ch!='('&&ch!=')'){
                temp.push_back(ch);
                ++i;
            }else if(ch=='('){
                temp.push_back(' ');
                stk.push(i);
                ++i;
            }else{
                if(stk.empty()){
                    continue;
                }
                temp.push_back(')');
                ++i;
                temp[stk.top()] = '(';
                stk.pop();
            }
        }
        for(const auto& ch : temp){
            if(ch!=' '){
                result.push_back(ch);
            }
        }
        return result;
    }
    // 利用input s节省空间
    string minRemoveToMakeValid2(string s) {
        string result;
        int size = s.size();
        stack<int> stk;
        char ch;
        for(int i=0;i<size;++i){
            ch = s[i];
            if(ch=='('){
                s[i] = ' ';
                stk.push(i);
            }else if(ch==')'){
                if(stk.empty()){
                    s[i] = ' ';
                    continue;
                }
                s[stk.top()] = '(';
                stk.pop();
            }
        }
        for(const auto& ch : s){
            if(ch!=' '){
                result.push_back(ch);
            }
        }
        return result;
    }
};