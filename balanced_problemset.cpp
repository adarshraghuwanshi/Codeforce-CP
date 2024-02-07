#include<bits/stdc++.h>
using namespace std;


// void solve(){
//     long long x,n; cin>>x>>n;
//     long long k=x/n;
//     long long ans=0;
//     for(long long i=k; i>=1; i--){
//         if(x%i==0) ans=ans
       
//     }
// }

void solve(){
    long long x,n; cin>>x>>n;
    long long k=x/n;
    long long ans=0;
    for(long long i=1; i*i<=x; i++){
        if(x%i==0){
            if(i<=k)
            ans=max(ans,i);
            if(x/i<=k) ans=max(ans,x/i);
        }
    }
    cout<< ans<<endl;
}
int main(){
    long long t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
