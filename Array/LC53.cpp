#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // dp 
        int temp = 0;
        int maxVal  = INT_MIN;
        for(const auto &i : nums){
            temp = max(temp+i,i);
            maxVal = max(temp,maxVal);
        }
        return maxVal;
    }
};