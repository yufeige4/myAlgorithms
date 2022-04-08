#include <bits/stdc++.h>

using namespace std;

// 35. 搜索插入位置
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if(target<nums[0]){
            return 0;
        }else if (target>nums[right]){
            return right + 1;
        }
        int val, mid;
        while(left<right){
            mid = left + (right-left)/2;
            val = nums[mid];
            if(val==target){
                return mid;
            }else if(val<target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        // left = right
        return left;
    }
};