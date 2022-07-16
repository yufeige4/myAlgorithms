#include <bits/stdc++.h>

using namespace std;

// ��ָ Offer II 041. �������ڵ�ƽ��ֵ

// ����һ��������������һ�����ڴ�С�����ݸû������ڵĴ�С�����㻬���������������ֵ�ƽ��ֵ��

// ʵ�� MovingAverage �ࣺ
// MovingAverage(int size) �ô��ڴ�С size ��ʼ������
// double next(int val)?��Ա���� next?ÿ�ε��õ�ʱ�򶼻���������������һ������������㲢��������������� size ��ֵ���ƶ�ƽ��ֵ���������������������ֵ�ƽ��ֵ��

class MovingAverage {
private:
    // ʹ��vectorģ�����ʵ�ֻ�������
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