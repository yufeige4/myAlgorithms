#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 24. 两两交换链表中的节点

// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode DummyHead = ListNode();
        ListNode* pre = &DummyHead;
        ListNode* curr = head;
        ListNode* next;
        while(curr){
            next = curr->next;
            if(next){
                curr->next = next->next;
                next->next = curr;
                pre->next = next;
            }
            pre = curr;
            curr = curr->next;
        }
        return DummyHead.next;
    }
};