#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,m,k; cin>>n>>m>>k;
    vector<ll> a(k+1,0);
    for(ll i=0; i<n; i++){
        ll x; cin>>x;
        if(x<=k) a[x]=1; 
    }
    vector<ll> b(k+1,0);
    for(ll j=0; j<m; j++){
        ll x; cin>>x;
        if(x<=k) b[x]=1; 
    }
    ll cntA=k/2;
    ll cntB=k/2;
    ll cmn=0;
    for(ll i=1; i<=k; i++){
        if(a[i]==0 && b[i]==0){
            cout<<"NO"<<endl;
            return;
        }
        if(a[i] && b[i]) cmn++;
        else if(a[i]) cntA--;
        else if(b[i]) cntB--;

    }
    if(cntA<0 || cntB<0) {cout<<"NO"<<endl;
    return;};
    if(cntA+cntB==cmn) {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;


    
}
int main(){
    ll t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
