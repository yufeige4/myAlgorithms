#include <bits/stdc++.h>

using namespace std;
// 305. 岛屿数量 II

// 给你一个大小为 m x n 的二进制网格 grid 。网格表示一个地图，其中，0 表示水，1 表示陆地。最初，grid 中的所有单元格都是水单元格（即，所有单元格都是 0）。

// 可以通过执行 addLand 操作，将某个位置的水转换成陆地。给你一个数组 positions ，其中 positions[i] = [ri, ci] 是要执行第 i 次操作的位置 (ri, ci) 。

// 返回一个整数数组 answer ，其中 answer[i] 是将单元格 (ri, ci) 转换为陆地后，地图中岛屿的数量。

// 岛屿 的定义是被「水」包围的「陆地」，通过水平方向或者垂直方向上相邻的陆地连接而成。你可以假设地图网格的四边均被无边无际的「水」所包围。

class UnionFind{
private:
    vector<int> parent;
    vector<int> sizes;
    int disjoints;
public:
    // 根据n个顶点构造graph
    UnionFind(int n) : sizes(n,1),disjoints(n){
        parent.resize(n);
        // 将根据val值递增1赋值
        iota(parent.begin(),parent.end(),0);
    }
    int find(int index){
        // 当index不为根时
        while(index!=parent[index]){
            // index的根向上找一层
            parent[index] = parent[parent[index]];
            index = parent[index];
        }
        // 直到找到原index的根为止
        return index;
    }
    void unite(int a,int b){
        // 将顶点a和b连通
        // 将a的根的父亲设置为b的根
        int rootA = find(a);
        int rootB = find(b);
        if(rootA==rootB){
            return;
        }
        // 统一合并规矩
        // 大吞小
        if(sizes[rootA]<sizes[rootB]){
            swap(rootA,rootB);
        }
        parent[rootB] = rootA;
        sizes[rootA] += sizes[rootB];
        --disjoints;
    }
    int setsNum(){
        return disjoints;
    }
};
class Solution {
private:
    int directX[4] = {0,0,-1,1};
    int directY[4] = {1,-1,0,0};
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> result;
        vector<vector<int>> grid(m,vector<int>(n,0));
        UnionFind myUF(m*n);
        // 初始化时每片海都是独立的
        int waterNum = m*n;
        for(auto& p : positions){
            int x = p[0];
            int y = p[1];
            // 若为无效操作
            if(grid[x][y]==1){
                result.push_back(result.back());
                continue;
            }
            // 多一块陆地则少一块水
            --waterNum;
            grid[x][y] = 1;
            int newX,newY;
            for(int i=0;i<4;++i){
                newX = x + directX[i];
                newY = y + directY[i];
                if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1){
                    // 为合法坐标
                    myUF.unite(x*n+y,newX*n+newY);
                }
            }
            // 总独立数量 - 水独立数量 = 岛屿独立数量
            int totalNum = myUF.setsNum();
            result.push_back(totalNum-waterNum);
        }
        return result;
    }
};