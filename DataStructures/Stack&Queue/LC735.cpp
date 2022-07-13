#include <bits/stdc++.h>

using namespace std;

// 735. 行星碰撞

// 给定一个整数数组 asteroids，表示在同一行的行星。
// 对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。
// 找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。

class Solution {
public:
    // 使用双端队列暴力
    vector<int> asteroidCollision1(vector<int>& asteroids) {
        deque<int> myQ;
        vector<int> result;
        for(auto& i : asteroids){
            bool diffDirect = i<0;
            bool boom = false;
            int val = abs(i);
            while(!myQ.empty()&&diffDirect&&val>=myQ.front()){
                if(val==myQ.front()){
                    boom = true;
                    myQ.pop_front();
                    break;
                }
                myQ.pop_front();
            }
            if(!boom){
               if(!diffDirect){
                   myQ.push_front(i);
               }else if(myQ.empty()){
                   result.push_back(i);
               }
            }
        }
        while(!myQ.empty()){
            result.push_back(myQ.back());
            myQ.pop_back();
        }
        return result;
    }
    // 数组模拟栈空间优化
    vector<int> asteroidCollision2(vector<int>& asteroids) {
        vector<int> result;
        for(auto& i : asteroids){
            bool diffDirect = i<0;
            bool boom = false;
            int val = abs(i);
            // 当行星没爆炸并 且 会发生碰撞 
            while(!boom&&!result.empty()&&diffDirect&&result.back()>0){
                boom = val<=result.back();
                if(val>=result.back()){
                    result.pop_back();
                }
            }
            if(!boom){
                result.push_back(i);
            }
        }
        return result;
    }
};