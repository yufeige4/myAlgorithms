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

// 1602. 找到二叉树中最近的右侧节点

// 给定一棵二叉树的根节点 root 和树中的一个节点 u ，返回与 u 所在层中距离最近的右侧节点，当 u 是所在层中最右侧的节点，返回 null 。

class Solution {
public:
    // levelOrder traverse
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if(root==NULL) return NULL;
        queue<TreeNode*> myQ;
        myQ.push(root);
        bool findU = false;
        while(!myQ.empty()){
            int size = myQ.size();
            for(int i=0;i<size;++i){
                TreeNode* curr = myQ.front();
                myQ.pop();
                if(findU) return curr;
                if(curr==u) findU = true;
                if(curr->left) myQ.push(curr->left);
                if(curr->right) myQ.push(curr->right);
            }
            if(findU) return NULL;
        }
        return NULL;
    }
};