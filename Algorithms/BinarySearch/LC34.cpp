#include <bits/stdc++.h>

using namespace std;

// 34. 在排序数组中查找元素的第一个和最后一个位置

// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 如果数组中不存在目标值 target，返回 [-1, -1]。

class Solution {
public:
    int binarySearch(vector<int>& arr,int target,bool isFloor){
        int left = 0;
        int right = arr.size()-1;
        int mid;
        int result = -1;
        while(left<=right){
            mid = left + (right-left)/2;
            if(arr[mid]==target){
                result = mid;
                if(isFloor){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else if(arr[mid]<target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return result;
    }
    // 两次二分查找
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = binarySearch(nums,target,true);
        int end = binarySearch(nums,target,false);
        return {start,end};
    }
};