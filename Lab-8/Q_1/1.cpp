# include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>

//initialize vectors
vi parent;
vi set_size;
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

    //creating a vector to store the edges and weights in the form 
    //weight,{node1,node2}
    ll n;cin>>n;
    ll e;cin>>e;

    vector<pair<pair<ll,ll>,ll>>edges;
    parent.assign(n,-1);
    set_size.assign(n,0);

    for(ll i=0;i<e;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.push_back({{u-1,v-1},w});
    }
    sort(edges.begin(),edges.end(),[](auto left, auto right){
        return left.second>right.second;
    });
    
    //assigning a parent element to each set
    for(ll i=0;i<n;i++){
        //setting the parent to  itself initially
        make(i);
    }

    //storing the final set of edges and their weights in the vector
    vector<pair<pair<ll,ll>,ll>>edges_final;
    for(auto x:edges){
        ll weight=x.second;
        ll a=(x.first).first;
        ll b=(x.first).second;
        // if a cycle gets created while adding the current edge then parent[a]=parent[b]
        //if a and b have different parents, then the corresponding edge will be considered
        if(find_par(a)!=find_par(b)){
            union_set(a,b);
            edges_final.push_back(x);
        }     
    }

    ll cost=0;

    //printing the edges along with their weights in th MST
    cout<<"Maximum Spanning Tree after applying Kruskal's algorithm: "<<endl;
    for(auto x: edges_final){
        //printing order:- node1 , node2 , weight
        cout<<(x.first).first<<" "<<(x.first).second<<" "<<(x.second)<<endl;
        cost+=(x.second);
    }
    cout<<"The cost of MST: "<<cost<<endl;
}