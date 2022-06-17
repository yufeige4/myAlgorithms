#include <bits/stdc++.h>

using namespace std;

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
    // 返回是否为有效合并
    bool unite(int a,int b){
        // 将顶点a和b连通
        // 将a的根的父亲设置为b的根
        int rootA = find(a);
        int rootB = find(b);
        if(rootA==rootB){
            return false;
        }
        // 统一合并规矩
        // 大吞小
        if(sizes[rootA]<sizes[rootB]){
            swap(rootA,rootB);
        }
        parent[rootB] = rootA;
        sizes[rootA] += sizes[rootB];
        --disjoints;
        return true;
    }
    int setsNum(){
        return disjoints;
    }
};