#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++) cin>>nums[i];
    int k;
    cin>>k;
    sort(nums,nums+n);
    cout<<nums[n-k];
    return 0;
}