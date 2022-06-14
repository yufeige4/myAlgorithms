#include <bits/stdc++.h>

using namespace std;

// 384. 打乱数组

// 给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。打乱后，数组的所有排列应该是 等可能 的。

// 实现 Solution class:

// Solution(int[] nums) 使用整数数组 nums 初始化对象
// int[] reset() 重设数组到它的初始状态并返回
// int[] shuffle() 返回数组随机打乱后的结果

// Fisher-Yates洗牌算法
class Solution {
private:
    vector<int> original;
    vector<int> curr;
public:
    Solution(vector<int>& nums) {
        this->original = nums;
        this->curr = nums;
    }
    
    vector<int> reset() {
        copy(original.begin(),original.end(),curr.begin());
        return curr; 
    }
    
    vector<int> shuffle() {
        int size = curr.size();
        // 在[i,size)中随即选择一个数，并将其与第i位(随即序列的第一位)交换，再去除第i位
        for(int i=0;i<size;++i){
            int j = i + rand()%(size-i);
            swap(curr[i],curr[j]);
        }
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */