#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin>>n;
    vector<ll> cnt(26,0);
    ll uni=0;
    string s;
    for(ll i=0; i<n; i++){
        ll a; cin>>a;
        if(a==0){
            s+=uni+'a';
            cnt[uni]++;
            uni++;
            
            continue;
        }
        for(ll j=0; j<26; j++){
            if(cnt[j]==a){
                s+=j+'a';
                cnt[j]++;
                break;
            }
        }

        
    }
    return s;
}
int main(){
    ll t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
