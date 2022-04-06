#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 用hash map去记录已经遍历过的数据的值和索引
        unordered_map<int,int> hash;
        int size = nums.size();
        int val;
        for(int i=0;i<size;++i){
            val = target - nums[i];
            if(hash.find(val)==hash.end()){
                hash[nums[i]] = i;
            }else{
                return {hash[val],i};
            }
        }
        return {-1,-1};
    }
};