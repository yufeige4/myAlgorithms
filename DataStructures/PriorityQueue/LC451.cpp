#include <bits/stdc++.h>

using namespace std;

// 451. 根据字符出现频率排序

// 给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。

// 返回 已排序的字符串 。如果有多个答案，返回其中任何一个。

class Solution {
public:
    typedef pair<char,int> MyPair;
    string frequencySort(string s) {
        auto cmp = [] (MyPair& a, MyPair& b){
            return a.second<b.second;
        };
        string result;
        unordered_map<char,int> hash;
        for(auto& ch : s){
            hash[ch]++;
        }
        priority_queue<MyPair,vector<MyPair>,decltype(cmp)> pq(cmp);
        for(auto& p : hash){
            pq.push({p.first,p.second});
        }

        while(!pq.empty()){
            auto [ch,count] = pq.top();
            pq.pop();
            result.insert(result.end(),count,ch);
        }

        return result;
    }
};