#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,q; cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=0; i<q; i++){
        int s,d,k; cin>>s>>d>>k;
        long long sum=0;
        for(int j=1; j<=k; j++){
            sum+=a[s+d*(j-1)]*j;
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}
int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
