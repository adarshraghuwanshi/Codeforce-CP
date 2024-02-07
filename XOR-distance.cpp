#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long  ll;

void solve(){
    ll a, b, r;
    cin>>a>>b>>r;

    vector<ll> diff;
    for(ll i=0; i<32; i++){
        if (((a>> i) & 1) != ((b >> i) & 1)) {
            diff.push_back(i);
        }
    }
    ll n=diff.size()-1;
    ll ans1=pow(2, diff[n]);

    ll k=r;
    if((b>>diff[n])&1) k=r;
    else if(r-pow(2,diff[n])>0) k=r-pow(2,diff[n]);
    else {
        k<0;
        ans1=1e15;
    }
    
    for(ll i=n-1; i>=0; i--){
        if(k<0) break;
        
        ll curr=diff[i];
        if((a>>curr)&1) ans1-=pow(2,diff[i]);
        else {
            if(k>=pow(2,diff[i])){
                ans1-=pow(2,diff[i]);
                k-=pow(2,diff[i]);
            }
            else ans1+=pow(2,diff[i]);
        }
        

    }
    if(ans1<0) ans1=-ans1;
    ll ans2=pow(2, diff[n]);
    k=r;
    if((a>>diff[n])&1) k=r;
    else if(r-pow(2,diff[n])>0) k=r-pow(2,diff[n]);
    else{
        k<0;
        ans2=1e15;
    }
    

    for(ll i=n-1; i>=0; i--){
        if(k<0) break;
        ll curr=diff[i];
        if((b>>curr)&1) ans2-=pow(2,diff[i]);
        else{
            if(k>=pow(2,diff[i])){
                ans2-=pow(2,diff[i]);
                k-=pow(2,diff[i]);
            }
            else ans2+=pow(2,diff[i]);
        }
        
    }
    if(ans2<0) ans2=-ans2;
    cout<<min(ans1, ans2)<<endl;
}
int main(){
    ll t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
