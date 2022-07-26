#include <bits/stdc++.h>

using namespace std;

// 1206. 设计跳表

// 不使用任何库函数，设计一个 跳表 。
// skip list
// 从高层往低层找 该层找不到则去下一层
// level 2: 1        ->         5 -> null
// level 1: 1    ->   3   ->    5 -> null
// level 0: 1 -> 2 -> 3 -> 4 -> 5 -> null
class Skiplist {
private:
    const static int MAXLEVEL = 16;
    struct SkiplistNode{
        int val;
        // 保存每一层的next所指向的指针
        // 即使该结点在某层为空也为其保存next
        vector<SkiplistNode*> nexts;
        SkiplistNode(int _i,int _level=MAXLEVEL):val(_i),nexts(_level,NULL){}
    };
    SkiplistNode* head;
    int level;

    int getRandLevel(){
        int level = 1;
        while(rand()%2>0){
            ++level;
        }
        return level;
    }
public:
    Skiplist() {
        head = new SkiplistNode(-1);
        level = 0;
    }
    
    bool search(int target) {
        SkiplistNode* curr = this->head;
        for(int i=level-1;i>=0;--i){
            while(curr->nexts[i]&&curr->nexts[i]->val<target){
                curr = curr->nexts[i];
            }
        }
        curr = curr->nexts[0];
        return (curr&&curr->val==target);
    }
    
    void add(int num) {
        vector<SkiplistNode*> update(MAXLEVEL,head);
        SkiplistNode* curr = this->head;
        for(int i=level-1;i>=0;--i){
            while(curr->nexts[i]&&curr->nexts[i]->val<num){
                curr = curr->nexts[i];
            }
            // 记录每一层停下的位置
            update[i] = curr;
        }
        int newLevel = getRandLevel();
        // 如果需要,更新层数
        this->level = max(level,newLevel);
        SkiplistNode* newNode = new SkiplistNode(num,newLevel);
        for(int i=0;i<newLevel;++i){
            // 根据新节点层数更新相应层的链表
            newNode->nexts[i] = update[i]->nexts[i];
            update[i]->nexts[i] = newNode;
        }

    }
    
    bool erase(int num) {
        vector<SkiplistNode*> update(MAXLEVEL,head);
        SkiplistNode* curr = this->head;
        for(int i=level-1;i>=0;--i){
            while(curr->nexts[i]&&curr->nexts[i]->val<num){
                curr = curr->nexts[i];
            }
            // 记录每一层停下的位置
            update[i] = curr;
        }
        // 判断是否存在该值
        curr = curr->nexts[0];
        if(!curr || curr->val!=num){
            return false;
        }
        for(int i=0;i<level;++i){
            if(update[i]->nexts[i]!=curr){
                // 该层不存在需要删除的结点 则下一层也必不需要删除
                break;
            }
            // 根据记录的位置删除更新每层的链表
            update[i]->nexts[i] = curr->nexts[i];
        }
        delete curr;
        // 若删除的结点为该层唯一结点
        while(this->level>1 && head->nexts[level-1]==NULL){
            --this->level;
        }
        return true;
    }
};

