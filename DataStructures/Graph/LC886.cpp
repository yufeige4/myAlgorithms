#include "UnionFind.h"

// 886. 可能的二分法

// 给定一组 n 人（编号为 1, 2, ..., n）， 我们想把每个人分进任意大小的两组。每个人都可能不喜欢其他人，那么他们不应该属于同一组。

// 给定整数 n 和数组 dislikes ，其中 dislikes[i] = [ai, bi] ，表示不允许将编号为 ai 和  bi的人归入同一组。

// 当可以用这种方法将所有人分进两组时，返回 true；否则返回 false。

class Solution {
public:
    // 将所有不喜欢某人的人相连，若图不连通，则可以分成两组
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        // 顶点编号为[1,2,..,n] 
        // graph[i]中保存和顶点i相连的边
        vector<vector<int>> graph(n+1);
        for(const auto& edge : dislikes){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        // 初始化并查集 一人一个集合
        UnionFind myUion = UnionFind(n+1);
        // 根据EdgeList 更新并查集
        for(int u=1;u<=n;++u){
            for(const auto& v : graph[u]){
                // 不喜欢的两个人出现在一个集合里则失败
                if(myUion.find(u)==myUion.find(v)) return false;
                // 将所有不喜欢u的人分到一个组里
                myUion.unite(graph[u][0],v);
            }
        }
        return true;
    }
};
