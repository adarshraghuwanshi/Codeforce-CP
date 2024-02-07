#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,vector<int>> &mpp, int node, int value, vector<int> &teams, bool &pos){
    if(pos==0) return;
    
    for(auto it: mpp[node]){
        if(teams[it]==value){
            pos=0;
            return;
        }
        if(teams[it]==0){
            teams[it]=3-value;
            dfs(mpp,it, 3-value, teams, pos);
        }
    }
    return;
}

int main(){
    int n, m;
    cin>>n>>m;

    unordered_map<int,vector<int>> mpp;
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        mpp[a].push_back(b);
        mpp[b].push_back(a);
    }

    vector<int> teams(n+1,0);
    bool pos=1;
    for(int i=1; i<=n; i++){
        if(teams[i]==0){
            teams[i]=1;
            dfs(mpp,i,1, teams,pos);
            if(pos==0) {cout<<"IMPOSSIBLE";
            return 0;}
        }
        
    }
    for(int i=1;i<=n; i++) cout<<teams[i]<<" ";
    
    return 0;
    
}
