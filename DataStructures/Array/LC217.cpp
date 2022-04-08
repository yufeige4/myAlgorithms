#include <bits/stdc++.h>

using namespace std;
// 217. 存在重复元素

// 给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0){
            return false;
        }
        unordered_map<int,bool> hash;
        for(auto i:nums){
            if(hash.find(i)==hash.end()){
                hash[i] = true;
            }else{
                return true;
            }
        }
        return false;
    }
};