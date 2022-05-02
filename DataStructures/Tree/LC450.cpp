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

// 450. 删除二叉搜索树中的节点

// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        TreeNode DummyHead = TreeNode();
        DummyHead.left = root;
        // find node to delete
        TreeNode* parent = &DummyHead;
        TreeNode* node = root;
        while(node&&node->val!=key){
            parent = node;
            if(node->val>key){
                node = node->left;
            }else{
                node = node->right;
            }
        }
        // node to delete not exist
        if(!node) return DummyHead.left;
        // both left-child and right-child exist
        if(node->left&&node->right){
            TreeNode* subNode = node->right;
            while(subNode->left){
                subNode = subNode->left;
            }
            node->val = subNode->val;
            node->right = deleteNode(node->right,subNode->val);
        }else{
            if(parent->left==node){
                parent->left = node->left ? node->left : node->right;
            }else{
                parent->right = node->left? node->left : node->right;
            }
            delete(node);
        }
        return DummyHead.left;
    }
};