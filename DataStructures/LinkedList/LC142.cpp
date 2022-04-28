#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 设链表中环外部分的长度为 a。
// slow 指针进入环后，又走了 b 的距离与 fast 相遇。
// 此时，fast 指针已经走完了环的 n 圈，因此它走过的总距离为 a+n(b+c)+b
// 由快慢指针性质知，a+n(b+c)+b = 2(a+b)
// a = (n-1)b+nc = c + (n-1)(b+c)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next&&fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                break;
            }
        }
        if(!fast->next||!fast->next->next){
            return NULL;
        }
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};