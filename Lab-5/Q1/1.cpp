#include<bits/stdc++.h>
using namespace std;

int DFS(vector<vector<int>>&v,vector<vector<int>>&visited,int i,int j){

    if(v[i][j]==0||visited[i][j]!=-1){return 0;}
    else{
        v[i][j]=0;
        int result=1;
        result+=DFS(v,visited,i+1,j)+DFS(v,visited,i+1,j+1)+DFS(v,visited,i-1,j)+DFS(v,visited,i+1,j-1)
               +DFS(v,visited,i,j+1)+DFS(v,visited,i,j-1)+DFS(v,visited,i-1,j+1)+DFS(v,visited,i-1,j-1);
        visited[i][j] = result;
        return result;
    }
}  

int MaxRegion(vector<vector<int>>&v,int m,int n){
    vector<vector<int>>visited(m,vector<int>(n,-1));
    int result=INT_MIN;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==1 && visited[i][j]==-1){
                result=max(result,DFS(v,visited,i,j));
            }
        }
    }
    return result;
}


int main(){ 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
   int result = MaxRegion(v,m,n);
   cout<<result<<endl;
   return 0;
}
