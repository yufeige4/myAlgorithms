#include <bits/stdc++.h>

using namespace std;

// 36. 有效的数独

// 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()<9){
            return false;
        }
        char horizon[9][9];
        char vertical[9][9];
        char square[3][3][9];
        memset(horizon,0,sizeof(horizon));
        memset(vertical,0,sizeof(vertical));
        memset(square,0,sizeof(square));
        char temp;
        int index;
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                temp = board[i][j];
                index = temp - '1';
                if(temp!='.'){
                    horizon[i][index]++;
                    vertical[j][index]++;
                    square[i/3][j/3][index]++;
                    if(horizon[i][index]>1||vertical[j][index]>1||square[i/3][j/3][index]>1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};