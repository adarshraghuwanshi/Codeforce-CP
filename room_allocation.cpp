#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>&a , pair<int,int>&b){
    if(a.first==b.first) return a.second>b.second;

}
int main(){
    int n; cin>>n;
    vector<pair<pair<int,int>,int>> timings(n);

    for(int i=0; i<n; i++){
        cin>>timings[i].first.first>>timings[i].first.second;
        timings[i].second=i;
    }
    sort(timings.begin(), timings.end());
    priority_queue<pair<int,int>,  vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int last_room=1;
    unordered_map<int,int> cust;
    pq.push({timings[0].first.first,1})
    for(int i=1; i<n; i++){
        if(pq.top().first< timings[i].first.first){
            pq.pop();
            pq.push({timings[i].first.second, pq.top().second});
            cust[timing[i].second]=pq.top().second;
        }
    }


    
}
