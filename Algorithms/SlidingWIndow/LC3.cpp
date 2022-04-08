#include <bits/stdc++.h>

using namespace std;

// 3. 无重复字符的最长子串

// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

class Solution {
public:
    // 暴力+hash map
    int lengthOfLongestSubstring1(string s) {
        int size = s.size();
        if(size==0){
            return 0;
        }else if(size==1){
            return 1;
        }
        int i = 0;
        int j = 0;
        int temp;
        int maxLen = 1;
        unordered_map<char,int> hash;
        while(i<size){
            j = i;
            while(j<size&&hash.find(s[j])==hash.end()){
                hash[s[j]] = j;
                ++j;
            }
            temp = j-i;
            maxLen = maxLen<temp ? temp : maxLen;
            if(j>=size){
                break;
            }
            i = hash[s[j]]+1;
            hash.clear();
        }
        return maxLen;
    }

    // 滑动窗口+hash set
    int lengthOfLongestSubstring2(string s) {
        int size = s.size();
        if(size==0){
            return 0;
        }else if(size==1){
            return 1;
        }
        int maxLen = 1;
        int right = -1;
        unordered_set<char> hashSet;

        for(int left=0;left<size;++left){
            if(left!=0){
                hashSet.erase(s[left-1]);
            }
            while(right+1<size&&hashSet.find(s[right+1])==hashSet.end()){
                hashSet.insert(s[right+1]);
                ++right;
            }
            maxLen = right-left+1>maxLen ? right-left+1 : maxLen ;
        }
        return maxLen;
    }
};