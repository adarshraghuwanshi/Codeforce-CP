#include<bits/stdc++.h>
using namespace std;
 
 
void solve(){
    long long n,k,m;
    cin>> n>> k>>m;
    string s;
    cin>>s;
 
    vector<long long> cnt(k,0);
    for(long long i=0; i<m; i++){
        cnt[s[i]-'a']++;
    }
    for(long long i=0; i<k; i++) {
        if(cnt[i]<n){
        cout<<"NO"<<endl;
        string ans;
        for(long long j=0; j<n; j++) ans+=('a'+i);
        cout<<ans<<endl;
        return;
    }}
 
 
    set<long long> st;
    long long need=n;
    for(long long i=0; i<m; i++){
        cnt[s[i]-'a']--;
        st.insert(s[i]-'a');
        if(cnt[s[i]-'a']<need-1){
            cout<<"NO"<<endl;
            string ans;
            long long p=m-n-1;
            long long r=n-need+1;
            while(r>0){
                if(s[p]!=s[i]) {ans+=s[p];
                r--;
                }
                p++;
            }
 
            
            for(long long j=1; j<=need-1; j++) ans+=s[i];
            cout<<ans<<endl;
 
            return;
        }
 
 
        if(st.size()==k){
            need--;
            st.clear();
        }
 
 
    }
    cout<<"YES"<<endl;
    return;
 
 
}
int main(){
    long long t; cin>>t;
 
    while(t--){
        solve();
    }
    return 0;
}
