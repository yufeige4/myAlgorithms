#include <bits/stdc++.h>

using namespace std;

// 116. 填充每个节点的下一个右侧节点指针

// 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。

// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

// 初始状态下，所有 next 指针都被设置为 NULL。

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    // 利用queue进行level-order traverse
    Node* connect(Node* root) {
        if(!root){
            return NULL;
        }
        int size;
        Node* curr;
        Node* pre = root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            size = q.size();
            for(int i=0;i<size;++i){
                curr = q.front();
                q.pop();
                if(i==0){
                    pre = curr;
                }else{
                    pre->next = curr;
                    pre = curr;
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            curr->next = NULL;
        }
        return root;
    }
};