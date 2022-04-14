#include <bits/stdc++.h>

using namespace std;

// 110. 平衡二叉树

// 给定一个二叉树，判断它是否是高度平衡的二叉树。

// 本题中，一棵高度平衡二叉树定义为：

// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

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
    int getDepth(TreeNode* node){
        if(!node) return 0;
        return 1 + max(getDepth(node->left),getDepth(node->right));
    }

    // 自顶向下递归 O(n^2)
    bool isBalanced1(TreeNode* root) {
        if(!root) return true;
        if(abs(getDepth(root->left)-getDepth(root->right))>1){
            return false;
        }
        return isBalanced1(root->left)&&isBalanced1(root->right);
    }

    // 自下而上递归 O(n)
    // 利用return value 隐式的包含结点高度和是否平衡这些信息
    int height(TreeNode* node){
        if(!node) return 0;
        int result;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if(leftHeight==-1 || rightHeight==-1 || abs(rightHeight-leftHeight)>1){
            result = -1;
        }else{
            result = leftHeight>rightHeight? leftHeight+1 : rightHeight+1;
        }
        return result;
    }
    bool isBalanced2(TreeNode* root) {
        if(!root) return true;
        return height(root)>=0;
    }
};