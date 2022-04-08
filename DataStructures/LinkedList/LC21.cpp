#include <bits/stdc++.h>

using namespace std;

// 21. 合并两个有序链表

// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode DummyHead = ListNode();
        ListNode* temp = &DummyHead;
        while(list1&&list2){
            if(list1->val<list2->val){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }else{
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        temp->next = list1? list1 : list2;
        return DummyHead.next;
    }
};