#include <bits/stdc++.h>

using namespace std;

// 15. 三数之和

// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        if(size==0) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<size;++i){
            if(nums[i]>0){
                break;
            }
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int left = i + 1;
            int right = size - 1;
            while(left<right){
                // 以下提速代价太大 反而不划算
                // while(left>i+1&&nums[left]==nums[left-1]){
                //     ++left;
                // }
                // while(right<size-1&&nums[right]==nums[right+1]){
                //     --right;
                // }
                // if(left>=right) break;
                int temp = nums[left] + nums[right];
                if(temp==target){
                    result.push_back({nums[i],nums[left],nums[right]});
                    ++left;
                    --right;
                    while(left<=right&&nums[left]==nums[left-1]) ++left;
                    while(left<=right&&nums[right]==nums[right+1]) --right;
                }else if(temp<target){
                    ++left;
                }else{
                    --right;
                }
            }
        }

        return result;
    }
};