#include <bits/stdc++.h>

using namespace std;

// 283. 移动零
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

class Solution {
public:
    // 逐个操作，最后赋值0
    void moveZeroes1(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        int temp;
        for(int i=0;i<size;++i){
            temp = nums[i];
            if(temp==0){
                count++;
            }else{
                nums[i-count] = temp;
            }
        }
        for(int i=count;i>0;--i){
            nums[size-i] = 0;
        }
    }

    // 非0对调，遇0记录，实现将0搬运到末尾
    void moveZeroes2(vector<int>& nums) {
        int size = nums.size();
        if(size==1){
            return;
        }
        int left = 0;
        int right = 0;
        while(size--){
            if(nums[right]!=0){
                swap(nums[left],nums[right]);
                ++left;
            }
            ++right;
        }
    }
};