#include <bits/stdc++.h>

using namespace std;

struct PolyNode {
    int coefficient, power;
    PolyNode *next;
    PolyNode(): coefficient(0), power(0), next(nullptr) {};
    PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
    PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
};

// 1634. 求两个多项式链表的和

// 多项式链表是一种特殊形式的链表，每个节点表示多项式的一项。

// 每个节点有三个属性：
// coefficient：该项的系数。项 9x4 的系数是 9 。
// power：该项的指数。项 9x4 的指数是 4 。
// next：指向下一个节点的指针（引用），如果当前节点为链表的最后一个节点则为 null 。
// 例如，多项式 5x3 + 4x - 7 可以表示成如下图所示的多项式链表：

// 多项式链表必须是标准形式的，即多项式必须 严格 按指数 power 的递减顺序排列（即降幂排列）。另外，系数 coefficient 为 0 的项需要省略。

// 给定两个多项式链表的头节点 poly1 和 poly2，返回它们的和的头节点。

// PolyNode 格式：
// 输入/输出格式表示为 n 个节点的列表，其中每个节点表示为 [coefficient, power] 。
// 例如，多项式 5x^3 + 4x - 7 表示为： [[5,3],[4,1],[-7,0]] 。

class Solution {
public:
    // 新建结点
    PolyNode* addPoly1(PolyNode* poly1, PolyNode* poly2) {
        PolyNode dummyHead = PolyNode();
        PolyNode* pre = &dummyHead;

        while(poly1&&poly2){
            PolyNode* node = new PolyNode();
            if(poly1->power>poly2->power){
                node->power = poly1->power;
                node->coefficient = poly1->coefficient;
                poly1 = poly1->next;
            }else if(poly1->power<poly2->power){
                node->power = poly2->power;
                node->coefficient = poly2->coefficient;
                poly2 = poly2->next;
            }else{
                node->power = poly1->power;
                node->coefficient = poly1->coefficient+poly2->coefficient;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
            if(node->coefficient!=0){
                pre->next = node;
                pre = node;
            }
        }
        poly1 = poly1 ? poly1 : poly2;
        while(poly1){
            PolyNode* node = new PolyNode(poly1->coefficient,poly1->power);
            poly1 = poly1->next;
            pre->next = node;
            pre = node;
        }
        return dummyHead.next;
    }
    // 尽可能原地
    PolyNode* addPoly2(PolyNode* poly1, PolyNode* poly2) {
        PolyNode dummyHead = PolyNode();
        PolyNode* pre = &dummyHead;

        while(poly1&&poly2){
            if(poly1->power>poly2->power){
                pre->next = poly1;
                poly1 = poly1->next;
            }else if(poly1->power<poly2->power){
                pre->next = poly2;
                poly2 = poly2->next;
            }else{
                PolyNode* node = new PolyNode();
                node->power = poly1->power;
                node->coefficient = poly1->coefficient+poly2->coefficient;
                poly1 = poly1->next;
                poly2 = poly2->next;
                if(node->coefficient==0){
                    continue;
                }
                pre->next = node;
            }
            pre = pre->next;
        }
        pre->next = poly1 ? poly1 : poly2;

        return dummyHead.next;
    }
};