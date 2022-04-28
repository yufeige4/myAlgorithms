#include <bits/stdc++.h>

using namespace std;

// 2. 两数相加

// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

// 请你将两个数相加，并以相同形式返回一个表示和的链表。

// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    // 用l1中原结点节省空间
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode dummyHead = ListNode();
        dummyHead.next = l1;
        int temp = 0;
        ListNode* pre;
        while(l1&&l2){
            temp = l1->val + l2->val + temp/10;
            l1->val = temp%10;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(!l1){
            pre->next = l2;
            l1 = l2;
        }
        while(l1){
            temp = l1->val + temp/10;
            l1->val = temp%10;
            pre = l1;
            l1 = l1->next;
        }
        if(temp/10>0){
            ListNode* newNode = new ListNode(1);
            pre->next = newNode;
        }
        return dummyHead.next;
    }

    // 新建结点
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode dummyHead = ListNode();
        int temp = 0;
        ListNode* pre = &dummyHead;
        while(l1&&l2){
            temp = l1->val + l2->val + temp/10;
            ListNode* newNode = new ListNode(temp%10);
            pre->next = newNode;
            pre = pre->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(!l1){
            l1 = l2;
        }
        while(l1){
            temp = l1->val + temp/10;
            ListNode* newNode = new ListNode(temp%10);
            pre->next = newNode;
            pre = pre->next;
            l1 = l1->next;
        }
        if(temp/10>0){
            ListNode* newNode = new ListNode(1);
            pre->next = newNode;
        }
        return dummyHead.next;
    }
};