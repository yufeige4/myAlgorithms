#include <bits/stdc++.h>

using namespace std;

// 350. 两个数组的交集 II

// 给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。
// 可以不考虑输出结果的顺序。


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()){
            return intersect(nums2,nums1);
        }
        unordered_map<int,int> hash;
        vector<int> result;
        int count;
        // 用hash map记录 nums1里的元素出现次数
        for(const auto &num:nums1){
            if(hash.find(num)==hash.end()){
                hash[num] = 1;
            }else{
                hash[num]++;
            }
        }
        // 如果在nums1中出现且在nums2中出现，加入输出中并减少记录的频率
        for(const auto &num:nums2){
            if(hash.find(num)!=hash.end()){
                count = hash[num];
                if(count>0){
                    result.emplace_back(num);
                    if(count-1==0){
                        hash.erase(num);
                    }else{
                        hash[num] = count-1;
                    }
                }
            }
        }
        return result;
    }
};