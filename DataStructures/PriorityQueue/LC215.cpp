#include <bits/stdc++.h>

using namespace std;

// 215. 数组中的第K个最大元素

// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

class Solution {
public:
    // 使用heap 
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,less<int>> pq(nums.begin(),nums.end());
        for(int i=1;i<k;++i){
            pq.pop();
        }
        return pq.top();
    }
};