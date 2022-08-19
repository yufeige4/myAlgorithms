#include <bits/stdc++.h>

using namespace std;

// 1450. 在既定时间做作业的学生人数

// 给你两个整数数组 startTime（开始时间）和 endTime（结束时间），并指定一个整数 queryTime 作为查询时间。

// 已知，第 i 名学生在 startTime[i] 时开始写作业并于 endTime[i] 时完成作业。

// 请返回在查询时间 queryTime 时正在做作业的学生人数。形式上，返回能够使 queryTime 处于区间 [startTime[i], endTime[i]]（含）的学生人数。

class Solution {
public:
    // 一次遍历 枚举
    int busyStudent1(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int count = 0;
        int size = startTime.size();
        for(int i=0;i<size;++i){
            if(queryTime>=startTime[i]&&queryTime<=endTime[i]){
                ++count;
            }
        }
        return count;
    }
    // 差分数组
    int busyStudent2(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int count = 0;
        int size = startTime.size();
        int maxEnd = *max_element(endTime.begin(),endTime.end());
        if(queryTime>maxEnd) return 0;
        vector<int> time(maxEnd+2,0);
        for(int i=0;i<size;++i){
            ++time[startTime[i]];
            --time[endTime[i]+1];
        }
        for(int i=0;i<=queryTime;++i){
            count += time[i];
        }
        return count;
    }
};