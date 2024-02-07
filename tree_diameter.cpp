#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs(unordered_map<ll, vector<ll>> &adj, ll node, ll &dia, ll pre){

    ll prev=0;
    ll curr=0;

    for(auto it: adj[node]){
        if(it==pre) continue;
        curr= dfs(adj,it,dia, node);
        dia=max(dia, prev+curr);
        prev=max(prev,curr);
        
    }
    
    return prev+1;
}

int main(){
    ll n; cin>>n;
    unordered_map<ll, vector<ll>> adj;
    for(int i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
         adj[b].push_back(a);
         adj[a].push_back(b);
    }
    ll dia=0;
    ll ans=dfs(adj,1,dia,-1);
    dia=max(dia,ans-1);
    cout<<dia;
    return 0;
}
