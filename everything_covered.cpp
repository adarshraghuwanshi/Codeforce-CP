#include<bits/stdc++.h>
using namespace std;


void solve(){
    long long n,k;
    cin>>n>>k;
    string str;
    for(int j=1; j<=n; j++){
    for(int i=1; i<=k; i++){
        
            str+='a'+i-1;
        }
    }
    cout<<str<<endl;
    
}
int main(){
    long long t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
