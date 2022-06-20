#include <bits/stdc++.h>

using namespace std;

// 253. 会议室 II

// 给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。

class Solution {
public:
    // 此题即为求某时刻同时存在的会议室最大数量
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // ends里存放会议室的结束时间
        priority_queue<int,vector<int>,greater<int>> ends;
        sort(intervals.begin(),intervals.end());
        int maxSize = 0;
        for(auto& time : intervals){
            while(!ends.empty()&&time[0]>=ends.top()){
                ends.pop();
            }
            ends.push(time[1]);
            maxSize = max(maxSize,(int)ends.size());
        }

        return maxSize;
    }
};