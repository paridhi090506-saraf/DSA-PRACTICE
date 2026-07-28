#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int orangesRotting(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    //{{r,c},t}
    queue<pair<pair<int,int>,int>> q;
    int vis[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
            vis[i][j]=2;
            q.push({{i,j},0});
            }
            else
            vis[i][j]=0;
        }
    }
    int tm=0;
    while(!q.empty()){
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        tm=max(tm,t);
        q.pop();
        for(int i=0;i<4;i++){
            int nr=r+delRow[i];
            int nc=c+delCol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=2 && grid[nr][nc]==1){
                q.push({{nr,nc},t+1});
                vis[nr][nc]=2;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]!=2 && grid[i][j]==1)
            return -1;
        }
    }
    return tm;
}
int main(){
    vector<vector<int>> grid={{2,1,1},{1,1,0},{0,1,1}};
    int time=orangesRotting(grid);
    cout<<time;
}