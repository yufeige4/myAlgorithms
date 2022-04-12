#include <bits/stdc++.h>

using namespace std;

// 206. 反转链表

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 非递归
    ListNode* reverseList1(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode* curr = head;
        ListNode* pre = NULL;
        ListNode* next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
    // 递归
    ListNode* reverseList2(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* newHead = reverseList2(head->next);
        // smart power
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};