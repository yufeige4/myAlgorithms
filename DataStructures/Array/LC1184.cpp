#include <bits/stdc++.h>

using namespace std;

// 1184. 公交站间的距离

// 环形公交路线上有 n 个站，按次序从 0 到 n - 1 进行编号。
// 我们已知每一对相邻公交站之间的距离，distance[i] 表示编号为 i 的车站和编号为 (i + 1) % n 的车站之间的距离。
// 环线上的公交车都可以按顺时针和逆时针的方向行驶。
// 返回乘客从出发点 start 到目的地 destination 之间的最短距离。

class Solution {
public:
    // 一次遍历, 顺时针+逆时针一共一圈
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int dist1 = 0;
        int dist2 = 0;
        for(int i=start;i!=destination;i=(i+1)%n){
            dist1 += distance[i];
        }
        for(int i=destination;i!=start;i=(i+1)%n){
            dist2 += distance[i];
        }
        return min(dist1,dist2);
    }
};