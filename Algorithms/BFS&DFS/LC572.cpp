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

// 572. 另一棵树的子树

// 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。

// 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

class Solution {
public:
    bool isPerfectMatch(TreeNode* root, TreeNode* subRoot){
        if(!root&&!subRoot){
            return true;
        }else if(!root||!subRoot){
            return false;
        }
        if(root->val!=subRoot->val){
            return false;
        }
        return isPerfectMatch(root->left,subRoot->left) && isPerfectMatch(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root&&!subRoot){
            return true;
        }else if(!root||!subRoot){
            return false;
        }
        bool checkChild = isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        bool checkItself = root->val==subRoot->val && isPerfectMatch(root->left,subRoot->left) && isPerfectMatch(root->right,subRoot->right);
        
        return checkItself || checkChild;
    }
};