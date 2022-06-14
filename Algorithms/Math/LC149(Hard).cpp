#include <bits/stdc++.h>

using namespace std;

// 149. 直线上最多的点数

// 给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。

class Solution {
public:
    // 返回a,b的最大公约数，若b为0则gcd=a
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }
        int result = 0;
        for (int i=0;i<n;++i) {
            // 当我们找到一条直线经过了图中超过半数的点时，我们即可以确定该直线即为经过最多点的直线；
            // 当我们枚举到点i（假设编号从0开始）时，我们至多只能找到n-i个点共线。
            // 假设此前找到的共线的点的数量的最大值为 k，如果有 k≥n−i，那么此时我们即可停止枚举，因为不可能再找到更大的答案了
            if (result>=n-i || result>n/2) {
                break;
            }
            unordered_map<int, int> myHash;
            // 避免重复所以直接从i+1开始
            for (int j=i+1;j<n;++j) {
                // 斜率的分母x,分子y
                int x = points[i][0]-points[j][0];
                int y = points[i][1]-points[j][1];
                // 若x为0
                if(x==0){
                    // 将y置1
                    y=1;
                }else if(y==0){
                    // 将x置1
                    x=1;
                }else{
                    // 若有符号则出现在分母上
                    if(y<0) {
                        x=-x;
                        y=-y;
                    }
                    // 找到其最大公约数
                    int gcdXY = gcd(abs(x), abs(y));
                    // 处理
                    x/=gcdXY;
                    y/=gcdXY;
                }
                // 手动hash 将x,y二元组映射在一元上 f(x,y) = y + x*20001;
                myHash[y+x*20001]++;
            }
            // 找出根据x点所连的所有直线中包含的最大点数
            int num = 0;
            for (auto& p : myHash) {
                num = max(num,p.second+1);
            }
            result = max(result, num);
        }
        return result;
    }
};