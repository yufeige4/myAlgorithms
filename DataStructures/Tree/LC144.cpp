#include <bits/stdc++.h>

using namespace std;

// 144. 二叉树的前序遍历
// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

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

    // 递归实现
    void preorderHelper1(TreeNode* node,vector<int>& array){
        if(!node){
            return;
        }
        array.emplace_back(node->val);
        if(node->left) preorderHelper1(node->left,array);
        if(node->right) preorderHelper1(node->right,array);
    }
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> result;
        preorderHelper1(root,result);
        result.shrink_to_fit();
        return result;
    }

    // 非递归实现
    vector<int> preorderTraversal2(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> result;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* temp;
        while(!stk.empty()){
            temp = stk.top();
            stk.pop();
            result.emplace_back(temp->val);
            if(temp->right) stk.push(temp->right);
            if(temp->left) stk.push(temp->left);
        }
        return result;
    }
};