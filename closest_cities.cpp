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
    int m; cin >> m;
    for(int j = 0; j < m; j++){
        int a, b; cin >> a >> b;
        int cost = 0;
        if(a < b){
            for(int i = a; i < b; i++){
                if(cc[i] == 1) cost++;
                else cost += city[i + 1] - city[i];
            }
        }
        else{
            for(int i = a; i > b; i--){
                if(cc[i] == 0) cost++;
                else cost += city[i] - city[i - 1];
            }
        }
        cout << cost << endl;
    }
}

int main(){
    int t; cin >> t;

    while(t--){
        solve();
    }
    return 0;
}
