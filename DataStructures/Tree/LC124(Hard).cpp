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

// 124. 二叉树中的最大路径和

// 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。
// 该路径 至少包含一个 节点，且不一定经过根节点。

// 路径和 是路径中各节点值的总和。

// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

class Solution {
public:
    // 返回可延长的经过该结点的路径，同时更新最大路径
    int maxPathHelper(TreeNode* node,int& maxPath){
        if(!node) return 0;
        // 记录左右孩子的贡献值的同时也更新最大路径   
        int leftMaxPath = max(maxPathHelper(node->left,maxPath),0);
        int rightMaxPath = max(maxPathHelper(node->right,maxPath),0);
        
        int pathCrossNode = leftMaxPath + rightMaxPath + node->val;
        // 更新最大路径
        maxPath = max(maxPath,pathCrossNode);

        return max(leftMaxPath,rightMaxPath)+node->val;
    }

    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;

        maxPathHelper(root,result);
        return result;
    }
};