#include <bits/stdc++.h>

using namespace std;

// 653. 两数之和 IV - 输入 BST

// 给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

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

    unordered_set<int> myHT;
    // HashTable + DFS
    bool findTarget1(TreeNode* root, int k) {
        if(!root) return false;
        if(myHT.count(k-root->val)>0){
            return true;
        }
        myHT.insert(root->val);
        return findTarget1(root->left,k) || findTarget1(root->right,k);
    }
    // HashTable + BFS
    bool findTarget2(TreeNode *root, int k) {
        unordered_set<int> hashTable;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (hashTable.count(k - node->val)) {
                return true;
            }
            hashTable.insert(node->val);
            if (node->left != nullptr) {
                que.push(node->left);
            }
            if (node->right != nullptr) {
                que.push(node->right);
            }
        }
        return false;
    }
};