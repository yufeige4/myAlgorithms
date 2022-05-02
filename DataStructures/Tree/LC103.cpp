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

// 103. 二叉树的锯齿形层序遍历

// 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        deque<TreeNode*> deq;
        bool flag = true;
        deq.push_back(root);
        int size;
        TreeNode* node;
        while(!deq.empty()){
            size = deq.size();
            vector<int> temp;
            for(int i=0;i<size;++i){
                if(flag){
                    node = deq.front();
                    deq.pop_front();
                    temp.push_back(node->val);
                    if(node->left){
                        deq.push_back(node->left);
                    }
                    if(node->right){
                        deq.push_back(node->right);
                    }
                }else{
                    node = deq.back();
                    deq.pop_back();
                    temp.push_back(node->val);
                    if(node->right){
                        deq.push_front(node->right);
                    }
                    if(node->left){
                        deq.push_front(node->left);
                    }
                }
            }
            flag = !flag;
            result.push_back(temp);
        }
        return result;

    }
};