#include "Trie.h"


// 745. ǰ׺�ͺ�׺����
// ���һ������һЩ���ʵ�����ʵ䣬���ܹ�ͨ��ǰ׺�ͺ�׺���������ʡ�

// ʵ�� WordFilter �ࣺ
// WordFilter(string[] words) ʹ�ôʵ��еĵ��� words ��ʼ������
// f(string pref, string suff) ���شʵ��о���ǰ׺?prefix?�ͺ�׺ suff?�ĵ��ʵ��±ꡣ������ڲ�ֹһ������Ҫ����±꣬�������� �����±� ����������������ĵ��ʣ����� -1 ��

// -С����-
// ��Trie���д浥�ʣ���abcdʱ����Ҫ�����µĵ��ʶ����ȥ��
// #abcd
// d#abcd
// cd#abcd
// bcd#abcd
// abcd#abcd
// ��ѯ��ʱ�򣬲�ѯ��׺ + # + ǰ׺���ɡ�

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
                // ��ԭ���ʵĵ�j���ַ�����ǰ��
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