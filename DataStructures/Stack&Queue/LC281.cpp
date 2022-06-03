#include <bits/stdc++.h>

using namespace std;

// 281. 锯齿迭代器

// 给出两个一维的向量，请你实现一个迭代器，交替返回它们中间的元素。

// 拓展：假如给你 k 个一维向量呢？你的代码在这种情况下的扩展性又会如何呢?

// 拓展声明：
//  “锯齿” 顺序对于 k > 2 的情况定义可能会有些歧义。所以，假如你觉得 “锯齿” 这个表述不妥，也可以认为这是一种 “循环”。例如：

// 普通解
class ZigzagIterator {
private:
    queue<int> myQ;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int size1 = v1.size();
        int size2 = v2.size();
        int i = 0;
        int j = 0;
        bool first = true;
        while(i<size1&&j<size2){
            if(first){
                myQ.push(v1[i++]);
            }else{
                myQ.push(v2[j++]);
            }
            first = !first;
        }
        while(i<size1){
            myQ.push(v1[i++]);
        }
        while(j<size2){
            myQ.push(v2[j++]);
        }
    }

    int next() {
        int result = myQ.front();
        myQ.pop();
        return result;
    }

    bool hasNext() {
        return !myQ.empty();
    }
};

// 拓展解
class CyclicIterator {
private:
    vector<vector<int>> data;
    // 每一个向量的总长度
    vector<int> sizes;
    // 表示每一个向量访问到第几个元素
    vector<int> idx;
    // 访问到第几个向量
    int curr;
    // 总向量数
    int capacity;
public:
    CyclicIterator(vector<vector<int>>& vecs) {
        capacity = vecs.size();
        curr = 0;
        data = vecs;
        idx = vector<int>(capacity,0);
        for(int i=0;i<capacity;++i){
            sizes.push_back(vecs[i].size());
        }
    }

    int next() {
        while(idx[curr]>=sizes[curr]){
            curr = (curr+1)%capacity;
        }
        int result = data[curr][idx[curr]];
        ++idx[curr];
        curr = (curr+1)%capacity;

        return result;
    }

    bool hasNext() {
        int origin = curr;
        while(idx[curr]>=sizes[curr]){
            curr = (curr+1)%capacity;
            if(origin==curr){
                break;
            }
        }
        return idx[curr]<sizes[curr];
    }
};