BFS

class Solution {
public:


    void bfs(int i,int j,int color,vector<vector<int>>&visited,vector<vector<int>>&image){
        int prevcolor=image[i][j];
        int n=image.size();
        int m=image[0].size();
        visited[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            image[row][col]=color;
            int dir[5]={-1,0,1,0,-1};
            for(int k=0;k<4;k++){
                int r=dir[k]+row;
                int c=dir[k+1]+col;
                if(r>=0&&r<n&&c>=0&&c<m&&image[r][c]==prevcolor&&!visited[r][c]){
                    q.push({r,c});
                    visited[r][c]=1;
                    image[r][c]=color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        bfs(sr,sc,color,visited,image);
        return image;
    }
};

DFS

class Solution {
public:

    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    void dfs(int i,int j,int color,vector<vector<int>>&image,vector<vector<int>>visited){
        int n=image.size();
        int m=image[0].size();
        int prevcolor=image[i][j];
        image[i][j]=color;
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int r=dr[k]+i;
            int c=dc[k]+j;
            if(r>=0&&r<n&&c>=0&&c<m&&image[r][c]==prevcolor&&!visited[r][c])
            dfs(r,c,color,image,visited);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        dfs(sr,sc,color,image,visited);
        return image;
    }
