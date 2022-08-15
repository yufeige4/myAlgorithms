#include <bits/stdc++.h>

using namespace std;

// 641. 设计循环双端队列

// 设计实现双端队列。

// 用仅提供尾指针的双链表实现双端循环队列
class MyCircularDeque {
private:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int data,ListNode* nextNode = NULL,ListNode* prevNode = NULL){
            val = data;
            next = nextNode;
            prev = prevNode;
        }
    };
    int maxCapacity;
    int currNum;
    ListNode* tail;
public:
    MyCircularDeque(int k=0):maxCapacity(k),currNum(0),tail(NULL){
    }
    
    bool insertFront(int value) {
        if(currNum>=maxCapacity){
            return false;
        }
        ListNode* temp = new ListNode(value);
        if(currNum==0){
            temp->next = temp;
            temp->prev = temp;
            tail = temp;
        }else{
            ListNode* head = tail->next;
            head->prev = temp;
            temp->next = head;
            temp->prev = tail;
            tail->next = temp; 
        }
        ++currNum;
        return true;
    }
    
    bool insertLast(int value) {
        if(currNum>=maxCapacity){
            return false;
        }
        ListNode* temp = new ListNode(value);
        if(currNum==0){
            temp->next = temp;
            temp->prev = temp;
            tail = temp;
        }else{
            ListNode* head = tail->next;
            head->prev = temp;
            temp->next = head;
            temp->prev = tail;
            tail->next = temp; 
            tail = temp;
        }
        ++currNum;
        return true;
    }
    
    bool deleteFront() {
        if(currNum==0) return false;
        ListNode* head = tail->next;
        head->next->prev = tail;
        tail->next = head->next;
        delete head;
        --currNum;
        if(currNum==0) tail = NULL;
        return true;
    }
    
    bool deleteLast() {
        if(currNum==0) return false;
        ListNode* head = tail->next;
        tail->prev->next = head;
        head->prev = tail->prev;
        ListNode* temp = tail;
        tail = tail->prev;
        delete temp;
        --currNum;
        if(currNum==0) tail = NULL;
        return true;
    }
    
    int getFront() {
        if(!tail) return -1;
        return tail->next->val;
    }
    
    int getRear() {
        if(!tail) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return currNum==0;
    }
    
    bool isFull() {
        return currNum>=maxCapacity;
    }
};