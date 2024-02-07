#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin>>n;
    set<ll> st;
    st.insert(1);
    ll a; cin>>a;
    ll prev=a;
    for(ll i=1; i<n; i++){
         cin>>a;
        if(prev!=a){
        st.insert(i+1);
        prev=a;}
    }
    st.insert(n+1);

    ll q; cin>>q;
    for(ll i=0; i<q; i++){
        ll l, r; cin>>l>>r;

        auto upp=st.upper_bound(l);
        if(*upp<=r && *upp<=n)  cout<< l<< " "<< *upp<< endl;
        else cout<<"-1 -1"<<endl;

    }
}
int main(){
    ll t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
