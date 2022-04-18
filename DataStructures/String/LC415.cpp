#include <bits/stdc++.h>

using namespace std;

// 415. 字符串相加

// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

// 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

class Solution {
public:
    string addStrings1(string num1, string num2) {
        int sizeA = num1.size();
        int sizeB = num2.size();
        int size = sizeA>sizeB ? sizeA : sizeB;
        int minSize = sizeA>sizeB ? sizeB : sizeA;
        int flag = 0;
        string result;
        result.resize(size);
        int i = 0;
        int val;
        for(;i<minSize;++i){
            val = num1[sizeA-i-1]-'0'+num2[sizeB-i-1]-'0'+flag;
            result[size-i-1] = (char)(val%10+'0');
            flag = val/10;
        }
        while(i<sizeA){
            val = num1[sizeA-i-1]-'0'+flag;
            result[size-i-1] = (char)(val%10+'0');
            flag = val/10;
            ++i;
        }
        while(i<sizeB){
            val = num2[sizeB-i-1]-'0'+flag;
            result[size-i-1] = (char)(val%10+'0');
            flag = val/10;
            ++i;
        }
        if(flag>0){
            result.insert(result.begin(),'1');
        }
        return result;
    }
    // 翻转简易版
    string addStrings2(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        // 计算完以后的答案需要翻转过来
        reverse(ans.begin(), ans.end());
        return ans;
    }

};