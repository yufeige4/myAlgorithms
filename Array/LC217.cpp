#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0){
            return false;
        }
        unordered_map<int,bool> hash;
        for(auto i:nums){
            if(hash.find(i)==hash.end()){
                hash[i] = true;
            }else{
                return true;
            }
        }
        return false;
    }
};