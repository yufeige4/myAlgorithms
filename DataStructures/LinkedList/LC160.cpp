#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 160. 相交链表

// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

class Solution {
public:
    // HashSet 空间复杂度O(m)
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> mySet;
        while(headA){
            mySet.insert(headA);
            headA = headA->next;
        }
        while(headB){
            if(mySet.find(headB)!=mySet.end()){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }

};