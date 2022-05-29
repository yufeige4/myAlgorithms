#include <bits/stdc++.h>

using namespace std;

// 1427. 字符串的左右移

// 给定一个包含小写英文字母的字符串 s 以及一个矩阵 shift，其中 shift[i] = [direction, amount]：

// direction 可以为 0 （表示左移）或 1 （表示右移）。
// amount 表示 s 左右移的位数。
// 左移 1 位表示移除 s 的第一个字符，并将该字符插入到 s 的结尾。
// 类似地，右移 1 位表示移除 s 的最后一个字符，并将该字符插入到 s 的开头。
// 对这个字符串进行所有操作后，返回最终结果。

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int step = 0;
        int size = s.size();
        for(auto& move : shift){
            if(move[0]==0){
                step -= move[1];
            }else{
                step += move[1];
            }
        }
        step = step%size;
        string result;
        result.resize(size);
        // 或者可以 step = (step%size+size)%size
        // return s.substr(size-step,step)+s.substr(0,size-step);
        for(int i=0;i<size;++i){
            result[i] = s[(i-step+size)%size];
        }
        return result;
    }
};