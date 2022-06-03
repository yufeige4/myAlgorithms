#include <bits/stdc++.h>

using namespace std;

// 394. 字符串解码

// 给定一个经过编码的字符串，返回它解码后的字符串。

// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

class Solution {
public:
    string decodeString(string s) {
        string result = "";
        stack <int> nums;
        stack <string> strStk;
        int num = 0;
        int len = s.size();
        for(int i=0;i<len;++i){
            if(s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + s[i] - '0';
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                result = result + s[i];
            }else if(s[i] == '['){
                // 将‘[’前的数字压入nums栈内，字母字符串压入strStk栈内
                nums.push(num);
                num = 0;
                strStk.push(result);
                // 清空现有的字符串
                result = "";
            }else{
                // 找到']'之前存储的字符串
                int multi = nums.top();
                nums.pop();
                for(int j=0;j<multi;++j){
                    // 将之前记录的字符串根据重复倍数加到之前strStk保存的字符串中
                    strStk.top() += result;
                }
                result = strStk.top(); 
                // 之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
                // 若是左括号，res会被压入strStk栈，作为上一层的运算
                strStk.pop();
            }
        }
        return result;
    }
};