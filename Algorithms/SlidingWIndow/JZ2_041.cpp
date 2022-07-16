#include <bits/stdc++.h>

using namespace std;

// 剑指 Offer II 041. 滑动窗口的平均值

// 给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

// 实现 MovingAverage 类：
// MovingAverage(int size) 用窗口大小 size 初始化对象。
// double next(int val)?成员函数 next?每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size 个值的移动平均值，即滑动窗口里所有数字的平均值。

class MovingAverage {
private:
    // 使用vector模拟队列实现滑动窗口
    vector<int> result_;
    int maxSize_;
    int currSize_;
    double currSum_;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        result_.resize(size);
        maxSize_ = size;
        currSize_ = 0;
        currSum_ = 0;
    }
    
    double next(int val) {
        if(currSize_<maxSize_){
            result_[currSize_] = val;
            ++currSize_;
            currSum_ += val;
            return currSum_/currSize_;
        }
        currSum_ -= result_[currSize_%maxSize_];
        currSum_ += val;
        result_[currSize_%maxSize_] = val;
        ++currSize_;
        return currSum_/maxSize_;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */