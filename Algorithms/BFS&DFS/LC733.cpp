#include <bits/stdc++.h>

using namespace std;

// 733. 图像渲染

// 有一幅以 m x n 的二维整数数组表示的图画 image ，其中 image[i][j] 表示该图画的像素值大小。

// 你也被给予三个整数 sr ,  sc 和 newColor 。你应该从像素 image[sr][sc] 开始对图像进行 上色填充 。

// 为了完成 上色工作 ，从初始像素开始，记录初始坐标的 上下左右四个方向上 像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应 四个方向上 像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为 newColor 。

// 最后返回 经过上色渲染后的图像 。

class Solution {
public:


    int directX[4] = {-1,1,0,0};
    int directY[4] = {0,0,-1,1};

    // DFS + 无visited

    void dfs(vector<vector<int>>& image,int m,int n,int x, int y,int color,int newColor){
        image[x][y] = newColor;
        int newX,newY;
        for(int i=0;i<4;++i){
            newX = x + directX[i];
            newY = y + directY[i];
            if(newX>=0&&newX<m&&newY>=0&&newY<n){
                if(image[newX][newY]==color){
                    dfs(image,m,n,newX,newY,color,newColor);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int color = image[sr][sc];
        if(color!=newColor){
            dfs(image,m,n,sr,sc,image[sr][sc],newColor);
        }
        return image;
    }
};