#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int, vector<int>> &adj, int node, int prev, vector<int> &visited, int &start, bool &br, vector<int> &route, bool &inloop){
    
visited[node]=1;

for(auto it: adj[node]){
    
    if(prev!=it){
        if(visited[it]==0){
            dfs(adj, it,node,visited, start, br, route, inloop );
            if(inloop==1) {route.push_back(node);
            if(start==node){
                br=1;
                inloop=0;
            }}
            if(br==1 || inloop==1) return;
        }
        else{
            inloop=1;
            start=it;
            route.push_back(it);
            route.push_back(node);
            return;
        }

    }
}
}
int main(){
    int n,m; cin>>n>>m;
unordered_map<int, vector<int>> adj;
for(int i=0; i<m; i++){
int a,b; cin>>a>>b;
adj[a].push_back(b);
adj[b].push_back(a);
}
vector<int> visited(n+1,0);
 for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> route;
            bool inloop=0;
            bool br=0;
            int start=-1;
            dfs(adj, i, -1, visited, start, br, route, inloop);
            
            if(route.size()<4) continue;
            cout << route.size() << endl;
            for (int j = route.size() - 1; j >= 0; j--) {
                cout << route[j] << " ";
            }

            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
