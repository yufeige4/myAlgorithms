#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 148. 排序链表
// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

class Solution {
public:
    // 升序合并两个链表
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode dummyHead = ListNode();
        ListNode* pre = &dummyHead;
        while(head1&&head2){
            if(head1->val<=head2->val){
                pre->next = head1;
                head1 = head1->next;
            }else{
                pre->next = head2;
                head2 = head2->next;
            }
            pre = pre->next;
        }
        pre->next = head1 ? head1 : head2;
        return dummyHead.next;
    }

    // 对于链表的归并排序O(nlogn) + 常数空间复杂度 
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        // 得到总长
        int maxLen = 0;
        ListNode* temp = head;
        while(temp){
            ++maxLen;
            temp = temp->next;
        }
        // 从长度1开始 长度每次乘2 自下而上归并
        ListNode dummyHead = ListNode(0,head);
        for(int len=1;len<maxLen;len*=2){
            ListNode* pre = &dummyHead;
            ListNode* curr = dummyHead.next;
            while(curr){
                ListNode* head1 = curr;
                // 往后位移len-1个结点
                for(int i=1;i<len&&curr->next!=NULL;++i){
                    curr = curr->next;
                }
                // 下一个结点为head2
                ListNode* head2 = curr->next;
                // 将list1和list2分离 防止bug
                curr->next = NULL;
                // 找到list2的尾部
                curr = head2;
                for(int i=1;i<len&&curr!=NULL&&curr->next!=NULL;++i){
                    curr = curr->next;
                }
                // 记下list2尾部的下一个结点
                ListNode* next = NULL;
                if(curr){
                    next = curr->next;
                    // 将list2和下一个链表分离
                    curr->next = NULL;
                }
                ListNode* mergedHead = merge(head1,head2);
                pre->next = mergedHead;
                // 已经合并的部分的尾部在下一个将要合并的部分的前面
                while(pre->next){
                    pre = pre->next;
                }
                curr = next;
            }
        }
        return dummyHead.next;
    }
};