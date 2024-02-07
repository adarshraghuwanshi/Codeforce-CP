#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> city(n + 1);
    for(int i = 1; i <= n; i++) cin >> city[i];

    vector<int> cc(n + 1, 0);
    cc[1] = 1;
    cc[n] = 0;
    for(int i = 2; i < n; i++){
        if(abs(city[i] - city[i - 1]) > abs(city[i] - city[i + 1])) cc[i] = 1;
    }

    vector<int> cost_f(n+1,0);
    vector<int> cost_b(n+1,0);

    for(int i=2; i<=n; i++){
        if(cc[i-1]==1) cost_f[i]=cost_f[i-1]+1;
        else cost_f[i]=cost_f[i-1]+abs(city[i]-city[i-1]);
    }
    for(int i=n-1; i>=0; i--){
        if(cc[i+1]==0) cost_b[i]=cost_b[i+1]+1;
        else cost_b[i]=cost_b[i+1]+abs(city[i+1]-city[i]);
    }

    int m; cin >> m;
    for(int j = 0; j < m; j++){
     int a,b; cin>>a>>b;
     if(a<b){
        cout<<cost_f[b]-cost_f[a]<<endl;
     }
     else{
        cout<<cost_b[b]-cost_b[a]<<endl;
     }
    }
}

int main(){
    int t; cin >> t;

    while(t--){
        solve();
    }
    return 0;
}
