#include <bits/stdc++.h>

using namespace std;

// 565. ����Ƕ��

// ������0��ʼ����ΪN������A������0��N - 1�������������ҵ����ļ���S���������С������ S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }���������µĹ���

// ����ѡ������Ϊi��Ԫ��A[i]ΪS�ĵ�һ��Ԫ�أ�S����һ��Ԫ��Ӧ����A[A[i]]��֮����A[A[A[i]]]... �Դ����ƣ��������ֱ��S�����ظ���Ԫ�ء�

class Solution {
public:
    // ���ܴ��ڻ�, �ҳ����Ļ�
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int maxSize = 0;
        for(int i=0;i<n;++i){
            int count = 0;
            while(nums[i]!=-1){
                int temp = nums[i];
                nums[i] = -1;
                i = temp;
                ++count;
            }
            maxSize = max(maxSize,count);
        }
        return maxSize;
    }
};