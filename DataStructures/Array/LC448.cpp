#include <bits/stdc++.h>

using namespace std;

// 448. 找到所有数组中消失的数字

// 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
// 请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。

class Solution {
public:
    // 时间复杂度O(n) 空间复杂度O(n)
    vector<int> findDisappearedNumbers1(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> myHS;
        int maxNum = nums.size();
        for(auto& i : nums){
            myHS.insert(i);
        }
        for(int i=1;i<=maxNum;++i){
            if(myHS.find(i)==myHS.end()){
                result.push_back(i);
            }
        }
        return result;
    }
    // 利用原数组进行hash 从而优化空间复杂度O(1)
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        int val;
        for(int i=0;i<n;++i){
            // 该数存在则将[0,n-1]区间进行hash
            // 有可能此数已被hash过所以要mod
            val = (nums[i]-1)%n;
            nums[val] += n;
        }
        for(int i=0;i<n;++i){
            // 若该数(i+1)出现过则nums[i]必然被hash过(>n)
            if(nums[i]<=n){
                result.push_back(i+1);
            }
        }
        return result;
    }
};