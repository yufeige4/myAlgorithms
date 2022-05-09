#include <bits/stdc++.h>

using namespace std;

// 11. 盛最多水的容器

// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

// 返回容器可以储存的最大水量。

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int maxVal = 0;
        int val = 0;
        int left = 0;
        int right = size-1;
        int leftHeight;
        int rightHeight;
        while(left<right){
            leftHeight = height[left];
            rightHeight = height[right];
            if(leftHeight<rightHeight){
                val = leftHeight*(right-left);
                ++left;
            }else{
                val = rightHeight*(right-left);
                --right;
            }
            maxVal = val>maxVal ? val : maxVal;
        }
        return maxVal;
    }
};