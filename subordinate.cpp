#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(unordered_map<ll,set<ll>> &adj, ll node, vector<ll> &sub, ll prev){

    for(auto it: adj[node]){
        dfs(adj, it, sub, node);
    }
    sub[prev]+=sub[node];

}
int main(){
    ll n; cin>>n;
    vector<ll> sub(n+1);
    unordered_map<ll,set<ll>> adj;
    
    for(int i=0; i<n-1; i++){
        ll a; cin>>a;
        sub[a]++;
        adj[a].insert(i+2);
    }

    // queue<<ll>> q;
    // q.push(1);
    // vector<ll> order;
    // order.push_back(1);
    // while(!q.empty()){
    //     ll top=q.front();
    //     q.pop();
    //     for(auto it: adj[top]){
    //         q.push(it);
    //         order.push_back(it);
    //     }
    // }
    ll prev=0;
    dfs(adj, 1, sub, prev);
    for(int i=1; i<=n; i++){
        cout<< sub[i]<<" ";
    }
    return 0;


}
