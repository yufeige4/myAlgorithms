#include <bits/stdc++.h>

using namespace std;

// 557. 反转字符串中的单词 III

// 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

class Solution {
public:
    // 利用stack实现
    string reverseWords1(string s) {
        string result;
        stack<char> stk;
        char ch;
        int size = s.size();
        for(int i=0;i<size;++i){
            ch = s[i];
            if(ch!=' '){
                stk.push(ch);
                if(i==size-1){
                    while(!stk.empty()){
                        result.push_back(stk.top());
                        stk.pop();
                    }
                }
            }else{
                while(!stk.empty()){
                    result.push_back(stk.top());
                    stk.pop();
                }
                result.push_back(ch);
            }
        }
        return result;
    }
    string reverseWords2(string s) {
        string result;
        int size = s.size();
        int i = 0;
        int start,left,right;
        while(i<size){
            start = i;
            while(s[i]!=' '&&i<size){
                ++i;
            }
            // now i is at space or end
            // 逆序输出介于left和right中的字符
            left = start;
            right = i-1;
            while(left<=right){
                result.push_back(s[right--]);
            }
            // 该字符为空格
            if(s[i]==' '){
                result.push_back(' ');
                ++i;
            }
        }
        return result;
    }
};

