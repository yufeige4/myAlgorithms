#include <bits/stdc++.h>

using namespace std;

// 763. 划分字母区间

// 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

class Solution {
public:
    // Hash + Set 最初的想法
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int size = s.size();
        int pre = 0;
        int ch;
        bool flag;
        vector<int> rightHash(26,0);
        unordered_set<int> chList;
        for(int i=0;i<size;++i){
            ch = s[i] - 'a';
            rightHash[ch]++;
        }
        
        for(int i=0;i<size;++i){
            ch = s[i]-'a';
            chList.insert(ch);
            rightHash[ch]--;
            flag = true;
            for(auto& key : chList){
                if(rightHash[key]!=0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                result.push_back(i-pre+1);
                pre = i+1;
                chList.clear();
            }
        }
        return result;
    }
    // 贪心 + hash O(n)
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int size = s.size();
        vector<int> lastOccurPos(26,0);
        // 记录每个元素最后出现的下标位置
        for(int i=0;i<size;++i){
            lastOccurPos[s[i]-'a'] = i;
        }
        int start = 0;
        int end = 0;
        int temp;
        for(int i=0;i<size;++i){
            temp = lastOccurPos[s[i]-'a'];
            end = temp>end ? temp : end;
            // 当i==所有元素最后出现的下标位置的最大值
            if(i==end){
                result.push_back(end-start+1);
                start = end + 1;
            }
        }
        return result;
    }
};