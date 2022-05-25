#include <bits/stdc++.h>

using namespace std;

// 1151. 最少交换次数来组合所有的 1

// 给出一个二进制数组 data，你需要通过交换位置，将数组中 任何位置 上的 1 组合到一起，并返回所有可能中所需 最少的交换次数。

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int size = data.size();
        int oneCount = 0;
        for(int i=0;i<size;++i){
            if(data[i]>0){
                ++oneCount;
            }
        }
        if(oneCount<=1){
            return 0;
        }
        // 窗口内1的数量
        int sum = 0;
        // oneCount为窗口大小
        for(int i=0;i<oneCount;++i){
            sum += data[i];
        }
        int maxSum = sum;
        for(int i=oneCount;i<size;++i){
            sum += data[i]-data[i-oneCount];
            maxSum = sum>maxSum ? sum:maxSum;
        }
        // 窗口大小-窗口内数量最多的1 = 最少需要移动的0的数量
        return oneCount-maxSum;
    }
};