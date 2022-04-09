#include <bits/stdc++.h>

using namespace std;

// 145. 二叉树的后序遍历

// 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

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
    void postorderHelper(TreeNode* node,vector<int>& array){
        if(!node){
            return;
        }
        if(node->left) postorderHelper(node->left,array);
        if(node->right) postorderHelper(node->right,array);
        array.push_back(node->val);
    }

    // 递归
    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int> result;
        postorderHelper(root,result);
        return result;
    }

    // 非递归
    vector<int> postorderTraversal2(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        TreeNode* node = root;
        stack<TreeNode*> nodeStk;
        stack<int> flagStk;
        int flag;
        while(!nodeStk.empty()||node){
            while(node){
                // 左子树进栈
                nodeStk.push(node);
                flagStk.push(0);
                node = node->left;
            }
            node = nodeStk.top();
            flag = flagStk.top();
            nodeStk.pop();
            flagStk.pop();
            if(flag==0){
                // 第一次处理，进栈并处理右子树
                nodeStk.push(node);
                flagStk.push(1);
                node = node->right;
            }else{
                // 第二次处理, 访问该结点
                result.push_back(node->val);
                node = NULL;
            }
        }
        return result;
    }
};