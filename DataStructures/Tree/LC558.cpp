#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// 二进制矩阵中的所有元素不是 0 就是 1 。

// 给你两个四叉树，quadTree1 和 quadTree2。其中 quadTree1 表示一个 n * n 二进制矩阵，而 quadTree2 表示另一个 n * n 二进制矩阵。

// 请你返回一个表示 n * n 二进制矩阵的四叉树，它是 quadTree1 和 quadTree2 所表示的两个二进制矩阵进行 按位逻辑或运算 的结果。

// 注意，当 isLeaf 为 False 时，你可以把 True 或者 False 赋值给节点，两种值都会被判题机制 接受 。

// 四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：
// val：储存叶子结点所代表的区域的值。1 对应 True，0 对应 False；
// isLeaf: 当这个节点是一个叶子结点时为 True，如果它有 4 个子节点则为 False 。


class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(!quadTree1||!quadTree2) return NULL;
        if(quadTree1->isLeaf&&quadTree2->isLeaf){
            Node* curr = new Node();
            curr->isLeaf = true;
            curr->val = quadTree1->val || quadTree2->val;
            return curr;
        }else if(quadTree1->isLeaf){
            if(quadTree1->val){
                return quadTree1;
            }else{
                return quadTree2;
            }
        }else if(quadTree2->isLeaf){
            if(quadTree2->val){
                return quadTree2;
            }else{
                return quadTree1;
            }
        }
        // 两者都非叶子节点
        auto node1 = intersect(quadTree1->topLeft,quadTree2->topLeft);
        auto node2 = intersect(quadTree1->topRight,quadTree2->topRight);
        auto node3 = intersect(quadTree1->bottomLeft,quadTree2->bottomLeft);
        auto node4 = intersect(quadTree1->bottomRight,quadTree2->bottomRight);
        bool allLeaf = node1->isLeaf && node2->isLeaf && node3->isLeaf && node4->isLeaf;
        bool allOne = node1->val && node2->val && node3->val && node4->val;
        if(allLeaf&&allOne){
            return new Node(1,1);
        }else{
            return new Node(0,0,node1,node2,node3,node4);
        }
    }
};