#include <bits/stdc++.h>

using namespace std;

// 347. 前 K 个高频元素

// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

class Solution {
public:
    typedef pair<int,int> MyPair;
    class MyCmp{
        public:
            bool operator() (MyPair& a,MyPair& b){
                return a.second>b.second;
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> hash;

        for(const auto& num : nums){
            hash[num]++;
        }
        // 小根堆
        priority_queue<MyPair,vector<MyPair>,MyCmp> pq;
        // 使pq中保持最多只有k个元素
        for(auto& pair : hash){
            if(pq.size()<k){
                pq.push({pair.first,pair.second});
            }else{
                if(pair.second>pq.top().second){
                    pq.pop();
                    pq.push({pair.first,pair.second});
                }
            }
        }

        for(int i=0;i<k;++i){
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;

    }
};