#include <bits/stdc++.h>

using namespace std;

// 707. 设计链表

// 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。
// val 是当前节点的值，next 是指向下一个节点的指针/引用。
// 如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

// 在链表类中实现这些功能：

// get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
// addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
// addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
// addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
// deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

class MyLinkedList {
private:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* head;
    ListNode* tail; 
public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) {
        int count = 0;
        ListNode* curr = head;
        while(count<index&&curr){
            curr = curr->next;
            ++count;
        }
        if(index<0||!curr){
            return -1;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val,head);
        head = newNode;
        if(tail==NULL) tail=head;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(!head) head = newNode;
        if(tail) tail->next = newNode;
        tail = newNode;
    }
    
    void addAtIndex(int index, int val) {
        if(index<=0){
            addAtHead(val);
            return;
        }
        int count = 0;
        ListNode* curr = head;
        while(count+1<index&&curr){
            curr = curr->next;
            ++count;
        }
        // 找到需要插入位置
        if(curr&&curr->next){
            ListNode* newNode = new ListNode(val,curr->next);
            curr->next = newNode;
        }else if(curr&&!curr->next){
            // curr->next不存在
            addAtTail(val);
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<0){
            return;
        }else if(index==0){
            // 若结点唯一
            if(head==tail) tail = NULL;
            head = head->next;
            return;
        }
        // index>0
        int count = 0;
        ListNode* curr = head;
        while(count+1<index&&curr){
            curr = curr->next;
            ++count;
        }
        // curr为应删除结点的前一个结点
        if(curr&&curr->next){
            if(curr->next==tail) tail = curr;
            curr->next = curr->next->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */