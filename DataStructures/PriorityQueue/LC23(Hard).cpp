#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 23. 合并K个升序链表

// 给你一个链表数组，每个链表都已经按升序排列。

// 请你将所有链表合并到一个升序链表中，返回合并后的链表。

class cmp{
public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(ListNode*& node : lists){
            if(node){
                pq.push(node);
            }
        }
        ListNode dummyHead = ListNode();
        ListNode* pre = &dummyHead;

        while(!pq.empty()){
            pre->next = pq.top();
            pre = pre->next;
            ListNode* next = pq.top()->next;
            pq.pop();
            if(next){
                pq.push(next);
            }
        }
        return dummyHead.next;
    }
};