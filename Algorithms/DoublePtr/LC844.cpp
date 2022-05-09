#include <bits/stdc++.h>

using namespace std;

// 844. 比较含退格的字符串
// 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

// 注意：如果对空文本输入退格字符，文本继续为空。

class Solution {
public:
    void handleBackSpace(string& s,int& i){
        int count = 0;
        do{
            if(s[i]=='#'){
                ++count;
            }else{
                --count;
            }
            --i;
        }while(count>0&&i>=0);
    }
    
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1;
        int j = t.size()-1;
        int k;
        while(i>=0&&j>=0){
            if(s[i]!='#' && t[j]!='#'){
                if(s[i]!=t[j]){
                    return false;
                }else{
                    --i;
                    --j;
                    continue;
                }
            }
            if(s[i]=='#') handleBackSpace(s,i);
            if(t[j]=='#') handleBackSpace(t,j);
        }
        while(i>=0&&s[i]=='#') handleBackSpace(s,i);
        while(j>=0&&t[j]=='#') handleBackSpace(t,j);
        return i<0&&j<0;
    }
};