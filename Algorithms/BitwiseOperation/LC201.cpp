#include <bits/stdc++.h>

using namespace std;

// 201. 数字范围按位与

// 给你两个整数 left 和 right ，表示区间 [left, right] ，返回此区间内所有数字 按位与 的结果（包含 left 、right 端点）。

class Solution {
public:
    int rangeBitwiseAnd1(int left, int right) {
        int count = 0;
        // 抹去后面不同的位,只保留公共前缀
        while(right>left){
            left >>= 1;
            right >>= 1;
            ++count;
        }
        return left<<count;
    }

    int rangeBitwiseAnd2(int left, int right) {
        // 使用 n&(n-1)操作抹去最右边的1
        while(left<right){
            right = right & (right-1);
        }
        return right;
    }



};