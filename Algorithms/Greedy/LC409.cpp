#include <bits/stdc++.h>

using namespace std;

// 409. 最长回文串

// 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。

// 在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。

class Solution {
public:
    // 贪心
    int longestPalindrome(string s) {
        int count = 0;
        unordered_map<char,int> hash;
        for(auto const& ch : s){
            hash[ch]++;
        }
        for(auto& pair : hash){
            int temp = pair.second;
            // 可利用的字符数为 temp/2 * 2
            count += temp/2 * 2;
            // 第一次出现奇数个字符时可以利用其构造中间字符
            if(temp%2==1 && count%2==0){
                count++;
            }
        }
        return count;
    }
};