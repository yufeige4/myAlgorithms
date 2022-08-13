#include <bits/stdc++.h>

using namespace std;

// 768. 最多能完成排序的块 II

// 这个问题和“最多能完成排序的块”相似，但给定数组中的元素可以重复，输入数组最大长度为2000，其中的元素最大为10**8。

// arr是一个可能包含重复元素的整数数组，我们将这个数组分割成几个“块”，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。

// 我们最多能将数组分成多少块？

class Solution {
public:
    // My first attempt, trash code O(n) using mono stack
    // int maxChunksToSorted(vector<int>& arr) {
    //     int size = arr.size();
    //     stack<pair<int,int>> monoStk;
    //     monoStk.push(make_pair(arr[0],arr[0]));
    //     int blockMax = arr[0];
    //     int blockMin = arr[0];
    //     for(int i=1;i<size;++i){
    //         if(monoStk.empty()||arr[i]>=blockMax){
    //             monoStk.push(make_pair(arr[i],arr[i]));
    //             blockMax = arr[i];
    //         }else if(arr[i]<blockMin){
    //             blockMin = arr[i]; 
    //             monoStk = stack<pair<int,int>>();
    //             monoStk.push(make_pair(blockMin,blockMax));
    //         }else{
    //             while(!monoStk.empty()&&monoStk.top().first>arr[i]){
    //                 monoStk.pop();
    //             }
    //             if(monoStk.empty()){
    //                 monoStk.push(make_pair(blockMin,blockMax));
    //             }
    //             if(monoStk.top().second>arr[i]){
    //                 int left = monoStk.top().first;
    //                 monoStk.pop();
    //                 monoStk.push(make_pair(left,blockMax));
    //             }else{
    //                 monoStk.push(make_pair(arr[i],blockMax));
    //             }
    //         }
    //     }
    //     return monoStk.size();
    // }

    // 如果新添加的数字大于或等于原数组最后一个块的最大值，则这个新添加的数字可以自己形成一个块。
    // 如果新添加的数字小于原数组最后一个块的最大值，则它必须融入最后一个块。
    // 如果它大于或等于原数组倒数第二个块（如果有）的最大值，那么这个过程可以停止，新数组的分块方式已经求得。
    // 否则，它将继续融合原数组倒数第二个块，直到遇到一个块，使得该块的最大值小于或等于这个新添加的数，或者这个数字已经融合了所有块。
    
    // 经过以上思路优化
    // 使用仅保存最大值的单调栈
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> monoStk;
        for(const auto& num : arr){
            if(monoStk.empty()||num>=monoStk.top()){
                monoStk.push(num);
            }else{
                int maxNum = monoStk.top();
                monoStk.pop();
                while(!monoStk.empty()&&num<monoStk.top()){
                    monoStk.pop();
                }
                monoStk.push(maxNum);
            }
        }
        return monoStk.size();
    }
    


};
