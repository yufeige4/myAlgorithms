#include <bits/stdc++.h>

using namespace std;

// 435. 无重叠区间

// 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。

class Solution {
public:
    // 按左端点排序并贪心
    int eraseOverlapIntervals1(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int size = intervals.size();
        int end = intervals[0][1];
        int count = 1;
        int left,right;
        for(int i=1;i<size;++i){
            left = intervals[i][0];
            right = intervals[i][1];
            if(left>=end){
                end = right;
                ++count;
            }else{
                if(right<end){
                    end = right;
                }
            }
        }
        return size-count;
    }

    // 按右端点排序并贪心
    int eraseOverlapIntervals2(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1];
        });
        int size = intervals.size();
        int end = intervals[0][1];
        int count = 1;
        int left,right;
        for(int i=1;i<size;++i){
            left = intervals[i][0];
            right = intervals[i][1];
            if(left>=end){
                end = right;
                ++count;
            }
        }
        return size-count;
    }
};
