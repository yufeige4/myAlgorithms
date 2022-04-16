#include <bits/stdc++.h>

using namespace std;

// 240. 搜索二维矩阵 II

// 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。
// 该矩阵具有以下特性：
// 每行的元素从左到右升序排列。
// 每列的元素从上到下升序排列。

class Solution {
public:
    // O(mlogn) 对每一行二分
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0;i<m;++i){
            int left = 0;
            int right = n-1;
            int mid,val;
            while(left<=right){
                mid = left + (right-left)/2;
                val = matrix[i][mid];
                if(target==val){
                    return true;
                }else if(target<val){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
        }
        return false;
    }
    // O(m+n) Z字形查找
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n-1;
        int val;
        while(x<m&&y>=0){
            val = matrix[x][y];
            if(val==target){
                return true;
            }else if(target<val){
                --y;
            }else{
                ++x;
            }
        }
        return false;
    }
};