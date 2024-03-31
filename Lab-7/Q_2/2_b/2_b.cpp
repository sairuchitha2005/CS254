#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

struct Compare {
    bool operator()(const pair<ll, pair<ll, ll>>& a, const pair<ll, pair<ll, ll>>& b) {
        return a.second.first < b.second.first;
    }
};

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll n;cin>>n;
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,Compare>pq;

    ll max_deadline=-1;
    vector<pair<ll,pair<ll,ll>>>v;//vector of {dead_line,{profit,id}}
    for(ll i=0;i<n;i++){
        ll id,dead,profit;
        cin>>id>>dead>>profit;
        v.pb({dead,{profit,id}});
        max_deadline=max(max_deadline,dead);
    }
        //pq.push({profit,{dead,id}});
    sort(v.begin(),v.end());
    //vector<bool>slot(max_deadline,0);
    ll ans=0;
    vector<ll>sequence;

    for(ll i=n-1;i>=0;i--){
        int slots_available = v[i].first;
        if(i>0) slots_available -= v[i-1].first;
        pq.push(v[i]);
        while(!pq.empty()&&slots_available>0){
            slots_available--;
            auto y=pq.top();
            pq.pop();
            sequence.pb(y.second.second);
            ans+=y.second.first;
        }
    }

    cout<<"profit "<<ans<<endl;
    reverse(sequence.begin(),sequence.end());
    cout<<"sequence ";
    for(auto x:sequence)cout<<x<<" ";
    cout<<endl;
    return 0;
    //optimal greedy solution
    //Time Complexity=O(NlogN)
}