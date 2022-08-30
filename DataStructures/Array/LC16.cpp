#include <bits/stdc++.h>

using namespace std;

// 16. 最接近的三数之和

// 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
// 返回这三个数的和。
// 假定每组输入只存在恰好一个解。

class Solution {
public:
    // 类似三数之和 排序 + 双指针 O(n^2)
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int result;
        int size = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<size;++i){
            // 去重提速
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int need = target - nums[i];
            int left = i + 1;
            int right = size -1;
            while(left<right){
                int sum = nums[left] + nums[right];
                if(abs(need-sum)<diff){
                    diff = abs(need-sum);
                    result = sum + nums[i];
                }
                if(sum==need){
                    return target;
                }else if(sum>need){
                    --right;
                    // 去重提速
                    // while(right>left&&nums[right]==nums[right+1]){
                    //     --right;
                    // }
                }else{
                    ++left;
                    // 去重提速
                    // while(left<right&&nums[left]==nums[left-1]){
                    //     ++left;
                    // }
                }
            }
        }
        return result;
    }
};