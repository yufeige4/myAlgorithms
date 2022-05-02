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

// 113. 路径总和 II

// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

// 叶子节点 是指没有子节点的节点。

class Solution {
public:
    void dfs(TreeNode* node, vector<vector<int>>& result,vector<int>& temp,int targetSum){
        if(!node){
            return;
        }
        int val = node->val;
        temp.push_back(val);
        if(!node->left&&!node->right){
            if(val==targetSum){
                result.push_back(temp);
            }
        }
        if(node->left){
            dfs(node->left,result,temp,targetSum-val);
        }
        if(node->right){
            dfs(node->right,result,temp,targetSum-val);
        }
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(root,result,temp,targetSum);
        return result;
    }
};