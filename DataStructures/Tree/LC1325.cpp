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

// 1325. 删除给定值的叶子节点

// 给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的 叶子节点 。

// 注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。

// 也就是说，你需要重复此过程直到不能继续删除。

class Solution {
public:

    TreeNode* removeLeafNodes(TreeNode* node, int target) {
        if(node==NULL) return NULL;
        node->left = removeLeafNodes(node->left,target);
        node->right = removeLeafNodes(node->right,target);
        if(!node->left&&!node->right && node->val==target){
            node = NULL;
        }
        return node;
    }
    
};