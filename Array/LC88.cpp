#include <bits/stdc++.h>

using namespace std;

// 88. 合并两个有序数组

// 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

// 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

// 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // nums1足够大的情况下 从大到小往nums1写数据
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--] = nums1[i--];
            }else{
                nums1[k--] = nums2[j--];
            }
        }
        // i or j = 0
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
};