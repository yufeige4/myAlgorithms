#include "UnionFind.h"

// 323. 无向图中连通分量的数目

// 你有一个包含 n 个节点的图。给定一个整数 n 和一个数组 edges ，其中 edges[i] = [ai, bi] 表示图中 ai 和 bi 之间有一条边。

// 返回 图中已连接分量的数目 。


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind myUF(n);
        for(auto& e : edges){
            myUF.unite(e[0],e[1]);
        }
        return myUF.setsNum();
    }
};