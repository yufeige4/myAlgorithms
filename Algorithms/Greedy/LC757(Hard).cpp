#include <bits/stdc++.h>

using namespace std;

// 757. 设置交集大小至少为2

// 一个整数区间 [a, b]  ( a < b ) 代表着从 a 到 b 的所有连续整数，包括 a 和 b。

// 给你一组整数区间intervals，请找到一个最小的集合 S，使得 S 里的元素与区间intervals中的每一个整数区间都至少有2个元素相交。

// 输出这个最小集合S的大小。

// 思路 贪心+排序

// 若要求交集大小为m=1 则可先排序 从后往前取起点元素 若重叠则跳过

// 若m>1 则先排序(根据起始点升序,若相同起始点则根据末端点降序)
// 根据每一个区间创建一个与之相交的集合, 当该集合大小不满足m时，从该区间起始点往后依次向该集合添加元素
// 若此元素与前面区间产生交集，还需放入前面区间所对应的集合中


// 该解法适应于任何M
class Solution {
public:
    void update(vector<vector<int>>& intervals,vector<vector<int>>& numSets,int index,int num){
        for(int i=index;i>=0;--i){
            // 若当前值与该区间无交集且必然与前面所有区间无交集
            if(intervals[i][1]<num){
                break;
            }
            // 有交集则放入对应相交元素集合中
            numSets[i].push_back(num);
        }
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int result = 0;
        const int M = 2;
        auto cmp = [](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }else{
                return a[0]<b[0];
            }
        };
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        vector<vector<int>> numSets(n);
        for(int i=n-1;i>=0;--i){
            for(int val=intervals[i][0];numSets[i].size()<M;++val){
                // 将当前区间起始点和后续点加入对应相交元素集合
                numSets[i].push_back(val);
                // 判断前面区间是否与之相交 相交则加入前面区间所对应相交元素集合
                update(intervals,numSets,i-1,val);
                ++result;
            }
        }
        return result;
    }
};