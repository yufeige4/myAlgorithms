#include <bits/stdc++.h>

using namespace std;

// 98. 验证二叉搜索树

// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

// 有效 二叉搜索树定义如下：
// 节点的左子树只包含 小于 当前节点的数。
// 节点的右子树只包含 大于 当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。

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
    bool isBSTHelper(TreeNode* root,long upper, long lower){
        if(!root) return true;
        bool flag = root->val<upper && root->val>lower;
        flag = flag && (!root->left||root->left->val<root->val);
        flag = flag && (!root->right||root->right->val>root->val);
        return flag && isBSTHelper(root->left,root->val,lower) && isBSTHelper(root->right,upper,root->val);
    }

    bool isValidBST(TreeNode* root) {
        long upper = (long)INT_MAX+1;
        long lower = (long)INT_MIN-1;
        return isBSTHelper(root,upper,lower);
    }
};