#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
      int result=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i<j && a[i]>a[j]){result++;}
        }
    }
    cout<<result;
    return 0;
}



