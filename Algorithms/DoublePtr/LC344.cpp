#include <bits/stdc++.h>

using namespace std;

// 344. 反转字符串

// 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

// 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int j = size/2;
        int i = size%2 ? size/2 : size/2-1;
        // 从中间开始，左右两侧对调
        while(i>=0&&j<size){
            swap(s[i--],s[j++]);
        }
    }
};