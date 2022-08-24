#include <bits/stdc++.h>

using namespace std;

// 1460. 通过翻转子数组使两个数组相等

// 给你两个长度相同的整数数组 target 和 arr 。每一步中，你可以选择 arr 的任意 非空子数组 并将它翻转。你可以执行此过程任意次。

// 如果你能让 arr 变得与 target 相同，返回 True；否则，返回 False 。

class Solution {
public:
    // 元素相同即可使其相等
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> hash;
        for(const auto& i : target){
            ++hash[i];
        }
        for(const auto& i : arr){
            --hash[i];
            if(hash[i]==0){
                hash.erase(i);
            }
        }
        return hash.size()==0;
    }
};