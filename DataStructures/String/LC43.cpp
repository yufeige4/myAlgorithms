#include <bits/stdc++.h>

using namespace std;

// 43. 字符串相乘

// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int sizeA = num1.size();
        int sizeB = num2.size();
        int size = sizeA+sizeB;
        vector<int> temp(size,0);

        // 使用优化竖式计算乘法
        for(int i=sizeA-1;i>=0;--i){
            int a = num1[i]-'0';
            for(int j=sizeB-1;j>=0;--j){
                int b = num2[j]-'0';
                int val = a*b+temp[i+j+1];
                temp[i+j+1] = val%10;
                temp[i+j] += val/10;
            }
        }

        bool flag = false;
        string result;

        for(int i=0;i<size;++i){
            if(flag||temp[i]!=0){
                flag = true;
                result.push_back(temp[i]+'0');
            }
        }
        return result;
    }
};