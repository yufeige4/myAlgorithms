#include <bits/stdc++.h>

using namespace std;

// 55. 跳跃游戏

// 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 判断你是否能够到达最后一个下标。

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int farest = 0;
        for(int i=0;i<size;++i){
            // 若该可以到达则判断是否更新最远距离
            if(i<=farest){
                farest = i+nums[i]>farest ? i+nums[i] : farest;
            }else{
                return false;
            }
        }
        return true;
    }
};