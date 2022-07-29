#include <bits/stdc++.h>

using namespace std;

// 593. 有效的正方形

// 给定2D空间中四个点的坐标 p1, p2, p3 和 p4，如果这四个点构成一个正方形，则返回 true 。

// 点的坐标 pi 表示为 [xi, yi] 。输入 不是 按任何顺序给出的。

// 一个 有效的正方形 有四条等边和四个等角(90度角)。

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // helper function计算两点之间距离的平方
        auto getDist = [](auto& a,auto& b){
            return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
        };
        // 将所有组合组成的边放入set中 去重
        unordered_set<int> mySet {getDist(p1,p2),getDist(p1,p3),getDist(p1,p4),getDist(p2,p3),getDist(p2,p4),getDist(p3,p4)};
        // 无重复点并且set中只有正方形边长和斜边长
        return mySet.count(0)<1 && mySet.size()==2;
    }
};