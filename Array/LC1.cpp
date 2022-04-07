#include <bits/stdc++.h>

using namespace std;

// 1. 两数之和

// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

// 你可以按任意顺序返回答案。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 用hash map去记录已经遍历过的数据的值和索引
        unordered_map<int,int> hash;
        int size = nums.size();
        int val;
        for(int i=0;i<size;++i){
            val = target - nums[i];
            if(hash.find(val)==hash.end()){
                hash[nums[i]] = i;
            }else{
                return {hash[val],i};
            }
        }
        return {-1,-1};
    }
};