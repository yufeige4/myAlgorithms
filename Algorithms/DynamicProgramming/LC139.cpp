#include <bits/stdc++.h>

using namespace std;

// 139. 单词拆分

// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        unordered_set<string> mySet;
        int minSize = INT_MAX;
        int maxSize = INT_MIN;
        int temp;
        for(auto& str : wordDict){
            temp = str.size();
            minSize = min(minSize,temp);
            maxSize = max(maxSize,temp);
            mySet.insert(str);
        }
        int end = 0;
        int start = 0;
        vector<bool> dp(size+1,false);
        dp[0] = true;
        while(start+minSize<=size){
            // 若该位置不可到达 则直接跳过
            if(dp[start]==false){
                ++start;
                continue;
            }
            // 将可到达的位置更新为true
            for(int k=minSize;k<=maxSize;++k){
                if(start+k>size || dp[start+k]) continue;
                if(mySet.find(s.substr(start,k))!=mySet.end()){
                    dp[start+k] = true;
                }
            }
            ++start;
        }
        return dp[size];
    }
};