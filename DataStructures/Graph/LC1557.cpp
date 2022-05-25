#include <bits/stdc++.h>

using namespace std;

// 1557. 可以到达所有点的最少点数目

// 给你一个 有向无环图 ， n 个节点编号为 0 到 n-1 ，以及一个边数组 edges ，其中 edges[i] = [fromi, toi] 表示一条从点  fromi 到点 toi 的有向边。

// 找到最小的点集使得从这些点出发能到达图中所有点。题目保证解存在且唯一。

// 你可以以任意顺序返回这些节点编号。

class Solution {
public:
    // 只需要找到入度为0的点
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> result;
        vector<int> hash(n,0);
        for(auto& edge : edges){
            hash[edge[1]]--;
        }
        for(int i=0;i<n;++i){
            if(hash[i]==0){
                result.push_back(i);
            }
        }
        return result;
    }
};