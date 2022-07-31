#include <bits/stdc++.h>

using namespace std;

// 1161. 最大层内元素和

// 给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。

// 请返回层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。



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
    // level-order traverse
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> myQ;
        myQ.push(root);
        int level = 1;
        int maxLevel = 0;
        int maxSum = INT_MIN;
        while(!myQ.empty()){
            int size = myQ.size();
            int sum = 0;
            for(int i=0;i<size;++i){
                TreeNode* temp = myQ.front();
                myQ.pop();
                sum +=  temp->val;
                if(temp->left) myQ.push(temp->left);
                if(temp->right) myQ.push(temp->right);
            }
            if(sum>maxSum){
                maxSum = sum;
                maxLevel = level;
            }
            ++level;
        }
        return maxLevel;
    }
};