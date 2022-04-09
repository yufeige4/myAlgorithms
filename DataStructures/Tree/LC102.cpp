#include <bits/stdc++.h>

using namespace std;

// 102. 二叉树的层序遍历

// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root){
            return result;
        }
        queue<TreeNode*> myQueue;
        TreeNode* node;
        int size;
        myQueue.push(root);
        while(!myQueue.empty()){
            vector<int> temp;
            size = myQueue.size();
            for(int i=0;i<size;++i){
                node = myQueue.front();
                temp.push_back(node->val);
                myQueue.pop();
                if(node->left) myQueue.push(node->left);
                if(node->right) myQueue.push(node->right);
            }
            result.push_back(temp);
        }
        return result;
    }
};
