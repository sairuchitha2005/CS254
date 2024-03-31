#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair


//initialize vectors
vector<ll> parent;
vector<ll> set_size;
void make(ll v)
{
    parent[v] = v;
    set_size[v] = 1;
}

ll find_par(ll v)
{
    if(parent[v] == v) return v;
    else return parent[v] = find_par(parent[v]);
}

void union_set(ll a, ll b)
{
    a = find_par(a);
    b = find_par(b);
    if(a!=b)
    {
        if(set_size[a] < set_size[b]) swap(a,b);
        parent[b] = a;
        set_size[a] += set_size[b];
    }
}


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
    parent.assign(max_deadline+1,0);
    set_size.assign(max_deadline+1,0);
    for(int i=0;i<max_deadline+1;i++)parent[i]=i;
    ll ans=0;
    vector<ll>sequence;
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        ll id=t.second.second,dead=t.second.first,profit=t.first;

        ll par=find_par(dead);
        if(par!=0){
            union_set(dead-1,dead);
            ans+=profit;
            sequence.push_back(id);
        }
    }
    cout<<"profit "<<ans<<endl;
    cout<<"sequence ";
    for(auto x:sequence)cout<<x<<" ";
    cout<<endl;
    return 0;
    //optimised 2_a solution using DSU
    //Time Complexity : O(NlogN)
}