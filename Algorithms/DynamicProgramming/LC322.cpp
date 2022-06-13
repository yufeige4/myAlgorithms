#include <bits/stdc++.h>

using namespace std;

// 322. 零钱兑换

// 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

// 你可以认为每种硬币的数量是无限的。

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 设置为canary值保证了可以判断结果合法不合法
        int canary = amount+1;
        // 凑成金额i所需硬币数
        // 因为 coins[i]>=1， 故合法dp[amount]一定小于等于amount
        vector<int> dp(amount+1,canary);
        dp[0] = 0;
        for(int i=1;i<=amount;++i){
            for(auto& val : coins){
                // 若i-val为合法的金额
                // 则dp[i] = 合法金额所需最小硬币数 + 1
                if(i-val>=0){
                    dp[i] = min(dp[i],dp[i-val]+1);
                }
            }
        }
        return dp[amount]>=canary? -1 : dp[amount];
    }
};