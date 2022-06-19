#include "UnionFind.h"

// 1101. 彼此熟识的最早时间

// 在一个社交圈子当中，有 n 个人。每个人都有一个从 0 到 n - 1 的唯一编号。
// 我们有一份日志列表 logs，其中 logs[i] = [timestampi, xi, yi] 表示 xi 和 yi 将在同一时间 timestampi 成为朋友。

// 友谊是 相互 的。也就是说，如果 a 和 b 是朋友，那么 b 和 a 也是朋友。同样，如果 a 和 b 是朋友，或者 a 是 b 朋友的朋友 ，那么 a 和 b 是熟识友。

// 返回圈子里所有人之间都熟识的最早时间。如果找不到最早时间，就返回 -1 。

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        UnionFind myUF(n);
        for(auto& log : logs){
            myUF.unite(log[1],log[2]);
            if(myUF.setsNum()==1){
                return log[0];
            }
        }
        return -1;
    }
};