#include <bits/stdc++.h>

using namespace std;

// 141. 环形链表
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

// 如果链表中存在环 ，则返回 true 。 否则，返回 false 。



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }
        // 快慢指针
        ListNode *pSlow, *pFast;
        pSlow = head;
        pFast = head;
        while(pFast->next&&pFast->next->next){
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if(pSlow==pFast){
                return true;
            }
        }
        return false;
    }
};