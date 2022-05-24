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

// 236. 二叉树的最近公共祖先

// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

// 所有 Node.val 互不相同 。
// p != q
// p 和 q 均存在于给定的二叉树中。

class Solution {
public:
    bool dfs(TreeNode* curr,TreeNode* p,TreeNode* q,TreeNode* &result){
        if(curr==NULL) return false;
        bool lChild = dfs(curr->left,p,q,result);
        bool rChild = dfs(curr->right,p,q,result);
        // 判断是否为公共祖先
        // 一左一右或者结点本身为p或q
        if(lChild&&rChild || (curr->val==p->val||curr->val==q->val)&&(lChild||rChild)) {
            result = curr;
        }

        return lChild || rChild || curr->val==p->val || curr->val==q->val;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = NULL;
        dfs(root,p,q,result);
        return result;
    }
};