#include "UnionFind.h"

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // 26个小写字母
        // graph[i]里是所有和i相等的字母
        vector<pair<int,int>> notEqual;

        UnionFind myUF(26);
        for(auto& e : equations){
            int u = e[0]-'a';
            int v = e[3]-'a';
            if(e[1]=='!'){
                notEqual.push_back(make_pair(u,v));
            }else{
                myUF.unite(u,v);
            }
            
        }
        for(auto& [u,v] : notEqual){
            if(myUF.find(u)==myUF.find(v)){
                return false;
            }
        }
        return true;
    }
};