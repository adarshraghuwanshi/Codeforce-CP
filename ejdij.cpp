#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs(unordered_map<ll, vector<ll>> &adj, ll node, ll &dia, ll pre){
    ll first_max = 0;
    ll second_max = 0;

    for(auto it: adj[node]){
        if(it==pre) continue;
        ll child_length = dfs(adj, it, dia, node);
        dia = max(dia, first_max + second_max);
        if (child_length > first_max) {
            second_max = first_max;
            first_max = child_length;
        } else if (child_length > second_max) {
            second_max = child_length;
        }
    }
    
    return first_max + 1;
}


int main(){
    ll n; cin>>n;
    unordered_map<ll, vector<ll>> adj;
    for(int i=0; i<n-1; i++){
        ll a,b;
        cin>>a>>b;
         adj[a].push_back(b);
         adj[b].push_back(a);
        
    }
    ll dia=0;
    ll ans=dfs(adj,1,dia,-1);
    dia=max(dia,ans-1);
    cout<<dia;
    return 0;
}
