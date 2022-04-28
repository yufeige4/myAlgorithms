#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 143. 重排链表

// 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
// L0 → L1 → … → Ln - 1 → Ln

// 请将其重新排列后变为：
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

class Solution {
public:
    // O(n) 空间复杂度
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        ListNode* curr = head;
        while(curr){
            arr.push_back(curr);
            curr = curr->next;
        }
        int i = 0;
        int j = arr.size()-1;
        while(i<j){
            arr[i]->next = arr[j];
            ++i;
            if(i==j){
                break;
            }
            arr[j]->next = arr[i];
            --j;
        }
        arr[i]->next = NULL;
    }
    // 还可以使用 找中间结点 + 反转右半部分 + 交叉合并 实现O(1)空间复杂度
};