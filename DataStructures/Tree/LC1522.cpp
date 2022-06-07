#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// 1522. N 叉树的直径

// 给定一棵 N 叉树的根节点 root ，计算这棵树的直径长度。

// N 叉树的直径指的是树中任意两个节点间路径中 最长 路径的长度。这条路径可能经过根节点，也可能不经过根节点。

// （N 叉树的输入序列以层序遍历的形式给出，每组子节点用 null 分隔）

class Solution {
public:
    // 找出到该结点最长路径
    int longestPath(Node* node){
        if(!node) return 0;
        int len = 0;
        for(auto& child : node->children){
            len = max(len,1+longestPath(child));
        }
        return len;
    }
    // 返回该节点最长的两条路径和
    int diameterHelper(Node* node){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto& child : node->children){
            int len = longestPath(child)+1;
            if(pq.size()<2){
                pq.push(len);
            }else{
                if(len>pq.top()){
                    pq.pop();
                    pq.push(len);
                }
            }
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
    int diameter(Node* root) {
        if(!root) return 0;
        int sum = 0;
        for(auto& child : root->children){
            // 在每个孩子中找出最长直径
            sum = max(sum,diameter(child));
        }
        // 和自身的最长直径作对比
        sum = max(sum,diameterHelper(root));

        return sum;
    }
};