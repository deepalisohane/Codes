BFS

class Solution {
public:

    void bfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&visisted){
        int n=grid.size();
        int m=grid[0].size();
        visisted[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int dir[5]={-1,0,1,0,-1};
            for(int k=0;k<4;k++){
                int r=dir[k]+row;
                int c=dir[k+1]+col;
                if(r>=0&&r<n&&c>=0&&c<m&&!visisted[r][c]&&grid[r][c]=='1'){
                    q.push({r,c});
                    visisted[r][c]=1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visisted(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visisted[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid,visisted);
                }
            }
        }
        return cnt;
    }
};


DFS

class Solution {
public:

    int dir[5]={-1,0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int r=dir[k]+i;
            int c=dir[k+1]+j;
            if(r>=0&&r<n&&c>=0&&c<m&&!vis[r][c]&&grid[i][j]=='1') dfs(r,c,vis,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1') {
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;

    }
}
