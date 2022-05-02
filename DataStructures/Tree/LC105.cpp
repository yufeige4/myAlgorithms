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

// 105. 从前序与中序遍历序列构造二叉树

// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

class Solution {
public:
    TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder,int inStart,int inEnd,int& size,int& preIndex){
        if(inStart>inEnd||preIndex>=size){
            return NULL;
        }
        int val = preorder[preIndex];
        int i;
        for(i=inStart;i<=inEnd;++i){
            if(inorder[i]==val){
                break;
            }
        }
        if(i==inEnd+1){
            return NULL;
        }
        preIndex++;
        TreeNode* node = new TreeNode(val);
        node->left = buildNode(preorder,inorder,0,i-1,size,preIndex);
        node->right = buildNode(preorder,inorder,i+1,inEnd,size,preIndex);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int count = 0;
        int size = inorder.size();
        return buildNode(preorder,inorder,0,size-1,size,count);
    }
};