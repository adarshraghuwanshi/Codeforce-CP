#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin>>n>>k;

    vector<ll> perm(n+1,0);
    ll low=1;
    ll high=n;
    ll seq=n/k;
    ll extra=n%k;
    
    for(ll i=1; i<=k; i++){

        if(extra){
            for(ll s=0; s<seq+1; s++){
                perm[i+s*k]=i%2?high--:low++;
            }
            extra--;
        }
        else{
            for(ll s=0; s<seq; s++){
                perm[i+s*k]=i%2?high--:low++;
            }
        }
    }
    for(ll i=1; i<=n; i++) cout<<perm[i]<<" ";
    cout<<endl;
    
}
int main(){
    ll t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
