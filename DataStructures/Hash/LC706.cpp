#include <bits/stdc++.h>

using namespace std;

// 706. 设计哈希映射

// 实现 MyHashMap 类：

// MyHashMap() 用空映射初始化对象
// void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
// int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
// void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。


// using sparate chaining to implement
class MyHashMap {

private:
    vector<list<pair<int,int>>> table;
    static const int base = 769;
    static int hash(int input){
        return input % base;
    };
public:
    MyHashMap(): table(base){
    }
    
    void put(int key, int value) {
        int index = hash(key);
        list<pair<int,int>>* myList = &table[index];
        for(auto it=myList->begin();it!=myList->end();++it){
            if(it->first==key){
                it->second = value;
                return;
            }
        }
        myList->push_back({key,value});

    }
    
    int get(int key) {
        int index = hash(key);
        list<pair<int,int>>* myList = &table[index];
        for(auto it=myList->begin();it!=myList->end();++it){
            if(it->first==key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        list<pair<int,int>>* myList = &table[index];
        for(auto it=myList->begin();it!=myList->end();++it){
            if(it->first==key){
                myList->erase(it);
                return;
            }
        }
    }
};