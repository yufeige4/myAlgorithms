#include <bits/stdc++.h>

using namespace std;

// 413. 等差数列划分

// 如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。
// 例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。

// 给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。

// 子数组 是数组中的一个连续序列。

class Solution {
public:
    // int fact(int total){
    //     int num = 3;
    //     int count = 0;
    //     while(total-num>=0){
    //         count += total-num+1;
    //         ++num;
    //     }
    //     return count;
    // }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        if(size<3){
            return 0;
        }
        int diff;
        int start = 0;
        int end = 0;
        int count = 0;
        while(start+2<size){
            diff = nums[start+1]-nums[start];
            end = start+1;
            while(end+1<size&&nums[end+1]-nums[end]==diff){
                ++end;
            }
            if(end-start>=2){
                count += (end-start)*(end-start-1)/2;
            }
            start = end;
        }

        return count;
    }
};
