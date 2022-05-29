#include <bits/stdc++.h>

using namespace std;

// 128. 最长连续序列

// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

class Solution {
public:
    // 先sort O(nlogn)
    int longestConsecutive1(vector<int>& nums) {
        int size = nums.size();
        if(size<1){
            return 0;
        }
        // store each par
        sort(nums.begin(),nums.end());
        int pre = nums[0];
        int len = 1;
        int maxLen = 1;
        for(int i=1;i<size;++i){
            if(nums[i]!=pre){
                if(nums[i]!=pre+1){
                    len = 1;
                }else{
                    ++len;
                }
            }
            pre = nums[i];
            maxLen = len>maxLen ? len : maxLen;
        }
        return maxLen;
    }
    // HashSet O(n)
    int longestConsecutive2(vector<int>& nums) {
        unordered_set<int> myHS;
        int maxLen = 0;
        for(auto& num : nums){
            myHS.insert(num);
        }
        for(auto num : myHS){
            int currLen = 1;
            // 当没有比该数小1的数存在时 减少重复访问同一序列的不同部分
            if(myHS.find(num-1)==myHS.end()){
                while(myHS.find(num+1)!=myHS.end()){
                    num = num+1;
                    ++currLen;
                }
            }
            maxLen = currLen>maxLen ? currLen : maxLen;
        }
        return maxLen;
    }
};