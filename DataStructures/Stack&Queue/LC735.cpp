#include <bits/stdc++.h>

using namespace std;

// 735. ������ײ

// ����һ���������� asteroids����ʾ��ͬһ�е����ǡ�
// ���������е�ÿһ��Ԫ�أ������ֵ��ʾ���ǵĴ�С��������ʾ���ǵ��ƶ���������ʾ�����ƶ�������ʾ�����ƶ�����ÿһ����������ͬ���ٶ��ƶ���
// �ҳ���ײ��ʣ�µ��������ǡ���ײ�������������໥��ײ����С�����ǻᱬը������������Ǵ�С��ͬ�����������Ƕ��ᱬը�������ƶ�������ͬ�����ǣ���Զ���ᷢ����ײ��

class Solution {
public:
    // ʹ��˫�˶��б���
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
    // ����ģ��ջ�ռ��Ż�
    vector<int> asteroidCollision2(vector<int>& asteroids) {
        vector<int> result;
        for(auto& i : asteroids){
            bool diffDirect = i<0;
            bool boom = false;
            int val = abs(i);
            // ������û��ը�� �� �ᷢ����ײ 
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