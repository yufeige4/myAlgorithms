#include <bits/stdc++.h>

using namespace std;

// 75. 颜色分类

// 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

// 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

// 必须在不使用库的sort函数的情况下解决这个问题。

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int redIndex = 0;
        int blueIndex = size-1;
        int i = 0;
        // 将不同的颜色搬到不同的位置
        while(i<=blueIndex){
            int color = nums[i];
            if(color==0){
                swap(nums[i],nums[redIndex]);
                ++redIndex;
                ++i;
            }else if(color==2){
                swap(nums[i],nums[blueIndex]);
                --blueIndex;
            }else{
                ++i;
            }
        }
    }
};