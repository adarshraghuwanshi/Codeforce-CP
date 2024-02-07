#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> dfs(long long node, unordered_map<long long, vector<pair<long long,long long>>> &adj, vector<long long> &dfsVis, vector<pair<long long,long long>> &dp){
    if(node==dfsVis.size()-1) {
        return {0,0};
    }
    if(dp[node].first!=-1) return dp[node];
    long long cost=1e15;
    long long disc=0;
    dfsVis[node]=1;
    
    for(auto it: adj[node]){
        if(!dfsVis[it.first]){
            
           
            pair<long long,long long> curr= dfs(it.first, adj, dfsVis, dp);
            curr.second=max(curr.second,it.second);
            if(cost - (disc+1)/2 > curr.first+it.second-(curr.second+1)/2){
                cost=curr.first+it.second;
                disc=curr.second;
            }



        }
    }
    dfsVis[node]=0;
    return dp[node]={cost, disc};
    
}
int main(){
    long long n,m; 
    cin>>n>>m;

    unordered_map<long long, vector<pair<long long,long long>>> adj;

    for(int i=0;i<m; i++){
        long long a,b, c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<long long> dfsVis(n+1,0);
    vector<pair<long long,long long>> dp(n+1,{-1,-1});

    pair<long long, long long> ans=dfs(1, adj, dfsVis, dp);
    cout<< ans.first-(ans.second+1)/2;
}
