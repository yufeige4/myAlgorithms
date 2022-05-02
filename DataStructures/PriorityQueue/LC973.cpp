#include <bits/stdc++.h>

using namespace std;

// 973. 最接近原点的 K 个点

// 给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，并且是一个整数 k ，返回离原点 (0,0) 最近的 k 个点。

// 这里，平面上两点之间的距离是 欧几里德距离（ √(x1 - x2)2 + (y1 - y2)2 ）。

// 你可以按 任何顺序 返回答案。除了点坐标的顺序之外，答案 确保 是 唯一 的。

class Solution {
public:
    int distance(vector<vector<int>>& points,int ptr){
        int x = points[ptr][0];
        int y = points[ptr][1];
        return x*x+y*y;
    }
    // 堆 O(nlogk)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<int,int> MyPair;
        vector<vector<int>> result;
        auto cmp = [](MyPair& a,MyPair& b){
            return a.second<b.second;
        };
        priority_queue<MyPair,vector<MyPair>,decltype(cmp)> pq(cmp);
        int size = points.size();
        int minPtr;
        for(int ptr=0;ptr<size;++ptr){
            int dist = distance(points,ptr);
            if(pq.size()<k){
                pq.push({ptr,dist});
            }else{
                if(dist<pq.top().second){
                    pq.pop();
                    pq.push({ptr,dist});
                }
            }
        }
        while(!pq.empty()){
            result.push_back(points[pq.top().first]);
            pq.pop();
        }
        return result;
    }
};