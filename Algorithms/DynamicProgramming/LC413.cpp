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
    int numberOfArithmeticSlices1(vector<int>& nums) {
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
            // 求和公式法
            if(end-start>=2){
                count += (end-start)*(end-start-1)/2;
            }
            start = end;
        }

        return count;
    }
    // 单项递增法
    int numberOfArithmeticSlices2(vector<int>& nums) {
        int size = nums.size();
        if(size<3){
            return 0;
        }
        int diff = nums[1]-nums[0];
        int count = 0;
        int temp = 0;
        for(int i=2;i<size;++i){
            if(nums[i]-nums[i-1]==diff){
                // 每长一位则多出(新长度-2)个子数组
                // 数组[1,2,3,4,...,n] [1,2,3,4,...,n,n+1]
                // n+1位可以和前面[1,...,n-1]中任何一位为start结合形成新的子数组
                // n-1个新数组
                ++temp;
                count += temp; 
            }else{
                diff = nums[i]-nums[i-1]; 
                temp = 0;
            }
        }
        return count;
    }
};
