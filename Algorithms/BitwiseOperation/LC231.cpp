#include <bits/stdc++.h>

using namespace std;

// 231. 2 的幂

// 给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

// 如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

class Solution {
public:
    // 定义: 一个正整数的二进制表达只能有1个1才能使得其是2的幂次方
    // n & (n-1) 将最低位1去除
    bool isPowerOfTwo(int n) {
        return n>0 && (n&(n-1))==0;
    }
};