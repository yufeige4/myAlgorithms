#include <bits/stdc++.h>

using namespace std;

// 189. 轮转数组
// 给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

class Solution {
public:
    void reverse(vector<int>& nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    // 利用数学方法，将其反转，再将其前k项和剩余项分别反转，即可得到移动后的数组
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int index = k%size - 1;
        reverse(nums,0,size-1);
        reverse(nums,0,index);
        reverse(nums,index+1,size-1);
    }
};