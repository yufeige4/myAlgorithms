#include <bits/stdc++.h>
#define INF 10e6
using namespace std;

// 787. K 站中转内最便宜的航班

// 有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [from_i, to_i, price_i] 

// 现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到出一条最多经过 k 站中转的路线，使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 
// 如果不存在这样的路线，则输出 -1。

class Solution {
private:
    struct Edge{
        int u;
        int v;
        int cost;
    };
public:
    int bfs(vector<Edge>& edgeList,int& n,int& src,int& dst,int& k,int& m){
        vector<int> dist(n,INF);
        dist[src] = 0;
        // 每一步更新到所有顶点的最小距离
        for(int i=0;i<k+1;++i){
            // 复制原dist 防止以更新过的距离来计算(不符合当前步数)
            vector<int> temp = dist;
            // 遍历所有的边 更新所能触及的顶点的最小距离
            for(auto& edge : edgeList){
                dist[edge.v] = min(dist[edge.v],temp[edge.u]+edge.cost);
            }
        }
        return dist[dst];
    }
    // 有限制性的最短距离问题
    // bfs + Bellman Ford + Edge Class
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<Edge> edgeList;
        for(const auto& flight : flights){
            edgeList.push_back({flight[0],flight[1],flight[2]});
        }
        // 一共有多少条边
        int m = edgeList.size();

        int result = bfs(edgeList,n,src,dst,k,m);

        return result>INF/2 ? -1 : result;
    }
};