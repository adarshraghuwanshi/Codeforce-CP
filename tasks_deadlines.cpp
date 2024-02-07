#include<bits/stdc++.h>
using namespace std;
using ll =long long;


int main(){
    int n; cin>>n;
    vector<pair<int,int> > t;
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        t.push_back({a,b});
    }
    sort(t.begin(), t.end());
    ll curr=0;
    ll ans=0;
    for(int i=0; i<n; i++){
        curr+=t[i].first;
        ans+=t[i].second-curr;
    }
    cout<<ans;
    return 0;
}
