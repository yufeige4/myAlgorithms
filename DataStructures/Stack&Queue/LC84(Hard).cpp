#include <bits/stdc++.h>

using namespace std;

// 84. 柱状图中最大的矩形

// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

// 求在该柱状图中，能够勾勒出来的矩形的最大面积。


class Solution {
public:
    // my first thought 单调栈存储高度 但效率不高 因为每去掉一个元素要加上一个相同元素
    int largestRectangleArea1(vector<int>& heights) {
        // 单调递增栈存储高度
        stack<int> monoStk;
        int size = heights.size();
        int result = 0;
        for(auto& height : heights){
            int count = 0;
            int minHeight = INT_MAX;
            // 把栈中元素进行一次面积判断
            while(!monoStk.empty() && height<monoStk.top()){
                // 因为是单调栈 又栈顶到栈底总是减小或相同
                result = max(minHeight*count,result);
                minHeight = monoStk.top();
                ++count;
                monoStk.pop();
            }
            result = max(minHeight*count,result);
            for(int i=0;i<count;++i){
                // 填充上count个height
                monoStk.push(height);
            }
            // 栈为空或大于栈顶元素时
            monoStk.push(height);
        }
        // 把栈中元素进行一次面积判断
        int count = 0;
        int minHeight = INT_MAX;
        while(!monoStk.empty()){
            // 因为是单调栈 又栈顶到栈底总是减小或相同
            result = max(minHeight*count,result);
            minHeight = monoStk.top();
            ++count;
            monoStk.pop();
        }
        result = max(minHeight*count,result);

        return result;
    }

    // 根据first thought进行优化 使用下标计算代替添加重复高度
    int largestRectangleArea2(vector<int>& heights) {
        int size = heights.size();
        // 单调递增栈存储下标
        stack<int> monoStk;
        // 利用数组存储 每个以heights[i]为矩形高度的左端点下标(不包括)和右端点(不包括)下标
        // (left,right)
        vector<int> left(size,0);
        vector<int> right(size,size);
        int result = 0;
        for(int i=0;i<size;++i){
            // 目前高度小于等于在栈顶元素高度时
            while(!monoStk.empty() && heights[i]<=heights[monoStk.top()]){
                // 目前高度一定小于等于栈顶元素高度
                // 所以有端点(不包括)一定为i
                right[monoStk.top()] = i;
                monoStk.pop();
            }
            // 若栈为空则代表该高度小于最左端高度 置left为-1
            left[i] = monoStk.empty() ? -1 : monoStk.top();
            monoStk.push(i);
        }

        // 根据左右端点数组计算出最大面积
        for(int i=0;i<size;++i){
            // area = 宽度(left,right) * 高度heights[i]
            result = max((right[i]-left[i]-1)*heights[i],result);
        }
        return result;
    }
};