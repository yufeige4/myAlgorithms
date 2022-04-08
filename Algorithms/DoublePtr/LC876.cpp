#include <bits/stdc++.h>

using namespace std;

// 876. 链表的中间结点

// 给定一个头结点为 head 的非空单链表，返回链表的中间结点。

// 如果有两个中间结点，则返回第二个中间结点。

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    // 快慢指针
    ListNode* middleNode(ListNode* head) {
        if(!head){
            return NULL;
        }
        // slow ptr p, fast ptr q
        ListNode* p = head;
        ListNode* q = head;
        while(q->next&&q->next->next){
            p = p->next;
            q = q->next->next;
        }
        return !q->next? p : p->next;
    }
};