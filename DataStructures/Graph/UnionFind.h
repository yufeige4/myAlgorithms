#include <bits/stdc++.h>

using namespace std;


class UnionFind{
private:
    vector<int> parent;
public:
    // 根据n个顶点构造graph
    UnionFind(int n){
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
        parent[find(a)] = find(b);
    }

};