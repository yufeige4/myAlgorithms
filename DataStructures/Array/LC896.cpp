#include <bits/stdc++.h>

using namespace std;

// 896. 单调数列

// 如果数组是单调递增或单调递减的，那么它是 单调 的。

// 如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i]> = nums[j]，那么数组 nums 是单调递减的。

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int size = nums.size();
        if(size==1){
            return true;
        }
        int i = 1;
        int flag;
        do{
            flag = nums[i]-nums[i-1];
            ++i;
        }while(!flag&&i<size);
        // now flag!=0
        for(;i<size;++i){
            if(flag>0){
                if(nums[i]-nums[i-1]<0){
                    return false;
                }
            }else{
                if(nums[i]-nums[i-1]>0){
                    return false;
                }
            }
        }
        return true;
    }
};