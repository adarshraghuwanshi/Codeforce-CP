#include <bits/stdc++.h>
using namespace std;
#include<unordered_map>
long long dfs(unordered_map<int,vector<pair<int,int>>> &adj, int i,  int end, vector<int> &dfsVis){
    if(i==end) return 0;
    dfsVis[i]=1;
    long long ans=INT_MIN;
    for(auto it:adj[i]){
        
        if(dfsVis[it.first]==0)
       ans=max(ans, it.second+dfs(adj,it.first,end, dfsVis));
       else {
        
        return 1e-13;
       }
       
    }
    dfsVis[i]=0;
    return ans;
    
}
int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int,vector<pair<int,int>>> adj;
    vector<int> dfsVis(n+1,0);
    for(int i=0; i<m; i++){ 
        int a,b,x; cin>>a>>b>>x;
        adj[a].push_back({b,x});
    }
long long ans=dfs(adj,1,n, dfsVis);
if(ans<=1e-13) {cout<<"-1";
return 0;}
cout<<ans;


    return 0;
}
