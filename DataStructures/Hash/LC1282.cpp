#include <bits/stdc++.h>

using namespace std;

// 1282. 用户分组

// 有 n 个人被分成数量未知的组。每个人都被标记为一个从 0 到 n - 1 的唯一ID 。

// 给定一个整数数组 groupSizes ，其中 groupSizes[i] 是第 i 个人所在的组的大小。例如，如果 groupSizes[1] = 3 ，则第 1 个人必须位于大小为 3 的组中。

// 返回一个组列表，使每个人 i 都在一个大小为 groupSizes[i] 的组中。

// 每个人应该 恰好只 出现在 一个组 中，并且每个人必须在一个组中。如果有多个答案，返回其中 任何 一个。可以 保证 给定输入 至少有一个 有效的解。

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> result;
        // map size of group to people
        unordered_map<int,vector<int>> sizeGroup;
        for(int i=0;i<n;++i){
            sizeGroup[groupSizes[i]].push_back(i);
        }
        for(const auto& [sizeOfGroup,totalPeople] : sizeGroup){
            int count = totalPeople.size()/sizeOfGroup;
            for(int i=0;i<count;++i){
                int start = i*sizeOfGroup;
                vector<int> temp;
                for(int j=0;j<sizeOfGroup;++j){
                    temp.push_back(sizeGroup[sizeOfGroup][start+j]);
                }
                result.push_back(temp);
            }
        }
        return result;
    }
};