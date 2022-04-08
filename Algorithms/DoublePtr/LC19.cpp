#include <bits/stdc++.h>

using namespace std;

// 19. 删除链表的倒数第 N 个结点

// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyHead;
        dummyHead.next = head;
        // p为慢指针 q为快指针
        ListNode *p,*q;
        p = head;
        q = head;
        while(n>0){
            q = q->next;
            --n;
        }
        // 正好只有n个结点
        if(!q){
            dummyHead.next = p->next;
            delete p;
            return dummyHead.next;
        }

        while(q->next){
            p = p->next;
            q = q->next;
        }
        // p为应删除结点的前一个结点
        q = p->next;
        p->next = q->next;
        delete q;
        return dummyHead.next;
    }
};