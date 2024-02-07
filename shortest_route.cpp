#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
#include<set>
 
using namespace std;
 
/// @brief 
/// @return 
int main() {
    int n, m;
    cin >> n >> m;
 
    unordered_map<int, vector<pair<int, int>>> adj;
    vector<int> vis(n + 1, 0);
    vector<long long> dist(n + 1, LLONG_MAX);
 
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
 
    set<pair<long long, int>>pq;
 
    pq.insert({0, 1});
    dist[1] = 0;
 
    while (!pq.empty()) {
        int node = pq.begin()->second;
        long long nodedist = pq.begin()->first;
        pq.erase({nodedist, node});
 
        
 
        for (auto it : adj[node]) {
            if (!vis[it.first] && dist[it.first] > nodedist + it.second) {
                if(pq.find({ dist[it.first], it.first})!=pq.end()) pq.erase({ dist[it.first], it.first});
                dist[it.first] = nodedist + it.second;
                pq.insert({dist[it.first], it.first});
            }
        }
    }
 
    for (int i = 1; i <= n; i++) {
        if (dist[i] == LLONG_MAX) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
 
    return 0;
}