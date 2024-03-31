#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll n;cin>>n;
    priority_queue<pair<ll,pair<ll,ll>>>pq;
    ll max_deadline=-1;
    for(ll i=0;i<n;i++){
        ll id,dead,profit;
        cin>>id>>dead>>profit;
        max_deadline=max(max_deadline,dead);
        pq.push({profit,{dead,id}});
    }
    vector<bool>slot(max_deadline,0);
    ll ans=0;
    vector<ll>sequence;
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        ll id=t.second.second,dead=t.second.first,profit=t.first;
        while(dead-1>=0&&slot[dead-1]!=0){
            dead--;
        }
        if(dead-1>=0){
            ans+=profit;
            slot[dead-1]=1;
            sequence.push_back(id);
        }
    }
    cout<<"profit "<<ans<<endl;
    cout<<"sequence ";
    for(auto x:sequence)cout<<x<<" ";
    cout<<endl;
    return 0;
    //non-optimal greedy solution
}