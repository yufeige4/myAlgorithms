#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 369. 给单链表加一

// 给定一个用链表表示的非负整数， 然后将这个整数 再加上 1 。

// 这些数字的存储是这样的：最高位有效的数字位于链表的首位 head 。

class Solution {
public:
    // 哨兵头结点+找出最右非9结点
    ListNode* plusOne(ListNode* head) {
        // 设置哨兵结点
        ListNode* canary = new ListNode(0,head);
        head = canary;
        // 找到最右非9结点
        ListNode* last = canary;
        while(head!=nullptr){
            if(head->val!=9){
                last = head;
            }
            head = head->next;
        }
        // 将其加一并将右边所有结点归0
        last->val = last->val+1;
        while(last->next!=nullptr){
            last = last->next;
            last->val = 0;
        }
        // 删除多余结点防止memory leak
        if(canary->val==0){
            head = canary->next;
            delete canary;
        }else{
            head = canary;
        }
        return head;
    }
};