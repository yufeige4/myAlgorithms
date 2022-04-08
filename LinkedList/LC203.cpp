#include <bits/stdc++.h>

using namespace std;

// 203. 移除链表元素

// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummyHead = ListNode();
        dummyHead.next = head;
        ListNode* pre = &dummyHead;
        while(pre->next){
            if(pre->next->val==val){
                pre->next = pre->next->next;
            }else{
                pre = pre->next;
            }
        }
        return dummyHead.next;
    }
};