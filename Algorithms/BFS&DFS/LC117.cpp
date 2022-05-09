#include <bits/stdc++.h>

using namespace std;

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

// 117. 填充每个节点的下一个右侧节点指针 II

// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

// 初始状态下，所有 next 指针都被设置为 NULL。

// 进阶：

// 你只能使用常量级额外空间。
// 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

class Solution {
public:
    // 利用next遍历该层的同时更新下一层
    Node* connect(Node* root) {
        if(!root){
            return NULL;
        }
        Node* curr = root;
        Node dummyNode = Node();
        Node* pre = NULL;
        while(curr){
            dummyNode.next = NULL;
            pre = &dummyNode;
            while(curr){
                if(curr->left){
                    pre->next = curr->left;
                    pre = pre->next;
                }
                if(curr->right){
                    pre->next = curr->right;
                    pre = pre->next;
                }
                curr = curr->next;
            }
            curr = dummyNode.next;
        }
        return root;
    }
};