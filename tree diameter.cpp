#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,ll> bfs(ll node, unordered_map<ll, vector<ll>> &adj, ll n){
    vector<ll> visited(n+1,0);

    queue<pair<ll,ll>> q;
    q.push({node,0});
    
    pair<ll,ll> u;
    while(!q.empty()){
        u=q.front();
        visited[u.first]=1;
        q.pop();

        for(auto it: adj[u.first]){
            if(!visited[it]){
            q.push({it,u.second+1});
            visited[it]=1;
            }
        }
    }
    return u;
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
    
    pair<ll,ll> start=bfs(1, adj,n);
    pair<ll,ll> end=bfs(start.first,adj, n);
    cout<<end.second<<endl;
}
