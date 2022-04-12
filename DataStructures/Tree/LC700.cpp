#include <bits/stdc++.h>

using namespace std;

// 700. 二叉搜索树中的搜索

// 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

// 你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return NULL;
        }
        int nodeVal = root->val;
        if(nodeVal==val){
            return root;
        }else if(nodeVal<val){
            return searchBST(root->right,val);
        }else{
            return searchBST(root->left,val);
        }
    }
};