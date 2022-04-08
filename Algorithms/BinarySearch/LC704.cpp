#include <bits/stdc++.h>

using namespace std;

// 704. 二分查找
// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size==0||nums[0]>target||nums[size-1]<target){
            return -1;
        }
        int left = 0;
        int right = size-1;
        int mid, val;
        while(left<=right){
            mid = left + (right-left)/2;
            val = nums[mid];
            if(val==target){
                return mid;
            }else if(val<target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
};