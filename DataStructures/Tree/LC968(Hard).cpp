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

// 968. 监控二叉树

// 给定一个二叉树，我们在树的节点上安装摄像头。

// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

// 计算监控树的所有节点所需的最小摄像头数量。

class Solution {
private:
    struct NodeStatus{
        int putCam; //此结点放置cam的前提下,该树watched
        int whateverPut; //无论放置与否,该书watched
        int notPutCam; //子树watched
    };
public:
    NodeStatus minCamHelper(TreeNode* node){
        if(!node) return {INT_MAX/2,0,0};

        auto left = minCamHelper(node->left);
        auto right = minCamHelper(node->right);

        int putCam = 1+left.notPutCam+right.notPutCam;
        int whateverPut = min(putCam,min(left.whateverPut+right.putCam,left.putCam+right.whateverPut));
        int notPutCam = min(putCam,left.whateverPut+right.whateverPut);

        return {putCam,whateverPut,notPutCam};
    }
    int minCameraCover(TreeNode* root) {
    
        auto result = minCamHelper(root);
        return min(result.putCam,result.whateverPut);
    }
};