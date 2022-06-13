#include <bits/stdc++.h>

using namespace std;

// 343. 整数拆分

// 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

// 返回 你可以获得的最大乘积 。


class Solution {
public:
    int integerBreak(int n) {
        // dp[i]表示整数i所能拆成的最大乘积
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;++i){
            for(int j=1;j<i;++j){
                // 两种拆法
                // (i-j)*(j) j不再拆分
                // (i-j)*dp[j] j也是一个可拆的整数
                dp[i] = max(dp[i],max((i-j)*j,dp[j]*(i-j)));
            }
        }
        return dp[n];
    }
};
