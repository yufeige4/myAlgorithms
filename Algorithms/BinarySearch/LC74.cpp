#include <bits/stdc++.h>

using namespace std;

// 74. 搜索二维矩阵

// 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
//     每行中的整数从左到右按升序排列。
//     每行的第一个整数大于前一行的最后一个整数。

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m*n-1;
        int mid,val;
        while(left<=right){
            mid = left + (right-left)/2;
            val = matrix[mid/n][mid%n];
            if(val==target){
                return true;
            }else if(val<target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return false;
    }
};