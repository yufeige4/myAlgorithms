#include <bits/stdc++.h>

using namespace std;

// 565. 数组嵌套

// 索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。

// 假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。

class Solution {
public:
    // 可能存在环, 找出最大的环
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int maxSize = 0;
        for(int i=0;i<n;++i){
            int count = 0;
            while(nums[i]!=-1){
                int temp = nums[i];
                nums[i] = -1;
                i = temp;
                ++count;
            }
            maxSize = max(maxSize,count);
        }
        return maxSize;
    }
};