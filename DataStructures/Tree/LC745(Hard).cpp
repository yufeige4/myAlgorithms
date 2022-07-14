#include "Trie.h"


// 745. 前缀和后缀搜索
// 设计一个包含一些单词的特殊词典，并能够通过前缀和后缀来检索单词。

// 实现 WordFilter 类：
// WordFilter(string[] words) 使用词典中的单词 words 初始化对象。
// f(string pref, string suff) 返回词典中具有前缀?prefix?和后缀 suff?的单词的下标。如果存在不止一个满足要求的下标，返回其中 最大的下标 。如果不存在这样的单词，返回 -1 。

// -小技巧-
// 往Trie树中存单词，如abcd时，需要将以下的单词都存进去：
// #abcd
// d#abcd
// cd#abcd
// bcd#abcd
// abcd#abcd
// 查询的时候，查询后缀 + # + 前缀即可。

class WordFilter {
private:
    Trie* data;
public:
    WordFilter(vector<string>& words) {
        data = new Trie();
        int size = words.size();
        for(int i=0;i<size;++i){
            string word = '#'+words[i];
            data->insert(word,i);
            for(int j=words[i].size()-1;j>=0;--j){
                // 将原单词的第j个字符加在前面
                word = words[i][j] + word;
                data->insert(word,i);
            }
        }
    }
    
    int f(string pref, string suff) {
        return data->query(suff+'#'+pref);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */