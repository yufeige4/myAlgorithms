#include "UnionFind.h"

// 1579. 保证图可完全遍历

// Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3  种类型的边：

// 类型 1：只能由 Alice 遍历。
// 类型 2：只能由 Bob 遍历。
// 类型 3：Alice 和 Bob 都可以遍历。
// 给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi 之间存在类型为 typei 的双向边。
// 请你在保证图仍能够被 Alice和 Bob 完全遍历的前提下，找出可以删除的最大边数。
// 如果从任何节点开始，Alice 和 Bob 都可以到达所有其他节点，则认为图是可以完全遍历的。

// 返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1 。

class Solution {
public:
    // 贪心 优先处理公共边 再 处理私人边 因为有可能一条边当两条用
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind aliceUF(n);
        UnionFind bobUF(n);
        int count = 0;
        for(auto& edge : edges){
            // 处理公共边
            if(edge[0]==3){
                // 若该操作多余 则直接count++，而无需再在bobUF中连接一次
                if(!aliceUF.unite(edge[1]-1,edge[2]-1)){
                    ++count;
                }else{
                    // 若该操作不多余
                    bobUF.unite(edge[1]-1,edge[2]-1);
                }
            }
        }
        for(auto& edge : edges){
            if(edge[0]==1){
                // 处理alice的边
                // 若该边多余
                if(!aliceUF.unite(edge[1]-1,edge[2]-1)){
                    ++count;
                }
            }else if(edge[0]==2){
                // 处理bob的边
                // 若该边多余
                if(!bobUF.unite(edge[1]-1,edge[2]-1)){
                    ++count;
                }
            }
        }
        // 若任意一图不连通
        if(aliceUF.setsNum()!=1||bobUF.setsNum()!=1){
            return -1;
        }
        return count;
    }
};