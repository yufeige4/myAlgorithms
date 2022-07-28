#include <bits/stdc++.h>

using namespace std;

// 1331. 数组序号转换

// 给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。

// 序号代表了一个元素有多大。序号编号的规则如下：
// 序号从 1 开始编号。
// 一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
// 每个数字的序号都应该尽可能地小。

class Solution {
public:
    typedef pair<int,int> MyPair;
    class cmp{
    public:
        cmp(){}
        bool operator()(MyPair& a,MyPair& b){
            return a.first>b.first;
        }
    };
    // 利用heap sort进行排序 利用MyPair进行映射
    vector<int> arrayRankTransform(vector<int>& arr) {
        int size = arr.size();
        priority_queue<MyPair,vector<MyPair>,cmp> pq;
        for(int i=0;i<size;++i){
            pq.push(make_pair(arr[i],i));
        }

        int count = 0;
        int prev = 0;
        vector<int> result(size,0);
        while(pq.size()>0){
            auto [val,index] = pq.top();
            pq.pop();
            if(count!=0){
                if(val!=prev){
                    ++count;
                }
            }else{
                ++count;
            }
            prev = val;
            result[index] = count;
        }
        return result;
    }
};