#include<bits/stdc++.h>
using namespace std;
void solve(){
    vector<pair<int,int>> sides(4);
    for(int i=1; i<=4; i++){
        int a,b; cin>>a>>b;
        sides[i-1]={a,b};
    }
    sort(sides.begin(), sides.end());
    int lon=abs(sides[0].second-sides[1].second);
    int hor=abs(sides[0].first-sides[2].first);
    cout<<lon*hor<<endl;
}
int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
