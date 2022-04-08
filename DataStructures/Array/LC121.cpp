#include <bits/stdc++.h>

using namespace std;

// 121. 买卖股票的最佳时机

// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyVal = INT_MAX;
        int profit = 0;
        for(const auto& price:prices){
            // 每次计算利润若利润大则修改profit 若price低于buyVal则修改buyVal
            profit = profit<price-buyVal ? price-buyVal : profit;
            buyVal = buyVal>price ? price : buyVal;
        }
        return profit;
    }
};