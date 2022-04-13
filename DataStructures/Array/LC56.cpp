#include <bits/stdc++.h>

using namespace std;

// 56. 合并区间

// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

class Solution {
public:
    // Sort + 贪心
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
            [](vector<int>& a,vector<int>& b){
                return a[0]<b[0];
            }
        );
        vector<vector<int>> result;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(const auto& interval : intervals){
            int i = interval[0];
            int j = interval[1];
            if(start<=i&&end>=i){
                if(j>=end){
                    end = j;
                }
            }else{
                result.push_back({start,end});
                start = i;
                end = j;
            }
        }
        result.push_back({start,end});
        return result;
    }
};