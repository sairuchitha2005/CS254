#include<bits/stdc++.h>
using namespace std;

int DFS(vector<vector<int>>&v,int i,int j){

    if(v[i][j]==0){return 0;}
    else{
        v[i][j]=0;
        int ans=1;
        ans+=DFS(v,i+1,j)+DFS(v,i+1,j+1)+DFS(v,i-1,j)+DFS(v,i+1,j-1)+DFS(v,i,j+1)+DFS(v,i,j-1)+DFS(v,i-1,j+1)+DFS(v,i-1,j-1);
        return ans;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<vector<int>> v(n+2,vector<int>(n+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>v[i][j];
        }
    }
    int mn=INT32_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mn=max(DFS(v,i,j),mn);
        }
    }
   cout<<mn<<endl;
    return 0;
}
