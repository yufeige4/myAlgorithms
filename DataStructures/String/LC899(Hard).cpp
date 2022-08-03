#include <bits/stdc++.h>

using namespace std;

// 899. 有序队列

// 给定一个字符串 s 和一个整数 k 。你可以从 s 的前 k 个字母中选择一个，并把它加到字符串的末尾。

// 返回 在应用上述步骤的任意数量的移动后，字典上最小的字符串 。

// 分类讨论 k=1 和 k>1
class Solution {
public:
    string orderlyQueue(string s, int k) {
        int size = s.size();
        if(k==1){
            string minStr = s;
            for(int i=1;i<size;++i){
                string temp = s.substr(i)+s.substr(0,i);
                if(temp<minStr){
                    minStr = temp;
                }
            }
            return minStr;
        }
        sort(s.begin(),s.end());
        return s;
    }
};