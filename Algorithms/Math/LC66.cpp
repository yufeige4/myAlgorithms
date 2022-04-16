#include <bits/stdc++.h>

using namespace std;

// 66. 加一

// 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

// 你可以假设除了整数 0 之外，这个整数不会以零开头。

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int i = len-1;
        int temp;
        do{
            temp = digits[i]+1;
            digits[i] = temp%10;
            --i;
        }while(temp==10&&i>=0);
        if(temp==10){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};