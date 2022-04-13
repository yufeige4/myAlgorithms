#include <bits/stdc++.h>

using namespace std;

// 169. 多数元素

// 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

class Solution {
public:
    int majorityElement1(vector<int>& nums) {
        unordered_map<int,int> myHT;
        int freq = nums.size()/2;
        int result = -1;
        for(const auto& num : nums){
            myHT[num]++;
            if(myHT[num]>freq){
                result = num;
                break;
            }
        }
        return result;
    }
    // 尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
    // Boyer-Moore 投票算法
    int majorityElement2(vector<int>& nums) {
        int candidate = nums[0];
        int count = 0;
        for(const auto& num : nums){
            if(count==0){
                candidate = num;
                ++count;
            }else{
                if(num!=candidate){
                    --count;
                }else{
                    ++count;
                }
            }
        }
        return candidate;
    }


};



