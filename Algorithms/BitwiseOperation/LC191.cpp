#include <bits/stdc++.h>

using namespace std;

// 191. 位1的个数

// 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n>0){
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
};