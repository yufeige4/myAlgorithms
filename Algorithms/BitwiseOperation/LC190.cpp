#include <bits/stdc++.h>

using namespace std;

// 190. 颠倒二进制位

// 颠倒给定的 32 位无符号整数的二进制位。

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=0;i<32;++i){
            result = result<<1;
            result += (n&1);
            n = (n>>1);
        }
        return result;
    }
};