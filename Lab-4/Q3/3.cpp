//Time Complexity:O(n*logn)
//Space Complexity:O(n)
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
    if(k>0 && k<n){
    cout<<nums[n-k];
    }
    else{cout<<"Error: k is out of bounds";}
    return 0;
}