#include <bits/stdc++.h>

using namespace std;

// 101. 对称二叉树

// 给你一个二叉树的根节点 root ， 检查它是否轴对称。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymHelper(TreeNode* left,TreeNode* right){
        if(!left&&!right){
            return true;
        }
        if(!left||!right){
            return false;
        }
        if(left->val!=right->val){
            return false;
        }
        return isSymHelper(left->left,right->right) && isSymHelper(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return false;
        }
        return isSymHelper(root->left,root->right);
    }
};