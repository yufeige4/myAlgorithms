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

// 337. 打家劫舍 III

// 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

// 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
// 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

// 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。

class Solution {
private:
    struct NodeStatus{
        int robbed;
        int notRobbed;
    };
public:
    // my first thought 超时 思路正确 但是会对同一个node的两个状态分别call一次递归
    // int dfs(TreeNode* node,bool steal){
    //     if(!node) return 0;
    //     int val = 0;
    //     if(steal){
    //         val = node->val+dfs(node->left,false)+dfs(node->right,false);
    //     }else{
    //         val = max(dfs(node->left,false),dfs(node->left,true))+max(dfs(node->right,false),dfs(node->right,true));
    //     }
    //     return val;
    // }
    // int rob(TreeNode* root) {
    //     return max(dfs(root,true),dfs(root,false));
    // }

    NodeStatus dfs(TreeNode* node){
        if(!node) return {0,0};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        int steal = node->val + left.notRobbed + right.notRobbed;
        int notSteal = max(left.notRobbed,left.robbed) + max(right.notRobbed,right.robbed);
        return {steal,notSteal};
    }
    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.robbed,result.notRobbed);

    }
};