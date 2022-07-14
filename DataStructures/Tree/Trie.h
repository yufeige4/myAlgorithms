#include <bits/stdc++.h>

using namespace std;

class TrieNode{
public:
    // 26字母和#字母
    // #字符为26
    // unordered_map<char, TrieNode*> children;
    TrieNode* children[27];
    int index;
    TrieNode(){
        for(int i=0;i<=26;++i){
            children[i] = NULL;
        }
        index = -1;
    }
};

class Trie{
private:
    TrieNode* node;
public:
    Trie(){
        node = new TrieNode();
    }

    void insert(string str,int id){
        auto curr = node;
        for(auto& ch : str){
            int hash = (ch=='#' ? 26 : (ch-'a'));
            // 若无当前序列中的字符时
            if(curr->children[hash]==NULL){
                curr->children[hash] = new TrieNode;
                curr->children[hash]->index = id;
            }
            // 去TrieNode的下面一层
            curr = curr->children[hash];
            // 覆盖id
            curr->index = id;
        }
    }

    int query(string str){
        auto curr = node;
        for(auto& ch : str){
            int hash = (ch=='#' ? 26 : (ch-'a'));
            if(curr->children[hash]==NULL){
                return -1;
            }
            curr = curr->children[hash];
        }
        return curr->index;
    }
};