#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
void solve(){
    long long n,k,m;
    cin>> n>> k>>m;
    string s;
    cin>>s;
 
    unordered_map<ll,ll> cnt;
    ll need=0;
    //ll track=0;
    string pre;
    for(long long i=0; i<m; i++){
        cnt[s[i]-'a']++;
        if(cnt.size()==k){
            need++;
            cnt.clear();
            pre+=s[i];
        
        }
    }
    
    if(need<n){
        cout<<"NO"<<endl;
        cout<<pre;
        ll missing=0;
        for(ll i=0; i<k; i++){
            if(cnt[i]==0) {missing=i; break;}
        }
        for(ll i=1; i<=n-pre.size(); i++){ 
            char ch ='a'+missing;
            cout<<ch;}


        cout<<endl;
    }
    else{
        cout<<"YES"<<endl;
        
    }
    
    return ;
 
}
int main(){
    long long t; cin>>t;
 
    while(t--){
        solve();
    }
    return 0;
}
