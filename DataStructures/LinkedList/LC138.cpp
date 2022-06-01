#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 138. 复制带随机指针的链表

// 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

// 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
// 新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
// 复制链表中的指针都不应指向原链表中的节点 。

// 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。

// 返回复制链表的头节点。

// 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

// val：一个表示 Node.val 的整数。
// random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
// 你的代码 只 接受原链表的头节点 head 作为传入参数。

class Solution {
public:
    // 利用HashMap将原结点和新结点作映射
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node dummyHead = Node(0);
        Node* pre = &dummyHead;
        unordered_map<Node*,Node*> hash;
        hash[NULL] = NULL;
        while(head){
            Node* temp = new Node(head->val);
            temp->random = head->random;
            pre->next = temp;
            pre = temp;
            hash[head] = temp;
            head = head->next;
        }

        Node* curr = dummyHead.next;
        while(curr){
            curr->random = hash[curr->random];
            curr = curr->next;
        }
        return dummyHead.next;
    }
};