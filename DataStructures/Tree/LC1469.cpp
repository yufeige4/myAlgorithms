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

// 1469. 寻找所有的独生节点

// 二叉树中，如果一个节点是其父节点的唯一子节点，则称这样的节点为 “独生节点” 。二叉树的根节点不会是独生节点，因为它没有父节点。

// 给定一棵二叉树的根节点 root ，返回树中 所有的独生节点的值所构成的数组 。数组的顺序 不限 。

class Solution {
public:
    void lonelyHelper(TreeNode* node,vector<int>& arr){
        if(node->left&&node->right){
            lonelyHelper(node->left,arr);
            lonelyHelper(node->right,arr);
        }else if(node->left||node->right){
            if(node->left){
                arr.push_back(node->left->val);
                lonelyHelper(node->left,arr);
            }else{
                arr.push_back(node->right->val);
                lonelyHelper(node->right,arr);
            }
        }
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        lonelyHelper(root,result);

        return result;
    }
};