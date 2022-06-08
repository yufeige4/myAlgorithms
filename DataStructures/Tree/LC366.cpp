#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 366. 寻找二叉树的叶子节点
// 给你一棵二叉树，请按以下要求的顺序收集它的全部节点：

// 依次从左到右，每次收集并删除所有的叶子节点
// 重复如上过程直到整棵树为空
 
class Solution {
public:
    int getHeight(TreeNode* node,vector<vector<int>>& result){
        if(!node) return -1;
        // 去左子树删除叶子结点并计算左孩子的层数
        int left = getHeight(node->left,result);
        // 去右子树删除叶子结点并计算右孩子的层数
        int right = getHeight(node->right,result);
        // 根据左右孩子的层数计算此结点的层数
        int nodeHeight = max(left,right)+1;
        // 若层数大于最大层数，更新最大层数
        if(nodeHeight>=result.size()) result.push_back({});
        // 将该结点加入那层中
        result[nodeHeight].push_back(node->val);
        //返回此结点的层数
        return nodeHeight;
    }
    // 此题的本质是从外到内一层一层的删除叶子结点
    // 只需通过后序遍历DFS计算出该结点的层数即可
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        getHeight(root,result);
        return result;
    }
};

