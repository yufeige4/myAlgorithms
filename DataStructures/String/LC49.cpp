#include <bits/stdc++.h>

using namespace std;

// 49. 字母异位词分组

// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

// 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

class Solution {
public:

    // 第一时间想到的方法 暴力破 超时
    bool isAna(string& a, string& b){
        int sizeA = a.size();
        int sizeB = b.size();
        if(sizeA!=sizeB) return false;
        vector<int> hash(26,0);
        for(int i=0;i<sizeA;++i){
            hash[a[i]-'a']++;
        }
        int ch;
        for(int i=0;i<sizeB;++i){
            ch = b[i]-'a';
            hash[ch]--;
            if(hash[ch]<0){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> result;
        result.push_back({strs[0]});
        for(int i=1;i<size;++i){
            int isNew = true;
            for(auto& groups : result){
                if(isAna(groups[0],strs[i])){
                    groups.push_back(strs[i]);
                    isNew = false;
                    break;
                };
            }
            if(isNew){
                result.push_back({strs[i]});
            }
        }
        return result;
    }

    // 利用字母异位词排序后的字符串相同这一性质
    // 将排序后的字符串作为HashMap的key O(n klogk) k为字符串最大长度
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> result;
        unordered_map<string,vector<string>> hash;
        for(auto& str : strs){
            string key = str;
            sort(key.begin(),key.end());
            hash[key].push_back(str);
        }

        for(auto& pair : hash){
            result.push_back(pair.second);
        }
        return result;
    }

    // 利用字母异位词的每个字符出现次数相同这一性质
    // 将每个字符出现次数作为key O(n k sigma)
    // sigma为生成string为key的时间
    vector<vector<string>> groupAnagrams3(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> result;
        unordered_map<string,vector<string>> hash;
        for(auto& str : strs){
            string key = string(26,0);
            for(auto& c : str){
                key[c-'a']++;
            }
            hash[key].push_back(str);
        }

        for(auto& pair : hash){
            result.push_back(pair.second);
        }
        return result;
    }
};