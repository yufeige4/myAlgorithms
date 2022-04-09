#include <bits/stdc++.h>

using namespace std;

// 94. 二叉树的中序遍历
// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

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

    void inorderHelper(TreeNode* node, vector<int>& array){
        if(!node){
            return;
        }
        inorderHelper(node->left,array);
        array.emplace_back(node->val);
        inorderHelper(node->right,array);
    }
    // 递归
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> result;
        inorderHelper(root,result);
        return result;
    }

    // 非递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(!stk.empty()||node){
            // 处理左子树
            while(node){
                stk.push(node);
                node = node->left;
            }
            // 处理本身
            node = stk.top();
            stk.pop();
            result.push_back(node->val);
            // 处理右子树
            node = node->right;
        }
        return result;
    }
};