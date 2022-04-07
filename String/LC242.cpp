#include <bits/stdc++.h>

using namespace std;

// 242. 有效的字母异位词
// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26,0);
        int sizeA = s.size();
        int sizeB = t.size();
        int index;
        int val;
        if(sizeA!=sizeB){
            return false;
        }

        // 用hash记录s里的每个char的出现频率
        for(int i=0;i<sizeA;++i){
            index = s[i] - 'a';
            hash[index]++;
        }
        // 根据t中出现的每个元素，对hash中记录的频率进行递减
        // 若频率小于1则不为异位词
        for(int i=0;i<sizeB;++i){
            index = t[i] - 'a';
            val = hash[index];
            if(val<1){
                return false;
            }else{
                hash[index]--;
            }
        }
        return true;
    }
};