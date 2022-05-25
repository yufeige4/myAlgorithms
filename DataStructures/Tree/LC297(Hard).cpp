#include <bits/stdc++.h>

using namespace std;

// 297. 二叉树的序列化与反序列化

// 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，
// 同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

// 请设计一个算法来实现二叉树的序列化与反序列化。
// 这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                TreeNode* temp = q.front();
                q.pop();
                if(temp==NULL){
                    result.push_back('#');
                }else{
                    result.append(to_string(temp->val));
                    q.push(temp->left);
                    q.push(temp->right);
                }
                result.push_back(',');
            }
            result.push_back('|');
        }
        return result;
    }
    //  [1,2,3,null,null,4,5]
    //  1,|2,3,|#,#,4,5,|#,#,#,#,|

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==3){
            return NULL;
        }
        vector<vector<TreeNode*>> nodes;
        int size = data.size();
        int start = 0;
        int end;
        while(start<size){
            int end = start;
            vector<TreeNode*> level;
            // for each level
            while(end<size&&data[end]!='|'){
                // for each node
                while(data[end]!=','){
                    ++end;
                }
                if(end-start==1&&data[start]=='#'){
                    // if node is null
                    level.push_back(NULL);
                }else{
                    // normal node
                    int val = stoi(data.substr(start, end - start));
                    TreeNode* node = new TreeNode(val);
                    level.push_back(node);
                }
                ++end;
                start = end;
            }
            nodes.push_back(level);
            ++end;
            start = end;
        }
        // 已成为vector形式
        int maxLevel = nodes.size();
        for(int i=0;i<maxLevel-1;++i){
            int maxNum = nodes[i].size();
            int count = 0;
            for(int j=0;j<maxNum;++j){
                if(nodes[i][j]){
                    nodes[i][j]->left = nodes[i+1][2*count];
                    nodes[i][j]->right = nodes[i+1][2*count+1];
                    ++count;
                }
            }
        }
        return nodes[0][0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));