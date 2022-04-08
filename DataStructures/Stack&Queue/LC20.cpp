#include <bits/stdc++.h>

using namespace std;

// 20. 有效的括号

// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。

class Solution {
public:
    bool isValid1(string s) {
        stack<char> stk;

        for(const auto& ch:s){
            switch(ch){
                case '(':
                case '{':
                case '[':
                    stk.push(ch);
                    break;
                case ')':
                    if(!stk.empty()&&stk.top()=='('){
                        stk.pop();
                        break;
                    }else{
                        return false;
                    }
                case '}':
                    if(!stk.empty()&&stk.top()=='{'){
                        stk.pop();
                        break;
                    }else{
                        return false;
                    }
                case ']':
                    if(!stk.empty()&&stk.top()=='['){
                        stk.pop();
                        break;
                    }else{
                        return false;
                    }
                default:
                    return false;
            }
        }
        return stk.empty();
    }

    // 更聪明的写法
    bool isValid2(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop();
        }
        return st.empty();
    }
};
