#include <bits/stdc++.h>

using namespace std;

// 402. 移掉 K 位数字

// 给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

class Solution {
public:
    string removeKdigits(string num, int k) {
        int size = num.size();
        // 利用数组模拟单调递增栈(或相同)
        vector<int> monoStk;
        int count = 0;

        for(auto& ch : num){
            // 栈不为空 且 当前字符比栈顶小 且 还需去除字符
            while(monoStk.size()>0 && ch<monoStk.back() && count<k){
                ++count;
                monoStk.pop_back();
            }
            monoStk.push_back(ch);
        }
        // 去除剩余需要去除字符
        while(count<k && monoStk.size()>0){
            monoStk.pop_back();
            ++count;
        }
        string result = "";
        // 处理前缀0
        bool initFlag = true;
        for(auto& ch : monoStk){
            if(initFlag && ch=='0'){
                continue;
            }
            initFlag = false;
            result.push_back(ch);
        }
        
        return result.size()>=1 ? result : "0";
    }
};