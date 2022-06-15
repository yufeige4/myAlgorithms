#include "UnionFind.h"

// 261. 以图判树

// 给定编号从 0 到 n - 1 的 n 个结点。

// 给定一个整数 n 和一个 edges 列表，其中 edges[i] = [ai, bi] 表示图中节点 ai 和 bi 之间存在一条无向边。

// 如果这些边能够形成一个合法有效的树结构，则返回 true ，否则返回 false 。

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind myUF(n);
        for(auto& e : edges){
            // 若两点已在一个集合中 则存在环
            if(myUF.find(e[0])==myUF.find(e[1])){
                return false;
            }
            myUF.unite(e[0],e[1]);
        }
        // 判断是否只有一个根结点存在
        int count = 0;
        for(int i=0;i<n;++i){
            if(myUF.find(i)==i){
                ++count;
            }
        }
        return count==1;
    }
};