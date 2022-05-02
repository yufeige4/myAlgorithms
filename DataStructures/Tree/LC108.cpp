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

// 108. 将有序数组转换为二叉搜索树

// 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

// 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

class Solution {
public:
    // 每次取中间值构造结点
    TreeNode* convertToBST(vector<int>& nums,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid = (start+end)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = convertToBST(nums,start,mid-1);
        node->right = convertToBST(nums,mid+1,end);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();

        TreeNode* root = convertToBST(nums,0,size-1);
        return root;
    }
};