#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    string a,b,c; cin>>a>>b>>c;
    bool ans=0;
    for(int i=0; i<n; i++){
        if(a[i]!=c[i] && b[i]!=c[i]){
            ans=1;
            break;
        }

    }
    if(ans==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
