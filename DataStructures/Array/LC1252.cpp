#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // ֱ��ģ�� O(q*m*n+m*n)
    int oddCells1(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(m,vector<int>(n,0));
        for(auto& index : indices){
            for(int i=0;i<n;++i){
                matrix[index[0]][i]++;
            }
            for(int i=0;i<m;++i){
                matrix[i][index[1]]++;
            }
        }
        int result = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]%2!=0){
                    result++;
                }
            }
        }
        return result;
    }
    // �ռ�ģ���Ż� O(q+m*n)
    int oddCells2(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m,0);
        vector<int> cols(n,0);
        for(auto& index : indices){
            rows[index[0]]++;
            cols[index[1]]++;
        }
        int result = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if((rows[i]+cols[j])%2!=0){
                    result++;
                }
            }
        }
        return result;
    }
    // �����ݳ�ԭ����м����Ż�
    int oddCells3(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m,0);
        vector<int> cols(n,0);
        for(auto& index : indices){
            rows[index[0]]++;
            cols[index[1]]++;
        }
        int oddRows = 0;
        int oddCols = 0;
        for(int i=0;i<m;++i){
            if(rows[i]%2){
                ++oddRows;
            }
        }
        for(int i=0;i<n;++i){
            if(cols[i]%2){
                ++oddCols;
            }
        }
        int evenRows = m - oddRows;
        int evenCols = n - oddCols;
        return evenCols*oddRows+oddCols*evenRows;
    }
};