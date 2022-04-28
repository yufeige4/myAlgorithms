#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 82. 删除排序链表中的重复元素 II

// 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

// [1,2,3,3,4,4,5] -> [1,2,5]

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode DummyHead = ListNode();
        ListNode* pre = &DummyHead;
        ListNode* curr = head;
        ListNode* next;
        while(curr){
            int val = curr->val;
            next = curr->next;
            if(!next||val!=next->val){
                pre->next = curr;
                pre = curr;
            }
            while(next&&next->val==val){
                next = next->next;
            }
            curr = next;
        }
        pre->next = NULL;
        return DummyHead.next;
    }
};