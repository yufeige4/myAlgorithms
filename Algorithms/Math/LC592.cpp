#include <bits/stdc++.h>

using namespace std;

// 592. 分数加减运算

// 给定一个表示分数加减运算的字符串 expression ，你需要返回一个字符串形式的计算结果。 

// 这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2 应该被转换为 2/1。

class Solution {
public:
    const int UNDEFINED = 0;

    inline long long gcd(long long a,long long b) {    
        return b>0 ? gcd(b,a%b):a;
    }

    string fractionAddition(string expression) {
        long long numerator = 0;
        long long denominator = 1;
        auto it = expression.begin();
        auto end = expression.end();
        int sign = 1;
        while(it!=end){
            int tempNumerator = UNDEFINED;
            int tempDenominator = UNDEFINED;
            bool isFinished = false;
            while(it!=end&&*it!='+'&&*it!='-'){
                if(*it=='/'){
                    ++it;
                    isFinished = true;
                    continue;
                }
                if(!isFinished){
                    // 获取分子
                    while(isdigit(*it)){
                        tempNumerator = tempNumerator*10 + *it-'0';
                        ++it;
                    }
                    isFinished = true;
                }else{
                    // 获取分母
                    while(isdigit(*it)){
                        tempDenominator = tempDenominator*10 + *it-'0';
                        ++it;
                    }
                }
            }
            if(tempNumerator!=UNDEFINED){
                // 计算当前分子分母和新获取的分子分母做加法后的结果
                numerator = numerator*tempDenominator + sign*tempNumerator*denominator;
                denominator *= tempDenominator;
            }
            sign = (*it=='+' ? 1 : -1);
            if(it==end) break;
            ++it;
        }
        // 化简
        int div = gcd(abs(numerator),denominator);
        numerator /= div;
        denominator /= div;
        // 转化成string格式并输出
        return to_string(numerator)+"/"+to_string(denominator);
    }
};