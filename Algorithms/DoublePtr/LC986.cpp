#include <bits/stdc++.h>

using namespace std;

// 986. 区间列表的交集

// 给定两个由一些 闭区间 组成的列表，firstList 和 secondList ，其中 firstList[i] = [starti, endi] 而 secondList[j] = [startj, endj] 。
// 每个区间列表都是成对 不相交 的，并且 已经排序 。

// 返回这 两个区间列表的交集 。

// 形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b 。

// 两个闭区间的 交集 是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3] 。

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int sizeA = firstList.size();
        int j = 0;
        int sizeB = secondList.size();
        vector<vector<int>> result;
        if(sizeA==0||sizeB==0) return result;
        int start,end;
        while(i<sizeA&&j<sizeB){
            start = firstList[i][0]<secondList[j][0] ? secondList[j][0] : firstList[i][0];
            if(firstList[i][1]<secondList[j][1]){
                end = firstList[i][1];
                ++i;
            }else{
                end = secondList[j][1];
                ++j;
            }
            if(start<=end){
                result.push_back({start,end});
            }
        }
        return result;
    }
};