#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(unordered_map<ll, vector<pair<ll,ll>>> &adj, ll s, ll e, vector<ll> &ans, bool &found){
    if(s==e){
        found=true;
        ans.push_back(s);
        return;
    }

    for(auto it: adj[s]){
        solve(adj, it.first, e, found);
        if(found){
            ans.push_back(s);
            return;
        }
    }
}
int main(){
    ll n,m; cin>>n>>m;

    vector<vector<ll>> edges(m, vector<ll>(3));
    unordered_map<ll, vector<pair<ll,ll>>> adj;

    for(ll i=0;i<m; i++){
        ll a,b,c; cin>>a>>b>>c;
        edges[i]={a,b,c};
        adj[a].push_back({b,c});
    }
    vector<ll> dist(n+1,1e9);

    for(ll i=0; i<n-1; i++){
        for(ll i=0; i<m; i++){
            if(dist[edges[i][1]]>dist[edges[i][0]]+edges[i][2]){
                dist[edges[i][1]]=dist[edges[i][0]]+edges[i][2];
            }
        }

    }
    ll neg=-1;
    for(ll i=0; i<m; i++){
        if(dist[edges[i][1]]!=dist[edges[i][0]]+edges[i][2]) {neg=i; break;}
    }

    if(neg==-1) {cout<<"NO"<<endl;
    return 0;}

    ll a=edges[neg][0], b=edges[neg][1];
    vector<ll> ans;
    bool found=false;
    solve(adj, b, a, ans, found);
    


}
