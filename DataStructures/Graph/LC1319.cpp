#include "UnionFind.h"


// 319. 连通网络的操作次数

// 用以太网线缆将 n 台计算机连接成一个网络，计算机的编号从 0 到 n-1。线缆用 connections 表示，其中 connections[i] = [a, b] 连接了计算机 a 和 b。

// 网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。

// 给你这个计算机网络的初始布线 connections，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。

// 请你计算并返回使所有计算机都连通所需的最少操作次数。如果不可能，则返回 -1 。 

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if(n-1>size){
            return -1;
        }
        UnionFind myUF(n);
        // 通过并查集找到一共有多少个不相交的集合
        // 集合数量-1即为需要连通的数量
        for(auto& conn : connections){
            myUF.unite(conn[0],conn[1]);
        }

        int count = 0;
        for(int i=0;i<n;++i){
            if(myUF.find(i)==i){
                ++count;
            }
        }
        return count-1;
    }
};