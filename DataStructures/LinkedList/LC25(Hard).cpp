#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 25. K 个一组翻转链表

// 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

class Solution {
public:
    void reverse(ListNode* before,ListNode* start,ListNode* end){
        ListNode* curr = start;
        ListNode* pre = end;
        ListNode* next;
        while(curr!=end){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        before->next = pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next) return head;
        ListNode DummyHead = ListNode();
        ListNode* before = &DummyHead;
        ListNode* start = head;
        ListNode* end;
        while(start){
            int count = 0;
            end = start;
            while(count<k&&end){
                end = end->next;
                ++count;
            }
            // 当count==k并且end！=NULL时
            if(count==k){
                reverse(before,start,end);
            }
            before = start;
            start = end;
        }
        return DummyHead.next;
    }
};