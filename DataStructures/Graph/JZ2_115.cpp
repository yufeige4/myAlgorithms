#include <bits/stdc++.h>

using namespace std;

// 剑指 Offer II 115. 重建序列

// 给定一个长度为 n 的整数数组 nums ，其中 nums 是范围为 [1，n] 的整数的排列。还提供了一个 2D 整数数组 sequences ，其中 sequences[i] 是 nums 的子序列。
// 检查 nums 是否是唯一的最短 超序列 。
// 最短 超序列 是 长度最短 的序列，并且所有序列 sequences[i] 都是它的子序列。对于给定的数组 sequences ，可能存在多个有效的 超序列 。

// 例如，对于 sequences = [[1,2],[1,3]] ，有两个最短的 超序列 ，[1,2,3] 和 [1,3,2] 。
// 而对于 sequences = [[1,2],[1,3],[1,2,3]] ，唯一可能的最短 超序列 是 [1,2,3] 。[1,2,3,4] 是可能的超序列，但不是最短的。

// 如果 nums 是序列的唯一最短 超序列 ，则返回 true ，否则返回 false 。
// 子序列 是一个可以通过从另一个序列中删除一些元素或不删除任何元素，而不改变其余元素的顺序的序列。

class Solution {
public:
    // 为了判断nums是不是序列的唯一最短超序列，只需要判断根据sequences中的每个序列构造超序列的结果是否唯一。
    // 可以将sequences 中的所有序列看成有向图 利用拓扑排序确定是否唯一最短超序列
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> indegrees(n+1,0);
        vector<unordered_set<int>> graph(n+1);

        for(auto& seq : sequences){
            // 对每个序列进行遍历 相邻元素[a,b]视为顶点a到顶点b的边
            int size = seq.size();
            int u,v;
            for(int i=1;i<size;++i){
                u = seq[i-1];
                v = seq[i];
                if(graph[u].count(v)==0){
                    graph[u].insert(v);
                    ++indegrees[v];
                }
            }
        }

        queue<int> myQ;
        for(int i=1;i<=n;++i){
            if(indegrees[i]==0){
                myQ.emplace(i);
            }
        }
        // 进行拓扑排序, 若唯一则true
        while(!myQ.empty()){
            if(myQ.size()>1) return false;
            int curr = myQ.front();
            myQ.pop();
            for(auto& next : graph[curr]){
                if(--indegrees[next]==0){
                    myQ.emplace(next);
                }
            }
        }
        return true;
    }
};