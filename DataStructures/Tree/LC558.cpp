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

// �����ƾ����е�����Ԫ�ز��� 0 ���� 1 ��

// ���������Ĳ�����quadTree1 �� quadTree2������ quadTree1 ��ʾһ�� n * n �����ƾ��󣬶� quadTree2 ��ʾ��һ�� n * n �����ƾ���

// ���㷵��һ����ʾ n * n �����ƾ�����Ĳ��������� quadTree1 �� quadTree2 ����ʾ�����������ƾ������ ��λ�߼������� �Ľ����

// ע�⣬�� isLeaf Ϊ False ʱ������԰� True ���� False ��ֵ���ڵ㣬����ֵ���ᱻ������� ���� ��

// �Ĳ������ݽṹ�У�ÿ���ڲ��ڵ�ֻ���ĸ��ӽڵ㡣���⣬ÿ���ڵ㶼���������ԣ�
// val������Ҷ�ӽ��������������ֵ��1 ��Ӧ True��0 ��Ӧ False��
// isLeaf: ������ڵ���һ��Ҷ�ӽ��ʱΪ True��������� 4 ���ӽڵ���Ϊ False ��


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
        // ���߶���Ҷ�ӽڵ�
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